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
Utilizador* criarUtilizador();
string pedeEmailDoUtilizadorQueQuerApagar();
void mostrarAnunciosPorCategoria(const OLZ& olz);
void mostrarAnunciosPorLocalizacaoDoAnunciante(const OLZ& olz);
void mostrarAnunciosPorPalavraChave(const OLZ& olz);
void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados);
void mostrarAnunciosPorPrecoAproximado(const OLZ& olz);
DeVenda* CriarAnuncioVenda(const OLZ& olz);
DeCompra* CriaAnuncioCompra(const OLZ& olz);
Utilizador* encontraUtilizadorAtravesDoEmail(const OLZ& olz, string email);
bool existeCategoria(const OLZ& olz,string categoria);
Estado leEstadoDoProduto();
bool leResposta();
Data leData();
string leCategoria(const OLZ& olz);
vector<string> leImagens();
int leIdDoAnuncioDeVendaParaTroca(Utilizador* anunciante,const OLZ& olz);
void verAnuncio(const OLZ& olz);
Contacto* criarContactoEntreDoisUtilizadores(const OLZ& olz);
Utilizador* leUtilizadorAtravesDoEmail(const OLZ& olz);
Anuncio* encontraAnuncioAtravesDoId(const OLZ& olz,int id);
void apagarAnuncio(OLZ& olz);
void concretizarNegocio(OLZ& olz);
void mostrarNegociosConcretizados(OLZ& olz);
void mostrarContactos(OLZ& olz);
void mostrarCategorias(OLZ& olz);
void apagarUtilizador(OLZ& olz);
void apagarAnuncioEncontrado(int id_anuncio, OLZ& olz);



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
	while(1){
		mostrarMenuPrincipal();
		cin >> opcao;
		cin.ignore();
		if(isOpcaoInvalida(opcao, 1, 17) == true){
			cout << "Opcao invalida\n\n";
			continue;
		}
		if(opcao == 1)
			olz.imprimeUtilizadores();
		else if(opcao == 2){
			Utilizador* novoUtil = criarUtilizador();
			olz.adicionarUtilizador(novoUtil);
		}
		else if(opcao == 3)
			apagarUtilizador(olz);
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
		else if(opcao == 10)
			verAnuncio(olz);
		else if(opcao == 11)
			apagarAnuncio(olz);
		else if(opcao == 12){
			Contacto* novoContacto = criarContactoEntreDoisUtilizadores(olz);
			olz.adicionarContacto(novoContacto);
		}
		else if(opcao == 13)
			concretizarNegocio(olz);
		else if(opcao == 14)
			mostrarNegociosConcretizados(olz);
		else if(opcao == 15)
			mostrarContactos(olz);
		else if(opcao == 16)
			mostrarCategorias(olz);
		else
			break;
		cout << "\n\nPrime a tecla enter para continuar.\n";
		cin.get();
	}
	ofstream olzFile("OLZ-file.txt");
	olz.salvarTodosOsDados(olzFile);
	olzFile.close();
	return 0;
}

void apagarUtilizador(OLZ& olz){
	while(1){
		try{
			string email = pedeEmailDoUtilizadorQueQuerApagar();
			olz.apagarUtilizador(email);
		}
		catch(ExceptionUtilizadorNaoExistente& u){
			cout << "Utilizador com email " << u.getEmail() << " nao foi encontrado.\n";
			cout << "Tente de novo com outro email.\n";
			continue;
		}
		cout << "Utilizador eliminado com sucesso.\n";
		break;
	}
}

void mostrarCategorias(OLZ& olz){
	vector<string> categorias = olz.getCategorias();
	cout << "Categorias:\n";
	for(unsigned int i = 0;i < categorias.size();i++)
		cout << i+1 << " - " << categorias[i] << endl;
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
			"\t15 - Mostrar contactos\n"
			"\t16 - Mostrar categorias\n"
			"\t17 - Sair da aplicacao\n";
	cout << endl;
	cout << "Opcao: ";
	return;
}

void mostrarContactos(OLZ& olz){
	vector<Contacto*> contactos = olz.getContactos();
	int negociosImpri = 0;
	for(unsigned int i = 0;i< contactos.size();i++)
		if(contactos[i]->negocioEstaConcretizado()){
			contactos[i]->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImpri++;
		}
		else{
			contactos[i]->imprimeContacto();
			cout << endl << "/--------------------------------------------\n";
			negociosImpri++;
		}
	if(negociosImpri == 0)
		cout << "Nao foram encontrados negocios concretizados.\n";
}

