#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main()
{
    std::vector<int> vec(100);
    std::random_device dv;
    std::mt19937 seed(dv());
    std::uniform_int_distribution<> dist(0, 30);
    
    /// (1) create lambda generator which return random value --> use comand dist(seed) which return random number
    std::generate(begin(vec), end(vec), generator);
    std::cout << "Print all numbers\n";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    std::cout << "Print first ten element\n";
    /// (2) Print first 10 elements of vector
    std::cout << "\n\n";

    std::cout << "All Odd numbers:\n";
    /// (3) Print all odd numbers

    std::cout << "All Even numbers:\n";
    /// (4) Without changing implementation of lambda, print all Even numbers

    return 0;
}
