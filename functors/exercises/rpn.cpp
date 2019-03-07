/*
Algorytm obliczenia wartości wyrażenia ONP:
- Jezeli i-ty symbol jest liczba, to odloz go na stos
- Jezeli i-ty symbol jest operatorem, to:
    - zdejmij ze stosu jeden element (a)
    - zdejmij ze stosu kolejny element (b)
    - odloz na stos wartosc b operator a
- Zdejmij ze stosu wynik

TODO:
1. Zapoznaj sie z kodem
2. Zaproponuj kontener przechowujacy dane
3. Zaimplementuj funkcje processNumber
4. Zaimplementuj funkcje processOperator uwzgledniajac
   obsluge wyjatku out_of_range/invalid_argument oraz blad wyrazenia
5. Przetestuj dla przykladowych danych wejsciowych:

"3 1 2 + * 2 /"
"2 7 + 3 / 14 3 - 4 * + 2 /"
"12 2 3 4 * 10 5 / + * +"

*/

#include <iostream>
#include <map>
#include <functional>
#include <iterator>
#include <stack>
#include <sstream>
#include <stdexcept>

using Iter = std::istream_iterator<std::string>;

std::stack<double> val_stack;

void processNumber(double val)
{

}

void processOperator(Iter it)
{

}

double rpn(Iter it, Iter end)
{
    while(it != end)
    {
        std::stringstream ss{*it};
        double val;
        (ss >> val) ? processNumber(val) : processOperator(it);

        ++it;
    }
    return val_stack.top();
}

int main()
{
    try
    {
        std::cout<<rpn(Iter{std::cin}, {})<<std::endl;
    }
    catch(...)
    {
        std::cout<<"Nieprawidlowe wyrazenie RPN"<<std::endl;
    }
}
