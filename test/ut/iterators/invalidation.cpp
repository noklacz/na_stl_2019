//
// Created by pawluch on 3/6/19.
//

#include <gtest/gtest.h>
#include <vector>
#include <list>

TEST(invalidation, shrink_to_fit)
{
    std::vector<int> vec {1,2,3,4,5};
    vec.shrink_to_fit();

    auto it = vec.begin();
    vec.push_back(7);
    it = vec.begin(); // ASSIGN once again here!
    EXPECT_EQ(1, *it);
}

TEST(invalidation, remove_from_list)
{
    std::list<int> l{1,2,3,4,5};
    auto it = l.begin();
    EXPECT_EQ(1, *it);
    it = l.erase(it); // without assigning UB
    EXPECT_EQ(2, *it);
}

TEST(invalidation, remove_from_list_wrong_in_loop)
{
    std::list<int> l{1,2,3,4,5};
    for (auto it = l.begin(); it != l.end(); it++)
    {
        if (*it == 2)
            it = l.erase(it); // assign it!
    }
    std::list<int> expected{1,3,4,5};
    EXPECT_EQ(expected, l);
}