void mostrarNegociosConcretizados(OLZ& olz){
	vector<Contacto*> contactos = olz.getContactos();
	int negociosImpri = 0;
	for(unsigned int i = 0;i< contactos.size();i++)
		if(contactos[i]->negocioEstaConcretizado()){
			contactos[i]->imprimeNegocioConcretizado();
			cout << endl << "/--------------------------------------------\n";
			negociosImpri++;
		}
	if(negociosImpri == 0)
		cout << "Nao foram encontrados negocios concretizados.\n";
}
void apagarAnuncioEncontrado(int id_anuncio, OLZ& olz){
	vector<DeVenda*> anunciosDeVenda = olz.getAnunciosDeVenda();
	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		if(anunciosDeVenda[i]->getId() == id_anuncio){
			olz.apagarAnuncioVenda(id_anuncio);
			return;
		}

	vector<DeCompra*> anunciosDeCompra = olz.getAnunciosDeCompra();
	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
		if(anunciosDeCompra[i]->getId() == id_anuncio){
			olz.apagarAnuncioCompra(id_anuncio);
			return;
		}
}

void concretizarNegocio(OLZ& olz){
	Anuncio* anuncio = NULL;
	Utilizador* anunciante = NULL;
	Utilizador* pessoaInt = NULL;
	Contacto* contacto = NULL;
	int id;
	while(1){
		cout << "Introduza o id do anuncio: ";
		while(1){
			cin >> id;
			cin.ignore();
			anuncio = encontraAnuncioAtravesDoId(olz,id);
			if(anuncio != NULL)
				break;
			else
				cout << "Nao foi possivel encontrar o anuncio, tente de novo com outro id.\n";
		}

		cout << "Introduza o email do anunciante:";
		anunciante = leUtilizadorAtravesDoEmail(olz);
		cout << "Introduza o email da pessoa interessada:";
		pessoaInt = leUtilizadorAtravesDoEmail(olz);
		vector<Contacto*> contactos = olz.getContactos();

		for(unsigned int i = 0;i < contactos.size();i++)
			if(contactos[i]->getAnunciante()->getEmail() == anunciante->getEmail()
					&& contactos[i]->getPessoaInteressada()->getEmail() == pessoaInt->getEmail()
					&& contactos[i]->getAnuncio()->getId() == anuncio->getId())
				contacto = contactos[i];
		if(contacto != NULL)
			break;
		else
			cout << "Contacto nao encontrado, tente de novo.\n";
	}
	cout << "Introduza o montante negociado:";
	int montanteNegociado;
	cin >> montanteNegociado;
	cin.ignore();
	cout << "Introduza a data de negociacai: (exemplo: '4 11 215', dia mes ano)\n";
	Data data = leData();
	contacto->concretizaNegocio(montanteNegociado,data);
	apagarAnuncioEncontrado(id, olz);
}

void apagarAnuncio(OLZ& olz){
	int id;
	Anuncio* anuncio = NULL;
	cout << "Introduza o id do anuncio que quer apagar:";
	while(1){
		cin >> id;
		cin.ignore();
		anuncio = encontraAnuncioAtravesDoId(olz,id);
		if(anuncio != NULL)
			break;
		else
			cout << "Anuncio nao encontrado, tente de novo com outro id.\n";
	}
	apagarAnuncioEncontrado(id,olz);
}


