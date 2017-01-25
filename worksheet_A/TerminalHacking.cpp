// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

using namespace std;
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
	string secret = words.getRandomWord();

	// Create a set to hold the list of options
	set<string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (string word in options)
	{
		cout << word << endl;
	}
	
	// Game loop
	while (playerLives > 0) 
	{
		cout << "Choose a word... ";
		cin >> guessWord;
		simScore = simCheck(guessWord, secret);
		if (simScore == wordLength)
		{
			cout << "Correct" << endl;
			cin >> guessWord;
			playerLives = 0;
		}
		else
		{
			playerLives -= 1;
			cout << simScore << " Letters are correct" << endl;
			cout << "You have " << playerLives << " lives remaining" << endl;
			cout << endl;
		}
	}
	

    return 0;
}

