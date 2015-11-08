/*
 * OLZ.cpp
 *
 *  Created on: 01/11/2015
 *      Author: Helder Antunes
 */

#include "OLZ.h"

/*
 * Funções auxiliares
 */
Utilizador* leUtilizador(istream& olz_file);
DeVenda* leAnuncioDeVenda(istream& olz_file);
Data leDataDoAnuncio(istream& olz_file);
vector<string> leImagensDoAnuncio(istream& olz_file);
Estado leEstadoDoProdutoDoAnuncio(istream& olz_file);
DeCompra* leAnuncioDeCompra(istream& olz_file);
vector<string> leCategorias(istream& olz_file);

/**
 * @brief constructor of OLZ
 */
OLZ::OLZ() {}

/**
 * @brief destructor of OLZ, delete memory dynamic allocation
 */
OLZ::~OLZ() {
	for(unsigned int i = 0;i < utilizadores.size();i++)
		delete utilizadores[i];
	utilizadores.clear();
	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
		delete anunciosDeCompra[i];
	anunciosDeCompra.clear();
	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		delete anunciosDeVenda[i];
	anunciosDeVenda.clear();
	for(unsigned int i = 0;i < contactos.size();i++)
		delete contactos[i];
	contactos.clear();
}

/**
 * @brief read data from a file
 * @param istream& olz_file
 */
void OLZ::leTodosOsDados(istream& olz_file){
	leUtilizadores_e_respetivosAnuncios(olz_file);
	int static_id_anuncio_inicial;
	olz_file >> static_id_anuncio_inicial;
	Anuncio::setIdentificadorInicial(static_id_anuncio_inicial);
	categorias = leCategorias(olz_file);
	leContactos(olz_file);
}

/**
 * @brief read the contatcs from a file
 * @param istream& olz_file
 */
void OLZ::leContactos(istream& olz_file){
	olz_file.ignore();
	string inicioContactos;
	olz_file >> inicioContactos;
	while(1){
		string inidicadorNovoContacto;
		olz_file >> inidicadorNovoContacto;
		if(inidicadorNovoContacto == "NOVO_CONTACTO"){
			string emailAnunciante, emailPessoaInt;
			Utilizador* anunciante = NULL;
			Utilizador* pessoaInt = NULL;
			olz_file >> emailAnunciante;
			olz_file >> emailPessoaInt;
			for(unsigned int i = 0;i < utilizadores.size();i++)
				if(utilizadores[i]->getEmail() == emailAnunciante){
					anunciante = utilizadores[i];
					break;
				}
			for(unsigned int i = 0;i< utilizadores.size();i++)
				if(utilizadores[i]->getEmail() == emailPessoaInt){
					pessoaInt = utilizadores[i];
					break;
				}

			int id_anuncio;
			olz_file >> id_anuncio;
			Anuncio* anuncio = NULL;
			vector<Anuncio*> anuncios = this->getAnunciosDeVendaEdeCompra();
			for(unsigned int i = 0;i< anuncios.size();i++)
				if(anuncios[i]->getId() == id_anuncio){
					anuncio = anuncios[i];
					break;
				}
			string mensagem;
			olz_file.ignore();
			getline(olz_file, mensagem);
			string numTel_pessoaInt;
			getline(olz_file, numTel_pessoaInt);
			Contacto* novoContacto = new Contacto(anunciante,pessoaInt,anuncio,mensagem,numTel_pessoaInt);
			bool concretizado;
			olz_file >> concretizado;
			float montanteNegociado;
			olz_file >> montanteNegociado;
			Data data;
			olz_file >> data;
			if(concretizado)
				novoContacto->concretizaNegocio(montanteNegociado,data);

			contactos.push_back(novoContacto);
		}
		else if(inidicadorNovoContacto == "FIM_CONTACTOS")
			break;
	}
}

/**
 * @brief read users and their ads from a file
 * @param istream& olz_file
 */
void OLZ::leUtilizadores_e_respetivosAnuncios(istream& olz_file){
	string utilizadores_inicio;
	olz_file >> utilizadores_inicio;
	while(1){
		string indicadorNovoUtilizador;
		olz_file >> indicadorNovoUtilizador;
		if(indicadorNovoUtilizador == "NOVO_UTILIZADOR"){
			olz_file.ignore();
			Utilizador* utilizador = leUtilizador(olz_file);
			utilizadores.push_back(utilizador);
			leAnunciosDeVendaDeUmUtilizador(olz_file, utilizador);
			leAnunciosDeCompraDeUmUtilizador(olz_file, utilizador);
		}
		else if(indicadorNovoUtilizador == "FIM_UTILIZADORES")
			break;
	}
}

