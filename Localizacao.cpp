
#include "Localizacao.h"

Localizacao::Localizacao(string freguesia, string concelho, string distrito):
	freguesia(freguesia),
	concelho(concelho),
	distrito(distrito)
{
	// Empty block
}

string Localizacao::getFreguesia() const
{
	return freguesia;
}

string Localizacao::getConcelho() const
{
	return concelho;
}

string Localizacao::getDistrito() const
{
	return distrito;
}

bool Localizacao::operator <(const Localizacao & l) const
{
	if (distrito == l.distrito)
	{
		if (concelho == l.concelho)
		{
			return freguesia < l.freguesia;
		} else
		{
			return concelho < l.concelho;
		}
	}

	return distrito < l.distrito;
}