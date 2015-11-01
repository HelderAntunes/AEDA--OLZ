/**
 * @file Anuncio.cpp
 *
 * @brief Code for class Anuncio*/

#include"Anuncio.h"
#include"Data.h"

using namespace std;

int Anuncio::identificador(0);

/**
 * Creates new advertisement with information provided and data correspondent to current date.
 * @brief class Anuncio constructor.
 *
 * @param titulo 		advertisement's title
 * @param categoria 	advertisement's category
 * @param descricao 	advertisement's description
 * @param imagens 		names of image files used
 * @param data 			date of creation
 * @param anunciante 	pointer to the advertiser
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 */
Anuncio::Anuncio(string titulo, string categoria, string descricao,vector<string> imagens, Data data, Utilizador* anunciante, bool showEmail, bool showNome, bool showNumTel): id(identificador++), data(data){
	this->titulo = titulo;
	this->descricao = descricao;
	this->imagens = imagens;
	this->visualizacoes = 0;
	this->anunciante = anunciante;
	this->cat = categoria;
	this->showEmail =  showEmail;
	this->showNome = showNome;
	this->showNumTel = showNumTel;
}

/**
 * A virtual destructor
 * @brief class Anuncio destructor.
 */
Anuncio::~Anuncio(){}

/**
 * @brief get title.
 *
 * @return advertisement's title
 */
string Anuncio::getTitulo(){return titulo;}

/**
 * @brief get category.
 *
 * @return advertisement's category
 */
string Anuncio::getCategoria(){	return cat;}

/**
 * @brief get id.
 *
 * @return advertisement's id
 */
int Anuncio::getId(){return id;}

/**
 * @brief get date.
 *
 * @return advertisement's creation date
 */
Data Anuncio::getData(){ return data;}

/**
 * @brief get views.
 *
 * @return number of views gotten by the advertisement
 */
int Anuncio::getVisualizacoes(){return visualizacoes;}

/**
 * @brief get permit to show email.
 *
 * @return is email public?
 */
bool Anuncio::getShowEmail(){
	return showEmail;
}

/**
 * @brief get permit to show name.
 *
 * @return is name public?
 */
bool Anuncio::getShowNome(){
	return this->showNome;
}

/**
 * @brief get permit to show phone number.
 *
 * @return is phone number public?
 */
bool Anuncio::getShowNumTel(){
	return showNumTel;
}

/**
 * @brief set permit to email.
 *
 * @param is email public?
 */
void Anuncio::setShowEmail(bool showEmail){
	this->showEmail = showEmail;
}

/**
 * @brief set permit to show name.
 *
 * @param is name public?
 */
void Anuncio::setShowNome(bool showNome){
	this->showNome = showNome;
}

/**
 * @brief set permit to show phone number.
 *
 * @param is phone number public?
 */
void Anuncio::setShowNumTel(bool showNumTel){
	this->showNumTel = showNumTel;
}

/**
 * This function increments view counter by one
 * @brief increment views.
 */
void Anuncio::incVisualizacoes(){
	this->visualizacoes ++;
}

/**
 * This function searches title and description for a keyword
 * @brief searches for keyword
 *
 * @param palavra keyword to look for
 */
bool Anuncio::procuraPalavraChave(string palavra){

	if(titulo.find(palavra) != string::npos)
		return true;

	if(descricao.find(palavra) != string::npos)
		return true;
	return false;
}

bool Anuncio::operator<(const Anuncio &right){
	return id < right.id;
}

/**
 * Creates new sale advertisement with information provided and data correspondent to current date.
 * @brief class DeVenda constructor.
 *
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param imagens names of image files used
 * @param estado advertised object's condition
 * @param preco advertised object's demanded price
 * @param negociacao advertiser position regarding negotiation
 * @param data date of creation
 * @param anunciante pointer to the advertiser
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 */
DeVenda::DeVenda(string titulo,	string categoria,string descricao,vector<string> imagens, Estado estado,float preco, bool negociacao,Data data, Utilizador* anunciante, bool showEmail, bool showNome, bool showNumTel) :
																Anuncio(titulo,categoria,descricao, imagens, data, anunciante, showEmail, showNome, showNumTel){
	this->estado = estado;
	this->preco = preco;
	this->negociacao = negociacao;
}

/**
 * @brief get condition.
 *
 * @return condition of advertised product
 */
Estado DeVenda::getEstado(){return estado;}

/**
 * @brief get price.
 *
 * @return price of advertised product
 */
float DeVenda::getPreco(){ return preco;}

/**
 * Function changes the price of the product
 * @brief set price.
 *
 * @param preco new price for product
 */
void DeVenda::setPreco(float preco){this->preco = preco;}

/**
 * Function displays sale advertisement on screen
 * @brief display sale ad.
 */
void DeVenda::imprime() const {
	cout << id << ". Vende-se " << titulo << endl;
	cout << "\t Categoria: " << cat << endl;
	cout << descricao << endl;
	switch(estado){
	case NOVO:
		cout << "Artigo novo\n";
		break;
	case USADO:
		cout << "Artigo usado como novo\n";
		break;
	case FUNCIONAL:
		cout << "Artigo funcional\n";
		break;
	case PECAS:
		cout << "Artigo indicado somente para pecas";
		break;
	}
	cout << preco << "€";
	if(negociacao)
		cout << " mas com possibilidade de negociar preco";

	//Informações do anunciante
	if(showNome || showEmail || showNumTel)
		cout << "Informacao do anunciante:\n";
	if(showNome)
		cout << "\t" << anunciante->getNome() << endl;
	if(showNumTel)
		cout << "\t" << anunciante->getContacto() << endl;
	if(showEmail)
		cout << "\t" << anunciante->getEmail() << endl;

	cout << "\n\tcriado em: " << data <<endl;
}

/**
 * Creates new purchase advertisement with exchange possibility.
 * @brief class DeCompra constructor.
 *
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param imagens names of image files used
 * @param data date of creation
 * @param anunciante pointer to the advertiser
 * @param trocaId id of the sale ad admissible for exchange
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 */
DeCompra::DeCompra(string titulo, string categoria, string descricao, vector<string> imagens, bool troca, int trocaId, Data data, Utilizador* anunciante, bool showEmail, bool showNome, bool showNumTel):
																	Anuncio(titulo,categoria,descricao, imagens, data, anunciante, showEmail, showNome, showNumTel){
	this->troca = troca;
	this->trocaId = trocaId;
}

/**
 * Function displays purchase advertisement on screen
 * @brief display purchase ad.
 */
void DeCompra::imprime() const{
	cout << id << ". Compra-se " << titulo << endl;
	cout << "\t Categoria: ";
	cout << cat << endl;
	cout << descricao << endl;
	if(troca)
		cout << "Aceita-se tambem troca pelo produto de id: " << trocaId << endl;

	//Informações do anunciante
	if(showNome || showEmail || showNumTel)
		cout << "Informacao do anunciante:\n";
	if(showNome)
		cout << "\t" << anunciante->getNome() << endl;
	if(showNumTel)
		cout << "\t" << anunciante->getContacto() << endl;
	if(showEmail)
		cout << "\t" << anunciante->getEmail() << endl;

	cout << "\tcriado em: " << data <<endl;
}
