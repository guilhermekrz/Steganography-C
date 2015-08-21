#include "MPixels.h"

void MPixels::esconderPixel(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande)
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7 - bit 0
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 1, 2, 3
    Pixel* p5 = &pixelsGrande[lugarGrande+4]; //bit 4, 5, 6
    Pixel* p6 = &pixelsGrande[lugarGrande+5]; //bit 7 - bit 0, 1
    Pixel* p7 = &pixelsGrande[lugarGrande+6]; //bit 2, 3, 4
    Pixel* p8 = &pixelsGrande[lugarGrande+7]; //bit 5, 6, 7
    lugarGrande = lugarGrande+8; //para o proximo

    int numR = peq->r;
    int numG = peq->g;
    int numB = peq->b;

    //ESCONDIDA DO R
    p1->r = MPixels::esconderBitMenorBit(numR%2,p1->r); //bit 0
    numR = numR/2;
    p1->g = MPixels::esconderBitMenorBit(numR%2,p1->g); //bit 1
    numR = numR/2;
    p1->b = MPixels::esconderBitMenorBit(numR%2,p1->b); //bit 2
    numR = numR/2;
    p2->r = MPixels::esconderBitMenorBit(numR%2,p2->r); //bit 3
    numR = numR/2;
    p2->g = MPixels::esconderBitMenorBit(numR%2,p2->g); //bit 4
    numR = numR/2;
    p2->b = MPixels::esconderBitMenorBit(numR%2,p2->b); //bit 5
    numR = numR/2;
    p3->r = MPixels::esconderBitMenorBit(numR%2,p3->r); //bit 6
    numR = numR/2;
    p3->g = MPixels::esconderBitMenorBit(numR%2,p3->g); //bit 7
    //COMPLETADO a escondida do R

    //ESCONDIDA DO G
    p3->b = MPixels::esconderBitMenorBit(numG%2,p3->b); //bit 0
    numG = numG/2;
    p4->r = MPixels::esconderBitMenorBit(numG%2,p4->r); //bit 1
    numG = numG/2;
    p4->g = MPixels::esconderBitMenorBit(numG%2,p4->g); //bit 2
    numG = numG/2;
    p4->b = MPixels::esconderBitMenorBit(numG%2,p4->b); //bit 3
    numG = numG/2;
    p5->r = MPixels::esconderBitMenorBit(numG%2,p5->r); //bit 4
    numG = numG/2;
    p5->g = MPixels::esconderBitMenorBit(numG%2,p5->g); //bit 5
    numG = numG/2;
    p5->b = MPixels::esconderBitMenorBit(numG%2,p5->b); //bit 6
    numG = numG/2;
    p6->r = MPixels::esconderBitMenorBit(numG%2,p6->r); //bit 7
    //COMPLETADO a escondida do G

    //ESCONDIDA DO B
    p6->g = MPixels::esconderBitMenorBit(numB%2,p6->g); //bit 0
    numB = numB/2;
    p6->b = MPixels::esconderBitMenorBit(numB%2,p6->b); //bit 1
    numB = numB/2;
    p7->r = MPixels::esconderBitMenorBit(numB%2,p7->r); //bit 2
    numB = numB/2;
    p7->g = MPixels::esconderBitMenorBit(numB%2,p7->g); //bit 3
    numB = numB/2;
    p7->b = MPixels::esconderBitMenorBit(numB%2,p7->b); //bit 4
    numB = numB/2;
    p8->r = MPixels::esconderBitMenorBit(numB%2,p8->r); //bit 5
    numB = numB/2;
    p8->g = MPixels::esconderBitMenorBit(numB%2,p8->g); //bit 6
    numB = numB/2;
    p8->b = MPixels::esconderBitMenorBit(numB%2,p8->b); //bit 7
    //COMPLETADO a escondida do B


}

