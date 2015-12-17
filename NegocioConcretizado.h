/*
 * NegocioConcretizado.h
 *
 *  Created on: 16/12/2015
 *      Author: Helder Antunes
 */

#ifndef NEGOCIOCONCRETIZADO_H_
#define NEGOCIOCONCRETIZADO_H_

#include "Utilizador.h"
#include "Anuncio.h"

class NegocioConcretizado {
private:
	Data dataNegociada;   /** data of negotiation */
	Utilizador* anunciante;    /**< pointer to advertiser */
	Utilizador* pessoaInt;    /**< pointer to interested person */
	Anuncio* anuncio;		/**< pointer to add */
	float montanteNegociado;  /** money negotiated */
	string mensagem;    /**< message of interested person to advertiser */

public:
	NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt, Anuncio* anuncio, float montanteNegociado, string mensagem);
	virtual ~NegocioConcretizado();
	Data getDataNegociada() const;
	Utilizador* getAnunciante() const;
	Utilizador* getPessoaInteressada() const;
	Anuncio* getAnuncio() const;
	float getMontanteNegociado() const;
	string getMensagem() const;
	void setAnunciantePtr_toNull();
	void setPessoaInteressadaPtr_toNull();
};

#endif /* NEGOCIOCONCRETIZADO_H_ */
