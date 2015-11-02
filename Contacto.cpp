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
 * @param pointer to anuncio
 * @param message to send to anunciante
 * @param numTel_pessoaInt to send to anunciante
 */
Contacto::Contacto(Utilizador* anunciante,Utilizador* pessoaInt,
		Anuncio* anuncio, string mensagem, string numTel_pessoaInt)
:anunciante(anunciante),
 pessoaInt(pessoaInt),
 mensagem(mensagem),
 numTel_pessoaInt(numTel_pessoaInt)
{
	concretizado = false;
	montanteNegociado = 0;
	dataNegociada = Data(0,0,0);
}

/**
 * @brief class contacto destructor
 */
Contacto::~Contacto() {}
