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
 * @param id			ad's id
 * @param data 			date of creation
 * @param anunciante 	pointer to the advertiser
 * @param visualizacoes	number of views
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 */
Anuncio::Anuncio(string titulo, string categoria, string descricao,
		vector<string> imagens,int id, Data data, Utilizador* anunciante,
		int visualizacoes, bool showEmail, bool showNome, bool showNumTel):
				data(data){
	this->titulo = titulo;
	this->descricao = descricao;
	this->imagens = imagens;
	this->visualizacoes = visualizacoes;
	this->anunciante = anunciante;
	this->cat = categoria;
	this->showEmail =  showEmail;
	this->showNome = showNome;
	this->showNumTel = showNumTel;
	this->temDestaque = false;		//adicionei esta instru��o, por favor, confiram
	this->id = id;
}

/**
 * Creates new advertisement with information provided and data correspondent to current date.
 * @brief class Anuncio constructor.
 *
 * @param titulo 		advertisement's title
 * @param categoria 	advertisement's category
 * @param descricao 	advertisement's description
 * @param imagens 		names of image files used
 * @param id			ad's id
 * @param data 			date of creation
 * @param anunciante 	pointer to the advertiser
 * @param visualizacoes	number of views
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 * @param temDestaque 	is ad priority in search
 */
