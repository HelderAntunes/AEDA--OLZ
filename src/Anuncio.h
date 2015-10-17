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

class Anuncio{
	static int identificador;
protected:
	string titulo;
	string categoria;
	string descricao;
	//imagens
	int id;
	Data data;
	int visualizacoes;
public:
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano);
};

class DeVenda: public Anuncio{
	string estado;
	float preco;
	bool negociacao;
public:
	DeVenda(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano,string estado,	float preco,bool negociacao);
};

class DeCompra: public Anuncio{
	DeVenda* troca;
public:
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano, DeVenda* ptr);
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano);
};


#endif /* SRC_ANUNCIO_H_ */
