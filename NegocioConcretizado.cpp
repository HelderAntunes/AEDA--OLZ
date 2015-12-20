/*
 * NegocioConcretizado.cpp
 *
 *  Created on: 16/12/2015
 *      Author: Helder Antunes
 */

#include "NegocioConcretizado.h"

NegocioConcretizado::NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt,
		Anuncio* anuncio, float montanteNegociado, string mensagem):

		dataNegociada(dataNegociada), anunciante(anunciante), pessoaInt(pessoaInt), descricaoAnuncio(anuncio->getDescricao()),
		categoria(anuncio->getCategoria()), montanteNegociado(montanteNegociado), mensagem(mensagem){}

NegocioConcretizado::~NegocioConcretizado() {}

Data NegocioConcretizado::getDataNegociada() const{	return dataNegociada;}

Utilizador* NegocioConcretizado::getAnunciante() const{	return anunciante;}

Utilizador* NegocioConcretizado::getPessoaInteressada() const{ return pessoaInt;}

string NegocioConcretizado::getCategoria() const{ return categoria;}

string NegocioConcretizado::getDescricao() const{ return descricaoAnuncio;}

float NegocioConcretizado::getMontanteNegociado() const{ return montanteNegociado;}

string NegocioConcretizado::getMensagem() const{ return mensagem;}

void NegocioConcretizado::setAnunciantePtr_toNull(){ anunciante = NULL;}

void NegocioConcretizado::setPessoaInteressadaPtr_toNull(){	pessoaInt = NULL;}

void NegocioConcretizado::imprimeNegocioConcretizado(){
	if(anunciante != NULL)
		cout << "Anuciante: " << anunciante->getNome() << endl;
	else
		cout << "Anunciante ja nao se encontra registado no site OLZ.\n";

	if(pessoaInt != NULL)
		cout << "Pessoa interessada: " << pessoaInt->getNome() << endl;
	else
		cout << "A pessoa interessada ja nao se encontra registado no site OLZ.\n";

	cout << "Objeto negociado:" << descricaoAnuncio << endl;


	cout << "Mensagem da pessoa interessada:\n";
	cout << mensagem << endl;

	cout << "Montante negociado: " << montanteNegociado << "€\n";
	cout << "Data do negocio: " << dataNegociada << endl;
}

ostream &operator<<(ostream &out, NegocioConcretizado nc){

	out << nc.dataNegociada << endl;
	out << nc.anunciante->getEmail() << endl;
	out << nc.pessoaInt->getEmail() << endl;
	out << nc.descricaoAnuncio << endl;
	out << nc.mensagem << endl;

	return out;
}
