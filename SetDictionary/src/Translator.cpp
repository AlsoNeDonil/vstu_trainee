
#include "Translator.h"

#include <sstream>

Translator::Translator(Dict firstLang, Dict secondLang)
	: m_FirstLanguage(firstLang), m_SecondLanguage(secondLang)
{
}

Translator::Translator(const std::string& filepath)
{
	ParseFromFile(filepath);
}

bool Translator::ChangeDict(const std::string& filepath)
{
	m_FirstLanguage.DeleteAll();
	m_SecondLanguage.DeleteAll();
	return ParseFromFile(filepath);
}

std::string Translator::Translate(std::string& sentence)
{
	auto words = SplitWords(sentence);

	std::string translated_sentense;
	for (auto word : words)
	{
		int pos = m_FirstLanguage.GetByWord(word);
		if (pos >= 0)
		{
			translated_sentense += m_SecondLanguage.GetByIndex(pos) + " ";
		}
		else
		{
			translated_sentense += word + " ";
		}
	}

	return translated_sentense;
}

std::vector<std::string> Translator::SplitWords(std::string& sentence)
{
	std::vector<std::string> words;

	std::string word;
	std::istringstream iss(sentence);

	while (std::getline(iss, word, ' '))
	{
		words.push_back(word);
	}

	return words;
}

bool Translator::ParseFromFile(const std::string& filepath)
{
	std::ifstream ifs(filepath.c_str());

	std::string first;
	std::string second;

	if (ifs.bad() || !ifs)
		return false;

	std::string line;
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		size_t pos = line.find(" ");


		first = line.substr(0, pos);
		line.erase(0, pos + 1);
		second = line;
		
		if ( (first.size() != 0) && (second.size() != 0))
		{
			m_FirstLanguage.Add(first);
			m_SecondLanguage.Add(second);
		}

	}

	return true;
}
