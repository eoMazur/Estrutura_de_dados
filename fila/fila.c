
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

    novo->prox = NULL;
    
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
    if(fila->inicio == NULL){

        printf("\nFila vazia!!");
    }

    else{

    do{
        printf("\n%dº valor: %d", i + 1, aux->num);

        if(aux->prox != NULL){
            printf("\n    Proximo: %d", aux->prox->num);
        }

        else{
            printf("\n  Proximo: NULL");
        }
        aux = aux->prox;
        i++;
    }while(aux != NULL);
    
    printf("\nTodos os elementos foram impressos!!");

    }
}


void remove_elemento(struct fila *fila){
    if(fila->inicio == NULL){
        printf("Fila vazia!!!");
    }

    else{
        struct elemento *aux = fila->inicio;

        fila->inicio = fila->inicio->prox;

        free(aux);

        printf("\nElemento removido!!");

        
    }
}

void retorna_valores_maior_media_menor(struct fila *fila){
    if(fila->inicio == NULL){
        printf("\nFila vazia!!");
    }

    else{
        struct elemento *aux = fila->inicio;
        int maior = aux->num;

    

        do
        {
            if(aux->prox != NULL){
                if(aux->num < aux->prox->num){
                if(maior < aux->prox->num){
                    maior = aux->prox->num;
                }
            }
            }

            aux = aux->prox;
        }while(aux != NULL);

        printf("\nO maior valor da fila é: %d", maior);
    
        //pedaço do calculo da média;

                
        aux = fila->inicio;
        int media = 0, count = 0;


        do{
           
            media = media + aux->num;
            count++;

            aux = aux->prox;
        }while(aux != NULL);

        media = media / count;

        printf("\nA média é: %d", media);

        


        //pedaço do calculo do menor valor;

        
        aux = fila->inicio;
        int menor = aux->num;

        do{
            if(aux->prox != NULL){
                if(aux->num > aux->prox->num){
                    if(menor > aux->prox->num){
                        menor = aux->prox->num;
                    }
                }

            }

            aux = aux->prox;
        }while(aux != NULL);

        printf("\nO menor valor é: %d", menor);
        
        
    }

    

    
}

int main(void){
    struct fila fila;

    cria_fila(&fila);
    while(1){

        
        int opcao = 0;
        
        printf("\nEscolha uma opção:\n1 - Insere elemento\n2 - Imprime fila\n3 - Remove elemento\n4 - Retorna maior\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        
            /*case 1:
                cria_fila(&fila);
                break;
                */
            case 1:
                insere_elemento(&fila);
                break;
                
            case 2:
                imprime_fila(&fila);
                break;

            case 3:
                remove_elemento(&fila);
                break;


            case 4:
                retorna_valores_maior_media_menor(&fila);
                break;
                
            default:
                break;
                break;
        }
    }
}
