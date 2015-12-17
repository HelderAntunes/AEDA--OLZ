/*
 * Contacto.h
 * Author: Helder Antunes
 */

#ifndef SRC_CONTACTO_H_
#define SRC_CONTACTO_H_

#include "Anuncio.h"
#include <string>
#include <iostream>



/**@class Contacto
 * @brief contact between two persons
 */
class Contacto {
private:
	Utilizador* anunciante;    /**< pointer to advertiser */
	Utilizador* pessoaInt;    /**< pointer to interested person */
	Anuncio* anuncio;		/**< pointer to add */
	string mensagem;    /**< message of interested person to advertiser */
	string numTel_pessoaInt;  /**< phone number of interested person */
public:
	Contacto(Utilizador* anunciante,Utilizador* pessoaInt,Anuncio* anuncio,
			string mensagem, string numTel_pessoaInt);
	void setAnuncioPtr_toNull();
	Anuncio* getAnuncio() const;
	Utilizador* getAnunciante() const;
	Utilizador* getPessoaInteressada() const;
	string getMensagem()const;
	string getNumTel_PessoaInt();
	void setAnunciantePtr_toNull();
	void setPessoaInteressadaPtr_toNull();
	void concretizaNegocio(float montanteNegociado, Data data);
	void imprimeContacto();
	virtual ~Contacto();
};


#endif /* SRC_CONTACTO_H_ */
