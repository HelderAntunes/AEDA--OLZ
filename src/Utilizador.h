
#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include <iostream>
#include "Localizacao.h"

using namespace std;

class Utilizador {
	string nome;
	string email;
	string contacto;
	Localizacao localizacao;

public:
	Utilizador(string nome, string email, string contacto, Localizacao localizacao);
	Utilizador(string nome, string email, string contacto, string freguesia, string concelho, string distrito);
	virtual ~Utilizador(){}
	string getNome() const;
	string getEmail() const;
	string getContacto() const;
	Localizacao getLocalizacao() const;
	void setNome(const string & nome);
	void setEmail(const string & email);
	void setContacto(const string & contacto);
	void setLocalizacao(const Localizacao & localizacao);
	friend ostream & operator<<(ostream & os, const Utilizador & utilizador);
	void imprime();
};

class Utilizadores {
	vector<Utilizador> utilizadores;
public:
	void addUtilizador(const Utilizador * u);
	bool delUtilizador(const string & email);
	Utilizador * getUtilizador(const string & email);
	void ordena_clientes_nome();
	void ordena_clientes_email();
	void ordena_clientes_contacto();
	void ordena_clientes_localizacao();
	vector<Utilizador> getUtilizadores() const;
	void setUtilizadorNome(Utilizador * u, const string & nome);
	void setUtilizadorEmail(Utilizador * u, const string & email);
	void setUtilizadorContacto(Utilizador * u, const string & contacto);
	void setUtilizadorLocalizacao(Utilizador * u, const Localizacao & localizacao);
};

class ExceptionEmailJaExistente {

	const Utilizador * utilizador;
public:
	ExceptionEmailJaExistente(const Utilizador * u);
	string getEmail() const;
	const Utilizador * getUtilizador() const;
};

class ExceptionContactoJaExistente {
	const Utilizador * utilizador;
public:
	ExceptionContactoJaExistente(const Utilizador * u);
	string getContacto() const;
	const Utilizador * getUtilizador() const;
};

class ExceptionUtilizadorNaoExistente{
	string email;
public:
	ExceptionUtilizadorNaoExistente(string email){
		this->email = email;
	}
	string getEmail() const{
		return email;
	}
};

#endif /* UTILIZADOR_H_ */
