#include "Text.h"

void displayText(float x, float y, float r, float g, float b, const char *string ) {
	int j = strlen( string );
    glDisable(GL_LIGHTING);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for(int i=0; i<j; i++)
    {
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, string[i]);
		//GLUT_BITMAP_TIMES_ROMAN_24
	}
	glEnable(GL_LIGHTING);
}
