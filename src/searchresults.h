#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H

#include <iostream>
#include <set>
#include <tuple>

/**
 *
 * \brief The SearchResults class is a all results container
 *
 */

class SearchResults
{
public:
    void addResult(const int length, const int haystackOffset, const int needleOffset);
    std::set<std::tuple<int, int, int>> results() const { return _results; }

    enum
    {
        SequenceLength = 0,
        HaystackOffset = 1,
        NeedleOffset = 2
    };

private:
    std::set<std::tuple<int, int, int>> _results;
};

#endif // SEARCHRESULTS_H
