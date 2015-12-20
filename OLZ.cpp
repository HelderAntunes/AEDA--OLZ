/*
 * OLZ.cpp
 *
 *  Created on: 01/11/2015
 *      Author: Helder Antunes
 */

#include "OLZ.h"
#include <algorithm>

/*
 * Funções auxiliares
 */
Utilizador* leUtilizador(istream& olz_file);
DeVenda* leAnuncioDeVenda(istream& olz_file);
Data leDataDoAnuncio(istream& olz_file);
vector<string> leImagensDoAnuncio(istream& olz_file);
Estado leEstadoDoProdutoDoAnuncio(istream& olz_file);
DeCompra* leAnuncioDeCompra(istream& olz_file);
DeVenda* leAnuncioDeVenda(istream& olz_file);
vector<string> leCategorias(istream& olz_file);
bool ordenarPorDestaque(Anuncio* left, Anuncio* right);

/**
 * @brief constructor of OLZ
 */
OLZ::OLZ() {}

/**
 * @brief destructor of OLZ, delete memory dynamic allocation
 */
OLZ::~OLZ() {

	set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();
	while(it != utilizadores.end()){
		delete(*it);
		it++;
	}
	utilizadores.clear();

	while(!anunciosDeCompra.empty()){
		delete anunciosDeCompra.top();
		anunciosDeCompra.pop();
	}

	while(!anunciosDeVenda.empty()){
		delete anunciosDeVenda.top();
		anunciosDeVenda.pop();
	}

	for(unsigned int i = 0;i < contactos.size();i++)
		delete contactos[i];
	contactos.clear();

	iteratorHNegociosConcretizados it2 = negociosConcretizados.begin();
	while(it2 != negociosConcretizados.end()){
		delete(*it2);
		it2++;
	}
	negociosConcretizados.clear();

}

void OLZ::adicionarUtilizador(Utilizador* novoUtilizador){
	utilizadores.insert(novoUtilizador);
}

void OLZ::adicionarAnuncioVenda(DeVenda* novoAnuncio){
	anunciosDeVenda.push(novoAnuncio);
}

void OLZ::adicionarAnuncioCompra(DeCompra* novoAnuncio){
	anunciosDeCompra.push(novoAnuncio);
}

void OLZ::adicionarContacto(Contacto* novoContacto){
	contactos.push_back(novoContacto);
}

void OLZ::adicionarNegocio(NegocioConcretizado* novoNegocio){
	negociosConcretizados.insert(novoNegocio);
}

void OLZ::apagarAnuncioDeCompra(int id_anuncio){
	priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> aux;

	while(!anunciosDeCompra.empty()){

		DeCompra* anuncio = anunciosDeCompra.top();
		anunciosDeCompra.pop();

		if(anuncio->getId() != id_anuncio)
			aux.push(anuncio);
		else
			delete(anuncio);

	}

	anunciosDeCompra = aux;
}

void OLZ::apagarAnuncioDeVenda(int id_anuncio){
	priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > aux;

	while(!anunciosDeVenda.empty()){

		DeVenda* anuncio = anunciosDeVenda.top();
		anunciosDeVenda.pop();

		if(anuncio->getId() != id_anuncio)
			aux.push(anuncio);
		else
			delete(anuncio);
	}

	anunciosDeVenda = aux;
}

void OLZ::apagarAnunciosDeUmUtilizador(string emailUtilizador){
	vector<DeVenda*> anunVenda = getAnunciosDeVenda();
	vector<DeCompra*> anunCompra = getAnunciosDeCompra();

	for(size_t i = 0;anunVenda.size();i++)
		if(anunVenda[i]->getAnunciante()->getEmail() == emailUtilizador){
			int id_anuncio = anunVenda[i]->getId();
			apagarAnuncioDeVenda(id_anuncio);
		}

	for(size_t i = 0;anunCompra.size();i++)
		if(anunCompra[i]->getAnunciante()->getEmail() == emailUtilizador){
			int id_anuncio = anunCompra[i]->getId();
			apagarAnuncioDeCompra(id_anuncio);
		}

}

void OLZ::apagarInformacoesDoUtilizadorEmNegociosConcretizados(string emailUtilizador){
	iteratorHNegociosConcretizados i = negociosConcretizados.begin();

	while(i != negociosConcretizados.end()){
		if((*i)->getAnunciante() != NULL){
			if((*i)->getAnunciante()->getEmail() == emailUtilizador)
				(*i)->setAnunciantePtr_toNull();
		}

		if((*i)->getPessoaInteressada() != NULL)
			if((*i)->getPessoaInteressada()->getEmail() == emailUtilizador)
				(*i)->setPessoaInteressadaPtr_toNull();
	}

}

