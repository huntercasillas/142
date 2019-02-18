#include "Property.h"
using namespace std;

Property(bool rental_in, int value_in, string address_in) {
	rental = rental_in;
	value = value_in;
	address = address_in;
}

~Property(){}

string Property::getAddress() {
	return address;
}

int Property::getValue() {
	return value;
}

bool Property::getRental() {
	return rental;
}

double Property::getTax() {
	return tax;
}

int Property::getID() const {
	return ID;
}

string Property::toString() {
	string RENTAL;
    
	if (rental == 0) {
		RENTAL = "Rental";
	} else {
		RENTAL = "NOT Rental";
	}
	stringstream ss;
	ss << "Property ID: " << "-" << "\t" << "Address: " << address << "\t" << "Rental: " << rental << "\t" << "Estimated Value: " << value << endl;
	return ss.str();
}
