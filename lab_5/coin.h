#ifndef coin_h
#define coin_h

enum rodzaj{heads, tails};
enum wartosc{one=1,two=2};

///klasa reprezentujaca monety
class Coin{
    public:
    //konstruktor tworzacy monete, o wartosci 1 i losowej stronie
    Coin();
    //konstruktor tworzacy monete o zadanej wartosci, losowej stronie
    Coin(wartosc);
    //metoda do losowania strony monety
    void toss();
    //metoda do wypisywania strony monety
    void print_side_up();
    //metoda zwracajaca wartosc monety
    wartosc get_coin_value() const{
        return _y;
    };
    //metoda zwracajaca strone monety
    rodzaj get_side_up() const {
        return _x;
    };
   
    private:
    rodzaj _x; 
    wartosc _y;
};

#endif
