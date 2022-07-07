#pragma once

#include <fstream>
#include "Dict.h"

class Translator
{
public:

	Translator() = default;
	Translator(Dict firstLang, Dict secondLang);
	Translator(const std::string& filepath);

	std::string Translate(std::string& sentence);

	~Translator() = default;
private:
	void ParseFromFile(const std::string& filepath);
	std::vector<std::string> SplitWords(std::string& sentence);
private:
	Dict m_FirstLanguage;
	Dict m_SecondLanguage;
};