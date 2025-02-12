//PILHA

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int vetor[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1; 
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->vetor[++(p->topo)] = valor; 
}

int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; 
    }
    return p->vetor[(p->topo)--];
}

void imprimirPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->vetor[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    imprimirPilha(&p);

    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));

    imprimirPilha(&p);

    return 0;
}

//FILA
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int vetor[TAMANHO_MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1; 
}

int estaVazia(Fila *f) {
    return f->fim < f->inicio; 
}

int estaCheia(Fila *f) {
    return f->fim == TAMANHO_MAX - 1;
}

void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->vetor[++(f->fim)] = valor; 
}

int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; 
    }
    return f->vetor[(f->inicio)++];
}

void imprimirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->inicio; i <= f->fim; i++) {
        printf("%d ", f->vetor[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    imprimirFila(&f);

    printf("Desenfileirado: %d\n", desenfileirar(&f));
    printf("Desenfileirado: %d\n", desenfileirar(&f));

    imprimirFila(&f);

    return 0;
}

//Quicksort

#include <stdio.h>


void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; 
    int i = inicio - 1;    

    for (int j = inicio; j < fim; j++) {
        
        if (vetor[j] <= pivo) {
            i++; 
            trocar(&vetor[i], &vetor[j]);
        }
    }
    
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1; 

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

//Merge Sort

#include <stdio.h>
#include <stdlib.h>

void mesclar(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1; 
    int n2 = fim - meio;        

    int *esquerda = (int *)malloc(n1 * sizeof(int));
    int *direita = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    i = 0; 
    j = 0; 
    k = inicio; 

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

// Função MergeSort

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2; 
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        mesclar(vetor, inicio, meio, fim);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    mergeSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

//<Selection Sort>
#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        trocar(&vetor[indiceMenor], &vetor[i]);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    selectionSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}