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
#include "NegocioConcretizado.h"

typedef tr1::unordered_set<NegocioConcretizado*,NegocioConcretizadoHash,NegocioConcretizadoHash> tabHNegociosConcretizados;
typedef tabHNegociosConcretizados::iterator iteratorHNegociosConcretizados;

/**
 * structure to hashing table of achieved business
 */
struct NegocioConcretizadoHash
{
	// hashing function
	int operator() (const NegocioConcretizado* c) const
	{
		int hash = 0;

		string desc = c->getDescricao();
		for (unsigned int i = 0; i < desc.size(); ++i) {
			hash = hash*3 + desc[i];
		}

		Utilizador* ptr = c->getAnunciante();
		string email = ptr->getEmail();
		for (unsigned int i = 0; i < desc.size(); ++i) {
			hash = hash*3 + email[i];
		}

		ptr = c->getPessoaInteressada();
		email = ptr->getEmail();
		for (unsigned int i = 0; i < desc.size(); ++i) {
			hash = hash*3 + email[i];
		}

		return hash;
	}

	// equal function
	bool operator() (const NegocioConcretizado* c1, const NegocioConcretizado* c2) const
	{
		return ((c1->getDescricao() == c2->getDescricao())
				&& (c1->getAnunciante() == c2->getAnunciante())
				&& (c1->getPessoaInteressada() == c2->getPessoaInteressada()));
	}
};



/**
 * structure to compare two pointer of users (useful to implement the set)
 */
struct userPtrComp{
	bool operator()(const Utilizador* left, const Utilizador* right) const  {
		return (*left) < (*right);
	}
};

/**
 * structure that implement the operator minus for seller ad
 */
struct menorPorDestaque_AVenda{
	bool operator()(const DeVenda* left, const DeVenda* right) const{
		if(left->anuncioTemDestaque() && !right->anuncioTemDestaque())
			return true;

		else if(!left->anuncioTemDestaque() && right->anuncioTemDestaque())
			return false;

		else
			return left->getData() < right->getData();
	}
};

/**
 * structure that implement the operator minus for Buying ad
 */
struct menorPorDestaque_ACompra{
	bool operator()(const DeCompra* left, const DeCompra* right) const{
		if(left->anuncioTemDestaque() && !right->anuncioTemDestaque())
			return true;

		else if(!left->anuncioTemDestaque() && right->anuncioTemDestaque())
			return false;

		else
			return left->getData() < right->getData();
	}
};

/**@class OLZ
 * @brief compact all information of system
 */
class OLZ {
	vector<Contacto*> contactos;
	vector<string> categorias;
	set<Utilizador*, userPtrComp> utilizadores;
	priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > anunciosDeVenda;
	priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> anunciosDeCompra;
	tabHNegociosConcretizados negociosConcretizados;

	/**@brief delete contacts associated to a determined add
	 *
	 * @param id_anuncio id of a add
	 */
	void apagaContactosAssociados_A_Anuncio(int id_anuncio);

public:
	OLZ();
	// helder
	virtual ~OLZ();

	/**@brief add a user to a set of users
	 *
	 * @param Utilizador* novoUtilizador)
	 */
	void adicionarUtilizador(Utilizador* novoUtilizador);

	/**@brief delete a user, their adds and their contacts
	 *
	 * @param email email of user
	 */
	void apagarUtilizadorESeusAnuncios(string email);

	/**@brief add a seller add to a priority_queue of seller adds
	 *
	 * @param DeVenda* novoAnuncio
	 */
	void adicionarAnuncioVenda(DeVenda* novoAnuncio);

	/**@brief add a want add to a priority_queue of want adds
	 *
	 * @param DeCompra* novoAnuncio
	 */
	void adicionarAnuncioCompra(DeCompra* novoAnuncio);

	/**@brief delete anunciosVenda and the contacts associated
	 *
	 * @param id id of add to delete
	 */
	void apagarAnuncioVenda_E_ContactosAssociados(int id_anuncio);

	/**@brief delete anunciosCompra and the contacts associated
	 *
	 * @param id_anuncio id of add to delete
	 */
	void apagarAnuncioCompra_E_ContactosAssociados(int id_anuncio);

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

	// ines - esta feito
	void adicionarContacto(Contacto* novoContacto);
	void adicionarNegocio(NegocioConcretizado* novoNegocio);
	tabHNegociosConcretizados getNegociosConcretizados() const;

	vector<string> getCategorias() const;

	vector<Contacto*> getContactos() const;

	// helder
	void leTodosOsDados(istream& olz_file);
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leContactos(istream& olz_file);
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
