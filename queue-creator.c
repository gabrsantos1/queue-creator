#include <stdio.h>
#include <locale.h>

#define MAX 10  // Definindo o tamanho m�ximo da fila

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

int filaCheia(Fila *fila) {
    return fila->tras == MAX - 1;
}

int filaVazia(Fila *fila) {
    return fila->frente == -1;
}

void enfileirar(Fila *fila, int valor) {
    if (filaCheia(fila)) {
        printf("Fila cheia! N�o � poss�vel adicionar um novo item.\n");
    } else {
        if (filaVazia(fila)) {
            fila->frente = 0; 
        }
        fila->tras++;
        fila->itens[fila->tras] = valor;
        printf("Valor %d adicionado � fila.\n", valor);
    }
}

int desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! N�o � poss�vel remover um item.\n");
        return -1;  
    } else {
        int valor = fila->itens[fila->frente];
        printf("Valor %d removido da fila.\n", valor);
        if (fila->frente == fila->tras) {
            fila->frente = fila->tras = -1; 
        } else {
            fila->frente++;
        }
        return valor;
    }
}

void verificarEspaco(Fila *fila) {
    if (filaCheia(fila)) {
        printf("N�o h� espa�o na fila.\n");
    } else {
        printf("H� espa�o na fila.\n");
    }
}

void exibirFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
    } else {
        printf("Fila: ");
        for (int i = fila->frente; i <= fila->tras; i++) {
            printf("%d ", fila->itens[i]);
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Fila fila;
    inicializarFila(&fila);
    int opcao, valor;

    while (1) {
        printf("\nMenu de Op��es:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Verificar espa�o na fila\n");
        printf("4. Exibir fila\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (filaCheia(&fila)) {
                    printf("Fila cheia! N�o � poss�vel adicionar mais elementos.\n");
                } else {
                    printf("Digite o valor para enfileirar: ");
                    scanf("%d", &valor);
                    enfileirar(&fila, valor);
                }
                break;
            
            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                verificarEspaco(&fila);
                break;

            case 4:
                exibirFila(&fila);
                break;

            case 5:
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    }

    return 0;
}

