#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include <iostream>
#include "Localizacao.h"
#include "Data.h"

using namespace std;



/**@class Utilizador
 * @brief Utilizador class
 */
class Utilizador {
	string nome;	            /**< name of user*/
	string email;	            /**< email of user*/
	string contacto;			/**< phone number of user*/
	Localizacao localizacao;	/**< localization of user*/
    int negociosConcretizados;  /**< number of achieved trade*/
    Data dataUltimoNegocio;        /**< date of last trade*/
public:
	Utilizador(string nome, string email, string contacto, Localizacao localizacao);
	Utilizador(string nome, string email, string contacto, string freguesia, string concelho, string distrito);
	virtual ~Utilizador(){}
	string getNome() const;
	string getEmail() const;
	string getContacto() const;
	Localizacao getLocalizacao() const;
	int getNegociosConcretizados() const;
	Data getDataUltimoNegocio() const;
	void setNome(const string & nome);
	void setEmail(const string & email);
	void setContacto(const string & contacto);
	void setLocalizacao(const Localizacao & localizacao);
	friend ostream & operator<<(ostream & os, const Utilizador & utilizador);
	void imprime();
	void incNegociosConcretizados();
	void updateDataUltimoNegocio(Data novaData);

	bool operator==(const Utilizador& u) const;
	bool operator< (const Utilizador& right) const;
};

/**@class ExceptionEmailJaExistente
 * @brief a exception class
 */
class ExceptionEmailJaExistente {
	string email;		/**< existing email*/
public:
	/**
	 * @brief constructor of ExceptionEmailJaExistente
	 */
	ExceptionEmailJaExistente(string email){
		this->email = email;
	}
	/**
	 * @brief get existing email
	 */
	string getEmail() const{
		return email;
	}

};

/**@class ExceptionUtilizadorNaoExistente
 * @brief a exception class
 */
class ExceptionUtilizadorNaoExistente{
	string email;	/**< nonexistent email*/
public:
	/**
	 * @brief constructor of ExceptionUtilizadorNaoExistente
	 */
	ExceptionUtilizadorNaoExistente(string email){
		this->email = email;
	}
	/**
	 * @brief get nonexistent email
	 */
	string getEmail() const{
		return email;
	}
};

#endif /* UTILIZADOR_H_ */
