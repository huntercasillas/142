#include "Property.h"
#include <string>
#include <sstream>
#pragma once
using namespace std;

class Residential : public Property {
protected:
	bool occupied;

public:
	Residential::Residential(bool rental, int value, bool occupied, string address);
	~Residential();
	bool getOccupied();
	virtual double getTax();
	virtual string toString();
};
