/*
 * Contacto.cpp
 *
 *  Created on: 16/10/2015
 *      Author: Hélder Antunes
 */

#include "Contacto.h"


/*
 * Membros função de Contacto
 */

Contacto::Contacto(Utilizador* anuciante, Utilizador* pessoaInt):
	anuciante(anuciante), pessoaInt(pessoaInt){}

Contacto::~Contacto() {
	delete anuciante;
	delete pessoaInt;
}


/*
 * Membros função de Contacto_size
 */

Contacto_site::Contacto_site(Utilizador* anuciante,Utilizador* pessoaInt,std::string msg, int numTel_pessoaInt)
: Contacto(anuciante,pessoaInt){
	this->msg = msg;
	this->numTel_pessoaInt = numTel_pessoaInt;
}


std::string Contacto_site::get_msg() const{
	return msg;
}

int Contacto_site::get_numTel_pessoaInt() const{
	return numTel_pessoaInt;
}