int MPixels::esconderNumeroEm4Pixels(int numero,Pixel* pixelsGrande,int& lugarGrande)  //bit 0 ao 11 -> até o nº 2048
{
    int num = numero;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7 8
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 9, 10, 11

    p1->r = MPixels::esconderBitMenorBit(num%2,p1->r); //bit 0
    num= num/2;
    p1->g = MPixels::esconderBitMenorBit(num%2,p1->g); //bit 1
    num = num/2;
    p1->b = MPixels::esconderBitMenorBit(num%2,p1->b); //bit 2
    num = num/2;
    p2->r = MPixels::esconderBitMenorBit(num%2,p2->r); //bit 3
    num = num/2;
    p2->g = MPixels::esconderBitMenorBit(num%2,p2->g); //bit 4
    num = num/2;
    p2->b = MPixels::esconderBitMenorBit(num%2,p2->b); //bit 5
    num = num/2;
    p3->r = MPixels::esconderBitMenorBit(num%2,p3->r); //bit 6
    num = num/2;
    p3->g = MPixels::esconderBitMenorBit(num%2,p3->g); //bit 7
    num = num/2;
    p3->b = MPixels::esconderBitMenorBit(num%2,p3->b); //bit 8
    num= num/2;
    p4->r = MPixels::esconderBitMenorBit(num%2,p4->r); //bit 9
    num = num/2;
    p4->g = MPixels::esconderBitMenorBit(num%2,p4->g); //bit 10
    num = num/2;
    p4->b = MPixels::esconderBitMenorBit(num%2,p4->b); //bit 11

    lugarGrande = lugarGrande + 4;

    return 0;
}

int MPixels::pegarNumeroEm4Pixels(Pixel* pixelsGrande,int& lugarGrande)  //bit 0 ao 11 -> até o nº 2048
{
    int num = 0;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7 8
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 9, 10, 11

    if(p1->r%2==0)
    {
    }
    else
    {
        num = num +1;
    }
    if(p1->g%2==0)
    {
    }
    else
    {
        num = num +2;
    }
    if(p1->b%2==0)
    {
    }
    else
    {
        num = num +4;
    }
    if(p2->r%2==0)
    {
    }
    else
    {
        num = num +8;
    }
    if(p2->g%2==0)
    {
    }
    else
    {
        num = num +16;
    }
    if(p2->b%2==0)
    {
    }
    else
    {
        num = num +32;
    }
    if(p3->r%2==0)
    {
    }
    else
    {
        num = num +64;
    }
    if(p3->g%2==0)
    {
    }
    else
    {
        num = num +128;
    }
    if(p3->b%2==0)
    {
    }
    else
    {
        num = num +256;
    }
    if(p4->r%2==0)
    {
    }
    else
    {
        num = num +512;
    }
    if(p4->g%2==0)
    {
    }
    else
    {
        num = num +1024;
    }
    if(p4->b%2==0)
    {
    }
    else
    {
        num = num +2048;
    }

    lugarGrande = lugarGrande + 4;
    return num;
}

