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
bool isOpcaoInvalida(int opcao, int inf, int sup);
bool isOpcaoSaida(int opcao);
Utilizador* criarUtilizador();
string pedeEmailDoUtilizadorQueQuerApagar();
void mostrarAnunciosPorCategoria(const OLZ& olz);
void mostrarAnunciosPorLocalizacaoDoAnunciante(const OLZ& olz);
void mostrarAnunciosPorPalavraChave(const OLZ& olz);
void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados);
void mostrarAnunciosPorPrecoAproximado(const OLZ& olz);


int main(){
	OLZ olz;
	ifstream olz_file("OLZ-file.txt");
	olz.leTodosOsDados(olz_file);
	cout << "Bem-vindo ao OLZ!!!\n\n";
	int opcao = 0;
	while(1){
		mostrarMenuPrincipal();
		cin >> opcao;
		if(isOpcaoInvalida(opcao, 1, 15) == true){
			cout << "Opcao invalida\n\n";
			continue;
		}
		else if(isOpcaoSaida(opcao))
			break;
		if(opcao == 1)
			olz.imprimeUtilizadores();
		else if(opcao == 2){
			Utilizador* novoUtil = criarUtilizador();
			olz.adicionarUtilizador(novoUtil);
		}
		else if(opcao == 3){
			string email = pedeEmailDoUtilizadorQueQuerApagar();
			olz.apagarUtilizador(email);
		}
		else if(opcao == 4)
			mostrarAnunciosPorCategoria(olz);
		else if(opcao == 5)
			mostrarAnunciosPorLocalizacaoDoAnunciante(olz);
		else if(opcao == 6)
			mostrarAnunciosPorPalavraChave(olz);
		else if(opcao == 7)
			mostrarAnunciosPorPrecoAproximado(olz);

	}while(isOpcaoInvalida(opcao,1,15));


	return 0;
}

bool isOpcaoInvalida(int opcao, int inf, int sup){
	if(opcao < inf || opcao > sup)
		return true;
	else
		return false;
}

bool isOpcaoSaida(int opcao){
	if(opcao == 15)
		return true;
	else
		return false;
}

void mostrarMenuPrincipal(){
	cout << "Pretende:\n"
				"\t 1 - Mostrar Utilizadores\n"
				"\t 2 - Adicionar Utilizador\n"
				"\t 3 - Apagar Utilizador\n"
				"\t 4 - Mostrar anuncios por categoria\n"
				"\t 5 - Mostrar anuncios por localizacao do anunciante\n"
				"\t 6 - Mostrar anuncios por palavra-chave\n"
				"\t 7 - Mostrar anuncios por preco aproximado\n"
				"\t 8 - Adicionar anuncio de venda\n"
				"\t 9 - Adicionar anuncio de compra\n"
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

void mostrarAnunciosPorLocalizacaoDoAnunciante(const OLZ& olz){
	int opcao = 0;
	do{
		cout << "Procurar anuncios por:\n";
		cout << "\t1 - Freguesia do anunciante\n";
		cout << "\t2 - Concelho do anunciante\n";
		cout << "\t3 - Distrito do anunciante\n";
		cin >> opcao;
		if(isOpcaoInvalida(opcao,1,3))
			cout << "Opcao invalida\n\n";
	}while(isOpcaoInvalida(opcao,1,3));

	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	vector<Anuncio*> anunciosEncontrados;

	if(opcao == 1){
		string freguesia;
		cout << "Introduza a freguesia a procurar: "; cin >> freguesia;
		for(int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getFreguesia() == freguesia)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 2){
		string concelho;
		cout << "Introduza a concelho a procurar: "; cin >> concelho;
		for(int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getConcelho() == concelho)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 3){
		string distrito;
		cout << "Introduza a distrito a procurar: "; cin >> distrito;
		for(int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getDistrito() == distrito)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
}

void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados){
	for(int i = 0;i< anunciosEncontrados.size();i++)
		anunciosEncontrados[i]->imprime();
	if(anunciosEncontrados.size() == 0)
		cout << "Nao foi encontrado nenhum anuncio com a distrito indicada.\n";
}

void mostrarAnunciosPorPalavraChave(const OLZ& olz){
	string palavraChave;
	cout << "Introduz a palavra chave:";
	cin >> palavraChave;
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	vector<Anuncio*> anunciosEncontrados;
	for(int i = 0;i < anuncios.size();i++)
		if(anuncios[i]->procuraPalavraChave(palavraChave))
			anunciosEncontrados.push_back(anuncios[i]);
	imprimirAnunciosEncontrados(anunciosEncontrados);
}

void mostrarAnunciosPorPrecoAproximado(const OLZ& olz){
	float preco_min, preco_max;
	cout << "Introduza um intervalo de preco\n";
	cout << "Preco minimo: ";
	cin >> preco_min;
	cout << "Preco maximo: ";
	cin >> preco_max;
	vector<DeVenda*> anunciosVenda = olz.getAnunciosDeVenda();
	vector<DeVenda*> anunciosEncontrados;
	for(int i = 0;i < anunciosVenda.size();i++)
		if(anunciosVenda[i]->getPreco() >= preco_min && anunciosVenda[i]->getPreco() <= preco_max)
			anunciosEncontrados.push_back(anunciosVenda[i]);
	vector<Anuncio*> anunciosParaImprimir;
	for(int i = 0;i< anunciosEncontrados.size();i++)
		anunciosParaImprimir.push_back(anunciosEncontrados[i]);
	imprimirAnunciosEncontrados(anunciosParaImprimir);
}


