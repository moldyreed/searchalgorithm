#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H

#include <iostream>
#include <set>
#include <tuple>

class SearchResults
{
public:
//    SearchResults();
//    ~SearchResults();
    void addResult(const int length, const int haystackOffset, const int needleOffset);
    std::set<std::tuple<int, int, int>> results() const { return _results; }
private:
    std::set<std::tuple<int, int, int>> _results;
};

#endif // SEARCHRESULTS_H
