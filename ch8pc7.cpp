// ch8pc7.cpp : Defines the entry point for the console application.
//
/* 
 * by Mark Hawes
 * Lottery Program generates lottery numbers and then asks the user to guess what they are, then displays how many they
 * got correct, or if they won entirely
 * last updated 7/31/17
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getPlayerNumbers(int player[], int size);
void generateWinning(int input[], int size);
void displayArray(int array[], int size);
int checkCorrect(int winning[], int player[], int size);
bool win(int winning[], int player[], int size);
void closeMessage();

int main()
{
	// definitions
	const int LOTTERY_NUMS = 5; // this number is the lotteries total entries
	const int MIN_NUM = 0, MAX_NUM = 9; // min and max numbers allowed for lottery
	typedef int lottery[LOTTERY_NUMS];
	lottery winningDigits;
	lottery player;

	// generate winning numbers
	generateWinning(winningDigits, LOTTERY_NUMS);
	// get players lottery numbers
	getPlayerNumbers(player, LOTTERY_NUMS);
	
	// blank line -- for formatting
	cout << endl;

	// checks and displays if player won, or how many they guessed correct
	if (win(winningDigits, player, LOTTERY_NUMS)) {
		cout << "You guessed all lottery numbers correctly! Congratulations!\n";
	}
	else {
		cout << "You guessed " << checkCorrect(winningDigits, player, LOTTERY_NUMS) << " correct!\n";
	}

	// blank line -- for formatting
	cout << endl;

	// displays player and winning number arrays
	cout << "Winning numbers: ";
	displayArray(winningDigits, LOTTERY_NUMS);
	cout << "Your numbers: ";
	displayArray(player, LOTTERY_NUMS);
	
	closeMessage(); // stops program from auto closing when done
    return 0;
}

// get lottery numbers
void getPlayerNumbers(int player[], int size) {
	int input;

	cout << "Enter your five lottery numbers(0-9): \n";
	for (int index = 0; index < size; index++) {
		cin >> input;
		while (input < 0 || input > 9) {
			cout << "Invalid input, try again\n";
			cin >> input;
		}
		player[index] = input;
	}
}

// checks to see if players numbers and winning numbers are all the same
bool win(int winning[], int player[], int size) {
	for (int index = 0; index < size; index++) {
		if (winning[index] != player[index])
			return false;
	} // end if
	return true;
}

// returns a count of the number of values player has guessed correct
int checkCorrect(int winning[], int player[], int size) {
	int count = 0;
	for (int index = 0; index < size; index++) {
		if (winning[index] == player[index])
			count++;
	} // end if
	return count;
}

// displays given array
void displayArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

// generates winning values
void generateWinning(int input[],int size){
	// stops random from being the same random at the start of each iteration, 
	// but uses time because it's easy
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		input[i] = rand() % 10;
	} // end for
}

/********************************************
 *				closeMessage				*
 * final statement of program that stops it	*
 * from closing until user enters input		*
 ********************************************/
void closeMessage() {
	cout << "\nPress enter to exit program.\n";
	getchar();
	getchar();
}