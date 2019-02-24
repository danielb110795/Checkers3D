#define GLUT_DISABLE_ATEXIT_HACK
#include <stdio.h>
#include <iostream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <vector>
#include <string.h>

#include "Targa.h"
#include "Text.h"
#include "Rysowanie.h"
#include "Klikniecia.h"
#include "PionekClass.cpp"
#include "PoleClass.cpp"
#include "Logika.h"

using namespace std;

int ktoSieRusza = 0; //0 - czarny, 1 - bialy, zmienna do wyswietlania tekstu
int ruchMozliwy = 0;
int ruchNiemozliwy = 2;
int enter;
int button_state;
int button_x;
int button_y;
int szerokosc_okna;
int wysokosc_okna;
int glob_id_pionka = -1;
int ruch = 0;
int zmianaRuchu = -1;
int czekaj;
int tabBic[5];
bool bicie;
bool bicie2;
bool blokada = false;
bool spacja = false;
int zbitePionkiCzarne = 0;
int zbitePionkiBiale = 0;

GLfloat rotx = 30, roty = 30;  /* Dane globalne (animacja) */
GLuint tex[2];	/* Dwie tekstury */

//Parametry oświelenia
GLfloat lightAmb[] = {0.3, 0.3, 0.3, 1.0};
GLfloat lightDif[] = {0.7, 0.7, 0.7, 1.0};
GLfloat lightPos[] = {150, 200, 200, 1.0};
GLfloat lightSpec[] = {1, 1, 1, 1};

//czarne
Pionek pionek1(0,-25,35,0,0,0);
Pionek pionek2(1,-5,35,1,0,-1);
Pionek pionek3(2,15,35,2,0,-1);
Pionek pionek4(3,35,35,3,0,1);
Pionek pionek5(4,-35,25,4,1,0);
Pionek pionek6(5,-15,25,5,1,-1);
Pionek pionek7(6,5,25,6,1,-1);
Pionek pionek8(7,25,25,7,1,-1);
Pionek pionek9(8,-25,15,8,0,0);
Pionek pionek10(9,-5,15,9,0,-1);
Pionek pionek11(10,15,15,10,0,-1);
Pionek pionek12(11,35,15,11,0,1);
//biale
Pionek pionek13(12,25,-35,31,1,1);
Pionek pionek14(13,5,-35,30,1,-1);
Pionek pionek15(14,-15,-35,29,1,-1);
Pionek pionek16(15,-35,-35,28,1,0);
Pionek pionek17(16,35,-25,27,0,1);
Pionek pionek18(17,15,-25,26,0,-1);
Pionek pionek19(18,-5,-25,25,0,-1);
Pionek pionek20(19,-25,-25,24,0,0);
Pionek pionek21(20,25,-15,23,1,1);
Pionek pionek22(21,5,-15,22,1,-1);
Pionek pionek23(22,-15,-15,21,1,-1);
Pionek pionek24(23,-35,-15,20,1,0);

Pionek tabPionkow[24]= {pionek1, pionek2, pionek3, pionek4, pionek5, pionek6, pionek7, pionek8, pionek9,
                        pionek10, pionek11, pionek12, pionek13, pionek14, pionek15, pionek16, pionek17,
                        pionek18, pionek19, pionek20, pionek21, pionek22, pionek23, pionek24
};

Pole pole1(0,0,true,0,-25,35,0,0);
Pole pole2(1,1,true,0,-5,35,0,-1);
Pole pole3(2,2,true,0,15,35,0,-1);
Pole pole4(3,3,true,0,35,35,0,1);
Pole pole5(4,4,true,0,-35,25,1,0);
Pole pole6(5,5,true,0,-15,25,1,-1);
Pole pole7(6,6,true,0,5,25,1,-1);
Pole pole8(7,7,true,0,25,25,1,1);
Pole pole9(8,8,true,0,-25,15,0,0);
Pole pole10(9,9,true,0,-5,15,0,-1);
Pole pole11(10,10,true,0,15,15,0,-1);
Pole pole12(11,11,true,0,35,15,0,1);
Pole pole13(12,-1,false,-1,-35,5,1,0);
Pole pole14(13,-1,false,-1,-15,5,1,-1);
Pole pole15(14,-1,false,-1,5,5,1,-1);
Pole pole16(15,-1,false,-1,25,5,1,1);
Pole pole17(16,-1,false,-1,-25,-5,0,0);
Pole pole18(17,-1,false,-1,-5,-5,0,-1);
Pole pole19(18,-1,false,-1,15,-5,0,-1);
Pole pole20(19,-1,false,-1,35,-5,0,1);
Pole pole21(20,23,true,1,-35,-15,1,0);
Pole pole22(21,22,true,1,-15,-15,1,-1);
Pole pole23(22,21,true,1,5,-15,1,-1);
Pole pole24(23,20,true,1,25,-15,1,1);
Pole pole25(24,19,true,1,-25,-25,0,0);
Pole pole26(25,18,true,1,-5,-25,0,-1);
Pole pole27(26,17,true,1,15,-25,0,-1);
Pole pole28(27,16,true,1,35,-25,0,1);
Pole pole29(28,15,true,1,-35,-35,1,0);
Pole pole30(29,14,true,1,-15,-35,1,-1);
Pole pole31(30,13,true,1,5,-35,1,-1);
Pole pole32(31,12,true,1,25,-35,1,1);