/**
 * @brief read selling ads from a file
 * @param istream& olz_file
 */
void OLZ::leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
	string anunciosDeVenda_inicio;
	olz_file >> anunciosDeVenda_inicio;
	while(1){
		string indicadorNovoAnuncio;
		olz_file >> indicadorNovoAnuncio;
		if(indicadorNovoAnuncio == "NOVO_ANUNCIO"){
			olz_file.ignore();
			DeVenda* anuncioVenda = leAnuncioDeVenda(olz_file);
			anuncioVenda->setAnunciantePtr(anunciante);
			anunciosDeVenda.push_back(anuncioVenda);
		}
		else if(indicadorNovoAnuncio == "FIM_ANUNCIOS_VENDA")
			break;
	}
}

/**
 * @brief read want ads from a file
 * @param istream& olz_file
 */
void OLZ::leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
	string anunciosDeCompra_inicio;
	olz_file >> anunciosDeCompra_inicio;
	while(1){
		string indicadorNovoAnuncio;
		olz_file >> indicadorNovoAnuncio;
		if(indicadorNovoAnuncio == "NOVO_ANUNCIO"){
			olz_file.ignore();
			DeCompra* anuncioCompra = leAnuncioDeCompra(olz_file);
			anuncioCompra->setAnunciantePtr(anunciante);
			anunciosDeCompra.push_back(anuncioCompra);
		}
		else if(indicadorNovoAnuncio == "FIM_ANUNCIOS_COMPRA")
			break;
	}
}


/**
 * @brief prints the information of existent users
 */
void OLZ::imprimeUtilizadores(){
	for(unsigned int i = 0;i < utilizadores.size();i++)
		cout << (*utilizadores[i]) << endl << "/--------------------------------------------\n";
	if(utilizadores.size() == 0)
		cout << "\nNenhum utilizador foi encontrado.\n";
}


/**
 * @brief add a user to a vector of users
 * @param Utilizador* novoUtilizador)
 */
void OLZ::adicionarUtilizador(Utilizador* novoUtilizador){
	utilizadores.push_back(novoUtilizador);
}

/**
 * @brief add a seller add to a vector of seller adds
 * @param DeVenda* novoAnuncio
 */
void OLZ::adicionarAnuncioVenda(DeVenda* novoAnuncio){
	anunciosDeVenda.push_back(novoAnuncio);
}

/**
 * @brief add a want add to a vector of want adds
 * @param DeCompra* novoAnuncio
 */
void OLZ::adicionarAnuncioCompra(DeCompra* novoAnuncio){
	anunciosDeCompra.push_back(novoAnuncio);
}

/**
 * @brief delete a seller add of vector of seller adds
 * @param int id of seller add
 */
void OLZ::apagarAnuncioVenda(int id){
	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		if(anunciosDeVenda[i]->getId() == id){
			// all the contactos stay with anuncio pointer equal to NULL
			for(unsigned int j = 0;j < contactos.size();j++)
				if(contactos[j]->getAnuncio() != NULL)
					if(contactos[j]->getAnuncio()->getId() == id)
						contactos[j]->setAnuncioPtr_toNull();
			anunciosDeVenda.erase(anunciosDeVenda.begin()+i);
			break;
		}
}

/**
 * @brief delete a want add of vector of seller adds
 * @param int id of want add
 */
void OLZ::apagarAnuncioCompra(int id){
	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
			if(anunciosDeCompra[i]->getId() == id){
				// all the contactos stay with anuncio pointer equal to NULL
				for(unsigned int j = 0;j < contactos.size();j++)
					if(contactos[j]->getAnuncio() != NULL)
						if(contactos[j]->getAnuncio()->getId() == id)
							contactos[j]->setAnuncioPtr_toNull();
				anunciosDeCompra.erase(anunciosDeCompra.begin()+i);
				break;
			}
}

/**
 * @brief add new contact between two users
 * Contacto* novoContacto
 */
void OLZ::adicionarContacto(Contacto* novoContacto){
	contactos.push_back(novoContacto);
}

