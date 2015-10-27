/**
 * @file Anuncio.h
 *
 * @brief Header file for class Anuncio*/


#ifndef SRC_ANUNCIO_H_
#define SRC_ANUNCIO_H_

#include <string>
#include <ctime>
#include "Data.h"
#include "Utilizador.h"

using namespace std;

/**@class Categoria
 * @brief category class
 * This class helps make the categories finite and uniform
 */
class Categoria{
	string cat;					/**< category name */
	Categoria* subCategoria;	/**< pointer to subcategory */
public:
	/**
	 * @brief class Categoria constructor.
	 * Creates new category without subcategories
	 *
	 * @param nome category's name
	 */
	Categoria(string nome){
		cat = nome;
		subCategoria = NULL;
	}
	/**
	 * @brief class Categoria constructor.
	 * Creates new category with subcategories
	 *
	 * @param nome category's name
	 * @param catPtr pointer to subcategory
	 */
	Categoria(string nome, Categoria* catPtr){
		this->cat = nome;
		this->subCategoria = catPtr;
	}
	/**
	 * @brief get category's name.
	 *
	 * @return category's name
	 */
	string getCat(){return cat;}
};

enum Estado {NOVO,USADO, FUNCIONAL, PECAS};

/**@class Anuncio
 * @brief Advertisement class
 */
class Anuncio{
	static int identificador;
protected:
	string titulo;			/**< advertisement's title */
	Categoria cat;			/**< advertisement's category */
	string descricao;		/**< advertisement's description */
	//imagens
	int id;					/**< advertisement's id */
	Data data;				/**< advertisement's date of creation */
	int visualizacoes;		/**< advertisement's number of views */
	Utilizador* anunciante;	/**< pointer to the advertiser */
public:
	/**
	 * @brief class Anuncio constructor.
	 * Creates new advertisement with information provided and data correspondent to current date.
	 *
	 * @param titulo advertisement's title
	 * @param categoria advertisement's category
	 * @param descricao advertisement's description
	 * @param anunciante pointer to the advertiser
	 */
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/Utilizador* anunciante);
	/**
	 * @brief class Anuncio destructor.
	 * A virtual destructor
	 */
	virtual ~Anuncio();
	/**
	 * @brief get title.
	 *
	 * @return advertisement's title
	 */
	string getTitulo();
	/**
	 * @brief get category.
	 *
	 * @return advertisement's category
	 */
	string getCategoria();
	/**
	 * @brief get id.
	 *
	 * @return advertisement's id
	 */
	int getId();
	/**
	 * @brief get date.
	 *
	 * @return advertisement's creation date
	 */
	Data getData();
	/**
	 * @brief get views.
	 *
	 * @return number of views gotten by the advertisement
	 */
	int getVisualizacoes();
	/**
	 * @brief increment views
	 *
	 * This function increments view counter by one
	 */
	void incVisualizacoes();
	/**
	 * @brief display ad
	 *
	 * Funtion display advertisement on screen
	 */
	virtual void imprime() const = 0;
};

class DeVenda: public Anuncio{
	Estado estado;
	float preco;
	bool negociacao;
public:
	DeVenda(string titulo, string categoria, string descricao,/*imagens*/Estado estado,	float preco,bool negociacao,Utilizador* anunciante);
	Estado getEstado();
	float getPreco();
	void setPreco(float preco);
	void imprime() const ;
};

class DeCompra: public Anuncio{
	DeVenda* troca;
public:
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ DeVenda* ptr,Utilizador* anunciante);
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ Utilizador* anunciante);
	void imprime() const ;
};


#endif /* SRC_ANUNCIO_H_ */
