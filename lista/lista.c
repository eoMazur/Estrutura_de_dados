#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *prox;
    struct elemento *ant;
};

struct lista
{
    struct elemento *inicio;
    struct elemento *fim;
};

void cria_lista(struct lista *lista){
    lista = (struct lista *) malloc(sizeof(struct lista));

    if(lista != NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
    }


}

void inserir_elemento_fim(struct lista *lista){

    struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));

    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);

    novo->prox = NULL;
    novo->ant = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }

    else{
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void inserir_elemento_inicio(struct lista *lista){
    
    struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));

    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);

    novo->prox = NULL;
    novo->ant = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;

    }

    else{
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
}

void inserir_elemento_meio(struct lista *lista){

    struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));

    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);

    novo->prox = NULL;
    novo->ant = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }

    else{
        int posicao = 0;

        printf("\nInforme a posição do elemento: ");
        scanf("%d", &posicao);

        struct elemento *aux;

        aux = lista->inicio;

        for(int i = 0; i < posicao;i++){
            if(i == posicao - 1){
                novo->ant = aux->ant;
                novo->prox = aux;
                aux->ant->prox = novo;
                aux->ant = novo;

            }
            else{
                aux = aux->prox;
            }
        }
    }
}

void imprime_lista(struct lista *lista){
    if(lista->inicio == NULL){
        printf("\nLista vazia!!");
    }

    else{
        struct elemento *aux;
        aux = lista->inicio;

        int i = 1;

        do{
            printf("\n%dº valor: %d", i, aux->num);

            i++;
            aux = aux->prox;
        }while(aux != NULL);
    }
}

int main(void){

    struct lista lista;

    cria_lista(&lista);

    while(1){
        int opcao = 0;

        printf("\nInforme a opção:\n1 - Inserir elemento no inicio: \n2 - Inserir elemento no meio\n3 - Inserir elemento no fim\n4 - Imprimir lista\n");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                inserir_elemento_inicio(&lista);
                break;

            case 2:
                inserir_elemento_meio(&lista);
                break;
            
            case 3:
                inserir_elemento_fim(&lista);
                break;

            case 4:
                imprime_lista(&lista);

            default:
                break;
                break;
        }
        
    }
}
