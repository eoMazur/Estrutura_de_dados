#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *dir;
    struct elemento *esq;
};

struct arvore{
    struct elemento *raiz;
};

void criaArvore(struct arvore *arv){
    arv = (struct arvore *) malloc(sizeof(struct arvore));

    if(arv != NULL){
        arv->raiz = NULL;
    }
}

void adicionaElemento(struct arvore *arv){
    struct elemento *novo = (struct elemento *) malloc(sizeof(struct arvore));
    struct elemento *aux = arv->raiz;

    printf("Informe um número\n");
    scanf("%d", &novo->num);
    
    if(aux != NULL){
            while(1){
            if(novo->num < aux->num){
                if(aux->esq == NULL){
                    aux->esq = novo;
                    break;
                }
                else{
                    aux = aux->esq;
                }

            }
            else if(novo->num >= aux->num){
                if(aux->dir == NULL){
                    aux->dir = novo;
                    break;
                }
                else{
                    aux = aux->dir;
                }
            }
        }
    }

    else if(aux == NULL){
        arv->raiz = novo;
    }
}

void imprimeArvore(struct elemento *aux){

        if(aux != NULL){
            printf("%d\n", aux->num);
            imprimeArvore(aux->esq);
            imprimeArvore(aux->dir);
        }

    

}

int main(void)
{
    struct arvore arv;

    criaArvore(&arv);

    while(1){
        int opcao = 0;

        printf("Informe a operação \n 1 - Adiciona elemento \n 2 - imprime arvore\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionaElemento(&arv);
            break;
        
        case 2:
            imprimeArvore(arv.raiz);
            break;

        default:
            break;
        }

    }
}
