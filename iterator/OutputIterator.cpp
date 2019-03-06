#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <forward_list>
#include <deque>

int main()
{
    std::deque<int> deque {6, 11, 12, 13, 14};

    std::initializer_list<int> initList {7, 8, 9, 10};
    std::copy(begin(initList), end(initList), std::inserter(deque, std::next(std::begin(deque), 1)));

    std::istream_iterator<int> input2(std::cin);
    std::copy(input2, {}, std::front_inserter(deque));

    std::forward_list<int> forwardList {15, 16, 17, 18};
    std::copy(begin(forwardList), end(forwardList), std::back_inserter(deque));

    std::copy(begin(deque), end(deque), std::ostream_iterator<int>(std::cout, " | "));

    std::cout << std::endl;

    return 0;
}
