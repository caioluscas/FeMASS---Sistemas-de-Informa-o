//no_dado.h

class no_dado{
	//Declarar atributos
	public:
		int info;
		no_dado* prox; 
	
	//Declara métodos
	public:
		no_dado(); //construtor sem passagem de parâmetros
		no_dado(int x, no_dado* ptr); //construtor com passagem de parâmetros	
				
};
