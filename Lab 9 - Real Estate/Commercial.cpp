#include <string>
#include <sstream>
#include "Commercial.h"
#include "Property.h"
#pragma once
using namespace std;

Commercial::Commercial(bool rental, int value, bool discountStatus_in, double discountRate_in, string address) :Property(rental, value, address)
{

	discountStatus = discountStatus_in;
	discountRate = discountRate_in;
}
//-----------------------------------------------------------------------------------------------------------------------
Commercial::~Commercial(){}
//-----------------------------------------------------------------------------------------------------------------------
bool Commercial::getDiscountStatus()
{
	return discountStatus;
}
//-----------------------------------------------------------------------------------------------------------------------
double Commercial::getDiscountRate()
{
	return discountRate;
}
//-----------------------------------------------------------------------------------------------------------------------
double Commercial::getTax()
{
	double taxRate;

	if (rental)
	{
		taxRate = 0.012;
	}
	else
	{
		taxRate = 0.01;
	}
	if (discountStatus)
	{
		tax = (value * (1.00 - discountRate)) * taxRate;
	}
	else
	{
		tax = value * taxRate;
	}
	return tax;
}
//-----------------------------------------------------------------------------------------------------------------------
string Commercial::toString()
{
	string RENTAL;
	if (rental == 1)
	{
		RENTAL = "Rental";
	}
	else
	{
		RENTAL = "NOT Rental";
	}

	string DISCOUNTSTATUS;
	if (discountStatus == 1)
	{
		DISCOUNTSTATUS = "Discounted";
	}
	else
	{
		DISCOUNTSTATUS = "NOT Discounted";
	}

	stringstream ss;
	ss << "Property ID: " << ID << " " << "Address:" << address << " " << RENTAL << " " << "Estimated Value: " << value << " " << DISCOUNTSTATUS << " " << "Discount " << discountRate << endl;
	return ss.str();
}
