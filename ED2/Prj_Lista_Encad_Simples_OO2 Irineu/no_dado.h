//no_dado.h

class no_dado{
	//Declarar atributos
	public:
		int info;
		no_dado* prox; 
	
	//Declara m�todos
	public:
		no_dado(); //construtor sem passagem de par�metros
		no_dado(int x, no_dado* ptr); //construtor com passagem de par�metros	
				
};
