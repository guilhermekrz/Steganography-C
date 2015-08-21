#ifndef DEFS_H
#define DEFS_H

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

#include <iostream>
#include <fstream>
#include "Imagem.h"
#include "EsconderP1.h"
#include "EsconderP2.h"
#include "EsconderTC.h"
#include "EsconderP4.h"
#include "EsconderP5.h"
#include "EsconderP6.h"
#include "EsconderPrograma.h"

using namespace std;

int carregamento();

Imagem carregarImagem(string nomeImagemTemp);

//políticas
int politica1Esconder(string simGrande, string simPequena);
int politica1EsconderPintando(string simGrande, string simPequena);
int politica1Descobrir(string simGrande);
int politica2Esconder(string simGrande, string simPequena);
int politica2EsconderPintando(string simGrande, string simPequena);
int politica2Descobrir(string simGrande);
int politica3Esconder(string simGrande, string simPequena);
int politica3EsconderPintando(string simGrande, string simPequena);
int politica3Descobrir(string simGrande);
int politica4Esconder(string simGrande, string simPequena);
int politica4EsconderPintando(string simGrande, string simPequena);
int politica4Descobrir(string simGrande);
int politica5Esconder(string simGrande, string simPequena);
int politica5EsconderPintando(string simGrande, string simPequena);
int politica5Descobrir(string simGrande);
int politica6Esconder(string simGrande, string simPequena);
int politica6EsconderPintando(string simGrande, string simPequena);
int politica6Descobrir(string simGrande);

//code
int esconderCodigo(char nomeArquivo[], string simGrande);
int executarCodigo(string simGrande);


//salvar
int salvarImagem(Imagem* im);

//
int outraPolitica(string simGrande, string simPequena);

void imprimirIncorreta();

#endif