Pixel MPixels::pegarPixel(Pixel* pixelsGrande,int& lugarGrande)
{
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7 - bit 0
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 1, 2, 3
    Pixel* p5 = &pixelsGrande[lugarGrande+4]; //bit 4, 5, 6
    Pixel* p6 = &pixelsGrande[lugarGrande+5]; //bit 7 - bit 0, 1
    Pixel* p7 = &pixelsGrande[lugarGrande+6]; //bit 2, 3, 4
    Pixel* p8 = &pixelsGrande[lugarGrande+7]; //bit 5, 6, 7
    lugarGrande = lugarGrande+8; //para o proximo

    //num
    if(p1->r%2==0)
    {
    }
    else
    {
        num = num +1;
    }
    if(p1->g%2==0)
    {
    }
    else
    {
        num = num +2;
    }
    if(p1->b%2==0)
    {
    }
    else
    {
        num = num +4;
    }
    if(p2->r%2==0)
    {
    }
    else
    {
        num = num +8;
    }
    if(p2->g%2==0)
    {
    }
    else
    {
        num = num +16;
    }
    if(p2->b%2==0)
    {
    }
    else
    {
        num = num +32;
    }
    if(p3->r%2==0)
    {
    }
    else
    {
        num = num +64;
    }
    if(p3->g%2==0)
    {
    }
    else
    {
        num = num +128;
    }

    //num1
    if(p3->b%2==0)
    {
    }
    else
    {
        num1 = num1 +1;
    }
    if(p4->r%2==0)
    {
    }
    else
    {
        num1 = num1 +2;
    }
    if(p4->g%2==0)
    {
    }
    else
    {
        num1 = num1 +4;
    }
    if(p4->b%2==0)
    {
    }
    else
    {
        num1 = num1 +8;
    }
    if(p5->r%2==0)
    {
    }
    else
    {
        num1 = num1 +16;
    }
    if(p5->g%2==0)
    {
    }
    else
    {
        num1 = num1 +32;
    }
    if(p5->b%2==0)
    {
    }
    else
    {
        num1 = num1 +64;
    }
    if(p6->r%2==0)
    {
    }
    else
    {
        num1 = num1 +128;
    }

    //num2
    if(p6->g%2==0)
    {
    }
    else
    {
        num2 = num2 +1;
    }
    if(p6->b%2==0)
    {
    }
    else
    {
        num2 = num2 +2;
    }
    if(p7->r%2==0)
    {
    }
    else
    {
        num2 = num2 +4;
    }
    if(p7->g%2==0)
    {
    }
    else
    {
        num2= num2 +8;
    }
    if(p7->b%2==0)
    {
    }
    else
    {
        num2 =num2 +16;
    }
    if(p8->r%2==0)
    {
    }
    else
    {
        num2 = num2 +32;
    }
    if(p8->g%2==0)
    {
    }
    else
    {
        num2 = num2 +64;
    }
    if(p8->b%2==0)
    {
    }
    else
    {
        num2 = num2 +128;
    }

    Pixel p;
    p.r = num;
    p.g = num1;
    p.b = num2;
    p.a = 255;
    return p;
}

int MPixels::esconderBitMenorBit(int bit, int num)
{
//    int novoNum = num;
//    if(novoNum%2==0){ //par
//        if(bit==0){
//        }
//        else{ //bit==1
//            if(novoNum==255){
//                novoNum--;
//            }
//            else{
//                novoNum++;
//            }
//        }
//    }
//    else{ //impar
//        if(bit==0){
//            novoNum++;
//        }
//        else{ //bit==1
//        }
//    }
//    return novoNum;
    return (num & 0xFE) + bit; //bit tem que ser 0 ou 1
}

//esconder nos dois menores bits
int MPixels::esconder2BitsMenorBit(int bits, int num)
{
    return (num & 0xFC) + bits; //bits tem que ser 0, 1, 2 ou 3
}

void MPixels::esconderPixel2(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande)
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 01, 23, 45
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 67 -bit0, 01, 23
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 45, 67 - bit 1, 01
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 23, 45, 67
    lugarGrande = lugarGrande+4; //para o proximo

    int numR = peq->r;
    int numG = peq->g;
    int numB = peq->b;

    //ESCONDIDA DO R
    p1->r = MPixels::esconder2BitsMenorBit(numR%4,p1->r); //bit 01
    numR = numR/4;
    p1->g = MPixels::esconder2BitsMenorBit(numR%4,p1->g); //bit 23
    numR = numR/4;
    p1->b = MPixels::esconder2BitsMenorBit(numR%4,p1->b); //bit 45
    numR = numR/4;
    p2->r = MPixels::esconder2BitsMenorBit(numR%4,p2->r); //bit 67
    //COMPLETADO a escondida do R

    //ESCONDIDA DO G
    p2->g = MPixels::esconder2BitsMenorBit(numG%4,p2->g); //bit 01
    numG = numG/4;
    p2->b = MPixels::esconder2BitsMenorBit(numG%4,p2->b); //bit 23
    numG = numG/4;
    p3->r = MPixels::esconder2BitsMenorBit(numG%4,p3->r); //bit 45
    numG = numG/4;
    p3->g = MPixels::esconder2BitsMenorBit(numG%4,p3->g); //bit 67
    //COMPLETADO a escondida do G

    //ESCONDIDA DO B
    p3->b = MPixels::esconder2BitsMenorBit(numB%4,p3->b); //bit 01
    numB = numB/4;
    p4->r = MPixels::esconder2BitsMenorBit(numB%4,p4->r); //bit 23
    numB = numB/4;
    p4->g = MPixels::esconder2BitsMenorBit(numB%4,p4->g); //bit 45
    numB = numB/4;
    p4->b = MPixels::esconder2BitsMenorBit(numB%4,p4->b); //bit 67
    //COMPLETADO a escondida do B
}

