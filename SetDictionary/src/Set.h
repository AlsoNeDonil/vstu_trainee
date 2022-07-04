#pragma once
#include <vector>
#include <algorithm>

class Set
{
public:
	Set() = default;
	Set(std::vector<int> values);

	void Add(int value);
	void Delete(int value);

	bool Exist(int value);
	void Merge(Set& other);
	Set Intersect(Set& oher);

	std::vector<int>::iterator begin() { return m_Values.begin(); }
	std::vector<int>::iterator end() { return m_Values.end(); }

	~Set() = default;
private:
	std::vector<int> m_Values;
};