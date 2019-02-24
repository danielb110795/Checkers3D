#define GLUT_DISABLE_ATEXIT_HACK

#include <stdio.h>
#include <iostream>
#include "PionekClass.cpp"
#include "PoleClass.cpp"
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
using namespace std;

extern Pionek tabPionkow[];
extern bool bicie;
extern bool bicie2;
extern int tabBic[];
int tabZbitych[5];
int tabBijacego[5];
extern Pole tabPol[];
extern int glob_id_pionka;
extern int ruch;
extern int zmianaRuchu;
extern int czekaj;
extern bool blokada;
extern int enter;
extern GLfloat roty;
extern int ruchMozliwy;
extern int ktoSieRusza;
extern int zbitePionkiBiale;
extern int zbitePionkiCzarne;

void sprawdzBicie()
{

    int id_pola_pionka;
    bicie = false;
    bicie2 = false;
    int ilosc_bic = -1;
    int pocz, kon;
    for(int j = 0; j<5; j++)
    {
        tabBic[j] = 0;
        tabZbitych[j] = 0;
        tabBijacego[j] = 0;
    }
    if(ruch == 0)
    {
        pocz = 0;
        kon = 12;
        cout<<"Sprawdzam bicie... dla czarnych ....."<<endl;
    }
    else
    {
        pocz = 12;
        kon = 24;
        cout<<"Sprawdzam bicie... dla bialych ....."<<endl;
    }
    for(int i = pocz; i<kon; i++)
    {
        if(tabPionkow[i].getId() > -1){
            id_pola_pionka = tabPionkow[i].getIdPola();
            if(tabPionkow[i].getRzad() == 0)
            {
                if(tabPionkow[i].getKolumna() == 1)
                {
                    if(tabPol[id_pola_pionka+4].getZajety() == true && (id_pola_pionka+7) < 32)
                    {
                        if(tabPol[id_pola_pionka+4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-4].getZajety() == true && (id_pola_pionka-9) > -1)
                    {
                        if(tabPol[id_pola_pionka-4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
                if(tabPionkow[i].getKolumna() == -1)
                {
                    if(tabPol[id_pola_pionka+4].getZajety() == true && (id_pola_pionka+7) < 32)
                    {
                        if(tabPol[id_pola_pionka+4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka+5].getZajety() == true && (id_pola_pionka+9) < 32)
                    {
                        if(tabPol[id_pola_pionka+5].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+5].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-3].getZajety() == true && (id_pola_pionka-7) > -1)
                    {
                        if(tabPol[id_pola_pionka-3].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-3].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-4].getZajety() == true && (id_pola_pionka-9) > -1)
                    {
                        if(tabPol[id_pola_pionka-4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
                if(tabPionkow[i].getKolumna() == 0)
                {
                    if(tabPol[id_pola_pionka+5].getZajety() == true && (id_pola_pionka+9) < 32)
                    {
                        if(tabPol[id_pola_pionka+5].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+5].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }

                    if(tabPol[id_pola_pionka-3].getZajety() == true && (id_pola_pionka-7) > -1)
                    {
                        if(tabPol[id_pola_pionka-3].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-3].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
            }
            if(tabPionkow[i].getRzad() == 1)
            {
                if(tabPionkow[i].getKolumna() == 1)
                {
                    if(tabPol[id_pola_pionka+3].getZajety() == true && (id_pola_pionka+7) < 32)
                    {
                        if(tabPol[id_pola_pionka+3].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+3].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-5].getZajety() == true && (id_pola_pionka-9) > -1)
                    {
                        if(tabPol[id_pola_pionka-5].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-5].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
                if(tabPionkow[i].getKolumna() == -1)
                {
                    if(tabPol[id_pola_pionka+3].getZajety() == true && (id_pola_pionka+7) < 32)
                    {
                        if(tabPol[id_pola_pionka+3].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+3].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka+4].getZajety() == true && (id_pola_pionka+9) < 32)
                    {
                        if(tabPol[id_pola_pionka+4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-4].getZajety() == true && (id_pola_pionka-7) > -1)
                    {
                        if(tabPol[id_pola_pionka-4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-5].getZajety() == true && (id_pola_pionka-9) > -1)
                    {
                        if(tabPol[id_pola_pionka-5].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-5].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
                if(tabPionkow[i].getKolumna() == 0)
                {
                    if(tabPol[id_pola_pionka+4].getZajety() == true && (id_pola_pionka+9) < 32)
                    {
                        if(tabPol[id_pola_pionka+4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka+9].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka+9].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka+4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                    if(tabPol[id_pola_pionka-4].getZajety() == true && (id_pola_pionka-7) > -1)
                    {
                        if(tabPol[id_pola_pionka-4].getKolor() != tabPol[id_pola_pionka].getKolor())
                        {
                            if(tabPol[id_pola_pionka-7].getZajety() == false)
                            {
                                if(ruch == 0)
                                    bicie = true;
                                else
                                    bicie2 = true;
                                ilosc_bic += 1;
                                tabBic[ilosc_bic] = tabPol[id_pola_pionka-7].getId();
                                tabZbitych[ilosc_bic] = tabPol[id_pola_pionka-4].getIdPionka();
                                tabBijacego[ilosc_bic] = i;
                                cout<<"TAB BIC: "<<ilosc_bic<<"  ID W TABLICY:  "<<tabBic[ilosc_bic]<<endl;
                                cout<<"ZBITY PIONEK: "<<tabZbitych[ilosc_bic]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void wykonajRuch(int nr)
{
    int id_pola;
    int id_pola_pionka;
    int tmp_x;
    int tmp_y;
    if(tabPol[nr].getZajety()==true)
    {

        if(tabPol[nr].getKolor()==ruch)
        {

            glob_id_pionka=tabPol[nr].getIdPionka();
            tabPol[nr].wypisz();
        }
    }
    if(tabPol[nr].getZajety()==false)
    {

        tabPol[nr].wypisz();
        if(glob_id_pionka>-1)
        {
            id_pola=tabPol[nr].getId();
            id_pola_pionka = tabPionkow[glob_id_pionka].getIdPola();

            if(tabPionkow[glob_id_pionka].getRzad() == 1)
            {
                if(id_pola-4==id_pola_pionka || id_pola-3==id_pola_pionka)
                {

                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();

                    if(ruch == 0)
                    {
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                    else
                    {
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                }
            }
            else
            {
                if((id_pola-4==id_pola_pionka) || (id_pola-5==id_pola_pionka))
                {
                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();
                    if(ruch == 0)
                    {
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                    else
                    {
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                }
            }
        }
    }
    glutPostRedisplay();
}

void wykonajRuch2(int nr)
{
    int id_pola;
    int id_pola_pionka;
    int tmp_x;
    int tmp_y;
    if(tabPol[nr].getZajety()==true)
    {

        if(tabPol[nr].getKolor()==ruch)
        {

            glob_id_pionka=tabPol[nr].getIdPionka();
            tabPol[nr].wypisz();
        }
    }
    if(tabPol[nr].getZajety()==false)
    {

        tabPol[nr].wypisz();
        if(glob_id_pionka>-1)
        {
            id_pola=tabPol[nr].getId();
            id_pola_pionka = tabPionkow[glob_id_pionka].getIdPola();

            if(tabPionkow[glob_id_pionka].getRzad() == 1)
            {
                if(id_pola+4==id_pola_pionka || id_pola+5==id_pola_pionka)
                {

                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();
                    if(ruch == 0)
                    {
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;

                    }
                    else
                    {
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                }
            }
            else
            {
                if((id_pola+3==id_pola_pionka) || (id_pola+4==id_pola_pionka))
                {

                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();
                    if(ruch == 0)
                    {
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                    else
                    {
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                    }
                }
            }
        }
    }
}
void sprawdzPole(int nr)
{
    if(bicie == true)
    {
        if(tabPol[nr].getZajety()==true)
        {

            if(tabPol[nr].getKolor()==ruch)
            {

                glob_id_pionka=tabPol[nr].getIdPionka();
                tabPol[nr].wypisz();
            }
        }
        if(tabPol[nr].getZajety()==false  && glob_id_pionka > -1)
        {
            int id_pola;
            int id_pola_pionka;
            int tmp_x;
            int tmp_y;
            id_pola = tabPol[nr].getId();
            cout<<"PUSTE POLE"<<endl;
            for(int i = 0; i<5; i++)
            {
                cout<<"WESZLO W PETLE"<<endl;
                cout<<id_pola<<" == "<<tabBic[i]<<endl;
                cout<<glob_id_pionka<<" === "<<tabBijacego[i]<<endl;
                if(id_pola == tabBic[i] && glob_id_pionka == tabBijacego[i])
                {
                    cout<<"JEST W TAB BIC"<<endl;

                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();

                    tabPionkow[tabZbitych[i]].setId(-1);

                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setKolor(-1);
                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setZajety(false);

                    if(ruch == 0)
                    {
                        sprawdzBicie();
                        if(bicie == true){
                            zbitePionkiBiale++;
                            break;
                        }
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                        zbitePionkiBiale++;
                    }
                    else
                    {
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        ruchMozliwy = 0;
                    }
                }
            }
        }
    }

    else
    {
        wykonajRuch(nr);
    }
}





void sprawdzPole2(int nr)
{
    if(bicie2 == true)
    {
        if(tabPol[nr].getZajety()==true)
        {

            if(tabPol[nr].getKolor()==ruch)
            {

                glob_id_pionka=tabPol[nr].getIdPionka();
                tabPol[nr].wypisz();
            }
        }
        if(tabPol[nr].getZajety()==false  && glob_id_pionka > -1)
        {
            int id_pola;
            int id_pola_pionka;
            int tmp_x;
            int tmp_y;
            id_pola = tabPol[nr].getId();
            cout<<"PUSTE POLE"<<endl;
            for(int i = 0; i<5; i++)
            {
                cout<<"WESZLO W PETLE"<<endl;
                cout<<id_pola<<" == "<<tabBic[i]<<endl;
                cout<<glob_id_pionka<<" === "<<tabBijacego[i]<<endl;
                if(id_pola == tabBic[i] && glob_id_pionka == tabBijacego[i])
                {
                    cout<<"JEST W TAB BIC"<<endl;

                    tmp_x=tabPol[nr].getX();
                    tmp_y=tabPol[nr].getY();
                    tabPionkow[glob_id_pionka].setXY(tmp_x,tmp_y);

                    tabPol[nr].setIdPionka(tabPionkow[glob_id_pionka].getId());
                    tabPol[nr].setZajety(true);
                    tabPol[nr].setKolor(ruch);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setZajety(false);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[glob_id_pionka].getIdPola()].setKolor(-1);
                    tabPionkow[glob_id_pionka].setIdPola(tabPol[id_pola].getId());
                    tabPionkow[glob_id_pionka].setRzadKolumna(tabPol[id_pola].getRzad(),tabPol[id_pola].getKolumna());
                    tabPionkow[glob_id_pionka].wypisz();
                    glob_id_pionka = -1;
                    tabPol[nr].wypisz();

                    tabPionkow[tabZbitych[i]].setId(-1);

                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setIdPionka(-1);
                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setKolor(-1);
                    tabPol[tabPionkow[tabZbitych[i]].getIdPola()].setZajety(false);

                    if(ruch == 0)
                    {
                        sprawdzBicie();
                        if(bicie2 == true){
                            zbitePionkiCzarne++;
                            break;
                        }
                        ruch = 1;
                        zmianaRuchu = 1;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                        zbitePionkiCzarne++;
                    }
                    else
                    {
                        sprawdzBicie();
                        if(bicie2 == true){
                            zbitePionkiCzarne++;
                            break;
                        }
                        ruch = 0;
                        zmianaRuchu = 0;
                        czekaj = 1;
                        blokada = true;
                        sprawdzBicie();
                        ruchMozliwy = 0;
                        zbitePionkiCzarne++;
                    }
                }
            }
        }
    }

    else
    {
        wykonajRuch2(nr);
    }
    glutPostRedisplay();
}



void zmienRuch()
{
    if(zmianaRuchu == 1)
        roty += 2;

    if(zmianaRuchu == 0)
        roty -= 2;

    if(roty == 180 && zmianaRuchu == 1)
    {
        zmianaRuchu = -1;
        blokada = false;
        enter = 0;
        ruchMozliwy = 1;
        ktoSieRusza = 1;
    }
    if(roty == 0 && zmianaRuchu == 0)
    {
        zmianaRuchu = -1;
        blokada = false;
        enter = 0;
        ruchMozliwy = 1;
        ktoSieRusza = 0;
    }
    glutPostRedisplay();
}
