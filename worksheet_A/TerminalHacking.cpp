// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

// Function returns likeness score
int GetLikeness(std::string guessedWord, std::string secret)
{
	int score = 0;

	// Checks letters from guessed word against corresponding letters of secret word
	for (int check = 0; check < wordLength; check++)
	{
		if (guessedWord.at(check) == secret.at(check))
			score++;
	}
	return score;
}

// Appliction entry point
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
	
	// Intialize variables
	std::string guessedWord = "";
	int likeness = 0;
	int guesses = 0;

	// Main Game Loop
	while (guesses < 4)
	{
		std::cout << "\nPlease enter your guess (in capitals):\n";
		std::cin >> guessedWord;

		// Check guessed word is in generated word list
		std::set<std::string>::iterator counter = options.find(guessedWord);

		// If guessed word not in list, inform player and start again
		if (counter == options.end())
		{
			std::cout << "Invalid Guess." << std::endl;
			continue;
		}

		else
		{
			// Print Likeness score to player (get from GetLikeness() function)
			likeness = GetLikeness(guessedWord, secret);
			std::cout << "\nScore: " << likeness << " out of " << wordLength << "\n";

			// If guess is right exit game
			if (likeness == wordLength)
			{
				std::cout << "\nYou win!\n";
				exit(0);
			}

			// If guess is wrong display number of guesses left
			else
			{
				guesses++;
				std::cout << "\nYou have " << 4 - guesses << " guesses left. \n";
				likeness = 0;
			}

		}
	}

	// If all guesses played, game over
	std::cout << "\nYou lose!\n";

	return 0;
}

