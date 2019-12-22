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

#include "main.h"
#include "MainGameArea.h"
#include "PassDialog.h"
#include "MyLog.h"
#include <SDL.h>
#include <SDL_Image.h>

MainGameArea::MainGameArea( wxWindow* parent )
:
GameArea( parent )
{
    sdlInit = false;
    sdlImageInit = false;
    screen = NULL;
    gameOver = false;
    computerTriedToMove = false;
    playerTriedToMove = false;
    passCount = 0;
    autoPass = true;
}

MainGameArea::~MainGameArea()
{
    quitSDL();
    quitSDL_Image();
}

void MainGameArea::quitSDL()
{
    if (sdlInit) {
        SDL_Quit();
    }
}

void MainGameArea::quitSDL_Image()
{
    if (sdlImageInit) {
        IMG_Quit();
    }
}

void MainGameArea::initSDL()
{
    MYLOG_DEBUG( "Init SDL")
    if (SDL_Init(SDL_INIT_EVERYTHING /*SDL_INIT_VIDEO*/) != -1) {
        sdlInit = true;
    }
    else {
        MYLOG_DEBUG( "Error initializing SDL: " << SDL_GetError())
        sdlInit = false;
    }
}

void MainGameArea::initSDL_Libs()
{
    initSDL_Image();
}

void MainGameArea::initSDL_Image()
{
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        MYLOG_DEBUG( "Error initializing SDL_Image: " << IMG_GetError())
    }
    else {
        sdlImageInit = true;
    }
}

void MainGameArea::initVideoMode()
{
    int width = 0;
    int height = 0;
    int bpp = 0;        /* Color depth in bits of our window. */
    int flags = 0;
    const SDL_VideoInfo* info = NULL;
    
    flags = SDL_SWSURFACE /*SDL_OPENGL | SDL_FULLSCREEN*/;
    info = SDL_GetVideoInfo( );

    if( !info ) {
        MYLOG_DEBUG( "Video query failed: " << SDL_GetError( ) )
    }

    width = GAME_AREA_WIDTH;
    height = GAME_AREA_HEIGHT;
    bpp = info->vfmt->BitsPerPixel;
    
    screen = SDL_SetVideoMode( width, height, bpp, flags );
    
    if( screen == NULL ) {
        MYLOG_DEBUG( "Video mode set failed: " << SDL_GetError( ) )
    }
    
    #ifdef TEST_DRAW 
        test_Draw();
        test_Bitmap();
    #endif
}

void MainGameArea::test_Bitmap()
{
    SDL_Surface *s;
    s = SDL_LoadBMP( "hello.bmp" );
    sprintf( errorStr, "Bmp: %s\n", SDL_GetError( ) );
    MYLOG_DEBUG(errorStr);
    
//    SDL_Surface *screen = SDL_GetVideoSurface();
    SDL_BlitSurface(s, NULL, screen, NULL);
    MYLOG_DEBUG( "Blit: %s\n" << SDL_GetError( ) )
    SDL_Flip( screen );
    SDL_FreeSurface(s);
}

void MainGameArea::test_Draw()
{
    int width = 50;
    int height = 50;
    SDL_Surface *s;
    s = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0, 0, 0, 0);
    if ( s == NULL) {
        MYLOG_DEBUG( "Blit: " << SDL_GetError( ) )
    }
    SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));
    MYLOG_DEBUG( "Bmp: %s\n" << SDL_GetError() )
    
//    SDL_Surface *screen = SDL_GetVideoSurface();
    SDL_BlitSurface(s, NULL, screen, NULL);
    
    MYLOG_DEBUG( "Blit: " << SDL_GetError( ) );
    SDL_Flip( screen );
    SDL_FreeSurface(s);
}

