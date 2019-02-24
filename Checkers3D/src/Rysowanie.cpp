#include "Rysowanie.h"
#include "PionekClass.cpp"

extern int glob_id_pionka;
extern Pionek tabPionkow[];
extern int zbitePionkiCzarne;
extern int zbitePionkiBiale;

void RysujPlanszeWarcab(GLuint tex[])
{
    /*Narysowanie ka¿dej œciany szeœcianu po kolei */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    glBegin(GL_QUADS);
    // Œciana górna
    glTexCoord2f(0, 0);
    glVertex3f(-40,  5, -40);
    glTexCoord2f(1, 0);
    glVertex3f( 40,  5, -40);
    glTexCoord2f(1, 1);
    glVertex3f( 40,  5,  40);
    glTexCoord2f(0, 1);
    glVertex3f(-40,  5,  40);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    glBegin(GL_QUADS);
    // Œciana dolna
    glTexCoord2f(0, 0);
    glVertex3f(-40, -5, -40);
    glTexCoord2f(1, 0);
    glVertex3f( 40, -5, -40);
    glTexCoord2f(1, 1);
    glVertex3f( 40, -5,  40);
    glTexCoord2f(0, 1);
    glVertex3f(-40, -5,  40);
    // Œciana bli¿sza
    glTexCoord2f(0, 0);
    glVertex3f(-40,  5,  40);
    glTexCoord2f(1, 0);
    glVertex3f( 40,  5,  40);
    glTexCoord2f(1, 1);
    glVertex3f( 40, -5,  40);
    glTexCoord2f(0, 1);
    glVertex3f(-40, -5,  40);
    // Œciana dalsza
    glTexCoord2f(0, 0);
    glVertex3f(-40,  5, -40);
    glTexCoord2f(1, 0);
    glVertex3f( 40,  5, -40);
    glTexCoord2f(1, 1);
    glVertex3f( 40, -5, -40);
    glTexCoord2f(0, 1);
    glVertex3f(-40, -5, -40);
    // Œciana lewa
    glTexCoord2f(0, 0);
    glVertex3f(-40,  5,  40);
    glTexCoord2f(1, 0);
    glVertex3f(-40,  5, -40);
    glTexCoord2f(1, 1);
    glVertex3f(-40, -5, -40);
    glTexCoord2f(0, 1);
    glVertex3f(-40, -5,  40);
    // Œciana prawa
    glTexCoord2f(0, 0);
    glVertex3f( 40,  5,  40);
    glTexCoord2f(1, 0);
    glVertex3f( 40,  5, -40);
    glTexCoord2f(1, 1);
    glVertex3f( 40, -5, -40);
    glTexCoord2f(0, 1);
    glVertex3f( 40, -5,  40);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void RysujPionka()
{
    int normals = GLU_SMOOTH;
    int style = GLU_NONE;
    int orientation = GLU_OUTSIDE;
    int segments = 10;
    GLfloat x,y,kat;
    const GLfloat GL_PI=3.1415f;

    GLUquadricObj * quadobj = gluNewQuadric();

    gluQuadricNormals( quadobj, normals ); // sposób generacji wektorów normalnych
    gluQuadricDrawStyle( quadobj, style ); // styl ((wygląd) generowanej kwadryki
    gluQuadricOrientation( quadobj, orientation ); // określenie orientacji wektorów normalnych kwadryki

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); //srodek kola
    for(kat = 0.0f; kat < (2.0f*GL_PI); kat += (GL_PI/32.0f))
    {
        x = 3.0f*sin(kat);
        y = 3.0f*cos(kat);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    gluCylinder( quadobj, 3, 3, 2, segments, segments );
    glColor3f( 1, 0.5, 0.01 );
    glutWireTorus( 0.2, 2.3, 10, 20 );
    glutWireTorus( 0.2, 1, 10, 20 );
}

void RysujBialePionki()
{
    for(int i = 0; i<12; i++)
    {
        if(tabPionkow[i].getId() > -1){
            if(glob_id_pionka == i)
                glColor3f( 1, 0.0, 1 );
            else
                glColor3f( 1, 0, 0.01 );
            glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glTranslatef(tabPionkow[i].getX(), tabPionkow[i].getY(), -7);
            RysujPionka();
            glPopMatrix();
        }
    }
}

void RysujCzarnePionki()
{
    for(int i = 11; i<24; i++)
    {
        if(tabPionkow[i].getId() > -1){
            if(glob_id_pionka == i)
                glColor3f( 1, 0.0, 1 );
            else
                glColor3f( 1, 1, 0.01 );
            glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glTranslatef(tabPionkow[i].getX(), tabPionkow[i].getY(), -7);
            RysujPionka();
            glPopMatrix();
        }
    }
}

void RysujZbiteCzarnePionki()
{
    int x, y;
    x = -68;
    y = 33;
    for(int i = 0; i<zbitePionkiCzarne; i++)
    {

        glColor3f(1, 0, 0.01 );
        glPushMatrix();
        glTranslatef(x, y, 0);
        RysujPionka();
        glPopMatrix();
        y -= 8;
    }
}

void RysujZbiteBialePionki()
{
    int x, y;
    x = 68;
    y = 33;
    for(int i = 0; i<zbitePionkiBiale; i++)
    {
        glColor3f(1, 1, 0.01 );
        glPushMatrix();
        glTranslatef(x, y, 0);
        RysujPionka();
        glPopMatrix();
        y -= 8;
    }
}
