/*
 * Contacto.h
 *
 *  Created on: 16/10/2015
 *      Author: Hélder Antunes
 */

#ifndef SRC_CONTACTO_H_
#define SRC_CONTACTO_H_

#include "Utilizador.h"
#include <string>

class Contacto {
private:
	Utilizador* anuciante;
	Utilizador* pessoaInt;
public:
	Contacto(Utilizador* anuciante,Utilizador* pessoaInt);
	virtual ~Contacto();
};

class Contacto_site: public Contacto{
private:
	std::string msg;
	int numTel_pessoaInt;
public:
	Contacto_site(Utilizador* anuciante,Utilizador* pessoaInt,std::string msg,int numTel_pessoaInt);
	virtual ~Contacto_site(){}
	std::string get_msg() const;
	int get_numTel_pessoaInt() const;
};

#endif /* SRC_CONTACTO_H_ */
