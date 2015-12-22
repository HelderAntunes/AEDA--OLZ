/** @mainpage Olz documentation
 *
 * @section intro_sec Introduction
 *
 * This document contains the doxygen generated documentation for every class in this project
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Anuncio.h"
#include "OLZ.h"

using namespace std;

void mostrarMenuPrincipal();

/***********************
 *OPTIONS OF MAIN MENU *
 ***********************/
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

/***********************
 * AUXILIARY FUNCTIONS *
 ***********************/
bool isOpcaoInvalida(int opcao, int inf, int sup);
Utilizador* criarUtilizador(const OLZ& olz);
string leEmaiDoUtilizador();
void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados);
DeVenda* criarAnuncioVenda(const OLZ& olz);
DeCompra* criarAnuncioCompra(const OLZ& olz);
bool existeCategoria(const OLZ& olz,string categoria);
Estado leEstadoDoProduto();
bool leResposta();
Data leData();
string leCategoria(const OLZ& olz);
vector<string> leImagens();
int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz);
Contacto* criarContactoEntreDoisUtilizadores(const OLZ& olz);
Utilizador* leUtilizadorAtravesDoEmail(const OLZ& olz);
Anuncio* encontraAnuncioAtravesDoId(const OLZ& olz,int id);
void apagarAnuncioEncontradoEseusContactos(int id_anuncio, OLZ& olz);
bool emailExiste(string email,const OLZ& olz);
Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz, string email);
void imprimirUtilizadores(const OLZ& olz);

void avisarOpcaoInvalida();
bool ordenaPorVisualizacoes(Anuncio* a1, Anuncio* a2);


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
		if(isOpcaoInvalida(opcao, 1, 22) == true){
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
			run = false;
		}
		cout << "\n\nPrime a tecla enter para continuar.";
		cin.ignore(1000,'\n');
		system("cls");
	}
	cout << "Obrigado! Volte sempre!\n";
	ofstream olzFile("OLZ-file.txt");
	olz.salvarTodosOsDados(olzFile);
	olzFile.close();
	return 0;
}

/**
 * @brief show main menu
 */
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
			"\t15 - Mostrar negocios concretizados por categoria\n"
			"\t16 - Mostrar negocios concretizados por anunciante\n"
			"\t17 - Mostrar negocios concretizados por comprador\n"
			"\t18 - Mostrar negocios concretizados por preco aproximado\n"
			"\t19 - Mostrar contactos\n"
			"\t20 - Mostrar categorias\n"
			"\t21 - Mostrar anuncios mais populares\n"
			"\t22 - Sair da aplicacao\n";
	cout << endl;
	cout << "Opcao: ";
	return;
}

/**OPTION 1
 * @brief show all users of OLZ
 *
 */
void imprimirUtilizadores(const OLZ& olz){
	set<Utilizador*, userPtrComp> utilizadores = olz.getUtilizadores();
	set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();

	while(it != utilizadores.end()){
		(*it)->imprime();
		cout << "\n\n";
		it++;
	}
}

void apagarAnuncioEncontrado(int id_anuncio, OLZ& olz){
	vector<DeVenda*> anunciosDeVenda = olz.getAnunciosDeVenda();
	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		if(anunciosDeVenda[i]->getId() == id_anuncio){
			olz.apagarAnuncioDeVendaESeusContactos(id_anuncio);
			return;
		}

	vector<DeCompra*> anunciosDeCompra = olz.getAnunciosDeCompra();
	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
		if(anunciosDeCompra[i]->getId() == id_anuncio){
			olz.apagarAnuncioDeCompraESeusContactos(id_anuncio);
			return;
		}
}

/**OPTION 2
 * @brief create a user, and add to OLZ
 */
void criar_e_adicionarNovoUtilizador(OLZ& olz){
	Utilizador* novoUtil = NULL;
	while(1){
		try{
			novoUtil = criarUtilizador(olz);
		}
		catch(ExceptionEmailJaExistente& e){
			cout << "Erro ao criar o utilizador.\n";
			cout << "O email " << e.getEmail() << " ja existe.\n";
			cout << "Por favor, tente de novo.\n";
			continue;
		}
		break;
	}
	olz.adicionarUtilizador(novoUtil);
}

/**
 * @brief create a user. this function throw
 * an exception if exists a user with same email
 */
