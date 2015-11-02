/*
 * main.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Anuncio.h"
#include "OLZ.h"

using namespace std;

int main(){
	OLZ olz;
	ifstream olz_file("OLZ-file.txt");


	/*
	cout << "Bem-vindo ao OLZ!!!\n\n";
	int opcao = 0;
	do{
		mostraMenuPrincipal();
		cin >> opcao;
		if(opcao < 1 || opcao > 3)
			cout << "Opcao invalida\n\n";
	}while(opcao < 1 || opcao > 3);
	 */
	return 0;
}


void mostraMenuPrincipal(){
	cout << "Pretende:\n"
			"1 - entrar como visitante\n"
			"2 - realizar login\n"
			"3 - registar-se no OLZ\n";
	cout << "Opcao: ";
	return;
}



