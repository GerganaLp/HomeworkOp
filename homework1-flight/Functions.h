#pragma once
#include <fstream>
#include "Flight.h"
/*
void create() {
	fstream file;
	file.open("Planes.txt", ios::app);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Flights st;
	cin >> st;
	file << st;
	cout << "Record saved!\n";
	file.close();

}

void sequentialSearch() {
	fstream file;
	file.open("Planes.txt", ios::in);
	if (!file) { cerr << "File couldn't be opened!\n"; }
	Flights st;
	unsigned long long id;
	do { cin >> id; } while (id<0 || id>pow(2, 50));
	bool found = false;
	file.seekg(0, ios::beg);
	while (file >> st) {
		if (st.getid() == id)
		{
			cout << st; found = true; break;
		}

	}
	if (!found) { cout << "Record not found!\n"; }
	file.close();

}
void operationParser() {
	string input;
	cin >> input;

	while (input != "exit") {

		if (input == "create") {
			create();
		}
		else if (input == "sequentialSearch") {
			sequentialSearch();
		}
		else { cout << "Invalid operation!\n"; }
		cin >> input;
	}
}
*/
void create(ofstream& dbO, ifstream& dbI, const Flights& stC) {
	if (stC.checkFlight(dbI)) {
		stC.save(dbO);
	}
	else {
		cerr << "This id already exist!" << endl;
	}
}

void sequentialSearch(int id, ifstream& db) {
	int idLocal;
	bool flag = false;
	db.clear();
	db.seekg(0, ios::beg);
	while (!db.eof()) {
		db >> idLocal;
		if (id == idLocal) {
			flag = true;
			break;
		}
		db.ignore(256, '\n');
	}
	if (flag) {
		char line[512];
		db.getline(line, 512, '\n');
		cout << id << ' ' << line << endl;
	}
	else {
		cerr << "Record not found!" << endl;
	}
}
void readCommands(ifstream& dbI, ofstream& dbO, const char* path) {
	bool flag = true;
	char cmd[256], plane[256], type[256];
	int id;
	short flight;
	do {
		cin >> cmd;
		cin.ignore();
		if (!strcmp(cmd, "exit")) {
			flag = false;
			continue;
		}
		if (!strcmp(cmd, "create")) {
			cin >> id;
			cin.ignore();
			cin.getline(plane, 255, ' ');
			cin.getline(type, 255, ' ');
			cin >> flight;
			cin.ignore();
			Flights st(id, plane, type, flight);
			create(dbO, dbI, st);
		
			continue;
		}
		if (!strcmp(cmd, "sequentialSearch")) {
			cin >> id;
			cin.ignore();
			sequentialSearch(id, dbI);
			continue;
		}
		
	} while (flag);
}
void updateDb(ifstream& dbI, ofstream& dbO, const char* path) {
	dbI.close();
	dbO.close();
	dbO.open(path, ios::out | ios::app);
	dbI.open(path, ios::in);
}