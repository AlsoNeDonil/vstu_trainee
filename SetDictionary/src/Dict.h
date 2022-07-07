#pragma once

#include "Set.h"

#include <fstream>

class Dict : public Set
{
public:
	Dict() = default;

	Dict(std::vector<std::string>& words);
	Dict(std::vector<std::string> words);

	~Dict() = default;
};