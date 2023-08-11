#include <stdio.h>

#define MAX_SIZE 20


typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;


void criarConjuntoVazio(Conjunto *conj) {
    conj->tamanho = 0;
}


void lerConjunto(Conjunto *conj) {
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &conj->tamanho);

    if (conj->tamanho > MAX_SIZE) {
        printf("Tamanho do conjunto excede o limite.\n");
        return;
    }

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < conj->tamanho; i++) {
        scanf("%d", &conj->elementos[i]);
    }
}


int estaNoConjunto(int elemento, Conjunto *conj) {
    for (int i = 0; i < conj->tamanho; i++) {
        if (conj->elementos[i] == elemento) {
            return 1;
        }
    }
    return 0;
}


void uniaoConjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conj1->tamanho; i++) {
        resultado->elementos[resultado->tamanho++] = conj1->elementos[i];
    }

    for (int i = 0; i < conj2->tamanho; i++) {
        if (!estaNoConjunto(conj2->elementos[i], resultado)) {
            resultado->elementos[resultado->tamanho++] = conj2->elementos[i];
        }
    }
}


void intersecaoConjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conj1->tamanho; i++) {
        if (estaNoConjunto(conj1->elementos[i], conj2)) {
            resultado->elementos[resultado->tamanho++] = conj1->elementos[i];
        }
    }
}


int saoIguais(Conjunto *conj1, Conjunto *conj2) {
    if (conj1->tamanho != conj2->tamanho) {
        return 0;
    }

    for (int i = 0; i < conj1->tamanho; i++) {
        if (!estaNoConjunto(conj1->elementos[i], conj2)) {
            return 0;
        }
    }

    return 1;
}


void imprimirConjunto(Conjunto *conj) {
    printf("{ ");
    for (int i = 0; i < conj->tamanho; i++) {
        printf("%d ", conj->elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto conjunto1, conjunto2, resultado;

    criarConjuntoVazio(&conjunto1);
    criarConjuntoVazio(&conjunto2);
    criarConjuntoVazio(&resultado);

    printf("Digite os elementos do conjunto 1:\n");
    lerConjunto(&conjunto1);

    printf("Digite os elementos do conjunto 2:\n");
    lerConjunto(&conjunto2);

    printf("Conjunto 1: ");
    imprimirConjunto(&conjunto1);

    printf("Conjunto 2: ");
    imprimirConjunto(&conjunto2);

    uniaoConjuntos(&conjunto1, &conjunto2, &resultado);
    printf("União: ");
    imprimirConjunto(&resultado);

    intersecaoConjuntos(&conjunto1, &conjunto2, &resultado);
    printf("Interseção: ");
    imprimirConjunto(&resultado);

    if (saoIguais(&conjunto1, &conjunto2)) {
        printf("Conjuntos iguais.\n");
    } else {
        printf("Conjuntos diferentes.\n");
    }

    return 0;
}

