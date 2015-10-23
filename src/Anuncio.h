/*
 * Anuncio.h
 *
 *  Created on: 17/10/2015
 *      Author: Inês
 */

#ifndef SRC_ANUNCIO_H_
#define SRC_ANUNCIO_H_

#include <string>
#include "Data.h"

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
};

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
public:
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano);
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/ Data data);
};

class DeVenda: public Anuncio{
public:
	enum Estado {NOVO,USADO, FUNCIONAL, PECAS};
	DeVenda(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano,string estado,	float preco,bool negociacao);
private:
	Estado estado;
	float preco;
	bool negociacao;
};

class DeCompra: public Anuncio{
	DeVenda* troca;
public:
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano, DeVenda* ptr);
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano);
};


#endif /* SRC_ANUNCIO_H_ */
