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

#ifndef __MainGameArea__
#define __MainGameArea__
#include "Sprite.h"
#include "GamePlay.h"
#include "Utils.h"
#include "wxformbuilder.h"
#include <SDL.h>

#undef DEBUG_PASS_FUNCTION

class MainGameArea : public GameArea
{
public:
    static const unsigned GAME_AREA_HEIGHT = 512;
    static const unsigned GAME_AREA_WIDTH = 512;
    bool gameOver;
protected:
    bool computerTriedToMove, playerTriedToMove;
    int passCount;
    bool autoPass;

public:
    MainGameArea(wxWindow* parent);
    virtual ~MainGameArea();
    
    SDL_Surface *screen;
    
    bool sdlInit;
    bool sdlImageInit;
    
    void initConfigFromUI(uiParamsType &uiParams);
    void initSDL();
    void initSDL_Libs();
    void initSDL_Image();
    void initVideoMode();
    void quitSDL();
    void quitSDL_Image();
    void mainGameLoop();

protected:
    bool playerPasses();
    bool computerPasses();
    bool playerMustPass();
    bool isGameOver();
    void showGameOver();
    void gameOverLoop();
    int checkWinner();
    void applyPhysics();
    void updateScene();
    void mouseFineEvents();
    SDL_Rect mouseMotion();
    void mouseActions(SDL_Rect &mouseCoords);
    void putPieceAt(int mouseX, int mouseY);
    void updateGamePlay();
    void updateDataGrid(int checkerX, int checkerY, int color, checkerboardCoord (&moveResultMatrix)[8][8]);

private:
    void test_Draw();
    void test_Bitmap();

};
#endif // __MainGameArea__

