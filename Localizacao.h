#ifndef LOCALIZACAO_H_
#define LOCALIZACAO_H_

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Localizacao
 * @brief Localizacao class
 */
class Localizacao {
	string freguesia;    /**< freguesia of user */
	string concelho;	/**< concelho of user */
	string distrito;	/**< distrito of user */
public:
	Localizacao(string freguesia, string concelho, string distrito);
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
	friend ostream & operator<<(ostream & os, const Localizacao & l);
};

#endif /* LOCALIZACAO_H_ */
