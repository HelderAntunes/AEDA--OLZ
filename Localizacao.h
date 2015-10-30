
#ifndef LOCALIZACAO_H_
#define LOCALIZACAO_H_

#include <string>
#include <iostream>

using namespace std;

class Localizacao {
	string freguesia;
	string concelho;
	string distrito;
public:
	Localizacao(string freguesia, string concelho, string distrito);
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
	bool operator<(const Localizacao & l) const;
	friend ostream & operator<<(ostream & os, const Localizacao & l);
};

#endif /* LOCALIZACAO_H_ */
