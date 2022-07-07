#include <iostream>
#include <intrin.h>

#include "Translator.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Translator t("assets/dict.txt");

	std::string sentence1("Brother Mother Dima govno");
	std::string sentence2("Mother jump in window");

	std::cout << t.Translate(sentence1) << std::endl;
	std::cout << t.Translate(sentence2) << std::endl;

	system("pause");
	return 0;
}