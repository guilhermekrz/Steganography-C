#ifndef ESCONDERPROGRAMA_H
#define ESCONDERPROGRAMA_H

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
#include <sstream>
#include <fstream>
#include "MPixels.h"

class EsconderPrograma
{
public:
    //hide
    static void esconderArquivo(char nomeArquivo[],Imagem* grande);
    int static pixelInicial(Imagem* grande);
    //show
    static void runArquivo(Imagem* escondida);
    static string mostrarTexto(Imagem* escondida);
    int static getPixelInicial(Imagem* grande);
protected:
private:
    void static esconderLetra(char letra,Pixel* pixelsGrande,int& lugarGrande);
    void static esconderTexto(string s,Imagem* grande);
    char static pegarLetra(Pixel* pixelsGrande, int& lugarGrande);
};

#endif // ESCONDERPROGRAMA_H
