#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Localizacao.h"
#include "Anuncio.h"

/**
 * @brief constructor of class Utilizador
 *
 * @param nome 			
 * @param email 		
 * @param contacto 		
 * @param localizacao	
 */
Utilizador::Utilizador(string nome, string email, string contacto, Localizacao localizacao):
	nome(nome),
	email(email),
	contacto(contacto),
	localizacao(localizacao)
{
	// Empty Block
}

/**
 * @brief constructor of class Utilizador
 *
 * @param nome 			
 * @param email 		
 * @param contacto 		
 * @param freguesia		
 * @param concelho
 * @param distrito		
 */
Utilizador::Utilizador(string nome, string email, string contacto, string freguesia, string concelho, string distrito):
		nome(nome),
		email(email),
		contacto(contacto),
		localizacao(Localizacao(freguesia, concelho, distrito))
{
	// Empty Block
}

/**
 * @brief get name of user
 *
 * @return nome
 */
string Utilizador::getNome() const
{
	return nome;
}

/**
 * @brief get email of user
 *
 * @return email
 */
string Utilizador::getEmail() const
{
	return email;
}

/**
 * @brief get phone number of user
 *
 * @return contacto
 */
string Utilizador::getContacto() const
{
	return contacto;
}

/**
 * @brief get localization of user
 *
 * @return localizacao		localization of user
 */
Localizacao Utilizador::getLocalizacao() const
{
	return localizacao;
}

/**
 * @brief set name of user
 *
 * @param nome 		name of user
 */
void Utilizador::setNome(const string & nome)
{
	this->nome = nome;
}

/**
 * @brief set email of user
 *
 * @param email		email of user
 */
void Utilizador::setEmail(const string & email)
{
	this->email = email;
}

/**
 * @brief set phone number of user
 *
 * @param contacto	phone number of user
 */
void Utilizador::setContacto(const string & contacto)
{
	this->email = email;
}

/**
 * @brief set localization of user
 *
 * @param localizacao	localization of user
 */
void Utilizador::setLocalizacao(const Localizacao & localizacao)
{
	this->localizacao = localizacao;
}

//operator <<
ostream & operator<<(ostream & os, const Utilizador & utilizador)
{
	os << "Nome: " << utilizador.getNome() << endl;
	os << "Email: " << utilizador.getEmail() << endl;
	os << "Contacto: " << utilizador.getContacto()<< endl;
	os << "Localizacao: " << utilizador.getLocalizacao()<< endl;
	return os;
}

/**
 * @brief print information of user in console
 */
void Utilizador::imprime(){
	cout << "Nome: " << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Contacto: " << contacto << endl;
	cout << "Localizacao: " << localizacao << endl;
}
