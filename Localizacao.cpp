
#include <string>
#include <iostream>
#include "Localizacao.h"

/**
 * @brief class Localizacao constructor
 *
 * @param freguesia		freguesia of user
 * @param concelho 		concelho of user
 * @param distrito		distrito of user
 */
Localizacao::Localizacao(string freguesia, string concelho, string distrito):
	freguesia(freguesia),
	concelho(concelho),
	distrito(distrito)
{
	// Empty block
}

/**
 * @brief get freguesia
 *
 * @return freguesia
 */
string Localizacao::getFreguesia() const
{
	return freguesia;
}

/**
 * @brief get concelho
 *
 * @return concelho
 */
string Localizacao::getConcelho() const
{
	return concelho;
}

/**
 * @brief get distrito
 *
 * @return distrito
 */
string Localizacao::getDistrito() const
{
	return distrito;
}

/**@brief operator << to write location
 *
 * @param os where to write
 * @param l  location to be written *
 */
ostream & operator<<(ostream & os, const Localizacao & l)
{
	os << l.getFreguesia() << ", " << l.getConcelho() << ", " << l.getDistrito();
	return os;
}
