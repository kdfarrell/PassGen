#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
#include <unordered_set>
#include <vector>

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

// Function to display a message with color
void printMessage(const string& message, const string& color) {
    cout << color << message << RESET << endl;
}

int main() {
	
	char choices[6];
	char choice;
	int length, amount;
	
	printMessage("--- Welcome to PassGen ---", BLUE);
    cout << CYAN << "This program will help you create a secure and random password.\n";
    cout << CYAN << "You will be able to customize your password based on various criteria.\n";
    cout << CYAN << "Let's get started!\n\n" << RESET;
    
    // Choosing the amount of passwords
	printMessage("How many passwords would you like to generate?", CYAN);
    cout << BRIGHT_YELLOW << "Please enter a number between 1 and 10 (inclusive): " << RESET;
    
    while (true) {
		cin >> amount;
		
		if (cin.fail()) { // user enters non-numeric character
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printMessage("\nInvalid input. Please enter a number between 1 and 10 (inclusive).", RED);
			cout << BRIGHT_YELLOW << "Length: " << RESET;
		}
		else if (amount >= 1 && amount <= 10) {
            break;
        } 
		else {
            printMessage("Invalid input. Please enter a number between 1 and 10 (inclusive).", RED);
            cout << BRIGHT_YELLOW << "Length: " << RESET;
        }
	}

	// Choosing the length of the password
	printMessage("\nHow long would you like your password to be?", CYAN);
    cout << BRIGHT_YELLOW << "Please enter a number between 8 and 32 (inclusive): " << RESET;
	
	while (true) {
		cin >> length;
		
		if (cin.fail()) { // user enters non-numeric character
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printMessage("\nInvalid input. Please enter a number between 8 and 32 (inclusive).", RED);
			cout << BRIGHT_YELLOW << "Length: " << RESET;
		}
		else if (length >= 8 && length <= 32) {
            break;
        } 
		else {
            printMessage("Invalid input. Please enter a number between 8 and 32 (inclusive).", RED);
            cout << BRIGHT_YELLOW << "Length: " << RESET;
        }
	}
	
	// Choosing letters a-z
	printMessage("\nInclude characters (a-z)?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[0] = choice;
	
	//Choosing letters A-Z
	printMessage("\nInclude characters (A-Z)?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[1] = choice;
	
	//Choosing numbers 0-9
	printMessage("\nInclude characters (0-9)?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[2] = choice;
	
	//Choosing special characters
	printMessage("\nInclude special characters (*%#!)?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[3] = choice;
	
	//Choosing to exclude characters
	printMessage("\nWould you like to exclude any characters?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[4] = choice;
	
	string exclude;
	unordered_set<char> excluded;
    if (choices[4] == 'Y') {
        cout << BRIGHT_YELLOW << "\nWhat characters would you like to exclude? ";
        cout << "\nCharacters: " << RESET;
        cin.ignore();
        getline(cin, exclude);
    }
    
    for (auto c : exclude) {
    	excluded.insert(c);
	}
    
    
	// Include sequence of characters
	printMessage("\nWould you like to include a specific sequence of characters?", CYAN);
    cout << CYAN << "Example: ('1234', 'abc') in your password?" << RESET << endl;
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("\nInvalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[5] = choice;
	
	string sequence;
    if (choices[5] == 'Y') {
        cout << BRIGHT_YELLOW << "\nWhat characters would you like to include in the sequence? ";
    	cout << "\nCharacters: " << RESET;
        cin.ignore();
        getline(cin, sequence);
        
        while (sequence.length() > length) {
        	printMessage("\nInvalid input. Sequence is longer than length of password", RED);
        	cout << BRIGHT_YELLOW << "Enter Sequence: " << RESET;
        	cin.ignore();
        	getline(cin, sequence);
		}
    }
    
    printMessage("\nThank you for your input! Your password will be generated based on your selections.", GREEN);
	
	srand(time(NULL));
	vector<string> allPasswords;
	string password = "";
	char selectedChar;
	int temp = length;
	
	if (choices[5] == 'Y') {	
		password = password + sequence;
		length = length - sequence.length();
	}
	
	while (length != 0) {
		
		int chartype = rand() % 4;
		
		if (chartype == 0 && choices[0] != 'N') {
			selectedChar = rand() % (122 - 97 + 1) + 97; // a-z
			
			while (excluded.find(selectedChar) != excluded.end()) {
				selectedChar = rand() % (122 - 97 + 1) + 97;
			}
			password = selectedChar + password;	
			length--;
		}
		else if (chartype == 1 && choices[1] != 'N') {
			selectedChar = rand() % (90 - 65 + 1) + 65; // A-Z
			
			while (excluded.find(selectedChar) != excluded.end()) {
				selectedChar = rand() % (90 - 65 + 1) + 65;
			}
			password = selectedChar + password;	
			length--;
		}
		else if (chartype == 2 && choices[2] != 'N') { // 0-9
			selectedChar = rand() % (57 - 48 + 1) + 48;
			
			while (excluded.find(selectedChar) != excluded.end()) {
				selectedChar = rand() % (57 - 48 + 1) + 48;
			}
			password = selectedChar + password;	
			length--;
		}
		else if (chartype == 3 && choices[3] != 'N') { //Special Characters
		
			int typeOfSpecial = rand() % 4 + 1;
			
			if (typeOfSpecial == 1) {
				selectedChar = rand() % (47 - 33 + 1) + 33;
			
				while (excluded.find(selectedChar) != excluded.end()) {
					selectedChar = rand() % (47 - 33 + 1) + 33;
				}
				password = selectedChar + password;	
				length--;	
			}
			else if (typeOfSpecial == 2) {
				selectedChar = rand() % (64 - 58 + 1) + 58;
			
				while (excluded.find(selectedChar) != excluded.end()) {
					selectedChar = rand() % (64 - 58 + 1) + 58;
				}
				password = selectedChar + password;	
				length--;
			}
			else if (typeOfSpecial == 3) {
				selectedChar = rand() % (96 - 91 + 1) + 91;
			
				while (excluded.find(selectedChar) != excluded.end()) {
					selectedChar = rand() % (96 - 91 + 1) + 91;
				}
				password = selectedChar + password;	
				length--;
			}
			else if (typeOfSpecial == 4) {
				selectedChar = rand() % (126 - 123 + 1) + 123;
			
				while (excluded.find(selectedChar) != excluded.end()) {
					selectedChar = rand() % (126 - 123 + 1) + 123;
				}
				password = selectedChar + password;	
				length--;
			}
		}
		
		if (length == 0 && allPasswords.size() != amount) {
			length = temp;
			allPasswords.push_back(password);
			password = "";
			
			if (choices[5] == 'Y') {	
				password = password + sequence;
				length = length - sequence.length();
			}
		}	
	}
	
	cout << GREEN << "\nYour Password/s:\n" << password;
	
	for(auto word : allPasswords) {
		cout << word << endl;
	}
    
	
	return 0;
}

	