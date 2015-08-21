#ifndef MPIXELS_H
#define MPIXELS_H

#include "sPixel.h"
#include <iostream>

using namespace std;

class MPixels
{
public:
    //só esconder no menor bit
    static int esconderBitMenorBit(int bit, int num);
    static void esconderPixel(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande);
    static int esconderNumeroEm4Pixels(int numero,Pixel* pixelsGrande,int& lugarGrande);
    static int pegarNumeroEm4Pixels(Pixel* pixelsGrande,int& lugarGrande);
    static Pixel pegarPixel(Pixel* pixelsGrande,int& lugarGrande);

    //esconder nos dois menores bits
    static int esconder2BitsMenorBit(int bits, int num);
    static void esconderPixel2(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande);
    static int esconderNumeroEm2Pixels(int numero,Pixel* pixelsGrande,int& lugarGrande);
    static int pegarNumeroEm2Pixels(Pixel* pixelsGrande,int& lugarGrande);
    static Pixel pegarPixel2(Pixel* pixelsGrande,int& lugarGrande);

    //esconder nos tres menores bits
    static int esconder3BitsMenorBit(int bits, int num);

    //esconder nos quatros menores bits
    static int esconder4BitsMenorBit(int bits, int num);

    //esconder tons de cinza
    static void esconderPixel3(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande);
    static Pixel pegarPixel3(Pixel* pixelsGrande,int& lugarGrande);

    //esconder politica4
    static void esconderPixel4(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande);
    static Pixel pegarPixel4(Pixel* pixelsGrande,int& lugarGrande);
    static int esconderNumeroEm1Pixel(int numero,Pixel* pixelsGrande,int& lugarGrande);
    static int pegarNumeroEm1Pixel(Pixel* pixelsGrande,int& lugarGrande);

    //politica5
    static void esconderPixelContrario(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande);
    static int esconderNumeroEm1PixelContrario(int numero,Pixel* pixelsGrande,int& lugarGrande);
    static Pixel pegarPixelContrario(Pixel* pixelsGrande,int& lugarGrande);
    static int pegarNumeroEm1PixelContrario(Pixel* pixelsGrande,int& lugarGrande);

    //generico
    int static copiarPixel(Pixel* src,Pixel* dest);
    void static imprimirPixel(Pixel* p);
    static bool isIgual(Pixel* p1, Pixel* p2);
protected:
private:
};

#endif // MPIXELS_H
