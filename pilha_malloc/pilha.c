#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *ant;
};

struct pilha{
    struct elemento *topo;
    
};

struct fila{
    struct elemento *inicio;
    struct elemento *fim;
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
    novo->ant = NULL;
    

    if(pilha->topo == NULL){
        pilha->topo = novo;

        printf("\nElemento empilhado: ");
    }

    else{
        novo->ant = pilha->topo;
        pilha->topo = novo;

        printf("\nElemento empilhado: ");
    }
    
}

void imprime_pilha(struct pilha *pilha){
    if(pilha->topo == NULL){
        printf("\nPilha vazia!!");
    }

    else if(pilha->topo != NULL){

    

    struct elemento *aux;
    int i = 1;

    aux = pilha->topo;


    do{
        printf("\n%dº valor: %d", i, aux->num);

        i++;
        aux = aux->ant;
    }while(aux != NULL);
    }

    else{
        printf("\nErro na leitura!!");
    }
}

void desempilha(struct pilha *pilha){
    if(pilha->topo == NULL){
        printf("\nPilha vazia!!");
    }

    else if(pilha->topo != NULL){

        struct elemento *aux;

        aux = pilha->topo;

        //desempilha de for o unico elemento da pilha
        if(aux->ant == NULL){
            pilha->topo = NULL;
            printf("\nValor desempilhado: %d", aux->num);
            free(aux);
        }

        //desempilha se houver mais de um elemento
        else if(aux->ant != NULL){
            pilha->topo = aux->ant;
            printf("\nValor desempilhado: %d", aux->num);
            free(aux);
        }

        //para detecção de erros
        else{
            printf("\nErro de leitura dentro da verificação!!");
        }
    }

    else{
        printf("\nErro na leitura");
    }
}

void desempilha_tudo(struct pilha *pilha){
    if(pilha->topo == NULL){
        printf("\nPilha vazia!!");
    }
    
    else if(pilha->topo != NULL){
        struct elemento *aux;
        
        aux = pilha->topo;
        
        do{
            pilha->topo = aux->ant;
            free(aux);
            
            aux = pilha->topo;
        }while(aux != NULL);
        
        
        printf("\nToda a pilha foi apagada!!");
    }
    
    
    else{
        printf("\nErro na leitura: ");
    }
}

void Fibonacci(struct pilha *pilha){
    int n;

    printf("\nInforme o valor: ");
    scanf("%d", &n);

    //struct elemento *aux = pilha->topo;

    int anterior = 0, proximo = 1, soma = 0;

    if(n == 2 || n > 2){
        struct elemento *elemento1 = (struct elemento *) malloc(sizeof(struct elemento));
        elemento1->num = 0;
        elemento1->ant = pilha->topo;

        pilha->topo = elemento1;

        struct elemento *elemento2 = (struct elemento *) malloc(sizeof(struct elemento));
        elemento2->num = 1;
        elemento2->ant = pilha->topo;

        pilha->topo = elemento2;
    }

    else if (n == 1){
        struct elemento *elemento0 = (struct elemento *) malloc(sizeof(struct elemento));
        elemento0->num = 0;
        elemento0->ant = pilha->topo;

        pilha->topo = elemento0;
    }
    
        

     if(n > 2){
        for(int i = 2; i < n; i++){
            
        
        soma = anterior + proximo;

        anterior = proximo;
        proximo = soma;

        struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));
        novo->num = soma;
        novo->ant = pilha->topo;

        pilha->topo = novo;
        

    }

    printf("\nUltimo número de fibonnaci: %d", soma);
     }
        


}

void cria_fila(struct fila *fila){
    
    fila->inicio = NULL;
    fila->fim = NULL;
}

void adiciona_elemento_fila(struct fila *fila){
    struct elemento *novo = (struct elemento *) malloc(sizeof(struct elemento));
    
    printf("\nInforme o valor: ");
    scanf("%d", &novo->num);
    novo->ant = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }
    
    else if(fila->inicio != NULL){
        fila->fim->ant = novo;
        fila->fim = novo;
    }
}

void imprime_fila(struct fila *fila){
    if(fila->inicio == NULL){
        printf("\nFila vazia!!");
    }
    
    else if(fila->inicio != NULL){
        struct elemento *aux;
        aux = fila->inicio;
        int i = 1;
        
        do{
            printf("\n%dº valor: %d", i, aux->num);
            i++;
            aux = aux->ant;
        }while(aux != NULL);
    }
    
    else{
        printf("\nErro na leitura!!");
    }
}