Utilizador* criarUtilizador(const OLZ& olz){
	string nome, email, contacto;
	string freguesia, concelho, distrito;

	cout << "Nome do utilizador: ";
	getline(cin,nome);

	cout << "Email do Utilizador: ";
	getline(cin, email);
	if(emailExiste(email,olz))
		throw ExceptionEmailJaExistente(email);

	cout << "Contacto do utilizador: ";
	getline(cin, contacto);

	cout << "Introduza os dados da morada.\n";

	cout << "Freguesia: ";
	getline(cin,freguesia);

	cout << "Concelho: ";
	getline(cin,concelho);

	cout << "Distrito: ";
	getline(cin,distrito);

	Localizacao local(freguesia,concelho,distrito);
	return new Utilizador(nome, email,contacto, local);
}

/**
 * @brief receive an email, and check if exists a user whit that email
 *
 * @return true if exists, false otherwise
 */

bool emailExiste(string email,const OLZ& olz){
	set<Utilizador*, userPtrComp> utilizadores = olz.getUtilizadores();
	set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();

	while(it != utilizadores.end()){
		if((*it)->getEmail() == email)
			return true;
		it++;
	}

	return false;
}

/**OPTION 3
 * @brief delete a user, asking for this email.
 * The function can throw an exception if the email introduced can´t be founded
 */
void apagarUtilizador(OLZ& olz){
	while(1){
		string emailUtilizador = leEmaiDoUtilizador();

		if(!emailExiste(emailUtilizador,olz)){
			cout << "Utilizador com email " << emailUtilizador << " nao foi encontrado.\n";
			cout << "Por favor, tente de novo com outro email.\n";
		}
		else{
			olz.apagarUtilizador_SeusAnuncios_Contactos_E_Informacoes(emailUtilizador);
			cout << "Utilizador eliminado com sucesso.\n";
			return;
		}
	}
}

/**
 * @brief asking for email of user, and return this email
 *
 * @return email email of user
 */
string leEmaiDoUtilizador(){
	string email;
	cout << "Email do utilizador que quer apagar: ";
	getline(cin, email);

	return email;
}

/**OPTION 4
 * @brief show ads by category
 */
void mostrarAnunciosPorCategoria(const OLZ& olz){
	string categoria, tipoDeAnuncios;
	vector<Anuncio*> anunciosParaImprimir;

	mostrarCategorias(olz);
	cout << "Introduza a categoria(o nome) do anuncio de entre estas: ";
	getline(cin,categoria);

	while(1){
		cout << "Ver:\n";
		cout << "1 -> Anuncios de Venda\n";
		cout << "2 -> Anuncios de compra\n";
		getline(cin, tipoDeAnuncios);

		if(tipoDeAnuncios == "1"){
			vector<DeVenda*> anunVendas = olz.getAnunciosDeVenda();
			for(size_t i = 0;i < anunVendas.size();i++){
				if(anunVendas[i]->getCategoria() == categoria)
					anunciosParaImprimir.push_back(anunVendas[i]);
			}
			break;
		}
		else if(tipoDeAnuncios == "2"){
			vector<DeCompra*> anunCompras = olz.getAnunciosDeCompra();
			for(size_t i = 0;i < anunCompras.size();i++){
				if(anunCompras[i]->getCategoria() == categoria)
					anunciosParaImprimir.push_back(anunCompras[i]);
			}
			break;
		}
		else{
			avisarOpcaoInvalida();
		}
	}

	imprimirAnunciosEncontrados(anunciosParaImprimir);

}

/**
 * @brief receive a vector of ads and print him
 */
void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados){
	for(unsigned int i = 0;i< anunciosEncontrados.size();i++){
		anunciosEncontrados[i]->imprime();
		cout << endl << "/--------------------------------------------\n";
	}

	if(anunciosEncontrados.size() == 0)
		cout << "Nao foi encontrado nenhum anuncio.\n";
}

/**OPTION 5
 * @brief show ads by location
 */
