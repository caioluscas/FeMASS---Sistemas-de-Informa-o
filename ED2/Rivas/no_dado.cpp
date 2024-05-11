//No_dado.cpp
#include "no_dado.h"

// Construtor
NoArv::NoArv() {
    this->numChaves = 0;
    this->chaves = 0;
    this->filhos = 0;
}

NoArv::NoArv(int i, NoArv* abb) {
    this->numChaves = 1;
    this->chaves = new int[1];
    this->chaves[0] = i;
    this->filhos = new NoArv*[2];
    this->filhos[0] = abb;
    this->filhos[1] = abb;
}

// Destrutor
NoArv::~NoArv() {
    delete[] chaves;
    delete[] filhos;
}
