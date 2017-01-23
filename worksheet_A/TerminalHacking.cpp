// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int GetLikeness(std::string guessed, std::string secret)
{
	int i;
	int score = 0;

	for (i = 0; i < WordLength; i++)
	{
		if (guessed.at(i) == secret.at(i))
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
	while (options.size() < numberOfWords){
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options){
		std::cout << word << std::endl;
	}

	
	std::string guess = "";
	int Likeness = 0;
	int guessremain = 0;

	while (guessremain < 4){
		std::cout << "\nPlease enter your guess\n";
		std::transform(cout.begin(), str.end(),str.begin(), ::toupper);
		std::cin >> guess;
		std::set<std::string>::iterator Counter = options.find(guess);
		
		if (Counter == options.end()){
			std::cout << "Invalid Guess." << std::endl;
			continue;
		}

		else{
			Likeness = GetLikeness(guess, secret);
			std::cout << "\nyou have a likeness of " << Likeness << " out of " << WordLength << "\n";

			if (Likeness == WordLength){
				std::cout << "\nyou won\n";
				exit(0);
			}
			
			else{
				guessremain++;
				std::cout << 4 - guessremain << " guesses remaining \n";
				Likeness = 0;
			}
		}
	}
	std::cout << "\ngameover\n";
	return 0;
}
