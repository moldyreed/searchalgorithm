#ifndef BOYERMOOREHORSPOOLSEARCH_H
#define BOYERMOOREHORSPOOLSEARCH_H

#include <iostream>
#include <map>

#include "searchresults.h"

class BoyerMooreHorspoolSearch
{
public:
    BoyerMooreHorspoolSearch(const std::string& needle);
    SearchResults search (const std::string& haystack) noexcept;
private:
    void preproccess(const std::string& needle) noexcept;
    std::map<int, char> _skipTable;
    std::set<std::string> _needleMap;
	std::string _needle;
	
};

#endif // BOYERMOOREHORSPOOLSEARCH_H

