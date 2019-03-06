#include <iostream>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <vector>
#include <fstream>
#include <forward_list>
#include <deque>
#include <list>
#include <functional>
#include <utility>

/// Bidirectional Iterator
class BidirectionalIterator
{
public:
    explicit BidirectionalIterator(const size_t position): position_(position)
    {}

    size_t operator* () const { return position_; }
    BidirectionalIterator& operator-> () { return *this; }

    /// pre
    BidirectionalIterator& operator++() { ++position_; return *this; }
    BidirectionalIterator& operator--() { --position_; return *this; }

    /// post
    BidirectionalIterator operator++(int) { BidirectionalIterator tmp(*this); ++position_; return tmp; }
    BidirectionalIterator operator--(int) { BidirectionalIterator tmp(*this); --position_; return tmp; }

    bool operator!= (const BidirectionalIterator& other) const { return position_ != other.position_; }
    bool operator== (const BidirectionalIterator& other) const { return !(*this != other); }

private:
    size_t position_;
};

class MyRange
{
public:
    MyRange(const size_t count): count_(count)
    {}

    BidirectionalIterator begin() const { return BidirectionalIterator(0); }
    BidirectionalIterator end() const { return BidirectionalIterator(count_); }

private:
    const size_t count_;
};

namespace std
{
template <>
struct iterator_traits<BidirectionalIterator>
{
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = size_t;
    using difference_type = int;
    using pointer = size_t*;
    using reference = size_t&;
};
}

int main()
{
    /// Input Iterator
    std::istream_iterator<int> input(std::cin);
    std::copy(input, {}, std::ostream_iterator<int>(std::cout, ", "));

    std::vector<double> vecOfDouble;
    std::ifstream readOnlyFile("readOnlyFile", std::ios::in);
    std::copy(std::istream_iterator<double>(readOnlyFile), {}, std::back_inserter(vecOfDouble));
    for (const auto el : vecOfDouble)
    {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    /// Forward Iterator
    std::ofstream writeOnlyFile("writeOnlyFile", std::ios::out);
    std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list.begin();
    std::copy(begin(list), end(list), std::ostream_iterator<int>(writeOnlyFile, ", "));

    /// Bidirectional Iterator
    MyRange myRange(15);
    std::cout << "\nElements: ";
    std::copy(std::begin(myRange), std::end(myRange),
              std::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\nElements: ";
    auto it = --std::end(myRange);
    auto middle = std::next(std::begin(myRange), 7);
    for (it ; it != middle; --it)
    {
        std::cout << *it << ", ";
    }

    /// Random Acces Iterator & Contiguous Iterator
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    auto forthPosition = (std::begin(vec) + 3);

    std::cout << "el: " << *forthPosition << std::endl;

    std::cout << std::endl;

    /// Output Iterator
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