void mostrarAnunciosPorLocalizacaoDoAnunciante(const OLZ& olz){
	int opcao = 0;
	do{
		cout << "Procurar anuncios por:\n";
		cout << "\t1 - Freguesia do anunciante\n";
		cout << "\t2 - Concelho do anunciante\n";
		cout << "\t3 - Distrito do anunciante\n";
		cin >> opcao;
		cin.ignore();

		if(isOpcaoInvalida(opcao,1,3))
			avisarOpcaoInvalida();
	}while(isOpcaoInvalida(opcao,1,3));

	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	vector<Anuncio*> anunciosEncontrados;
	string local;
	if(opcao == 1){
		cout << "Introduza a freguesia: ";
		getline(cin,local);
	}
	else if(opcao == 2){
		cout << "Introduza o concelho: ";
		getline(cin, local);
	}
	else if(opcao == 3){
		cout << "Introduza o distrito: ";
		getline(cin,local);
	}

	for(unsigned int i = 0;i< anuncios.size();i++)
		if(opcao == 1){
			if(anuncios[i]->getAnunciante()->getLocalizacao().getFreguesia() == local)
				anunciosEncontrados.push_back(anuncios[i]);
		}
		else if(opcao == 2){
			if(anuncios[i]->getAnunciante()->getLocalizacao().getConcelho() == local)
				anunciosEncontrados.push_back(anuncios[i]);
		}
		else
			if(anuncios[i]->getAnunciante()->getLocalizacao().getDistrito() == local)
				anunciosEncontrados.push_back(anuncios[i]);

	imprimirAnunciosEncontrados(anunciosEncontrados);
}

/**OPTION 6
 * @brief show ads by keyword
 */
void mostrarAnunciosPorPalavraChave(const OLZ& olz){
	string palavraChave;
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	vector<Anuncio*> anunciosEncontrados;

	cout << "Introduz a palavra chave: ";
	getline(cin, palavraChave);

	for(unsigned int i = 0;i < anuncios.size();i++)
		if(anuncios[i]->procuraPalavraChave(palavraChave))
			anunciosEncontrados.push_back(anuncios[i]);

	imprimirAnunciosEncontrados(anunciosEncontrados);
}

/**OPTION 7
 * @brief show ads by approximate price
 */
void mostrarAnunciosPorPrecoAproximado(const OLZ& olz){
	float preco_min, preco_max;
	vector<DeVenda*> anunciosVenda = olz.getAnunciosDeVenda();
	vector<Anuncio*> anunciosEncontrados;

	cout << "Introduza um intervalo de preco\n";
	cout << "Preco minimo: ";
	cin >> preco_min;
	cin.ignore();
	cout << "Preco maximo: ";
	cin >> preco_max;
	cin.ignore();

	for(unsigned int i = 0;i < anunciosVenda.size();i++)
		if(anunciosVenda[i]->getPreco() >= preco_min && anunciosVenda[i]->getPreco() <= preco_max)
			anunciosEncontrados.push_back(anunciosVenda[i]);

	imprimirAnunciosEncontrados(anunciosEncontrados);
}

/**OPTION  8
 * @brief add a seller ad
 */
void adicionarAnuncioDeVenda(OLZ& olz){
	DeVenda* novoAnuncio = criarAnuncioVenda(olz);
	olz.adicionarAnuncioVenda(novoAnuncio);
}

DeVenda* criarAnuncioVenda(const OLZ& olz){
	string titulo,categoria,descricao;
	vector<string> imagens;
	int id;
	float preco;
	Estado estado;
	bool negociacao, showEmail, showNome, showNumTel;
	Data data;
	Utilizador* anunciante = NULL;

	cout << "Introduza o email do utilizador: ";
	anunciante = leUtilizadorAtravesDoEmail(olz);
	cout << "Introduza o titulo do anuncio: ";
	getline(cin,titulo);

	mostrarCategorias(olz);
	cout << "Introduza a categoria(o nome) do anuncio de entre estas: ";
	categoria = leCategoria(olz);

	cout << "Introduza a descricao do anuncio: ";
	getline(cin, descricao);

	cout << "Imagens do anuncio: ('N' - nao tem mais imagens)\n";
	imagens = leImagens();

	id = Anuncio::getIdentificadorInicial();
	Anuncio::setIdentificadorInicial(id+1);

	cout << "Introduza o preco do anuncio:\n";
	cin >> preco;
	cin.ignore();

	cout << "Introduza o estado do produto: (NOVO/USADO/FUNCIONAL/PARA PECAS)\n";
	estado = leEstadoDoProduto();

	cout << "Esta disponivel para negociar: y-sim n-nao\n";
	negociacao = leResposta();

	cout << "Pretende mostrar o email no anuncio: y-sim n-nao\n";
	showEmail = leResposta();

	cout << "Pretende mostrar o nome no anuncio: y-sim n-nao\n";
	showNome = leResposta();

	cout << "Pretende mostrar o numero de telemovel no anuncio: y-sim n-nao\n";
	showNumTel = leResposta();

	cout << "Introduza a data de hoje: (exemplo: '4 11 215', dia mes ano)\n";

	data = leData();

	return new DeVenda(titulo,categoria,descricao,imagens,
			id,estado,preco,negociacao,data,anunciante
			,0,showEmail,showNome,showNumTel,false);
}

