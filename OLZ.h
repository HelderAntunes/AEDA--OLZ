/*
 * OLZ.h
 *
 *  Created on: 01/11/2015
 *      Author: Asus
 */

#ifndef SRC_OLZ_H_
#define SRC_OLZ_H_
#include <iostream>
#include <vector>
#include "Anuncio.h"
#include "Contacto.h"

class OLZ {
	vector<DeVenda*> anunciosDeVenda;
	vector<DeCompra*> anunciosDeCompra;
	vector<Utilizador*> utilizadores;
	vector<Contacto*> contactos;
	vector<string> categorias;
public:
	OLZ();
	virtual ~OLZ();
	void leTodosOsDados(istream& olz_file);
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leContactos(istream& olz_file);
	void imprimeTodosOsDados();
	void imprimeUtilizadores();
	void imprimeAnunciosDeVenda();
	void imprimeAnunciosDeCompra();
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

class ExceptionCategoriaInexistente{
	string categoria;
public:
	ExceptionCategoriaInexistente(string categoria){
		this->categoria = categoria;
	}
	string getCategoria() const{
		return categoria;
	}
};

#endif /* SRC_OLZ_H_ */
