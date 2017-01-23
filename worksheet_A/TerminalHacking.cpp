// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"
#include <string>
#include <iostream>

using namespace std;

const int wordLength = 5;
const int numberOfWords = 15;

// Gets the similarity of the words
int likeness(string wordGuessed, string secretWord)
{
	int result = 0;

		for (int i = 0; i < (secretWord.length()); i++)
		{
		if (secretWord.at(i) == wordGuessed.at(i))
		{
			result ++;
		}
	}
	return result;
}

//Makes user enter a word in the list or it loops
bool listedWord(string userInput, set<string> options)
{
	for each (string word in options)
	{
		if (userInput == word)
		{
			return true;
		}
	}
	return false;
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

	int turnsLeft = 4;
	string wordGuessed;

	cout << endl;
	cout << "Please guess the password" << endl;

	while (turnsLeft > 0)
		{
			if (turnsLeft > 0)
			{
				cout << "Guesses left : " << turnsLeft << endl;
				cin >> wordGuessed;
				turnsLeft -= 1;
			}
			
			if (listedWord(wordGuessed, options))
			{
				//If words match you win
				if (wordGuessed == secret)
				{
					cout << "You win!" << endl;
					turnsLeft = 0;
				}
				//If you have no guesses left you lose
				else if (turnsLeft == 0)
				{
					cout << "You lose!" << endl;
				}
				//prints Likeness so you know what letters you have right
				else
				{
					cout << "Likeness = " << likeness(wordGuessed, secret) << endl;
				}
			}
	else
	{
		cout << endl << "Word not in list" << endl;
	}
	
			if (turnsLeft == 0)
			{
				cout << "The word was : " <<  secret << endl;
			}

	}

    return 0;
}

