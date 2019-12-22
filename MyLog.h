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

#ifndef MYLOG_H
#define MYLOG_H
#include <sstream>
#include "LogFile.h"

#define LOG_MODE_CONSOLE 0
#define LOG_MODE_FILE 1
#define ENABLE_LOG
#undef LOG_APPEND
#define REDIRECT_LOG_TO_STDOUT_ON_LOG_INIT_FAIL
#define LOG_TO_FILE
#define LOG_TO_CONSOLE

#ifdef ENABLE_LOG
    #define MYLOG_DEBUG(message) { \
        std::stringstream messageStream; \
        MyLog::debug(messageStream << message); \
    }
#else
    #define MYLOG_DEBUG(message) { }
#endif


#ifdef ENABLE_LOG
    #define MYLOG_DEBUG_PRI(level, message) { \
        std::stringstream messageStream; \
        MyLog::debugPriority(level, messageStream << message); \
    }
#else
    #define MYLOG_DEBUG_PRI(level, message) { }
#endif


#ifdef ENABLE_LOG
    #define MYLOG_DEBUG_NO_NL(message) { \
        std::stringstream messageStream; \
        MyLog::debugNoNL(messageStream << message); \
    }
#else
    #define MYLOG_DEBUG(message) { }
#endif

using namespace std;

class MyLog
{
protected:
    static LogFile logFile;
    static unsigned lineNumber;
    static int currentPriorityLevel;
    static bool logWasInit;
    static int logMode;
    
protected:
    static void composeLine(ostream &inStream, stringstream &outStream);
    static void debugImpl(ostream &stream, bool flagNL = true);
    
public:
    MyLog();
    ~MyLog();

    static void configureFile();
    static void configureConsole();
    static void debug(ostream &stream);
    static void debugNoNL(ostream &stream);
    static void debugPriority(int priorityLevel, ostream &stream);
};

#endif // MYLOG_H
