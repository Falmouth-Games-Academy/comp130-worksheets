// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;
int lives = 4;

int getlikeness(std::string guessedWord, std::string secretWord)
{
	int result = 0;
		for (int i = 0; i < secretWord.length(); i++)
		{
			if (secretWord.at(i) = guessedWord.at(i))
			{
				result++;
			}
		}

		return result;
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

	while (lives > 0)
	{
		std::cout << "This should work";
	}
	// TODO: implement the rest of the game



    return 0;
}

