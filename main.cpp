//Nicholas Girmes
//CPSC351

//Includes
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

//Prototypes
void welcome();
void next_command();
void CreateThread(char*);

//Begin main function
int main() {

	//Begin Variable declaration
	string userInput;

	//Welcome message
	welcome();


	while (1){

		//Prompt next command
		next_command();

		//Obtain user input
		getline(cin, userInput);

		//Test user input
		if (userInput == "exit") {
			
			cout << "\nThanks for using myShell";
			return 0;

		}

		else if (userInput == "help") {

			cout << "Commands:\n-dir\n-help\n-vol\n-path\n-tasklist\n-notepad\n-echo\n-color\n-ping\n-exit\n\n";

		}
		else {

			//Obtatining writeable copy of userInput
			char* ptr_userInput = new char[userInput.size() + 1];
			copy(userInput.begin(), userInput.end(), ptr_userInput);

			//Create terminating 0
			ptr_userInput[userInput.size()] = '\0';

			//Call to create child thread
			CreateThread(ptr_userInput);

			//Free string after use
			delete[] ptr_userInput;

		}
	}
	return 0;
}

void welcome() {

	cout << "Welcome to myShell\n\n";

}

void next_command() {

	cout << "==>";

}

void CreateThread(char* ptr_userInput) {

	system(ptr_userInput);
	cout << endl;

}
