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
	 * @param dataNegociada date of transaction
	 * @param anunciante pointer to anunciante
	 * @param pessoaInt pointer to interested person
	 * @param descricaoAnuncio description of ad
	 * @param montanteNegociado price agreed
	 * @param mensagem message sent by interested person
	 * @param categoria category of ad
	 */
	NegocioConcretizado(Data dataNegociada, Utilizador* anunciante, Utilizador* pessoaInt, string descricaoAnuncio,
						float montanteNegociado, string mensagem, string categoria);
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

	/**
	 * @brief save information of concretized business on a file
	 *
	 * @param out ostream where is sent information
	 * @param nc concretized business that is to save on a file
	 *
	 * @return out ostream with information saved
	 */
	friend ostream &operator<<(ostream &out,const NegocioConcretizado& nc);

};

#endif /* NEGOCIOCONCRETIZADO_H_ */
