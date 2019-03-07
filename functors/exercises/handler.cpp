/* TODO:
 * 1. Stworz dwa obiekty typu Data: z pustym oraz niepustym wektorem liczb calkowitych
 * 2. Zaimplementuj funkcje doSomeComputing, przyjmujaca jako argumenty:
 *    - strukture Data
 *    - funkcje handler
 *    Puste dane wejsciowe powinny wywolac funkcje handler z kodem bledu Failure,
 *    w przeciwnym wypadku z kodem bledu Success.
 * 3. Zastap funkcje handler:
 *    - funktorem
 *    - wyrazeniem lambda
 *    - obsluz handler bezposrednio w miejscu wywolania
 */
#include <iostream>
#include <functional>
#include <vector>

enum class ErrorCode
{
    Success,
    Failure
};

struct Data
{
    std::vector<int> input;
    Data();
};

void doHandlerPart(const ErrorCode ec)
{
    ec == ErrorCode::Success ? std::cout<<"Success" : std::cout<<"Failure";
    std::cout<<std::endl;
}

void handler(const ErrorCode ec)
{
    doHandlerPart(ec);
}

int main()
{

}
