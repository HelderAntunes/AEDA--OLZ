/*
 * Anuncio.h
 *
 *  Created on: 17/10/2015
 *      Author: Inês
 */

#ifndef SRC_ANUNCIO_H_
#define SRC_ANUNCIO_H_

#include <string>
#include <ctime>
#include "Data.h"
#include "Utilizador.h"

using namespace std;

class Categoria{
	string cat;
	Categoria* subCategoria;
public:
	Categoria(string nome){
		cat = nome;
		subCategoria = NULL;
	}
	Categoria(string nome, Categoria* catPtr){
		this->cat = nome;
		this->subCategoria = catPtr;
	}
	string getCat(){return cat;}
};

enum Estado {NOVO,USADO, FUNCIONAL, PECAS};

class Anuncio{
	static int identificador;
protected:
	string titulo;
	Categoria cat;
	string descricao;
	//imagens
	int id;
	Data data;
	int visualizacoes;
	Utilizador* anunciante;
public:
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/Utilizador* anunciante);
	virtual ~Anuncio();
	string getTitulo();
	string getCategoria();
	int getId();
	Data getData();
	int getVisualizacoes();
	void incVisualizacoes();
	virtual void imprime() const = 0;
};

class DeVenda: public Anuncio{
	Estado estado;
	float preco;
	bool negociacao;
public:
	DeVenda(string titulo, string categoria, string descricao,/*imagens*/Estado estado,	float preco,bool negociacao,Utilizador* anunciante);
	Estado getEstado();
	float getPreco();
	void setPreco(float preco);
	void imprime() const ;
};

class DeCompra: public Anuncio{
	DeVenda* troca;
public:
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ DeVenda* ptr,Utilizador* anunciante);
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ Utilizador* anunciante);
	void imprime() const ;
};


#endif /* SRC_ANUNCIO_H_ */
