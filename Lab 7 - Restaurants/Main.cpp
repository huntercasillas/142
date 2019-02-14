/*
***************TEST CASES*******************
I chose the option to display the vector, and it displayed properly.
I chose the option to add a restaurant. I entered "Chilis". It added "Chilis" to the vector properly and reported that it was added to the vector.
I chose the option to add "Chilis" again. It reported that "Chilis" was already in the vector.
I chose the option to remove a vector. I entered "chilis". It removed "Chilis" from the vector properly.
I chose the option to remove a vector. I entered "Cracker Barrel". It removed "Cracker Barrel" from the vector properly.
I chose the option to remove a vector. I entered "Dog". It reported that "Dog" was not in the vector.
I chose the option to shuffle the vector. It shuffled properly. I checked it by printing out the new vector to the console.
I chose the option to begin the tournament. The program reported I could not begin because the number of restaurants was not equal to 2^n. I had to add restaurants until I reached 2^n.
It displayed two restaurants at a time in appropriate pairs.
It eliminated restaurants one by one until there was one restaurant left in the vector.
The last remaining restaurant printed to the console as the winner.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <math.h> 

using namespace std;

const int NOT_FOUND = -1;

//Initialize Vector
vector<string> initialize()
{
	vector<string> restaurants;
	restaurants.push_back("Cracker Barrel");
	restaurants.push_back("Olive Garden");
	restaurants.push_back("Cafe Rio");
	restaurants.push_back("Sammys");
	restaurants.push_back("JDawgs");
	restaurants.push_back("Texas Roadhouse");
	restaurants.push_back("Zupas");
	restaurants.push_back("Brick Oven Pizza");
	return restaurants;
}

//Print Restaurants Function
void print_restaurants(vector<string>& restaurants)
{
	cout << "Print Vector: " << endl;
	cout << "{";
	for (int index = 0; index < restaurants.size(); index++)
	{
		if (index < restaurants.size() - 1)
		{
			cout << restaurants[index] << ",";
		}
		else
			cout << restaurants[index];
	}
	cout << "}" << endl << endl;
}


//Print Loser Function
void print_losers(vector<string>& losers)
{
	cout << "\nPrint Vector: " << endl;
	cout << "{";
	for (int i = 0; i < losers.size(); i++)
	{
		if (i < losers.size() - 1)
		{
			cout << losers[i] << ",";
		}
		else
			cout << losers[i];
	}
	cout << "}" << endl << endl;
}


//Find Function
int find(string restaurant_name, vector<string> restaurants)
{
	for (int index = 0; index < restaurants.size(); index++)
	{
		if (restaurant_name == restaurants[index])
		{
			return index;
		}
	}
	return NOT_FOUND;
}


//Add Function
void add_restaurant(string restaurant_name, vector<string>& restaurants)
{
	int found = find(restaurant_name, restaurants);
	if (found == NOT_FOUND)
	{
		restaurants.push_back(restaurant_name);
		cout << "The restaurant " << restaurant_name << " was added to the vector" << endl;
	}
	else
	{
		cout << "The restaurant " << restaurant_name << " was not added because it is already there" << endl;
	}
}

//Remove Function
void remove_restaurant(string restaurant_name, vector<string>& restaurants)
{
	int found = find(restaurant_name, restaurants);
	if (found != NOT_FOUND)
	{
		int last_pos = restaurants.size() - 1;
		restaurants.erase(restaurants.begin() + found);
		cout << "The restaurant " << restaurant_name << " was removed from the vector" << endl;
	}
	else
	{
		cout << "The restaurant " << restaurant_name << " was not removed because it was not in the vector" << endl;
	}
}

//Remove Loser Function
void remove_loser_restaurant(string restaurant_name, vector<string>& restaurants)
{
	int found = find(restaurant_name, restaurants);
	if (found != NOT_FOUND)
	{
		int last_pos = restaurants.size() - 1;
		restaurants.erase(restaurants.begin() + found);
	}
	else
	{
		cout << "The restaurant " << restaurant_name << " was not removed because it was not in the vector" << endl;
	}
}

//Shuffle Function
void shuffle_vector(vector<string>& restaurants)
{
	int max_shuffle = 100;
	for (int shuffle = 0; shuffle < max_shuffle; shuffle++)
	{
		int posA = rand() % restaurants.size();
		int posB = rand() % restaurants.size();
		string temp = restaurants[posA];
		restaurants[posA] = restaurants[posB];
		restaurants[posB] = temp;
	}
}

//Tournament Function
string tournament(vector<string>& restaurants)
{
	const int power_base = 2;// determines if the vector size is equal to 2^n
	int integer_exponent = log(restaurants.size()) / log(power_base);
	double double_exponent = log(restaurants.size()) / log(power_base);
	//int length = (restaurants.size())-1;
	int index = 0;
	vector<string> losers;
	string restaurant_name = "";

	if (double_exponent == integer_exponent)
	{
		do//loops for multiple rounds
		{
			for (int i = 0; i < restaurants.size() - 1; i += 2)//loops through all the choices for 1 round
			{
				string competitor1 = restaurants[i];//competitor1 and 2 are joined in pairs
				string competitor2 = restaurants[i + 1];
				cout << endl << competitor1 << " vs " << competitor2 << endl;//standoff
				string winner;
				getline(cin, winner);//user selects winner

				while (winner != restaurants[i] && winner != restaurants[i + 1])//When the user types in something incorrectly
				{
					cout << "invalid, please re-enter" << endl;
					getline(cin, winner);
				}

				if (winner == competitor1)//remove the loser from the vector to narrow down results.
				{
					restaurant_name = competitor2;//give me the index of competitor2 and pass it into an array for restaurants to be deleted
					losers.push_back(restaurant_name);
				}
				else if (winner == competitor2)
				{
					restaurant_name = competitor1;//give me the index of competitor1 and pass it into an array for restaurants to be deleted
					losers.push_back(restaurant_name);
				}
			}
			for (int i = 0; i < losers.size(); i++)//remove all the restaurants indicated in the indexes vector
			{
				restaurant_name = losers[i];
				remove_loser_restaurant(restaurant_name, restaurants);
			}
			losers.clear();
			print_restaurants(restaurants);
			cout << "\n******Time for the next round!******" << endl;
		} while (restaurants.size() > 1);
		cout << "\n And the winner is......" << restaurants[0] << "!!!" << endl << endl;
	}
	else
	{
		cout << "Could not begin tournament. There are not enough restaurants in the tournament (number of restaurants must be 2^n), please add or remove some restaurants." << endl << endl;
		cout << ". Current restaurant size is " << restaurants.size() << " current power is " << double_exponent;
	}
	return restaurant_name;
}

int main()
{
	int menu = 1;
	vector<string> restaurants = initialize();

	cout << "\t\tTournament of Restaurants!" << endl << endl;

	srand(time(0));

	while (menu == 1)//Loops the menu refresh
	{

		cout << "Choose an Option:\n\t(1)Display all restaurants\n\t(2)Add a restaurant\n\t(3)Remove a Restaurant\n\t(4)Shuffle the vector\n\t(5)Begin the tournament\n\t(6)Quit the program" << endl;
		string choice = "";
		cin >> choice;
		cin.ignore();

		if (choice == "1")
		{
			cout << "Option 1: ";
			print_restaurants(restaurants);
		}

		if (choice == "2")
		{
			cout << "Option 2: Enter a restaurant: ";
			string restaurant_name;
			getline(cin, restaurant_name);
			add_restaurant(restaurant_name, restaurants);
		}

		if (choice == "3")
		{
			cout << "Option 3: Enter a restaurant: ";
			string restaurant_name;
			getline(cin, restaurant_name);
			remove_restaurant(restaurant_name, restaurants);
		}

		if (choice == "4")
		{
			cout << "Option 4: The Vector has been shuffled" << endl;

			shuffle_vector(restaurants);
		}

		if (choice == "5")
		{
			cout << "Option 5: Begin the Tournament!" << endl;
			tournament(restaurants);
		}

		if (choice == "6")//Quits the program
		{
			menu = 0;
			return 0;
		}

	}

	system("pause");
	return 0;
}