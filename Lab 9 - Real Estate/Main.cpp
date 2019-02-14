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


void display_all(vector<Property*> all_properties)
{
	cout << "\nAll valid properties:\n" << endl;
	for (int i = 0; i < all_properties.size(); i++)
	{
		cout << all_properties[i]->toString();
		cout << endl;
	}

}



void load_file(string fileName, vector<Property*> &all_properties)
{
	int ID = 0;

	ifstream inFile;
	inFile.open(fileName.c_str());

	if (!inFile.good()) {					// check to see if the file opened
		cout << "File: " << fileName << " doesn't exist." << endl;
		system("pause");
		exit(EXIT_FAILURE);					// bail out!
	}

	string line;// Will get one line of input at a time.

	while (getline(inFile, line))// Read one line, until there are none left.
	{
		stringstream inLine(line);// Put the line read into a stringstream.
		string type;
		bool rental;
		int value;
		bool occupied;
		bool discountStatus;
		double discountRate;
		string address;

		if (inLine >> type)//insert first part into "type" variable
		{

			if (type == "Residential")//If the object is Residential, parse the data this way
			{
				if (inLine >> rental >> value >> occupied && getline(inLine, address))
				{
					Property* r = new Residential(rental, value, occupied, address);
					all_properties.push_back(r);
					r->ID = ID;
					ID++;

				}
				else
				{
					cout << "Ignoring bad RESIDENTIAL in input file: " << inLine.str() << endl; // complain
				}

			} // end of Residential if-statement


			else if (type == "Commercial")	//If the object is Commercial, pare the data this way
			{
				if (inLine >> rental >> value >> discountStatus >> discountRate && getline(inLine, address))
				{
					Property* c = new Commercial(rental, value, discountStatus, discountRate, address);
					all_properties.push_back(c);
					c->ID = ID;
					ID++;

				}
				else
				{
					cout << "Ignoring bad COMMERCIAL in input file: " << inLine.str() << endl; // complain
				}
			} // end of Commercial if-statement
			else
			{
				cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl; // complain
			}

		}//end of Type if-statement
		else
		{
			cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl; // complain
		}



	}// end of while loop

	inFile.close();
	return;
}//end of function


void tax_report(vector<Property*> all_properties)
{
	int value;
	double discountRate;
	bool rental;

	cout << "NOW PRINTING TAX REPORT:********************************************************************" << endl << endl << endl;
	for (int i = 0; i < all_properties.size(); i++)
	{

		cout << "**Taxes due for the property at:\t\t" << all_properties[i]->getAddress() << endl;
		cout << "Property ID: \t\t\t\t\t" << all_properties[i]->getID() << endl;
		cout << "This Property has an estimated value of: \t" << all_properties[i]->getValue() << endl;
		cout << "Taxes due on this property are: \t\t" << fixed << setprecision(2) << all_properties[i]->getTax() << endl << endl << endl;//This doesn't work because it's different for Residential
	}
}



int main()
{
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


