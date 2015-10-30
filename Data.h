/*
 * Data.h
 *
 *  Created on: 17/10/2015
 *      Author: Inês
 */

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <string>
#include <iostream>

using namespace std;

struct DataInvalida{
	string dado;
	int valor;
	DataInvalida(string erro, int val): dado(erro), valor(val){}
};

class Data{
	int dia;
	int mes;
	int ano;
public:
	Data(int d, int m, int a){
		if(m < 0 || m >12)
			throw DataInvalida("mes",m);
		if(d < 0 || d > 31)
			throw DataInvalida("dia",d);
		if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		if(m == 2 && a%4 == 0 && d > 29)
			throw DataInvalida("dia",d);
		if(m == 2 && a%4 != 0 && d > 28)
			throw DataInvalida("dia",d);
		dia = d;
		mes = m;
		ano = a;
	}
	Data(){
		dia = 1;
		mes = 1;
		ano = 2000;
	}
	friend ostream& operator<< (ostream& out, const Data &data){
		out << data.dia << "/" << data.mes << "/" << data.ano;

		return out;
	}
};

#endif /* SRC_DATA_H_ */
