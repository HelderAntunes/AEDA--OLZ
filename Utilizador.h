
#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include <iostream>
#include "Localizacao.h"
#include "Anuncio.h"

using namespace std;

class Utilizador {
	string nome;
	string email;
	string contacto;
	Localizacao localizacao;
	//vector<Anuncio *> anuncios;

public:


	Utilizador(string nome, string email, string contacto, Localizacao localizacao);
	Utilizador(string nome, string email, string contacto, string freguesia, string concelho, string distrito);
	virtual ~Utilizador();
	string getNome() const;
	string getEmail() const;
	string getContacto() const;
	Localizacao getLocalizacao() const;
};

class Utilizadores {
	vector<Utilizador> utilizadores;
public:
	void addUtilizador(const Utilizador & u);
	bool delUtilizador(const string & email);
	Utilizador * getUtilizador(const string & email);
	void ordena_clientes_nome();
	void ordena_clientes_email();
	void ordena_clientes_contacto();
	void ordena_clientes_localizacao();
	vector<Utilizador> getUtilizadores() const;
	friend ostream & operator<<(ostream & os, const Utilizadores & utilizadores);
};

class ExceptionEmailJaExistente {

	Utilizador utilizador;
public:
	ExceptionEmailJaExistente(Utilizador u);
	string getEmail() const;
	Utilizador & getUtilizador() const;
};

class ExceptionContactoJaExistente {
	Utilizador utilizador;
public:
	ExceptionContactoJaExistente(Utilizador u);
	string getContacto() const;
	Utilizador & getUtilizador() const;
};

#endif /* UTILIZADOR_H_ */
