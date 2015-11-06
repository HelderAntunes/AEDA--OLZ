/*
 * OLZ.h
 *
 *  Created on: 01/11/2015
 *      Author: Helder Antunes
 */

#ifndef SRC_OLZ_H_
#define SRC_OLZ_H_
#include <iostream>
#include <vector>
#include "Anuncio.h"
#include "Contacto.h"

/**@class OLZ
 * @brief compact all information of system
 */
class OLZ {
	vector<DeVenda*> anunciosDeVenda; /**< vector of pointers to DeVenda */
	vector<DeCompra*> anunciosDeCompra; /**< vector of pointers to DeCompra */
	vector<Utilizador*> utilizadores; /**< vector of pointers to Utilizador */
	vector<Contacto*> contactos; /**< vector of pointers to Contacto */
	vector<string> categorias;  /**< vector of categorias */
public:
	OLZ();
	virtual ~OLZ();
	void leTodosOsDados(istream& olz_file);
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leContactos(istream& olz_file);
	void imprimeUtilizadores();
	void adicionarUtilizador(Utilizador* novoUtilizador);
	void apagarUtilizador(string email);
	void adicionarAnuncioVenda(DeVenda* novoAnuncio);
	void adicionarAnuncioCompra(DeCompra* novoAnuncio);
	void apagarAnuncioVenda(int id);
	void apagarAnuncioCompra(int id);
	void adicionarContacto(Contacto* novoContacto);
	void mostrarContactos();
	vector<Anuncio*> getAnunciosDeVendaEdeCompra() const;
	vector<DeVenda*> getAnunciosDeVenda() const;
	vector<DeCompra*> getAnunciosDeCompra() const;
	vector<Utilizador*> getUtilizadores() const;
	vector<string> getCategorias() const;
	vector<Contacto*> getContactos() const;
	void salvarTodosOsDados(ostream& olz_file);
};

/**@class ExceptionCategoriaInexistente
 * @brief it is used when a category does not exist.
 */
class ExceptionCategoriaInexistente{
	string categoria; /**< string name of category that does not exist*/
public:
	/**
	 * @brief Constructor of class
	 * @param name of category that does not exist
	 */
	ExceptionCategoriaInexistente(string categoria){
		this->categoria = categoria;
	}
	/**
	 * @brief return the name of category that does not exist
	 * @return the name of category that does not exist
	 */
	string getCategoria() const{
		return categoria;
	}
};

#endif /* SRC_OLZ_H_ */
