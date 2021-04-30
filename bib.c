#include "bib.h"

int menu(){

    int op;
    printf("Escolha uma opção:\n");
    printf("1 - Para ler Arquivos\n");
    printf("2 - Para Indexar Arquivo\n");
    printf("3 - Para Consultar Arquivo\n");
    printf("0 - Para Sair\n");

    scanf("%d", &op);

    return op;
}

int tamfile(FILE *file){

    char c;
    int tam = 1;
    while((c = fgetc(file)) != EOF){
        if(c == '\n')
            tam++;
    }

    return tam;
}

void PreencheStruct(int N, FILE *file, dados_cov *D){

    char buff[1024];
    int cont = 0;
    int cont_campo = 0;

    int i = 0;

    while(fgets(buff, 1024, file)){
        cont_campo = 0;
        cont++;

        if(cont == 1)
            continue;

        char *campo = strtok(buff, ";");
        while(campo){

            if(cont_campo == 0)
                strcpy(D[i].Codg, campo);

            if(cont_campo == 1)
                strcpy(D[i].Regiao, campo);

            if(cont_campo == 2)
                strcpy(D[i].UF, campo);

            if(cont_campo == 3)
                strcpy(D[i].Data, campo);

            if(cont_campo == 4)
                D[i].Dados[0] = atoi(campo);

            if(cont_campo == 5)
                D[i].Dados[1] = atoi(campo);

            if(cont_campo == 6)
                D[i].Dados[2] = atoi(campo);

            if(cont_campo == 7)
                D[i].Dados[3] = atoi(campo);

            if(cont_campo == 8)
                D[i].Dados[4] = atoi(campo);

            if(cont_campo == 9)
                D[i].Dados[5] = atoi(campo);

            campo = strtok(NULL, ";\n");
            cont_campo++;
        }

        i++;
    }

    file = fopen("COV.csv", "r");
/*
    for(i = 0;i < N-1;i++)
        printf("%s - %s - %s - %s - %d - %d - %d - %d - %d - %d\n", D[i].Codg, D[i].Regiao, D[i].UF, D[i].Data, D[i].Dados[0], D[i].Dados[1], D[i].Dados[2], D[i].Dados[3], D[i].Dados[4], D[i].Dados[5]);
*/
}

void Indexar(indexacao *I, dados_cov *D, int N){

    int i, trocou = 1, auxI;
    char aux[10];
    int comp;
    for(i = 0; i < N-1;i++){
        strcpy(I[i].Chave, D[i].Codg);
        I[i].posicao = i;
    }

    while(trocou){
        trocou = 0;
        for (i = 0; i < N-2; ++i) {
            comp = strcmp(I[i].Chave, I[i+1].Chave);
                if(comp > 0){
                    auxI = I[i].posicao;
                    I[i].posicao = I[i+1].posicao;
                    I[i+1].posicao = auxI;
                    strcpy(aux, I[i].Chave);
                    strcpy(I[i].Chave, I[i+1].Chave);
                    strcpy(I[i+1].Chave, aux);
                    trocou = 1;
            }
        }
    }
/*
    for(i = 0;i < N-1;i++){
        printf("%s -> %d\n", I[i].Chave, I[i].posicao);
    }
*/
    printf("Arquivo Indexado com sucesso!\n");
}
int Consulta(dados_cov *D, indexacao *I, int N){

    int j;
    int achou = 0;
    char comp[11];

    scanf("%s", comp);

    for(int i = 0;i < N-1;i++){
        achou = strcmp(comp, I[i].Chave);
        j = I[i].posicao;
        if(achou == 0){
            printf("\n");
            printf("Região: %s\n", D[j].Regiao);
            printf("UF: %s\n", D[j].UF);
            printf("Data: %s\n", D[j].Data);
            printf("Semana: %d\n", D[j].Dados[0]);
            printf("População: %d\n", D[j].Dados[1]);
            printf("Casos Acumulados: %d\n", D[j].Dados[2]);
            printf("Casos Novos: %d\n", D[j].Dados[3]);
            printf("Óbitos Acumulados: %d\n", D[j].Dados[4]);
            printf("Óbitos Novos: %d\n", D[j].Dados[5]);
            printf("\n");
            return 1;
        }
    }

    achou = 0;
    return achou;
}
