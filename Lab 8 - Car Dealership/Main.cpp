/*
Test Cases:

Test Case 1
I displayed the inventory - it did not display anything because the inventory was empty.
I displayed the balance - it displayed 10000 because I hadn't altered the original inventory.
Buy a Car: I added "Jeep Black 2000" - it added it to the vector.
Display balance: The balance displayed 8000 since we spent 2000 on a jeep.
Paint a Car: I tried to paint "Jeep" from black to blue - the color was updated.
Buy a Car: I added "Audi White 4000" - it added it to the vector.
Buy a Car: I added "Cadillac Black 3000" - it added it to the vector.
Save a File: "cars1.txt". It wrote it to the file and saved it.

Test Case 2
Loaded File "cars1.txt"
Displayed inventory properly
Balance was also correct with $2000 - Adding the current $1000 balance to the balance from the file
Buy a Car: Buy "Honda Red 1000"
New Balance: $1000
Sell a Car: "Honda"
Inventory: 2 Jeep, 2 Audi, 2 Cadillac
Balance: $2000

Test Case 3
Loaded File "cars1.txt"
New Balance from file and current: $3000
Sell a Car: "Audi"
New Balance: $7000
New Inventory: 3 Jeep, 2 Audi, 3 Cadillac,
Save a File "cars2.txt"
Inventory: Displays all the info in "cars2.txt"
Buy a Car: "Infiniti Silver 3000"
Updated Balance: $4000
Save a File: cars3.txt
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Car.h"

using namespace std;

// Inventory Function
void display_inventory(vector<Car> all_cars) {
	cout << "Inventory:" << endl;
	for (int i = 0; i < all_cars.size(); i++) {
		cout << all_cars[i].toString();
	}
}

// Find Car Function
int find_car(vector<Car> all_cars, string your_choice) {
	for (int index = 0; index < all_cars.size(); index++) {
		if (your_choice == all_cars[index].getName()) {
			return index;
		}
	}
	return -1;
}

// Display Balance Function
void display_balance(vector<Car> all_cars, double &balance) {
	cout << "Balance: " << fixed << setprecision(2) << balance << endl;
}

// Buy Car Function
void buy_car(vector<Car> &all_cars, double &balance) {
	string name;
	string color;
	double price;

	cout << "Please enter the Name, Color, and Price (hit enter after each): " << endl;

	cin >> name;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
    
	cin >> color;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
    
	cin >> price;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}
    
	Car new_car(name, color, price);

	string your_choice = name;
	int found = find_car(all_cars, your_choice);

	if (balance - price < 0 || found != -1) {
		cout << "Car not added to the vector, you do not have enough money to buy this car." << endl;
    } else {
		all_cars.push_back(new_car);
		balance -= new_car.getPrice();
	}
}

// Sell Car Function
void sell_car(vector<Car> &all_cars, double& balance) {
	string sell_car_name;
	cout << "Please enter the car to be sold: " << endl;
	cin >> sell_car_name;

	string your_choice = sell_car_name;
	int found = find_car(all_cars, your_choice);

	if (found != -1) {
		Car sell_car = all_cars[found];
		balance += sell_car.getPrice();
		all_cars.erase(all_cars.begin() + found);
	}
	
    if (found == -1) {
		cout << "Sorry, that car is not in our inventory" << endl;
	}
}

// Paint Car Function
void paint_car(vector<Car> &all_cars, double &balance) {
	string paint_car_name;
	cout << "Which car do you want to paint? " << endl;
	cin >> paint_car_name;

	string your_choice = paint_car_name;
	int found = find_car(all_cars, your_choice);
	Car paint_car = all_cars[found];

	string new_color;
	cout << "What color?" << endl;
	cin >> new_color;

	paint_car.paint(new_color);
	all_cars[found] = paint_car;
}

// Load File Function
void load_file(vector<Car> &all_cars, double &balance) {
	string file_name;
	double file_balance;
	string name;
	string color;
	double price;

	ifstream input_file;
	cout << "File name? " << endl;
	cin >> file_name;
	input_file.open(file_name.c_str());

	input_file >> file_balance;

	while (input_file >> name) {
		input_file >> color;
		input_file >> price;
		Car new_car(name, color, price);
		all_cars.push_back(new_car);
	}
	balance += file_balance;
}

// Save File Function
void save_file(vector<Car> all_cars, double balance) {
	string name;
	string color;
	double price;
	string file_name;
	ofstream save_file;
	cout << "File name?" << endl;
	cin >> file_name;

	save_file.open(file_name);

	save_file << fixed << setprecision(2) << balance << "\n";

	for (int i = 0; i < all_cars.size(); i++) {
		name = all_cars[i].getName();
		color = all_cars[i].getColor();
		price = all_cars[i].getPrice();

		save_file << name << " ";
		save_file << color << " ";
		save_file << price << "\n";
	}
	save_file.close();
}

// Main Function
int main() {
	double balance = 10000;

	vector<Car> all_cars;

	int menu = 0;
	while (menu == 0) {
		cout << endl << "\tMain Menu" << endl << endl;
		cout << "(1) Show Current Inventory\n(2) Show Current Balance\n(3) Buy a Car\n(4) Sell a Car\n(5) Paint a Car\n(6) Load a File\n(7) Save File\n(8) Quit Program" << endl;
		cout << "Please make your selection here: ";

		string input;
		cin >> input;

		if (input == "1") {
			display_inventory(all_cars);
        } else if (input == "2") {
			display_balance(all_cars, balance);
        } else if (input == "3") {
			buy_car(all_cars, balance);
        } else if (input == "4") {
			sell_car(all_cars, balance);
        } else if (input == "5") {
			paint_car(all_cars, balance);
        } else if (input == "6") {
			load_file(all_cars, balance);
        } else if (input == "7") {
			save_file(all_cars, balance);
        } else if (input == "8") {
			menu = 0;
			return 0;
		}
	}

	system("pause");
	return 0;
}
