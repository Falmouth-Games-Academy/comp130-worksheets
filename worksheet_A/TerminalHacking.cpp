// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

using namespace std;
const int wordLength = 5;

// Checks the similarity between players guessed word and the correct secret word
int SimilarityCheck(string guessWord, string secretWord)
{
	int wordLengthLetter;
	int score = 0;

	// Checks every letter in the players guess agianst the letter in the same place in
	// the correct word and adds one to the similarity score for every correctly placed letter
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
	const int numberOfWords = 15;
	int playerLives = 4;
	std::string guessWord;
	int SimilarityScore = 0;

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

	// Fills the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		string word = words.getRandomWord();
		options.insert(word);
	}

	// Displays all words
	for each (string word in options)
	{
		cout << word << endl;
	}
	
	// Main game loop
	// As long as there are more than zero lives left the game plays
	while (playerLives > 0) 
	{
		// Prompts the player to input a word from the list
		cout << "Choose a word... ";
		cin >> guessWord;

		// Checks if the players word is similar to the secret word
		SimilarityScore = SimilarityCheck(guessWord, secret);

		// If the words match tell the player their correct and ends the game
		if (SimilarityScore == wordLength)
		{
			cout << "Correct" << endl;
			cin >> guessWord;
			break;
		}
		else
		{

			// If the words dont match subtract a life and output how 
			// many letters are correct and how many lives are left
			playerLives -= 1;
			cout << SimilarityScore << " Letters are correct" << endl;
			cout << "You have " << playerLives << " lives remaining" << endl;
			cout << endl;
		}
	}
	
    return 0;
}

