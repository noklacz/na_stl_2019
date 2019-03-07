#include <iostream>
#include <algorithm>

void printAllRepetitions(const std::string& sentence)
{
    /// Print all repetition of word 'all' in sentence
    const std::string word = "all";
    auto it = std::begin(sentence);
    while (true)
    {
        it = std::search(it, end(sentence), begin(word), end(word));
        if (it == std::end(sentence))
        {
            break;
        }
        std::cout << "Find word: " << word << " at position: " << std::distance(begin(sentence), it) << '\n';
        std::advance(it, 1);
    }
}

int main()
{
    /// Exercise3
    std::string aphorism = "You can fool some of the people all of the time, and all of the people some of the time, but you can't fool all of the people all of the time";
    printAllRepetitions(aphorism);

    return 0;
}
