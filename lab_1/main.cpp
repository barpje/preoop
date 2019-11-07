/// \file main.cpp
/// \mainpage
///
/// Program implememtuje 'robota' na 2D plaszczyznie.
/// Roboty moga wykonywac dwie operacje: ruch wkierunku x lub y
/// o zdana liczbe pol.
/// W jednym punkcie nie moze znajdowac sie wiecej niz 1 robot. 
/// Nakladamy ograniczenie na maskymalna liczbe robotow: 5; \n\n
///
///
/// Nalezy utworzyc brakujace pliki naglowkowe
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany na koncu tego pliku.
/// Prosze NIE UZYWAC klas (mozna uzywac struktur, ale tylko jako 
/// POD -- plain-old-data). 
/// 
/// Wskazowki:
/// -- W miare mozliwosci prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///
///    \n\n
///
/// Zasady ogolne pracowni: \n
/// 1) Nie wolno modyfikowac pliku main.cc oraz ewentualnych innych 
///  plikow gdzie jest to explicite zastrzezone odpowiednim komentarzem. \n 
/// 2) Nie wolno korzystac z pomocy kolegow/prowadzacego, internetu, notatek,
/// ani zadnych innych materialow (w tym wlasnych wczesniej
/// przygotowanych plikow).\n
/// 2) Kod zrodlowy musi znajdowac sie w katalogu o prawach dostepu 
/// tylko dla uzytkownika.\n
/// 3) Nalezy zadbac o przejrzystosc programu oraz dobre zarzadzanie pamiecia.\n
/// 4) Punktacja: poprawna kompilacja - 2pkt, poprawne wyjscie oraz brak wyciekow pamieci -- 3pkt,
/// dokumentacja -- 1pkt, ocena kodu -- max 4pkt. Kod MUSI sie kompilowac aby byl w ogole oceniany.
///
/// POWODZENIA!


#include<iostream>

#include "robots.h"


int main() {
	
	std::cout << "\n";

	// Tworzymy pierwszego robota w punkcie x=0, y=0
	PositionXY posxy1 = {0,0};
	Robot *robot1 = CreateRobot("Marry",posxy1);
	// Prosimy robota o przedstawienie sie
	Speak(robot1);

	// Tworzymy drugiego robota
	PositionXY posxy2 = {2,-4};
	Robot *robot2 = CreateRobot("Bobby",posxy2);
	Speak(robot2);

	// Proba utworzenia 3go robota
	Robot *robot3 = CreateRobot("Georgie",posxy2);
	Speak(robot3);

	// Tworzymy automatycznie roboty
	for (int i=1;i<5;++i) {
		PositionXY pos = {i*3,i*4};
		Robot *robot = CreateRobot(pos);
		Speak(robot); 
	}

	std::cout << "\n";

	// Przesuwamy robota nr 1
	ShiftX(robot1,-2);
	ShiftY(robot1,4);
	Speak(robot1);
	
	std::cout << "\n";

	// Probujmey przesunac robota 2 do miejsca gdzie anjduje sie nr 1
	ShiftX(robot2,-4);
	ShiftY(robot2,8);
	Speak(robot2);

	std::cout << "\n";

	// Kilka operacji na robocie
	Operation moveXY[] = {ShiftX,ShiftY,ShiftX,ShiftX,ShiftY,ShiftX};
	int shifts[] = {-3,5,12,10,-29,11};
	int opsize = sizeof(moveXY)/sizeof(Operation);
	for (int i=0;i<opsize;++i) 
		moveXY[i](robot1,shifts[i]);
	Speak(robot1);

	RemoveRobots();

return 0;}

/*
>> Hi, I'm robot Marry standing at x=0, y=0.
>> Hi, I'm robot Bobby standing at x=2, y=-4.
CreateRobot: Robots cannot be placed in the same position.
Speak: No such robot.
>> Hi, I'm robot noname standing at x=3, y=4.
>> Hi, I'm robot noname standing at x=6, y=8.
>> Hi, I'm robot noname standing at x=9, y=12.
CreateRobot: Reached maximal number of robots.
Speak: No such robot.

>> Hi, I'm robot Marry standing at x=-2, y=4.

ShiftY: Robots cannot stand in the same position.
>> Hi, I'm robot Bobby standing at x=-2, y=-4.

>> Hi, I'm robot Marry standing at x=28, y=-20.
*/
