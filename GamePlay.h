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

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "AI.h"
#include "TypeDefs.h"

class GamePlay
{
    typedef checkerboardCoord (GamePlay::*bestMoveFunctionType)(checkerboardCoord (&mosse)[64]);

protected:
    AI ai;
    
public:
    int whoseTurn;
    checkerboardCoord moveResultMatrix[8][8];
    int algoritmoAI;

public:
    GamePlay();
    ~GamePlay();
    
    bool canPutPieceAt(int checkerX, int checkerY, int color);
    bool buildMoveResultMatrix(int checkerX, int checkerY, int color);
    checkerboardCoord update();
    int trovaMossePossibili(int color, checkerboardCoord (&mosseValide)[64]);
    void dumpMoveResultMatrix();
    int numeroCaselleLibere();
    int getGainCountAt(int checkerX, int checkerY, int color);
    
protected:
    checkerboardCoord opponentMove();
    checkerboardCoord trovaMossaMigliore(checkerboardCoord (&mosseValide)[64], bestMoveFunctionType bestFunction);
    checkerboardCoord bestMove_Random(checkerboardCoord (&mosseValide)[64]);
    checkerboardCoord bestMove_Longest(checkerboardCoord (&mosseValide)[64]);
    bool isMossaValida(int checkerX, int checkerY, int color);
    bool esisteCamminoVerticaleSu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoVerticaleGiu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoOrizzontaleDestra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoOrizzontaleSinistra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoDiagonaleQuadrante1(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoDiagonaleQuadrante2(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoDiagonaleQuadrante3(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    bool esisteCamminoDiagonaleQuadrante4(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8]);
    int calcGainCount(int checkerX, int checkerY, int color);
    int pathLength(checkerboardCoord (&path)[8]);
    
private:
    int otherColor(int color);
    bool _esisteCamminoVerticaleSu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoVerticaleGiu(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoOrizzontaleDestra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoOrizzontaleSinistra(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoDiagonaleQuadrante1(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoDiagonaleQuadrante2(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoDiagonaleQuadrante3(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
    bool _esisteCamminoDiagonaleQuadrante4(int checkerX, int checkerY, int color, checkerboardCoord (&path)[8], int pathIndex);
};

#endif // GAMEPLAY_H
