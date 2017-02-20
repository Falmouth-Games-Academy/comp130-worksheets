// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//
#include <windows.h>
#include <mmsystem.h>
#include "stdafx.h"
#include "WordList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#pragma comment(lib,"Winmm.lib")

const int wordLength = 5;
const int numberOfWords = 15;
std::string s = "";
std::string g = "";
bool w;

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));
	
	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);
	s = secret; // load string in to useable variable

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	int i = 0;
	int k = 0;

	for each (std::string word in options){
		std::cout << "\t" <<word << std::endl; // no matches but print it
	}

	// TODO: implement the rest of the game
	// get user input of their chosen word


	int x = 4; //to limit 4 guesses
	std::string Guess; //variable to hold user input
	std::string request; //petty text variable
	while (x > 0) { //while we have any guesses left
		Guess = ""; //reset varialbe to empty
		if (x == 1) { //
			request = "guess";
		}
		else {
			request = "guesses";
		}
		std::cout << "Enter your guess. You have " << x << " " << request << " remaining." << std::endl;
		std::getline(std::cin, Guess, '\n');
		
			std::transform(Guess.begin(), Guess.end(), Guess.begin(), ::toupper);
			if (options.find(Guess) != options.end()) {
				std::cout << "Word is in List!" << std::endl;
				w = 0; //word is in list
			}
			else {
				std::cout << "Invalid Word!" << std::endl;
				w = 1; //word is not in list
			}
		if (Guess == secret) { // compare the whole word first
			std::cout << Guess << " - You Win!" << std::endl; // if they match then print the word
			system("PAUSE");
			return 0;
		}
		else {
			for (i = 0; i < wordLength; i++) { //work through the word one char at a time to find matches
				if (Guess[i] == secret[i]) {
					k++;
				}
			}
			if (k>0 & w == 0) { //if the amount of letters that are similar are greater than 0 AND the word is in the list then proceed
				if (k == 1) {
					request = " letter.";
				}
				else {
					request = " letters.";
				}
				std::cout << Guess << " - matched " << k << request << std::endl; // if matches are more than zero then print it
			}
			else {
				std::cout << Guess << std::endl; // no matches but print it
			}
			k = 0; // reset count of matches
		}
		x--; //decrement counter
		if ((x==0) && (k==0)) {
			std::cout << "You Lose!" << std::endl;
		}
	}
	system("PAUSE"); //give the user time to view results
	return 0; //close program
}

