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

// START Patch for "not found" on AttachConsole symbol
// Vedi: https://stackoverflow.com/questions/41457019/attachconsole-has-not-been-declared
#ifndef WINVER
    #define WINVER 0x0603
#endif

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0603
#endif

#ifndef _WIN32_IE
    #define _WIN32_IE 0x0700
#endif
// END Patch for "not found" on AttachConsole symbol
#include "MyLog.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <windows.h>

//unsigned MyLog::lineNumber = 0;
//int MyLog::currentPriorityLevel = 1;
//bool MyLog::logWasInit = false;
//int MyLog::logMode = -1;
LogFile MyLog::logFile("C:\\tmp\\flipcolors.log");
bool MyLog::logWasInit;
int MyLog::logMode;
unsigned MyLog::lineNumber;
int MyLog::currentPriorityLevel;

MyLog::MyLog()
{
    // NON LOGGARE QUI - IL LOG NON E' ANCORA INIZIALIZZATO
}

MyLog::~MyLog()
{
    // NON LOGGARE QUI - LogFile E' GIA' STATO DISTRUTTO
    logWasInit = false; // Penso che non serva, ma per sicurezza
}

void MyLog::configureFile()
{
    logWasInit = false;
    
    if (logFile.file != NULL) {
        fclose(logFile.file);
    }
    
    #ifdef LOG_APPEND
    logFile.file = fopen(logFile.fileName.c_str(), "a+");
    #else
    logFile.file = fopen(logFile.fileName.c_str(), "w+");
    #endif
    if (logFile.file == NULL) {
        #ifdef REDIRECT_LOG_TO_STDOUT_ON_LOG_INIT_FAIL
        ::AllocConsole();
        ::AttachConsole(GetCurrentProcessId());
        if (freopen( "CON", "w", stdout ) != NULL) {
//            cout << "Can't write to log file: " << logFile.fileName << "\n";
//            cout << "fopen() error code = " << errno << "\n";
//            cout << "Redirecting log to stdout\n";
            printf("Can't write to log file: %s\n",  logFile.fileName.c_str());
            printf("fopen() error code = %d\n", errno);
            printf("Redirecting log to stdout\n");

            logWasInit = true;
            logMode = LOG_MODE_CONSOLE;
        }
        #endif
    }
    else {
        MYLOG_DEBUG("[MyLog::configureFile] ********************** Logging system started");
        logWasInit = true;
        logMode = LOG_MODE_FILE;
    }
}

void MyLog::configureConsole()
{
    // Vedi:
    // https://bobobobo.wordpress.com/2009/03/01/how-to-attach-a-console-to-your-gui-app-in-c/
    // https://www.tillett.info/2013/05/13/how-to-create-a-windows-program-that-works-as-both-as-a-gui-and-console-application/
    
    logWasInit = false;
    
    logFile.file = NULL;
    ::AllocConsole();
    ::AttachConsole(GetCurrentProcessId());
    
    if (freopen( "CON", "w", stdout ) != NULL) {
        printf("[MyLog::configureConsole] ********************** Logging system started\n");
        logWasInit = true;
        logMode = LOG_MODE_CONSOLE;
    }
    
}

void MyLog::composeLine(ostream &inStream, stringstream &outStream)
{
    // Line Number
    outStream << "[" << lineNumber << "] ";
    
    // Time
    outStream << "[";
    time_t now;
    time(&now);
    char timeS[100];
    struct tm *timeinfo;
    timeinfo = localtime (&now);
    strftime(timeS, sizeof(timeS), "%b %d %H:%M:%S", timeinfo);
    outStream << timeS;
    outStream << "] ";
    
    // User message
    outStream << inStream.rdbuf();
}
    
void MyLog::debug(ostream &stream)
{
    if (currentPriorityLevel != 0) {
        return;
    }
    
    debugImpl(stream);
}

void MyLog::debugNoNL(ostream &stream)
{
    if (currentPriorityLevel != 0) {
        return;
    }
    
    debugImpl(stream, false);
}

void MyLog::debugPriority(int priorityLevel, ostream &stream)
{
    if (priorityLevel < currentPriorityLevel) {
        return;
    }
    debugImpl(stream);
}

void MyLog::debugImpl(ostream &stream, bool flagNL)
{
    if (!logWasInit) {
        return;
    }
    
    string FORMAT_STR = "";
    
    if (flagNL) {
        FORMAT_STR = "%s\n";
    }
    else {
        FORMAT_STR = "%s";
    }
    stringstream ss;
    composeLine(stream, ss);
    
    string message = ss.str();
    
    if (logMode == LOG_MODE_FILE) {
        if (logFile.file != NULL) {
            fprintf(logFile.file, FORMAT_STR.c_str(), message.c_str());
            fflush(logFile.file);
            lineNumber++;
        }
        else {
            #ifdef REDIRECT_LOG_TO_STDOUT_ON_LOG_INIT_FAIL
            printf(FORMAT_STR.c_str(), message.c_str());
            fflush(stdout);
            lineNumber++;
            #endif
        }
    }
    else if (logMode == LOG_MODE_CONSOLE) {
        printf(FORMAT_STR.c_str(), message.c_str());
        fflush(stdout);
        lineNumber++;
    }
}