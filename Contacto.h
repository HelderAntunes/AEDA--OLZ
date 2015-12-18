/*
 * Contacto.h
 * Author: Helder Antunes
 */

#ifndef SRC_CONTACTO_H_
#define SRC_CONTACTO_H_

#include "Anuncio.h"
#include "NegocioConcretizado.h"
#include <string>
#include <iostream>



/**@class Contacto
 * @brief contact between two persons
 */
class Contacto {
protected:
	Utilizador* anunciante;    /**< pointer to advertiser */
	Utilizador* pessoaInt;    /**< pointer to interested person */
	Anuncio* anuncio;		/**< pointer to add */
	string mensagem;    /**< message of interested person to advertiser */
	string numTel_pessoaInt;  /**< phone number of interested person */
public:
	/**
	 * @brief class Contacto constructor
	 *
	 * @param pointer to anunciante
	 * @param pointer to interested person
	 * @param pointer to anuncio
	 * @param message to send to anunciante
	 * @param numTel_pessoaInt to send to anunciante
	 */
	Contacto(Utilizador* anunciante,Utilizador* pessoaInt,Anuncio* anuncio,
			string mensagem, string numTel_pessoaInt);
	/**
	 * @brief set add pointer to null
	 */
	void setAnuncioPtr_toNull();
	/**
	 * @brief get pointer to add
	 * @return Anuncio* anuncio
	 */
	Anuncio* getAnuncio() const;
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
	 * @brief get message between two users
	 *
	 * @return message
	 */
	string getMensagem()const;
	/**
	 * @brief get phone number of interested person
	 *
	 * return numTel_pessoaInt
	 */
	string getNumTel_PessoaInt();
	/**
	 * @brief set pointer to advertiser to NULL
	 */
	void setAnunciantePtr_toNull();
	/**
	 * @brief set pointer to interested person to NULL
	 */
	void setPessoaInteressadaPtr_toNull();
	/**
	 * @brief concretize the trade
	 * @param int montanteNegociado
	 * @param Data data of negotiation
	 */
	NegocioConcretizado* concretizaNegocio(float montanteNegociado, Data data);
	/**
	 * @brief print the contact
	 */
	void imprimeContacto();
	/**
	 * @brief class contacto destructor
	 */
	virtual ~Contacto();
	friend ostream &operator<<(ostream &out, Contacto c);
};


#endif /* SRC_CONTACTO_H_ */
