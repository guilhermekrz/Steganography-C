#ifndef ESCONDERTC_H
#define ESCONDERTC_H

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include "Imagem.h"
#include "sPixel.h"
#include <iostream>
#include "MPixels.h"

#include "Imagem.h"
#include "sPixel.h"
#include <iostream>
#include "MPixels.h"

class EsconderTC
{
public:
    //hide
    int static hide(Imagem* grande,Imagem* pequena);
    int static hidePintando(Imagem* grande,Imagem* pequena);
    int static pixelInicial(Imagem* grande);
    void static esconderAlturaLargura(Pixel* pixelsGrande, int& lugarGrande,int alturaPequena,int larguraPequena);
    //show
    static SDL_Surface* show(Imagem* escondida);
    int static getPixelInicial(Imagem* grande);
    int static getAlturaLargura(Pixel* pixelsGrande, int& lugarGrande,int& alturaPequena,int& larguraPequena);

protected:
private:
    int static pegarNumero(Pixel* pixelsGrande, int& lugarGrande);
};

#endif // ESCONDERTC_H
