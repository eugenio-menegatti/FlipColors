/*
Copyright (c) 2019, EUGENIO MENEGATTI
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "AI.h"
#include "main.h"
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include "MyLog.h"

string DATA_PATH = string("C:\\Users\\") + USER_NAME + "\\" + DOCUMENTS_PATH + "\\Workspaces\\" + WORKSPACE_ROOT + "\\GitHubWorkspace\\FlipColors\\data\\";
string PYTHON_PATH = string("C:\\Users\\") + USER_NAME + "\\" + DOCUMENTS_PATH + "\\Workspaces\\" + WORKSPACE_ROOT + "\\GitHubWorkspace\\FlipColors\\python\\";

AI::AI()
{
    initPython();
}

AI::~AI()
{
    quitPython();
}

void AI::initPython()
{
    #ifdef PYTHON_INSTALLED
        // C'e' il python installato, va impostata la python-home
        string home("C:/Python37-32"); // Elimina la necessita' di avere la var di ambiente PYTHONHOME=C:/Python27 impostata dall'esterno
        Py_SetPythonHome( Py_DecodeLocale(home.c_str(), NULL) );
    #else
        // Non c'e' il python installato
        // VEDI: https://stackoverflow.com/questions/551227/deploying-application-with-python-or-another-embedded-scripting-language
        Py_NoSiteFlag = 1;
    #endif
    Py_Initialize();
}

void AI::quitPython()
{
    Py_Finalize();
}

void AI::runPythonCode(string &pythonCode)
{
    // https://wiki.python.org/moin/EmbeddingPythonTutorial
    MYLOG_DEBUG("[AI::runPythonCode] START");
    // Define main module
    MYLOG_DEBUG("[AI::runPythonCode] 1");
    PyObject *main_module = PyImport_ImportModule("__main__");
    MYLOG_DEBUG("[AI::runPythonCode] 2");
    PyObject *main_dict   = PyModule_GetDict(main_module);
    
    MYLOG_DEBUG("[AI::runPythonCode] 3");
    PyObject *sys_module = PyImport_ImportModule( "sys" );
    MYLOG_DEBUG("[AI::runPythonCode] 4");
    PyObject *sys_dict   = PyModule_GetDict(sys_module);
    
    MYLOG_DEBUG("[AI::runPythonCode] 4.1");
    PyDict_SetItemString(main_dict, "sys", sys_module);
    
    
    MYLOG_DEBUG("[AI::runPythonCode] 5");
    PyObject *sys_path = PyObject_GetAttrString( sys_module, "path" );

    MYLOG_DEBUG("[AI::runPythonCode] 6");
    PyObject *folder_path = PyUnicode_FromString( PYTHON_PATH.c_str() );
    MYLOG_DEBUG("[AI::runPythonCode] 7");
    PyList_Append( sys_path, folder_path );
    
    outputPyObjectAsString(sys_path);
    
    MYLOG_DEBUG("[AI::runPythonCode] 8");
    
    // import AIMove
    PyObject *aimove_module = PyImport_ImportModule("AIMove");
    MYLOG_DEBUG("[AI::runPythonCode] 9");
    if (aimove_module == NULL) {
        MYLOG_DEBUG("[AI::runPythonCode] module AIMove not found or null");
    }
    else {
//    PyObject *aimove_dict   = PyModule_GetDict(aimove_module);
        MYLOG_DEBUG("[AI::runPythonCode] 10");
        PyDict_SetItemString(main_dict, MODULE_IMPORT_NAME, aimove_module);
        MYLOG_DEBUG("[AI::runPythonCode] 11");
        PyRun_SimpleString(pythonCode.c_str());
        MYLOG_DEBUG("[AI::runPythonCode] END");
    }
    // https://python-forum.io/Thread-Embedded-python-in-C
}

void AI::outputPyObjectAsString(PyObject *obj)
{
    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");
    const char *bytes = PyBytes_AS_STRING(str);
    MYLOG_DEBUG(bytes);
}

void AI::writeFileToPython()
{
    wxString filename = ((string)DATA_PATH + (string)DATA_FILE_FROM_CPP).c_str();
    std::ofstream fout(filename);

    if (inGameContext.playerColor == WHITE_PIECE) {
        fout << "W\n";
    }
    if (inGameContext.playerColor == BLACK_PIECE) {
        fout << "B\n";
    }
    dumpGridToFile(dataGrid, fout);
    
    fout.close();
}

checkerboardCoord AI::trovaMossaMigliore(unsigned short (&inputDataGrid)[8][8])
{
    checkerboardCoord mossaMigliore = {-1, -1};
    
    memcpy(dataGrid, inputDataGrid, sizeof(unsigned short) * DATA_GRID_W * DATA_GRID_H);
    
    writeFileToPython();
    string pythonCode = string(MODULE_IMPORT_NAME) + string(".aiMove()");
    
    runPythonCode(pythonCode);
    unsigned short (*newDataGrid)[8][8] = buildGridFromFile();
    MYLOG_DEBUG("Chekboard from Python (C++ doesn't use this):")
    dumpGrid(newDataGrid);
    MYLOG_DEBUG("Python moved in: " << nextMoveX << ", " << nextMoveY );
    mossaMigliore = { nextMoveX, nextMoveY };
    return mossaMigliore;
}

void AI::dumpGrid(unsigned short (*dataGrid)[8][8])
{
    MYLOG_DEBUG("[AI::dumpGrid] START");
    string line;
    string cell;
    for (int j = 0; j < DATA_GRID_H; j++) {
        line = "";
        for (int i = 0; i < DATA_GRID_W; i++) {
            int data = (*dataGrid)[j][i];
            if ( data == NO_PIECE ) {
                cell = "'_'";    
            }
            else if ( data == WHITE_PIECE ) {
                cell = "'W'";
            }
            else if ( data == BLACK_PIECE ) {
                cell = "'B'";
            }
            line += cell;
            line += " ";
        }
        MYLOG_DEBUG(line);
    }
    MYLOG_DEBUG("[AI::dumpGrid] END");
}

void AI::dumpGridToFile(unsigned short (&dataGrid)[8][8], ofstream &fout)
{
    MYLOG_DEBUG("[AI::dumpGridToFile] START");
    string dump;

    for (int i=0; i<DATA_GRID_H; ++i) {
        dump = "[ ";
        for (int j=0; j<DATA_GRID_W; ++j) {
            int cell = dataGrid[i][j];
            if ( cell == NO_PIECE ) {
                dump += "'_'";
            }
            else if ( cell == WHITE_PIECE ) {
                dump += "'W'";
            }
            else if ( cell == BLACK_PIECE ) {
                dump += "'B'";
            }
            if (j < DATA_GRID_W-1) {
                dump += ", ";
            }
        }
        dump += " ]";
        fout << dump << "\n";
        MYLOG_DEBUG( dump );
    }
    fout.flush();
    MYLOG_DEBUG("[AI::dumpGridToFile] END");
}

unsigned short (*AI::buildGridFromFile())[8][8]
{
    MYLOG_DEBUG("[AI::buildGridFromFile] START")
    string dump;
    wxString filename = ((string)DATA_PATH + (string)DATA_FILE_FROM_PYTHON).c_str();
    std::ifstream in(filename);
    unsigned short data = -1;
    char sLine[256];
    in.getline(sLine, 255);
    stringstream ss(sLine);
    ss >> nextMoveX;
    ss >> nextMoveY;
    int pos = 0;
    for (int i=0; i<DATA_GRID_H; ++i) {
        pos = 0;
        in.getline(sLine, 255);
        string line(sLine);
        dump = "";
        for (int j=0; j<DATA_GRID_W; ++j) {
            pos = line.find('\'', pos);
            string cell = "";
            if (pos != string::npos) {
                cell = line.substr(pos, 3);
                if ( cell == "'_'" || cell == "'o'" || cell == "'O'" ) {
//                    MYLOG_DEBUG( "e" );
                    data = NO_PIECE;
                }
                else if ( cell == "'W'" || cell == "'w'" ) {
//                    MYLOG_DEBUG( "w" );
                    data = WHITE_PIECE;
                }
                else if ( cell == "'B'" || cell == "'b'") {
//                    MYLOG_DEBUG( "b" );
                    data = BLACK_PIECE;
                }
                dataGrid[i][j] = data;
            }
            dump += cell;
            dump += " ";
            pos = line.find(',', pos);
            if (pos == string::npos) {
                break;
            }
        }
        MYLOG_DEBUG( dump );
    }
    MYLOG_DEBUG("[AI::buildGridFromFile] END")
    return &dataGrid;
}
