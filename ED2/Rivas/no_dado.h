//No_dado.h

class NoArv {
public:
    int numChaves;        // Número de chaves armazenadas no nó
    int* chaves;          // Array para armazenar as chaves
    NoArv** filhos;       // Array para armazenar os ponteiros para os filhos

public:
    NoArv();
    NoArv(int i, NoArv* abb);
    ~NoArv();             // Adicione um destrutor para liberar a memória dos arrays
};
