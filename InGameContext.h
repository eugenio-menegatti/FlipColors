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

#ifndef INGAMECONTEXT_H
#define INGAMECONTEXT_H

#include "Sprite.h"
#include "Background.h"
#include "GamePlay.h"
#include "AI.h"

#define CHECKER_W_PIXEL 64
#define CHECKER_H_PIXEL 64
#define MAX_ENEMY_COUNT 64
#define DATA_GRID_W 8
#define DATA_GRID_H 8
#define MAX_PATH_LENGHT 8

#define NO_PIECE 0
#define WHITE_PIECE 1
#define BLACK_PIECE 2
#define SELECTION_PIECE 3

#define DEFAULT_PLAYER_COLOR WHITE_PIECE
#define DEFAULT_AUTO_PASS true
#define DEFAULT_AI_METHOD AI_THINK

class InGameContext
{
public:
    int playerColor, opponentColor;
    Background background;
    Sprite pedinaBianca;
    Sprite pedinaNera;
    Sprite selectionPiece;
    unsigned short displayGrid[DATA_GRID_H][DATA_GRID_W];
    unsigned short dataGrid[DATA_GRID_H][DATA_GRID_W];
    GamePlay gamePlay;
    
public:
    InGameContext();
    ~InGameContext();

    void init();
    void dumpDataGrid();
    
protected:
    void initGrid();
};

#endif // INGAMECONTEXT_H
