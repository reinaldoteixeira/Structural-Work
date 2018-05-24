#include <iostream>
#include <cstdlib>
#include "arvore.h"
#include "level.h"
#include <queue>

using namespace std;


void Arvore::inicializar(){
	this->raiz = NULL;	
}



No *inserirElemento(No *raiz,Level *level, int father){ //function aux 
	if(raiz == NULL){
		raiz = (No*) malloc(sizeof(No)); 
		raiz->level = level;
		raiz->dir = NULL;
		raiz->esq = NULL;
	}
	else if (raiz->level->level == father){
		if(raiz->esq == NULL)
			raiz->esq = inserirElemento(raiz->esq,level, father);
		else if(raiz->dir == NULL)
			raiz->dir = inserirElemento(raiz->dir,level, father);
		else
			cout << "Elemento Ja Existe" << endl;
	}
	else{
		if(raiz->esq != NULL)
			raiz->esq = inserirElemento(raiz->esq,level,father);
		if(raiz->dir != NULL)
			raiz->dir = inserirElemento(raiz->dir,level,father);
	}
	return raiz;
}

void Arvore::inserir(Level *level, int father){
	if(this->raiz == NULL)
		this->raiz = inserirElemento(this->raiz,level, father); 
	else
		inserirElemento(this->raiz,level, father); 
}
void exibirPreOrdem(No *raiz){
	
	if(raiz!=NULL){
		cout<<raiz->level->level << ", ";
		exibirPreOrdem(raiz->esq);
		exibirPreOrdem(raiz->dir);
	}
}
/*
void exibirPosOrdem(No *raiz){
	
	if(raiz!=NULL){
		
		exibirPosOrdem(raiz->esq);
		exibirPosOrdem(raiz->dir);
		cout<<raiz->elemento << ", ";
	}
}

void exibirEmOrdem(No *raiz){	
	if(raiz!=NULL){
		exibirEmOrdem(raiz->esq);
		cout<<raiz->elemento << ", ";
		exibirEmOrdem(raiz->dir);
	}
}



void exibirPorNivel(No *raiz){
	queue<No*> fila;
	fila.push(raiz);
	
	while(!fila.empty()){
		No *aux = fila.front();
		cout << aux->elemento << ", " ;
		if(aux->esq != NULL)
			fila.push(aux->esq);
		if(aux->dir != NULL)
			fila.push(aux->dir);
		
		fila.pop();
		
		
	}

}


*/
void Arvore::exibir(){
	cout << "Pre Ordem " << endl;
	exibirPreOrdem(this->raiz);
	
	//cout << endl << endl << "Pos Ordem " << endl;
	//exibirPosOrdem(this->raiz);
	
	//cout << endl << endl << "Em Ordem " << endl;
//	exibirEmOrdem(this->raiz);
	
	//cout << endl << endl << "Por Nivel " << endl;
	//exibirPorNivel(this->raiz);
	
	cout << endl << endl;
	//system("pause");
}
/*
No *removeNo(No *no){
	if(no->esq == NULL && no->dir == NULL){
		free(no);
		return NULL;
	}
	if(no->dir != NULL && no->esq == NULL){
		No* aux = no->dir;
		free(no);
		return aux;
	}
	if(no->esq != NULL && no->dir == NULL){
		No* aux = no->esq;
		free(no);
		return aux;
	}
	
	No *novo = no->esq;
	No *pai = no;
	
	while(novo->dir != NULL){
		pai = novo;
		novo = novo->dir;
	}
	if(pai!=no){
		pai->dir = novo->esq;
		novo->esq = no->esq;
	}
	novo->dir = no->dir;
	free(no);
	return novo;
}
void Arvore::remover(Level elemento){
	No *pai = NULL;
	No *no = raiz;
	
	while(no != NULL){
		if(no->elemento == elemento){
			if(no == raiz)
				raiz = removeNo(no);
			else{
				if(pai->esq == no)
					pai->esq = removeNo(no);
				else
					pai->dir = removeNo(no);
			}
			return;	
		}
		else{
			pai = no;
			if(elemento < no->elemento)
				no = no->esq;
			else
				no = no->dir;
		}
			
			
	}
}*/

























