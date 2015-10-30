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
 */
Contacto::Contacto(Utilizador* anuciante, Utilizador* pessoaInt):
	anuciante(anuciante), pessoaInt(pessoaInt){}


/**
 * @brief class contacto destructor
 */
Contacto::~Contacto() {}



/******************************
 * Functions of class Contacto*
 ******************************/



/**
 * @brief class Contacto_site constructor
 *
 * @param pointer to advertiser
 * @param pointer to interested person
 * @param message to send
 * @param phone number of interested person
 */
Contacto_site::Contacto_site(Utilizador* anuciante,Utilizador* pessoaInt,std::string msg, int numTel_pessoaInt)
: Contacto(anuciante,pessoaInt){
	this->msg = msg;
	this->numTel_pessoaInt = numTel_pessoaInt;
}



/**
 * @brief get message to send
 * @return message to send
 */
std::string Contacto_site::get_msg() const{
	return msg;
}


/**
 * @brief get phone number of interested person
 * @return phone number of interested person
 */
int Contacto_site::get_numTel_pessoaInt() const{
	return numTel_pessoaInt;
}


