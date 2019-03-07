#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<int> vec;
    vec.resize(20);

    /// (1) Fill vector with value 10
    std::cout << "Print all numbers\n";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    /// (2) Fill first 5 element of vector with value 5
    std::cout << "Print all numbers\n";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    /// (3) Using Algorithm std::swap_ranges -> reverse vector
    std::cout << "Print reverse numbers\n";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    std::string sentence = "I'm pretty good at reversing my sentence";
    std::cout << std::setw(15) << "Sentence: " << sentence << std::endl;
    /// (4) Using Algorithm std::swap_ranges -> reverse std::string
    std::cout << std::setw(15) << "Reverse: " << sentence << std::endl;
    /// (5) Using std::reverse -> reverse std::string
    std::cout << std::setw(15) << "Reverse Again: " << sentence << std::endl;
    std::cout << std::setw(15) << "And again: ";
    /// (6) Using std::reverse_copy -> reverse std:;string
    std::cout << std::endl;

    std::cout << "\nUnique element in vec: ";
    /// (7) Print all unique value in vector
    std::cout << std::endl;

    return 0;
}
