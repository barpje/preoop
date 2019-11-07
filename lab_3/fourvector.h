#ifndef fourvector_h
#define fourvector_h
#include <iostream>
///struktura zawieraca wspolrzedne czterowektora oraz jego mase niezmiennicza
typedef struct v{
    double x;
    double y;
    double z;
    double t;
    double M2;
}FVector;

///funkcja wypisuja wspolrzedne czterowektora
void PrintFVector(FVector gluon);
///funkcja wypisuja wspolrzedne czterowektora
void PrintFVector(FVector *gluon);
///funkcja kasujaca czterowektor
void RemoveFVector(FVector *gluon);
///funkcja inicjalizujaca czterowektor(inicjalizuje cztery wspolrzedne oraz wywoluje funkcje do obliczania masy niezmienniczej)
FVector * InitFVector(double coord[]);


#endif
