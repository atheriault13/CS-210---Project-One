// 07/16/2025 - Project One
// Outputs two clocks (one 12-hour clock and one 24-hour clock) and allows for manipulation by the user by adding increments of time

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function for clock borders
void printClockBorder() {
	// For loop that prints out space padding
	for (int i = 0; i < 16; ++i) {
		cout << " ";
	}
	// For loop that prints '*' for clock border
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	// For loop that prints out space padding 
	for (int i = 0; i < 5; ++i) {
		cout << " ";
	}
	// For loop that prints '*' for clock border
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	cout << endl;
}

// Function that outputs both of the clocks and converts the 24-hour clock to a 12-hour clock
void printClocks(int hours, int minutes, int seconds) {
	// Attributes for clock conversion
	int hourConv;
	int minConv;
	int secConv;
	string amPm = "AM";

	// Clock conversion
	if (hours == 0) {
		hourConv = 12;
	}
	else if (hours == 12) {
		hourConv = hours;
		amPm = "PM";
	}
	else {
		hourConv = hours;
	}

	// Titles for both clocks
	cout << "\t\t*\t" << "12-Hour Clock";
	cout << "\t  *";
	cout << "\t*" << "\t24-Hour Clock";
	cout << "\t  *" << endl;

	// 12-Hour Clock
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hourConv << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t  *" << endl;
}

// Function to take time from user
void inputInitialTime(int& setHour, int& setMinute, int& setSecond) {
	// Holds user input
	string inputString;
	// User time input validation
	string tempString;
	// Valid time toggle for while statement
	bool validTime = false;
	// Used to find 1st colon
	int firstColonPosition;
	// Used to find 2nd colon
	int secondColonPosition;

	// Ask for user time input
	while (!validTime) {
		cout << "Enter time as HH:MM:SS in 24-hour format: ";
		// Assign user input
		getline(cin, inputString);

		// Finds 1st colon
		firstColonPosition = inputString.find(':');
		// Finds 2nd colon
		secondColonPosition = inputString.find(':', firstColonPosition + 1);

		// Attempts to assign and convert each clock section if integers, otherwise ignore
		try {
			// Converts first section to an int
			setHour = stoi(inputString.substr(0, firstColonPosition));
			// Same as setHour
			setMinute = stoi(inputString.substr(firstColonPosition + 1, secondColonPosition));
			// Same as setHour
			setSecond = stoi(inputString.substr(secondColonPosition + 1, inputString.size() - 1));
		}
		catch (const std::exception&)
		{
			// Not doing anything with the exception
		}

		// Checking proper character length
		if (inputString.size() != 8) {
			cout << "Time is invalid" << endl;
			!validTime;
		}
		// Check if setHour is between 0 and 23
		else if (setHour < 0 || setMinute > 23) {
			cout << "Time is invalid" << endl;
			!validTime;
		}
		// Check is setMinute is between 0 and 59
		else if (setMinute < 0 || setMinute > 59) {
			cout << "Time is invalid" << endl;
			!validTime;
		}
		// Check if setSecond is between 0 and 59
		else if (setSecond < 0 || setSecond > 59) {
			cout << "Time is invalid" << endl;
			!validTime;
		}
		// Time is valid
		else {
			validTime = true;
		}
	}
}

// Main Menu options
void printMainMenu() {
	cout << endl;
	cout << "******************************" << endl;
	cout << "* 1 - Add One Hour\t\t*" << endl;
	cout << "* 2 - Add One Minute\t\t*" << endl;
	cout << "* 3 - Add One Second\t\t*" << endl;
	cout << "* 4 - Exit\t\t\t*" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

// Function for taking in user inputs and validating
void processUserInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {
	// Ask user for option number
	cout << "Select option 1 through 4: ";

	if (!(cin >> userChoice)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		userChoice = 0;
	}
	// Utilize switch statement for user's input
	switch (userChoice) {
	case 1:
		cout << "1 Hour Added" << endl; 
		// Increments 1 hour until reaches 24
		if (setHour < 23) {
			++setHour;
		}
		// Reset to 00 hour once it reaches 24
		else {
			setHour = 00;
		}
		break;

	case 2:
		cout << "1 Minute Added" << endl;
		// Increments 1 minutes until reaches 59
		if (setMinute < 59) {
			++setMinute;
		}
		// Reset to 00 minute once it reaches 59
		else {
			setMinute = 00;
		}
		break;

	case 3:
		// Increments 1 second until it reaches 59
		if (setSecond < 59) {
			++setSecond;
		}
		// Reset to 00 seconds once it reaches 59
		else {
			setSecond = 00;
		}
		break;
	case 4:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice. Enter a number between 1 through 4..." << endl;
		cin.clear();
		break;
	}
}

int main() {
	// Declare golabl properties
	// Initial user choice
	int userChoice = 0;
	// The following attributes initialize clocks to midnight
	int setHour = 0;
	int setMinute = 0;
	int setSecond = 0;
	// Ask user to input the initial time
	inputInitialTime(setHour, setMinute, setSecond);
	// Enter while loop
	while (userChoice != 4) {
		// Call clock functions
		// Top clock borders
		printClockBorder();
		// Print both clocks
		printClocks(setHour, setMinute, setSecond);
		// Bottom clock borders
		printClockBorder();
		// Prints main menu to manipulate clocks
		printMainMenu();
		// Takes in integers and modifies clocks
		processUserInput(userChoice, setHour, setMinute, setSecond);
	}

	return 0;
}