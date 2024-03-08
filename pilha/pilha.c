

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pilha{
    int topo;
    int tamanho;
    float *pElem;
};

void cria_pilha(struct pilha *p, int quant){
    p->topo = -1;
    p->tamanho = quant;
    
    p->pElem = (float *) malloc(quant * sizeof(float));
}

void verificaVazio(struct pilha *p){
    
    if(p->topo == -1){
        printf("\nEsta vazia ");
        
        printf("\n<-------------------------------->\n\n");
    }
    else{
        printf("\nNão está vazia, possui elementos. ");
        
        printf("\n<-------------------------------->\n\n");
    }
}

void verificaCheio(struct pilha *p){
    if(p->topo == p->tamanho - 1){
        printf("\nPilha Cheia ");
        
        printf("\n<-------------------------------->\n\n");
    }
    
    else{
        printf("\nEstá vazia ou incompleta ");
        
        printf("\n<-------------------------------->\n\n");
        
    }
}

void empilha(struct pilha *p){
    if(p->topo == p->tamanho - 1){
        printf("\nPilha cheia!");
        
        printf("\n<-------------------------------->\n\n");
    }
    else{
        
    float valor = 0.0;
    
    printf("\nInforme o valor: ");
    scanf("%f", &valor);
        
    p->topo++;
    p->pElem [p->topo] = valor;
    
    }
}

float desempilha(struct pilha *p){
    if(p->topo == -1){
        printf("\nPilha Vazia!");
        
        printf("\n<-------------------------------->\n\n");
    }
    
    else {
    
    float valor = p->pElem[p->topo];
    
    printf("\nValor retirado: %.2f", valor);
    
    printf("\n<-------------------------------->\n\n");
    
    p->topo--;
    
    return valor;
    
    }
}

float retornaTopo(struct pilha *p){
    float valor = p->pElem[p->topo];
    
    printf("Valor do topo: %.2f", valor);
    
    printf("\n<-------------------------------->\n\n");
    
    return valor;
}

void retornaValores(struct pilha *p){
    float aux;
    
    
    if (p->topo == -1) {
        printf("\nPilha Vazia!");
        printf("\n<-------------------------------->\n\n");
        return;
    }
    
    aux = p->pElem[0];
    int aux_topo = p->topo;
    
    
    //procura o maior valor
    for(int i = 0; i < p->tamanho; i++){
        if(aux < p->pElem[i]){
            aux = p->pElem[i];
        }
        
    }
    printf("\nMaior valor: %.2f", aux);
    
    p->topo = aux_topo;
    aux = 0;
    
    
    
    //Calcula a média
    for(int i = 0; i < p->tamanho; i++){
        aux = aux + p->pElem[i];
    }
    
    
    aux = aux / (p->tamanho);
    printf("\nMédia: %.2f", aux);
    
    
    
    //procura o menor valor
    aux = p->pElem[0];
    for(int i = 0; i < p->tamanho; i++){
        if(aux > p->pElem[i]){
            aux = p->pElem[i];
        }
    }
    
    printf("\nMenor valor: %.2f", aux);
    
    
    
    
    printf("\n<-------------------------------->\n\n");
    
}

void copia_pilha(struct pilha *p, struct pilha *copia){
    copia->tamanho = p->tamanho;
    
    for(int i = 0; i < p->tamanho; i++){
        copia->pElem[i] = p->pElem[i];
        
    }
    
    copia->topo = copia->tamanho - 1;
    
    printf("\nPilha copiada com sucesso!!");
}

void retorna_impar_par(struct pilha *p){
    int impar = 0, par = 0;
    
    for(int i = 0; i < p->tamanho; i++){
        if(fmod(p->pElem[i], 2) == 0){
            par++;
        }
        
        else{
            impar++;
        }
    }
    
    printf("\nA pilha possui %d impares e %d pares", impar, par);
    printf("\n<-------------------------------->\n\n");
}

void imprime_pilha(struct pilha *p){
    for(int i = 0; i < p->tamanho; i++){
        printf("\n%dº valor: %.2f", i + 1, p->pElem[i]);
    }
    printf("\n<-------------------------------->\n\n");
}

int main(void)
{
    //int repetir = 0;

    
    struct pilha variavelPilha1;
    int tamanho1 = 0;
    
    struct pilha variavelPilha2;
    int tamanho2 = 0;
    
    printf("\nInforme o tamanho da primeira pilha: ");
    scanf("%d", &tamanho1);
    
    printf("\nInforme o tamanho da segunda pilha: ");
    scanf("%d", &tamanho2);
    
    /*
    while(repetir == 0){
    
    
    int opcao = 0;
    
    printf("\nInforme a operação: \n1 - Cria pilha\n2 - Empilha\n3 - Desempilha\n4 - Retorna Topo\n5 - Verifica vazio\n6 - Verifica Cheio\n7 - Sair\n");
    scanf("%d", &opcao);
    
    if(opcao == 1){
      cria_pilha(&variavelPilha, tamanho);  
    }
    
    if(opcao == 2){
        empilha(&variavelPilha);
    }
    
    if(opcao == 3){
        float valorPilha;
        
        valorPilha = desempilha(&variavelPilha);
        //printf("\nValor: %f", valorPilha);
    }
    
    if(opcao == 4){
        retornaTopo(&variavelPilha);
    }
    
    if(opcao == 5){
        verificaVazio(&variavelPilha);
    }
    
    if(opcao == 6){
        verificaCheio(&variavelPilha);
    }
    
    if(opcao == 7){
        repetir = 1;
    }
    
    
    
    }
    
    
   */
   
   cria_pilha(&variavelPilha1, tamanho1);
   cria_pilha(&variavelPilha2, tamanho2);
   
   if(variavelPilha1.tamanho == variavelPilha2.tamanho){
       printf("\nAs pilhas possuem o mesmo tamanho: ");
   }
   
   else if(variavelPilha1.tamanho > variavelPilha2.tamanho){
       printf("\nA pilha 1 é maior: ");
   }
   
   else if(variavelPilha1.tamanho < variavelPilha2.tamanho){
       printf("\nA pilha 2 é maior: ");
   }
   
   for(int i = 0;i < tamanho1; i++){
       
       empilha(&variavelPilha1);
       
       
   }
   
   for(int i = 0;i < tamanho2; i++){
       
       empilha(&variavelPilha2);
       
       
   }
   
   imprime_pilha(&variavelPilha1);
   imprime_pilha(&variavelPilha2);
   

   retornaValores(&variavelPilha1);
   retornaValores(&variavelPilha2);
   
   
   copia_pilha(&variavelPilha1, &variavelPilha2);
   
   
   imprime_pilha(&variavelPilha2);
   
   
   
   retorna_impar_par(&variavelPilha2);
   
   
   
   
    
   
}
