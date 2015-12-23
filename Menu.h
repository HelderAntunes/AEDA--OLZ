/*
 * Menu.h
 *
 *  Created on: 23/12/2015
 *      Author: Hélder Antunes
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include "OLZ.h"

// just print main menu
void mostrarMenuPrincipal();

/************************
 * OPTIONS OF MAIN MENU *
 ************************/

// OPTION 1
void imprimirUtilizadores(const OLZ& olz);
// OPTION 2
void criar_e_adicionarNovoUtilizador(OLZ& olz);
// OPTION 3
void apagarUtilizador(OLZ& olz);
// OPTION 4
void mostrarAnunciosPorCategoria(const OLZ& olz);
// OPTION 5
void mostrarAnunciosPorLocalizacaoDoAnunciante(const OLZ& olz);
// OPTION 6
void mostrarAnunciosPorPalavraChave(const OLZ& olz);
// OPTION 7
void mostrarAnunciosPorPrecoAproximado(const OLZ& olz);
// OPTION 8
void adicionarAnuncioDeVenda(OLZ& olz);
// OPTION 9
void adicionarAnuncioDeCompra(OLZ& olz);
// OPTION 10
void verAnuncio(const OLZ& olz);
// OPTION 11
void apagarAnuncio(OLZ& olz);
// OPTION 12
void adicionarContacto(OLZ& olz);
// OPTION 13
void concretizarNegocio(OLZ& olz);
// OPTION 14
void mostrarNegociosConcretizados(OLZ& olz);
// OPTION 15
void mostrarNCPorCategoria(const OLZ& olz);
// OPTION 16
void mostrarNCPorAnunciante(const OLZ& olz);
// OPTION 17
void mostrarNCPorComprador(const OLZ& olz);
// OPTION 18
void mostrarNCPorPreco(const OLZ& olz);
// OPTION 19
void mostrarContactos(OLZ& olz);
// OPTION 20
void mostrarCategorias(const OLZ& olz);
// OPTION 21
void mostrarAnunciosMaisPopulares(const OLZ& olz);
// OPTION 22
void colocarOuRetirarDestaquemEmAnuncio(OLZ& olz);


/***********************
 * AUXILIARY FUNCTIONS *
 ***********************/

// return true if opcao is outside of interval [inf,sup], false other wise.
bool isOpcaoInvalida(int opcao, int inf, int sup);

// return true if categoria exists in olz.
bool existeCategoria(const OLZ& olz,string categoria);

// return true if exists a user with the email received as argument.
bool emailExiste(string email,const OLZ& olz);

// this function compare to pointers to ads, return true if *a1 < *a2, false otherwise
bool ordenaPorVisualizacoes(Anuncio* a1, Anuncio* a2);

// if input is y return true, if is no return false.
bool leResposta();

// asking for email of user, and return this email
string leEmaiDoUtilizador();

// read state of product in input, and return this state in form of type Estado
Estado leEstadoDoProduto();

// read data in input
Data leData();

// read category of input
string leCategoria(const OLZ& olz);

// read images of input
vector<string> leImagens();

// read if of a seller ad to swap
int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz);

// read a email, find a user with the introduced email, and return the user(pointer to user)
Utilizador* leUtilizadorAtravesDoEmail(const OLZ& olz);

// create an user using I/O operations.
Utilizador* criarUtilizador(const OLZ& olz);

// create a contact between two user using I/O operations.
Contacto* criarContactoEntreDoisUtilizadores(const OLZ& olz);

// create a seller ad using I/O operations.
DeVenda* criarAnuncioVenda(const OLZ& olz);

// create a want ad using I/O operations.
DeCompra* criarAnuncioCompra(const OLZ& olz);

// receive a vector of pointer to ads, and print them according their type.
void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados);

// print in screen all the user of OLZ
void imprimirUtilizadores(const OLZ& olz);

// warning the user that the option previously chosen is invalid
void avisarOpcaoInvalida();

// return a non-NULL pointer if found the ad, NULL pointer if the ad wasn´t found
Anuncio* encontraAnuncioAtravesDoId(const OLZ& olz,int id);

// Search the ad, erase the ad and the related contacts. Does nothing if doesn´t found the add
void apagarAnuncioEncontradoEseusContactos(int id_anuncio, OLZ& olz);

// try to find a user asking for this email, return non-pointer if the user was found
// or throw an exception otherwise
Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz, string email);


#endif /* SRC_MENU_H_ */
