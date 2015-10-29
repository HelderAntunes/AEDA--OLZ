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
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param anunciante pointer to the advertiser
 */
Anuncio::Anuncio(string titulo, string categoria, string descricao, Utilizador* anunciante): id(identificador++), cat (Categoria(categoria)){
	this->titulo = titulo;
	this->descricao = descricao;
	this->visualizacoes = 0;
	this->anunciante = anunciante;

	//Obter a data de criacao
	time_t t = time(0);   // get time now
	tm * now = localtime( & t );
	this->data = Data(now->tm_mday,now->tm_mon + 1,now->tm_year + 1900);
}

/**
 * Creates new advertisement with information provided and data correspondent to current date.
 * @brief class Anuncio constructor.
 *
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param imagens names of image files used
 * @param anunciante pointer to the advertiser
 */
Anuncio::Anuncio(string titulo, string categoria, string descricao, vector<string> imagens, Utilizador* anunciante): id(identificador++), cat (Categoria(categoria)){
	this->titulo = titulo;
	this->descricao = descricao;
	this->imagens = imagens;
	this->visualizacoes = 0;
	this->anunciante = anunciante;

	//Obter a data de criacao
	time_t t = time(0);   // get time now
	tm * now = localtime( & t );
	this->data = Data(now->tm_mday,now->tm_mon + 1,now->tm_year + 1900);
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
Categoria Anuncio::getCategoria(){	return cat;}

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
 * @param anunciante pointer to the advertiser
 */
DeVenda::DeVenda(string titulo,	string categoria,string descricao,vector<string> imagens, Estado estado,float preco, bool negociacao,Utilizador* anunciante) :
																Anuncio(titulo,categoria,descricao, imagens, anunciante){
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
	case USADO:
		cout << "Artigo usado como novo\n";
	case FUNCIONAL:
		cout << "Artigo funcional\n";
	case PECAS:
		cout << "Artigo indicado somente para pecas";
	}
	cout << preco << "€";
	if(negociacao)
		cout << " mas com possibilidade de negociar preco";
	//Imprimir os dados que o anunciante deseja mostrar
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
 * @param anunciante pointer to the advertiser
 * @param ptr pointer to sale ad admissible for exchange
 */
DeCompra::DeCompra(string titulo, string categoria, string descricao, vector<string> imagens, DeVenda* ptr, Utilizador* anunciante):
																	Anuncio(titulo,categoria,descricao, imagens, anunciante){
	this->troca = ptr;
}

/**
 * Creates new purchase advertisement without exchange possibility (troca equal to NULL).
 * @brief class DeCompra constructor.
 *
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param imagens names of image files used
 * @param anunciante pointer to the advertiser
 */
DeCompra::DeCompra(string titulo, string categoria, string descricao, vector<string> imagens, Utilizador* anunciante):
																	Anuncio(titulo,categoria,descricao, imagens, anunciante){
	this->troca = NULL;
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
	if(troca != NULL)
		cout << "Aceita-se tambem troca pelo produto de id: " << troca->getId() << endl;
	//Imprimir os dados que o anunciante deseja mostrar
	cout << "\tcriado em: " << data <<endl;
}
