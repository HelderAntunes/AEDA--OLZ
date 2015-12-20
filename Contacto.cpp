/*
 * Contacto.cpp
 * Author: Helder Antunes
 */

#include "Contacto.h"

Contacto::Contacto(Utilizador* anunciante,Utilizador* pessoaInt,
		Anuncio* anuncio, string mensagem, string numTel_pessoaInt)
:anunciante(anunciante),
 pessoaInt(pessoaInt),
 anuncio(anuncio),
 mensagem(mensagem),
 numTel_pessoaInt(numTel_pessoaInt)
{}

void Contacto::setAnuncioPtr_toNull(){
	this->anuncio = NULL;
}

Anuncio* Contacto::getAnuncio() const{
	return anuncio;
}

Utilizador* Contacto::getAnunciante() const{
	return anunciante;
}

Utilizador* Contacto::getPessoaInteressada() const{
	return pessoaInt;
}

NegocioConcretizado* Contacto::concretizaNegocio(float montanteNegociado, Data data){

	return new NegocioConcretizado(data, anunciante,pessoaInt,anuncio,montanteNegociado,mensagem);
}

void Contacto::imprimeContacto(){

	if(anunciante != NULL)
		cout << "Anuciante: " << anunciante->getNome() << endl;
	else
		cout << "Anunciante ja nao se encontra registado no site OLZ.\n";

	if(pessoaInt != NULL)
		cout << "Pessoa interessada: " << pessoaInt->getNome() << endl;
	else
		cout << "A pessoa interessada ja nao se encontra registado no site OLZ.\n";

	if(anuncio != NULL)
		cout << "Id do anuncio:" << anuncio->getId() << endl;
	else
		cout << "Anuncio ja nao se encontra no site OLZ.\n";

	cout << "Mensagem da pessoa interessada:\n";
	cout << mensagem << endl;

	if(pessoaInt != NULL)
		cout << "Numero de telemovel da pessoa interessada: " << numTel_pessoaInt << endl;
}

void Contacto::setAnunciantePtr_toNull(){
	anunciante = NULL;
}

void Contacto::setPessoaInteressadaPtr_toNull(){
	pessoaInt = NULL;
}

string Contacto::getMensagem()const{
	return mensagem;
}

string Contacto::getNumTel_PessoaInt(){
	return numTel_pessoaInt;
}

Contacto::~Contacto() {}

ostream &operator<<(ostream &out, Contacto c){
	if(c.anunciante != NULL)
		out << c.anunciante->getEmail() << endl;
	else
		out << "semEmail.pt\n";

	if(c.pessoaInt != NULL)
		out << c.pessoaInt->getEmail() << endl;
	else
		out << "semEmail.pt\n";

	if(c.anuncio != NULL)
		out << c.anuncio->getId() << endl;
	else
		out << -1 << endl;

	out << c.mensagem << endl;
	out << c.numTel_pessoaInt << endl;

	return out;
}
