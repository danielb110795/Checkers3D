#include <stdio.h>
#include <iostream>

using namespace std;

class Pionek
{
    int id;
    int x;
    int y;
    int idPola;
    int rzad;
    int kolumna;
public:
    Pionek(int id, int x, int y,int idPola,int rzad,int kolumna)
    {
        this->id = id;
        this->x = x;
        this->y = y;
        this->idPola = idPola;
        this->rzad = rzad;
        this->kolumna = kolumna;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setXY(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setIdPola(int idPola)
    {
        this->idPola = idPola;
    }
    void setRzadKolumna(int rzad, int kolumna)
    {
        this->rzad = rzad;
        this->kolumna = kolumna;
    }
    int getId()
    {
        return id;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getIdPola()
    {
        return idPola;
    }
    int getRzad()
    {
        return rzad;
    }
    int getKolumna()
    {
        return kolumna;
    }
    void wypisz()
    {
        cout<<"id= "<<id<<"x: "<<x<<"y: "<<y<<"id pola: "<<idPola<<"rzad:  "<<rzad<<"kolumna:  "<<kolumna<<endl;
    }
};