void OLZ::apagarUtilizador(string emailUtilizador){
	set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();

	while(it != utilizadores.end()){

		if((*it)->getEmail() == emailUtilizador){
			utilizadores.erase(it);
			break;
		}
	}
}

void OLZ::apagarContactosAssociados_A_Anuncio(int id_anuncio){
	for(size_t i = 0;i < contactos.size();i++){
		if(contactos[i]->getAnuncio()->getId() == id_anuncio){
			delete(contactos[i]);
			contactos.erase(contactos.begin() + i);
			i--;
		}
	}
}

void OLZ::apagarAnuncioDeVendaESeusContactos(int id_anuncio){
	apagarContactosAssociados_A_Anuncio(id_anuncio);
	apagarAnuncioDeVenda(id_anuncio);
}

void OLZ::apagarAnuncioDeCompraESeusContactos(int id_anuncio){
	apagarContactosAssociados_A_Anuncio(id_anuncio);
	apagarAnuncioDeCompra(id_anuncio);
}

void OLZ::apagarUtilizador_SeusAnuncios_Contactos_E_Informacoes(string emailUtilizador){
	apagarUtilizador(emailUtilizador);
	apagarAnunciosDeUmUtilizador(emailUtilizador);
	apagarContactosDeUmUtilizador(emailUtilizador);
	apagarInformacoesDoUtilizadorEmNegociosConcretizados(emailUtilizador);
}

void OLZ::apagarContactosDeUmUtilizador(string emailUtilizador){
	for(size_t i = 0;i < contactos.size();i++){

		string emailAnunciante = contactos[i]->getAnunciante()->getEmail();
		string emailInteressado = contactos[i]->getPessoaInteressada()->getEmail();

		if(emailAnunciante == emailUtilizador || emailAnunciante == emailUtilizador){
			delete(contactos[i]);
			contactos.erase(contactos.begin()+i);
			i--;
		}
	}
}

tabHNegociosConcretizados OLZ::getNegociosConcretizados() const{
	return negociosConcretizados;
}

vector<Contacto*> OLZ::getContactos() const{
	return contactos;
}

vector<Anuncio*> OLZ::getAnunciosDeVendaEdeCompra() const{
	vector<Anuncio*> res;

	vector<DeVenda*> anunVenda = getAnunciosDeVenda();
	vector<DeCompra*> anunCompra = getAnunciosDeCompra();

	res.insert(res.begin(),anunVenda.begin(),anunVenda.end());
	res.insert(res.begin(),anunCompra.begin(),anunCompra.end());

	sort(res.begin(),res.end(),ordenarPorDestaque);

	return res;
}

bool ordenarPorDestaque(Anuncio* left, Anuncio* right){
	if(left->anuncioTemDestaque() && !right->anuncioTemDestaque())
		return true;

	else if(!left->anuncioTemDestaque() && right->anuncioTemDestaque())
		return false;

	else
		return left->getData() < right->getData();
}

vector<DeVenda*> OLZ::getAnunciosDeVenda() const{
	vector<DeVenda*> res;
	priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > aux = anunciosDeVenda;

	while(!aux.empty()){
		DeVenda* anuncio = aux.top();
		aux.pop();
		res.push_back(anuncio);
	}

	return res;
}

vector<DeCompra*> OLZ::getAnunciosDeCompra() const{
	vector<DeCompra*> res;
	priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> aux = anunciosDeCompra;

	while(!aux.empty()){
		DeCompra* anuncio = aux.top();
		aux.pop();
		res.push_back(anuncio);
	}

	return res;
}

set<Utilizador*, userPtrComp> OLZ::getUtilizadores() const{
	return utilizadores;
}

vector<string> OLZ::getCategorias() const{
	return categorias;
}