/**OPTION 9
 * @brief add a want ad
 */
void adicionarAnuncioDeCompra(OLZ& olz){
	DeCompra* novoAnuncio = criarAnuncioCompra(olz);
	olz.adicionarAnuncioCompra(novoAnuncio);
}

DeCompra* criarAnuncioCompra(const OLZ& olz){
	string titulo,categoria,descricao;
	vector<string> imagens;
	int id;
	int trocaId = 0;
	bool troca, showEmail, showNome, showNumTel;
	Data data;
	Utilizador* anunciante = NULL;

	cout << "Introduza o email do anunciante:\n";
	anunciante = leUtilizadorAtravesDoEmail(olz);

	cout << "Introduza o titulo do anuncio:\n";
	getline(cin,titulo);
	mostrarCategorias(olz);

	cout << "Introduza a categoria(o nome) do anuncio de entre estas: ";
	categoria = leCategoria(olz);

	cout << "Introduza a descricao do anuncio:\n";
	getline(cin, descricao);

	cout << "Imagens do anuncio: ('N' - nao tem mais imagens)\n";
	imagens = leImagens();

	id = Anuncio::getIdentificadorInicial();
	Anuncio::setIdentificadorInicial(id+1);

	cout << "Esta disponivel para troca: y-sim n-nao\n";
	troca = leResposta();
	if (troca){
		cout << "Introduza o id do anuncio de venda do utilizador\n";
		trocaId = leIdDoAnuncioDeVendaParaTroca(anunciante, olz);
	}

	cout << "Pretende mostrar o email no anuncio: y-sim n-nao\n";
	showEmail = leResposta();

	cout << "Pretende mostrar o nome no anuncio: y-sim n-nao\n";
	showNome = leResposta();

	cout << "Pretende mostrar o numero de telemovel no anuncio: y-sim n-nao\n";
	showNumTel = leResposta();

	cout << "Introduza a data de hoje: (exemplo: '4 11 215', dia mes ano)\n";
	data = leData();

	return new DeCompra(titulo,categoria,descricao,imagens,
			id,troca,trocaId,data,anunciante
			,0,showEmail,showNome,showNumTel,false);
}

int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz){
	int idTroca;
	while(1){
		cout << "Id do anuncio de Venda: ";
		cin >> idTroca;
		cin.ignore();
		vector<DeVenda*> anunciosDeVenda = olz.getAnunciosDeVenda();
		for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
			if(anunciosDeVenda[i]->getId() == idTroca && anunciante->getEmail() == anunciosDeVenda[i]->getAnunciante()->getEmail())
				return idTroca;
		cout << "Id nao encontrado, tente de novo.\n";
	}
}

/**OPTION 10
 * @brief show a ad, asking for id
 */
void verAnuncio(const OLZ& olz){
	int id;
	Anuncio* anuncio = NULL;

	while(1){
		cout << "Introduz o id do anuncio que quer ver: ";
		cin >> id;
		cin.ignore();

		anuncio = encontraAnuncioAtravesDoId(olz,id);

		if(anuncio != NULL)
			break;
		else
			cout << "Anuncio nao encontrado, tente de novo com outro id.\n";
	}

	anuncio->imprime();
}

/**OPTION 11
 * @brief delete a ad, asking for id
 */
void apagarAnuncio(OLZ& olz){
	int id;
	Anuncio* anuncio = NULL;

	while(1){
		cout << "Introduza o id do anuncio que quer apagar:";
		cin >> id;
		cin.ignore();

		anuncio = encontraAnuncioAtravesDoId(olz,id);

		if(anuncio != NULL)
			break;
		else
			cout << "Anuncio nao encontrado, tente de novo com outro id.\n";
	}
	apagarAnuncioEncontradoEseusContactos(id,olz);
}

