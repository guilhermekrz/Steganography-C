#include "Imagem.h"
Imagem::Imagem()
{
    //ctor
}

Imagem::Imagem(const char n[]) //no maximo 50 caracteres de nome!
{
    strcpy(nome,n);
}

int Imagem::carregar()
{
    // Carrega uma imagem
    img = IMG_Load(nome);
    if (!img)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }
    // Converte imagem para temporaria de 32 bits
    SDL_Surface* temp = SDL_CreateRGBSurface( SDL_SWSURFACE, img->w, img->h, 32,
                        0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000 );
    SDL_SetAlpha( img, 0, SDL_ALPHA_OPAQUE );
    SDL_BlitSurface( img, NULL, temp, NULL );

    // Libera imagem original...
    SDL_FreeSurface(img);
    // ... e aponta para temporaria
    img = temp;
    return 0;
}

int Imagem::getAltura()
{
    return img->h;
}

int Imagem::getLargura()
{
    return img->w;
}

void Imagem::convertParaTonsCinzas()
{
    Pixel* pixelsImagem = (Pixel*) img->pixels; // A partir daqui, o acesso é feito como array, normalmente:
    int largura = this->getLargura();
    int altura = this->getAltura();

    SDL_LockSurface(img);
    for(int i=0; i<altura; i++)
    {
        for(int j=0; j<largura; j++)
        {
            int lugar = i*largura+j;
            Pixel p = pixelsImagem[lugar];
            int r = p.r;
            int g = p.g;
            int b = p.b;
            int tomCinza = 0.3*r + 0.59*g + 0.11*b;
            Pixel p1;
            p1.r = tomCinza;
            p1.g = tomCinza;
            p1.b = tomCinza;
            p1.a = 255;
            pixelsImagem[lugar] = p1;
        }
    }
    SDL_UnlockSurface(img);
}

SDL_Surface* Imagem::getSurface()
{
    return img;
}

void Imagem::setSurface(SDL_Surface* surf)
{
    img = surf;
}

void Imagem::salvar()
{
    SDL_SaveBMP(img, nome);
}

void Imagem::salvar(const char novoNome[])
{
    SDL_SaveBMP(img, novoNome);
}

void Imagem::freeSurface()
{
    SDL_FreeSurface(img);
}

char* Imagem::getNome()
{
    return nome;
}

int Imagem::mostrarImagem()
{
    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(this->getLargura(), this->getAltura(), 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - img->w) / 2;
    dstrect.y = (screen->h - img->h) / 2;

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
            {
                // exit if ESCAPE is pressed
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
                break;
            }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(img, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop
    return 0;
}

double Imagem::quantasVezesMaior(Imagem* outraImagem)
{
    return (((double)getAltura())*getLargura())/(((double)outraImagem->getAltura())*outraImagem->getLargura());
}
