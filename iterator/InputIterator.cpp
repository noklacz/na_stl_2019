#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <forward_list>

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

    return 0;
}
