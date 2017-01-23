// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int getLikeness(std::string guessword, std::string password)
{
	int score = 0;

	for (int i = 0; i < wordLength; i++) {
		if (guessword.at(i) == password.at(i)) {
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

	// TODO: implement the rest of the game

	std::string inputWord;
	bool winGame = false;

	std::cout << "The password is " << secret << "\n";

	for (int numLives = 5; numLives > 0; numLives = numLives - 1) {
		std::getline(std::cin, inputWord);
		int output = getLikeness(inputWord, secret);

		std::cout << "Your score is: " << output << "\n";



		if (output == 5) {
			std::cout << "You win!";
			numLives = 0;
			winGame = true;
		}
	}

	if (winGame == false) {
		std::cout << "You have run out of lives. You lose";
	}
	std::getline(std::cin, inputWord);

    return 0;
}

