#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

int main()
{
    std::vector<int> vec(100);
    std::random_device dv;
    std::mt19937 seed(dv());
    std::uniform_int_distribution<> dist(0, 30);
    
    /// (1) create lambda generator which return random value --> use comand dist(seed) which return random number
    auto generator = [&seed, &dist](){ return dist(seed); };
    std::generate(begin(vec), end(vec), generator);
    std::cout << "Print all numbers\n";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    std::cout << "Print first ten element\n";
    std::copy_n(begin(vec), 10, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n\n";

    std::cout << "All Odd numbers:\n";
    std::copy_if(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "),
                 [](const auto& el){ return el & 1; });
    /// (3) Print all odd numbers
    std::cout << "\nAll Even numbers:\n";
    std::remove_copy_if(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, ", "),
                 [](const auto& el){ return el & 1; });
    /// (4) Without changing implementation of lambda, print all Even numbers

    return 0;
}
