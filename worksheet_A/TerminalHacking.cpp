// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

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

	// variables
	std::string input;
	int IncorrectGuess = 0;

	while (IncorrectGuess < 4)
	{
			//prompts user for input
			std::cout << "What's your guess?" << std::endl;
			std::cin input; 

		
	}

	

    return 0;
}

// Function thats gives the likeness score after a guess
int GetLikeness(std::string guessedWord, std::string secretWord)
{
		int matches = 0; 

		// Compares characters from both guessed and secret words 
		
		for (int i = 0; i < wordLength; i++)
		{
			// Adds 1 to likeness for every correct character 
			if (guessedWord.at(i) == secretWord(i))
				score++;

		}
		return matches
}
