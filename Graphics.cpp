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

#include "Graphics.h"
#include "main.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "MyLog.h"

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
}

SDL_Surface *Graphics::loadSurface(string &filename)
{
    //The final optimized image
//    SDL_Surface* optimizedSurface = NULL;
    string res(graphicsPath);
    res += filename;
    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load( res.c_str() );
    if ( loadedSurface == NULL ) {
//        sprintf( errorStr, "Unable to load image %s - SDL_image Error: %s\n", filename.c_str(), IMG_GetError() );
//        myContext.getLogger()->debug(errorStr);
        MYLOG_DEBUG( "Unable to load image " + filename + " - SDL_image Error: " + IMG_GetError())
    }
    else {
        /*
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
         * */
    }

//    return optimizedSurface;
    return loadedSurface;
}

void Graphics::loadPNG(string &filename)
{
    surface = loadSurface(filename);
}

void Graphics::loadBMP(string &filename)
{
    SDL_Surface *s;
    char res[255];
    strcpy(res, graphicsPath.c_str());
    strcat(res, filename.c_str());
    MYLOG_DEBUG( "res=" << res);
    s = SDL_LoadBMP( res );
    if (s==NULL) {
        MYLOG_DEBUG( "Bmp: %s\n" << SDL_GetError( ) );
    }
    else {
        surface = s;
    }
}

void Graphics::loadBitmap(string &filename)
{
    MYLOG_DEBUG( filename << " NON e' in cache" );
    char fileExtension[4];
    char *indexOfDot = strstr(filename.c_str(),".");
    if (indexOfDot == NULL) {
        return;
    }
    strcpy(fileExtension, indexOfDot + sizeof(char));
    
    if (strcmp(fileExtension, "bmp")==0) {
        loadBMP(filename);
    }
    else if (strcmp(fileExtension, "png")==0) {
        loadPNG(filename);
    }
    MYLOG_DEBUG( "surface=" << surface );
}

void Graphics::blit(SDL_Surface *screen, SDL_Rect &coords)
{
    if (surface!=NULL) {
        SDL_BlitSurface(surface, NULL, screen, &coords);
    }
}
