/*
 * NegocioConcretizado.cpp
 *
 *  Created on: 16/12/2015
 *      Author: Helder Antunes
 */

#include "NegocioConcretizado.h"

NegocioConcretizado::NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt,
		Anuncio* anuncio, float montanteNegociado, string mensagem):

		dataNegociada(dataNegociada), anunciante(anunciante), pessoaInt(pessoaInt), anuncio(anuncio),
		montanteNegociado(montanteNegociado), mensagem(mensagem){}

NegocioConcretizado::~NegocioConcretizado() {
}

Data NegocioConcretizado::getDataNegociada() const{
	return dataNegociada;
}

Utilizador* NegocioConcretizado::getAnunciante() const{
	return anunciante;
}

Utilizador* NegocioConcretizado::getPessoaInteressada() const{
	return pessoaInt;
}

Anuncio* NegocioConcretizado::getAnuncio() const{
	return anuncio;
}

float NegocioConcretizado::getMontanteNegociado() const{
	return montanteNegociado;
}

string NegocioConcretizado::getMensagem() const{
	return mensagem;
}

/**
 * @brief set pointer to advertiser to NULL
 */
void NegocioConcretizado::setAnunciantePtr_toNull(){
	anunciante = NULL;
}

/**
 * @brief set pointer to interested person to NULL
 */
void NegocioConcretizado::setPessoaInteressadaPtr_toNull(){
	pessoaInt = NULL;
}
