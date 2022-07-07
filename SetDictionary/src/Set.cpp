
#include "Set.h"

void Set::Add(std::string& value)
{
	if (!Exist(value))
	{
		m_Values.push_back(value);
	}
}

void Set::Delete(std::string& value)
{
	std::vector<std::string>::iterator pos;

	for (pos = m_Values.begin(); pos != m_Values.end(); pos++)
	{
		if (*pos == value)
			break;
	}

	if (pos != m_Values.end())
		m_Values.erase(pos);
}

std::string Set::GetByIndex(size_t index)
{
	if (index < m_Values.size())
	{
		return m_Values[index];
	}
}

int Set::GetByWord(std::string& word)
{
	auto pos = std::find(m_Values.begin(), m_Values.end(), word);
	auto dist = std::distance(m_Values.begin(), pos);
	int index = (pos != m_Values.end()) ? dist : -1;
	return index;
}

bool Set::Exist(std::string& value)
{
	auto it = std::find(m_Values.begin(), m_Values.end(), value);
	return (it != m_Values.end());
}

void Set::Merge(Set& other)
{
	for (auto it : other)
	{
		Add(it);
	}

}

Set Set::Intersect(Set& other)
{
	Set result;

	for (auto it : other)
	{
		if (Exist(it))
			result.Add(it);
	}

	return result;
}