int MPixels::esconderNumeroEm2Pixels(int numero,Pixel* pixelsGrande,int& lugarGrande)  //bit 0 ao 11 -> até o nº 2048
{
    int num = numero;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 01, 23, 45
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 67, 89, 1011

    p1->r = MPixels::esconder2BitsMenorBit(num%4,p1->r); //bit 01
    num= num/4;
    p1->g = MPixels::esconder2BitsMenorBit(num%4,p1->g); //bit 23
    num = num/4;
    p1->b = MPixels::esconder2BitsMenorBit(num%4,p1->b); //bit 45
    num = num/4;
    p2->r = MPixels::esconder2BitsMenorBit(num%4,p2->r); //bit 67
    num = num/4;
    p2->g = MPixels::esconder2BitsMenorBit(num%4,p2->g); //bit 89
    num = num/4;
    p2->b = MPixels::esconder2BitsMenorBit(num%4,p2->b); //bit 1011

    lugarGrande = lugarGrande + 2;

    return 0;
}

int MPixels::pegarNumeroEm2Pixels(Pixel* pixelsGrande,int& lugarGrande)  //bit 0 ao 11 -> até o nº 2048
{
    unsigned int num = 0;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 01, 23, 45
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 67, 89, 1011

    unsigned int auxR = p1->r;
    auxR = auxR & 0x03;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x03;
    auxG = auxG << 2;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x03;
    auxB = auxB << 4;
    num = num + auxB;

    auxR = p2->r;
    auxR = auxR & 0x03;
    auxR = auxR << 6;
    num = num + auxR;

    auxG = p2->g;
    auxG = auxG & 0x03;
    auxG = auxG << 8;
    num = num + auxG;

    auxB = p2->b;
    auxB = auxB & 0x03;
    auxB = auxB << 10;
    num = num + auxB;

    lugarGrande = lugarGrande + 2;
    return num;
}

Pixel MPixels::pegarPixel2(Pixel* pixelsGrande,int& lugarGrande)
{
    unsigned int num = 0;
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 01, 23, 45
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 67 -bit0, 01, 23
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 45, 67 - bit1, 01
    Pixel* p4 = &pixelsGrande[lugarGrande+3]; //bit 23, 45, 67
    lugarGrande = lugarGrande+4; //para o proximo

    //num
    unsigned int auxR = p1->r;
    auxR = auxR & 0x03;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x03;
    auxG = auxG << 2;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x03;
    auxB = auxB << 4;
    num = num + auxB;

    auxR = p2->r;
    auxR = auxR & 0x03;
    auxR = auxR << 6;
    num = num + auxR;

    //num1
    auxG = p2->g;
    auxG = auxG & 0x03;
    num1 = num1+ auxG;

    auxB = p2->b;
    auxB = auxB & 0x03;
    auxB = auxB << 2;
    num1 = num1 + auxB;

    auxR = p3->r;
    auxR = auxR & 0x03;
    auxR = auxR << 4;
    num1 = num1 + auxR;

    auxG = p3->g;
    auxG = auxG & 0x03;
    auxG = auxG << 6;
    num1 = num1 + auxG;

    //num2
    auxB = p3->b;
    auxB = auxB & 0x03;
    num2 = num2 + auxB;

    auxR = p4->r;
    auxR = auxR & 0x03;
    auxG = auxG << 2;
    num2 = num2 + auxR;

    auxG = p4->g;
    auxG = auxG & 0x03;
    auxG = auxG << 4;
    num2 = num2 + auxG;

    auxB = p4->b;
    auxB = auxB & 0x03;
    auxB = auxB << 6;
    num2 = num2 + auxB;

    Pixel p;
    p.r = num;
    p.g = num1;
    p.b = num2;
    p.a = 255;

    return p;
}

//esconder tons de cinza

