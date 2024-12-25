#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// Color codes
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define BRIGHT_YELLOW "\033[1;33m"

int main() {
	
	vector<char> charSet;
	char choice;
	int length, amount;
	
	cout << BLUE << "--- Welcome to PassGen ---\n" << RESET;
    cout << CYAN << "This program will help you create a secure and random password.\n";
    cout << CYAN << "You will be able to customize your password based on various criteria.\n";
    cout << CYAN << "Let's get started!\n\n" << RESET;
    
    // Choosing the amount of passwords
	cout << CYAN << ("How many passwords would you like to generate?\n") << RESET;
    cout << BRIGHT_YELLOW << "Please enter a number between 1 and 10 (inclusive): " << RESET;
    
    while (true) {
		cin >> amount;
		
		if (cin.fail()) { // user enters non-numeric character
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << RED << "\nInvalid input. Please enter a number between 1 and 10 (inclusive).\n" << RESET;
			cout << BRIGHT_YELLOW << "Length: " << RESET;
		}
		else if (amount >= 1 && amount <= 10) {
            break;
        } 
		else {
            cout << RED << "Invalid input. Please enter a number between 1 and 10 (inclusive).\n" << RESET;
            cout << BRIGHT_YELLOW << "Length: " << RESET;
        }
	}

	// Choosing the length of the password
	cout << CYAN << "\nHow long would you like your password to be?\n"  << RESET;
    cout << BRIGHT_YELLOW << "Please enter a number between 8 and 32 (inclusive): " << RESET;
	
	while (true) {
		cin >> length;
		
		if (cin.fail()) { // user enters non-numeric character
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << RED << "\nInvalid input. Please enter a number between 8 and 32 (inclusive).\n" << RESET;
			cout << BRIGHT_YELLOW << "Length: " << RESET;
		}
		else if (length >= 8 && length <= 32) {
            break;
        } 
		else {
            cout << RED << "\nInvalid input. Please enter a number between 8 and 32 (inclusive).\n" << RESET;
            cout << BRIGHT_YELLOW << "Length: " << RESET;
        }
	}
	
	bool populated = false;
	
	while (populated == false) {

		// Choosing letters a-z
		cout << CYAN << "\nInclude characters (a-z)?\n" << RESET;
		cout << YELLOW << "[Y] Yes" << RESET << endl;
		cout << YELLOW << "[N] No" << RESET << endl;
		cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		cin >> choice;
		choice = toupper(choice);
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice != 'Y' && choice != 'N') {
		    cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
		    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		    cin >> choice;
		    choice = toupper(choice);
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if (choice == 'Y') {
			for (int i = 97; i <= 122; i++) {
				charSet.push_back(i);
			}
			populated = true;
		}
		
		//Choosing letters A-Z
		cout << CYAN << "\nInclude characters (A-Z)?\n" << RESET;
		cout << YELLOW << "[Y] Yes" << RESET << endl;
		cout << YELLOW << "[N] No" << RESET << endl;
		cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		cin >> choice;
		choice = toupper(choice);
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice != 'Y' && choice != 'N') {
		    cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
		    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		    cin >> choice;
		    choice = toupper(choice);
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if (choice == 'Y') {
			for (int i = 65; i <= 90; i++) {
				charSet.push_back(i);
			}
			populated = true;
		}
		
		//Choosing numbers 0-9
		cout << CYAN << "\nInclude characters (0-9)?\n" << RESET;
		cout << YELLOW << "[Y] Yes" << RESET << endl;
		cout << YELLOW << "[N] No" << RESET << endl;
		cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		cin >> choice;
		choice = toupper(choice);
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice != 'Y' && choice != 'N') {
		    cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
		    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		    cin >> choice;
		    choice = toupper(choice);
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if (choice == 'Y') {
			for (int i = 48; i <= 57; i++) {
				charSet.push_back(i);
			}
			populated = true;
		}
		
		//Choosing special characters
		cout << CYAN << "\nInclude special characters (*%#!)?\n" << RESET;
		cout << YELLOW << "[Y] Yes" << RESET << endl;
		cout << YELLOW << "[N] No" << RESET << endl;
		cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		cin >> choice;
		choice = toupper(choice);
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice != 'Y' && choice != 'N') {
		    cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
		    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
		    cin >> choice;
		    choice = toupper(choice);
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if (choice == 'Y') {
			for (int i = 33; i <= 47; i++) {
				charSet.push_back(i);
			}
			
			for (int i = 58; i <= 64; i++) {
				charSet.push_back(i);
			}
			
			for (int i = 91; i <= 96; i++) {
				charSet.push_back(i);
			}	
			
			for (int i = 123; i <= 126; i++) {
				charSet.push_back(i);
			}
			populated = true;	
		}
		
		if (populated == false) {
			cout << RED << "\nInvalid input: You didn't select any charachters. You must choose at least 1 charachter set.\n" << RESET;
		}
	}
	
	// Using Similar Characters
	cout << CYAN << "\nExclude similar-looking characters, including 'i', 'l', '1', 'L', 'o', '0', and 'O'.?\n" << RESET;
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
       
    if (choice == 'Y') {
    	string similar = "il1Lo0OI|!";
    	
    	for (int i = 0 ; i < similar.length(); i++) {
    		auto itr = find(charSet.begin(), charSet.end(), similar[i]);
    			
			if (itr != charSet.end()) {
				itr = charSet.erase(itr);
			}
		}		
	}
   	
	// Include sequence of characters
	cout << CYAN << "\nWould you like to use the same character more than once?\n" << RESET;
    cout << CYAN << "Example: ('1234', 'abc') in your password?" << RESET << endl;
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        cout << RED << "\nInvalid input. Please enter a 'Y' or 'N'.\n" << RESET;
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    bool duplicate = false;
    
    if (choice == 'Y') {
    	duplicate = true;
	}
	
    cout << GREEN << "\nThank you for your input! Your password will be generated based on your selections.\n" << RESET;
	
	return 0;
}

	