Pole tabPol[32]= {pole1, pole2, pole3, pole4, pole5, pole6, pole7, pole8, pole9, pole10, pole11,
                  pole12, pole13, pole14, pole15, pole16, pole17, pole18, pole19, pole20, pole21,
                  pole22, pole23, pole24, pole25, pole26, pole27, pole28, pole29, pole30, pole31, pole32
};


/* Funkcja ustawia parametry renderowania i oświetlenie */
void inicializacja(void)
{
    glEnable(GL_DEPTH_TEST);    /* W³¹czenie Z-Bufora */
    glEnable(GL_LIGHTING); /* W³¹czenie oœwietlenia */
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb); /* Natê¿enie œwiat³a otoczenia (AMBIENT) */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif); /* Natê¿enie œwiat³a rozpraszaj¹cego (DIFFUSE) */
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos); /* Œwiat³o nr 0 umieszczone nad scen¹ z prawej strony */
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec); /* Natê¿enie odb³ysków */
    glEnable(GL_LIGHT0); /* W³¹czenie œwiat³a nr 0 */
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpec); /* Ustawienie odb³ysku materia³ów */
    glMateriali(GL_FRONT, GL_SHININESS, 64); /* Skupienie i jasnoœæ plamy œwiat³a */
    glEnable(GL_COLOR_MATERIAL); /* Œledzenie kolorów */ /* Wspó³czynniki odbicia œwiat³a s¹ takie same jak kolor */
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glGenTextures(2, tex); /* Wygenerowanie trzech tzw. "tabPol[nr]ów" dla tekstur */
    glBindTexture(GL_TEXTURE_2D, tex[0]);     /* Aktywacja ka¿dej tekstury po kolei i ³adowanie z plików TGA */
    LoadTGAMipmap((char*) "tex0.tga");
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    LoadTGAMipmap((char*) "tex1.tga");

    glClearColor(0.184, 0.310, 0.310, 1.0); 	/* Kolor t³a */
}

void GlownaFunkcjaRysujaca(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* Wyczyszczenie t³a kolorem t³a */
    glLoadIdentity(); /* Wstêpne ustawienie sceny */
    glTranslatef(0, 0, -207); /* Odsuniêcie œrodka sceny od obserwatora */

    displayText(-72, 40, 1, 0, 0, "Zbite czarne:");
    displayText(50, 40, 1, 0, 0, "Zbite biale:");

    RysujZbiteCzarnePionki();
    RysujZbiteBialePionki();

    if (zbitePionkiBiale == 12) {
        displayText(-25, 67, 1, 0, 0, "Wygral gracz czarny!");
    }

    if (zbitePionkiCzarne == 12) {
        displayText(-25, 67, 1, 0, 0, "Wygral gracz bialy!");
    }

    if (ktoSieRusza == 0 && zbitePionkiCzarne != 12 && zbitePionkiBiale != 12)
    {
        displayText(-25, 67, 1, 0, 0, "Ruch gracza czarnego!");
    }

    if (ktoSieRusza == 1 && zbitePionkiCzarne != 12 && zbitePionkiBiale != 12)
    {
        displayText(-25, 67, 1, 0, 0, "Ruch gracza bialego!");
    }

    if ((bicie == true || bicie2 == true) && ruchMozliwy == 1)
    {
        displayText(-30, 55, 1, 0, 0, "Musisz zbic pionek przeciwnika!");
    }

    if (ruchMozliwy == 1 && zbitePionkiCzarne != 12 && zbitePionkiBiale != 12 && bicie2 == false && bicie == false)
    {
        displayText(-30, 55, 1, 0, 0, "Teraz mozesz wykonac ruch!");
    }

    if ((ruchNiemozliwy == 1 || ruchNiemozliwy == 2) && zbitePionkiCzarne != 12 && zbitePionkiBiale != 12)
    {
        displayText(-45, 55, 1, 0, 0, "Nie mozesz wykonac ruchu, nascisnij spacje!");
    }

    if (ruchMozliwy == 0 && ruchNiemozliwy == 0 && zbitePionkiCzarne != 12 && zbitePionkiBiale != 12)
    {
        displayText(-45, 55, 1, 0, 0, "Nacisnij PPM aby oddac ruch przeciwnikowi!");
    }

    if(zmianaRuchu != -1 && enter == 1)
    {
        zmienRuch();
    }

    glRotatef(rotx, 1, 0, 0);
    glRotatef(roty, 0, 1, 0);
    glColor4f( 1, 1, 1, 0);

    RysujPlanszeWarcab (tex);
    RysujBialePionki();
    RysujCzarnePionki();

    glutSwapBuffers(); /* Zmiana bufora i opró¿nienie kolejki renderowania */
}

