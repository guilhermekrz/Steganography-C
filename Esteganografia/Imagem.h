#ifndef IMAGEM_H
#define IMAGEM_H

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

#include "sPixel.h"
#include <string>

using namespace std;

class Imagem
{
public:
    Imagem();
    Imagem(const char n[]);
    int carregar();
    int getAltura();
    int getLargura();
    void convertParaTonsCinzas();
    void setSurface(SDL_Surface* surf);
    SDL_Surface* getSurface();
    void salvar();
    void salvar(const char novoNome[]);
    void freeSurface();
    char* getNome();
    int mostrarImagem();
    double quantasVezesMaior(Imagem* outraImagem);
protected:
private:
    SDL_Surface* img;
    char nome[50];
};

#endif // IMAGEM_H
