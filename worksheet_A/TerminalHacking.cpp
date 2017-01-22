// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int WordLength = 5;
const int NumberOfWords = 15;

// Appliction entry point
int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(WordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < NumberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}
	
	// Intialize variables
	std::string GuessedWord = "";
	int Likeness = 0;
	int Guesses = 0;

	// Main Game Loop
	while (Guesses < 4)
	{
		std::cout << "\nPlease enter your guess (in capitals):\n";
		std::cin >> GuessedWord;

		// Check guessed word is in generated word list
		std::set<std::string>::iterator Counter = options.find(GuessedWord);

		// If guessed word not in list, inform player and start again
		if (Counter == options.end())
		{
			std::cout << "Invalid Guess." << std::endl;
			continue;
		}

		else
		{
			// Print Likeness score to player (get from GetLikeness() function)
			Likeness = GetLikeness(GuessedWord, secret);
			std::cout << "\nScore: " << Likeness << " out of " << WordLength << "\n";

			// If guess is right exit game
			if (Likeness == WordLength)
			{
				std::cout << "\nYou win!\n";
				exit(0);
			}

			// If guess is wrong display number of guesses left
			else
			{
				Guesses++;
				std::cout << "\nYou have " << 4 - Guesses << " guesses left. \n";
				Likeness = 0;
			}

		}
	}

	// If all guesses played, game over
	std::cout << "\nYou lose!\n";

	return 0;
}

// Function returns likeness score
int GetLikeness(std::string guessedWord, std::string secret)
{
	int Check;
	int score = 0;

	// Checks letters from guessed word against corresponding letters of secret word
	for (Check = 0; Check < WordLength; Check++)
	{
		if (guessedWord.at(Check) == secret.at(Check))
			score++;
	}
	return score;
}