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
	Anuncio* anuncio;
	string mensagem;
	string numTel_pessoaInt;
	bool concretizado;
	int montanteNegociado;
	Data dataNegociada;
public:
	Contacto(Utilizador* anunciante,Utilizador* pessoaInt,Anuncio* anuncio,
			string mensagem, string numTel_pessoaInt);
	void setAnuncioPtr(Anuncio* anuncio);
	Anuncio* getAnuncioPtr();
	Utilizador* getAnunciante();
	Utilizador* getPessoaInteressada();
	void setAnunciantePtr_toNull();
	void setPessoaInteressadaPtr_toNull();
	bool negocioEstaConcretizado();
	void imprimeContacto();
	void imprimeNegocioConcretizado();
	virtual ~Contacto();
};


#endif /* SRC_CONTACTO_H_ */
