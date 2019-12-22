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

#ifndef AI_H
#define AI_H
#include "TypeDefs.h"
#include <string>
#include <windows.h>
#ifndef PY_SSIZE_T_CLEAN
    #define PY_SSIZE_T_CLEAN 
#endif
#include <Python.h>

using namespace std;

#define AI_RANDOM 0
#define AI_LONGEST_PATH 1
#define AI_BEST_ALGORITHMIC 2
#define AI_THINK 3

#define USER_NAME "<your-user-name>"
#define DOCUMENTS_PATH "Desktop"
#define WORKSPACE_ROOT "cpp"


#define DATA_FILE_FROM_PYTHON "boardOUT.txt"
#define DATA_FILE_FROM_CPP "boardIN.txt"

#define MODULE_IMPORT_NAME "maimove"

#define PYTHON_INSTALLED
extern string DATA_PATH;
extern string PYTHON_PATH;

class AI
{
protected:
    unsigned short dataGrid[8][8];
    int nextMoveX, nextMoveY;
    
public:
    AI();
    ~AI();
    checkerboardCoord trovaMossaMigliore(unsigned short (&dataGrid)[8][8]);
    void dumpGrid(unsigned short (*dataGrid)[8][8]);
    
protected:
    void writeFileToPython();
    void dumpGridToFile(unsigned short (&dataGrid)[8][8], ofstream &out);
    unsigned short (*buildGridFromFile())[8][8];
    void initPython();
    void quitPython();
    void runPythonCode(string &pythonCode);
    void outputPyObjectAsString(PyObject *obj);
};

#endif // AI_H
