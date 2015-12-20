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
protected:
	Data dataNegociada;			/** data of negotiation */
	Utilizador* anunciante;		/**< pointer to advertiser */
	Utilizador* pessoaInt;		/**< pointer to interested person */
	string categoria;			/**< ad's category */
	string descricaoAnuncio;	/**< description of ad */
	float montanteNegociado;	/** money negotiated */
	string mensagem;			/**< message of interested person to advertiser */

public:
	/**
	 * @brief class NegocioConcretizado constructor
	 *
	 * @param date of transaction
	 * @param pointer to anunciante
	 * @param pointer to interested person
	 * @param pointer to anuncio
	 * @param message to send to anunciante
	 * @param price agreed
	 * @param numTel_pessoaInt to send to anunciante
	 */
	NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt, Anuncio* anuncio, float montanteNegociado, string mensagem);
	/**
	 * @brief class NegocioConcretizado destructor
	 */
	virtual ~NegocioConcretizado();
	/**
	 * @brief get date of transaction
	 * @return Data date of transaction
	 */
	Data getDataNegociada() const;
	/**
	 * @brief get pointer to advertiser
	 * @return Utilizador* anunciante
	 */
	Utilizador* getAnunciante() const;
	/**
	 * @brief get pointer to interested person
	 * @return Utilizador* pessoaInt
	 */
	Utilizador* getPessoaInteressada() const;
	/**
	 * @brief get ad category
	 *
	 * return ad category
	 */
	string getCategoria() const;
	/**
	 * @brief get ad description
	 *
	 * return ad description
	 */
	string getDescricao() const;
	/**
	 * @brief get agreed price
	 *
	 * @return price agreed
	 */
	float getMontanteNegociado() const;
	/**
	 * @brief get message between two users
	 *
	 * @return message
	 */
	string getMensagem() const;
	/**
	 * @brief set pointer to advertiser to NULL
	 */
	void setAnunciantePtr_toNull();
	/**
	 * @brief set pointer to interested person to NULL
	 */
	void setPessoaInteressadaPtr_toNull();
	/**
	 * @brief print transaction
	 */
	void imprimeNegocioConcretizado();
	friend ostream &operator<<(ostream &out, NegocioConcretizado nc);
};

#endif /* NEGOCIOCONCRETIZADO_H_ */
