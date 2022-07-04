
#include "Set.h"

Set::Set(std::vector<std::string> values)
{
	for (auto it : values)
	{
		Add(it);
	}
}

void Set::Add(std::string& value)
{
	if (!Exist(value))
	{
		m_Values.push_back(value);
		std::sort(m_Values.begin(), m_Values.end());
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

	std::sort(m_Values.begin(), m_Values.end());
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
