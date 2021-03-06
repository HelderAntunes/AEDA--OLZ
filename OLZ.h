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

/**
 * structure to hashing table of achieved business
 */
struct NegocioConcretizadoHash
{
	/** @brief hashing function
	 *
	 * @param c transaction to be placed on hash table
	 */
	int operator() (const NegocioConcretizado* c) const
	{
		int hash = 0;

		string desc = c->getDescricao();
		for (unsigned int i = 0; i < desc.size(); ++i) {
			hash = hash*3 + desc[i];
		}

		return hash;
	}

	/** function to determine if to transactions are equal
	 * @brief equal function
	 *
	 * @param c1 transaction on the left
	 * @param c2 transaction on the right
	 */
	bool operator() (const NegocioConcretizado* c1, const NegocioConcretizado* c2) const
	{
		return ((c1->getDescricao() == c2->getDescricao())
				&& (c1->getAnunciante() == c2->getAnunciante())
				&& (c1->getPessoaInteressada() == c2->getPessoaInteressada()));
	}
};

typedef tr1::unordered_set<NegocioConcretizado*,NegocioConcretizadoHash,NegocioConcretizadoHash> tabHNegociosConcretizados;
typedef tabHNegociosConcretizados::iterator iteratorHNegociosConcretizados;

/**
 * @brief structure to compare two pointer of users (useful to implement the set)
 */
struct userPtrComp{
	/**
	 * @brief function to compare to pointers of users
	 */
	bool operator()(const Utilizador* left, const Utilizador* right) const  {
		return (*left) < (*right);
	}
};

/**
 * structure that implement the operator minus for seller ad
 */
struct menorPorDestaque_AVenda{
	/** @brief funcion to compare two sale advertisements
	 *
	 * @param left ad on the left
	 * @param right ad on the right
	 */
	bool operator()(const DeVenda* left, const DeVenda* right) const{
		if(left->anuncioTemDestaque() && !right->anuncioTemDestaque())
			return false;

		else if(!left->anuncioTemDestaque() && right->anuncioTemDestaque())
			return true;

		else
			return left->getData() < right->getData();
	}
};

/**
 * structure that implement the operator minus for Buying ad
 */
struct menorPorDestaque_ACompra{
	/** @brief funcion to compare two purchase advertisements
	 *
	 * @param left ad on the left
	 * @param right ad on the right
	 */
	bool operator()(const DeCompra* left, const DeCompra* right) const{
		if(left->anuncioTemDestaque() && !right->anuncioTemDestaque())
			return false;

		else if(!left->anuncioTemDestaque() && right->anuncioTemDestaque())
			return true;

		else
			return left->getData() < right->getData();
	}
};

/**@class OLZ
 * @brief compact all information of system
 */
class OLZ {
	set<Utilizador*, userPtrComp> utilizadores;													/**< users */
	priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > anunciosDeVenda; 		/**< sales advertisements */
	priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> anunciosDeCompra;	/**< purchase advertisements */
	tabHNegociosConcretizados negociosConcretizados; 											/**< transactions */
	vector<Contacto*> contactos;																/**< contacts */
	vector<string> categorias;																	/**< categories */
	/**
	 * @brief delete all the contacts associated to a ad
	 *
	 *@param id_anuncio id of ad
	 */
	void apagarContactosAssociados_A_Anuncio(int id_anuncio);

	/**
	 * @brief the function delete information about user in achieved business
	 *
	 * @param emailUtilizador email of user
	 */
	void apagarInformacoesDoUtilizadorEmNegociosConcretizados(string emailUtilizador);

	/**
	 * @brief delete ads and contacts of a user, using user email
	 *
	 * @param emailUtilizador email of the user
	 */
	void apagarAnunciosDeUmUtilizador(string emailUtilizador);

	/**
	 * @brief just delete a user from a set of users
	 *
	 * @param emailUtilizador email of user
	 */
	void apagarUtilizador(string emailUtilizador);

	/**
	 * @brief detete all the contacts of a user
	 *
	 * @param emailUtilizador email of user
	 */
	void apagarContactosDeUmUtilizador(string emailUtilizador);

	/**
	 * @brief delete a seller add
	 *
	 * @param id_anuncio id of add for be deleted
	 */
	void apagarAnuncioDeVenda(int id_anuncio);

