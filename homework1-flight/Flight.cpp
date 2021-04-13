#include "Flight.h"

Flights::Flights(unsigned short int _id, char* _plane, char* _type, int _fl)
{
	id = _id;
	plane = new char[strlen(_plane) + 1];
	strcpy(plane, _plane);
	type= new char[strlen(_type) + 1];
	strcpy(type, _type);
	flights = _fl;
}

Flights::Flights(Flights& st)
{
	id = st.id;
	plane = new char[strlen(st.plane) + 1];
	strcpy(plane, st.plane);
	type = new char[strlen(st.type) + 1];
	strcpy(type, st.type);
	flights = st.flights;
}

Flights& Flights::operator=(const Flights& st)
{
	if (this != &st) {
		delete[] plane;
		delete[] type;
		id = st.id;
		plane = new char[strlen(st.plane) + 1];
		strcpy(plane, st.plane);
		type = new char[strlen(st.type) + 1];
		strcpy(type, st.type);
		flights = st.flights;
	}return *this;
}

Flights::~Flights() {
	delete[] plane;
	delete[] type;

}
void Flights::setId(unsigned short int _id) {
	id = _id;
}

void Flights::setPlane(const char* _plane) {
	int length = strlen(_plane) + 1;
	this->plane = NULL;
	this->plane = new(std::nothrow) char[length];
	if (plane == NULL) {
		return;
	}
	strcpy(this->plane, _plane);
}
void Flights::setType(const char* _type) {
	int length = strlen(_type) + 1;
	this->type = NULL;
	this->type = new(std::nothrow) char[length];
	if (type == NULL) {
		return;
	}
	strcpy(this->type, _type);
}
void Flights::setFlights(int _fl) {
	flights = _fl;
}

void Flights::save(ofstream& db) const {
	db << id << ' ' << plane << ' ' << type << ' ' << flights << endl;
	cout << "Record saved" << endl;
}
bool Flights::checkFlight(ifstream& db) const {
	int id = -1;
	db.clear();
	db.seekg(0, ios::beg);
	while (!db.eof()) {
		db >> id;
		db.ignore(256, '\n');
		if (this->id == id) return  false;
	}
	
	return true;
}
