#include "boyermoorehorspoolsearch.h"

BoyerMooreHorspoolSearch::BoyerMooreHorspoolSearch(const std::string& needle) :
	_needle(needle)
{
	preproccess(needle);
}

SearchResults BoyerMooreHorspoolSearch::search(const std::string& haystack) noexcept
{
	auto skip = 0;
	SearchResults results;

	while (haystack.length() - skip >= _needle.length())
	{
		auto i =  _needle.length() - 1;
		while (haystack[skip + i] == _needle[i])
		{
			if (i == 0)
				std::cout << skip << std::endl;
			i = i - 1;
		}

		skip = skip + _skipTable[haystack[skip + _needle.length() - 1]];
	}

	return results;
}

void BoyerMooreHorspoolSearch::preproccess(const std::string& needle) noexcept
{
	for (int i = 0; i < UINT8_MAX; i++)
	{
		_skipTable[i] = needle.length();
	}

	for (int i = 0; i < needle.length(); i++)
	{
		_skipTable[needle[i]] = needle.length() - 1 - i;
	}
}
