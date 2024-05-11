//Abb.h
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> //aplicada para função abb_displayTree - contâiner C++ LIFO
#include "no_dado.h"
#define ORDER 5 // Definindo o valor de ORDER como 5

using namespace std;

class ArvBB {
private:
    // Modificações na estrutura do nó
    struct BNode {
        int keys[ORDER]; // Array de chaves
        BNode* children[ORDER + 1]; // Array de ponteiros para os filhos
        bool leaf; // Indica se é um nó folha
        int numKeys; // Número atual de chaves
    };

    BNode* root; // Ponteiro para o nó raiz

public:
    ArvBB();
    ~ArvBB();
    void insere(int v);
    void busca(int v);
    void retira(int v);
    void displayTree();
    bool vazia();
    void displayRoot();
    void liberarArvore();

private:
    BNode* criaNo();
    void divideNo(BNode* parent, int childIndex, BNode* child);
    void insereNoNaoCheio(BNode* node, int key);
    void buscaNo(BNode* node, int key);
    void removeNo(BNode* node, int key);
    void displayNode(BNode* node);
    void liberarArvoreRecursivo(BNode* node);
};
