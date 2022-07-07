#include <iostream>
#include <intrin.h>

#include "Translator.h"
#include "Menu.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Translator t("assets/dict.txt");

	std::string sentence1("Brother Mother Dima asshole");
	std::string sentence2("Nastya jump in window");

	Menu::Manage(t);

	return 0;
}