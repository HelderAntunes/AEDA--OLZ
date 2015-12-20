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
#include <vector>

using namespace std;

/**exception thrown when attempting to create an invalid date
 * @struct ExceptionDataInvalida
 * @brief exception for class Data
 */
struct ExceptionDataInvalida{
	string dado;	/**< component of Data that created the exception*/
	int valor;		/**< invalid value the component of Data took*/
	/**
	 * Creates new exception with information provided.
	 * @brief class DataInvalida constructor.
	 *
	 * @param dado 		component of Data that created the exception
	 * @param valor 	invalid value the component of Data took
	 */
	ExceptionDataInvalida(string erro, int val): dado(erro), valor(val){}
};

/**@class Data
 * @brief Date class
 */
class Data{
	int dia;		/**< date's day*/
	int mes;		/**< date's month*/
	int ano;		/**< date's year*/
public:
	/**
	 * Creates new date with information provided.
	 * @brief class Data constructor.
	 *
	 * @param d 		date's day
	 * @param m		 	date's month
	 * @param a			date's year
	 */
	Data(int d, int m, int a){
		if(m < 0 || m >12)
			throw ExceptionDataInvalida("mes",m);
		if(d < 0 || d > 31)
			throw ExceptionDataInvalida("dia",d);
		if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
			if(m == 2 && a%4 == 0 && d > 29)
				throw ExceptionDataInvalida("dia",d);
		if(m == 2 && a%4 != 0 && d > 28)
			throw ExceptionDataInvalida("dia",d);
		dia = d;
		mes = m;
		ano = a;
	}

	/**
	 * Creates new date 1/01/2000
	 * @brief class Data constructor with no arguments.
	 */
	Data(){
		dia = 1;
		mes = 1;
		ano = 2000;
	}

	/**
	 * sends date to out stream out
	 * @brief operator << for class Data
	 *
	 * @param out 		out stream chosen
	 * @param data		date to be sent
	 */
	friend ostream& operator<< (ostream& out, const Data &data){
		out << data.dia << "/" << data.mes << "/" << data.ano;

		return out;
	}

	/**
	 * sends date to in stream in
	 * @brief operator >> for class Data
	 *
	 * @param in		in stream chosen
	 * @param data		date to be sent
	 */
	friend istream &operator>>( istream  &in, Data &data ){
		char lixo;
		in >> data.dia >> lixo >> data.mes >> lixo >> data.ano;

		return in;
	}

    bool operator< (const Data& right) const{
        vector<int> l,r;
        l.push_back(this->ano);
        l.push_back(this->mes);
        l.push_back(this->dia);
        r.push_back(right.ano);
        r.push_back(right.mes);
        r.push_back(right.dia);

        for(size_t i = 0;i < l.size();i++){
            if(l[i] < r[i])
                return true;
            else if(l[i] > r[i])
                return false;
        }

        return false;
    }

    bool operator==(const Data& right) const{
    	if(this->dia == right.dia && this->mes == right.mes && this->ano == right.ano)
    		return true;

    	return false;
    }


};

#endif /* SRC_DATA_H_ */
