/*
 * NegocioConcretizado.cpp
 *
 *  Created on: 16/12/2015
 *      Author: Helder Antunes
 */

#include "NegocioConcretizado.h"

NegocioConcretizado::NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt,
		string descricaoAnuncio, float montanteNegociado, string mensagem, string categoria):
		dataNegociada(dataNegociada),
		anunciante(anunciante),
		pessoaInt(pessoaInt),
		descricaoAnuncio(descricaoAnuncio),
		montanteNegociado(montanteNegociado){
	this->mensagem = mensagem;
	this->categoria = categoria;
}

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

	cout << "Montante negociado: " << montanteNegociado << "�\n";
	cout << "Data do negocio: " << dataNegociada << endl;
}

ostream &operator<<(ostream &out,const NegocioConcretizado& nc){

	out << nc.dataNegociada << endl;

	if(nc.anunciante != NULL)
		out << nc.anunciante->getEmail() << endl;
	else
		out << "semEmail.pt\n";

	if(nc.pessoaInt != NULL)
		out << nc.pessoaInt->getEmail() << endl;
	else
		out << "semEmail.pt\n";

	out << nc.descricaoAnuncio << endl;
	out << nc.montanteNegociado << endl;
	out << nc.mensagem << endl;
	out << nc.categoria << endl;

	return out;
}



