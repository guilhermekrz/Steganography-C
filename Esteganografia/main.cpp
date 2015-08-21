#include "defs.h"

int main ( int argc, char** argv )
{
    if(argc == 1)
    {
        imprimirIncorreta();
        return 1;
    }

    if(carregamento()==1)
    {
        SDL_Quit();
        return 1;
    }

    if(argv[1][0]=='E' || argv[1][0]=='e')
    {
        if(argc < 4)
        {
            imprimirIncorreta();
            return 1;
        }

        if(argc==4)
        {
            politica6Esconder(argv[2],argv[3]);
        }
        else
        {
            int politica = atoi(argv[4]);
            switch(politica)
            {
            case 1:
                politica1Esconder(argv[2],argv[3]);
                break;
            case 2:
                politica2Esconder(argv[2],argv[3]);
                break;
            case 3:
                politica3Esconder(argv[2],argv[3]);
                break;
            case 4:
                politica4Esconder(argv[2],argv[3]);
                break;
            case 5:
                politica5Esconder(argv[2],argv[3]);
                break;
            case 6:
                politica6Esconder(argv[2],argv[3]);
                break;
            default:
                imprimirIncorreta();
                return 1;
            }
        }
    }
    else if(argv[1][0]=='D' || argv[1][0]=='d')
    {
        if(argc < 3)
        {
            imprimirIncorreta();
            return 1;
        }
        if(argc==3)
        {
            politica6Descobrir(argv[2]);
        }
        else
        {
            int politica = atoi(argv[3]);
            switch(politica)
            {
            case 1:
                politica1Descobrir(argv[2]);
                break;
            case 2:
                politica2Descobrir(argv[2]);
                break;
            case 3:
                politica3Descobrir(argv[2]);
                break;
            case 4:
                politica4Descobrir(argv[2]);
                break;
            case 5:
                politica5Descobrir(argv[2]);
                break;
            case 6:
                politica6Descobrir(argv[2]);
                break;
            default:
                imprimirIncorreta();
                return 1;
            }
        }
    }
    else if(argv[1][0]=='p' || argv[1][0]=='P')
    {
        if(argc < 4)
        {
            imprimirIncorreta();
            return 1;
        }
        if(argc==4)
        {
            politica6EsconderPintando(argv[2],argv[3]);
        }
        else
        {
            int politica = atoi(argv[4]);
            switch(politica)
            {
            case 1:
                politica1EsconderPintando(argv[2],argv[3]);
                break;
            case 2:
                politica2EsconderPintando(argv[2],argv[3]);
                break;
            case 3:
                politica3EsconderPintando(argv[2],argv[3]);
                break;
            case 4:
                politica4EsconderPintando(argv[2],argv[3]);
                break;
            case 5:
                politica5EsconderPintando(argv[2],argv[3]);
                break;
            case 6:
                politica6EsconderPintando(argv[2],argv[3]);
                break;
            default:
                imprimirIncorreta();
                return 1;
            }
        }
    }
    else if(argv[1][0]=='c' || argv[1][0]=='C')
    {
        if(argc < 3)
        {
            imprimirIncorreta();
            return 1;
        }

        if(argc==3)
        {
            executarCodigo(argv[2]);
        }
        else
        {
            esconderCodigo(argv[2],argv[3]);
        }
    }
    else
    {
        imprimirIncorreta();
    }

    SDL_Quit();
    return 0;
}

int carregamento()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )  // inicializa SDL video
    {
        printf( "Não foi possível inicializar o SDL: %s\n", SDL_GetError() );
        return 1;
    }
    atexit(SDL_Quit); // make sure SDL cleans up before exit
    SDL_Init(SDL_INIT_EVERYTHING); // Inicializa a SDL
    return 0;
}

Imagem carregarImagem(string nomeImagemTemp)
{
    char nomeImagem[50];
    strcpy(nomeImagem,nomeImagemTemp.c_str());
    Imagem imTemp (nomeImagem);
    if(imTemp.carregar()==1)
    {
        return NULL;
    }
    return imTemp;
}

void imprimirIncorreta()
{
    cout << "----------------------------------" << endl;
    cout << "Opções de linha de comando incorretas!" << endl;
    cout << "[modo], onde modo pode ser: E[sconder], D[escobrir], P[intando] ou C[ódigo];" <<endl;
    cout << "----------------------------------" << endl;
    cout << "E precisa de: [imagem original] [imagem escondida] [política]" << endl;
    cout << "D precisa de: [imagem resultante] [política];" << endl;
    cout << "P precisa de: [imagem original] [imagem escondida] [política];" << endl;
    cout << "C precisa de: [nome do arquivo] [imagem original] ou [imagem resultante];" << endl;
    cout << "Obs.: se nenhuma política for explicitada, será usada como base a política 6" << endl;
    cout << "----------------------------------" << endl;
    cout << "[Política] pode ser:" << endl;
    cout << "\t1 - Esconder no bit menos significativo;" << endl;
    cout << "\t2 - Esconder nos dois bits menos significativo;" << endl;
    cout << "\t3 - Esconder no bit menos significativo, convertendo a imagem escondida para tons de cinza;" << endl;
    cout << "\t4 - Esconder um pixel da imagem escondida em um pixel da imagem original, convertendo a imagem escondida para tons de cinza;" << endl;
    cout << "\t5 - Idem a política 4, porém escondendo a imagem escondida de trás para frente;" << endl;
    cout << "\t[RECOMENDADO] 6 - Idem a política 4, porém usando uma sequência aritmética para esconder a imagem escondida" << endl;
    cout << "----------------------------------" << endl;
}