void OLZ::salvarTodosOsDados(ostream& olz_file){
	olz_file << "INICIO_UTILIZADORES\n";
	for (set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin(); it != utilizadores.end(); ++it) {
		olz_file << "NOVO_UTILIZADOR\n";
		olz_file << (*it)->getNome() << endl;
		olz_file << (*it)->getEmail() << endl;
		olz_file << (*it)->getContacto() << endl;
		olz_file << (*it)->getLocalizacao().getFreguesia() << endl;
		olz_file << (*it)->getLocalizacao().getConcelho() << endl;
		olz_file << (*it)->getLocalizacao().getDistrito() << endl;

		olz_file << "INICIO_ANUNCIOS_VENDA\n";
		priority_queue<DeVenda*, vector<DeVenda*>, menorPorDestaque_AVenda > venda = anunciosDeVenda;
		while(!venda.empty()){
			DeVenda* anuncio = venda.top();
			if(anuncio->getAnunciante() == *it){
				olz_file << "NOVO_ANUNCIO\n";
				olz_file << *anuncio;
			}
			venda.pop();
		}
		olz_file << "FIM_ANUNCIOS_VENDA\n";

		olz_file << "INICIO_ANUNCIOS_COMPRA\n";
		priority_queue<DeCompra*, vector<DeCompra*>, menorPorDestaque_ACompra> compra = anunciosDeCompra;
		while(!compra.empty()){
			DeCompra* anuncio = compra.top();
			if(anuncio->getAnunciante() == *it){
				olz_file << "NOVO_ANUNCIO\n";
				olz_file << *anuncio;
			}
			compra.pop();
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
	for (unsigned int i = 0; i < contactos.size(); ++i){
		olz_file << "NOVO_CONTACTO\n";
		olz_file << (*contactos[i]);
	}
	olz_file << "FIM_CONTACTOS\n";

	olz_file << "NEGOCIOS\n";
	tabHNegociosConcretizados::const_iterator it  = negociosConcretizados.begin();
	while(it != negociosConcretizados.end()){
		olz_file << "NOVO_NEGOCIO\n";
		olz_file << *(*it);
		it++;
	}
	olz_file << "FIM_NEGOCIOS\n";
}

void OLZ::leTodosOsDados(istream& olz_file){
	leUtilizadores_e_respetivosAnuncios(olz_file);
	int static_id_anuncio_inicial;
	olz_file >> static_id_anuncio_inicial;
	Anuncio::setIdentificadorInicial(static_id_anuncio_inicial);
	categorias = leCategorias(olz_file);
	leContactos(olz_file);
	leNegocios(olz_file);
}

void OLZ::leNegocios(istream& olz_file){
	olz_file.ignore();
	string inicioNegocios;
	olz_file >> inicioNegocios;

	while(1){
		string inidicadorNovoNegocio;
		olz_file >> inidicadorNovoNegocio;

		if(inidicadorNovoNegocio == "NOVO_NEGOCIO"){
			Data data;
			string emailAnunciante, emailPessoaInt;
			Utilizador* anunciante = NULL;
			Utilizador* pessoaInt = NULL;
			string descricaoAnuncio;
			float montanteNegociado;
			string mensagem;
			string categoria;

			olz_file >> data;

			olz_file >> emailAnunciante;
			olz_file >> emailPessoaInt;

			set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();
			while(it != utilizadores.end()){
				string emailUtil = (*it)->getEmail();

				if(emailUtil == emailAnunciante)
					anunciante = (*it);
				if(emailUtil == emailPessoaInt)
					pessoaInt = (*it);

				it++;
			}

			olz_file.ignore();
			getline(olz_file,descricaoAnuncio);

			olz_file >> montanteNegociado;

			olz_file.ignore();
			getline(olz_file, mensagem);

			getline(olz_file, categoria);

			NegocioConcretizado* novoNegocio = new NegocioConcretizado(data,anunciante,pessoaInt,descricaoAnuncio,
																		montanteNegociado,mensagem,categoria);

			adicionarNegocio(novoNegocio);;
		}
		else if(inidicadorNovoNegocio == "FIM_NEGOCIOS")
			break;
	}
}

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
			int id_anuncio;
			Anuncio* anuncio = NULL;
			string mensagem;
			string numTel_pessoaInt;



			olz_file >> emailAnunciante;
			olz_file >> emailPessoaInt;

			set<Utilizador*, userPtrComp>::iterator it = utilizadores.begin();
			while(it != utilizadores.end()){
				string emailUtil = (*it)->getEmail();

				if(emailUtil == emailAnunciante)
					anunciante = (*it);
				if(emailUtil == emailPessoaInt)
					pessoaInt = (*it);

				it++;
			}

			olz_file >> id_anuncio;
			vector<Anuncio*> anuncios = this->getAnunciosDeVendaEdeCompra();
			for(unsigned int i = 0;i< anuncios.size();i++)
				if(anuncios[i]->getId() == id_anuncio){
					anuncio = anuncios[i];
					break;
				}

			olz_file.ignore();
			getline(olz_file, mensagem);

			getline(olz_file, numTel_pessoaInt);

			Contacto* novoContacto = new Contacto(anunciante,pessoaInt,anuncio,mensagem,numTel_pessoaInt);

			adicionarContacto(novoContacto);
		}
		else if(inidicadorNovoContacto == "FIM_CONTACTOS")
			break;
	}
}

