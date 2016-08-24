#include "searchresults.h"

void SearchResults::addResult(const int length, const int haystackOffset, const int needleOffset)
{
    _results.emplace(length, haystackOffset, needleOffset);
}
