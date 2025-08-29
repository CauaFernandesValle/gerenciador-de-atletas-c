#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Atleta
{
    char *nome;
    int matricula;
    int tempoTreino;
};



void incluirAtl(struct Atleta **vAtleta, int *totalAtletas);

void exibirPadrao(struct Atleta **vAtleta, int totalAtletas);

void exibirAlfabetica(struct Atleta **vAtleta, int totalAtletas);

void exibirTempoTreino(struct Atleta **vAtleta, int totalAtletas);

void filtroTempo(struct Atleta **vAtleta, int totalAtletas);

void ranqueiaTempo(struct Atleta **vAtleta, int totalAtletas, struct Atleta **ordem);

int main() {

    struct Atleta *vAtletas = NULL;

    int menu, critDeExibicao, totalAtletas = 0;


    do
    {
        printf("Menu:\n");
        printf("1. Incluir atleta\n");
        printf("2. Exibir atletas\n");
        printf("3. filtrar atletas com tempo abaixo do escolhido\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menu);
        printf("\n");

        switch (menu)
        {
        case 1:
            incluirAtl(&vAtletas, &totalAtletas);
            break;
        case 2:
            printf("gostaria de usar qual criterio de exibicao?\n");
            printf("1. Exibir por ordem de inclusao\n");
            printf("2. Exibir em ordem alfabetica\n");
            printf("3. Exibir em ordem de tempo de treino (do menos tempo para o maiss)\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &critDeExibicao);

            switch (critDeExibicao){
                case 1:
                   exibirPadrao(&vAtletas, totalAtletas);
                   break;
               case 2:
                   exibirAlfabetica(&vAtletas, totalAtletas);
                   break;
               case 3:
                   exibirTempoTreino(&vAtletas, totalAtletas);
                   break;
               default:
                   printf("Opcao invalida.\n");
                   break;
            }

            break;
        case 3:
            filtroTempo(&vAtletas, totalAtletas);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n\n");
            break;
        }

    } while (menu != 0);

    for (int i = 0; i < totalAtletas; i++) {
    free(vAtletas[i].nome);
    }

    free(vAtletas);
    return 0;
}

void incluirAtl(struct Atleta **vAtleta, int *totalAtletas){

    int numAtletasCadastrar;
    char tempNome[150];

    printf("quantos atletas deseja cadastrar? ");
    scanf("%d", &numAtletasCadastrar);

    *totalAtletas += numAtletasCadastrar;

    struct Atleta *temp = realloc(*vAtleta, *totalAtletas * sizeof(struct Atleta));

    if (temp == NULL) {

    printf("Falha ao alocar memoria!\n");
    return;

    }

    *vAtleta = temp;
    
    for(int i = 0; i < numAtletasCadastrar; i++){
        printf("Nome do atleta %d: ", i + 1);
        scanf("%s", tempNome);
        (*vAtleta)[*totalAtletas - numAtletasCadastrar + i].nome = malloc((strlen(tempNome) + 1) * sizeof(char));
        strcpy((*vAtleta)[*totalAtletas - numAtletasCadastrar + i].nome, tempNome);

        printf("Matricula do atleta %d: ", i + 1);
        scanf("%d", &(*vAtleta)[*totalAtletas - numAtletasCadastrar + i].matricula);

        printf("Tempo de treino do atleta %d (em minutos): ", i + 1);
        scanf("%d", &(*vAtleta)[*totalAtletas - numAtletasCadastrar + i].tempoTreino);

        printf("\n");
    }
}

void exibirPadrao(struct Atleta **vAtleta, int totalAtletas){

    if (totalAtletas == 0) {
        printf("Nenhum atleta cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalAtletas; i++) {
        printf("Atleta %d:\n", i + 1);
        printf("Nome: %s\n", (*vAtleta)[i].nome);
        printf("Matricula: %d\n", (*vAtleta)[i].matricula);
        printf("Tempo de treino: %d minutos\n", (*vAtleta)[i].tempoTreino);
        printf("\n");
    }


}

void exibirAlfabetica(struct Atleta **vAtleta, int totalAtletas){

    int  i, j, menorIndice = 0;
    struct Atleta **ordem;

    ordem = (struct Atleta **)malloc(totalAtletas * sizeof(struct Atleta *));

    if (totalAtletas == 0) {
        printf("Nenhum atleta cadastrado.\n");
        return;
    }

    for (i = 0; i < totalAtletas; i++) {
        ordem[i] = &(*vAtleta)[i];
    }

    for(i = 0; i < totalAtletas - 1; i++){
        
        menorIndice = i;

        for(j = i + 1; j < totalAtletas; j++){

            if(strcmp(ordem[j]->nome, ordem[menorIndice]->nome) < 0){
                menorIndice = j;
            } else if(strcmp(ordem[j]->nome, ordem[menorIndice]->nome) == 0){
                if(ordem[j]->matricula < ordem[menorIndice]->matricula){
                    menorIndice = j;
                }
            }
        }

        if(menorIndice != i){
            struct Atleta *temp = ordem[i];
            ordem[i] = ordem[menorIndice];
            ordem[menorIndice] = temp;

        }
        
    }

    printf("os atletas em ordem alfabetica sao:\n");
    for (int i = 0; i < totalAtletas; i++) {
        printf("%s\n", ordem[i]->nome);
        printf("Matricula: %d\n", ordem[i]->matricula);
        printf("Tempo de treino: %d:%02d\n", ordem[i]->tempoTreino / 60, ordem[i]->tempoTreino % 60);
        printf("\n");
    }

    free(ordem);

}

void exibirTempoTreino(struct Atleta **vAtleta, int totalAtletas){

    struct Atleta **ordem;

    ordem = (struct Atleta **)malloc(totalAtletas * sizeof(struct Atleta *));

    if (totalAtletas == 0) {
        printf("Nenhum atleta cadastrado.\n");
        return;
    }

    ranqueiaTempo(vAtleta, totalAtletas, ordem);

    printf("\nos atletas em ordem de menos tempo de treino sao:\n");
    for (int i = 0; i < totalAtletas; i++) {
        printf("%s\n", ordem[i]->nome);
        printf("Matricula: %d\n", ordem[i]->matricula);
        printf("Tempo de treino: %d:%02d\n", ordem[i]->tempoTreino / 60, ordem[i]->tempoTreino % 60);
        printf("\n");
    }

    free(ordem);

}

void ranqueiaTempo(struct Atleta **vAtleta, int totalAtletas, struct Atleta **ordem){

    int  i, j, menosTempoIndice = 0;

    for (i = 0; i < totalAtletas; i++) {
        ordem[i] = &(*vAtleta)[i];
    }

    for(i = 0; i < totalAtletas - 1; i++){

        menosTempoIndice = i;

        for(j = i + 1; j < totalAtletas; j++){

            if(ordem[j]->tempoTreino < ordem[menosTempoIndice]->tempoTreino){
                menosTempoIndice = j;
            } else if(ordem[j]->tempoTreino == ordem[menosTempoIndice]->tempoTreino){
                if(ordem[j]->matricula < ordem[menosTempoIndice]->matricula){
                    menosTempoIndice = j;
                }
            }
        }

        if(menosTempoIndice != i){
            struct Atleta *temp = ordem[i];
            ordem[i] = ordem[menosTempoIndice];
            ordem[menosTempoIndice] = temp;

        }
        
    }

}

void filtroTempo(struct Atleta **vAtleta, int totalAtletas){

    int limite, i;

    if (totalAtletas == 0) {
        printf("Nenhum atleta cadastrado.\n");
        return;
    }

    printf("qual o tempo limite do filtro? (em minutos) ");
    scanf("%d", &limite);
    printf("\n");

    printf("os atletas com o tempo menor que %d sao:\n\n", limite);
    for (int i = 0; i < totalAtletas; i++) {
        if ((*vAtleta)[i].tempoTreino < limite) {
            printf("%s\n", (*vAtleta)[i].nome);
            printf("Matricula: %d\n", (*vAtleta)[i].matricula);
            printf("Tempo de treino: %d:%02d\n", (*vAtleta)[i].tempoTreino / 60, (*vAtleta)[i].tempoTreino % 60);
            printf("\n");
        }
    }


}


