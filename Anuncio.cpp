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
Data Anuncio::getData(){ return data;}

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

void Anuncio::setAnunciantePtr(Utilizador* anunciantePtr){
	anunciante = anunciantePtr;
}

void Anuncio::setIdentificadorInicial(int static_id_anuncio_inicial){
	identificador = static_id_anuncio_inicial;
}

int Anuncio::getIdentificadorInicial(){
	return identificador;
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
DeVenda::DeVenda(string titulo,	string categoria,string descricao,
		vector<string> imagens,int id, Estado estado,float preco,
		bool negociacao,Data data, Utilizador* anunciante,
		int visualizacoes, bool showEmail, bool showNome, bool showNumTel) :
	Anuncio(titulo,categoria,descricao, imagens, id, data, anunciante,
			visualizacoes, showEmail, showNome, showNumTel){
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
	cout << "\tPreco: " << preco << "€";
	if(negociacao)
		cout << ", mas com possibilidade de negociar preco.\n";
	cout << endl;
	//Informações do anunciante
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
DeCompra::DeCompra(string titulo, string categoria, string descricao, vector<string> imagens,
		int id, bool troca, int trocaId, Data data, Utilizador* anunciante,int visualizacoes,
		bool showEmail, bool showNome, bool showNumTel):
		Anuncio(titulo,categoria,descricao, imagens,id, data, anunciante,
				visualizacoes, showEmail, showNome, showNumTel){
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
	//Informações do anunciante
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
int DeCompra::GetTrocaId(){
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
	return out;
}

istream &operator>>(istream &in, DeVenda &a){
	string temp;

	getline(in, a.titulo);
	getline(in, a.cat);
	getline(in, a.descricao);
	//lê imagens
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
	return out;
}

istream &operator>>(istream &in, DeCompra &a){
	string temp;

	getline(in, a.titulo);
	getline(in, a.cat);
	getline(in, a.descricao);
	//lê imagens
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

	return in;
}
