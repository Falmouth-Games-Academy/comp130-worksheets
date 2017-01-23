// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;


int GetLikeness(std::string guessedword, std::string secretword)
{
	int Result = 0;
	// Loops for the ammount of characters in the word
	for (int i = 0; i < wordLength; i++)
	{
		// for every letter that matches the result is increased by one
		if (guessedword.at(i) == secretword.at(i))
			Result++;
	}
	// Returns the Likeness value
	return Result;
}
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
	int Likeness = 0;
	int IncorrectGuesses = 0;
	bool inlist;
	std::string guess;
	
	while (IncorrectGuesses < 4)
	{
		inlist = false;
		while (inlist == false)
		{
			std::cout << "Type word in UPPERCASE" << std::endl;
			std::cin >> guess;

			// loops through all the words in the word list
			for each (std::string word in options)
			{
				// If the player guess is in the word list then it breaks out of the loop
				if (guess == word)
					inlist = true;
			}
		}
		// Gets the likeness value
		Likeness = GetLikeness(guess, secret);
		std::cout << "Likeness = " << Likeness << "/" << wordLength << std::endl;
		// Checks if the player got the correct answer
		if (Likeness == wordLength)
		{
			std::cout << "You Win!" << std::endl;
			return 0;
		}
		else
		{
			// Increments the incorrect guesses if the player gets the wrong answer
			IncorrectGuesses++;
			std::cout << "Incorrect Guesses = " << IncorrectGuesses << "/4" << std::endl;
		}
	}
	// When player reaches 4 incorrect guesses "game over" is displayed and the program exits
	std::cout << "Game Over" << std::endl;
    return 0;
}