void OLZ::leUtilizadores_e_respetivosAnuncios(istream& olz_file){
	string utilizadores_inicio;
	string indicadorNovoUtilizador;

	olz_file >> utilizadores_inicio;
	while(1){

		olz_file >> indicadorNovoUtilizador;

		if(indicadorNovoUtilizador == "NOVO_UTILIZADOR"){
			olz_file.ignore();

			Utilizador* utilizador = leUtilizador(olz_file);
			adicionarUtilizador(utilizador);

			leAnunciosDeVendaDeUmUtilizador(olz_file, utilizador);
			leAnunciosDeCompraDeUmUtilizador(olz_file, utilizador);

		}
		else if(indicadorNovoUtilizador == "FIM_UTILIZADORES")
			break;
	}
}

void OLZ::leAnunciosDeVendaDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
	string anunciosDeVenda_inicio;
	string indicadorNovoAnuncio;
	DeVenda* anuncioVenda = NULL;

	olz_file >> anunciosDeVenda_inicio;

	while(1){
		olz_file >> indicadorNovoAnuncio;

		if(indicadorNovoAnuncio == "NOVO_ANUNCIO"){
			olz_file.ignore();

			anuncioVenda = leAnuncioDeVenda(olz_file);
			anuncioVenda->setAnunciantePtr(anunciante);
			adicionarAnuncioVenda(anuncioVenda);
		}

		else if(indicadorNovoAnuncio == "FIM_ANUNCIOS_VENDA")
			break;
	}
}

void OLZ::leAnunciosDeCompraDeUmUtilizador(istream& olz_file, Utilizador* anunciante){
	string anunciosDeCompra_inicio;
	string indicadorNovoAnuncio;
	DeCompra* anuncioCompra = NULL;

	olz_file >> anunciosDeCompra_inicio;

	while(1){
		olz_file >> indicadorNovoAnuncio;

		if(indicadorNovoAnuncio == "NOVO_ANUNCIO"){
			olz_file.ignore();

			anuncioCompra = leAnuncioDeCompra(olz_file);
			anuncioCompra->setAnunciantePtr(anunciante);
			adicionarAnuncioCompra(anuncioCompra);
		}
		else if(indicadorNovoAnuncio == "FIM_ANUNCIOS_COMPRA")
			break;
	}
}
/***********************
 * AUXILIARY FUNCTIONS *
 ***********************/

/**
 * @brief read a want ad from a file
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

/**
 * @brief read a seller ad froma a file
 */
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

/**
 * @brief read state of a product of a seller ad
 */
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

/**
 * @brief read information of a user from a file
 */
Utilizador* leUtilizador(istream& olz_file){
	string nome, email, numTel, freguesia, concelho, distrito;

	getline(olz_file, nome);
	getline(olz_file, email);
	getline(olz_file, numTel);
	getline(olz_file, freguesia);
	getline(olz_file, concelho);
	getline(olz_file, distrito);

	return new Utilizador(nome, email, numTel, freguesia, concelho, distrito);
}

/**
 * @brief read data from a file
 */
Data leDataDoAnuncio(istream& olz_file){
	int dia, mes, ano;

	olz_file >> dia;
	olz_file >> mes;
	olz_file >> ano;

	return Data(dia,mes,ano);
}

/**
 * @brief read images from a ad (want ad or seller ad)
 */
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

/**
 * @brief read categories from a file
 */
vector<string> leCategorias(istream& olz_file){
	vector<string> categorias;
	string indicadorInicioCategorias;
	string categoria;

	olz_file.ignore();
	olz_file >> indicadorInicioCategorias;

	while(1){
		olz_file >> categoria;

		if(categoria == "FIM_CATEGORIAS")
			break;
		else
			categorias.push_back(categoria);
	}

	return categorias;
}