/**OPTION 12
 * @brief add a contact between two users
 */
void adicionarContacto(OLZ& olz){
	Contacto* novoContacto = criarContactoEntreDoisUtilizadores(olz);
	olz.adicionarContacto(novoContacto);
}

Contacto* criarContactoEntreDoisUtilizadores(const OLZ& olz){
	Utilizador* anunciante = NULL;
	Utilizador* pessoaInt = NULL;
	string mensagem, numTel_pessoaInt;
	Anuncio* anuncio = NULL;
	int id;

	cout << "Introduza o email da pessoa interessada:";
	pessoaInt = leUtilizadorAtravesDoEmail(olz);

	cout << "Introduza o id do anuncio:";
	while(1){
		cin >> id;
		cin.ignore();

		anuncio = encontraAnuncioAtravesDoId(olz, id);

		if (anuncio != NULL){
			anunciante = anuncio->getAnunciante();
			break;
		}
		else
			cout << "Anuncio nao encontrado, tente de novo com outro id.\n";
	}

	cout << "Mensagem da pessoa interessada para a o anunciante:\n";
	getline(cin, mensagem);

	numTel_pessoaInt = pessoaInt->getContacto();

	return new Contacto(anunciante,pessoaInt,anuncio,mensagem,numTel_pessoaInt);
}

/**OPTION 13
 * @brief concretize a business between two users. the ad
 * associated to that business is deleted, as well the contacts
 * associated.
 */
void concretizarNegocio(OLZ& olz){
	Anuncio* anuncio = NULL;
	Utilizador* anunciante = NULL;
	Utilizador* pessoaInt = NULL;
	Contacto* contacto = NULL;
	vector<Contacto*> contactos = olz.getContactos();
	float montanteNegociado;
	int id_anuncio;

	while (1){
		cout << "Introduza o id do anuncio: ";
		cin >> id_anuncio;
		cin.ignore();
		anuncio = encontraAnuncioAtravesDoId(olz, id_anuncio);
		if (anuncio != NULL)
			break;
		else
			cout << "Nao foi possivel encontrar o anuncio, tente de novo com outro id.\n";
	}

	cout << "Email do anunciante:\n";
	anunciante = leUtilizadorAtravesDoEmail(olz);

	cout << "Email da pessoa interessada:\n";
	pessoaInt = leUtilizadorAtravesDoEmail(olz);

	while(1){

		for(unsigned int i = 0;i < contactos.size();i++){
			if(contactos[i]->getAnunciante() != NULL && contactos[i]->getPessoaInteressada() != NULL)
				if(contactos[i]->getAnunciante()->getEmail() == anunciante->getEmail()
						&& contactos[i]->getPessoaInteressada()->getEmail() == pessoaInt->getEmail()
						&& contactos[i]->getAnuncio()->getId() == anuncio->getId())

					contacto = contactos[i];
		}

		if(contacto != NULL)
			break;
		else{
			cout << "Erro encontrado:\n";
			cout << "Nao existe contacto entre os utilizadores inseridos em relacao ao anuncio.\n";
			return;
		}
	}

	cout << "Introduza o montante negociado:";
	cin >> montanteNegociado;
	cin.ignore();

	cout << "Introduza a data de negociacai: (exemplo: '4/11/215', dia/mes/ano)\n";
	Data data = leData();

	NegocioConcretizado* negocio = contacto->concretizaNegocio(montanteNegociado,data);
	olz.adicionarNegocio(negocio);
	olz.incNegociosEatualizaDataUltimoNegocioDeUtilizador(anunciante->getEmail(), data);

	apagarAnuncioEncontradoEseusContactos(id_anuncio, olz);
}

/**OPTION 14
 * @brief print all concretized business
 */
void mostrarNegociosConcretizados(OLZ& olz){
	tabHNegociosConcretizados negocios = olz.getNegociosConcretizados();
	tabHNegociosConcretizados::const_iterator it  = negocios.begin();

	while(it != negocios.end()){
		(*it)->imprimeNegocioConcretizado();
		cout << endl << "/--------------------------------------------\n";
		it++;
	}

	if(negocios.empty())
		cout << "Nao foram encontrados negocios concretizados.\n";
}

/**OPTION 15
 * @brief print concretized business within a certain category
 */
