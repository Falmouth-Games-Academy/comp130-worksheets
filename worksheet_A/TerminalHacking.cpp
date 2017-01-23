// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;
int lives = 4;

//Likeness algorithm
int GetLikeness(std::string guessedWord,std::string secretWord)
{
    int result = 0;
    for (int i = 0; i < secretWord.length(); i++)
    {
        if (guessedWord[i] == secretWord[i])
            result++;
    }
    return result;
}
//Check if a word is in a list return true or talse.
bool CheckList(std::set<std::string> list, std::string word)
{
    for (std::string wordFromList : list)
    {
        if (word == wordFromList)
            return true;
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
    for(std::string word : options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game
    while(lives>0)//Game loop
    {
        std::string guessedWord;        //Define guessedWord outside the Guess loop
        
        //Enter Guess. If word is in wordList continue.
        while(true)
        {
            printf("Enter your Guess!(You have %d lives left)\n",lives);
            std::cin >> guessedWord;    //Input Guess
            //If the guessed word is in the list return true and break the loop else print Invalid guess
            if(CheckList(options,guessedWord) == true)
                break;
            else
                printf("Invalid guess\n");
        }//End Guess loop
        
        //Check the guessed word against the secret word
        if (guessedWord == secret)  //If they are the same print you win and break the loop ending the process
        {
            printf("You win!\n");
            break;
        }
        else  //If the words are not the same GetLikness and decrease lives
        {
            printf("Your likeness score is: %d\n", GetLikeness(guessedWord,secret));
            lives--;
        }
        
    }//End lives>0 loop
    
    //When the loop ends check the lives and if it is 0 print "You lose!" else continue to end the process
    if (lives == 0)
        printf("You lose!\n");
    return 0;
}

