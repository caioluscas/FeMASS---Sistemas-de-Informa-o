//No_dado.h

class NoArv {
public:
    int numChaves;        // N�mero de chaves armazenadas no n�
    int* chaves;          // Array para armazenar as chaves
    NoArv** filhos;       // Array para armazenar os ponteiros para os filhos

public:
    NoArv();
    NoArv(int i, NoArv* abb);
    ~NoArv();             // Adicione um destrutor para liberar a mem�ria dos arrays
};
