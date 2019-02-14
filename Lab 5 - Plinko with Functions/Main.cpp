/* Test Cases

Case 1:
--Single
Input: 1, 3
Output: Winnings: $0
Program Output: Same
--Multiple
Input: 2, 4, 4
Output: Average: $375, Total: $1500
Program Output: Same
--All Slots
Input: 3, 2
Output: 0- $500, $1000; 1 - $300, $600; 2 - $750, $1500; 3 - $300, $600; 4 - $500, $1000; 5 - $250, $500; 6 - $300, $600; 7 - $750, $1500; 8 - $250, $500;
Program Output: Same

Case 2:
Input: 1, 8
Output: $500
Program Output: Same
--Multiple
Input: 2, 2, 8
Output: Average: $50, Total: $100;
Program Output; Same
--All Slots
Input: 3, 10
Output: 0 - $610, $6100; 1 - $310, $3100; 2 - $270, $2700; 3 - $1500, $15000; 4 - $2450, $24500; 5 - $1310, $13100; 6 - $1260, $12600; 7 - $660, $6600; 8 - $480, $4800;
Program Output: Same

Case 3:
Input: 1, 1
Output: $100
Program Output: Same
--Multiple
Input: 2, 8, 1
Output: $225, $1800
Program Output; Same
--All Slots
Input: 3, 5
Output: 0 - $420, $2100; 1 - $2300, $15500; 2 - $2300, $11500; 3 - $200, $1000; 4 - $2200, $11000; 5 - $2600, $13000; 6 - $600, $3000; 7 - $2240, 112,000; 8 - $900, $4500;
Program Output: Same
*/


#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

//--------------------------------Prize Money Function------------------------------------
double get_prize_money(double location)
{
	double prize;
	const double prize0 = 100;
	const double prize1 = 500;
	const double prize2 = 1000;
	const double prize3 = 0;
	const double prize4 = 10000;
	const double prize5 = 0;
	const double prize6 = 1000;
	const double prize7 = 500;
	const double prize8 = 100;

	if (location == 0) { prize = prize0; }
	else if (location == 1) { prize = prize1; }
	else if (location == 2) { prize = prize2; }
	else if (location == 3) { prize = prize3; }
	else if (location == 4) { prize = prize4; }
	else if (location == 5) { prize = prize5; }
	else if (location == 6) { prize = prize6; }
	else if (location == 7) { prize = prize7; }
	else if (location == 8) { prize = prize8; }

	return prize;

}


//---------------------------Single Chip Function-------------------------------------
double single_chip(int slot_number, int chip_number)
{
	double location = slot_number;
	
	if (slot_number >= 0 && slot_number <= 8) //for loop to simulate random falling of chip
	{
		if (chip_number == 1)
		{
			cout << location << endl;
		}
		for (int i = 0; i < 12; i++) // simulate chip drop
		{

			double random = rand() % 2;
			if (random < 1)
			{
				location = location + 0.5;
			}
			else
			{
				location = location - 0.5;
			}
			if (location < 0)
			{
				location = 0.5;
			}
			else if (location > 8)
			{
				location = 7.5;
			}
			if (chip_number == 1)
			{
				cout << fixed << setprecision(1) << location << " ";
			}
		}


	}


	return location;//return final position
}


//-----------------------------------------Multiple Chip Function-----------------------------------------
double multiple_chips(int slot_number, int chip_number)
{
	double location = slot_number;
	double totalwinnings = 0;

	if (chip_number > 0)
	{
		if (slot_number >= 0 && slot_number <= 8)
		{

			for (int i = 0; i < chip_number; i++)
			{
				location = single_chip(slot_number, chip_number);
				totalwinnings = totalwinnings + get_prize_money(location);
			}

		}
	}

	double average = totalwinnings / chip_number;// calculate total winnings for multiple chips
	cout << "\nSlot " << slot_number << endl;
	cout << "Average winnings per chip: $" << average << endl;
	cout << "Total winnings: $" << totalwinnings << endl;

	return location;
}


//--------------------------------------------Multiple Chips in All Slots Function -----------------------------------
double all_slots(int slot_number, int chip_number)
{
	double location = slot_number;
	double totalwinnings = 0;

	for (int i = 0; i <= 8; i++)
	{
		slot_number = i;
		location = multiple_chips(slot_number, chip_number);
		totalwinnings = totalwinnings + get_prize_money(location);
		//cout << "Slot " << slot_number << endl;

	}
	double average = totalwinnings / chip_number;

	return location;
}

//--------------------------------------------Main Function------------------------------------------------
int main()
{
	srand(time(0));
	int menu = 1;
	while (menu == 1)
	{
		cout << "\nMENU:" << endl;
		cout << "Please enter one of the following options to continue: \n\tDrop One (1)\n\tDrop Multiple (2)\n\tDrop Multiple into all the slots (3)\n\tQuit (4): ";
		string menuoption = "";
		cin >> menuoption;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Selection. Please enter a number." << endl;
		}
		double location = 0;
		int slot_number = 0;// declare some variables
		int chip_number = 0;

		if (menuoption == "1")// single chip
		{
			chip_number = 1;
			cout << "Select a slot (0-8): ";
			cin >> slot_number;
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection. Please enter a number." << endl;
			}
			else if (slot_number >= 0 && slot_number <= 8)
			{
				location = single_chip(slot_number, chip_number);
				cout << endl << "Winnings: $" << get_prize_money(location) << endl;
			}
		
		}

		else if (menuoption == "2")// multiple chips options
		{
			cout << "Please enter the number of chips to drop: ";//multiple chips input
			cin >> chip_number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection. Please enter a number." << endl;
			}
			else if (chip_number > 0)
			{
				cout << "Select a slot (0-8): ";
				cin >> slot_number;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid Selection. Please enter a number." << endl;
				}
				else if (slot_number >= 0 && slot_number <= 8)
				{
					location = multiple_chips(slot_number, chip_number);
					/*double average = totalwinnings / chip_number;// calculate total winnings for multiple chips
					cout << "Average winnings per chip: $" << average << endl;
					cout << "Total winnings: $" << totalwinnings << endl;*/
				}
			}
		}

		else if (menuoption == "3")//multiple chips into all the slots
		{
			cout << "Please enter the number of chips to drop: ";
			cin >> chip_number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection. Please enter a number." << endl;
			}
			else if (chip_number > 0)
			{
				location = all_slots(slot_number, chip_number);
			}
		}

		else if (menuoption == "4")// quit option
		{
			return 0;
		}

		else if (menuoption != "1" || menuoption != "2" || menuoption != "3" || menuoption != "4")
		{
			cout << "Invalid Selection. Please enter 1, 2, 3, or 4" << endl << endl;
		}

	}

	system("pause");
	return 0;
}