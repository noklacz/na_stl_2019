#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <forward_list>

int main()
{
    std::ofstream writeOnlyFile("writeOnlyFile", std::ios::out);
    std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list.begin();
    std::copy(begin(list), end(list), std::ostream_iterator<int>(writeOnlyFile, ", "));

    return 0;
}
