#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iterator>
#include <numeric>

template <typename IT, typename PRED, typename FUNC>
void transform_if(IT begin1, IT end1, IT begin2, PRED pred, FUNC func)
{
    while (begin1 != end1)
    {
        if (pred(*begin1))
        {
            *begin2 = func(*begin1);
            ++begin2;
        }
        ++begin1;
    }
};

int main()
{
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto pred = [](const auto& val){ return val > 5; };
    auto func = [](const auto& val){ return val * 2; };

    std::vector<int> vec2(5);
    transform_if(begin(vec), end(vec), begin(vec2), pred, func);
    std::copy(begin(vec2), end(vec2), std::ostream_iterator<int>(std::cout, ", "));

    return 0;
}