/**
 * @brief print all contacts that exists
 */
void OLZ::mostrarContactos(){
	for(unsigned int i = 0;i < contactos.size();i++)
		contactos[i]->imprimeContacto();
}

/**
 * @brief get all adds that exists
 */
vector<Anuncio*> OLZ::getAnunciosDeVendaEdeCompra() const{
	vector<Anuncio*> anuncios;
	for(unsigned int i = 0;i < anunciosDeVenda.size();i++)
		anuncios.push_back(anunciosDeVenda[i]);
	for(unsigned int i = 0;i < anunciosDeCompra.size();i++)
		anuncios.push_back(anunciosDeCompra[i]);
	return anuncios;
}

/**
 * @brief get all contacts that exists
 * @return vector<Contacto*> contactos
 */
vector<Contacto*> OLZ::getContactos() const{
	return contactos;
}

/**
 * @delete a user
 * @param email´s user
 */
void OLZ::apagarUtilizador(string email){
	for(unsigned int i = 0;i < utilizadores.size();i++){
		if(utilizadores[i]->getEmail() == email){
			//todos os anuncios do utilizador serao apagados
			cout << "\nencontrou email\n";
			for(unsigned int j = 0;j < anunciosDeVenda.size();j++)
				if(anunciosDeVenda[j]->getAnunciante()->getEmail() == email){
					int id_anuncio = anunciosDeVenda[j]->getId();
					this->apagarAnuncioVenda(id_anuncio);
					j--;
				}
			cout << "apagou as vendas\n";
			for(unsigned int j = 0;j < anunciosDeCompra.size();j++)
				if(anunciosDeCompra[j]->getAnunciante()->getEmail() == email){
					int id_anuncio = anunciosDeCompra[j]->getId();
					this->apagarAnuncioCompra(id_anuncio);
					j--;
				}
			cout << "apagou as compras\n";
			// Os contactos nao serao apagados,mas quando
			// existir um apontador(anunciante ou pessoa interessada)
			// referente a este utilizador, esse apontador vai ser posto
			// a NULL
			for(unsigned int j = 0;j < contactos.size();j++){
				if(contactos[j]->getAnunciante() != NULL)
					if(contactos[j]->getAnunciante()->getEmail() == email)
						contactos[j]->setAnunciantePtr_toNull();

				if(contactos[j]->getPessoaInteressada() != NULL)
					if(contactos[j]->getPessoaInteressada()->getEmail() == email)
						contactos[j]->setPessoaInteressadaPtr_toNull();
			}

			cout << "apagou os contactos\n";
			utilizadores.erase(utilizadores.begin()+i);
			cout << "apagou o utilizador\n";
			return;
		}
	}

	throw ExceptionUtilizadorNaoExistente(email);
}

/**
 * @brief get all seller adds that exists
 * @return vector<DeVenda*> anunciosDeVenda
 */
vector<DeVenda*> OLZ::getAnunciosDeVenda() const{
	return anunciosDeVenda;
}

/**
 * @brief get all want adds that exists
 * @return vector<DeCompra*> anunciosDeCompra
 */
vector<DeCompra*> OLZ::getAnunciosDeCompra() const{
	return anunciosDeCompra;
}

/**
 * @brief get all users that exists
 * @return vector<Utilizador*> utilizadores
 */
vector<Utilizador*> OLZ::getUtilizadores() const{
	return utilizadores;
}

/**
 * @brief get all categorys that exists
 * @return vector<string> categorias
 */
vector<string> OLZ::getCategorias() const{
	return categorias;
}

/**
 * @brief save all data into a file
 * @para istream& olz_file
 */
