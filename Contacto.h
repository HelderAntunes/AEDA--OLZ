/*
 * Contacto.h
 * Author: Helder Antunes
 */

#ifndef SRC_CONTACTO_H_
#define SRC_CONTACTO_H_

#include "Utilizador.h"
#include <string>
#include <iostream>



/**@class Contacto
 * @brief contact between two persons
 */
class Contacto {
private:
	Utilizador* anuciante;    /**< pointer to advertiser */
	Utilizador* pessoaInt;    /**< pointer to interested person */

public:
	Contacto(Utilizador* anuciante,Utilizador* pessoaInt);
	virtual ~Contacto();
};




/**@class Contacto_site
 * @brief contact between two persons mediated by site
 */
class Contacto_site: public Contacto{
private:
	std::string msg;         /**< message to send */
	int numTel_pessoaInt;    /**< phone number of interested person */

public:
	Contacto_site(Utilizador* anuciante,Utilizador* pessoaInt,std::string msg,int numTel_pessoaInt);
	virtual ~Contacto_site(){}
	std::string get_msg() const;
	int get_numTel_pessoaInt() const;
};



#endif /* SRC_CONTACTO_H_ */