int outraPolitica(string simGrande,string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    double quantoMaior = imGrande->quantasVezesMaior(imPequena);
    if(quantoMaior>=8)
    {
        cout << "Você pode esconder suas imagens utilizando a política 1!" << endl;
        politica1Esconder(simGrande,simPequena);
    }
    else if(quantoMaior>=4)
    {
        cout << "Você pode esconder suas imagens utilizando a política 2!" << endl;
        politica2Esconder(simGrande,simPequena);
    }
    else if(quantoMaior>=3)
    {
        cout << "Você pode esconder suas imagens utilizando a política 3!" << endl;
        politica3Esconder(simGrande,simPequena);
    }
    else if(quantoMaior>=1)
    {
        cout << "Você pode esconder suas imagens utilizando a política 6!" << endl;
        politica6Esconder(simGrande,simPequena);
    }
    else
    {
        cout << "Ainda não foi implementado o programa para esconder imagens que sao " << quantoMaior << "x maior que as originais." << endl;
    }
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica1Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=8)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 1 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderP1::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica1Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }
    SDL_Surface* temp = EsconderP1::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int politica2Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=4)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 2 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderP2::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica2Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface* temp = EsconderP2::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int politica3Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=3)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 3 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderTC::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica3Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface* temp = EsconderTC::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int politica4Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 4 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderP4::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica4Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface* temp = EsconderP4::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int politica5Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 5 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderP5::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica5Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface* temp = EsconderP5::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int politica6Esconder(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 6 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return outraPolitica(simGrande,simPequena);
    }

    EsconderP6::hide(imGrande,imPequena);

    salvarImagem(imGrande);
    //imGrande->freeSurface();
    //imPequena->freeSurface();
    return 0;
}

int politica6Descobrir(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface* temp = EsconderP6::show(imGrande);
    if(temp==NULL)
    {
        return 1;
    }
    imGrande->setSurface(temp);
    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int salvarImagem(Imagem* im)
{
    cout<< "Digite o nome do arquivo para ser salvo (obs.: .BMP): ";
    string nomeArquivo;
    cin >> nomeArquivo;
    im->salvar(nomeArquivo.c_str());
    cout << "Arquivo salvo com sucesso!" << endl;
    return 0;
}

int politica1EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=8)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 1 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderP1::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica2EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=4)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 2 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderP2::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica3EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=3)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 3 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto deverás manipular sua imagem escondida antes de utilizar a política 1!" << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderTC::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica4EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 4 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderP4::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica5EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 5 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderP5::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    imPequena->freeSurface();
    return 0;
}

int politica6EsconderPintando(string simGrande, string simPequena)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    Imagem imPequenaTemp = carregarImagem(simPequena);
    Imagem* imPequena = &imPequenaTemp;
    if(!imPequena)
    {
        SDL_Quit();
        return 1;
    }

    int quantoMaior = imGrande->quantasVezesMaior(imPequena);

    if(quantoMaior>=1)
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida, portanto poderás usar a política 6 sem problemas!" << endl;
    }
    else
    {
        cout << "A imagem original é " << quantoMaior << "x maior que a imagem escondida." << endl;
        cout << "Você deverá utilizar outra política de mapeamento." <<endl;
        return 1;//outraPolitica(imGrande,imPequena);
    }

    EsconderP6::hidePintando(imGrande,imPequena);

    salvarImagem(imGrande);
    //imGrande->freeSurface();
    //imPequena->freeSurface();
    return 0;
}

//code

int esconderCodigo(char nomeArquivo[], string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    EsconderPrograma::esconderArquivo(nomeArquivo,imGrande);

    salvarImagem(imGrande);
    imGrande->freeSurface();
    return 0;
}

int executarCodigo(string simGrande)
{
    Imagem imGrandeTemp = carregarImagem(simGrande);
    Imagem* imGrande = &imGrandeTemp;
    if(!imGrande)
    {
        SDL_Quit();
        return 1;
    }

    EsconderPrograma::runArquivo(imGrande);
    imGrande->freeSurface();
    return 0;
}
