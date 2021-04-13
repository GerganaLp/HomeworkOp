#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Flights {
	unsigned short int id;
	char* plane;
	char* type;
	int flights;
public:
	Flights(unsigned short int, char*, char* , int );
	Flights(Flights&);
	Flights& operator=(const Flights&);
	~Flights();
	unsigned short int getid() const { return id; };
	char* getname() const { return plane; };
	char* gettype() const { return type; };
	int getflight() const { return flights; };
	void setId(unsigned short int);
	void setPlane(const char*);
	void setType(const char*);
	void setFlights(int);
	void save(ofstream&)const;
	bool checkFlight(ifstream&)const;
	//friend istream& operator>>(istream& is, Flights& st);
	//friend ostream& operator<<(ostream& os, Flights& st);
};