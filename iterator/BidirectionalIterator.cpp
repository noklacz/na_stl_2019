#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <forward_list>

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
    std::cout << std::endl;

    return 0;
}
