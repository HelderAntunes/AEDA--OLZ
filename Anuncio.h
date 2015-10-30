/**
 * @file Anuncio.h
 *
 * @brief Header file for class Anuncio*/


#ifndef SRC_ANUNCIO_H_
#define SRC_ANUNCIO_H_

#include <string>
#include <ctime>
#include <iostream>
#include "Data.h"
#include "Utilizador.h"

using namespace std;

enum Estado {NOVO,USADO, FUNCIONAL, PECAS};

class Utilizador;

/**@class Anuncio
 * @brief Advertisement class
 */
class Anuncio{
	static int identificador;
protected:
	string titulo;			/**< advertisement's title */
	string cat;				/**< advertisement's category */
	string descricao;		/**< advertisement's description */
	vector<string> imagens;	/**< vector of name of image files used*/
	int id;					/**< advertisement's id */
	Data data;				/**< advertisement's date of creation */
	int visualizacoes;		/**< advertisement's number of views */
	Utilizador *anunciante;	/**< pointer to the advertiser */
public:
	Anuncio(string titulo, string categoria, string descricao,vector<string> imagens, Data data, Utilizador* anunciante);
	virtual ~Anuncio();
	string getTitulo();
	string getCategoria();
	int getId();
	Data getData();
	int getVisualizacoes();
	void incVisualizacoes();
	bool procuraPalavraChave(string palavra);
	/**
	 * Function displays advertisement on screen
	 * @brief display ad.
	 */
	virtual void imprime() const {}
};

/**@class DeVenda
 * @brief Sale Advertisement class derived from Anuncio
 */
class DeVenda: public Anuncio{
	Estado estado;				/**< advertised object's condition */
	float preco;				/**< advertised object's demanded price */
	bool negociacao;			/**< boolean indicating whether advertiser is willing to negotiate */
public:
	DeVenda(string titulo, string categoria, string descricao,vector<string> imagens, Estado estado, float preco,bool negociacao, Data data, Utilizador* anunciante);
	Estado getEstado();
	float getPreco();
	void setPreco(float preco);
	void imprime() const ;
};

/**@class DeCompra
 * @brief Purchase Advertisement class derived from Anuncio
 */
class DeCompra: public Anuncio{
	DeVenda* troca;				/**< pointer to an sale advertisement alerting for the possibility of an exchange */
public:
	DeCompra(string titulo, string categoria, string descricao, vector<string> imagens, DeVenda* ptr,Data data, Utilizador* anunciante);
	DeCompra(string titulo, string categoria, string descricao, vector<string> imagens,Data data, Utilizador* anunciante);
	void imprime() const ;
};


#endif /* SRC_ANUNCIO_H_ */
