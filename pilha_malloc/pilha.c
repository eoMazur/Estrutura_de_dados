#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *ant;
};

struct pilha{
    struct elemento *topo;
    
};

void cria_pilha(struct pilha *pilha){
    pilha = (struct pilha *) malloc(sizeof(struct elemento));

    if(pilha != NULL){
       pilha->topo = NULL;
    }

    
}

void empilha(struct pilha *pilha){
    struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));

    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);

    if(pilha->topo == NULL){
        pilha->topo = novo;
        novo->ant = NULL;

        printf("\nElemento empilhado: ");
    }

    else{
        novo->ant = pilha->topo;
        pilha->topo = novo;

        printf("\nElemento empilhado: ");
    }
    
}

void imprime_pilha(struct pilha *pilha){
    struct elemento *aux;
    int i = 1;

    aux = pilha->topo;


    do{
        printf("\n%dº valor: %d", i, aux->num);

        i++;
        aux = aux->ant;
    }while(aux != NULL);

}

int main(void){
    struct pilha pilha;

    cria_pilha(&pilha);

    for(int i = 0; i < 5; i++){
        empilha(&pilha);
    }

    imprime_pilha(&pilha);

    printf("\n\n");
}