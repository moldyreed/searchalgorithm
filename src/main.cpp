#include <iostream>
#include <map>
#include <vector>

#include "boyermoorehorspoolsearch.h"
#include "needle.h"

int main()
{
    const char _cHaystack[] = "vnk2435kvabco8awkh125kjney123tbcd12qjhb4acd123xmnbqwnw4t";
    const char _cNeedle[] = "abcd1234";
    const std::vector<char>& _needle {_cNeedle, _cNeedle + sizeof _cNeedle / sizeof _cNeedle[0] - 1};
    const std::vector<char>& _haystack {_cHaystack, _cHaystack + sizeof _cHaystack / sizeof _cHaystack[0] - 1};
    const uint32_t threshold = 3;

    Needle needle{_needle, threshold};
    BoyerMooreHorspoolSearch algorithm{needle};
    const SearchResults& results = algorithm.search(_haystack);

    for (const auto& result : results.results())
    {
        std::cout << " sequence of length = "       << std::get<SearchResults::SequenceLength>(result) <<
                     " found at haystack offset = " << std::get<SearchResults::HaystackOffset>(result) <<
                     ", needle offset = "           << std::get<SearchResults::NeedleOffset>(result) << std::endl;
    }

	return 0;
}
