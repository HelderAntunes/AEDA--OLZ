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
#include <set>
#include <queue>
#include <tr1/unordered_set>
#include "Anuncio.h"
#include "Contacto.h"

//ines
struct hNegocioConcretizado{

};

//ines
struct eqNegocioConcretizado{

};

// helder
struct userPtrComp{
	bool operator()(const Utilizador* left, const Utilizador* right) const  {
		return (*left) < (*right);
	}
};

// filipe
struct menorPorDestaque_AVenda{
	bool operator()(const DeVenda* left, const DeVenda* right) const{
		return true;
	}
};

// filipe
struct menorPorDestaque_ACompra{
	bool operator()(const DeCompra* left, const DeCompra* right) const{
		return true;
	}
};

typedef tr1::unordered_set<Contacto*,hNegocioConcretizado,eqNegocioConcretizado>::iterator iteratorHNegociosConcretizados;
typedef tr1::unordered_set<Contacto*,hNegocioConcretizado,eqNegocioConcretizado> HashNegociosConcretizados;

/**@class OLZ
 * @brief compact all information of system
 */
class OLZ {
	vector<Contacto*> contactos;
	vector<string> categorias;
	set<Utilizador*, userPtrComp> utilizadores;
	priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > anunciosDeVenda;
	priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> anunciosDeCompra;
	HashNegociosConcretizados negociosConcretizados;
public:
	OLZ();
	// helder
	virtual ~OLZ();

	// helder - esta feito
	void adicionarUtilizador(Utilizador* novoUtilizador);

	// helder - esta feito
	void apagarUtilizadorESeusAnuncios(string email);

	// filipe
	void adicionarAnuncioVenda(DeVenda* novoAnuncio);

	// filipe
	void adicionarAnuncioCompra(DeCompra* novoAnuncio);

	// filipe
	void apagarAnuncioVenda(int id);

	// filipe
	void apagarAnuncioCompra(int id);

	// ines (adicionar a contactos ou negocios concretizados consoante novoContacto esta concretizado ou nao)
	void adicionarContacto(Contacto* novoContacto);

	// filipe (acho melhor retornar um vetor do que uma fila de prioridade,
	// pois o vetor e random acess iterator, enquanto que a fila de prioridade
	// nem suporta iteradores(apenas push, pop, top)
	vector<Anuncio*> getAnunciosDeVendaEdeCompra() const;

	// filipe
	vector<DeVenda*> getAnunciosDeVenda() const;

	// filipe
	vector<DeCompra*> getAnunciosDeCompra() const;

	// helder
	set<Utilizador*, userPtrComp> getUtilizadores() const;

	// ines
	HashNegociosConcretizados getNegociosConcretizados() const;

	vector<string> getCategorias() const;

	vector<Contacto*> getContactos() const;

	// helder
	void leTodosOsDados(istream& olz_file);
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leContactos(istream& olz_file);
	// helder
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
