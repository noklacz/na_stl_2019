/*TODO:
 * 1. Zaimplementuj w postaci wyrazenia lambda generator liczb podzielnych przez 7.
 * 2. Zaimplementuj w postaci wyrazenia lambda predykat sprawdzajacy podzielnosc przez 3.
 * 3. Wygeneruj w petli 10 kolejnych liczb za pomoca generatora podzielnych przez 7
 *    Wyswietl wszystkie spelniajace warunek predykatu.
 */

#include <iostream>

auto gen = [state = 0]() mutable
{
    state += 7;
    return state;
};

auto pred = [](int x)
{
    return (x % 3 == 0);
};

//create "gen" and "pred" as a
// -- lambda expression

int main()
{
    for(int i=0 ; i<10 ; i++)
    {
        auto val = gen();
        if (pred(val)) std::cout<<val<<std::endl;
    }
}

