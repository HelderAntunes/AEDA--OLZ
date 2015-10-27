
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
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
	bool operator<(const Localizacao & l) const;
};

#endif /* LOCALIZACAO_H_ */
