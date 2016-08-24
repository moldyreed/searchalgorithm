#include <iostream>
#include <map>

#include "boyermoorehorspoolsearch.h"

int main()
{
    const std::string& haystack = "ABAAABCD";
    const std::string& needle   = "ABC";
    BoyerMooreHorspoolSearch algorithm(needle);
    SearchResults results = algorithm.search(haystack);

    for (const auto& result : results.results())
    {
        std::cout << std::get<0>(result) << "  " << std::get<1>(result) << "  " << std::get<2>(result) << std::endl;
    }

    return 0;
}