void OLZ::salvarTodosOsDados(ostream& olz_file){
	olz_file << "INICIO_UTILIZADORES\n";
	for(unsigned int i = 0;i< utilizadores.size();i++){
		olz_file << "NOVO_UTILIZADOR\n";
		olz_file << utilizadores[i]->getNome() << endl;
		olz_file << utilizadores[i]->getEmail() << endl;
		olz_file << utilizadores[i]->getContacto() << endl;
		olz_file << utilizadores[i]->getLocalizacao().getFreguesia() << endl;
		olz_file << utilizadores[i]->getLocalizacao().getConcelho() << endl;
		olz_file << utilizadores[i]->getLocalizacao().getDistrito() << endl;

		olz_file << "INICIO_ANUNCIOS_VENDA\n";
		for(unsigned int j = 0;j < anunciosDeVenda.size();j++)
			if(anunciosDeVenda[j]->getAnunciante()->getEmail() == utilizadores[i]->getEmail()){
				olz_file << "NOVO_ANUNCIO\n";

				olz_file << anunciosDeVenda[j]->getTitulo() << endl;
				olz_file << anunciosDeVenda[j]->getCategoria() << endl;
				olz_file << anunciosDeVenda[j]->getDescricao() << endl;

				vector<string> imagens = anunciosDeVenda[j]->getImagens();
				olz_file << "Imagens\n";
				for(unsigned int k = 0; k < imagens.size();k++)
					olz_file << imagens[k]  << endl;
				olz_file << "FimImagens\n";

				olz_file << anunciosDeVenda[j]->getId() << endl;
				olz_file << anunciosDeVenda[j]->getData() << endl;
				olz_file << anunciosDeVenda[j]->getVisualizacoes() << endl;
				olz_file << anunciosDeVenda[j]->getShowEmail() << " " << anunciosDeVenda[j]->getShowNome()
								<< " " << anunciosDeVenda[j]->getShowNumTel() << endl;

				Estado estado = anunciosDeVenda[j]->getEstado();
				if(estado == NOVO)
					olz_file << "NOVO\n";
				else if(estado == USADO)
					olz_file << "USADO\n";
				else if(estado == FUNCIONAL)
					olz_file << "FUNCIONAL\n";
				else if(estado == PECAS)
					olz_file << "PECAS\n";

				olz_file << anunciosDeVenda[j]->getPreco() << endl;
				olz_file << anunciosDeVenda[j]->getNegociacao() << endl;
			}
		olz_file << "FIM_ANUNCIOS_VENDA\n";

		olz_file << "INICIO_ANUNCIOS_COMPRA\n";
		for(unsigned int j = 0;j < anunciosDeCompra.size();j++)
			if(anunciosDeCompra[j]->getAnunciante()->getEmail() == utilizadores[i]->getEmail()){
				olz_file << "NOVO_ANUNCIO\n";

				olz_file << anunciosDeCompra[j]->getTitulo() << endl;
				olz_file << anunciosDeCompra[j]->getCategoria() << endl;
				olz_file << anunciosDeCompra[j]->getDescricao() << endl;

				vector<string> imagens = anunciosDeCompra[j]->getImagens();
				olz_file << "Imagens\n";
				for(unsigned int k = 0; k < imagens.size();k++)
					olz_file << imagens[k]  << endl;
				olz_file << "FimImagens\n";

				olz_file << anunciosDeCompra[j]->getId() << endl;
				olz_file << anunciosDeCompra[j]->getData() << endl;
				olz_file << anunciosDeCompra[j]->getVisualizacoes() << endl;
				olz_file << anunciosDeCompra[j]->getShowEmail() << " " << anunciosDeCompra[j]->getShowNome()
												<< " " << anunciosDeCompra[j]->getShowNumTel() << endl;

				olz_file << anunciosDeCompra[j]->getTroca() << " " << anunciosDeCompra[j]->GetTrocaId() << endl;
			}
		olz_file << "FIM_ANUNCIOS_COMPRA\n";
	}
	olz_file << "FIM_UTILIZADORES\n";

	olz_file << Anuncio::getIdentificadorInicial() << endl;

	olz_file << "CATEGORIAS\n";
	for(unsigned int i = 0;i< categorias.size();i++)
		olz_file << categorias[i] << endl;
	olz_file << "FIM_CATEGORIAS\n";

	olz_file << "CONTACTOS\n";
	for(unsigned int i = 0;i < contactos.size();i++){
		olz_file << "NOVO_CONTACTO\n";

		if(contactos[i]->getAnunciante() != NULL)
			olz_file << contactos[i]->getAnunciante()->getEmail() << endl;
		else
			olz_file << "semEmail.pt\n";
		if(contactos[i]->getPessoaInteressada() != NULL)
			olz_file << contactos[i]->getPessoaInteressada()->getEmail() << endl;
		else
			olz_file << "semEmail.pt\n";

		if(contactos[i]->getAnuncio() != NULL)
			olz_file << contactos[i]->getAnuncio()->getId() << endl;
		else
			olz_file << -1 << endl;

		olz_file << contactos[i]->getMensagem() << endl;
		olz_file << contactos[i]->getNumTel_PessoaInt() << endl;
		olz_file << contactos[i]->negocioEstaConcretizado() << endl;
		olz_file << contactos[i]->getMontanteNegociado() << endl;
		olz_file << contactos[i]->getDataNegociada() << endl;
	}
	olz_file << "FIM_CONTACTOS\n";
}

