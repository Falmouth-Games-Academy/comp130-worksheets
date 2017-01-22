// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

// Returns number of matching letters
int getLikeness(std::string guessededWord, std::string secretWord)
{
	int result = 0;

	for (int i = 0; i < secretWord.length(); i += 1) {

		if (secretWord.at(i) == guessededWord.at(i)) {
			result += 1;
		}
	}

	return result;
}

// Checks to see if word is in the list
bool wordInList(std::string guessed, std::set<std::string> options)
{
	for each (std::string word in options) {

		if (guessed == word) {
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
	
	using namespace std;

	int attempts_remaining = 4;
	string guessed;

	cout << endl << "Welcome to ROBCO Industries (TM) Termlink" << endl << "Password Required";

	// Main loop
	while (attempts_remaining > 0) 
			{
				// Tells player how many attempts they have left
				if (attempts_remaining > 1)
				{
					cout << endl << "Attempts Remaining: " << attempts_remaining << endl << endl;
					cin >> guessed;
					attempts_remaining -= 1;
				}
				else 
				{
					cout << endl << "Attempts Remaining: " << attempts_remaining << endl
					<< "I Have a bad feeling about this" << endl << endl;
					cin >> guessed;
					attempts_remaining -= 1;
				}

				// Checks if word is in list
				if (wordInList(guessed, options)) 
				{									
					// Checks if word is the secret word
					if (guessed == secret) 
					{
						cout << "Password Accepted!" << endl << "The force is strong with you" << endl;
						attempts_remaining = 0;
					}

					else if (attempts_remaining == 0) 
					{
						cout << "0 attempts remaining, access denied" << endl << "I find your lack of skill disturbing" << endl << 
							"           _.-'~~~~~~`-._ " << endl <<
							"          /      ||      \ " << endl <<
							"         /       ||       \ " << endl <<
							"        |        ||        | " << endl <<
							"        | _______||_______ | " << endl <<
							"        |/ ----- \/ ----- \| " << endl <<
							"       /  (     )  (     )  \ " << endl <<
							"      / \  ----- () -----  / \ " << endl <<
							"     /   \      /||\      /   \ " << endl <<
							"    /     \    /||||\    /     \ " << endl <<
							"   /       \  /||||||\  /        " << endl <<
							"  /_        \o========o/        _\ " << endl <<
							"    `--...__|`-._  _.-'|__...--'" << endl <<
							"            |    `'    |             " << endl;
					}
					else 
					{
						cout << "Entry denied" << endl << "Likeness = " << getLikeness(guessed, secret);
					}

					if (getLikeness(guessed, secret) == 0)
					{
						if (attempts_remaining == 3)
						{
							cout << endl << "Once you start down the dark path, forever will it dominate your destiny";
						}

						if (attempts_remaining == 2)
						{
							cout << endl << "Patience you must have my yong padawan";
						}
						
					}

					if (getLikeness(guessed, secret) == 2)
					{
						cout << endl << "Powerful you have become, the dark side I sense in you";
					}

					if (getLikeness(guessed, secret) == 1)
					{
						cout << endl << "Do or do not. There is no try";
					}

				}
				else
				{
					cout << endl << "ERROR 57UP1D: word not in list   NOTE: the terminal is CASE sensitive" << endl ;
				}
			}

	return 0;
}


