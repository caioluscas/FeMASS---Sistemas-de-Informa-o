//no_dado.cpp
#include "no_dado.h"

no_dado::no_dado(){ //Construtor - inicializar atributos em NULL
	this->info = 0;
	this->prox = 0; //NULL
}

no_dado::no_dado(int x, no_dado* ptr){ //construtor com passagem de parâmetros	
	this->info = x;
	this->prox = ptr;
}
