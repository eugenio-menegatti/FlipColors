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

#include "GamePlay.h"
#include "main.h"
#include "InGameContext.h"
#include "Utils.h"
#include "AI.h"
#include "MyLog.h"

GamePlay::GamePlay()
{
    whoseTurn = DEFAULT_PLAYER_COLOR;
    algoritmoAI = DEFAULT_AI_METHOD;
    srand(time(NULL));
}

GamePlay::~GamePlay()
{
}

bool GamePlay::buildMoveResultMatrix(int checkerX, int checkerY, int color)
{
    bool isValidMatrix = false;
    isValidMatrix = inGameContext.gamePlay.isMossaValida(checkerX, checkerY, color);
    return isValidMatrix;
}

int GamePlay::numeroCaselleLibere()
{
    int count = 0;
    for (int y=0; y<DATA_GRID_H; ++y) {
        for (int x=0; x<DATA_GRID_W; ++x) {
            if (inGameContext.dataGrid[y][x] == NO_PIECE) {
                ++count;
            }
        }
    }
    return count;
}

bool GamePlay::canPutPieceAt(int checkerX, int checkerY, int color)
{
    bool result = false;
    if (inGameContext.dataGrid[checkerY][checkerX] == NO_PIECE) {
        if (inGameContext.gamePlay.isMossaValida(checkerX, checkerY, color)) {
            result = true;
        }
    }
    return result;
}

bool GamePlay::isMossaValida(int checkerX, int checkerY, int color)
{
    bool result = false;
    checkerboardCoord path[8];
    
    Utils::fillWithEmptyCoords(moveResultMatrix);
    
    if (esisteCamminoVerticaleSu(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[0], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoVerticaleGiu(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[1], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoOrizzontaleDestra(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[2], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoOrizzontaleSinistra(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[3], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoDiagonaleQuadrante1(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[4], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoDiagonaleQuadrante2(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[5], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoDiagonaleQuadrante3(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[6], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    if (esisteCamminoDiagonaleQuadrante4(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[7], path, sizeof(checkerboardCoord)*8);
        result = true;
    }
    
//    MYLOG_DEBUG( "isMossaValida? " << result);

    return result;
}

bool GamePlay::esisteCamminoVerticaleSu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    memset(path, -1, sizeof(checkerboardCoord) * 8);
    int pathIndex = 0;
    if (checkerY > 0) {
        result = _esisteCamminoVerticaleSu(checkerX, checkerY-1, color, path, pathIndex);
    }
//    for (int i=0; path[i].x!=-1; ++i) {
//        MYLOG_DEBUG( "SU path[" << i << "].x = " << path[i].x << " y = " << path[i].x);
//    }
    return result;
}

bool GamePlay::_esisteCamminoVerticaleSu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerY > 0) {
            result = _esisteCamminoVerticaleSu(checkerX, checkerY-1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY-1][checkerX] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoVerticaleGiu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerY < DATA_GRID_H-1) {
        result = _esisteCamminoVerticaleGiu(checkerX, checkerY+1, color, path, pathIndex);
    }
    return result;
}

void GamePlay::dumpMoveResultMatrix()
{
    MYLOG_DEBUG( "SU");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[0][j].x << " y=" << moveResultMatrix[0][j].y);
    }
    
    MYLOG_DEBUG( "GIU");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[1][j].x << " y=" << moveResultMatrix[1][j].y);
    }
    
    MYLOG_DEBUG( "DESTRA");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[2][j].x << " y=" << moveResultMatrix[2][j].y);
    }
    
    MYLOG_DEBUG( "SINISTRA");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[3][j].x << " y=" << moveResultMatrix[3][j].y);
    }
    
    MYLOG_DEBUG( "Q1");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[4][j].x << " y=" << moveResultMatrix[4][j].y);
    }
    
    MYLOG_DEBUG( "Q2");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[5][j].x << " y=" << moveResultMatrix[5][j].y);
    }
    
    MYLOG_DEBUG( "Q3");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[6][j].x << " y=" << moveResultMatrix[6][j].y);
    }
    
    MYLOG_DEBUG( "Q4");
    for (int j=0; j<8; ++j) {
        MYLOG_DEBUG( "x=" << moveResultMatrix[7][j].x << " y=" << moveResultMatrix[7][j].y);
    }
}

bool GamePlay::_esisteCamminoVerticaleGiu(int checkerX, int checkerY, int color,checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerY < DATA_GRID_H-1) {
            result = _esisteCamminoVerticaleGiu(checkerX, checkerY+1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY+1][checkerX] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoOrizzontaleDestra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX < DATA_GRID_W-1) {
        result = _esisteCamminoOrizzontaleDestra(checkerX+1, checkerY, color, path, pathIndex);
    }
    return result;
}

