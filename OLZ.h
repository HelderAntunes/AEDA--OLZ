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

using namespace std;

class OLZ {
	vector<DeVenda*> anunciosDeVenda;
	vector<DeCompra*> anunciosDeCompra;
	vector<Utilizador*> utilizadores;
public:
	OLZ();
	virtual ~OLZ();
	void leTodosOsDados(istream& olz_file);
	void leUtilizadores_e_respetivosAnuncios(istream& olz_file);
	void leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante);
	void imprimeTodosOsDados();
	void imprimeUtilizadores();
	void imprimeAnunciosDeVenda();
	void imprimeAnunciosDeCompra();
};

#endif /* SRC_OLZ_H_ */
