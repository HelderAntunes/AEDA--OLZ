#ifndef SRC_ANUNCIO_H_
#define SRC_ANUNCIO_H_

/**
 * @file Anuncio.h
 *
 * @brief Header file for class Anuncio*/

#include <string>
#include <ctime>
#include <iostream>
#include "Data.h"
#include "Utilizador.h"

using namespace std;

enum Estado {NOVO,USADO, FUNCIONAL, PECAS};

/**@class Anuncio
 * @brief Advertisement class
 */
class Anuncio{
	static int identificador; /**< id for the next advertisement created (ensures no 2 advertisements have the same id)*/
protected:
	string titulo;			/**< advertisement's title */
	string cat;				/**< advertisement's category */
	string descricao;		/**< advertisement's description */
	vector<string> imagens;	/**< vector of name of image files used*/
	int id;					/**< advertisement's id */
	Data data;				/**< advertisement's date of creation */
	int visualizacoes;		/**< advertisement's number of views */
	Utilizador *anunciante;	/**< pointer to the advertiser */
	bool showEmail;			/**< advertiser wishes to make email public*/
	bool showNome;			/**< advertiser wishes to make name public*/
	bool showNumTel;		/**< advertiser wishes to make phone number public*/
	bool temDestaque;
public:
	Anuncio(string titulo, string categoria, string descricao,
			vector<string> imagens,int id, Data data, Utilizador* anunciante,
			int visualizacoes, bool showEmail, bool showNome,	bool showNumTel);
	virtual ~Anuncio();
	string getTitulo();
	string getCategoria();
	int getId();
	Data getData() const;
	int getVisualizacoes();
	Utilizador* getAnunciante();
	vector<string> getImagens();
	string getDescricao();
	bool getShowEmail();
	bool getShowNome();
	bool getShowNumTel();
	bool anuncioTemDestaque() const;
	void setShowEmail(bool showEmail);
	void setShowNome(bool showNome);
	void setShowNumTel(bool showNumTel);
	void incVisualizacoes();
	bool procuraPalavraChave(string palavra);
	void setAnunciantePtr(Utilizador* anunciantePtr);
	static void setIdentificadorInicial(int static_id_anuncio_inicial);
	static int getIdentificadorInicial();
	void colocarDestaque();
	void retirarDestaque();
	/**
	 * Function displays advertisement on screen
	 * @brief display ad.
	 */
	virtual void imprime() const {}
	bool operator<(const Anuncio &right);
	//friend ostream &operator<<(ostream &out, Anuncio a);
	//friend istream &operator>>(istream &in, Anuncio &a);
};

/**@class DeVenda
 * @brief Sale Advertisement class derived from Anuncio
 */
class DeVenda: public Anuncio{
protected:
	Estado estado;				/**< advertised object's condition */
	float preco;				/**< advertised object's demanded price */
	bool negociacao;			/**< boolean indicating whether advertiser is willing to negotiate */
public:
	DeVenda(string titulo, string categoria, string descricao,vector<string> imagens, int id,
			Estado estado, float preco,bool negociacao, Data data, Utilizador* anunciante,
			int visualizacoes, bool showEmail, bool showNome,	bool showNumTel);
	Estado getEstado();
	float getPreco();
	bool getNegociacao();
	void setPreco(float preco);
	void imprime() const ;
	friend ostream &operator<<(ostream &out, DeVenda a);
	friend istream &operator>>(istream &in, DeVenda &a);
};

/**@class DeCompra
 * @brief Purchase Advertisement class derived from Anuncio
 */
class DeCompra: public Anuncio{
protected:
	bool troca;					/**< advertiser is open to the possibility of an exchange of items*/
	int trocaId;				/**< id of sale ad possible for exchange */
public:
	DeCompra(string titulo, string categoria, string descricao, vector<string> imagens, int id,
			bool troca, int trocaId, Data data, Utilizador* anunciante, int visualizacoes,
			bool showEmail, bool showNome, bool showNumTel);
	void imprime() const ;
	friend ostream &operator<<(ostream &out, DeCompra a);
	friend istream &operator>>(istream &in, DeCompra &a);
	bool getTroca();
	int getTrocaId();
};

#endif /* SRC_ANUNCIO_H_ */
