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

using OIter = std::ostream_iterator<Book>;

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

bool titleCompare(const Book& left, const Book& right)
{
    return left.title < right.title;
}

bool takeLongBooks(const Book& book)
{
    return book.pages > 500;
}

struct HasLessPagesThan
{

    int value;

    HasLessPagesThan(int val) : value(val){}

    bool operator()(const Book& book) const
    {
        return book.pages < value;
    }

};

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

    format(); std::cout<<std::internal<<"ORIGINAL LIBRARY BOOKS\n";
    std::copy(books.begin(), books.end(), OIter(std::cout, ""));

    format(); std::cout<<std::internal<<"SORTED LIBRARY BOOKS\n";
    std::sort(books.begin(), books.end(), titleCompare);
    std::copy(books.begin(), books.end(), OIter(std::cout, ""));

    format(); std::cout<<std::internal<<"LONG LIBRARY BOOKS\n";
    std::copy_if(books.begin(), books.end(), OIter(std::cout, ""),
            takeLongBooks
    );

    format(); std::cout<<std::internal<<"SHORT LIBRARY BOOKS\n";
    std::remove_copy_if(books.begin(), books.end(), OIter(std::cout, ""),
            takeLongBooks
    );

    format(); std::cout<<std::internal<<"SHORTER THAN X\n";
    std::copy_if(books.begin(), books.end(), OIter(std::cout, ""),
           HasLessPagesThan(550)
    );
}
