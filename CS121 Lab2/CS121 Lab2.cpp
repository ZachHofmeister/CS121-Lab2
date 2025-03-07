/*
	Zach Hofmeister		2/11/19
	Lab 2: Functions
	A quiz making application that asks the user for questions and answers and generates a quiz.
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void addQuestion(string[5][2], int); //Adds a question to the array at an index defined by an int
void displayQuiz(string[5][2], int); //Displays a quiz array of certain length defined by an int

int main() {
	string questions[5][2];
	char choice = 'a'; //keeps track of user input into the menu system
	int count = 0; //keeps track of question index

	cout << "Welcome to QuizMaker 5000" << endl;
	cout << "Make a quiz up to 5 questions long!" << endl;

	do {
		cout << endl << "What would you like to do?" << endl;
		cout << "a. Create a question" << endl;
		cout << "b. Quit" << endl;
		cout << "Choice: ";
		cin >> choice;
		choice = tolower(choice); //handles upper-case input equally

		if (choice == 'a' && count < 5) { //if user can enter more questions and user wants to
			addQuestion(questions, count);
			count++;
		} else if (choice != 'a' && choice != 'b') { //invalid character input
			cout << endl << "Invalid option" << endl;
		}
	} while (choice != 'b' && count < 5); //loop breaks if user quits or user inputs max questions

	displayQuiz(questions, count); //displays the entered questions and answers

	return 0;
}

void addQuestion(string questions[5][2], int index) { //Adds a question to the array at an index defined by an int
	string question, answer;
	cout << endl;
	cout << "Please enter your question: ";
	cin.ignore(); //Need to clear buffer since there is an escape character inside
	getline(cin, question); //Get a string
	cout << "Please enter the answer: ";
	getline(cin, answer); //Get a string
	questions[index][0] = question;
	questions[index][1] = answer;
	cout << "Question " << index + 1 << " added!" << endl;
}

void displayQuiz(string questions[5][2], int count) { //Displays a quiz array of certain length defined by an int
	cout << endl << "Thank you for using QuizMaker 5000" << endl;
	cout << endl << "Created Quiz" << endl;
	for (int i = 0; i < count; i++) {
		cout << "Q" << i + 1 << ": " << questions[i][0] << endl;
		cout << "A: " << questions[i][1] << endl;
		cout << endl;
	}
}

/*
SAMPLE OUTPUT:
Welcome to QuizMaker 5000
Make a quiz up to 5 questions long!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 1
Please enter the answer: 2
Question 1 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 3
Please enter the answer: 4
Question 2 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 5
Please enter the answer: 6
Question 3 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 7
Please enter the answer: 8
Question 4 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 9
Please enter the answer: 10
Question 5 added!

Thank you for using QuizMaker 5000

Created Quiz
Q1: 1
A: 2

Q2: 3
A: 4

Q3: 5
A: 6

Q4: 7
A: 8

Q5: 9
A: 10

Press any key to close this window . . .

===================================================================
SAMPLE 2
===================================================================

Welcome to QuizMaker 5000
Make a quiz up to 5 questions long!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 1
Please enter the answer: 2
Question 1 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 3
Please enter the answer: 4
Question 2 added!

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: 5
Please enter the answer: 6
Question 3 added!

What would you like to do?
a. Create a question
b. Quit
Choice: b

Thank you for using QuizMaker 5000

Created Quiz
Q1: 1
A: 2

Q2: 3
A: 4

Q3: 5
A: 6

Press any key to close this window . . .
*/