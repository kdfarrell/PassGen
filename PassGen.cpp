#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>

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
	int length;
	
	printMessage("--- Welcome to PassGen ---", BLUE);
    cout << CYAN << "This program will help you create a secure and random password.\n";
    cout << CYAN << "You will be able to customize your password based on various criteria.\n";
    cout << CYAN << "Let's get started!\n\n" << RESET;
	
	// Choosing the length of the password
	printMessage("How long would you like your password to be?", CYAN);
    cout << BRIGHT_YELLOW << "Please enter a number between 8 and 32 (inclusive): " << RESET;
	
	while (true) {
		cin >> length;
		
		if (cin.fail()) { // user enters non-numeric character
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printMessage("Invalid input. Please enter a number between 8 and 32 (inclusive).", RED);
			cout << RED << "Length: ";
		}
		else if (length >= 8 && length <= 32) {
            break;
        } 
		else {
            printMessage("Invalid input. Please enter a number between 8 and 32 (inclusive).", RED);
            cout << RED << "Length: ";
        }
	}
	cout << endl;
	
	// Choosing letters a-z
	printMessage("\nInclude characters (a-z)?", CYAN);
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
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
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
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
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
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
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
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
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[4] = choice;
	
	string exclude;
    if (choices[4] == 'Y') {
        cout << BRIGHT_YELLOW << "What characters would you like to exclude? " << RESET;
        cin.ignore();
        getline(cin, exclude);
    }
	
	// Include sequence of characters
	printMessage("\nWould you like to include a specific sequence of characters?", CYAN);
    cout << CYAN << "Example: ('1234', 'abc') in your password?" << RESET << endl;
    cout << YELLOW << "[Y] Yes" << RESET << endl;
    cout << YELLOW << "[N] No" << RESET << endl;
    cout << BRIGHT_YELLOW << "Your choice (Y/N): " << RESET;
    cin >> choice;
    choice = toupper(choice);
    
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (choice != 'Y' && choice != 'N') {
        printMessage("Invalid input. Please enter a 'Y' or 'N'.", RED);
        cout << BRIGHT_YELLOW << "Your choice: " << RESET;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    choices[5] = choice;
	
	string sequence;
    if (choices[5] == 'Y') {
        cout << BRIGHT_YELLOW << "What characters would you like to include in the sequence? " << RESET;
        cin.ignore();
        getline(cin, sequence);
    }
	
	printMessage("\nThank you for your input! Your password will be generated based on your selections.", GREEN);
    return 0;
}

