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

/* 
 * FLIPCOLORS source code is loosely based on my game engine v0.1.
 * Versions of the engine subsequent to version 0.1 are NOT REALEASED UNDER ANY FREE SOFTWARE LICENSE.
 * I explicitly reserve the right to release other versions and derivative works in commercial forms
 * under closed license.
 * This is legally compliant to the present 3-clause BSD licence.
 * https://en.wikipedia.org/wiki/BSD_licenses
 */


#include "main.h"
#include <wx/app.h>
#include <wx/event.h>
#include "MainDialog.h"
#include "MyContext.h"
#include "InGameContext.h"
#include "MyLog.h"
#include <wx/image.h>

/*
 * A note about global contexts: I consider this solution a big mistake.
 * Even in small programs a global variable will bring in bad errors like allocation problems.
 * I dont's correct this because I don't maintain this code, but I have completely removed every
 * global reference in later versions of my game engine.
 * If you encounter allocation bugs like crash on exit, this is the first thing to correct.
 */
MyContext myContext;
InGameContext inGameContext;
char errorStr[255];

// Define the MainApp
class MainApp : public wxApp
{
public:
    MainApp() {}
    virtual ~MainApp() {}

    virtual bool OnInit() {
        MYLOG_DEBUG( "Application Start")
        MYLOG_DEBUG( "base_res_path = " << myContext.base_res_path )
        // Add the common image handlers
        wxImage::AddHandler( new wxPNGHandler );
        wxImage::AddHandler( new wxJPEGHandler );

        MainDialog mainDialog(NULL);
        
        mainDialog.ShowModal();
        MYLOG_DEBUG( "Application End")
        return false;
    }
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
