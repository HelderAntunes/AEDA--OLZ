/*
 * Utilizador.h
 *
 *  Created on: 25/10/2015
 *      Author: filip
 */

#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>

using namespace std;

class Utilizador {
	string nome;
	string email;
	string contacto;
	Localizacao localizacao;

public:
	Utilizador(string nome, string email, string contacto, Localizacao localizacao);
	virtual ~Utilizador();
	string getNome() const;
	string getEmail() const;
	string contacto() const;
	Localizacao localizacao() const;
};

class Utilizadores {
	vector<Utilizador> utilizadores;
public:
	void addUtilizador(const Utilizador & u);
	void delUtilizador(const int index);
	Utilizador getUtilizadorByIndex(const int index);
	Utilizador getUtilizadorByEmail(const string & email);
	int getUtilizadorIndex(const Utilizador & u);
	void ordena_clientes_nome();
	void ordena_clientes_email;
	void ordena_clientes_contacto;
	//void ordena_clientes_localizacao;
};

#endif /* UTILIZADOR_H_ */