void MainGameArea::mainGameLoop()
{
    MYLOG_DEBUG( "Main loop start")
    bool done=false;
    
    int mouseX, mouseY;
    
    while ( !done && !gameOver ) {
        SDL_Event event;

        while ( SDL_PollEvent(&event) ) {
            if ( event.type == SDL_QUIT ) {
                done = true;
            }
            if ( event.type == SDL_KEYDOWN ) {
                if ( event.key.keysym.sym == SDLK_ESCAPE ) {
                    done = true; 
                }
            }
            else if ( event.type == SDL_MOUSEBUTTONDOWN) {
                if ( event.button.button == SDL_BUTTON_LEFT ) {
                    mouseX = event.motion.x;
                    mouseY = event.motion.y;
                    MYLOG_DEBUG( "PRESS: left mouse");
                    playerTriedToMove = true;
                    putPieceAt(mouseX, mouseY);
                }
            }
        }
    
        SDL_Rect mouseCoords = mouseMotion();
        mouseActions(mouseCoords);
        updateGamePlay();
//        MYLOG_DEBUG( "passCount = " << passCount);
        applyPhysics();
        updateScene();
        if (playerTriedToMove || computerTriedToMove) {
            gameOver = isGameOver();
        }
    }
    
    if (gameOver) {
        showGameOver();
    }
    
    MYLOG_DEBUG( "Main loop end")
}

void MainGameArea::showGameOver()
{
    Sprite gameOver;
    Sprite whoWon;
    
    gameOver.init("gameover.png");
    gameOver.setY(256);
    
    MYLOG_DEBUG( "Game over")
    int winner = checkWinner();
    switch (winner) {
        case WHITE_PIECE: {
            MYLOG_DEBUG( "Vince il BIANCO")
            whoWon.init("white-wins.png");
            break;
        }
        case BLACK_PIECE: {
            MYLOG_DEBUG( "Vince il NERO")
            whoWon.init("black-wins.png");
            break;
        }
        case -1: {
            MYLOG_DEBUG( "PARITA'")
            whoWon.init("pari.png");
            break;
        }
    }
    whoWon.draw(screen);
    gameOver.draw(screen);
    SDL_Flip(screen);
    gameOverLoop();
}

void MainGameArea::gameOverLoop()
{
    bool done = false;
    
    while( !done ) {
        SDL_Event event;

        while ( SDL_PollEvent(&event) ) {
        if ( event.type == SDL_QUIT ) {
            done = true;
        }
        if ( event.type == SDL_KEYDOWN )
            if ( event.key.keysym.sym == SDLK_ESCAPE ) done = true; 
        }
    
    }
}

int MainGameArea::checkWinner()
{
    int playerCount = 0, opponentCount = 0;
    int winner;
    
    for (int y=0; y<DATA_GRID_H; ++y) {
        for (int x=0; x<DATA_GRID_W; ++x) {
            if (inGameContext.dataGrid[y][x] == inGameContext.playerColor) {
                ++playerCount;
            }
            else if (inGameContext.dataGrid[y][x] == inGameContext.opponentColor) {
                ++opponentCount;
            }
        }
    }
    if (playerCount > opponentCount) {
        winner = inGameContext.playerColor;
    }
    else if (opponentCount > playerCount) {
        winner = inGameContext.opponentColor;
    }
    else {
        winner = -1;
    }
    return winner;
}

bool MainGameArea::isGameOver()
{
    bool result = false;
    int quanteCaselleLibere = 0;
    quanteCaselleLibere = inGameContext.gamePlay.numeroCaselleLibere();
    if (quanteCaselleLibere == 0) {
        result = true;
    }
    else {
        if (passCount >= 2) {
            MYLOG_DEBUG( "No more moves")
            result = true;
        }
    }
    return result;
}

bool MainGameArea::playerMustPass()
{
    bool result = false;
    checkerboardCoord mosseValide[64];
    int quanteMossePossibili = 0;
    quanteMossePossibili = inGameContext.gamePlay.trovaMossePossibili(inGameContext.playerColor, mosseValide);
    if (quanteMossePossibili == 0) {
        result = true;
    }
#ifdef DEBUG_PASS_FUNCTION
    return true;
#else
    return result;
#endif
}