void MPixels::esconderPixel3(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande)
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7
    lugarGrande = lugarGrande+3; //para o proximo

    int numR = peq->r;
    //r == g == b -> tons de cinza

    //ESCONDIDA DO R
    p1->r = MPixels::esconderBitMenorBit(numR%2,p1->r); //bit 0
    numR = numR/2;
    p1->g = MPixels::esconderBitMenorBit(numR%2,p1->g); //bit 1
    numR = numR/2;
    p1->b = MPixels::esconderBitMenorBit(numR%2,p1->b); //bit 2
    numR = numR/2;
    p2->r = MPixels::esconderBitMenorBit(numR%2,p2->r); //bit 3
    numR = numR/2;
    p2->g = MPixels::esconderBitMenorBit(numR%2,p2->g); //bit 4
    numR = numR/2;
    p2->b = MPixels::esconderBitMenorBit(numR%2,p2->b); //bit 5
    numR = numR/2;
    p3->r = MPixels::esconderBitMenorBit(numR%2,p3->r); //bit 6
    numR = numR/2;
    p3->g = MPixels::esconderBitMenorBit(numR%2,p3->g); //bit 7
    //COMPLETADO a escondida do R
}

Pixel MPixels::pegarPixel3(Pixel* pixelsGrande,int& lugarGrande)
{
    unsigned int num = 0;
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0, 1, 2
    Pixel* p2 = &pixelsGrande[lugarGrande+1]; //bit 3, 4, 5
    Pixel* p3 = &pixelsGrande[lugarGrande+2]; //bit 6, 7
    lugarGrande = lugarGrande+3; //para o proximo

    //num
    if(p1->r%2==0)
    {
    }
    else
    {
        num = num +1;
    }
    if(p1->g%2==0)
    {
    }
    else
    {
        num = num +2;
    }
    if(p1->b%2==0)
    {
    }
    else
    {
        num = num +4;
    }
    if(p2->r%2==0)
    {
    }
    else
    {
        num = num +8;
    }
    if(p2->g%2==0)
    {
    }
    else
    {
        num = num +16;
    }
    if(p2->b%2==0)
    {
    }
    else
    {
        num = num +32;
    }
    if(p3->r%2==0)
    {
    }
    else
    {
        num = num +64;
    }
    if(p3->g%2==0)
    {
    }
    else
    {
        num = num +128;
    }

    Pixel p;
    p.r = num;
    p.g = num;
    p.b = num;
    p.a = 255;
    return p;
}

//generico
int MPixels::copiarPixel(Pixel* src,Pixel* dest)
{
    int r = src->r;
    int g = src->g;
    int b = src->b;
    dest->r = r;
    dest->g = g;
    dest->b = b;
    return 0;
}

bool MPixels::isIgual(Pixel* p1,Pixel* p2)
{
    return (p1->r==p2->r && p1->g == p2->g && p1->b == p2->b);
}

void MPixels::imprimirPixel(Pixel* p)
{
    cout << "Pixel(R,G,B,A): " << (int)p->r << ", " << (int)p->g << ", " << (int)p->b << ", " << (int)p->a << endl;
}

//esconder nos tres menores bits
int MPixels::esconder3BitsMenorBit(int bits, int num)
{
//    int novoNum = num;
//
//    novoNum = novoNum & 0xF8;
//    novoNum = novoNum + bits;
//
//    return novoNum;
    return (num & 0xF8) + bits; // bits tem que ser um número de 0 a 7
}

//esconder nos quatros menores bits
int MPixels::esconder4BitsMenorBit(int bits, int num)
{
    return (num & 0xF0) + bits; // bits tem que ser um número de 0 a 15
}

//esconder politica4
void MPixels::esconderPixel4(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande)
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 012, 345, 67
    lugarGrande = lugarGrande+1; //para o proximo

    int numR = peq->r;
    //r == g == b -> tons de cinza

    //ESCONDIDA DO R
    p1->r = MPixels::esconder3BitsMenorBit(numR%8,p1->r); //bit 012
    numR = numR/8;
    p1->g = MPixels::esconder3BitsMenorBit(numR%8,p1->g); //bit 345
    numR = numR/8;
    p1->b = MPixels::esconder2BitsMenorBit(numR%4,p1->b); //bit 67
    //COMPLETADO a escondida do R
}

