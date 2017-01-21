// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;
int playerLives = 4; 
std::string guessWord;
int wordLengthLetter;
int simScore = 0;

// Checks the similarity between players guessed word and the correct secret word
int simCheck(std::string guessWord, std::string secretWord)
{
	int score = 0;
	for (wordLengthLetter = 0; wordLengthLetter < wordLength; wordLengthLetter++)
		{
			if (guessWord.at(wordLengthLetter) == secretWord.at(wordLengthLetter))
			{
				score++;
			}
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
	
	// Game loop
	while (playerLives > 0) 
	{
		std::cout << "Choose a word... ";
		std::cin >> guessWord;
		simScore = simCheck(guessWord, secret);
		if (simScore == wordLength)
		{
			std::cout << "Correct" << std::endl;
			std::cin >> guessWord;
			playerLives = 0;
		}
		else
		{
			playerLives -= 1;
			std::cout << simScore << " Letters are correct" << std::endl;
			std::cout << "You have " << playerLives << " lives remaining" << std::endl;
			std::cout << std::endl;
		}
	}
	

    return 0;
}

