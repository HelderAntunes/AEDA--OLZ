
#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include "Localizacao.h"
#include "Anuncio.h"

using namespace std;

class Utilizador {
	string nome;
	string email;
	string contacto;
	Localizacao localizacao;
	vector<Anuncio> anuncios;

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
	bool addUtilizador(const Utilizador & u);
	bool delUtilizador(const string & email);
	Utilizador * getUtilizador(const string & email);
	void ordena_clientes_nome();
	void ordena_clientes_email();
	void ordena_clientes_contacto();
	void ordena_clientes_localizacao();
};

#endif /* UTILIZADOR_H_ */
