
#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *prox;
};

struct fila{
    struct elemento *inicio;
    struct elemento *fim;
    
}; 


void cria_fila(struct fila *fila){
    fila = (struct fila *) malloc(sizeof(struct fila));
    
    if(fila != NULL){
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    
}

void insere_elemento(struct fila *fila){
   struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));
    
    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);
    
    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }
    
    else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    
    printf("\nElemento atribuído na fila!!");
}

void imprime_fila(struct fila *fila){
    
   struct elemento *aux = fila->inicio;
    int i = 0;
    do{
        printf("\n%dº valor: %d", i + 1, aux->num);
        aux = aux->prox;
        i++;
    }while(aux != NULL);
    
    printf("\nTodos os elementos foram impressos!!");
}


int main(void){
    struct fila fila;
    while(1){
        
        int opcao = 0;
        
        printf("\nEscolha uma opção: \n1 - Cria fila\n2 - Insere elemento\n3 - Imprime fila\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        
            case 1:
                cria_fila(&fila);
                break;
                
            case 2:
                insere_elemento(&fila);
                break;
                
            case 3:
                imprime_fila(&fila);
                break;
                
            default:
                break;
                break;
        }
    }
}
