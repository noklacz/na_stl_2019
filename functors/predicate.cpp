/* TODO:
 * 1. Wypisz zawartosc biblioteki za pomoca iteratorow
 * 2. Posortuj i wypisz ksiazki alfabetycznie
 * 3. Wypisz pozycje powyzej 500 stron
 * 4. Wypisz pozycje ponizej 500 stron
 * 5. Zaimplementuj obiekt funkcyjny tak, aby umozliwial przyjecie dowolnej liczby stron
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

struct Book
{
    std::string title;
    int pages;

    Book(std::string tit, int pag) :
        title(tit), pages(pag){}
};

std::ostream& operator<<(std::ostream& stream, const Book& book)
{
    stream.width(30);
    return stream<<std::left<<book.title<<": "<<std::right<<book.pages<<" stron"<<std::endl;
}

void format()
{
    using std::cout;
    cout<<"\n\n"; cout.width(30);
}

int main()
{
    std::vector<Book> books{
        {"W pustyni i w puszczy", 325},
        {"Wladca Pierscieni", 639},
        {"Milosc w Walbrzychu", 912},
        {"Krzyzacy", 538},
        {"Zorro", 418},
        {"Quo Vadis", 836},
        {"Franklin idzie do szkoly", 101},
        {"Lysy z Nadodrza", 218},
        {"Anakonda", 118},
        {"Dywizjon 303", 313}
    };

    // TODO: Task 1
    //format(); std::cout<<std::internal<<"ORIGINAL LIBRARY BOOKS\n";

    // TODO: Task 2
    //format(); std::cout<<std::internal<<"SORTED LIBRARY BOOKS\n";

    // TODO: Task 3
    //format(); std::cout<<std::internal<<"LONG LIBRARY BOOKS\n";

    // TODO: Task 4
    //format(); std::cout<<std::internal<<"SHORT LIBRARY BOOKS\n";

    // TODO: Task 5
    //format(); std::cout<<std::internal<<"SHORTER THAN X\n";
}
