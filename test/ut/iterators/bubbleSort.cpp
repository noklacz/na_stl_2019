//
// Created by pawluch on 3/6/19.
//

#include <gtest/gtest.h>
#include <vector>

namespace iterators
{
template <typename It>
void bubble_sort(It begin, It end)
{
    if (begin == end)
        return;

    auto actual = begin;
    auto next = std::next(begin);
    bool changed = true;
    while(changed)
    {
        changed = false;
        while(next != end)
        {
            if (*actual > *next)
            {
                changed = true;
                std::swap(*actual, *next);
            }
            actual = std::next(actual);
            next = std::next(next);
        }
        actual = begin;
        next = std::next(actual);
    }
}
}
TEST(bubble_sort, should_not_crash_with_empty_data)
{
    std::vector<int> v{};
    iterators::bubble_sort(v.begin(), v.end());
}