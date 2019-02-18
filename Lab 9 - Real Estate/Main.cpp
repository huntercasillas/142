#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Property.h"
#include "Commercial.h"
#include "Residential.h"

using namespace std;


void display_all(vector<Property*> all_properties) {
	cout << "\nAll valid properties:\n" << endl;
    
	for (int i = 0; i < all_properties.size(); i++) {
		cout << all_properties[i]->toString();
		cout << endl;
	}
}

void load_file(string fileName, vector<Property*> &all_properties) {
	int ID = 0;

	ifstream inFile;
	inFile.open(fileName.c_str());

    // check to see if the file opened
	if (!inFile.good()) {
		cout << "File: " << fileName << " doesn't exist." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	string line;

    // Read one line, until there are none left.
	while (getline(inFile, line)) {
		stringstream inLine(line);
		string type;
		bool rental;
		int value;
		bool occupied;
		bool discountStatus;
		double discountRate;
		string address;

        // insert first part into "type" variable
		if (inLine >> type) {

			if (type == "Residential") {
				if (inLine >> rental >> value >> occupied && getline(inLine, address)) {
					Property* r = new Residential(rental, value, occupied, address);
					all_properties.push_back(r);
					r->ID = ID;
					ID++;
				} else {
					cout << "Ignoring bad RESIDENTIAL in input file: " << inLine.str() << endl;
				}
			} else if (type == "Commercial") {
				if (inLine >> rental >> value >> discountStatus >> discountRate && getline(inLine, address)) {
					Property* c = new Commercial(rental, value, discountStatus, discountRate, address);
					all_properties.push_back(c);
					c->ID = ID;
					ID++;
				} else {
                    cout << "Ignoring bad COMMERCIAL in input file: " << inLine.str() << endl;
				}
			} else {
				cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl;
			}
		} else {
			cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl;
		}
	}
	inFile.close();
	return;
}


void tax_report(vector<Property*> all_properties) {
	int value;
	double discountRate;
	bool rental;

	cout << "NOW PRINTING TAX REPORT:********************************************************************" << endl << endl << endl;
	for (int i = 0; i < all_properties.size(); i++) {
		cout << "**Taxes due for the property at:\t\t" << all_properties[i]->getAddress() << endl;
		cout << "Property ID: \t\t\t\t\t" << all_properties[i]->getID() << endl;
		cout << "This Property has an estimated value of: \t" << all_properties[i]->getValue() << endl;
		cout << "Taxes due on this property are: \t\t" << fixed << setprecision(2) << all_properties[i]->getTax() << endl << endl << endl;
	}
}



int main() {
	vector<Property*> all_properties;

	string fileName;
	cout << "Where is the file?" << endl;
	cin >> fileName;

	load_file(fileName, all_properties);
	display_all(all_properties);

	tax_report(all_properties);

	system("pause");
	return 0;
}