bool GamePlay::_esisteCamminoOrizzontaleDestra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerX < DATA_GRID_W-1) {
            result = _esisteCamminoOrizzontaleDestra(checkerX+1, checkerY, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY][checkerX+1] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoOrizzontaleSinistra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX > 0) {
        result = _esisteCamminoOrizzontaleSinistra(checkerX-1, checkerY, color, path, pathIndex);
    }
//    for (int i=0; path[i].x!=-1; ++i) {
//        MYLOG_DEBUG( "SINISTRA path[" << i << "].x = " << path[i].x << " y = " << path[i].x);
//    }
    return result;
}

bool GamePlay::_esisteCamminoOrizzontaleSinistra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerX > 0) {
            result = _esisteCamminoOrizzontaleSinistra(checkerX-1, checkerY, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY][checkerX-1] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoDiagonaleQuadrante1(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX < DATA_GRID_W-1 && checkerY > 0) {
        result = _esisteCamminoDiagonaleQuadrante1(checkerX+1, checkerY-1, color, path, pathIndex);
    }
    return result;
}

bool GamePlay::_esisteCamminoDiagonaleQuadrante1(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerX < DATA_GRID_W-1 && checkerY > 0) {
            result = _esisteCamminoDiagonaleQuadrante1(checkerX+1, checkerY-1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY-1][checkerX+1] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoDiagonaleQuadrante2(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])    
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX > 0 && checkerY > 0) {
        result = _esisteCamminoDiagonaleQuadrante2(checkerX-1, checkerY-1, color, path, pathIndex);
    }
    return result;
}

bool GamePlay::_esisteCamminoDiagonaleQuadrante2(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerX > 0 && checkerY > 0) {
            result = _esisteCamminoDiagonaleQuadrante2(checkerX-1, checkerY-1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY-1][checkerX-1] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoDiagonaleQuadrante3(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX > 0 && checkerY < DATA_GRID_H-1) {
        result = _esisteCamminoDiagonaleQuadrante3(checkerX-1, checkerY+1, color, path, pathIndex);
    }
    return result;
}

bool GamePlay::_esisteCamminoDiagonaleQuadrante3(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if (checkerX > 0 && checkerY < DATA_GRID_H-1) {
            result = _esisteCamminoDiagonaleQuadrante3(checkerX-1, checkerY+1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY+1][checkerX-1] == color) {
                result = true;
            }
        }
    }
    return result;
}

bool GamePlay::esisteCamminoDiagonaleQuadrante4(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8])
{
    bool result = false;
    Utils::fillWithEmptyCoords(path);
    int pathIndex = 0;
    if (checkerX < DATA_GRID_W-1 && checkerY < DATA_GRID_H-1) {
        result = _esisteCamminoDiagonaleQuadrante4(checkerX+1, checkerY+1, color, path, pathIndex);
    }
    return result;
}

bool GamePlay::_esisteCamminoDiagonaleQuadrante4(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex)
{
    bool result = false;
    int opponentColor=otherColor(color);
    if (inGameContext.dataGrid[checkerY][checkerX] == opponentColor) {
        path[pathIndex].x=checkerX;
        path[pathIndex].y=checkerY;
        ++pathIndex;
        if ((checkerX < (DATA_GRID_W-1)) && (checkerY < (DATA_GRID_H-1))) {
            result = _esisteCamminoDiagonaleQuadrante4(checkerX+1, checkerY+1, color, path, pathIndex);
            if (inGameContext.dataGrid[checkerY+1][checkerX+1] == color) {
                result = true;
            }
        }
    }
    return result;
}

checkerboardCoord GamePlay::update()
{
    checkerboardCoord computerMove;
    computerMove.x = -1;
    computerMove.y = -1;
    if (whoseTurn == inGameContext.opponentColor) {
        MYLOG_DEBUG( "Tocca al COMPUTER");
        computerMove = opponentMove();
        whoseTurn = inGameContext.playerColor;
    }
    return computerMove;
}

