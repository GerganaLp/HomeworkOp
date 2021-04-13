
#include "Functions.h"

/*
int main() {
	cout << "create\nsequentialSearch\nexit\n";
	//operationParser(); 
	fstream file;
	file.open("Planes.txt", ios::app);
	if (!file) {
		cerr << "File could't be opened!" << endl;
		return 1;
	}
	readCommands(file);
	file.close();
	return 0;
} */
const char* path = "../Plane.db";
int main() {
    ofstream dbO;
    ifstream dbI;
    dbO.open(path, ios::out | ios::app);
    dbI.open(path, ios::in);
    if (!dbO) {
        cerr << "File could't be opened!" << endl;
        return 1;
    }
    if (!dbI) {
        cerr << "File could't be opened!" << endl;
        return 1;
    }
    readCommands(dbI, dbO, path);
    dbO.close();
    dbI.close();
    return 0;
}