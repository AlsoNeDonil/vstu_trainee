#include "Dict.h"

Dict::Dict(std::vector<std::string>& words)
{
	for (auto& word : words)
	{
		Add(word);
	}
}

Dict::Dict(std::vector<std::string> words)
{
	for (auto word : words)
	{
		Add(word);
	}
}