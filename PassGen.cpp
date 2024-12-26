#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Color codes
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
    cout << YELLOW << "This program will help you create a secure and random password.\n";
    cout << YELLOW << "You will be able to customize your password based on various criteria.\n";
    cout << YELLOW << "Let's get started!\n\n" << RESET;
    
    // Choosing the amount of passwords
	cout << CYAN << ("How many passwords would you like to generate?\n") << RESET;
    cout << BRIGHT_YELLOW << "Please enter a number between 1 and 10 (inclusive): " << RESET;
    
    while (true) {
		cin >> amount;
		
		// user enters non-numeric character
		if (cin.fail()) { 
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
		
		// user enters non-numeric character
		if (cin.fail()) { 
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
	
	bool duplicate = false;
	bool includeLowercase = false;
	bool includeUppercase = false;
	bool includeDigits = false;
	bool includeSpecialChars = false;
	bool includeSimilarChars = false;
	bool includeDuplicateChars = false;
	
	while (charSet.size() < length) {

		// Choosing Lowercase letters a-z
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
			cout << GREEN << "Lowercase characters added.\n";
			includeLowercase = true;
		}
		else {
			cout << RED << "Lowercase characters not added.\n";
		}
		
		//Choosing Uppercase letters A-Z
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
			cout << GREEN << "Uppercase characters added.\n";
			includeUppercase = true;
		}
		else {
			cout << RED << "Lowercase characters not added.\n";
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
			cout << GREEN << "Numeric characters added.\n";
			includeDigits = true;
		}
		else {
			cout << RED << "Numeric characters not added.\n";
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
			cout << GREEN << "Special characters added.\n";
			includeSpecialChars = true;
		}
		else {
			cout << RED << "Specail characters not added.\n";
		}
		
		// Using Similar Characters
		cout << CYAN << "\nInclude similar-looking characters, including 'i', 'l', '1', 'L', 'o', '0', and 'O'.?\n" << RESET;
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
	       
	    if (choice != 'Y') {
	    	string similar = "il1Lo0OI|!";
	    	
	    	for (int i = 0 ; i < similar.length(); i++) {
	    		auto itr = find(charSet.begin(), charSet.end(), similar[i]);
	    			
				if (itr != charSet.end()) {
					itr = charSet.erase(itr);
				}
			}		
			cout << RED << "Similar characters will not be used.\n";
		}
		else {
			cout << GREEN << "Similar characters will be used.\n";
			includeSimilarChars = true;
		}
	   	
		// Include Duplicate Characters
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
	    
	    if (choice == 'Y') {
	    	duplicate = true;
			cout << GREEN << "Duplicate characters will be used.\n";
			includeDuplicateChars = true;
		}
		else {
			cout << RED << "Duplicate characters will not be used.\n";
		}
		
		cout << BLUE << "\n--- Summary of Your Selections ---\n" << RESET;
		cout << CYAN << "Lowercase characters: " << (includeLowercase ? GREEN : RED) << (includeLowercase ? "Yes" : "No") << RESET << endl;
		cout << CYAN << "Uppercase characters: " << (includeUppercase ? GREEN : RED) << (includeUppercase ? "Yes" : "No") << RESET << endl;
		cout << CYAN << "Numeric characters: " << (includeDigits ? GREEN : RED) << (includeDigits ? "Yes" : "No") << RESET << endl;
		cout << CYAN << "Special characters: " << (includeSpecialChars ? GREEN : RED) << (includeSpecialChars ? "Yes" : "No") << RESET << endl;
		cout << CYAN << "Similar characters: " << (includeSimilarChars ? GREEN : RED) << (includeSimilarChars ? "Yes" : "No") << RESET << endl;
		cout << CYAN << "Duplicate characters: " << (includeDuplicateChars ? GREEN : RED) << (includeDuplicateChars ? "Yes" : "No") << RESET << endl;

		
		if (charSet.size() < length) {
			cout << RED << "\nYou haven't selected enough characters to generate a password of this length." << RESET;
    		cout << CYAN << "\nPlease select more character types (e.g., add lowercase, uppercase, digits, or special characters).\n" << RESET;
		}
	}
	
    cout << GREEN << "\nThank you for your input! Here are you passwords based on your selections.\n\n" << RESET;
    
    srand(time(NULL));
    string password = "";
    int selected;
    
    for (int i = 1; i <= amount; ++i) {
    	while (password.length() != length) {
    		selected = rand() % charSet.size();
    		
    		if (duplicate != true) {
    			if (password.find(charSet[selected]) == string::npos) {
    				password = password + charSet[selected];
				}
			}
			else {
				password = password + charSet[selected];
			}
		}
		cout << i << ") " << password << endl;
		password = "";
	}
	return 0;
}

	
