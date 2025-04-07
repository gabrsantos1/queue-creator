#include <stdio.h>
#include <locale.h>

#define MAX 10  // Definindo o tamanho máximo da fila

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
        printf("Fila cheia! Não é possível adicionar um novo item.\n");
    } else {
        if (filaVazia(fila)) {
            fila->frente = 0; 
        }
        fila->tras++;
        fila->itens[fila->tras] = valor;
        printf("Valor %d adicionado à fila.\n", valor);
    }
}

int desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não é possível remover um item.\n");
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
        printf("Não há espaço na fila.\n");
    } else {
        printf("Há espaço na fila.\n");
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
        printf("\nMenu de Opções:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Verificar espaço na fila\n");
        printf("4. Exibir fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (filaCheia(&fila)) {
                    printf("Fila cheia! Não é possível adicionar mais elementos.\n");
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
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