void MainGameArea::updateGamePlay()
{
    if (inGameContext.gamePlay.whoseTurn == inGameContext.opponentColor) {
        computerTriedToMove = true;

        checkerboardCoord opponentMove = inGameContext.gamePlay.update();
        if (opponentMove.x != -1) {
            MYLOG_DEBUG( "Il computer (" <<
                (inGameContext.opponentColor == BLACK_PIECE ? "BLACK" : "WHITE")
                << ") muove in x=" << opponentMove.x << " y=" << opponentMove.y);
            bool isValidMatrix = false;
            isValidMatrix = inGameContext.gamePlay.buildMoveResultMatrix(opponentMove.x, opponentMove.y, inGameContext.opponentColor);
            if (isValidMatrix) {
                MYLOG_DEBUG( "Mossa valida");
                updateDataGrid(opponentMove.x, opponentMove.y, inGameContext.opponentColor, inGameContext.gamePlay.moveResultMatrix);
            }
            else {
                MYLOG_DEBUG( "ERRORE: Il computer non riesce a muovere");
                gameOver = true;
            }
            passCount = 0;
            MYLOG_DEBUG( "Tocca al GIOCATORE");
        }
        else {
            MYLOG_DEBUG( "Il COMPUTER passa");
            computerPasses();
        }
    }
    if (inGameContext.gamePlay.whoseTurn == inGameContext.playerColor) {
        if (playerMustPass()) {
            MYLOG_DEBUG( "Il GIOCATORE passa");
            playerPasses();
        }
        else {
            passCount = 0;
        }
    }
}

void MainGameArea::updateDataGrid(int checkerX, int checkerY, int color, checkerboardCoord (&moveResultMatrix)[DATA_GRID_H][DATA_GRID_W])
{
    inGameContext.displayGrid[checkerY][checkerX] = color;
    inGameContext.dataGrid[checkerY][checkerX] = color;
    for (int i=0; i<DATA_GRID_H; ++i) {
        for (int j=0; moveResultMatrix[i][j].x!=-1; ++j) {
//            MYLOG_DEBUG( "y=" << moveResultMatrix[i][j].y << " x=" << moveResultMatrix[i][j].x);
            inGameContext.displayGrid[moveResultMatrix[i][j].y][moveResultMatrix[i][j].x] = color;
            inGameContext.dataGrid   [moveResultMatrix[i][j].y][moveResultMatrix[i][j].x] = color;
        }
    }
    inGameContext.dumpDataGrid();
}

void MainGameArea::putPieceAt(int mouseX, int mouseY)
{
    int checkerX = mouseX / CHECKER_W_PIXEL;
    int checkerY = mouseY / CHECKER_H_PIXEL;
    MYLOG_DEBUG( "Il GIOCATORE vuole muovere in: y=" << checkerY << " x=" <<checkerX);
    if (inGameContext.gamePlay.canPutPieceAt(checkerX, checkerY, inGameContext.playerColor)) {
        MYLOG_DEBUG( "Puo' farlo");
//        inGameContext.gamePlay.dumpMoveResultMatrix();
        updateDataGrid(checkerX, checkerY, inGameContext.playerColor, inGameContext.gamePlay.moveResultMatrix);
        inGameContext.gamePlay.whoseTurn = inGameContext.opponentColor;
    }
    else {
        MYLOG_DEBUG( "NON puo' farlo");
    }
}

void MainGameArea::applyPhysics()
{
}

