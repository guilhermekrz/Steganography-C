#include "EsconderPrograma.h"

//hide
void EsconderPrograma::esconderArquivo(char nomeArquivo[],Imagem* grande)
{
    stringstream ss(stringstream::out);

    ifstream arq;
    arq.open(nomeArquivo, ios::in);

    if(!arq.is_open())
    {
        cout << "Árquivo inválido!" <<endl;
        return;
    }

    do
    {
        string s;
        getline(arq,s);
        if(!arq.fail())
        {
            ss << s << endl;
        }
    }
    while(arq.good());

    if(arq.bad() || !arq.eof())
    {
        cout << "Erro fatal!" << endl;
        exit(1); // Aborta programa
    }

    arq.close();

    EsconderPrograma::esconderTexto(ss.str(),grande);
}

void EsconderPrograma::esconderTexto(string s,Imagem* grande)
{
    int tam = s.length();
    char charTexto[tam+1];
    strcpy(charTexto,s.c_str());

    int alturaGrande = grande->getAltura();
    int larguraGrande = grande->getLargura();

    int comp = (alturaGrande*larguraGrande)/(tam);
    if(comp<1)
    {
        cout << "O tamanho da imagem grande deve ser pelo menos 1x maior do que o tamanho do texto! A sua imagem grande é apenas " << comp << "x maior do que o tamanho do texto!" << endl;
        return;
    }

    SDL_LockSurface(grande->getSurface());

    Pixel* pixelsGrande = (Pixel*) grande->getSurface()->pixels;

    int lugarGrande = EsconderPrograma::pixelInicial(grande);
    if(lugarGrande==-1)
    {
        cout << "Não foi possível esconder o código fonte!" << endl;
        return;
    }

    MPixels::esconderNumeroEm1Pixel(tam,pixelsGrande,lugarGrande); //tam

    for(int i=0; i<tam; i++)
    {
        EsconderPrograma::esconderLetra(charTexto[i],pixelsGrande,lugarGrande);
    }
    SDL_UnlockSurface(grande->getSurface());
}

int EsconderPrograma::pixelInicial(Imagem* grande)
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

void EsconderPrograma::esconderLetra(char letra,Pixel* pixelsGrande,int& lugarGrande)  //8 bits - 012 345 67
{
    Pixel* p1 = &pixelsGrande[lugarGrande]; //bit 012, 345, 67
    lugarGrande++; //para o proximo

    int num = letra;

    //ESCONDIDA DA letra
    p1->r = MPixels::esconder3BitsMenorBit(num%8,p1->r); //bit 012
    num = num/8;
    p1->g = MPixels::esconder3BitsMenorBit(num%8,p1->g); //bit 345
    num = num/8;
    p1->b = MPixels::esconder2BitsMenorBit(num%4,p1->b); //bit 67
    //COMPLETADA a escondida da letra
}

//show
void EsconderPrograma::runArquivo(Imagem* escondida)
{
    string str = EsconderPrograma::mostrarTexto(escondida);
    if(str.empty())
    {
        return;
    }

    ofstream arqsaida;
    arqsaida.open("codigoFonte.cpp", ios::out);

    if(!arqsaida.is_open())
    {
        return;
    }

    arqsaida << str;
    arqsaida.close();

    system("g++ codigoFonte.cpp");
    system("./a.out");
}

string EsconderPrograma::mostrarTexto(Imagem* escondida)
{
    stringstream ss;

    SDL_LockSurface(escondida->getSurface());

    Pixel* pixelsGrande = (Pixel*) escondida->getSurface()->pixels;

    int lugarGrande = EsconderPrograma::getPixelInicial(escondida);
    if(lugarGrande==-1)
    {
        cout << "Erro ao achar o padrão de início da imagem!" << endl;
        return NULL;
    }

    int tam = MPixels::pegarNumeroEm1Pixel(pixelsGrande,lugarGrande);

    for(int i=0; i<tam; i++)
    {
        char letra = EsconderPrograma::pegarLetra(pixelsGrande,lugarGrande);
        ss << letra;
    }
    SDL_UnlockSurface(escondida->getSurface());

    return ss.str();
}

int EsconderPrograma::getPixelInicial(Imagem* grande)
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

char EsconderPrograma::pegarLetra(Pixel* pixelsGrande, int& lugarGrande)
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

    return (char)num;
}
