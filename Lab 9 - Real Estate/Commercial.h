#include "Property.h"
#include <iostream>
#include <string>
#include <sstream>
#pragma once
using namespace std;

class Commercial : public Property {
protected:
	bool discountStatus;
	double discountRate;

public:
	Commercial::Commercial(bool rental, int value, bool discountStatus, double discountRate, string address);
	~Commercial();
	bool getDiscountStatus();
	double getDiscountRate();
	virtual double getTax();
	virtual string toString();
};
