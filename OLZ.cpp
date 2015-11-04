/*
 * OLZ.cpp
 *
 *  Created on: 01/11/2015
 *      Author: Asus
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

OLZ::OLZ() {}

OLZ::~OLZ() {
	for(int i = 0;i < utilizadores.size();i++)
		delete utilizadores[i];
	for(int i = 0;i < anunciosDeCompra.size();i++)
		delete anunciosDeCompra[i];
	for(int i = 0;i < anunciosDeVenda.size();i++)
		delete anunciosDeVenda[i];
}

void OLZ::leTodosOsDados(istream& olz_file){
	leUtilizadores_e_respetivosAnuncios(olz_file);
	int static_id_anuncio_inicial;
	olz_file >> static_id_anuncio_inicial;
	Anuncio::setIdentificadorInicial(static_id_anuncio_inicial);
}

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

void OLZ::imprimeTodosOsDados(){
	imprimeUtilizadores();
	cout << endl;
	imprimeAnunciosDeVenda();
	cout << endl;
	imprimeAnunciosDeCompra();
	cout << endl;
}

void OLZ::imprimeUtilizadores(){
	for(int i = 0;i < utilizadores.size();i++)
		cout << (*utilizadores[i]) << endl;
}

void OLZ::imprimeAnunciosDeVenda(){
	for(int i = 0;i < anunciosDeVenda.size();i++)
		anunciosDeVenda[i]->imprime();
}

void OLZ::imprimeAnunciosDeCompra(){
	for(int i = 0;i < anunciosDeCompra.size();i++)
		anunciosDeCompra[i]->imprime();
}

void OLZ::adicionarUtilizador(Utilizador* novoUtilizador){
	utilizadores.push_back(novoUtilizador);
}


void OLZ::adicionarAnuncioVenda(DeVenda* novoAnuncio){
	anunciosDeVenda.push_back(novoAnuncio);
}

void OLZ::adicionarAnuncioCompra(DeCompra* novoAnuncio){
	anunciosDeCompra.push_back(novoAnuncio);
}

void OLZ::apagarAnuncioVenda(int id){
	for(int i = 0;i < anunciosDeVenda.size();i++)
		if(anunciosDeVenda[i]->getId() == id){
			// all the contactos stay with anuncio pointer equal to NULL
			for(int j = 0;j < contactos.size();j++)
				if(contactos[j]->getAnuncio()->getId() == id)
					contactos[j]->setAnuncioPtr_toNull();
			anunciosDeVenda.erase(anunciosDeVenda.begin()+i);
			break;
		}
}

void OLZ::apagarAnuncioCompra(int id){
	for(int i = 0;i < anunciosDeCompra.size();i++)
			if(anunciosDeCompra[i]->getId() == id){
				// all the contactos stay with anuncio pointer equal to NULL
				for(int j = 0;j < contactos.size();j++)
					if(contactos[j]->getAnuncio()->getId() == id)
						contactos[j]->setAnuncioPtr_toNull();
				anunciosDeCompra.erase(anunciosDeCompra.begin()+i);
				break;
			}
}

void OLZ::adicionarContacto(Contacto* novoContacto){
	contactos.push_back(novoContacto);
}

void OLZ::mostrarContactos(){
	for(int i = 0;i < contactos.size();i++)
		contactos[i]->imprimeContacto();
}

void OLZ::mostrarNegociosConcretizados(){
	for(int i = 0;i < contactos.size();i++)
		if(contactos[i]->negocioEstaConcretizado())
			contactos[i]->imprimeNegocioConcretizado();
}

vector<Anuncio*> OLZ::getAnunciosDeVendaEdeCompra() const{
	vector<Anuncio*> anuncios;
	for(int i = 0;i < anunciosDeVenda.size();i++)
		anuncios.push_back(anunciosDeVenda[i]);
	for(int i = 0;i < anunciosDeCompra.size();i++)
		anuncios.push_back(anunciosDeCompra[i]);
	return anuncios;
}

vector<Contacto*> OLZ::getContactos() const{
	return contactos;
}

void OLZ::apagarUtilizador(string email){
	for(int i = 0;i < utilizadores.size();i++)
		if(utilizadores[i]->getEmail() == email){
			//todos os anuncios do utilizador serao apagados
			for(int j = 0;j < anunciosDeVenda.size();j++)
				if(anunciosDeVenda[j]->getAnunciante()->getEmail() == email){
					int id_anuncio = anunciosDeVenda[j]->getId();
					this->apagarAnuncioVenda(id_anuncio);
					j--;
				}
			for(int j = 0;j < anunciosDeCompra.size();j++)
				if(anunciosDeCompra[j]->getAnunciante()->getEmail() == email){
					int id_anuncio = anunciosDeCompra[j]->getId();
					this->apagarAnuncioCompra(id_anuncio);
					j--;
				}
			// Os contactos nao serao apagados,mas quando
			// existir um apontador(anunciante ou pessoa interessada)
			// referente a este utilizador, esse apontador vai ser posto
			// a NULL
			for(int j = 0;j < contactos.size();j++)
				if(contactos[j]->getAnunciante()->getEmail() == email)
					contactos[j]->setAnunciantePtr_toNull();
				else if(contactos[j]->getPessoaInteressada()->getEmail() == email)
					contactos[j]->setPessoaInteressadaPtr_toNull();

			utilizadores.erase(utilizadores.begin()+i);
			break;
		}
}

vector<DeVenda*> OLZ::getAnunciosDeVenda() const{
	return anunciosDeVenda;
}

vector<DeCompra*> OLZ::getAnunciosDeCompra() const{
	return anunciosDeCompra;
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

vector<Utilizador*> OLZ::getUtilizadores() const{
	return utilizadores;
}

vector<string> OLZ::getCategorias() const{
	return categorias;
}
