#include <iostream>
#include <map>

#include "boyermoorehorspoolsearch.h"

int main()
{
	const std::string& haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
	const std::string& needle   = "abcd1234";
	const uint16_t threshold = 3;
	std::set<std::string> mapped;

	for (int offset = 0; offset <= needle.length() - threshold; offset++)
	{
		for (int i = threshold; i <= needle.length(); i++)
		{
			mapped.emplace(needle.substr(offset, i));
		}
	}

	for (const auto& _needle : mapped)
	{
		BoyerMooreHorspoolSearch algorithm(_needle);
		SearchResults results = algorithm.search(haystack);

		for (const auto& result : results.results())
		{
			std::cout << std::get<0>(result) << "  " << std::get<1>(result) << "  " << std::get<2>(result) << std::endl;
		}
	}

	return 0;
}