#include "book.h"

Book::Book(const Book& tmp){
            _author = tmp._author;
            _title = tmp._title;
            _year = tmp._year;
            _genre = tmp._genre;
            _ISBN = tmp._ISBN;
}

 Book::Book(Book&& tmp){
            _author = std::move(tmp._author);
            _title = std::move(tmp._title);
            _year = std::move(tmp._year);
            _genre = std::move(tmp._genre);
            _ISBN = std::move(tmp._ISBN);
}