
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

class ExceptionEmailJaExistente {
	string email;
public:
	ExceptionEmailJaExistente(string email){
		this->email = email;
	}
	string getEmail() const{
		return email;
	}

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
