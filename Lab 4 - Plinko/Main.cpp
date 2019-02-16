/*
Test Cases:

#1
Input: d, 1,
Output: [1, 0.5, 0, 0.5, 0, 0.5, 1, 1.5, 2, 2.5. 3, 2.5, 3], winnings: $0

#2
Input: m, 2, 2
Output: Ave-$250, Total-$500

#3
Input: m, 100, 8
Output: Ave-$1084, Total-$108400
*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    
	int menu = 1;
    while (menu == 1) {
		cout << "MENU: Please select one of the following options: \n1 - Drop a single chip into one slot\n2 - Drop multiple chips into one slot\n3 - Quit the program\nEnter your selection here:";
		string menuoption = "";
		cin >> menuoption;
		int slotnumber = 0;// declare some variables
		int chipnumber = 0;
		double location = slotnumber;
		double reward = 0;
		srand(time(0));
		const double PRZ0 = 100;
		const double PRZ1 = 500;
		const double PRZ2 = 1000;
		const double PRZ3 = 0;
		const double PRZ4 = 10000;
		const double PRZ5 = 0;
		const double PRZ6 = 1000;
		const double PRZ7 = 500;
		const double PRZ8 = 100;


        if (menuoption == "1") { // single chip
            
			cout << "Select a slot (0-8): ";
			cin >> slotnumber;

            if (slotnumber >= 0 && slotnumber <= 8) { //for loop to simulate random falling of chip
				double location = slotnumber;
				cout << location << endl;
                
                for (int i = 0; i < 12; i++) { // simulate chip drop

					double random = rand() % 2;
                    if (random < 1) {
						location = location + 0.5;
                    } else {
						location = location - 0.5;
					}
                    
                    if (location < 0) {
						location = 0.5;
                    } else if (location > 8) {
						location = 7.5;
					}
					cout << location << endl;
				}
                
                // if statements to determine winnings
				if (location == 0) {
                    reward = PRZ0;
                }
				else if (location == 1) { reward = PRZ1; }
				else if (location == 2) { reward = PRZ2; }
				else if (location == 3) { reward = PRZ3; }
				else if (location == 4) { reward = PRZ4; }
				else if (location == 5) { reward = PRZ5; }
				else if (location == 6) { reward = PRZ6; }
				else if (location == 7) { reward = PRZ7; }
				else if (location == 8) { reward = PRZ8; }
			}
			cout << "Winnings: $" << reward << endl;
			cout << endl << endl << endl;
        } else if (menuoption == "2") { // multiple chips options
		
			cout << "Please enter the number of chips to drop: ";//multiple chips input
			cin >> chipnumber;
            
            if (chipnumber > 0) {
				cout << "Please select a slot (0-8): ";
				cin >> slotnumber;

                if (slotnumber >= 0 && slotnumber <= 8) {
					double location = slotnumber;
					double totalwinnings = 0;

                    for (int i = 0; i < chipnumber; i++) { // simulate chip drop for multiple chips
						totalwinnings = totalwinnings + reward;

                        for (int i = 0; i < 12; i++) { // simulate chip drop for a single chips
							double random = rand() % 2;
                            
                            if (random < 1) {
								location = location + 0.5;
                            } else {
								location = location - 0.5;
							}
                            
                            if (location < 0) {
								location = 0.5;
							}
                            else if (location > 8) {
								location = 7.5;
							}
						}
                        
                        // if statements to determine individual winnings
						if (location == 0) {
                            reward = 100;
                        }
						else if (location == 1) { reward = 500; }
						else if (location == 2) { reward = 1000; }
						else if (location == 3) { reward = 0; }
						else if (location == 4) { reward = 10000; }
						else if (location == 5) { reward = 0; }
						else if (location == 6) { reward = 1000; }
						else if (location == 7) { reward = 500; }
						else if (location == 8) { reward = 100; }

						location = slotnumber;
					}
					double average = totalwinnings / chipnumber;// calculate total winnings for multiple chips
					cout << "Average winnings per chip: $" << average << endl;
					cout << "Total winnings: $" << totalwinnings << endl;
					cout << endl << endl << endl;

				}
			}
		} else if (menuoption == "3") { // quit option
			return 0;
        } else if (menuoption != "1" || menuoption != "2" || menuoption != "3") {
			cout << "Invalid Selection. Please enter 1, 2, or 3" << endl << endl;
		}
	}
	system("pause");
	return 0;
}
