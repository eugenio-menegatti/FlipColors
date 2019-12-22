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

#include "Background.h"
#include "main.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

Background::Background()
{
    graphicsPath = myContext.base_res_path + BACKGROUND_PATH;
}

Background::~Background()
{
}

void Background::draw(SDL_Surface *screen)
{
    if (screen!=NULL) {
        SDL_Rect coords;
        coords.x = x;
        coords.y = y;
        blit(screen, coords);
    }
}

void Background::init(string filename)
{
    surface = NULL;
    x = y = 0;
    loadBitmap(filename);
}

float Background::getX()
{
    return x;
}

float Background::setX(float x)
{
    this->x = x;
    return x;
}

float Background::getY()
{
    return y;
}

float Background::setY(float y)
{
    this->y = y;
    return y;
}