Contacto* criarContactoEntreDoisUtilizadores(const OLZ& olz){
	Utilizador* anunciante = NULL;
	Utilizador* pessoaInt = NULL;
	string mensagem, numTel_pessoaInt;
	Anuncio* anuncio = NULL;
	cout << "Introduza o email do anunciante:";
	anunciante = leUtilizadorAtravesDoEmail(olz);
	cout << "Introduza o email da pessoa interessada:";
	pessoaInt = leUtilizadorAtravesDoEmail(olz);
	cout << "Introduza o id do anuncio:";
	int id;
	while(1){
		cin >> id;
		cin.ignore();
		anuncio = encontraAnuncioAtravesDoId(olz, id);
		if(anuncio != NULL)
			break;
		else
			cout << "Anuncio nao encontrado, tente de novo com outro id.\n";
	}
	cout << "Mensagem da pessoa interessada para a o anunciante:\n";
	getline(cin, mensagem);
	numTel_pessoaInt = pessoaInt->getContacto();
	return new Contacto(anunciante,pessoaInt,anuncio,mensagem,numTel_pessoaInt);
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

Utilizador* criarUtilizador(){
	string nome, email, contacto;
	string freguesia, concelho, distrito;
	cout << "Nome do utilizador: ";
	getline(cin,nome);
	cout << "Email do Utilizador: ";
	getline(cin, email);
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

string pedeEmailDoUtilizadorQueQuerApagar(){
	string email;
	cout << "Email do utilizador que quer apagar:";
	cin >> email;
	cin.ignore();
	return email;
}

void verAnuncio(const OLZ& olz){
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	int id;
	while(1){
		cout << "Introduz o id do anuncio que quer ver:";
		cin >> id;
		cin.ignore();
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
	cin.ignore();
	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	int anunciosImprimidos = 0;
	for(unsigned int i = 0;i < anuncios.size();i++)
		if(anuncios[i]->getCategoria() == categoria){
			anuncios[i]->imprime();
			cout << endl << "/--------------------------------------------\n";
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
		cin.ignore();
		if(isOpcaoInvalida(opcao,1,3))
			cout << "Opcao invalida\n\n";
	}while(isOpcaoInvalida(opcao,1,3));

	vector<Anuncio*> anuncios = olz.getAnunciosDeVendaEdeCompra();
	vector<Anuncio*> anunciosEncontrados;

	if(opcao == 1){
		string freguesia;
		cout << "Introduza a freguesia a procurar: ";
		getline(cin,freguesia);
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getFreguesia() == freguesia)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 2){
		string concelho;
		cout << "Introduza a concelho a procurar: ";
		getline(cin, concelho);
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getConcelho() == concelho)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
	else if(opcao == 3){
		string distrito;
		cout << "Introduza a distrito a procurar: ";
		getline(cin,distrito);
		for(unsigned int i = 0;i< anuncios.size();i++)
			if(anuncios[i]->getAnunciante()->getLocalizacao().getDistrito() == distrito)
				anunciosEncontrados.push_back(anuncios[i]);
		imprimirAnunciosEncontrados(anunciosEncontrados);
	}
}

void imprimirAnunciosEncontrados(const vector<Anuncio*>& anunciosEncontrados){
	for(unsigned int i = 0;i< anunciosEncontrados.size();i++){
		anunciosEncontrados[i]->imprime();
		cout << endl << "/--------------------------------------------\n";
	}

	if(anunciosEncontrados.size() == 0)
		cout << "Nao foi encontrado nenhum anuncio com a distrito indicada.\n";
}

void mostrarAnunciosPorPalavraChave(const OLZ& olz){
	string palavraChave;
	cout << "Introduz a palavra chave:";
	cin >> palavraChave;
	cin.ignore();
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
	cin.ignore();
	cout << "Preco maximo: ";
	cin >> preco_max;
	cin.ignore();
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

	anunciante = leUtilizadorAtravesDoEmail(olz);
	cout << "Introduza o titulo do anuncio:";
	getline(cin,titulo);
	cout << "Introduza a categoria do anuncio:";
	categoria = leCategoria(olz);
	cout << "Introduza a descricao do anuncio:";
	getline(cin, descricao);
	cout << "Imagens do anuncio: ('N' - nao tem mais imagens)";
	imagens = leImagens();
	id = Anuncio::getIdentificadorInicial();
	Anuncio::setIdentificadorInicial(id+1);
	visualizacoes = 0;
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
			,visualizacoes,showEmail,showNome,showNumTel);
}

Utilizador* leUtilizadorAtravesDoEmail(const OLZ& olz){
	Utilizador* anunciante = NULL;
	while(1){
		cout << "Introduza o email do anunciante: ";
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

DeCompra* CriaAnuncioCompra(const OLZ& olz){
	string titulo,categoria,descricao;
	vector<string> imagens;
	int id, visualizacoes, trocaId;
	bool troca, showEmail, showNome, showNumTel;
	Data data;
	Utilizador* anunciante = NULL;
	cout << "Introduza o email do anunciante:\n";
	anunciante = leUtilizadorAtravesDoEmail(olz);
	cout << "Introduza o titulo do anuncio:\n";
	getline(cin,titulo);
	cout << "Introduza a categoria do anuncio:\n";
	categoria = leCategoria(olz);
	cout << "Introduza a descricao do anuncio:\n";
	getline(cin, descricao);
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
		cin.ignore();
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
	int dia, mes, ano;
	while(1){
		try{
			cin >> dia >> mes >> ano;
			cin.ignore();
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
		cin.ignore();
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
		cin.ignore();
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
	vector<Utilizador*> utilizadores = olz.getUtilizadores();
	for(unsigned int i = 0;i < utilizadores.size();i++)
		if(utilizadores[i]->getEmail() == email){
			utilizador = utilizadores[i];
			break;
		}
	if(utilizador == NULL)
		throw ExceptionUtilizadorNaoExistente(email);
	else
		return utilizador;
}


