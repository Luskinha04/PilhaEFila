#include<stdio.h>

struct No {
    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Fila {
    No *inicio, *fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void inserir(int valor) {
        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;
    }

    int remover() {
        if (vazia()) return -1;

        int valor = inicio->valor;
        No *r = inicio;
        inicio = inicio->prox;
        delete(r);
        n--;

        if (inicio == NULL) {
            fim = NULL;
        }

        return valor;
    }
};

struct Pilha {
    No *inicio;
    int n;

    Pilha() {
        inicio = NULL;
        n = 0;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void inserir(int valor) {
        n++;
        No *novo = new No(valor);

        novo->prox = inicio;
        inicio = novo;
    }

    int remover() {
        if (vazia()) return -1;

        int valor = inicio->valor;
        No *r = inicio;
        inicio = inicio->prox;
        delete(r);
        n--;

        return valor;
    }
};

void inverterFila(Fila &f) {
    Pilha p;

    while (!f.vazia()) {
        p.inserir(f.remover());
    }

    while (!p.vazia()) {
        f.inserir(p.remover());
    }
}

int main() {
    Fila f;
    f.inserir(1);
    f.inserir(2);
    f.inserir(3);
    f.inserir(4);
    f.inserir(5);
    f.inserir(6);
    f.inserir(7);
    f.inserir(8);
    f.inserir(9);

    inverterFila(f);

    while (!f.vazia()) {
        printf("%d ", f.remover());
    }

    return 0;
}
