#include "Residential.h"
#include "Property.h"
#pragma once
using namespace std;

Residential::Residential(bool rental, int value, bool occupied_in, string address) :Property(rental, value, address) {

	occupied = occupied_in;
}

Residential::~Residential(){}

bool Residential::getOccupied() {
	return occupied;
}

double Residential::getTax() {
	double taxRate;

	if (occupied) {
		taxRate = 0.006;
	} else {
		taxRate = 0.009;
	}

	double tax = value * taxRate;
	return tax;
}

string Residential::toString() {
	string RENTAL;
    
	if (rental == 1) {
		RENTAL = "Rental";
	} else {
		RENTAL = "NOT Rental";
	}

	string OCCUPIED;
    
	if (occupied == 1) {
		OCCUPIED = "occupied";
	} else {
		OCCUPIED = "NOT occupied";
	}

	stringstream ss;
	ss << "Property ID: " << ID << " " << "Address:" << address << " " << RENTAL << " " << "Estimated Value: " << value << " " << OCCUPIED << endl;
	return ss.str();
}
