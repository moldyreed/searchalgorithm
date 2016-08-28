#ifndef __searchalgorithm__needle__
#define __searchalgorithm__needle__

#include <iostream>
#include <vector>
#include <map>

/**
 * @brief The Needle class is a container class for needle bytes
 *        it stores needle offsets and "cut" bytes according
 *        threshold.
 */

class Needle
{
    std::map<uint, std::vector<char>> _mapped;
public:
    Needle(const std::vector<char>& needle, const std::uint32_t threshold);
    Needle(const Needle & _needle);
    std::map<uint, std::vector<char>> mapped() const { return _mapped; }
};

#endif /* defined(__searchalgorithm__needle__) */
