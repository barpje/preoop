#ifndef library_h
#define library_h
#include "book.h"

class Library{
    public:
//konstruktor tworzacy biblioteke o podanym rozmiarze, wypelniona pustymi wskaznikami
           Library(unsigned);
//metoda zwracacaja tablice ksiazek w bibliotece
           Book** const get_books()const{
                return _lib;
}
 //metoda zwraca wskaznik do ksiazki o podanym tytule    
           Book*const get_book(std::string)const;
//metoda tworzaca nowa ksiazke w bibliotece
           void new_book(const Book&);
//konstruktor przenoszacy
           Library(Library &&);
//konstruktor kopiujacy
           Library(const Library&);
//metoda zwracajaca aktualna liczbe ksiazek
           unsigned get_n_books()const{return _count;}
//destruktor czysci pamiec           
            ~Library(){
                for(unsigned i=0; i<_count; i++)
                    delete _lib[i];
                delete [] _lib;
}       
    private:
        Book ** _lib;// tablica wskaznikow na ksiazki
        unsigned _count;// aktualna liczba ksiazek w bibliotece
        unsigned _size = 0;//cpp11, maksymalna liczba ksiazek w bibliotece
};

#endif

