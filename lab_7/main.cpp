/// \file main.cpp
/// \mainpage
///
/// \n\n
///
//  ----------------------------------------------------------------------------------
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
/// 
///
/// Dodatkowe zastrzezenia:
/// a) Nalezy uzyc ***  CMake *** do przygotowania programu
/// -- pliki zrodlowe musza byc w podkatalogu 'src'
/// -- pliki naglowkowe musza byc w podkatalogu 'include' 
/// -- kod musi sie kompilowac w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' 
/// b) program musi się kompilować z flagami '-Wall -g' jako minimum
/// c) Jako rozwiazanie, prosze przeslac spakowany katalog zrodlowy, 
///    WLACZAJAC plik main.cpp, BEZ katalogu 'build'. 
/// d) Nie wolno modyfikowac pliku main.cpp.
//  --------------------------------------------------------------------------------- 
///
///    \n\n


// -----------------------------------------------------------
//
/// *** Klasa ToyotaCar ***
///
/// Klasa ta powinna implementowac nastepujace informacje 
/// na temat samochodow marki Toyota:
/// -- nazwa modelu
/// -- rok produkcji
/// -- przebieg
/// -- numer inwentaryzacyjny
/// -- cena
///
/// Jeden z konstruktorow musi okreslac (kolejno):
///   -- nazwe modelu
///   -- rok produkcji
///   -- przebieg
//
#include "car.h"
// ----------------------------------------------------------


// -----------------------------------------------------------
//
/// *** Klasa ToyotaDealer ***
///
/// Klasa ta powinna implementować salon sprzedajacy samochody
/// marki Toyota.
/// -- konstruktor musi okreslac 'rozmiar salonu', tj. ile 
///    maksymalnie samochodow moze salon posiadac
/// -- samochody musza sie znajdowac fizycznie w salonie 
///    (tj. obiekt klasy ToyotaDealer musi przechowywać obiekty ToyotaCar),
///    sposob ich przechowania jest dowolny o ile jest sensowny
/// -- musi istniec metoda wprowadzajaca nowy inwentarz do salonu
///    o nazwie 'new_inventory' i pobierajaca, kolejno:
///     -- obiekt ToyotaCar
///     -- nr inwentaryzacyjny nadawany samochodowi
///     -- cene samochodu 
/// -- musi istniec metoda 'show', pobierajaca nr inventaryzacyjny
///    samochodu jako argment, zwracajaca wskaznik do przechowywanego
///    obiektu ToyotaCar 
/// -- musi istniec metoda 'sell', pobierajaca nr inwentaryzacyjny
///    jako argument
///    ktora usuwa sprzedany samochod (czyli obiekt ToyotaCar) 
///    z inwentarza (kontenera);
///    cena sprzedanego samochodu musi powiekszac zarobek salonu
/// -- musi istniec metoda 'get_income' zwracajaca zarobek salonu
/// -- musi istniec metoda 'get_all_dealers_income' zwracajaca
///    zarobek wszystkich salonow razem.
//
#include "cardealer.h"
// --------------------------------------------------------------------     


#include<iostream>


int main() {
	
	std::cout << "\n";

	// Tworzymy dwa salony samochodowe:
	ToyotaDealer LarussoAutos(10), // salon miesci 10 pojazdow
		     ToyotaMotors(3);  // maly salon na 3 pojazdy

	// zaopatrujemy salon w samochody   (model,r.prod, przebieg)  nr invent., cena
	LarussoAutos.new_inventory(  ToyotaCar("RAV4",2017,3132)   ,101,18000);
	LarussoAutos.new_inventory(  ToyotaCar("RAV4",2019,3)     ,102,28000);
	LarussoAutos.new_inventory(  ToyotaCar("Yaris",2014,14234)  ,105,10100);
	LarussoAutos.new_inventory(  ToyotaCar("Corolla",2019,5)      ,106,27000);

	
	// zaopatrujemy salon w samochody
	ToyotaMotors.new_inventory(  ToyotaCar("Corolla",2018,11002)  ,203,18000);
	ToyotaMotors.new_inventory(  ToyotaCar("RAV4",2012,3112)    ,204,10200);
	ToyotaMotors.new_inventory(  ToyotaCar("RAV4",2019,6)     ,205,31400);
	ToyotaMotors.new_inventory(  ToyotaCar("Camry",2017,666)  ,208,22000);


	std::cout << "\n";

	// 'Ogladamy' samochod o nr inwentaryzacyjnym 102
	ToyotaCar* car = LarussoAutos.show(102);
	std::cout << "model: " << car->get_model() << ", " 
		  << "year: " << car->get_year()  << ", " 
		  << "mileage: " << car->get_mileage() << ", "
		  << "price: " << car->get_price() << std::endl;

	
	std::cout << "\n";


	// sprzedajemy samochody
	LarussoAutos.sell(102);
	LarussoAutos.sell(101);

	ToyotaMotors.sell(205);
	ToyotaMotors.sell(205);
	ToyotaMotors.sell(203);


	// posumowanie sprzedazy
	std::cout << "LarussoAutos income: " << LarussoAutos.get_income() << std::endl;
	std::cout << "ToyotaMotors income: " << ToyotaMotors.get_income() << std::endl;
	std::cout << "All dealers total income: " << ToyotaDealer::get_all_dealers_income() << std::endl;


	std::cout << "\n";

return 0;}

