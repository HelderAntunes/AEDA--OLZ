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
 anuncio(anuncio),
 mensagem(mensagem),
 numTel_pessoaInt(numTel_pessoaInt)
{
	concretizado = false;
	montanteNegociado = 0;
	dataNegociada = Data(0,0,0);
}

/**
 * @brief set add pointer to null
 */
void Contacto::setAnuncioPtr_toNull(){
	this->anuncio = NULL;
}

/**
 * @brief get pointer to add
 * @return Anuncio* anuncio
 */
Anuncio* Contacto::getAnuncio(){
	return anuncio;
}

/**
 * @brief get pointer to advertiser
 * @return Utilizador* anunciante
 */
Utilizador* Contacto::getAnunciante(){
	return anunciante;
}

/**
 * @brief get pointer to interested person
 * @return Utilizador* pessoaInt
 */
Utilizador* Contacto::getPessoaInteressada(){
	return pessoaInt;
}

/**
 * @brief reveals if trade is concretized
 * @return bool concretizado
 */
bool Contacto::negocioEstaConcretizado(){
	return concretizado;
}

/**
 * @brief concretize the trade
 * @param int montanteNegociado
 * @param Data data of negotiation
 */
void Contacto::concretizaNegocio(float montanteNegociado, Data data){
	concretizado = true;
	this->montanteNegociado = montanteNegociado;
	this->dataNegociada = data;
}

/**
 * @brief print the contact
 */
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

/**
 * @brief print the contact traded
 */
void Contacto::imprimeNegocioConcretizado(){
	if(anunciante != NULL)
		cout << "Anuciante: " << anunciante->getNome() << endl;
	else
		cout << "Anunciante ja nao se encontra registado no site OLZ.\n";

	if(pessoaInt != NULL)
		cout << "Pessoa interessada: " << pessoaInt->getNome() << endl;
	else
		cout << "A pessoa interessada ja nao se encontra registado no site OLZ.\n";

	cout << "Mensagem da pessoa interessada:\n";
	cout << mensagem << endl;

	if(pessoaInt != NULL)
		cout << "Numero de telemovel da pessoa interessada: " << numTel_pessoaInt << endl;

	cout << "Quantia negociada: " << montanteNegociado << endl;
	cout << "Data do negocio: " << dataNegociada << endl;
}

/**
 * @brief set pointer to advertiser to NULL
 */
void Contacto::setAnunciantePtr_toNull(){
	anunciante = NULL;
}

/**
 * @brief set pointer to interested person to NULL
 */
void Contacto::setPessoaInteressadaPtr_toNull(){
	pessoaInt = NULL;
}

/**
 * @brief get message between two users
 *
 * @return message
 */
string Contacto::getMensagem(){
	return mensagem;
}

/**
 * @brief get phone number of interested person
 *
 * return numTel_pessoaInt
 */
string Contacto::getNumTel_PessoaInt(){
	return numTel_pessoaInt;
}

/**
 * @brief get the amount traded, it will be 0 if not negotiated
 *
 * @return montanteNegociado
 */
float Contacto::getMontanteNegociado(){
	return montanteNegociado;
}

/**
 * @brief get the data of negotiation, it will be 0/0/0 if not negotiated
 *
 * @return data
 */
Data Contacto::getDataNegociada(){
	return dataNegociada;
}

/**
 * @brief class contacto destructor
 */
Contacto::~Contacto() {}
