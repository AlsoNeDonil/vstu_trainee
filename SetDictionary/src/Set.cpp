
#include "Set.h"

Set::Set(std::vector<int> values)
{
	for (auto it : values)
	{
		Add(it);
	}
}

void Set::Add(int value)
{
	if (!Exist(value))
	{
		m_Values.push_back(value);
		std::sort(m_Values.begin(), m_Values.end());
	}
}

void Set::Delete(int value)
{
	std::vector<int>::iterator pos;

	for (pos = m_Values.begin(); pos != m_Values.end(); pos++)
	{
		if (*pos == value)
			break;
	}

	if (pos != m_Values.end())
		m_Values.erase(pos);
}

bool Set::Exist(int value)
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