void MouseButton( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON )
    {
        // zapamiętanie stanu lewego przycisku myszki
        button_state = state;

        // zapamiętanie położenia kursora myszki
        if( state == GLUT_DOWN )
        {
            button_x = x-((szerokosc_okna-600)/2)+((wysokosc_okna-600)/5);
            button_y = y-((wysokosc_okna-600)/2)-((wysokosc_okna-600)/9);
            cout<<"x: "<<button_x<<endl;
            cout<<"y: "<<button_y<<endl;
            if(spacja == true)
            {
                if(ruch == 0 && blokada == false)
                    sprawdzenieKlikniecia();
                if(ruch == 1 && blokada == false)
                    sprawdzenieKlikniecia2();
            }
        }
    }
    glutPostRedisplay();

    if( button == GLUT_RIGHT_BUTTON && zmianaRuchu != -1)
    {
        enter = 1;
        glutPostRedisplay();
    }
}

void ZmianaRozmiaruOkna(int w, int h)
{
    if(h==0)	/* Zabezpieczenie przed dzieleniem przez zero */
        h=1;
    glViewport(0, 0, w, h); /* Ustawienie widoku */
    glMatrixMode(GL_PROJECTION); /* Ustawienie obszaru obcinania z uwzglêdnieniem proporcji okna */
    glLoadIdentity();
    gluPerspective(40, (float)w/h, 150, 450); /* Rzutowanie perspektywiczne */
    glMatrixMode(GL_MODELVIEW); /* Wyzerowanie macierzy widoku modelu dla funkcji rysuj¹cej */
    glLoadIdentity();
    szerokosc_okna = w;
    wysokosc_okna = h;
}

void ObracaniePlansza (int key, int x, int y)
{
    if(enter == 0)
    {
        if(blokada == false)
        {
            if(key == GLUT_KEY_DOWN)
            {
                ruchMozliwy = 0;
                rotx += 1;
                spacja = false;
            }
            if(key == GLUT_KEY_UP)
            {
                ruchMozliwy = 0;
                rotx -= 1;
                spacja = false;
            }
            if(key == GLUT_KEY_RIGHT)
            {
                ruchMozliwy = 0;
                roty += 1;
                spacja = false;
            }
            if(key == GLUT_KEY_LEFT)
            {
                ruchMozliwy = 0;
                roty -= 1;
                spacja = false;
            }
            ruchNiemozliwy = 1;
            glutPostRedisplay();
        }
    }
}

void ObslugaESC(unsigned char key, int x, int y)
{
    if(key == 0x1B)
        exit(0);

    if(key == 0x20 && ruch == 0 && zmianaRuchu == -1)
    {
        rotx=30;
        roty=0;
        spacja = true;
        ruchMozliwy = 1;
        ruchNiemozliwy = 0;
        glutPostRedisplay();
    }

    if(key == 0x20 && ruch == 1 && zmianaRuchu == -1)
    {
        rotx=30;
        roty=180;
        spacja = true;
        ruchMozliwy = 1;
        ruchNiemozliwy = 0;
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Warcaby");
    glutMouseFunc(MouseButton);
    glutDisplayFunc(GlownaFunkcjaRysujaca); 	/* Ustawienie funkcji rysuj¹cej zawartoœæ okna */
    glutReshapeFunc(ZmianaRozmiaruOkna); /* Funkcja ustawiaj¹ca parametry po zmianie rozmiaru okna */
    glutKeyboardFunc(ObslugaESC);
    glutSpecialFunc(ObracaniePlansza);
    inicializacja(); /* Ustawienia OpenGL */
    glutMainLoop(); /* Wejœcie do g³ównej pêtli programu */
    return(0);
}
