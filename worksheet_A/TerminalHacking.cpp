// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"
#include <stdio.h>
#include <set>


const int wordLength = 5;
const int numberOfWords = 15;
int likeness(std::string secretWord, std::string guessWord);

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

	// initialise variables
	bool WordInList = false;
	std::cout << secret;
	std::string guess;
	int lives = 4;
	std::string result = "Lost";

	// main game loop
	while (lives > 0) 
	{

		// Ask for user guess
		std::cout << " what is your guess?" << std::endl;
		std::cin >> guess;

		// Check to see if guess is in word set
		for each (std::string word in options)
		{
			size_t setSearch = word.find(guess);
			if (setSearch != std::string::npos) {

				WordInList = true;
			}
		}

		// Calculates likeness if guess is valid
		if (WordInList == true){
			int likenessScore = likeness(secret, guess);
			if (likenessScore == wordLength){
				std::cout << "Gz Noob! You had " << lives << " lives remaining!" << std::endl;
				result = "Won";
				lives = 0;
			}

			else{
				lives -= 1;
				std::cout << "Your Likeness Score was: " << likenessScore << std::endl;
			}
		}
		else {
			std::cout << "invalid guess, try again!" << std::endl;
		}
	}
	std::cout << "Game Over You " << result;
    return 0;
}

// function to calculate likeness
int likeness(std::string secretWord, std::string guessWord)
{
	int likeness = 0;
	const char *SecrWord = secretWord.c_str();
	const char *GuesWord = guessWord.c_str();
	int len = guessWord.length();
	for (int i = 0; i < len; i++){	
		if (SecrWord[i] == GuesWord[i]){
			likeness++;
		}

	}
	return likeness;
}


