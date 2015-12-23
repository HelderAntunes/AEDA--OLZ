/** @mainpage Olz documentation
 *
 * @section intro_sec Introduction
 *
 * This document contains the doxygen generated documentation for every class in this project
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "Anuncio.h"
#include "OLZ.h"
#include "Menu.h"

using namespace std;


int main(){

	OLZ olz;

	ifstream olz_file("OLZ-file.txt");
	if (!olz_file.is_open()){
		cout << "Erro na abertura do ficheiro!\n";

		return 1;
	}
	olz.leTodosOsDados(olz_file);
	olz_file.close();

	cout << "Bem-vindo ao OLZ!!!\n\n";

	int opcao = 0;
	bool run = true;
	while(run){
		mostrarMenuPrincipal();
		cin >> opcao;
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			avisarOpcaoInvalida();

			continue;
		}
		cin.ignore();
		if(isOpcaoInvalida(opcao, 1, 23) == true){
			avisarOpcaoInvalida();
			continue;
		}
		switch(opcao){
		case 1:
			imprimirUtilizadores(olz);
			break;
		case 2:
			criar_e_adicionarNovoUtilizador(olz);
			break;
		case 3:
			apagarUtilizador(olz);
			break;
		case 4:
			mostrarAnunciosPorCategoria(olz);
			break;
		case 5:
			mostrarAnunciosPorLocalizacaoDoAnunciante(olz);
			break;
		case 6:
			mostrarAnunciosPorPalavraChave(olz);
			break;
		case 7:
			mostrarAnunciosPorPrecoAproximado(olz);
			break;
		case 8:
			adicionarAnuncioDeVenda(olz);
			break;
		case 9:
			adicionarAnuncioDeCompra(olz);
			break;
		case 10:
			verAnuncio(olz);
			break;
		case 11:
			apagarAnuncio(olz);
			break;
		case 12:
			adicionarContacto(olz);
			break;
		case 13:
			concretizarNegocio(olz);
			break;
		case 14:
			mostrarNegociosConcretizados(olz);
			break;
		case 15:
			mostrarNCPorCategoria(olz);
			break;
		case 16:
			mostrarNCPorAnunciante(olz);
			break;
		case 17:
			mostrarNCPorComprador(olz);
			break;
		case 18:
			mostrarNCPorPreco(olz);
			break;
		case 19:
			mostrarContactos(olz);
			break;
		case 20:
			mostrarCategorias(olz);
			break;
		case 21:
			mostrarAnunciosMaisPopulares(olz);
			break;
		case 22:
			colocarOuRetirarDestaquemEmAnuncio(olz);
			break;
		case 23:
			run = false;
		}
		cout << "\n\nPrime a tecla enter para continuar.";
		cin.ignore(10000,'\n');
		system("cls");
	}
	cout << "Obrigado! Volte sempre!\n";

	ofstream olzFile("OLZ-file.txt");
	olz.salvarTodosOsDados(olzFile);
	olzFile.close();
	return 0;
}