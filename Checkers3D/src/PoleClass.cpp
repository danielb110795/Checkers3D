#include <stdio.h>
#include <iostream>

using namespace std;

class Pole
{
    int id;
    int idPionka;
    bool zajety;
    int kolor;
    int x;
    int y;
    int rzad;
    int kolumna;
public:
    Pole(int id, int idPionka, bool zajety, int kolor, int x, int y, int rzad, int kolumna)
    {
        this->id = id;
        this->idPionka = idPionka;
        this->zajety = zajety;
        this->kolor = kolor;
        this->x = x;
        this->y = y;
        this->rzad = rzad;
        this->kolumna = kolumna;

    }
    void setIdPionka(int idPionka)
    {
        this->idPionka = idPionka;
    }
    void setZajety(bool zajety)
    {
        this->zajety = zajety;
    }
    void setKolor(int kolor)
    {
        this->kolor = kolor;
    }
    int getId()
    {
        return id;
    }
    int getIdPionka()
    {
        return idPionka;
    }
    bool getZajety()
    {
        return zajety;
    }
    int getKolor()
    {
        return kolor;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
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
        cout<<"id= "<<id<<"id pionka: "<<idPionka<<"zajety: "<<zajety<<"kolor: "<<kolor<<"x: "<<x<<"y: "<<y<<endl;
    }
};
