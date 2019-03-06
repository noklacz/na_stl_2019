#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <forward_list>

int main()
{
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    auto forthPosition = (std::begin(vec) + 3);

    std::cout << "el: " << *forthPosition << std::endl;

    std::cout << std::endl;

    return 0;
}