void MainGameArea::updateScene()
{
    inGameContext.background.draw(screen);
    
    for (int i=0; i<DATA_GRID_H; ++i) {
        for (int j=0; j<DATA_GRID_W; ++j) {
            Sprite *pedina;
            int casella = inGameContext.displayGrid[i][j];
            if ( casella != NO_PIECE) {
                switch (casella) {
                    case WHITE_PIECE: {
                        pedina = &(inGameContext.pedinaBianca);
                        break;
                    }
                    case BLACK_PIECE: {
                        pedina = &(inGameContext.pedinaNera);
                        break;
                    }
                    case SELECTION_PIECE: {
                        pedina = &(inGameContext.selectionPiece);
                        break;
                    }
                }
                pedina->setX(j*CHECKER_W_PIXEL);
                pedina->setY(i*CHECKER_H_PIXEL);
                pedina->draw(screen);
            }
        }
    }
//    inGameContext.pedinaBianca.draw(screen);
//    inGameContext.pedinaNera.draw(screen);
    SDL_Flip(screen);
}

SDL_Rect MainGameArea::mouseMotion()
{
    SDL_Rect result;
    int x, y;
    static int prevX=0, prevY=0;
    SDL_GetMouseState(&x, &y);

    result.x = prevX;
    result.y = prevY;
    result.w = x;
    result.h = y;
    
    if (x != prevX) {
        prevX = x;
    }
    if (y != prevY) {
        prevY = y;
    }
    
    return result;
}

void MainGameArea::mouseFineEvents()
{
    // Utilizzare se si vuole sapere quanto tempo il pulsante sta premuto
    int x, y;
    
    if ( SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        MYLOG_DEBUG( "Mouse Button 1 (left) is pressed.");
    }
    if ( SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        MYLOG_DEBUG( "Mouse Button 2 (right) is pressed.");
    }
}

void MainGameArea::mouseActions(SDL_Rect &mouseCoords)
{
    static int previousChecker = 0;

//    MYLOG_DEBUG( "mouseActions BEGIN" );
    int checkerX = mouseCoords.x / CHECKER_W_PIXEL;
    int checkerY = mouseCoords.y / CHECKER_H_PIXEL;
    
    int currentChecker = checkerY * DATA_GRID_W + checkerX;
    
    if (currentChecker != previousChecker ) {
//        MYLOG_DEBUG( "currentChecker = " << currentChecker );
        
        int previousX = previousChecker / DATA_GRID_W;
        int previousY = previousChecker % DATA_GRID_W;
        inGameContext.displayGrid[previousX][previousY] = inGameContext.dataGrid[previousX][previousY];
        inGameContext.displayGrid[checkerY][checkerX]=SELECTION_PIECE;
        
        previousChecker = currentChecker;
    }
//    MYLOG_DEBUG( "mouseActions END" );
}

void MainGameArea::initConfigFromUI(uiParamsType &uiParams)
{
    inGameContext.playerColor = uiParams.playerColor;
    if (uiParams.playerColor == BLACK_PIECE) {
        inGameContext.opponentColor = WHITE_PIECE;
    }
    else {
        inGameContext.opponentColor = BLACK_PIECE;
    }
    
    autoPass = uiParams.autoPass;
    
    inGameContext.gamePlay.algoritmoAI = uiParams.algoritmoAI;
}

bool MainGameArea::playerPasses()
{
    bool result = false;
    if (!autoPass) {
        PassDialog *passDialog = new PassDialog(this);
        if (passDialog != NULL) {
            passDialog->setChiPassa(PLAYER_PASSES);
            passDialog->ShowModal();
            passDialog->Destroy();
        }
    }
    inGameContext.gamePlay.whoseTurn = inGameContext.opponentColor;
    ++passCount;
    return result;
}

bool MainGameArea::computerPasses()
{
    bool result = false;
    if (!autoPass) {
        PassDialog *passDialog = new PassDialog(this);
        if (passDialog != NULL) {
            passDialog->setChiPassa(COMPUTER_PASSES);
            passDialog->ShowModal();
            passDialog->Destroy();
        }
    }
    inGameContext.gamePlay.whoseTurn = inGameContext.playerColor;
    ++passCount;
    return result;
}
