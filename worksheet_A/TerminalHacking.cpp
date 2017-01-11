// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int getLikeness(std::string guessedWord, std::string secret)
{
	int i;
	int score = 0;
	for (i = 0; i < wordLength; i++)
	{
		if (guessedWord.at(i) == secret.at(i))
			score++;
	}
	return score;
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

	std::string guessedWord;
	int likeness = 0;
	int guesses = 0;

	while (guesses < 4)
	{
		std::cout << "\nPlease enter your guess (in capitals):\n";
		std::cin >> guessedWord;

		std::set<std::string>::iterator i = options.find(guessedWord);
		if (i == options.end())
		{
		std::cout << "Invalid Guess." << std::endl;
		continue;
		}
		else
		{
			std::cout << "\nCalculating Likeness Score.\n";
		}

		likeness = getLikeness(guessedWord, secret);
		std::cout << "\nScore: " << likeness << " out of " << wordLength << "\n";

		if (likeness == wordLength)
		{
			std::cout << "\nYou win!\n";
			exit(0);
		}

		else
		{
			guesses++;
			std::cout << "\nYou have " << 4 - guesses << " guesses left. \n";
			likeness = 0;
		}

	}

	std::cout << "\nYou lose!\n";

  return 0;
}