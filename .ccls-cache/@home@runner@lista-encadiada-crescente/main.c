#include <stdio.h>
#include <stdlib.h>

int controleMenu=1;

struct Node{
 int valor;
 struct Node *prox;
};
typedef struct Node node;

void inserir(node **p)
{
    node *atual, *novo, *anterior;
    int num;

    novo = (node *) malloc(sizeof(node));

    atual = *p;
    anterior = NULL;

    printf("Insira um valor: ");
    scanf("%d", &num);

    novo->valor = num;

    if(atual == NULL){
        novo->prox = NULL;
        *p = novo;
    } else{
        while(atual != NULL && atual->valor < num){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            *p = novo;
        } else{
            anterior->prox = novo;
        }
    }
}

void mostraLista(node *p)
{
 printf("fora do while");
    while(p != NULL)
    {
        printf("Lista: \n");
        printf("%d \n", p->valor);
        p = p->prox;
    }
}

void Menu(){
	node *inicio = NULL;
	
	printf(" ---------- Menu --------- \n");
	printf("1 - Inserir \n");
	printf("2 - Exibir \n");
	printf("3 - Sair \n");
	int op;
	scanf("%d", &op);

	switch(op){

		case 1:
			inserir(&inicio);
		break;
		
    case 2:
			printf("case 2");
		  mostraLista(inicio);
		break;
		case 3:
			printf("Saindo...");
			exit(1);
		break;
		default:
		printf("Digite uma opção válida");
	}
}

int main(){
	do{Menu();}while(controleMenu ==1);
}