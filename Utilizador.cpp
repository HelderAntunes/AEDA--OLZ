//TODO Add ExceptionEmailMalFormado
//TODO Add visible members to other Utilizadores

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Localizacao.h"
#include "Anuncio.h"

ExceptionEmailJaExistente::ExceptionEmailJaExistente(Utilizador * u):
		utilizador(u)
{
	// Empty Block
}

Utilizador & ExceptionEmailJaExistente::getUtilizador() const
{
	return utilizador;
}

string ExceptionEmailJaExistente::getEmail() const
{
	return utilizador->getEmail();
}



ExceptionContactoJaExistente::ExceptionContactoJaExistente(Utilizador * u):
		utilizador(u)
{
	// Empty Block
}

Utilizador & ExceptionContactoJaExistente::getUtilizador() const
{
	return utilizador;
}

string ExceptionContactoJaExistente::getContacto() const
{
	return utilizador->getContacto();
}



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



void Utilizadores::addUtilizador(const Utilizador & u)
{
	for (vector<Utilizador>::iterator it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if (it->getEmail() == u.getEmail())
		{
			Utilizador * ptr = u;
			ExceptionEmailJaExistente e(ptr);
			throw e;
		}
		if (it->getContacto() == u.getContacto())
		{
			Utilizador * ptr = u;
			ExceptionContactoJaExistente e(ptr);
			throw e;
		}
	}

	utilizadores.push_back(u);
}

bool Utilizadores::delUtilizador(const string & email)
{
	for (vector<Utilizador>::iterator it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if ((*it).getEmail() == email)
		{
			utilizadores.erase(it);
			return true;
		}
	}
	return false;
}

bool ordena_nome(const Utilizador & u1, const Utilizador & u2)
{
	if (u1.getNome() == u2.getNome())
	{
		//return ordena_email(u1, u2);
	}
	return u1.getNome() < u2.getNome();
}

bool ordena_email(const Utilizador & u1, const Utilizador & u2)
{
	return u1.getEmail() < u2.getEmail();
}

bool ordena_contacto(const Utilizador & u1, const Utilizador & u2)
{
	return u1.getContacto() < u2.getContacto();
}

bool ordena_localizacao(const Utilizador & u1, const Utilizador & u2)
{
	if (u1.getLocalizacao() == u2.getLocalizacao())
	{
		return ordena_nome(u1, u2);
	}
	return u1.getLocalizacao() < u2.getLocalizacao();
}

void Utilizadores::ordena_clientes_nome()
{
	sort(utilizadores.begin(), utilizadores.end(), ordena_nome);
}

void Utilizadores::ordena_clientes_email()
{
	sort(utilizadores.begin(), utilizadores.end(), ordena_email);
}

void Utilizadores::ordena_clientes_contacto()
{
	sort(utilizadores.begin(), utilizadores.end(), ordena_contacto);
}

void Utilizadores::ordena_clientes_localizacao()
{
	sort(utilizadores.begin(), utilizadores.end(), ordena_localizacao);
}

vector<Utilizador> Utilizadores::getUtilizadores() const
{
	return utilizadores;
}

void Utilizadores::setUtilizadorNome(Utilizador * u, const string & nome)
{
	u->setNome(nome);
}

void Utilizadores::setUtilizadorEmail(Utilizador * u, const string & email)
{
	for (vector<Utilizador>::iterator it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if (it->getEmail() == u->getEmail())
		{
			ExceptionEmailJaExistente e(u);
			throw e;
		}
	}

	u->setEmail(email);
}

void Utilizadores::setUtilizadorContacto(Utilizador * u, const string & contacto)
{
	for (vector<Utilizador>::iterator it = utilizadores.begin(); it != utilizadores.end(); it++)
	{
		if (it->getContacto() == u->getContacto())
		{
			ExceptionContactoJaExistente e(u);
			throw e;
		}
	}

	u->setContacto(contacto);
}

void Utilizadores::setUtilizadorLocalizacao(Utilizador * u, const Localizacao & localizacao)
{
	u->setLocalizacao(localizacao);
}

ostream & operator<<(ostream & os, const Utilizadores & utilizadores)
{
	vector<Utilizador> u = utilizadores.getUtilizadores();

	os << "Nome\t\tEmail\t\tContacto\\Localizacao" << endl;
	for (vector<Utilizador>::const_iterator it = u.begin(); it != u.end(); it++)
	{
		os << it->getNome() << it->getEmail() << it->getContacto() << it->getLocalizacao() << endl;
	}

	return os;
}

ostream & operator<<(ostream & os, const Utilizador & utilizador)
{
	os << "Nome: " << utilizador.getNome() << endl;
	os << "Email: " << utilizador.getEmail() << endl;
	os << "Contacto: " << utilizador.getContacto() << endl;
	os << "Localização: " << utilizador.getLocalizacao() << endl;
}
