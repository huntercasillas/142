/*
Hunter Casillas
87-647-3173
CS 142 Fall 2015 Midterm 2 Exam

I could not find a way to properly translate each sentence into pig latin, so I focused on translating what I could actually do. 
My code prompts the user for phrases until he or she types "opstay".
It then stores each word into a designated vector and prints out the user phrase after the sentinel "#" is entered. 
It checks to see if the first letter of each word in each phrase is a vowel.
If it is in fact a vowel, it stores these words in a seperate designated vector. 
It then adds "yay" to the end of each word beggining with a vowel and prints them out underneath the user's entire printed phrase.
This translates all words starting with and/or consisting entirely of vowels into proper Pig Latin.

For testing purposes, I avoided all punctuation since my code is designed to work differently then the actual midterm requirements.

Test Cases:

Test 1: A mixture of words starting with both vowels and consonants.

Input - What an amazing and incredible program this is
Expected - 
Print words: What an amazing and incredible program this is
Here is the Translation for words begining with a vowel: anyay amazingyay andyay incredibleyay isyay
Output - 
Print words: What an amazing and incredible program this is
Here is the Translation for words begining with a vowel: anyay amazingyay andyay incredibleyay isyay


Test 2: A phrase with no words begining with a vowel.

Input - This might be the craziest sentence possibly created
Expected -
Print words: This might be the craziest sentence possibly created
Here is the Translation for words begining with a vowel: 
Output -
Print words: This might be the craziest sentence possibly created
Here is the Translation for words begining with a vowel:

Test 3: A phrase with all words begining with a vowel.

Input - Amazing otters are intelligent and amusing
Expected -
Print words: Amazing otters are intelligent and amusing
Here is the Translation for words begining with a vowel: Amazingyay ottersyay areyay intelligentyay andyay amusingyay
Output -
Print words: Amazing otters are intelligent and amusing
Here is the Translation for words begining with a vowel: Amazingyay ottersyay areyay intelligentyay andyay amusingyay

Test 4: Words that contain only vowels and not a single consonant

Input - ooooo aaa iiii uu
Expected -
Print words: ooooo aaa iiii uu
Here is the Translation for words begining with a vowel: oooooyay aaayay iiiiyay uuyay
Output -
Print words: ooooo aaa iiii uu
Here is the Translation for words begining with a vowel: oooooyay aaayay iiiiyay uuyay

Test 5: Entering the word "opstay"

Input - opstay
Expected - 
...All done!
Output -
...All done!

*/

#include <iostream> //Including libraries needed
#include <string>
#include <vector>

using namespace std; //Must include for code to work in C++

int main() {
	vector<string> words(0); //Declaring a vector for all words
	vector<string> vowels(0); //Declaring a vector for words that begin with a vowel
	string input; //Declaring some additional variables
	string vowel;

	cout << "Starting..." << endl;
	cout << endl << "Please enter a phrase to translate (or opstay to stop) - then enter # to finish: "; //Prints starting instructions

    while (input != "opstay") { //Loops each input until "opstay" is entered, which terminates the program
    
		cin >> input; //Gets user input
		string vowel = input.substr(0, 1); //Takes first letter of user's word and stores it in string vowel
		
        //This statement checks to see if the newly created string vowel is in fact a vowel
		if (vowel == "A" || vowel == "E" || vowel == "I" || vowel == "O" || vowel == "U" || vowel == "a"
            || vowel == "e" || vowel == "i" || vowel == "o" || vowel == "u") {
			vowels.push_back(input); //Stores all words with vowels as their first letter into the vector vowels
		}
        
		cin.ignore();
		words.push_back(input); //Stores all words regardless into the vector words

        if (input == "#") { //Checks to see if the user inputs the sentinel to signify they are done with their phrase
            
			words.pop_back(); //Removes the "#" from the words vector
			cout << "Print Words: ";
            
            for (int i = 0; i < words.size(); i++) { //Prints each word stored inside the words vector
				cout << words[i] << " ";
			}
            
			cout << endl << "Here is the Translation for words begining with a vowel: ";
            
            for (int i = 0; i < vowels.size(); i++) {//Prints each word stored inside the vowels vector
				cout << vowels[i] << "yay" << " ";
			}
		
			cout << endl << endl << "Please enter a phrase to translate (or opstay to stop) - then enter # to finish: ";
			vowels.clear(); //Clears the vector of vowels to start again
			words.clear(); //Clears the vector of words in order to start a new sentence without keeping old words
            
        } else if (input == "opstay") { //Entering opstay will quit the program
			cout << "...All done!" << endl;
			system("pause");//Adding a system pause allows the user to see "...All done!" before exiting the program
			return 0; //Returning 0 ends the program
		}
	}
	system("pause");
	return 0;
}
