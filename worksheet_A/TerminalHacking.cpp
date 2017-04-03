// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"
#include <string>
#include <iostream>


using namespace std;

const int wordLength = 5;
const int numberOfWords = 15;
int PlayerLives = 4;
int Likeness = 0;
string Guess = "";

void HackingIntro();

int GetLikeness(string Guess, string SecretWord)
{
	int i = 0;
	int PlayerGuesses = 0;
	for (i = 0; i < wordLength; i++)
	{
		if (Guess.at(i) == SecretWord.at(i))
			PlayerGuesses++;
	}

	return PlayerGuesses;
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
	HackingIntro();

	while (PlayerLives > 0)
	{
		cout << "Please Enter Password\n";
		//getline(cin, Guess);
		cin >> Guess;
		Likeness = GetLikeness(Guess, secret);
		if (Likeness == wordLength)
		{
			cout << "Correct Password" << endl;
			return 0;
		}

		PlayerLives -= 1;
		cout << Likeness << "Letters Match" << endl;
		cout << "You Have " << PlayerLives << " lives remaining" << endl;
		cout << endl;
	}

	return 0;
}

void HackingIntro()
{
	//Create Constant Word Length
	cout << "Welcome To The Terminal.\n";
	cout << "Password Has A Length Of " << wordLength << endl;
	cout << endl;
	return;
}
