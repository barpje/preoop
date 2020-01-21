#ifndef book_h
#define book_h
#include <string>
#include <iostream>

enum Genre{ crime, sci_fi, thiller, bajka, undefined};
class Library;
class Book{
//deklaracja przyjazni z klasa Library
    friend class Library;
    public:
//konstruktor domyslny oraz konstruktor przyjmujacy podane wartosci
        Book(std::string title= "", std::string author = "", short unsigned year = 0, Genre genre = undefined, long unsigned int ISBN = 0){
                _author = author;
                _title = title;
                _year = year;
                _genre = genre;
                _ISBN = ISBN;
};
   
//metoda zwraca autora ksiazki
        std::string get_author()const{
            return _author;
}
//konstruktor    przenoszacy    
        Book(Book&&);
//konstruktor kopiujacy
        Book(const Book&);
//funkcja konwertujaca z klasy Book na string
        operator std::string()const{
                return _title;
}
//funkcja konwertujaca z klasy Book na short unsigned
        operator short unsigned()const{
                return _year;
}
//funkcja konwertujaca z klasy Book na Genre
        operator Genre()const{
                return _genre;
}
//funkcja konwertujaca z klasy Book na long unsigned int
        operator long unsigned int()const{
                return _ISBN;
}

             

    private:
        std::string _title;//tytul ksiazki
        std::string _author;//autor ksiazki
        short unsigned _year;//rok wydania
        Genre _genre;//gatunek
        long unsigned int _ISBN;// numer ISBN
};

#endif

