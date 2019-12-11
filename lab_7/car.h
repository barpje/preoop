#ifndef car_h
#define car_h

class ToyotaDealer;
class ToyotaCar{
//deklaracja przyjazni z klasa ToyotaDealer
    friend class ToyotaDealer;
    public:
//konstruktor dktory ustawia wszystkie pola klasy
    ToyotaCar(const char*,int,int,int,int);
//konstruktor, ktory ustawia nazwe modelu,rok produkcji,przebieg
    ToyotaCar(const char*,int,int);
//metoda zwraca model
    const char* get_model()const{
            return model;
};
//metoda zwraca rok produkcji
	int get_year()const{
        return year;
}; 
//metoda zwraca przebieg
	int get_mileage()const{
        return miles;
};
//metoda zwraca cene
	int get_price()const{
        return price;
};

    private:
///model
            const char* model;
// rok produkcji
            int year;
/// -- przebieg
            int miles;
/// -- cena
            int price;
/// -- numer inwentaryzacyjny
            int number;      

};


#endif
