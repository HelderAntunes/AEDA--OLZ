/*
 * Anuncio.cpp
 *
 *  Created on: 17/10/2015
 *      Author: Inês
 */

#include"Anuncio.h"
#include"Data.h"

int Anuncio::identificador(0);

Anuncio::Anuncio(string titulo,	string categoria,string descricao,/*imagens,*/int dia, int mes, int ano) : id(identificador ++), data(Data(dia,mes,ano)), cat (Categoria(categoria)){
	this->titulo = titulo;
	this->descricao = descricao;
	this->visualizacoes = 0;

}

Anuncio::Anuncio(string titulo, string categoria, string descricao,/*imagens*/ Data data): id(identificador ++), data(data), cat (Categoria(categoria)){
	this->titulo = titulo;
	this->descricao = descricao;
	this->visualizacoes = 0;
}

DeVenda::DeVenda(string titulo,	string categoria,string descricao,/*imagens*/int dia,int mes,int ano,string estado,float preco, bool negociacao) :
				Anuncio(titulo,categoria,descricao,/*imagens*/dia,mes,ano){
	if(estado == "novo")
		this->estado = NOVO;
	else if (estado == "usado")
		this->estado = USADO;
	else if (estado == "funcional")
		this->estado = FUNCIONAL;
	else if (estado == "pecas")
		this->estado = PECAS;
	this->preco = preco;
	this->negociacao = negociacao;
}

DeCompra::DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano, DeVenda* ptr):
				Anuncio(titulo,categoria,descricao,/*imagens*/dia,mes,ano){
	this->troca = ptr;
}

DeCompra::DeCompra(string titulo, string categoria, string descricao,/*imagens*/int dia,int mes,int ano):
						Anuncio(titulo,categoria,descricao,/*imagens*/dia,mes,ano){
	this->troca = NULL;
}
