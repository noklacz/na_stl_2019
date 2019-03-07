#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Students
{
    std::string name_;
    std::vector<int> grades_;

    friend std::ostream& operator << (std::ostream& out, const Students& student)
    {
        out << "Name: " << std::setw(8) << student.name_ << " grades: ";
        /// (1) Using std::for_each print all grades separated by ','
        std::for_each(begin(student.grades_), end(student.grades_),
            [&out](const int grade)
            {
                out << grade << ", ";
            });
        return out;
    }
};

auto printer()
{
    return [](const auto& vec)
    {
        /// (2) Using std::for_each implement printer function
        std::for_each(begin(vec), end(vec),
        [](const auto& el)
        {
            std::cout << el << std::endl;
        });
    };
}

int main()
{
    /// Exercise 1
    std::vector<Students> vec {
        {"Tom", {1, 2, 3, 4, 5, 6}},
        {"John", {5, 5, 5, 5, 3, 2}},
        {"Mike", {4, 3, 2, 3, 2, 6}},
        {"Jerry", {5, 5, 5, 6, 5, 4, 5}},
        {"Cris", {3, 3, 4, 2, 3, 5, 6}},
        {"Emil", {3, 2, 3, 4, 3, 3, 4}},
        {"Mathew", {2, 3, 2, 1, 1, 3}},
        {"Alice", {4, 5, 4, 5, 4, 5, 4}},
        {"Alison", {5, 5, 3, 2, 4, 5, 6}}
    };

    printer()(vec);

    /// (3) using only algorithm and predicate find if someone got 6 grade
    bool isSomeoneGot6 = std::any_of(begin(vec), end(vec),
            [](const Students& student) -> bool
            {
                bool res = std::any_of(begin(student.grades_), end(student.grades_),
                        [](const auto& el){ return el == 6; });
                return res;
            });

    /// (4) using only algorithm and predicate find if everybody got 6 grade
    bool isEveryoneGot6 = std::all_of(begin(vec), end(vec),
            [](const Students& student) -> bool
            {
                bool res = std::any_of(begin(student.grades_), end(student.grades_),
                                       [](const auto& el){ return el == 6; });
                return res;
            });

    /// (5) using only algorithm and predicate count number of student which got grade 1
    size_t numOfStdentWith1 = std::count_if(begin(vec), end(vec),
            [](const Students& student) -> bool
            {
                bool res = std::any_of(begin(student.grades_), end(student.grades_),
                                       [](const auto& el){ return el == 1; });
                return res;
            });

    std::cout << "Is someone got 6? " << std::boolalpha << isSomeoneGot6 << std::endl;
    std::cout << "Is everyone got 6? " << std::boolalpha << isEveryoneGot6 << std::endl;
    std::cout << "Number of students with grade 1: " << numOfStdentWith1 << std::endl;

    return 0;
}