	/**
	 * @brief delete a want ad
	 *
	 * @param id_anuncio id of add for be deleted
	 */
	void apagarAnuncioDeCompra(int id_anuncio);

public:
	/**
	 * @brief constructor of class OLZ
	 * The function don�t initialize any variables
	 */

	OLZ();
	/**
	 * @brief destuctor of class OLZ, free dynamic allocated memory
	 */
	virtual ~OLZ();

	/**
	 * @brief add a user to a set of users
	 *
	 * @param novoUtilizador)
	 */
	void adicionarUtilizador(Utilizador* novoUtilizador);

	/**
	 * @brief add new contact between two users
	 *
	 * @param novoContacto contact to be added
	 */
	void adicionarContacto(Contacto* novoContacto);

	/**
	 * @brief add new transaction between two users
	 *
	 * @param novoNegocio contact to be added
	 */
	void adicionarNegocio(NegocioConcretizado* novoNegocio);

	/**
	 * @brief add a seller add to a priority_queue of seller adds
	 *
	 * @param novoAnuncio new advertisement
	 */
	void adicionarAnuncioVenda(DeVenda* novoAnuncio);

	/**
	 * @brief add a want add to a priority_queue of want adds
	 *
	 * @param novoAnuncio new advertisement
	 */
	void adicionarAnuncioCompra(DeCompra* novoAnuncio);

	/**
	 * @brief delete a user, his adds, his contacts and informations in achieved trades
	 *
	 * @param emailUtilizador email of user
	 */
	void apagarUtilizador_SeusAnuncios_Contactos_E_Informacoes(string emailUtilizador);

	/**
	 * @brief delete a seller ad and all associated contacts
	 *
	 * @param id_anuncio id of ad
	 */
	void apagarAnuncioDeVendaESeusContactos(int id_anuncio);

	/**
	 * @brief delete a want ad and all asociated contacts
	 *
	 * @param id_anuncio id of ad
	 */
	void apagarAnuncioDeCompraESeusContactos(int id_anuncio);

	/** An ad could be altered, so the order of ads of priority queue must be updated
	 *
	 * @brief update the priority queues of OLZ
	 */
	void atualizarFilasPrioridade();

	/**
	 * @brief get all adds that exists
	 *
	 * @return vector<Anuncio*> vector of all adds
	 */
	vector<Anuncio*> getAnunciosDeVendaEdeCompra() const;

	/**
	 * @brief get all seller adds that exists
	 *
	 * @return vector<DeVenda*> anunciosDeVenda
	 */
	vector<DeVenda*> getAnunciosDeVenda() const;

	/**
	 * @brief get all want adds that exists
	 *
	 * @return vector<DeCompra*> anunciosDeCompra
	 */
	vector<DeCompra*> getAnunciosDeCompra() const;

	/**
	 * @brief get all users that exists
	 *
	 * @return vector<Utilizador*> utilizadores
	 */
	set<Utilizador*, userPtrComp> getUtilizadores() const;

	/**
	 * @brief get achieved business
	 */
	tabHNegociosConcretizados getNegociosConcretizados() const;

	/**
	 * @brief get all categories that exists
	 *
	 * @return vector<string> categories that exists
	 */
	vector<string> getCategorias() const;

	/**
	 * @brief get all contacts that exists
	 *
	 * @return vector<Contacto*> contactos
	 */
	vector<Contacto*> getContactos() const;

	/**
	 * @brief increment the number of business and update the date of last business of a user
	 *
	 * @param emailUtilizador email of user to update
	 * @param data date of last business
	 */
	void incNegociosEatualizaDataUltimoNegocioDeUtilizador(string emailUtilizador, Data data);

	/**
	 * @brief read data from a file
	 *
	 * @param olz_file
	 */
	void leTodosOsDados(istream& olz_file);

	/**
	 * @brief read users and their ads from a file
	 *
	 * @param olz_file
	 */
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);

	/**
	 * @brief read selling ads from a file
	 *
	 * @param olz_file
	 * @param anunciante advertiser
	 */
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);

	/**
	 * @brief read want ads from a file
	 *
	 * @param olz_file
	 * @param anunciante advertiser
	 */
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);

	/**
	 * @brief read the contacts from a file
	 *
	 * @param olz_file
	 */
	void leContactos(istream& olz_file);

	/**
	 * @brief read the contacts from a file
	 *
	 * @param olz_file
	 */
	void leNegocios(istream& olz_file);

	/**
	 * @brief save all data into a file
	 *
	 * @param olz_file
	 */
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
	 * @param categoria name of category that does not exist
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
