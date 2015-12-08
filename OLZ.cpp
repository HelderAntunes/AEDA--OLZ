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
/*	for(unsigned int i = 0;i < utilizadores.size();i++)
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
	contactos.clear();*/
}

/**
 * @brief read data from a file
 * @param istream& olz_file
 */
void OLZ::leTodosOsDados(istream& olz_file){
/*	leUtilizadores_e_respetivosAnuncios(olz_file);
	int static_id_anuncio_inicial;
	olz_file >> static_id_anuncio_inicial;
	Anuncio::setIdentificadorInicial(static_id_anuncio_inicial);
	categorias = leCategorias(olz_file);
	leContactos(olz_file);*/
}

/**
 * @brief read the contatcs from a file
 * @param istream& olz_file
 */
void OLZ::leContactos(istream& olz_file){
/*	olz_file.ignore();
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
	}*/
}

/**
 * @brief read users and their ads from a file
 * @param istream& olz_file
 */
void OLZ::leUtilizadores_e_respetivosAnuncios(istream& olz_file){
/*	string utilizadores_inicio;
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
	}*/
}

/**
 * @brief read selling ads from a file
 * @param istream& olz_file
 */
void OLZ::leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
/*	string anunciosDeVenda_inicio;
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
	}*/
}

/**
 * @brief read want ads from a file
 * @param istream& olz_file
 */
void OLZ::leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
/*	string anunciosDeCompra_inicio;
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
	}*/
}



/**
 * @brief add a user to a vector of users
 * @param Utilizador* novoUtilizador)
 */
/*void OLZ::adicionarUtilizador(Utilizador* novoUtilizador){
	utilizadores.push_back(novoUtilizador);
}*/

/**
 * @brief add a seller add to a vector of seller adds
 * @param DeVenda* novoAnuncio
 */
/*
void OLZ::adicionarAnuncioVenda(DeVenda* novoAnuncio){
	anunciosDeVenda.push_back(novoAnuncio);
}
*/

/**
 * @brief add a want add to a vector of want adds
 * @param DeCompra* novoAnuncio
 */
/*void OLZ::adicionarAnuncioCompra(DeCompra* novoAnuncio){

}*/

/**
 * @brief delete a seller add of vector of seller adds
 * @param int id of seller add
 */
/*void OLZ::apagarAnuncioVenda(int id){

}*/

/**
 * @brief delete a want add of vector of seller adds
 * @param int id of want add
 */
/*void OLZ::apagarAnuncioCompra(int id){

}*/

/**
 * @brief add new contact between two users
 * Contacto* novoContacto
 */
/*void OLZ::adicionarContacto(Contacto* novoContacto){

}*/


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
/*void OLZ::apagarUtilizador(string email){

}*/

/**
 * @brief get all adds that exists
 */
/*vector<Anuncio*> OLZ::getAnunciosDeVendaEdeCompra() const{

}*/

/**
 * @brief get all seller adds that exists
 * @return vector<DeVenda*> anunciosDeVenda
 */
/*vector<DeVenda*> OLZ::getAnunciosDeVenda() const{

}*/

/**
 * @brief get all want adds that exists
 * @return vector<DeCompra*> anunciosDeCompra
 */
/*vector<DeCompra*> OLZ::getAnunciosDeCompra() const{

}*/

/**
 * @brief get all users that exists
 * @return vector<Utilizador*> utilizadores
 */
/*
set<Utilizador*> OLZ::getUtilizadores() const{
	return utilizadores;
}
*/

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
	//...
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
	olz_file >> data;
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
	olz_file >> data;
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

