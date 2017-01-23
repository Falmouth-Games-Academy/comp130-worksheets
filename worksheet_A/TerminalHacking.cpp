// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

using namespace std;

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

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game

	// Initialising variables
	int guessesLeft = 4;
	string guess;

	// Game loop (incomplete)
	while (guessesLeft > 0)
	{
		bool notGuessed = true;
		while (notGuessed)
		{
			// Player input prompt
			cout << "Password required";
			cin >> guess;

			// Checks if the guess is correct
			if (guess == secret)
			{
				cout << "Access granted" << endl;
				notGuessed = false;
			}

			// Checks if the guess is wrong
			else 
			{
				guessesLeft -= 1;
				cout << "You have " << guessesLeft << " guesses remaining." << endl;
			}

		}
	}

	// Program displays as shown then exits if player fails with all their guesses.
	cout << "Access denied" << endl;

    return 0;
}

