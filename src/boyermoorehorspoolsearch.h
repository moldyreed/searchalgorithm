#ifndef BOYERMOOREHORSPOOLSEARCH_H
#define BOYERMOOREHORSPOOLSEARCH_H

#include <iostream>
#include <map>

#include "searchresults.h"
#include "needle.h"

/**
 * @brief The BoyerMooreHorspoolSearch class is a class which
 *        implements Boyer-Moore-Horspool search algorithm.
 */

class BoyerMooreHorspoolSearch
{
public:
    BoyerMooreHorspoolSearch(const Needle& needle);
    SearchResults search (const std::vector<char>& haystack) noexcept;
private:
    void preproccess(const std::vector<char>& needle) noexcept;
    std::map<char, int> _skipTable;
    std::set<std::string> _needleMap;
    const Needle _needle;
	
};

#endif // BOYERMOOREHORSPOOLSEARCH_H

