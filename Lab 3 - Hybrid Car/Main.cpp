/* Test Cases
Test Case 1:

Input:
Miles: 10,000
Gas: 2.5
Hybrid Price: 15000
Hybrid Resale: 1250
Hybrid Efficiency: 40
Non-Hybrid Price: 10000
Non-Hybrid Resale: 7500
Non-Hybrid Efficiency: 20

Output:
Hybrid Total Gallons: 1250
Non-Hybrid Total Gallons: 2500
Hybrid Total Cost: 6875
Non-Hybrid Total Cost: 8750

Test Case 2:

Input:
Miles: 10000
Gas: 2.2
Hybrid Price: 30000
Hybrid Resale: 12000
Hybrid Efficiency: 50
Non-Hybrid Price: 15000
Non-Hybrid Resale: 7500
Non-Hybrid Efficiency: 22

Output:
Hybrid Total Gallons: 1000
Non-Hybrid Total Gallons: 2272.73
Hybrid Total Cost: 20200
Non-Hybrid Total Cost: 12500

Test Case 3:

Input:
Miles: 20000
Gas: 3.5
Hybrid Price: 10000
Hybrid Resale: 6000
Hybrid Efficiency: 25
Non-Hybrid Price: 8000
Non-Hybrid Resale: 4800
Non-Hybrid Efficiency: 15

Output:
Hybrid Total Gallons:
Non-Hybrid Total Gallons:
Hybrid Total Cost:
Non-Hybrid Total Cost:
*/


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    
	const double YEARS = 5;

	cout << "Enter the estimated miles driven per year: ";
	double miles_per_year;
	cin >> miles_per_year;
    
    if (miles_per_year <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> miles_per_year;
	}

	cout << "Enter the estimated gasoline price per gallon during the 5 years of ownership: ";
	double price_per_gallon;
	cin >> price_per_gallon;
    
    if (price_per_gallon <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> price_per_gallon;
	}

	cout << "Enter the initial price of a hybrid car: ";
	double price_hybrid;
	cin >> price_hybrid;
    
    if (price_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> price_hybrid;
	}

	cout << "Enter the efficiency of the hybrid car in miles per gallon: ";
	double efficiency_hybrid;
	cin >> efficiency_hybrid;
    
    if (efficiency_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> efficiency_hybrid;
	}

	cout << "Enter the estimated resale value of the hybrid car after 5 years: ";
	double resale_hybrid;
	cin >> resale_hybrid;
    
    if (resale_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> resale_hybrid;
	}

	cout << "Enter the initial price of a non-hybrid car: ";
	double price_non_hybrid;
	cin >> price_non_hybrid;
    
    if (price_non_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> price_non_hybrid;
	}

	cout << "Enter the efficiency of the non-hybrid car in miles per gallon: ";
	double efficiency_non_hybrid;
	cin >> efficiency_non_hybrid;
    
    if (efficiency_non_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> efficiency_non_hybrid;
	}

	cout << "Enter the estimated resale value of the non-hybrid car after 5 years: ";
	double resale_non_hybrid;
	cin >> resale_non_hybrid;
    
    if (resale_non_hybrid <= 0) {
		cout << "Make sure to enter a positive number: ";
		cin >> resale_non_hybrid;
	}

	string buyer_criterion;
	cout << "Minimized gas or minimized total cost (enter \"Gas\" or \"Total\"): ";
	cin >> buyer_criterion;

	double total_gallons_hybrid = (miles_per_year*YEARS) / efficiency_hybrid;
	double total_gallons_non_hybrid = (miles_per_year * YEARS) / efficiency_non_hybrid;

	double fuel_cost_hybrid = total_gallons_hybrid * price_per_gallon;
	double depreciation_hybrid = price_hybrid - resale_hybrid;
	double total_cost_hybrid = fuel_cost_hybrid + depreciation_hybrid;

	double fuel_cost_non_hybrid = total_gallons_non_hybrid * price_per_gallon;
	double depreciation_non_hybrid = price_non_hybrid - resale_non_hybrid;
	double total_cost_non_hybrid = fuel_cost_non_hybrid + depreciation_non_hybrid;


    if (buyer_criterion == "Gas") {
        
        if (total_gallons_hybrid <= total_gallons_non_hybrid) {
			cout << "Hybrid Car" << endl;
			cout << "Total gallons: " << total_gallons_hybrid << endl;
			cout << "Total cost over 5 years: " << total_cost_hybrid << endl;

			cout << "Non-Hybrid Car" << endl;
			cout << "Total gallons: " << total_gallons_non_hybrid << endl;
			cout << "Total cost over 5 years: " << total_cost_non_hybrid << endl;
        } else {
			cout << "Non-Hybrid Car" << endl;
			cout << "Total gallons: " << total_gallons_non_hybrid << endl;
			cout << "Total cost over 5 years: " << total_cost_non_hybrid << endl;

			cout << "Hybrid Car" << endl;
			cout << "Total gallons: " << total_gallons_hybrid << endl;
			cout << "Total cost over 5 years: " << total_cost_hybrid << endl;

		}
    } else if (buyer_criterion == "Total") {
	
        if (total_cost_hybrid <= total_cost_non_hybrid) {
			cout << "Hybrid Car" << endl;
			cout << "Total cost over 5 years: " << total_cost_hybrid << endl;
			cout << "Total gallons: " << total_gallons_hybrid << endl;

			cout << "Non-Hybrid Car" << endl;
			cout << "Total cost over 5 years: " << total_cost_non_hybrid << endl;
			cout << "Total gallons: " << total_gallons_non_hybrid << endl;
        } else {
			cout << "Non-Hybrid Car" << endl;
			cout << "Total cost over 5 years: " << total_cost_non_hybrid << endl;
			cout << "Total gallons: " << total_gallons_non_hybrid << endl;

			cout << "Hybrid Car" << endl;
			cout << "Total cost over 5 years: " << total_cost_hybrid << endl;
			cout << "Total gallons: " << total_gallons_hybrid << endl;
		}
	}
	system("pause");
	return 0;
}
