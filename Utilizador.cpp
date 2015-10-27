
#include "Utilizador.h"
#include <algorithm>

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



bool Utilizadores::addUtilizador(const Utilizador & u)
{
	if (getUtilizador(u.getEmail()) == NULL)
		return false;

	utilizadores.push_back(u);
	return true;
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

bool ordena_nome(const Utilizador & u1, const Utilizador & u2) const
{
	return u1.getNome() < u2.getNome();
}

bool ordena_email(const Utilizador & u1, const Utilizador & u2) const
{
	return u1.getEmail() < u2.getEmail();
}

bool ordena_contacto(const Utilizador & u1, const Utilizador & u2) const
{
	return u1.getContacto() < u2.getContacto();
}

bool ordena_localizacao(const Utilizador & u1, const Utilizador & u2) const
{
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
