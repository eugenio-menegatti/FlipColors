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

#include "MainDialog.h"
#include "main.h"
#include "MainDialog.h"
#include "MainGameArea.h"
#include "InGameContext.h"
#include "LicensesDialog.h"
#include "BSDLicenseDialog.h"
#include <SDL.h>
#include <wx/aboutdlg.h>

MainDialog::MainDialog( wxWindow* parent )
:
MainDialogBase( parent )
{
    mainGameArea = NULL;
    uiParams.playerColor = DEFAULT_PLAYER_COLOR;
    uiParams.autoPass = DEFAULT_AUTO_PASS;
    uiParams.algoritmoAI = DEFAULT_AI_METHOD;
}

void MainDialog::OnStartGameButtonClicked( wxCommandEvent& event )
{
if (mainGameArea == NULL) {
mainGameArea = new MainGameArea(this);
}

mainGameArea->initConfigFromUI(uiParams);
mainGameArea->initSDL();
mainGameArea->initSDL_Libs();
mainGameArea->initVideoMode();
inGameContext.init();
mainGameArea->mainGameLoop();
mainGameArea->Destroy();
}

void MainDialog::OnLicenseButtonClicked( wxCommandEvent& event )
{
    BSDLicenseDialog licenseDialog(this);
    licenseDialog.ShowModal();
}

void MainDialog::OnThirdPartyButtonClicked( wxCommandEvent& event )
{
    LicensesDialog licensesDialog(this);
    licensesDialog.ShowModal();
}


MainDialog::~MainDialog()
{
    if (mainGameArea != NULL) {
        delete mainGameArea;
    }
}

void MainDialog::selezionaColoreGiocatore(wxCommandEvent& event)
{
    int selection = m_radioBox32->GetSelection();
    
    switch (selection) {
        case 0: {
            uiParams.playerColor = BLACK_PIECE;
            break;
        }
        case 1: {
            uiParams.playerColor = WHITE_PIECE;
            break;
        }
    }
}

void MainDialog::selezionaAlgoritmoMosseComputer(wxCommandEvent& event)
{
    int selection = m_radioBox36->GetSelection();
    
    switch (selection) {
        case 0: {
            uiParams.algoritmoAI = AI_RANDOM;
            break;
        }
        case 1: {
            uiParams.algoritmoAI = AI_LONGEST_PATH;
            break;
        }
        case 2: {
            uiParams.algoritmoAI = AI_BEST_ALGORITHMIC;
            break;
        }
        case 3: {
            uiParams.algoritmoAI = AI_THINK;
            break;
        }
    }
}

void MainDialog::impostaAutoPass(wxCommandEvent& event)
{
    uiParams.autoPass = m_checkBox38->GetValue();
}