#include "needle.h"

Needle::Needle(const std::vector<char> &needle, const std::uint32_t threshold)
{
    if(needle.size() < threshold)
        throw std::exception();

    for (int offset = 0; offset < needle.size() - threshold; offset++)
    {
        for (int i = threshold; i <= needle.size(); i++)
        {
            int begin = offset;
            int end = (offset + i);
            if(end <= begin || end >= needle.size())
                break;
            _mapped.emplace(std::make_pair<uint, std::vector<char>>(begin, {needle.begin() + begin, needle.begin() + end}));
        }
    }
}

Needle::Needle(const Needle &_needle) :
    _mapped(_needle._mapped)
{
}