Pixel MPixels::pegarPixel4(Pixel* pixelsGrande,int& lugarGrande)
{
    unsigned int num = 0;
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 012, 345, 67
    lugarGrande = lugarGrande+1; //para o proximo

    unsigned int auxR = p1->r;
    auxR = auxR & 0x07;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x07;
    auxG = auxG << 3;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x03;
    auxB = auxB << 6;
    num = num + auxB;

    Pixel p;
    p.r = num;
    p.g = num;
    p.b = num;
    p.a = 255;

    return p;
}

int MPixels::esconderNumeroEm1Pixel(int numero,Pixel* pixelsGrande,int& lugarGrande)  //bit 0 ao 11
{
    int num = numero;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0123, 4567, 891011

    p1->r = MPixels::esconder4BitsMenorBit(num%16,p1->r); //bit 0123
    num= num/16;
    p1->g = MPixels::esconder4BitsMenorBit(num%16,p1->g); //bit 4567
    num = num/16;
    p1->b = MPixels::esconder4BitsMenorBit(num%16,p1->b); //bit 891011

    lugarGrande = lugarGrande + 1;

    return 0;
}

int MPixels::pegarNumeroEm1Pixel(Pixel* pixelsGrande,int& lugarGrande) //bit 0 ao 11 -> até o nº 2048
{
    unsigned int num = 0;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0123, 4567, 891011
    unsigned int auxR = p1->r;
    auxR = auxR & 0x0F;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x0F;
    auxG = auxG << 4;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x0F;
    auxB = auxB << 8;
    num = num + auxB;

    lugarGrande = lugarGrande + 1;
    return num;
}

//politica 5
void MPixels::esconderPixelContrario(Pixel* peq,Pixel* pixelsGrande,int& lugarGrande)
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 012, 345, 67
    lugarGrande = lugarGrande-1; //para o proximo - ao contrário

    int numR = peq->r;
    //r == g == b -> tons de cinza

    //ESCONDIDA DO R
    p1->r = MPixels::esconder3BitsMenorBit(numR%8,p1->r); //bit 012
    numR = numR/8;
    p1->g = MPixels::esconder3BitsMenorBit(numR%8,p1->g); //bit 345
    numR = numR/8;
    p1->b = MPixels::esconder2BitsMenorBit(numR%4,p1->b); //bit 67
    //COMPLETADO a escondida do R
}

int MPixels::esconderNumeroEm1PixelContrario(int numero,Pixel* pixelsGrande,int& lugarGrande)
{
    int num = numero;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0123, 4567, 891011

    p1->r = MPixels::esconder4BitsMenorBit(num%16,p1->r); //bit 0123
    num= num/16;
    p1->g = MPixels::esconder4BitsMenorBit(num%16,p1->g); //bit 4567
    num = num/16;
    p1->b = MPixels::esconder4BitsMenorBit(num%16,p1->b); //bit 891011

    lugarGrande = lugarGrande - 1; //ao contrario

    return 0;
}

Pixel MPixels::pegarPixelContrario(Pixel* pixelsGrande,int& lugarGrande)
{
    unsigned int num = 0;
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 012, 345, 67
    lugarGrande = lugarGrande-1; //para o proximo - ao contrario

    unsigned int auxR = p1->r;
    auxR = auxR & 0x07;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x07;
    auxG = auxG << 3;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x03;
    auxB = auxB << 6;
    num = num + auxB;

    Pixel p;
    p.r = num;
    p.g = num;
    p.b = num;
    p.a = 255;

    return p;
}

int MPixels::pegarNumeroEm1PixelContrario(Pixel* pixelsGrande,int& lugarGrande) //bit 0 ao 11 -> até o nº 2048
{
    unsigned int num = 0;

    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 0123, 4567, 891011
    unsigned int auxR = p1->r;
    auxR = auxR & 0x0F;
    num = num + auxR;

    unsigned int auxG = p1->g;
    auxG = auxG & 0x0F;
    auxG = auxG << 4;
    num = num + auxG;

    unsigned int auxB = p1->b;
    auxB = auxB & 0x0F;
    auxB = auxB << 8;
    num = num + auxB;

    lugarGrande = lugarGrande - 1;
    return num;
}
