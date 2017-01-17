// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int likeness(std::string secret, std::string guess);
std::string guessed;


int main()
{	
	std::cout << "enter guess word:";
	std::cin >> guessed;
	likeness("mouse", guessed);
	
    return 0;
}

int likeness(std::string secret, std::string guess)
{
	int len = guess.length();
	for (int i = 0; i < len; i++)
	{
		std::cout << guess;
	}
	return 0;
}
 
