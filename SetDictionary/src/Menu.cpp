
#include "Menu.h"

void Menu::Manage(Translator& t)
{
	std::string userInput;
	while (true)
	{
		ShowOptions();
		std::cin >> userInput;

		int guess = atoi(userInput.c_str());
		CLEAR_COMMAND;

		switch (guess)
		{
		case 1:
			TranslateSentence(t);
			break;

		case 2:
			ChangeDictionary(t);
			break;

		case 3:
			return;

		default:
			std::cout << "Unknown action" << std::endl;
			break;
		}
	}
}

void Menu::ShowOptions()
{
	std::cout << "Choose action:" << std::endl;
	std::cout << "\t1. TranslateSentence" << std::endl;
	std::cout << "\t2. Change dictionary" << std::endl;
	std::cout << "\t3. Close translator" << std::endl;
}

void Menu::TranslateSentence(Translator& t)
{
	while (true)
	{
		std::cout << "Input sentence:(\q to quit)" << std::endl;

		std::string userInput;
		std::cin.ignore(1, 1);
		std::getline(std::cin, userInput);

		if ((userInput != "\t") && (userInput.size() != 0))
		{
			std::cout << t.Translate(userInput) << std::endl;
		}

		else
		{
			return;
		}

	}
}

void Menu::ChangeDictionary(Translator& t)
{
	std::cout << "Input dictionary filename" << std::endl;
	std::string userInput;
	std::cin >> userInput;

	if (!t.ChangeDict(userInput))
	{
		std::cout << "Error: File not found..." << std::endl;
	}
}

