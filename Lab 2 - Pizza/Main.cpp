#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
	cout << "How many guests are attending the event? ";
	int guests;
	cin >> guests;

	const int PEOPLE_PER_PIZZA_LARGE = 7; 
	const int PEOPLE_PER_PIZZA_MEDIUM = 3;
	const int PEOPLE_PER_PIZZA_SMALL = 1;

	int pizza_large = guests / 7;
	int pizza_medium = (guests % 7) / 3;
	int pizza_small = (guests % 7) % 3;

	cout << "Large Pizzas: " << pizza_large << endl; 
	cout << "Medium Pizzas: " << pizza_medium << endl;
	cout << "Small Pizzas: " << pizza_small << endl;

	const double PI = 3.14159; 
	const double DIAMETER_LARGE = 20.;
	const double DIAMETER_MEDIUM = 16.;
	const double DIAMETER_SMALL = 12.;

	double pizza_large_area = PI * pow(DIAMETER_LARGE / 2, 2.); 
	double pizza_medium_area = PI * pow(DIAMETER_MEDIUM / 2, 2.);
	double pizza_small_area = PI * pow(DIAMETER_SMALL / 2, 2.);

	double pizza_area = (pizza_large_area * pizza_large) + (pizza_medium_area * pizza_medium) + (pizza_small_area * pizza_small);

	cout << "Total Area of Pizza Needed: " << fixed << setprecision(4) << pizza_area << " sq in" << endl; 

	double pizza_area_guest = pizza_area / guests;

	cout << "Total Area of Pizza Needed per Guest: " << fixed << setprecision(4) << pizza_area_guest << " sq in" << endl; 

	const double price_large = 14.68; 
	const double price_medium = 11.48;
	const double price_small = 7.28;

	cout << "What percentage would you like to tip? "; 
	int tip_percent;
	cin >> tip_percent;

	double pizza_cost = (price_large * pizza_large) + (price_medium * pizza_medium) + (price_small * pizza_small); 
	double tip = pizza_cost * (tip_percent / 100.);
	double pizza_cost_total = pizza_cost + tip; 

	cout << fixed << setprecision(0) << "Total Cost: $" << pizza_cost_total << endl; 

	system("pause");
	return 0;
}
