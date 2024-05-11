//Abb.cpp
#define MIN_KEYS 2 // Valor mínimo de chaves em um nó
#define MIN_DEGREE (ORDER / 2) // Metade do valor de ORDER
#include "abb.h"
ArvBB::ArvBB() {
    root = NULL;
}

ArvBB::~ArvBB() {
    liberarArvore();
}

void ArvBB::insere(int v) {
    if (root == NULL) {
        root = criaNo();
        root->keys[0] = v;
        root->numKeys = 1;
        root->leaf = true;
    }
    else {
        if (root->numKeys == ORDER) {
            BNode* newRoot = criaNo();
            newRoot->children[0] = root;
            divideNo(newRoot, 0, root);
            root = newRoot;
        }
        insereNoNaoCheio(root, v);
    }
}

void ArvBB::busca(int v) {
    if (root != NULL) {
        buscaNo(root, v);
    }
    else {
        cout << "A árvore está vazia." << endl;
    }
}

void ArvBB::retira(int v) {
    if (root != NULL) {
        removeNo(root, v);
    }
    else {
        cout << "A árvore está vazia." << endl;
    }
}

void ArvBB::displayTree() {
    if (root != NULL) {
        displayNode(root);
    }
    else {
        cout << "A árvore está vazia." << endl;
    }
}

bool ArvBB::vazia() {
    return (root == NULL);
}

void ArvBB::displayRoot() {
    if (root != NULL) {
        cout << "Chave raiz: " << root->keys[0] << endl;
    }
    else {
        cout << "A árvore está vazia." << endl;
    }
}

void ArvBB::liberarArvore() {
    if (root != NULL) {
        liberarArvoreRecursivo(root);
        root = NULL;
    }
}

ArvBB::BNode* ArvBB::criaNo() {
    BNode* newNode = new BNode;
    newNode->numKeys = 0;
    newNode->leaf = true;
    for (int i = 0; i < ORDER + 1; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void ArvBB::divideNo(BNode* parent, int childIndex, BNode* child) {
    BNode* newChild = criaNo();
    newChild->leaf = child->leaf;
    newChild->numKeys = MIN_KEYS;

    for (int i = 0; i < MIN_KEYS; i++) {
        newChild->keys[i] = child->keys[i + MIN_DEGREE];
    }

    if (!child->leaf) {
        for (int i = 0; i < MIN_DEGREE; i++) {
            newChild->children[i] = child->children[i + MIN_DEGREE];
        }
    }

    child->numKeys = MIN_KEYS;

    for (int i = parent->numKeys; i > childIndex; i--) {
        parent->children[i + 1] = parent->children[i];
    }

    parent->children[childIndex + 1] = newChild;

    for (int i = parent->numKeys - 1; i >= childIndex; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }

    parent->keys[childIndex] = child->keys[MIN_KEYS - 1];

    parent->numKeys++;
}

void ArvBB::insereNoNaoCheio(BNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->numKeys++;
    }
    else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        i++;

        if (node->children[i]->numKeys == ORDER) {
            divideNo(node, i, node->children[i]);

            if (key > node->keys[i]) {
                i++;
            }
        }

        insereNoNaoCheio(node->children[i], key);
    }
}

void ArvBB::buscaNo(BNode* node, int key) {
    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) {
        i++;
    }

    if (i < node->numKeys && key == node->keys[i]) {
        cout << "Chave encontrada." << endl;
        return;
    }

    if (node->leaf) {
        cout << "Chave não encontrada." << endl;
        return;
    }

    buscaNo(node->children[i], key);
}

