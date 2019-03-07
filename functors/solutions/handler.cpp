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
#include <thread>
#include <chrono>

enum class ErrorCode
{
    Success,
    Failure
};

struct Data
{
    std::vector<int> input;
    Data(std::vector<int> data)
    {
        input = std::move(data);
    }
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

struct Handler
{
    void operator()(const ErrorCode ec) const
    {
        doHandlerPart(ec);
    }
};

auto lambda = [](const auto ec)
{
    doHandlerPart(ec);
};

void doSomeComputing(const Data& data, std::function<void(const ErrorCode)> handler)
{
    std::cout<<"Doing some computing..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    ErrorCode ec{};
    data.input.empty() ? ec = ErrorCode::Failure : ec = ErrorCode::Success;
    handler(ec);
}

int main()
{
    Data correctData{std::vector<int>{1, 2, 3, 4}};
    Data emptyData{std::vector<int>{}};

    doSomeComputing(emptyData, handler);
    doSomeComputing(correctData, Handler());
    doSomeComputing(emptyData, lambda);
    doSomeComputing(correctData, [](const ErrorCode ec)
    {
        doHandlerPart(ec);
    });
}
