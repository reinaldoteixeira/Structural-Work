#ifndef _arvore_h_
#define _arvore_h_
#include "level.h"

struct No{
	
	Level *level;
	No *esq;
	No *dir;
	
};

struct Arvore{
	
	No *raiz;
	
	void inicializar();
	void exibir();
	void inserir(Level *level, int father);
//	void remover(Level elemento); 
	
};
#endif