checkerboardCoord GamePlay::opponentMove()
{
    checkerboardCoord mosseValide[64];
    trovaMossePossibili(inGameContext.opponentColor, mosseValide);
    checkerboardCoord mossaMigliore = {-1, -1};
    MYLOG_DEBUG( "algoritmoAI = " << algoritmoAI);
    switch (algoritmoAI) {
        case AI_RANDOM: {
            MYLOG_DEBUG( "AI = Random");
            mossaMigliore = trovaMossaMigliore(mosseValide, &GamePlay::bestMove_Random);
            break;
        }
        case AI_LONGEST_PATH: {
            MYLOG_DEBUG( "AI = Longest path");
            mossaMigliore = trovaMossaMigliore(mosseValide, &GamePlay::bestMove_Longest);
            break;
        }
        case AI_BEST_ALGORITHMIC: {
            break;
        }
        case AI_THINK: {
            MYLOG_DEBUG( "AI = Think");
            mossaMigliore = ai.trovaMossaMigliore(inGameContext.dataGrid);
            break;
        }
    }
    
    return mossaMigliore;
}

int GamePlay::trovaMossePossibili(int color, checkerboardCoord (&mosseValide)[64])
{
    Utils::fillWithEmptyCoords(mosseValide);
    
    int k=0;
    for (int i=0; i<DATA_GRID_H; ++i) {
        for (int j=0; j<DATA_GRID_W; ++j) {
            if (canPutPieceAt(j, i, color)){
//                MYLOG_DEBUG( "Posso andare in: y= " << i << " x= " << j);
                mosseValide[k].y=i;
                mosseValide[k].x=j;
                ++k;
            }
        }
    }
    return k;
}

checkerboardCoord GamePlay::trovaMossaMigliore(checkerboardCoord (&mosseValide)[64], bestMoveFunctionType bestFunction)
{
    checkerboardCoord result;
    result = ((this)->*(bestFunction))(mosseValide);
    return result;
}

checkerboardCoord GamePlay::bestMove_Longest(checkerboardCoord (&mosseValide)[64])
{
    checkerboardCoord best;
    int maxGain = -1;
    int gain;
    int chosenMoveIndex = -1;
    for (int i = 0; i < 64; i++) {
        if (mosseValide[i].x == -1 && mosseValide[i].x == -1) {
            break;
        }
        else {
            gain = getGainCountAt(mosseValide[i].x, mosseValide[i].y, inGameContext.opponentColor);
            MYLOG_DEBUG("gain = " << gain);
            if (gain > maxGain) {
                chosenMoveIndex = i;
                maxGain = gain;
            }
        }
    }
    if (chosenMoveIndex != -1) {
        MYLOG_DEBUG("maxGain = " << maxGain);
        best = mosseValide[chosenMoveIndex];
    }
    else {
        best = mosseValide[0];
    }
    return best;
}

checkerboardCoord GamePlay::bestMove_Random(checkerboardCoord (&mosseValide)[64])
{
    checkerboardCoord best;
    int lastMove = 64;
    for (int i = 0; i < 64; i++) {
        if (mosseValide[i].x == -1 && mosseValide[i].x == -1) {
            lastMove = i;
            break;
        }
    }
    int chosenMoveIndex = rand() % lastMove;
    MYLOG_DEBUG("chosenMoveIndex = " << chosenMoveIndex);
    best = mosseValide[chosenMoveIndex];
    return best;
}

int GamePlay::otherColor(int color)
{
    int theOtherColor = (color == BLACK_PIECE ? WHITE_PIECE : BLACK_PIECE);
    return theOtherColor;
}

int GamePlay::getGainCountAt(int checkerX, int checkerY, int color)
{
    int gain = 0;
    if (inGameContext.dataGrid[checkerY][checkerX] == NO_PIECE) {
        gain = inGameContext.gamePlay.calcGainCount(checkerX, checkerY, color);
    }
    return gain;
}

int GamePlay::calcGainCount(int checkerX, int checkerY, int color)
{
    int gain = 0;
    checkerboardCoord path[8];
    
    Utils::fillWithEmptyCoords(moveResultMatrix);
    
    if (esisteCamminoVerticaleSu(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[0], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoVerticaleGiu(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[1], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoOrizzontaleDestra(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[2], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoOrizzontaleSinistra(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[3], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoDiagonaleQuadrante1(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[4], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoDiagonaleQuadrante2(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[5], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoDiagonaleQuadrante3(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[6], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    if (esisteCamminoDiagonaleQuadrante4(checkerX, checkerY, color, path)) {
        memcpy(moveResultMatrix[7], path, sizeof(checkerboardCoord)*8);
        gain += pathLength(path);
    }
    
//    MYLOG_DEBUG( "isMossaValida? " << result);

    return gain;
}

int GamePlay::pathLength(checkerboardCoord (&path)[8])
{
    int length = 0;
    for (int i = 0; i < 8; i++) {
        if (path[i].x != -1 && path[i].y != -1) {
            length++;
        }
        else {
            break;
        }
    }
    return length;
}