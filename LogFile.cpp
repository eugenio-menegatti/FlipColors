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

#include <stdio.h>
#include "LogFile.h"
#include "MyLog.h"

LogFile::LogFile()
{
    // NON LOGGARE QUI - IL LOG NON E' ANCORA INIZIALIZZATO
    file = NULL;
}

LogFile::LogFile(const char *logFileName)
{
    // NON LOGGARE QUI - IL LOG NON E' ANCORA INIZIALIZZATO
    initMyLog(logFileName);
    // DA QUI IN POI SI PUO' LOGGARE
    MYLOG_DEBUG("Log system started");
}

LogFile::~LogFile()
{
    // QUI SI PUO' ANCORA LOGGARE
    MYLOG_DEBUG("~LogFile");
    MYLOG_DEBUG("Log system ended");
    if (file != NULL) {
        fflush(file);
        fclose(file);
    }
    // DA QUI IN POI NON SI PUO' PIU' LOGGARE - LogFile E' STATO GIA' DISTRUTTO
}

void LogFile::initMyLog(const char *logFileName)
{
    fileName = logFileName;
    #ifdef ENABLE_LOG
        #ifdef LOG_TO_FILE
            MyLog::configureFile();
        #else
            #ifdef LOG_TO_CONSOLE
                MyLog::configureConsole();
            #endif
        #endif
    #endif
}