void mostrarNCPorCategoria(const OLZ& olz){
	string categoria;
	tabHNegociosConcretizados negocios = olz.getNegociosConcretizados();

	mostrarCategorias(olz);
	cout << "Introduza a categoria(o nome) do anuncio de entre estas: ";
	getline(cin,categoria);


	int negociosImprimidos = 0;
	for(iteratorHNegociosConcretizados it = negocios.begin(); it != negocios.end();it++)
		if((*it)->getCategoria() == categoria){
			(*it)->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImprimidos++;
		}

	if(negociosImprimidos == 0)
		cout << "Nao foram encontrados negocios dessa categoria.\n";

}

/**OPTION 16
 * @brief print concretized business with a certain advertiser
 */
void mostrarNCPorAnunciante(const OLZ& olz){
	Utilizador* anunciante = NULL;
	tabHNegociosConcretizados negocios = olz.getNegociosConcretizados();

	cout << "Introduza o email do anunciante:";
	anunciante = leUtilizadorAtravesDoEmail(olz);

	int negociosImprimidos = 0;
	for(iteratorHNegociosConcretizados it = negocios.begin(); it != negocios.end();it++)
		if((*it)->getAnunciante() == anunciante){
			(*it)->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImprimidos++;
		}

	if(negociosImprimidos == 0)
		cout << "Nao foram encontrados negocios desse anunciante.\n";
}

/**OPTION 17
 * @brief print concretized business with a certain buyer
 */
void mostrarNCPorComprador(const OLZ& olz){
	Utilizador* PessoaInt = NULL;
	tabHNegociosConcretizados negocios = olz.getNegociosConcretizados();

	cout << "Introduza o email da pessoa interessada:";
	PessoaInt = leUtilizadorAtravesDoEmail(olz);

	int negociosImprimidos = 0;
	for(iteratorHNegociosConcretizados it = negocios.begin(); it != negocios.end();it++)
		if((*it)->getPessoaInteressada() == PessoaInt){
			(*it)->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImprimidos++;
		}

	if(negociosImprimidos == 0)
		cout << "Nao foram encontrados negocios dessa pessoa comprador.\n";
}

/**OPTION 18
 * @brief print concretized business within a certain price range
 */
void mostrarNCPorPreco(const OLZ& olz){
	float preco_min, preco_max;
	tabHNegociosConcretizados negocios = olz.getNegociosConcretizados();

	cout << "Introduza um intervalo de preco\n";
	cout << "Preco minimo: ";
	cin >> preco_min;
	cin.ignore();
	cout << "Preco maximo: ";
	cin >> preco_max;
	cin.ignore();

	int negociosImprimidos = 0;
	for(iteratorHNegociosConcretizados it = negocios.begin(); it != negocios.end();it++)
		if((*it)->getMontanteNegociado() >= preco_min || (*it)->getMontanteNegociado() <= preco_max){
			(*it)->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImprimidos++;
		}

	if(negociosImprimidos == 0)
		cout << "Nao foram encontrados negocios dessa gama de precos.\n";
}

/**OPTION 19
 * @brief just print all contacts
 */
void mostrarContactos(OLZ& olz){
	vector<Contacto*> contactos = olz.getContactos();

	for(unsigned int i = 0;i< contactos.size();i++){
		contactos[i]->imprimeContacto();
		cout << endl << "/--------------------------------------------\n";
	}
	if(contactos.empty())
		cout << "Nao foram encontrados contactos.\n";
}

/**OPTION 20
 * @brief show all categories that exit
 */
void mostrarCategorias(const OLZ& olz){
	vector<string> categorias = olz.getCategorias();
	cout << "Categorias:\n";
	for(unsigned int i = 0;i < categorias.size();i++)
		cout << "\t" << categorias[i] << endl;
}

/**OPTION 21
 * @print ads ordered by populariry
 */
void mostrarAnunciosMaisPopulares(const OLZ& olz){
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	sort(anuncios.begin(),anuncios.end(),ordenaPorVisualizacoes); // ordem decrescente
	imprimirAnunciosEncontrados(anuncios);
}

bool ordenaPorVisualizacoes(Anuncio* a1, Anuncio* a2){
	return a1->getVisualizacoes() > a2->getVisualizacoes(); // ordem decrescente
}