/*
 * Funcoes auxiliares
 */

DeCompra* leAnuncioDeCompra(istream& olz_file){
	string lixo, titulo, categoria, descricao;
	vector<string> imagens;
	int visualizacoes, id, trocaId;
	bool showEmail, showNome, showNumTel, troca;
	Data data;
	getline(olz_file, titulo);
	getline(olz_file, categoria);
	getline(olz_file, descricao);
	imagens = leImagensDoAnuncio(olz_file);
	olz_file >> id;
	data = leDataDoAnuncio(olz_file);
	olz_file >> visualizacoes;
	olz_file >> showEmail >> showNome >> showNumTel;
	olz_file >> troca >> trocaId;
	DeCompra* deCompra_ptr = new DeCompra(titulo, categoria, descricao, imagens,id,troca,
			trocaId, data,NULL, visualizacoes,showEmail,
			showNome, showNumTel);
	return deCompra_ptr;
}

DeVenda* leAnuncioDeVenda(istream& olz_file){
	string lixo, titulo, categoria, descricao;
	vector<string> imagens;
	int visualizacoes, id;
	bool showEmail, showNome, showNumTel;
	Data data;
	Estado estado;
	float preco;
	bool negociacao;
	getline(olz_file, titulo);
	getline(olz_file, categoria);
	getline(olz_file, descricao);
	imagens = leImagensDoAnuncio(olz_file);
	olz_file >> id;
	data = leDataDoAnuncio(olz_file);
	olz_file >> visualizacoes;
	olz_file >> showEmail >> showNome >> showNumTel;
	estado = leEstadoDoProdutoDoAnuncio(olz_file);
	olz_file >> preco;
	olz_file >> negociacao;
	DeVenda* deVenda_ptr = new DeVenda(titulo, categoria, descricao, imagens,
			id, estado, preco, negociacao, data, NULL, visualizacoes,
			showEmail, showNome, showNumTel);
	return deVenda_ptr;
}

Utilizador* leUtilizador(istream& olz_file){
	string nome, email, numTel, freguesia, concelho, distrito;
	getline(olz_file, nome);
	getline(olz_file, email);
	getline(olz_file, numTel);
	getline(olz_file, freguesia);
	getline(olz_file, concelho);
	getline(olz_file, distrito);
	Utilizador* utilizador_ptr = new Utilizador(nome, email, numTel, freguesia, concelho, distrito);
	return utilizador_ptr;
}

Estado leEstadoDoProdutoDoAnuncio(istream& olz_file){
	Estado estado;
	string estado_string;
	olz_file >> estado_string;
	if(estado_string == "NOVO")
		estado = NOVO;
	else if(estado_string == "USADO")
		estado = USADO;
	else if(estado_string == "FUNCIONAL")
		estado = FUNCIONAL;
	else if(estado_string == "PECAS")
		estado = PECAS;
	return estado;
}

Data leDataDoAnuncio(istream& olz_file){
	int dia, mes, ano;
	olz_file >> dia;
	olz_file >> mes;
	olz_file >> ano;
	Data d(dia,mes,ano);
	return d;
}

vector<string> leImagensDoAnuncio(istream& olz_file){
	string imagem, lixo;
	vector<string> imagens;
	getline(olz_file, lixo);
	while(1){
		getline(olz_file,imagem);
		if(imagem == "FimImagens")
			break;
		else
			imagens.push_back(imagem);
	}
	return imagens;
}

vector<string> leCategorias(istream& olz_file){
	vector<string> categorias;
	string indicadorInicioCategorias;
	olz_file.ignore();
	olz_file >> indicadorInicioCategorias;
	while(1){
		string categoria;
		olz_file >> categoria;
		if(categoria == "FIM_CATEGORIAS")
			break;
		else
			categorias.push_back(categoria);
	}
	return categorias;
}

