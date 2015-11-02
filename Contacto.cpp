/*
 * Contacto.cpp
 * Author: Helder Antunes
 */

#include "Contacto.h"

/******************************
 * Functions of class Contacto*
 ******************************/



/**
 * @brief class Contacto constructor
 *
 * @param pointer to anunciante
 * @param pointer to interested person
 * @param pointer to anuncio
 * @param message to send to anunciante
 * @param numTel_pessoaInt to send to anunciante
 */
Contacto::Contacto(Utilizador* anunciante,Utilizador* pessoaInt,
		Anuncio* anuncio, string mensagem, string numTel_pessoaInt)
:anunciante(anunciante),
 pessoaInt(pessoaInt),
 mensagem(mensagem),
 numTel_pessoaInt(numTel_pessoaInt)
{
	concretizado = false;
	montanteNegociado = 0;
	dataNegociada = Data(0,0,0);
}

void Contacto::setAnuncioPtr(Anuncio* anuncio){
	this->anuncio = anuncio;
}

Anuncio* Contacto::getAnuncioPtr(){
	return anuncio;
}

Utilizador* Contacto::getAnunciante(){
	return anunciante;
}

Utilizador* Contacto::getPessoaInteressada(){
	return pessoaInt;
}

bool Contacto::negocioEstaConcretizado(){
	return concretizado;
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

	cout << "Mensagem da pessoa interessada\n";
	cout << mensagem << endl;

	if(pessoaInt != NULL)
		cout << "Numero de telemovel da pessoa interessada: " << numTel_pessoaInt << endl;
}

void Contacto::imprimeNegocioConcretizado(){
	if(anunciante != NULL)
		cout << "Anuciante: " << anunciante->getNome() << endl;
	else
		cout << "Anunciante ja nao se encontra registado no site OLZ.\n";

	if(pessoaInt != NULL)
		cout << "Pessoa interessada: " << pessoaInt->getNome() << endl;
	else
		cout << "A pessoa interessada ja nao se encontra registado no site OLZ.\n";

	cout << "Mensagem da pessoa interessada\n";
	cout << mensagem << endl;

	if(pessoaInt != NULL)
		cout << "Numero de telemovel da pessoa interessada: " << numTel_pessoaInt << endl;

	cout << "Quantia negociada: " << montanteNegociado << endl;
	cout << "Data do negocio: " << dataNegociada << endl;
}

void Contacto::setAnunciantePtr_toNull(){
	anunciante = NULL;
}
void Contacto::setPessoaInteressadaPtr_toNull(){
	pessoaInt = NULL;
}

/**
 * @brief class contacto destructor
 */
Contacto::~Contacto() {}
