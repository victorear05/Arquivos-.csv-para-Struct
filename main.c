#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    char nomeArquivo[256];
    FILE *file;
    int N;
    dados_cov *D;
    indexacao *I;
    int achou;

    do{
    op = menu();
        switch (op){

        case 1: //Ler Arquivo

            printf("Digite o nome do arquivo a ser lido:");
            scanf("%s", nomeArquivo);
            setbuf(stdin,NULL);
            file = fopen(nomeArquivo, "r");

            if(file){
                N = tamfile(file);
                D = (dados_cov*) malloc(sizeof(dados_cov) * N);
                file = fopen(nomeArquivo, "r");
                PreencheStruct(N, file, D);
                printf("Arquivo Lido e carregado com %d linhas!\n", N);
            }
            else
                printf("arquivo n abriu");
            break;

        case 2: //Indexar Dados
            I = (indexacao*) malloc(sizeof(dados_cov) * N);
            Indexar(I,D,N);
            break;

        case 3: //Consulta
            printf("Insira o termo de busca do tipo: UFAA/MM/DD\nPor exemplo, para:\nEstado: Goiás, dia: 25/03/2019\nDigite: GO19/03/25\n");
            achou = Consulta(D,I,N);
            if(achou == -1)
                printf("Termo de busca não encontrado!\n");
            break;

        case 0: //Sair
            printf("Até mais!\n");
            break;

        default :
            printf("Opção Inválida, por falor seleciona uma opção válida!\n");
            break;
        }

    }while(op != 0);

    free(D);
    free(I);
    fclose(file);

    return 0;
}