void compara_pilha_fila(struct pilha *pilha, struct fila *fila){
    if(pilha->topo == NULL || fila->inicio == NULL){
        printf("\nPilha ou fila vazia!!");
    }
    
    else if(pilha->topo != NULL || fila->inicio != NULL){
        struct elemento *aux_pilha = pilha->topo;
        struct elemento *aux_fila = fila->inicio;
        
        int contador = 0;
        
        do{
            if(aux_pilha->num == aux_fila->num){
                printf("\nElementos iguais encontrados!!");
                contador++;
            }
            
            aux_pilha = aux_pilha->ant;
            aux_fila = aux_fila->ant;
            
            
        }while(aux_pilha != NULL && aux_fila != NULL);
        
        printf("\n%d elementos iguais encontrados!!", contador);
    }
}


void compara_tamanhos_diferentes(struct pilha *pilha, struct fila *fila){

    if(pilha->topo == NULL || fila->inicio == NULL){
        printf("\nPilha ou fila vazia!!");
    }


    else if(pilha->topo != NULL || fila->inicio != NULL){
            struct elemento *aux_pilha;
            struct elemento *aux_fila;

            aux_pilha = pilha->topo;
            aux_fila = fila->inicio;

            int contador_pilha, contador_fila;
            contador_pilha = 0;
            contador_fila = 0;


            //calcula o tamanho da pilha
            do{
                contador_pilha++;
                aux_pilha = aux_pilha->ant;
            }while(aux_pilha != NULL);

            printf("\nTamanho da pilha: %d", contador_pilha);

            //calcula o tamanho da fila
            do{
                contador_fila++;
                aux_fila = aux_fila->ant;
            }while(aux_fila != NULL);

            printf("\nTamanho da fila: %d", contador_fila);

            int iguais = 0;


            //se a pilha for maior: ele pega um elemento da fila e compara com cada
            // um da pilha, ate ter comparado cada elemento da fila na pilha
            if(contador_pilha > contador_fila){
                aux_fila = fila->inicio;
                
                for(int i = 0; i < contador_fila; i++){
                    aux_pilha = pilha->topo;
                    for(int j = 0; j < contador_pilha; j++){
                        
                        
                        if(aux_fila->num == aux_pilha->num){
                            printf("\nElementos iguais encontrados!!");
                            iguais++;


                            break;
                        }
                        else if(aux_fila->num != aux_pilha->num){
                                aux_pilha = aux_pilha->ant;
                        }
                         
                       
                    }
                    
                    aux_fila = aux_fila->ant;
                }

                printf("\nPossui %d elementos iguais!!", iguais);
            }


            //se a fila for maior que a pilha ele compara cada elemento da pilha 
            //na fila, ate ter comparado cada elemento da pilha
            else if(contador_pilha < contador_fila){
                aux_fila = fila->inicio;
                aux_pilha = pilha->topo;

                for(int i = 0; i < contador_pilha; i++){
                    aux_fila = fila->inicio;

                    for(int j = 0; j < contador_fila; i++){

                        
                        if(aux_pilha->num == aux_fila->num){
                            iguais++;

                            break;

                        }

                        else if(aux_pilha->num != aux_fila->num){
                            aux_fila = aux_fila->ant;
                        }
                        
                        
                    }

                    aux_pilha = aux_pilha->ant;
                }

                printf("\nPossui %d elementos iguais!!", iguais);
            }



            else{
                printf("\nErro na execução!!");
            }

    }

}


int main(void){
    
    struct pilha pilha;
    cria_pilha(&pilha);
    
    struct fila fila;
    cria_fila(&fila);

    int opcao;

    while(1){
        printf("\nEscolha a operação: ");
        printf("\n1 - Empilhar: ");
        printf("\n2 - Desempilhar: ");
        printf("\n3 - Desempilha toda a pilha");
        printf("\n4 - Imprimir pilha: ");
        printf("\n5 - Fibonacci: ");
        printf("\n6 - Adiciona elemento na fila: ");
        printf("\n7 - Imprime fila: ");
        printf("\n8 - Compara pilha com fila: ");
        printf("\n9 - Compara tamanhos diferentes: ");
        printf("\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            empilha(&pilha);
            break;

        case 2:
            desempilha(&pilha);
            break;
            
        case 3:
            desempilha_tudo(&pilha);
            break;

        case 4:
            imprime_pilha(&pilha);
            break;
            
        case 5:
            Fibonacci(&pilha);
            break;
            
        case 6:
            adiciona_elemento_fila(&fila);
            break;
            
        case 7:
            imprime_fila(&fila);
            break;
            
        case 8:
            compara_pilha_fila(&pilha, &fila);
            break;

        case 9:
            compara_tamanhos_diferentes(&pilha, &fila);
            break;
        
        default:
            break;
        }


    }
}


//Desenvolva um programa que armazene n valores da sequência de Fibonacci em uma pilha.