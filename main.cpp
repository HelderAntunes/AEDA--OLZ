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
DeVenda* CriarAnuncioVenda(const OLZ& olz);
DeCompra* CriaAnuncioCompra(const OLZ& olz);
Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz);
bool existeCategoria(const OLZ& olz,string categoria);
Estado leEstadoDoProduto();
bool leResposta();
Data leData();
string leCategoria(const OLZ& olz);
vector<string> leImagens();
int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz);
void verAnuncio(const OLZ& olz);


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
		else if(opcao == 8){
			DeVenda* novoAnuncio = CriarAnuncioVenda(olz);
			olz.adicionarAnuncioVenda(novoAnuncio);
		}
		else if(opcao == 9){
			DeCompra* novoAnuncio = CriaAnuncioCompra(olz);
			olz.adicionarAnuncioCompra(novoAnuncio);
		}
		else if(opcao == 10){
			verAnuncio(olz);
		}
	}


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

void verAnuncio(const OLZ& olz){
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	int id;
	while(1){
		cout << "Introduz o id do anuncio que quer ver:";
		cin >> id;
		for(unsigned int i = 0;i < anuncios.size();i++)
			if(anuncios[i]->getId() == id){
				anuncios[i]->imprime();
				return;
			}
		cout << "Anuncio nao encontrado, tente com outro id.\n";
	}
}

void mostrarAnunciosPorCategoria(const OLZ& olz){
	string categoria;
	cout << "Introduza uma categoria: ";
	cin >> categoria;
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	int anunciosImprimidos = 0;
	for(unsigned int i = 0;i < anuncios.size();i++)
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
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getFreguesia() == freguesia)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 2){
		string concelho;
		cout << "Introduza a concelho a procurar: "; cin >> concelho;
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getConcelho() == concelho)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 3){
		string distrito;
		cout << "Introduza a distrito a procurar: "; cin >> distrito;
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getDistrito() == distrito)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
}

void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados){
	for(unsigned int i = 0;i< anunciosEncontrados.size();i++)
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
	for(unsigned int i = 0;i < anuncios.size();i++)
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
	for(unsigned int i = 0;i < anunciosVenda.size();i++)
		if(anunciosVenda[i]->getPreco() >= preco_min && anunciosVenda[i]->getPreco() <= preco_max)
			anunciosEncontrados.push_back(anunciosVenda[i]);
	vector<Anuncio*> anunciosParaImprimir;
	for(unsigned int i = 0;i< anunciosEncontrados.size();i++)
		anunciosParaImprimir.push_back(anunciosEncontrados[i]);
	imprimirAnunciosEncontrados(anunciosParaImprimir);
}

DeVenda* CriarAnuncioVenda(const OLZ& olz){
	string titulo,categoria,descricao;
	vector<string> imagens;
	int id, visualizacoes;
	float preco;
	Estado estado;
	bool negociacao, showEmail, showNome, showNumTel;
	Data data;
	Utilizador* anunciante = NULL;
	while(1){
		anunciante = encontraUtilizadorAtravesDoEmail(olz);
		if(anunciante != NULL)
			break;
	}
	cout << "Introduza o titulo do anuncio: ";
	cin.ignore();
	getline(cin,titulo);
	cout << "Introduza a categoria do anuncio: ";
	categoria = leCategoria(olz);
	cout << "Introduza a descricao do anuncio: ";
	cin >> descricao;
	cout << "Imagens do anuncio: ('N' - nao tem mais imagens)\n";
	imagens = leImagens();
	id = Anuncio::getIdentificadorInicial();
	Anuncio::setIdentificadorInicial(id+1);
	visualizacoes = 0;
	cout << "Introduza o preco do anuncio: ";
	cin >> preco;
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
			,visualizacoes,showEmail,showNome,showNumTel);
}

DeCompra* CriaAnuncioCompra(const OLZ& olz){
		string titulo,categoria,descricao;
		vector<string> imagens;
		int id, visualizacoes, trocaId;
		bool troca, showEmail, showNome, showNumTel;
		Data data;
		Utilizador* anunciante = NULL;
		while(1){
			anunciante = encontraUtilizadorAtravesDoEmail(olz);
			if(anunciante != NULL)
				break;
		}
		cout << "Introduza o titulo do anuncio: ";
		cin.ignore();
		getline(cin,titulo);
		cout << "Introduza a categoria do anuncio: ";
		categoria = leCategoria(olz);
		cout << "Introduza a descricao do anuncio: ";
		cin >> descricao;
		cout << "Imagens do anuncio: ('N' - nao tem mais imagens)\n";
		imagens = leImagens();
		id = Anuncio::getIdentificadorInicial();
		Anuncio::setIdentificadorInicial(id+1);
		visualizacoes = 0;
		cout << "Esta disponivel para troca: y-sim n-nao\n";
		troca = leResposta();
		cout << "Introduza o id do anuncio de venda do utilizador\n";
		trocaId = leIdDoAnuncioDeVendaParaTroca(anunciante, olz);
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
				,visualizacoes,showEmail,showNome,showNumTel);
}

int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz){
	int idTroca;
	while(1){
		cout << "Id do anuncio de Venda: ";
		cin >> idTroca;
		vector<DeVenda*> anunciosDeVenda = olz.getAnunciosDeVenda();
		for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
			if(anunciosDeVenda[i]->getId() == idTroca && anunciante->getEmail() == anunciosDeVenda[i]->getAnunciante()->getEmail())
				return idTroca;
		cout << "Id nao encontrado, tente de novo.\n";
	}
}

vector<string> leImagens(){
	string imagem;
	vector<string> imagens;
	while(1){
		cin >> imagem;
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
		cin.ignore();
		getline(cin,categoria);
		if(existeCategoria(olz,categoria))
			return categoria;
	}
}

Data leData(){
	int dia, mes, ano;
	while(1){
		try{
			cin >> dia >> mes >> ano;
			Data d(dia, mes, ano);
		}catch(DataInvalida& dInv){
			cout << dInv.dado << "(" << dInv.valor << ")" << " invalido, tente de novo.\n";
			continue;
		}
		return Data(dia,mes,ano);
	}
}

bool leResposta(){
	string resposta;
	while(1){
		cin >> resposta;
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
		cin >> estadoString;
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

Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz){
	Utilizador* utilizador = NULL;
	string email;
	try{
		cout << "Introduza o email do utilizador: ";
		cin >> email;
		vector<Utilizador*> utilizadores = olz.getUtilizadores();
		for(unsigned int i = 0;i < utilizadores.size();i++)
			if(utilizadores[i]->getEmail() == email){
				utilizador = utilizadores[i];
				break;
			}
		if(utilizador == NULL)
			throw ExceptionUtilizadorNaoExistente(email);
	}
	catch(ExceptionUtilizadorNaoExistente& e){
		cout << "Nao existe um utilizador com o email: " << e.getEmail() << endl;
	}
	return utilizador;
}


