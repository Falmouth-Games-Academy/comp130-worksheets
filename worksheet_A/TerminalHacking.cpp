// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int getLikeness(std::string secretWord, std::string playersWord)
{
	int Likeness = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (playersWord[i] == secretWord[i])
		{
			Likeness++;
		}
	}
	return Likeness;
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
	int lives = 5;
	bool playerHasChosen;
	std::string playerInput;
	std::string guess;
	int wordLikeness;

	while (lives > 0)
	{
		playerHasChosen = false;
		while (playerHasChosen == false)
		{
			std::cout << "Enter your guess in Capitals\n";
			std::cin >> playerInput;
			playerHasChosen = true;
		}
		wordLikeness = getLikeness(playerInput, secret);
		std::cout << "Your likeness score is: " << wordLikeness << "/" << wordLength << std::endl;

		if (wordLikeness == wordLength)
		{
			std::cout << "You guessed Correctly... Well done!" << std::endl;
			return 0;
		}
		else {
			lives--;
			std::cout << " You have " << lives << " guesses left \n" << std::endl;
		}
	}
	std::cout << "You ran out of guesses!";
    return 0;
}
