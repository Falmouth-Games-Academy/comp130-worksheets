// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

// Returns number of matching letters
int getLikeness(std::string guessedWord, std::string secretWord)
{
	int result = 0;

	for (int i = 0; i < secretWord.length(); i += 1) {

		if (secretWord.at(i) == guessedWord.at(i)) {
			result += 1;
		}
	}

	return result;
}

// Checks to see if word is in the list
bool wordInList(std::string guess, std::set<std::string> options)
{
	for each (std::string word in options) {

		if (guess == word) {
			return 1;
		}
	}

	return 0;
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

	// Initialise lives
	int lives = 4;

	// Initialise guessed word
	std::string guess;

	// Game loop
	while (lives > 0) {

		// Promt player to guess
		std::cout << std::endl << "You have " << lives << " chances to guess the word, pick your keystrokes wisely." << std::endl << std::endl;

		std::cin >> guess;

		// Applies check to see if word is in list
		if (wordInList(guess, options)) {

			lives -= 1;

			// Check to see if word is correct
			if (guess == secret) {
				std::cout << "Congrats, you're a real winner. Go upstairs and tell your mum, she will be proud." << std::endl;
				lives = 0;
			}
			else if (lives == 0) {
				std::cout << "Doesn't really matter how many you got right this time because you're out of tries, loser." << std::endl;
			}
			else {
				std::cout << "You got " << getLikeness(guess, secret) << " letters correct!";
			}
		}
		else {
			std::cout << std::endl << "That's not on the list, you idiot, have another go. I'll not take off a life because I enjoy insulting you." << std::endl << std::endl;
			std::cout << "P.S. Did you notice they're uppercase?" << std::endl;
		}
	}

    return 0;
}

