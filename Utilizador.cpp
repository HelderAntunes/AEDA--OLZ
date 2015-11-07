//TODO Add ExceptionEmailMalFormado

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Localizacao.h"
#include "Anuncio.h"


Utilizador::Utilizador(string nome, string email, string contacto, Localizacao localizacao):
	nome(nome),
	email(email),
	contacto(contacto),
	localizacao(localizacao)
{
	// Empty Block
}

Utilizador::Utilizador(string nome, string email, string contacto, string freguesia, string concelho, string distrito):
		nome(nome),
		email(email),
		contacto(contacto),
		localizacao(Localizacao(freguesia, concelho, distrito))
{
	// Empty Block
}

string Utilizador::getNome() const
{
	return nome;
}

string Utilizador::getEmail() const
{
	return email;
}

string Utilizador::getContacto() const
{
	return contacto;
}

Localizacao Utilizador::getLocalizacao() const
{
	return localizacao;
}

void Utilizador::setNome(const string & nome)
{
	this->nome = nome;
}

void Utilizador::setEmail(const string & email)
{
	this->email = email;
}

void Utilizador::setContacto(const string & contacto)
{
	this->email = email;
}

void Utilizador::setLocalizacao(const Localizacao & localizacao)
{
	this->localizacao = localizacao;
}

ostream & operator<<(ostream & os, const Utilizador & utilizador)
{
	os << "Nome: " << utilizador.getNome() << endl;
	os << "Email: " << utilizador.getEmail() << endl;
	os << "Contacto: " << utilizador.getContacto()<< endl;
	os << "Localizacao: " << utilizador.getLocalizacao()<< endl;
	return os;
}

void Utilizador::imprime(){
	cout << "Nome: " << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Contacto: " << contacto << endl;
	cout << "Localizacao: " << localizacao << endl;
}