/**************************************
 * OTHER FUNCTIONS USED IN SOME CASES *
 **************************************/

void apagarAnuncioEncontradoEseusContactos(int id_anuncio, OLZ& olz){
	vector<DeVenda*> anunciosDeVenda = olz.getAnunciosDeVenda();
	vector<DeCompra*> anunciosDeCompra = olz.getAnunciosDeCompra();

	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		if(anunciosDeVenda[i]->getId() == id_anuncio){
			olz.apagarAnuncioDeVendaESeusContactos(id_anuncio);
			return;
		}

	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
		if(anunciosDeCompra[i]->getId() == id_anuncio){
			olz.apagarAnuncioDeCompraESeusContactos(id_anuncio);
			return;
		}
}

Anuncio* encontraAnuncioAtravesDoId(const OLZ& olz,int id){
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	for(unsigned int i = 0;i < anuncios.size();i++)
		if(anuncios[i]->getId() == id){
			return anuncios[i];
		}
	return NULL;
}

bool isOpcaoInvalida(int opcao, int inf, int sup){
	if(opcao < inf || opcao > sup)
		return true;
	else
		return false;
}


Utilizador* leUtilizadorAtravesDoEmail(const OLZ& olz){
	Utilizador* anunciante = NULL;
	while(1){
		string email;
		getline(cin,email);
		try{
			anunciante = encontraUtilizadorAtravesDoEmail(olz, email);
		}
		catch(ExceptionUtilizadorNaoExistente& e){
			cout << "Nao existe um utilizador com o email: " << e.getEmail() << "." << endl;
			cout << "Tente de novo...\n";
		}
		if(anunciante != NULL)
			break;
	}
	return anunciante;
}

vector<string> leImagens(){
	string imagem;
	vector<string> imagens;
	while(1){
		getline(cin,imagem);
		if(imagem == "N")
			break;
		else
			imagens.push_back(imagem);
	}
	return imagens;
}

string leCategoria(const OLZ& olz){
	string categoria;
	while(1){
		getline(cin,categoria);
		if(existeCategoria(olz,categoria))
			return categoria;
	}
}

Data leData(){
	Data data;
	while(1){
		try{
			if (!(cin >> data)){
				cout << "Erro na data! Tente de novo. ";
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			else
				cin.ignore();
		}catch(ExceptionDataInvalida& dInv){
			cout << dInv.dado << " " << dInv.valor << " invalido, tente de novo.\n";
			continue;
		}
		return data;
	}
}

bool leResposta(){
	string resposta;
	while(1){
		getline(cin, resposta);
		if(resposta == "y")
			return true;
		else if(resposta == "n")
			return false;
		else
			cout << "Opcao invalida, tente de novo.\n";
	}
}

Estado leEstadoDoProduto(){
	Estado estado;
	string estadoString;
	while(1){
		getline(cin, estadoString);
		if(estadoString == "NOVO"){
			estado = NOVO;
			return estado;
		}
		else if(estadoString == "USADO"){
			estado = USADO;
			return estado;
		}
		else if(estadoString == "FUNCIONAL"){
			estado = FUNCIONAL;
			return estado;
		}
		else if(estadoString == "PARA PECAS"){
			estado = PECAS;
			return estado;
		}
		else
			cout << "Estado invalido, tente de novo.\n";
	}
}

bool existeCategoria(const OLZ& olz,string categoria){
	vector<string> categorias = olz.getCategorias();
	try{
		for(unsigned int i = 0;i < categorias.size();i++)
			if(categorias[i] == categoria)
				return true;
		throw ExceptionCategoriaInexistente(categoria);
	}
	catch(ExceptionCategoriaInexistente& c){
		cout << "Nao existe categoria chamada: " << c.getCategoria() << endl;
		return false;
	}
}

Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz, string email){
	Utilizador* utilizador = NULL;
	set<Utilizador*, userPtrComp> utilizadores = olz.getUtilizadores();
	set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();

	while (it != utilizadores.end()){
		if ((*it)->getEmail() == email){
			utilizador = *it;
			break;
		}
		it++;
	}
	if(utilizador == NULL)
		throw ExceptionUtilizadorNaoExistente(email);
	else
		return utilizador;
}

/**
 * @brief warning the user that the option previously chosen is invalid
 */
void avisarOpcaoInvalida(){
	cout << "Opcao invalida, tente de novo.\n";
}
