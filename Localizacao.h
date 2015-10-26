/*
 * Localizacao.h
 *
 *  Created on: 25/10/2015
 *      Author: filip
 */

#ifndef LOCALIZACAO_H_
#define LOCALIZACAO_H_

#include <string>

using namespace std;

class Localizacao {
	string freguesia;
	string concelho;
	string distrito;
public:
	Localizacao(string freguesia, string concelho, string distrito);
	virtual ~Localizacao();
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
};

#endif /* LOCALIZACAO_H_ */
