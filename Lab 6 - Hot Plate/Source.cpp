#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 20;
const double CHANGE = 0.1;

//Initialize Function
void initial(double hot_plate[SIZE][SIZE])
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (row == 0 || row == 19)
			{
				if (col == 0 || col == 19)
				{
					hot_plate[row][col] = 0;
				}
				else
				{
					hot_plate[row][col] = 100;
				}
			}
			else
			{
				hot_plate[row][col] = 0;
			}
		}
	}
}

//Print Function
void print(double hot_plate[SIZE][SIZE])
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << fixed << setprecision(1) << setw(6) << hot_plate[row][col] << ",";
		}
		cout << endl;
	}
}

//Average Function One
void first_average(double hot_plate[SIZE][SIZE])
{
	const double NEIGHBORS = 4.0;
	double average_temp;

	for (int row = 1; row < SIZE - 1; row++)
	{
		for (int col = 1; col < SIZE - 1; col++)
		{

			average_temp = (hot_plate[row][col - 1] + hot_plate[row + 1][col] + hot_plate[row][col + 1] + hot_plate[row - 1][col]) / NEIGHBORS;
			hot_plate[row][col] = average_temp;

		}
	}

}

//Average Function Two
void average(double hot_plate[SIZE][SIZE])
{
	const double NEIGHBORS = 4.0;
	double average_temp;
	double largest_change = 0;

	do
	{
		largest_change = 0;
		for (int row = 1; row < SIZE - 1; row++)
		{
			for (int col = 1; col < SIZE - 1; col++)
			{
				double old_value = hot_plate[row][col];
				average_temp = (hot_plate[row][col - 1] + hot_plate[row + 1][col] + hot_plate[row][col + 1] + hot_plate[row - 1][col]) / NEIGHBORS;
				hot_plate[row][col] = average_temp;

				double change = abs(old_value - hot_plate[row][col]);
				if (change > largest_change)
				{
					largest_change = change;
				}
			}
		}


	} while (largest_change > CHANGE);

}

//Export Function
void transport(double hot_plate[SIZE][SIZE])
{
	ofstream out;
	out.open("lab6output.csv");

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			out << hot_plate[row][col] << ",";
		}
		out << endl;
	}
	out.close();
}

//Main Program
int main()
{
	double hot_plate[SIZE][SIZE];

	initial(hot_plate);
	print(hot_plate);

	cout << endl << endl;

	first_average(hot_plate);

	print(hot_plate);

	cout << endl << endl;

	average(hot_plate);
	print(hot_plate);

	transport(hot_plate);

	system("pause");
	return 0;
}