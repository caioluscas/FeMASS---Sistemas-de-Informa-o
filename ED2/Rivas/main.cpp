#include <iostream>
#include "abb.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ArvBB arvore;
    int opcao, chave;

    while (true) {
        cout << "\n==== ÁRVORE B+ ====\n";
        cout << "1. Inserir chave\n";
        cout << "2. Buscar chave\n";
        cout << "3. Remover chave\n";
        cout << "4. Exibir árvore\n";
        cout << "5. Exibir chave raiz\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a chave a ser inserida: ";
                cin >> chave;
                arvore.insere(chave);
                break;
            case 2:
                cout << "Digite a chave a ser buscada: ";
                cin >> chave;
                arvore.busca(chave);
                break;
            case 3:
                cout << "Digite a chave a ser removida: ";
                cin >> chave;
                arvore.retira(chave);
                break;
            case 4:
                arvore.displayTree();
                break;
            case 5:
                arvore.displayRoot();
                break;
            case 6:
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
