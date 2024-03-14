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
    
        struct elemento *elemento0 = (struct elemento *) malloc(sizeof(struct elemento));
        elemento0->num = 0;
        elemento0->ant = pilha->topo;

        pilha->topo = elemento0;
        
        struct elemento *elemento1 = (struct elemento *) malloc(sizeof(struct elemento));
        elemento1->num = 1;
        elemento1->ant = pilha->topo;

        pilha->topo = elemento1;

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



int main(void){
    struct pilha pilha;

    cria_pilha(&pilha);

    int opcao;

    while(1){
        printf("\nEscolha a operação: ");
        printf("\n1 - Empilhar: ");
        printf("\n2 - Desempilhar: ");
        printf("\n3 - Desempilha toda a pilha");
        printf("\n4 - Imprimir pilha: ");
        printf("\n5 - Fibonacci: ");
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
        
        default:
            break;
        }


    }
}


//Desenvolva um programa que armazene n valores da sequência de Fibonacci em uma pilha.