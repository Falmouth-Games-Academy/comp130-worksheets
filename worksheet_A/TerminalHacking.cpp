// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

int wordLength = 5;
const int numberOfWords = 15;
int livesRemaining = 4;
int difficulty = 0;
std::string playerGuess;

int checkSimilarity(std::string secret, std::string player)
{
	int letter;
	int similarityScore = 0;
	for (letter = 0; letter < wordLength; letter++)
	{
		if (secret.at(letter) == player.at(letter))
		{
			similarityScore++;
		}
	}

	return similarityScore;
}

int main()
{
	std::cout << "Please choice your difficulty" << std::endl;
	std::cout << "Very Easy: 1" << std::endl;
	std::cout << "Easy: 2" << std::endl;
	std::cout << "Average: 3" << std::endl;
	std::cout << "Hard: 4" << std::endl;
	std::cout << "Very Hard: 5" << std::endl;
	std::cin >> difficulty;
	if (difficulty == 1){wordLength = 5;}
	
	else if (difficulty == 2){wordLength = 8;}
	
	else if (difficulty == 3){wordLength = 10;}
	
	else if (difficulty == 4){wordLength = 12;}

	else if (difficulty == 5){wordLength = 15;}	

	else 
	{
		difficulty = 1; 
		wordLength = 5;
		std::cout << "Invalid choice selected, Terminal will be set to Very Easy." << std::endl;
	}
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
	
	int similarityScore;

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

	// Main game loop
	while (livesRemaining > 0)
	{
		std::cout << "Please input a guess using only capital letters." << std::endl;
		std::cin >> playerGuess;
		
		for each (std::string word in options)
		{
			if (playerGuess != word)
			{
				std::cout << "Invalid suggestion" << std::endl;
			}
			else
			{
				pass;
			}	
			
		}	
		
		if (playerGuess != secret)
		{
			livesRemaining -= 1;
			std::cout << "Number of lives remaning " << livesRemaining << std::endl;
			similarityScore = checkSimilarity(secret, playerGuess);
			std::cout << "Similarity " << similarityScore << "/" << wordLength << std::endl;


		}
		
		else
		{
			std::cout << "You win the game" << std::endl << "Type Quit to exit" << std::endl;
			std::cin >> playerGuess;
			livesRemaining = 0;
		}

	}

    return 0;
}
