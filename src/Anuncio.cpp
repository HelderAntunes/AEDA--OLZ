/*
 * Anuncio.cpp
 *
 *  Created on: 17/10/2015
 *      Author: Inês
 */

#include"Anuncio.h"

int Anuncio::identificador(0);

Anuncio::Anuncio(string titulo,	string categoria,string descricao,/*imagens,*/int dia, int mes, int ano) : id(identificador ++){
	this->titulo = titulo;
	this->categoria = categoria;
	this->descricao = descricao;
	this->data = Data(dia,mes,ano);
	this->visualizacoes = 0;

}

DeVenda::DeVenda(string titulo,	string categoria,string descricao,/*imagens*/int dia,int mes,int ano,string estado,float preco, bool negociacao) :
				Anuncio(titulo,categoria,descricao,/*imagens*/dia,mes,ano){
	this->estado = estado;
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