Anuncio::Anuncio(string titulo, string categoria, string descricao,
		vector<string> imagens,int id, Data data, Utilizador* anunciante,
		int visualizacoes, bool showEmail, bool showNome, bool showNumTel, bool temDestaque):
			data(data){
	this->titulo = titulo;
	this->descricao = descricao;
	this->imagens = imagens;
	this->visualizacoes = visualizacoes;
	this->anunciante = anunciante;
	this->cat = categoria;
	this->showEmail =  showEmail;
	this->showNome = showNome;
	this->showNumTel = showNumTel;
	this->temDestaque = temDestaque;
	this->id = id;
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
Data Anuncio::getData() const{ return data;}

/**
 * @brief get views.
 *
 * @return number of views gotten by the advertisement
 */
int Anuncio::getVisualizacoes(){return visualizacoes;}

/**
 * @brief get pointer to anunciante
 *
 * @return pointer to anunciante
 */
Utilizador* Anuncio::getAnunciante(){return anunciante;}

/**
 * @brief get permit to show email.
 *
 * @return showEmail is email public?
 */
bool Anuncio::getShowEmail(){
	return showEmail;
}

/**
 * @brief get permit to show name.
 *
 * @return showNome is name public?
 */
bool Anuncio::getShowNome(){
	return showNome;
}

/**
 * @brief get permit to show phone number.
 *
 * @return showNumTel is phone number public?
 */
bool Anuncio::getShowNumTel(){
	return showNumTel;
}

/**
 * @brief get description of anuncio
 *
 * @return description
 */
string Anuncio::getDescricao(){
	return descricao;
}

/**
 * @brief get images of anuncio
 *
 * @return vector of images
 */
vector<string> Anuncio::getImagens(){
	return imagens;
}

/**
 * @brief if a ad haves more visibility
 * if it haves more visibility return true, otherwise return false
 * @return temDestaque
 */
bool Anuncio::anuncioTemDestaque() const{
	return temDestaque;
}

/**
 * @brief set temDestaque to true
 */
void Anuncio::colocarDestaque(){
	temDestaque = true;
}

/**
 * @brief set temDestaque to false
 */
void Anuncio::retirarDestaque(){
	temDestaque = false;
}

/**
 * @brief set permit to email.
 *
 * @param showEmail is email public?
 */
void Anuncio::setShowEmail(bool showEmail){
	this->showEmail = showEmail;
}

/**
 * @brief set permit to show name.
 *
 * @param showNome is name public?
 */
void Anuncio::setShowNome(bool showNome){
	this->showNome = showNome;
}

/**
 * @brief set permit to show phone number.
 *
 * @param showNumTel is phone number public?
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

/**
 * @brief compares two ads by id
 *
 * @param right ad on the right of operator <
 *
 * @return true if id of ad on the left is less than the one on the right
 */
bool Anuncio::operator<(const Anuncio &right){
	return id < right.id;
}

/**
 * @brief set advertiser
 *
 * @param anunciantePtr new advertiser
 */
void Anuncio::setAnunciantePtr(Utilizador* anunciantePtr){
	anunciante = anunciantePtr;
}

/**
 * @brief set identifier
 *
 * @param static_id_anuncio_inicial new identifier
 */
void Anuncio::setIdentificadorInicial(int static_id_anuncio_inicial){
	identificador = static_id_anuncio_inicial;
}

/**
 * @brief get identifier
 *
 * @return identifier
 */
int Anuncio::getIdentificadorInicial(){
	return identificador;
}

/**
 * Creates new sale advertisement with information provided and data correspondent to current date.
 * @brief class DeVenda constructor.
 *
 * @param titulo 		advertisement's title
 * @param categoria 	advertisement's category
 * @param descricao 	advertisement's description
 * @param imagens 		names of image files used
 * @param id			ad's id
 * @param estado 		advertised object's condition
 * @param preco 		advertised object's demanded price
 * @param negociacao 	advertiser position regarding negotiation
 * @param data 			date of creation
 * @param anunciante 	pointer to the advertiser
 * @param visualizacoes	number of views
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 * @param temDestaque 	ad has priority in search?
 */
DeVenda::DeVenda(string titulo,	string categoria,string descricao,
		vector<string> imagens,int id, Estado estado,float preco,
		bool negociacao,Data data, Utilizador* anunciante,
		int visualizacoes, bool showEmail, bool showNome, bool showNumTel, bool temDestaque) :
			Anuncio(titulo,categoria,descricao, imagens, id, data, anunciante,
					visualizacoes, showEmail, showNome, showNumTel, temDestaque){
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
 * @brief get information about if the advertiser want negotiate
 *
 * @return true if he wants, false if he does not want
 */
bool DeVenda::getNegociacao(){return negociacao;}
/**
 * Function displays sale advertisement on screen
 * @brief display sale ad.
 */
void DeVenda::imprime() const {
	cout << "Id do anuncio de venda: " << id << "." << endl;
	cout << "\tTitulo: " << titulo << endl;
	cout << "\tCategoria: " << cat << endl;
	cout << "\tDescricao: " << descricao << endl;
	cout << "\tEstado do produto: ";
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
		cout << "Artigo indicado somente para pecas\n";
		break;
	}
	cout << "\tPreco: " << preco << "�";
	if(negociacao)
		cout << ", mas com possibilidade de negociar preco.\n";
	cout << endl;
	//Informa��es do anunciante
	if(showNome || showEmail || showNumTel)
		cout << "Informacao do anunciante:\n";
	if(showNome)
		cout << "\tNome: " << anunciante->getNome() << endl;
	if(showNumTel)
		cout << "\tContacto telemovel: " << anunciante->getContacto() << endl;
	if(showEmail)
		cout << "\tEmail: " << anunciante->getEmail() << endl;
	cout << "\n\tNumero de visualizacoes: " << visualizacoes << endl;
	cout << "\tCriado em: " << data <<endl;
	if(temDestaque)
		cout << "Este anuncio tem destaque.\n";
	else
		cout << "Este anuncio nao tem destaque.\n";
}

/**
 * Creates new purchase advertisement with exchange possibility.
 * @brief class DeCompra constructor.
 *
 * @param titulo advertisement's title
 * @param categoria advertisement's category
 * @param descricao advertisement's description
 * @param imagens 		names of image files used
 * @param id			ad's id
 * @param troca			is available for trade
 * @param data 			date of creation
 * @param anunciante 	pointer to the advertiser
 * @param visualizacoes	number of views
 * @param trocaId id of the sale ad admissible for exchange
 * @param showEmail 	is email public?
 * @param showNome		is name public?
 * @param showNumTel	is phone number public?
 * @param temDestaque 	ad has priority in search?
 */
DeCompra::DeCompra(string titulo, string categoria, string descricao, vector<string> imagens,
		int id, bool troca, int trocaId, Data data, Utilizador* anunciante,int visualizacoes,
		bool showEmail, bool showNome, bool showNumTel, bool temDestaque):
				Anuncio(titulo,categoria,descricao, imagens,id, data, anunciante,
						visualizacoes, showEmail, showNome, showNumTel, temDestaque){
	this->troca = troca;
	this->trocaId = trocaId;
}

/**
 * Function displays purchase advertisement on screen
 * @brief display purchase ad.
 */
void DeCompra::imprime() const{
	cout << "Id do anuncio de compra: " << id << "." << endl;
	cout << "\tTitulo: " << titulo << endl;
	cout << "\tCategoria: " << cat << endl;
	cout << "\tDescricao: " << descricao << endl;
	if(troca)
		cout << "\tAceita-se tambem troca pelo produto de id: " << trocaId << endl;
	cout << endl;
	//Informa��es do anunciante
	if(showNome || showEmail || showNumTel)
		cout << "Informacao do anunciante:\n";
	if(showNome)
		cout << "\t" << anunciante->getNome() << endl;
	if(showNumTel)
		cout << "\t" << anunciante->getContacto() << endl;
	if(showEmail)
		cout << "\t" << anunciante->getEmail() << endl;

	cout << "\n\tNumero de visualizacoes: " << visualizacoes << endl;
	cout << "\tCriado em: " << data <<endl;
	if(temDestaque)
		cout << "Este anuncio tem destaque.\n";
	else
		cout << "Este anuncio nao tem destaque.\n";
}

/**
 * @return if the advertiser want a exchange
 */
bool DeCompra::getTroca(){
	return troca;
}

/**
 * @return the id of anuncio de venda
 */
int DeCompra::getTrocaId(){
	return trocaId;
}

//Operators << e >>
ostream &operator<<(ostream &out, DeVenda a){
	out << a.titulo <<endl;
	out << a.cat <<endl;
	out << a.descricao <<endl;

	//escreve imagens
	out << "Imagens\n";
	for(unsigned int i = 0; i < a.imagens.size(); i++)
		out << a.imagens[i] <<endl;
	out << "FimImagens\n";

	out << a.id << endl;
	out << a.data << endl;
	out << a.visualizacoes << endl;
	out << a.showEmail << " " << a.showNome << " " << a.showNumTel << endl;

	//escreve estado
	switch (a.estado){
	case NOVO:
		out << "NOVO\n";
		break;
	case USADO:
		out << "USADO\n";
		break;
	case FUNCIONAL:
		out << "FUNCIONAL\n";
		break;
	case PECAS:
		out << "PECAS\n";
		break;
	}

	out << a.preco << endl;
	out << a.negociacao << endl;
	out << a.temDestaque << endl;

	return out;
}

istream &operator>>(istream &in, DeVenda &a){
	string temp;

	getline(in, a.titulo);
	getline(in, a.cat);
	getline(in, a.descricao);
	//l� imagens
	getline(in, temp);
	while(1){
		getline(in,temp);
		if(temp == "FimImagens")
			break;
		else
			a.imagens.push_back(temp);
	}

	in >> a.id;
	in >> a.data;
	in >> a.visualizacoes;
	in >> a.showEmail >> a.showNome >> a.showNumTel;

	//ler estado
	string estado_string;
	in >> estado_string;
	if(estado_string == "NOVO")
		a.estado = NOVO;
	else if(estado_string == "USADO")
		a.estado = USADO;
	else if(estado_string == "FUNCIONAL")
		a.estado = FUNCIONAL;
	else if(estado_string == "PECAS")
		a.estado = PECAS;

	in >> a.preco;
	in >> a.negociacao;
	in >> a.temDestaque;

	return in;
}
ostream &operator<<(ostream &out, DeCompra a){
	out << a.titulo <<endl;
	out << a.cat <<endl;
	out << a.descricao <<endl;

	//escreve imagens
	out << "Imagens\n";
	for(unsigned int i = 0; i < a.imagens.size(); i++)
		out << a.imagens[i] <<endl;
	out << "FimImagens\n";

	out << a.id << endl;
	out << a.data << endl;
	out << a.visualizacoes << endl;
	out << a.showEmail << " " << a.showNome << " " << a.showNumTel << endl;
	out << a.troca << endl;
	out << a.trocaId << endl;
	out << a.temDestaque << endl;
	return out;
}

istream &operator>>(istream &in, DeCompra &a){
	string temp;

	getline(in, a.titulo);
	getline(in, a.cat);
	getline(in, a.descricao);
	//l� imagens
	getline(in, temp);
	while(1){
		getline(in,temp);
		if(temp == "FimImagens")
			break;
		else
			a.imagens.push_back(temp);
	}

	in >> a.id;
	in >> a.data;
	in >> a.visualizacoes;
	in >> a.showEmail >> a.showNome >> a.showNumTel;
	in >> a.troca;
	in >> a.trocaId;
	in >> a.temDestaque;

	return in;
}
