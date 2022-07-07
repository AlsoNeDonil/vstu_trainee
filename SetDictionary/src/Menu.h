#pragma once

#include "Translator.h"
#include <iostream>

#ifdef _WIN32
	#define CLEAR_COMMAND system("cls")

#elif __linux__
	#define CLEAR_COMMAND system("clear")
#else
	#define CLEAR_COMMAND
#endif 


class Menu
{
public:
	Menu() = delete;

	static void Manage(Translator& t);

private:
	static void ShowOptions();
	static void TranslateSentence(Translator& t);
	static void ChangeDictionary(Translator& t);
};