#include "boyermoorehorspoolsearch.h"

BoyerMooreHorspoolSearch::BoyerMooreHorspoolSearch(const Needle &needle) :
    _needle(needle)
{
}

SearchResults BoyerMooreHorspoolSearch::search(const std::vector<char> &haystack) noexcept
{
	SearchResults results;
    for(const auto& _pair : _needle.mapped()){
        auto skip = 0;
        const auto& needle =  _pair.second;
        preproccess(needle);

        while (haystack.size() - skip >= needle.size())
        {
            auto i =  needle.size() - 1;
            while (haystack[skip + i] == needle[i])
            {
                if (i == 0)
                    results.addResult(needle.size(), skip + i, _pair.first);
                i = i - 1;
            }

            auto nextSkipStep = _skipTable[haystack[(skip + needle.size() - 1)]];
            skip = skip + nextSkipStep;
        }
    }

	return results;
}

void BoyerMooreHorspoolSearch::preproccess(const std::vector<char> &needle) noexcept
{
    _skipTable.clear();

	for (int i = 0; i < UINT8_MAX; i++)
	{
        _skipTable[(i + '0')] = needle.size();
	}

    for (int i = 0; i < needle.size() - 1 ; i++)
	{
        _skipTable[needle[i]] = needle.size() - 1 - i;
	}
}
