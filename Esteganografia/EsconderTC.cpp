#include "EsconderTC.h"

//hide

int EsconderTC::hide(Imagem* grande,Imagem* pequena)
{
    pequena->convertParaTonsCinzas();

    SDL_LockSurface(grande->getSurface());
    SDL_LockSurface(pequena->getSurface());

    Pixel* pixelsGrande = (Pixel*) grande->getSurface()->pixels;
    Pixel* pixelsPequena = (Pixel*) pequena->getSurface()->pixels;


    int lugarGrande = EsconderTC::pixelInicial(grande);
    if(lugarGrande==-1)
    {
        cout << "Não foi possível esconder a imagem utilizando a política 3" << endl;
        return 1;
    }

    EsconderTC::esconderAlturaLargura(pixelsGrande,lugarGrande, pequena->getAltura(),pequena->getLargura()); //8 pixels

    int alturaPequena = pequena->getAltura();
    int larguraPequena = pequena->getLargura();

    for(int i=0; i<alturaPequena; i++)
    {
        for(int j=0; j<larguraPequena; j++)
        {
            int lugarPequena = i*larguraPequena+j;
            Pixel* peq = &pixelsPequena[lugarPequena];
            MPixels::esconderPixel3(peq,pixelsGrande,lugarGrande); //3 pixels
        }
    }
    SDL_UnlockSurface(grande->getSurface());
    SDL_UnlockSurface(pequena->getSurface());
    return 0;
}

void EsconderTC::esconderAlturaLargura(Pixel* pixelsGrande, int& lugarGrande,int alturaPequena,int larguraPequena)
{
    MPixels::esconderNumeroEm4Pixels(alturaPequena,pixelsGrande,lugarGrande);
    MPixels::esconderNumeroEm4Pixels(larguraPequena,pixelsGrande,lugarGrande);
}

int EsconderTC::pixelInicial(Imagem* grande)  //sequencia de 5 pixels iguais (iguais ao primeiro)
{
    SDL_LockSurface(grande->getSurface());
    Pixel* pixelsGrande = (Pixel*) grande->getSurface()->pixels;

    Pixel* p1 = &pixelsGrande[0];
    Pixel* p2 = &pixelsGrande[1];
    Pixel* p3 = &pixelsGrande[2];
    Pixel* p4 = &pixelsGrande[3];
    Pixel* p5 = &pixelsGrande[4];
    MPixels::copiarPixel(p1,p2);
    MPixels::copiarPixel(p1,p2);
    MPixels::copiarPixel(p1,p3);
    MPixels::copiarPixel(p1,p4);
    MPixels::copiarPixel(p1,p5);

    SDL_UnlockSurface(grande->getSurface());
    return 5;
}

//show
SDL_Surface* EsconderTC::show(Imagem* escondida)
{
    int alturaPequena = 0;
    int larguraPequena = 0;

    SDL_LockSurface(escondida->getSurface());

    Pixel* pixelsGrande = (Pixel*) escondida->getSurface()->pixels;

    int lugarGrande = EsconderTC::getPixelInicial(escondida);
    if(lugarGrande==-1)
    {
        cout << "Erro ao achar o padrão de início da imagem!" << endl;
        return NULL;
    }

    int retal = EsconderTC::getAlturaLargura(pixelsGrande,lugarGrande,alturaPequena,larguraPequena);
    if(retal!=0)
    {
        cout << "Erro ao achar o padrão de altura e largura da imagem!" << endl;
        return NULL;
    }

    SDL_Surface* img = SDL_CreateRGBSurface( SDL_SWSURFACE, larguraPequena, alturaPequena, 32,
                       0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000 );
    SDL_SetAlpha( img, 0, SDL_ALPHA_OPAQUE );

    if(img==NULL)
    {
        cout << "Erro ao criar a superfície!" << endl;
        return NULL;
    }
    SDL_LockSurface(img);


    Pixel* pixelsPequena = (Pixel*) img->pixels;

    for(int i=0; i<alturaPequena; i++)
    {
        for(int j=0; j<larguraPequena; j++)
        {

            int lugarPequena = i*larguraPequena+j;
            Pixel p = MPixels::pegarPixel3(pixelsGrande,lugarGrande);
            pixelsPequena[lugarPequena] = p;
        }
    }
    SDL_UnlockSurface(escondida->getSurface());
    SDL_UnlockSurface(img);

    return img;
}

int EsconderTC::getPixelInicial(Imagem* grande)
{
    SDL_LockSurface(grande->getSurface());
    Pixel* pixelsGrande = (Pixel*) grande->getSurface()->pixels;

    Pixel* p1 = &pixelsGrande[0];
    Pixel* p2 = &pixelsGrande[1];
    Pixel* p3 = &pixelsGrande[2];
    Pixel* p4 = &pixelsGrande[3];
    Pixel* p5 = &pixelsGrande[4];

    if(MPixels::isIgual(p1,p2) && MPixels::isIgual(p1,p3) && MPixels::isIgual(p1,p4) && MPixels::isIgual(p1,p5))
    {
        SDL_UnlockSurface(grande->getSurface());
        return 5;
    }

    SDL_UnlockSurface(grande->getSurface());
    return -1;
}

int EsconderTC::getAlturaLargura(Pixel* pixelsGrande, int& lugarGrande,int& alturaGrande,int& larguraGrande)
{
    alturaGrande = MPixels::pegarNumeroEm4Pixels(pixelsGrande,lugarGrande);
    larguraGrande = MPixels::pegarNumeroEm4Pixels(pixelsGrande,lugarGrande);
    return 0;
}

int EsconderTC::hidePintando(Imagem* grande,Imagem* pequena)
{
    pequena->convertParaTonsCinzas();

    SDL_LockSurface(grande->getSurface());
    SDL_LockSurface(pequena->getSurface());

    Pixel* pixelsGrande = (Pixel*) grande->getSurface()->pixels;

    Pixel azul;
    azul.a = 255;
    azul.r = 0;
    azul.g = 0;
    azul.b = 255;
    int lugarGrande = 0;
    for(int i=0; i<5; i++)
    {
        pixelsGrande[lugarGrande] = azul;
        lugarGrande++;
    }

    Pixel verde;
    verde.a = 255;
    verde.r = 0;
    verde.g = 255;
    verde.b = 0;
    for(int i=0; i<8; i++)
    {
        pixelsGrande[lugarGrande] = verde;
        lugarGrande++;
    }

    int alturaPequena = pequena->getAltura();
    int larguraPequena = pequena->getLargura();

    Pixel vermelho;
    vermelho.a = 255;
    vermelho.r = 255;
    vermelho.g = 0;
    vermelho.b = 0;

    for(int i=0; i<alturaPequena; i++)
    {
        for(int j=0; j<larguraPequena; j++)
        {
            for(int i=0; i<3; i++)
            {
                pixelsGrande[lugarGrande] = vermelho;
                lugarGrande++;
            }
        }
    }
    SDL_UnlockSurface(grande->getSurface());
    SDL_UnlockSurface(pequena->getSurface());
    return 0;
}
