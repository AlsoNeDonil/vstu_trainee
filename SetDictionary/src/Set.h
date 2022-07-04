#pragma once
#include <vector>
#include <string>
#include <algorithm>

class Set
{
public:
	Set() = default;
	Set(std::vector<std::string> values);

	void Add(std::string& value);
	void Delete(std::string& value);

	bool Exist(std::string& value);
	void Merge(Set& other);
	Set Intersect(Set& oher);

	std::vector<std::string>::iterator begin() { return m_Values.begin(); }
	std::vector<std::string>::iterator end() { return m_Values.end(); }

	~Set() = default;
private:
	std::vector<std::string> m_Values;
};