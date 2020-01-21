#include "library.h"

 Library::Library(unsigned max){
                _size = max;
                _count = 0;
                _lib = new Book*[_size];
                for(unsigned i = 0; i<_size;i++)
                    _lib[i] = nullptr;
}
Book*const Library::get_book(std::string title)const{
                for(unsigned i = 0; i <_count; i++){
                    if(_lib[i]->_title == title)
                        return _lib[i];
                }
                
                return nullptr;
}
Library::Library(Library &&tmp){
                _lib = tmp._lib;
                _count = tmp._count;
                _size = tmp._size;
                tmp._lib = nullptr;
                tmp._count = 0;
                tmp._size = 0;
}
 Library::Library(const Library& tmp){
                _count = tmp._count;
                _size = tmp._size;
                _lib = new Book*[_size];
                for(unsigned i=0;i<_count;i++)
                    _lib[i]=new Book(tmp._lib[i]->_title, tmp._lib[i]->_author,tmp._lib[i]->_year, tmp._lib[i]->_genre, tmp._lib[i]->_ISBN);
}
void Library::new_book(const Book& tmp){
                if(_count < _size)
                    _lib[_count++] = new Book(tmp._title, tmp._author,tmp._year, tmp._genre, tmp._ISBN);
                else std::cout<<"Library full"<<std::endl;
}