#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

bool isPalindrome(std::string text)
{
    /// Using only algorithm and predicate check if sentence is palindrome
    return true;
}

int main()
{
    /// Exercise2
    std::string word1 = "Aba";
    std::string word2 = "Anakonda";
    std::string word3 = "A man a plan a Canal Panama";
    std::string word4 = "Do geese see God";
    std::string word5 = "A";
    std::string word6 = "Ac";
    std::cout << "is palindrome: " << word1 << std::boolalpha << " : " << isPalindrome(word1) << "\n";
    std::cout << "is palindrome: " << word2 << std::boolalpha << " : " << isPalindrome(word2) << "\n";
    std::cout << "is palindrome: " << word3 << std::boolalpha << " : " << isPalindrome(word3) << "\n";
    std::cout << "is palindrome: " << word4 << std::boolalpha << " : " << isPalindrome(word4) << "\n";
    std::cout << "is palindrome: " << word5 << std::boolalpha << " : " << isPalindrome(word5) << "\n";
    std::cout << "is palindrome: " << word6 << std::boolalpha << " : " << isPalindrome(word6) << "\n";

    return 0;
}
