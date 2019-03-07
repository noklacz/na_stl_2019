/* TODO:
 * 1. Zaimplementuj obiekt funkcyjny sprawdzajacy czy podana liczba jest parzysta.
 * 2. Zaimplementuj obiekt funkcyjny sprawdzajacy czy podana liczba jest podzielna
 *    przez dowolna inna liczbe, tj. IsDivisible(2)(4) ma zwrocic true.
 * 3. Stworz wektor 100 kolejnych rosnacych licz calkowitych z zakresu 0-99 i wyswietl
 *    jego zawartosc.
 * 4. Usun z wektora wszystkie liczby parzyste, nastepnie podzielne przez 3 i na koniec
 *    podzielne przez 5.
 * 5. Usun z wektora wszystkie liczby pierwsze.
 */

#include <iostream>
#include <cassert>
#include <numeric>
#include <vector>
#include <algorithm>

struct IsEven
{
    bool operator()(int val) const
    {
        return (val % 2 == 0);
    }

};

struct IsDivisibleBy
{
    int divisor;

    IsDivisibleBy(int val) : divisor(val) {}

    bool operator()(int val) const
    {
        return (val % divisor == 0);
    }

};

bool isPrime(int val)
{
    if (val < 2) return false;
    for(int i = 2; i < val/2; i++)
    {
        if (val % i == 0) return false;
    }
    return true;
}

int main()
{
    assert(IsEven()(6) == true);
    assert(IsDivisibleBy(2)(4) == true && IsDivisibleBy(3)(5) == false);

    std::vector<int> vec(100);
    std::iota(vec.begin(), vec.end(), 0);
    //for(const auto& x : vec) std::cout<<x<<std::endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), IsDivisibleBy(2)), vec.end());
    vec.erase(std::remove_if(vec.begin(), vec.end(), IsDivisibleBy(3)), vec.end());
    vec.erase(std::remove_if(vec.begin(), vec.end(), IsDivisibleBy(5)), vec.end());
    //for(const auto& x : vec) std::cout<<x<<std::endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), isPrime), vec.end());
    //for(const auto& x : vec) std::cout<<x<<std::endl;
}