void ArvBB::removeNo(BNode* node, int key) {
    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) {
        i++;
    }

    if (i < node->numKeys && key == node->keys[i]) {
        // Remover chave do nó
        for (int j = i; j < node->numKeys - 1; j++) {
            node->keys[j] = node->keys[j + 1];
        }
        node->numKeys--;
        cout << "Chave removida." << endl;
        return;
    }

    if (node->leaf) {
        cout << "Chave não encontrada." << endl;
        return;
    }

    if (node->children[i]->numKeys == MIN_KEYS) {
        // Caso em que o filho tem a quantidade mínima de chaves
        BNode* leftSibling = (i > 0) ? node->children[i - 1] : NULL;
        BNode* rightSibling = (i < node->numKeys) ? node->children[i + 1] : NULL;

        if (leftSibling && leftSibling->numKeys > MIN_KEYS) {
            // Empréstimo de chave do irmão esquerdo
            for (int j = node->children[i]->numKeys; j > 0; j--) {
                node->children[i]->keys[j] = node->children[i]->keys[j - 1];
            }
            node->children[i]->numKeys++;
            node->children[i]->keys[0] = node->keys[i - 1];

            node->keys[i - 1] = leftSibling->keys[leftSibling->numKeys - 1];

            if (!node->children[i]->leaf) {
                for (int j = node->children[i]->numKeys; j > 0; j--) {
                    node->children[i]->children[j] = node->children[i]->children[j - 1];
                }
                node->children[i]->children[0] = leftSibling->children[leftSibling->numKeys];
            }

            leftSibling->numKeys--;
        }
        else if (rightSibling && rightSibling->numKeys > MIN_KEYS) {
            // Empréstimo de chave do irmão direito
            node->children[i]->keys[node->children[i]->numKeys] = node->keys[i];

            node->keys[i] = rightSibling->keys[0];

            for (int j = 0; j < rightSibling->numKeys - 1; j++) {
                rightSibling->keys[j] = rightSibling->keys[j + 1];
            }

            if (!node->children[i]->leaf) {
                node->children[i]->children[node->children[i]->numKeys + 1] = rightSibling->children[0];

                for (int j = 0; j < rightSibling->numKeys; j++) {
                    rightSibling->children[j] = rightSibling->children[j + 1];
                }
            }

            rightSibling->numKeys--;
        }
        else {
            // Fusão com irmão
            if (leftSibling) {
                // Fusão com irmão esquerdo
                leftSibling->keys[leftSibling->numKeys] = node->keys[i - 1];

                for (int j = 0; j < node->children[i]->numKeys; j++) {
                    leftSibling->keys[leftSibling->numKeys + 1 + j] = node->children[i]->keys[j];
                }

                if (!node->children[i]->leaf) {
                    for (int j = 0; j <= node->children[i]->numKeys; j++) {
                        leftSibling->children[leftSibling->numKeys + 1 + j] = node->children[i]->children[j];
                    }
                }

                leftSibling->numKeys += 1 + node->children[i]->numKeys;

                for (int j = i - 1; j < node->numKeys - 1; j++) {
                    node->keys[j] = node->keys[j + 1];
                    node->children[j + 1] = node->children[j + 2];
                }

                node->numKeys--;

                delete node->children[i];
            }
            else if (rightSibling) {
                // Fusão com irmão direito
                node->children[i]->keys[node->children[i]->numKeys] = node->keys[i];

                for (int j = 0; j < rightSibling->numKeys; j++) {
                    node->children[i]->keys[node->children[i]->numKeys + 1 + j] = rightSibling->keys[j];
                }

                if (!node->children[i]->leaf) {
                    for (int j = 0; j <= rightSibling->numKeys; j++) {
                        node->children[i]->children[node->children[i]->numKeys + 1 + j] = rightSibling->children[j];
                    }
                }

                node->children[i]->numKeys += 1 + rightSibling->numKeys;

                for (int j = i; j < node->numKeys - 1; j++) {
                    node->keys[j] = node->keys[j + 1];
                    node->children[j + 1] = node->children[j + 2];
                }

                node->numKeys--;

                delete rightSibling;
            }
        }
    }

    removeNo(node->children[i], key);
}

void ArvBB::displayNode(BNode* node) {
    if (node->leaf) {
        for (int i = 0; i < node->numKeys; i++) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < node->numKeys; i++) {
            displayNode(node->children[i]);
            cout << node->keys[i] << " ";
        }
        displayNode(node->children[node->numKeys]);
    }
}

void ArvBB::liberarArvoreRecursivo(BNode* node) {
    if (node->leaf) {
        delete node;
    }
    else {
        for (int i = 0; i <= node->numKeys; i++) {
            liberarArvoreRecursivo(node->children[i]);
        }
        delete node;
    }
}
