// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int getLikeness(std::string guessedWord, std::string secretWord)
{
	// Returns a likeness score defined as the number of letters in guessedWord which match the same position in secretWord
	int likenessScore = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (guessedWord[i] == secretWord[i])
			likenessScore++;
	}
	return likenessScore;
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

	// Initialise variables
	std::string guess;
	int maxLives = 4;
	int remainingLives = maxLives;

	// Two different ways of displaying text to console
	std::cout << "Guess the secret word." << std::endl;
	printf("You have %i guesses. \n\n", maxLives);

	while (remainingLives > 0)
	{
		bool isValidGuess = false;

		// Recieves player guess and checks it is in the list
		while (!isValidGuess)
		{
			printf("Enter your guess: ");
			std::cin >> guess;
			std::cout << "your guess was: " << guess << std::endl;

			// Scan through the line, converting each character to upper case.
			for (int i = 0; i < guess.length(); i++)
			{
				if (isalpha(guess[i]))
				{
					guess[i] = toupper(guess[i]);
				}
			}

			// Check guess is in list
			for each (std::string word in options)
			{
				if (guess == word)
				{
					isValidGuess = true;
					break;
				}
			}

			// Player feedback and adjusts number of lives remaining
			if (!isValidGuess)
			{
				printf("Invalid guess. \nHint: guess should be one of the options. \n\n");
			}
			else
			{
				printf("That is a valid guess \n\n");
			}
		}

		// Check winning conditions
		if (guess == secret)
		{
			printf("You win! You got it in %i guesses. \n", maxLives - remainingLives);
			return 0;
		}

		// Calculate likeness score
		int likenessScore = getLikeness(guess, secret);
		printf("Likeness score: %i \n\n", likenessScore);

		// Decrement lives
		remainingLives -= 1;
		printf("You have %i guesses remaining \n\n", remainingLives);
	}

	// End game when out of lives
	printf("You lose. \n");
    return 0;
}


