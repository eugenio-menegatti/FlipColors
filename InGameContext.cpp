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

#include "InGameContext.h"
#include "Sprite.h"
#include "main.h"
#include "MyLog.h"

InGameContext::InGameContext()
{
    playerColor = BLACK_PIECE;
    opponentColor = WHITE_PIECE;
}

InGameContext::~InGameContext()
{
}

void InGameContext::dumpDataGrid()
{
    string dump;
    for (int i=0; i<DATA_GRID_H; ++i) {
        dump = "";
        for (int j=0; j<DATA_GRID_W; ++j) {
            int cell = dataGrid[i][j];
            if ( cell == NO_PIECE ) {
                dump += ".";
            }
            else if ( cell == WHITE_PIECE ) {
                dump += "B";
            }
            else if ( cell == BLACK_PIECE ) {
                dump += "N";
            }
        }
        MYLOG_DEBUG( dump );
    }        
}

void InGameContext::init()
{
    pedinaBianca.init("pedinaBianca.png");
    pedinaNera.init("pedinaNera.png");
    selectionPiece.init("pedinaBlu.png");
    
    background.init("checkerboard.png");

    initGrid();
}

void InGameContext::initGrid()
{
    memset(displayGrid, NO_PIECE, sizeof(unsigned short) * DATA_GRID_W * DATA_GRID_H);
    
    displayGrid[3][3] = WHITE_PIECE;
    displayGrid[4][3] = BLACK_PIECE;
    displayGrid[3][4] = BLACK_PIECE;
    displayGrid[4][4] = WHITE_PIECE;
    
    // Init copy grid
    memcpy(dataGrid, displayGrid, sizeof(unsigned short) * DATA_GRID_W * DATA_GRID_H);
}