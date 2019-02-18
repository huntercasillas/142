#pragma once
#include <string>
#include <sstream>

using namespace std;

class Property {
protected:
	bool rental;
	int value;
	string address;
	double tax;


public:
	Property::Property(bool rental, int value, string address);
	Property::Property();
	~Property();
	string getAddress();
	int getValue();
	bool getRental();
	virtual double getTax()=0;
	int getID() const;
	virtual string toString()=0;
	int ID = 0;
};
