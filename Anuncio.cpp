/**
* @file Anuncio.cpp
*
* @brief Code for class Anuncio*/

#include"Anuncio.h"
#include"Data.h"

using namespace std;

int Anuncio::identificador(0);

Anuncio::Anuncio(string titulo, string categoria, string descricao, Utilizador* anunciante): id(identificador++), cat (Categoria(categoria)){
	this->titulo = titulo;
	this->descricao = descricao;
	this->visualizacoes = 0;
	this->anunciante = anunciante;

	//Obter a data de criacao
	time_t t = time(0);   // get time now
	tm * now = localtime( & t );
	this->data = Data(now->tm_mday,now->tm_mon + 1,now->tm_year + 1900);
}

Anuncio::~Anuncio(){}

string Anuncio::getTitulo(){return titulo;}

string Anuncio::getCategoria(){	return cat;}

int Anuncio::getId(){return id;}

Data Anuncio::getData(){ return data;}

int Anuncio::getVisualizacoes(){return visualizacoes;}

void Anuncio::incVisualizacoes(){
	this->visualizacoes ++;
}

DeVenda::DeVenda(string titulo,	string categoria,string descricao,/*imagens*/Estado estado,float preco, bool negociacao,Utilizador* anunciante) :
										Anuncio(titulo,categoria,descricao/*imagens*/, anunciante){
	this->estado = estado;
	this->preco = preco;
	this->negociacao = negociacao;
}

Estado DeVenda::getEstado(){return estado;}

float DeVenda::getPreco(){ return preco;}

void DeVenda::setPreco(float preco){this->preco = preco;}

void DeVenda::imprime() const {
	cout << id << ". Vende-se " << titulo << endl;
	cout << "\t Categoria: " << cat.getCat() << endl;
	cout << descricao << endl;
	switch(estado){
	case NOVO:
		cout << "Artigo novo\n";
	case USADO:
		cout << "Artigo usado como novo\n";
	case FUNCIONAL:
		cout << "Artigo funcional\n";
	case PECAS:
		cout << "Artigo indicado somente para pecas";
	}
	cout << preco << "€";
	if(negociacao)
		cout << " mas com possibilidade de negociar preco";
	//Imprimir os dados que o anunciante deseja mostrar
	cout << "\n\tcriado em: " << data <<endl;
}

DeCompra::DeCompra(string titulo, string categoria, string descricao,/*imagens*/DeVenda* ptr, Utilizador* anunciante):
										Anuncio(titulo,categoria,descricao/*imagens*/, anunciante){
	this->troca = ptr;
}

DeCompra::DeCompra(string titulo, string categoria, string descricao,/*imagens*/ Utilizador* anunciante):
												Anuncio(titulo,categoria,descricao/*imagens*/, anunciante){
	this->troca = NULL;
}

void DeCompra::imprime() const{
	cout << id << ". Compra-se " << titulo << endl;
	cout << "\t Categoria: ";
	cout << cat.getCat() << endl;
	cout << descricao << endl;
	if(troca != NULL)
		cout << "Aceita-se tambem troca pelo produto de id: " << troca->getId() << endl;
	//Imprimir os dados que o anunciante deseja mostrar
	cout << "\tcriado em: " << data <<endl;
}
