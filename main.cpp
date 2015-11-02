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

void mostrarMenuPrincipal();
bool opcaoInvalida(int opcao);
bool opcaoDeSaidaDaAplicacaoEscolhida(int opcao);
Utilizador* criarUtilizador();
string pedeEmailDoUtilizadorQueQuerApagar();
void mostrarAnunciosPorCategoria(const OLZ& olz);
void mostrarAnunciosPorLocalizacao(const OLZ& olz);

int main(){
	OLZ olz;
	ifstream olz_file("OLZ-file.txt");
	olz.leTodosOsDados(olz_file);
	cout << "Bem-vindo ao OLZ!!!\n\n";
	int opcao = 0;
	do{
		mostrarMenuPrincipal();
		cin >> opcao;
		if(opcaoInvalida(opcao) == true)
			cout << "Opcao invalida\n\n";
		else if(opcaoDeSaidaDaAplicacaoEscolhida(opcao))
			break;


		switch(opcao){
		case 1:
			olz.imprimeUtilizadores();
			break;
		case 2:
		{
			Utilizador* novoUtil = criarUtilizador();
			olz.adicionarUtilizador(novoUtil);
		}
		case 3:
		{
			string email = pedeEmailDoUtilizadorQueQuerApagar();
			olz.apagarUtilizador(email);
		}
		case 4:
		{
			mostrarAnunciosPorCategoria(olz);
		}
		case 5:
		{
			mostrarAnunciosPorLocalizacao(olz);
		}
		}
	}while(opcao < 1 || opcao > 3);


	return 0;
}

bool opcaoInvalida(int opcao){
	if(opcao < 1 || opcao > 15)
		return true;
	else
		return false;
}

bool opcaoDeSaidaDaAplicacaoEscolhida(int opcao){
	if(opcao == 15)
		return true;
	else
		return false;
}

void mostrarMenuPrincipal(){
	cout << "Pretende:\n"
				"\t1 - Mostrar Utilizadores\n"
				"\t2 - Adicionar Utilizador\n"
				"\t3 - Apagar Utilizador\n"
				"\t4 - Mostrar anuncios por categoria\n"
				"\t5 - Mostrar anuncios por localizacao do anunciante\n"
				"\t6 - Mostrar anuncios por palavra-chave\n"
				"\t7 - Mostrar anuncios por preco aproximado\n"
				"\t8 - Adicionar anuncio de venda\n"
				"\t9 - Adicionar anuncio de compra\n"
				"\t10 - Ver anuncio\n"
				"\t11 - Apagar anuncio\n"
				"\t12 - Criar contacto entre dois utilizadores\n"
				"\t13 - Concretizar negocio\n"
				"\t14 - Mostrar negocios concretizados\n"
				"\t15 - Sair da aplicacao\n";
	cout << endl;
	cout << "Opcao: ";
	return;
}

Utilizador* criarUtilizador(){
	string nome, email, contacto;
	string freguesia, concelho, distrito;
	cout << "Nome do utilizador: "; cin >> nome;
	cout << "Email do Utilizador: "; cin >> email;
	cout << "Contacto do utilizador: "; cin >> contacto;
	cout << "Introduza os dados da morada.\n";
	cout << "Freguesia: "; cin >> freguesia;
	cout << "Concelho: "; cin >> concelho;
	cout << "Distrito: "; cin >> distrito;
	Localizacao local(freguesia,concelho,distrito);
	return new Utilizador(nome, email,contacto, local);
}

string pedeEmailDoUtilizadorQueQuerApagar(){
	string email;
	cout << "Email do utilizador que quer apagar: ";
	cin >> email;
	return email;
}

void mostrarAnunciosPorCategoria(const OLZ& olz){
	string categoria;
	cout << "Introduza uma categoria: ";
	cin >> categoria;
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	int anunciosImprimidos = 0;
	for(int i = 0;i < anuncios.size();i++)
		if(anuncios[i]->getCategoria() == categoria){
			anuncios[i]->imprime();
			cout << endl;
			anunciosImprimidos++;
		}
	if(anunciosImprimidos == 0)
		cout << "Nao foram encontrados anuncios dessa categoria.\n";
}

void mostrarAnunciosPorLocalizacao(const OLZ& olz){

}


