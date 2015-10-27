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
 * This class helps make the categories finite and uniform
 * @brief category class.
 */
class Categoria{
	string catName;					/**< category name */
	Categoria* subCategoria;	/**< pointer to subcategory */
public:
	/**
	 * Creates new category without subcategories
	 * @brief class Categoria constructor.
	 *
	 * @param nome category's name
	 */
	Categoria(string nome){
		catName = nome;
		subCategoria = NULL;
	}
	/**
	 * Creates new category with subcategories
	 * @brief class Categoria constructor.
	 *
	 * @param nome category's name
	 * @param catPtr pointer to subcategory
	 */
	Categoria(string nome, Categoria* catPtr){
		this->catName = nome;
		this->subCategoria = catPtr;
	}
	/**
	 * @brief display category on screen.
	 *
	 * @return output stream passed as parameter
	 */
	friend std::ostream operator<< (std::ostream out, Categoria category);
};

std::ostream operator<< (std::ostream out, Categoria category){
	out << category.catName;
	return out;
}

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
	 * Creates new advertisement with information provided and data correspondent to current date.
	 * @brief class Anuncio constructor.
	 *
	 * @param titulo advertisement's title
	 * @param categoria advertisement's category
	 * @param descricao advertisement's description
	 * @param anunciante pointer to the advertiser
	 */
	Anuncio(string titulo, string categoria, string descricao,/*imagens*/Utilizador* anunciante);
	/**
	 * A virtual destructor
	 * @brief class Anuncio destructor.
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
	 * This function increments view counter by one
	 * @brief increment views.
	 */
	void incVisualizacoes();
	/**
	 * Funtion displays advertisement on screen
	 * @brief display ad.
	 */
	virtual void imprime() const = 0;
};

/**@class DeVenda
 * @brief Sale Advertisement class derived from Anuncio
 */
class DeVenda: public Anuncio{
	Estado estado;				/**< advertised object's condition */
	float preco;				/**< advertised object's demanded price */
	bool negociacao;			/**< boolean indicating whether advertiser is willing to negotiate */
public:
	/**
	 * Creates new sale advertisement with information provided and data correspondent to current date.
	 * @brief class DeVenda constructor.
	 *
	 * @param titulo advertisement's title
	 * @param categoria advertisement's category
	 * @param descricao advertisement's description
	 * @param estado advertised object's condition
	 * @param preco advertised object's demanded price
	 * @param negociacao advertiser position regarding negotiation
	 * @param anunciante pointer to the advertiser
	 */
	DeVenda(string titulo, string categoria, string descricao,/*imagens*/Estado estado,	float preco,bool negociacao,Utilizador* anunciante);
	/**
	 * @brief get condition.
	 *
	 * @return condition of advertised product
	 */
	Estado getEstado();
	/**
	 * @brief get price.
	 *
	 * @return price of advertised product
	 */
	float getPreco();
	/**
	 * Function changes the price of the product
	 * @brief set price.
	 *
	 * @param preco new price for product
	 */
	void setPreco(float preco);
	/**
	 * Function displays sale advertisement on screen
	 * @brief display sale ad.
	 */
	void imprime() const ;
};

/**@class DeCompra
 * @brief Purchase Advertisement class derived from Anuncio
 */
class DeCompra: public Anuncio{
	DeVenda* troca;				/**< pointer to an sale advertisement alerting for the possibility of an exchange */
public:
	/**
	 * Creates new purchase advertisement with exchange possibility.
	 * @brief class DeCompra constructor.
	 *
	 * @param titulo advertisement's title
	 * @param categoria advertisement's category
	 * @param descricao advertisement's description
	 * @param anunciante pointer to the advertiser
	 * @param ptr pointer to sale ad admissible for exchange
	 */
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ DeVenda* ptr,Utilizador* anunciante);
	/**
	 * Creates new purchase advertisement without exchange possibility (troca equal to NULL).
	 * @brief class DeCompra constructor.
	 *
	 * @param titulo advertisement's title
	 * @param categoria advertisement's category
	 * @param descricao advertisement's description
	 * @param anunciante pointer to the advertiser
	 */
	DeCompra(string titulo, string categoria, string descricao,/*imagens*/ Utilizador* anunciante);
	/**
	 * Function displays purchase advertisement on screen
	 * @brief display purchase ad.
	 */
	void imprime() const ;
};


#endif /* SRC_ANUNCIO_H_ */
