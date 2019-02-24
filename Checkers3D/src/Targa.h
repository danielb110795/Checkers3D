#ifndef TARGA_H_INCLUDED
#define TARGA_H_INCLUDED

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glu.h>

typedef struct {
	GLuint bpp;		// iloœæ bitów na piksel
	GLuint width;	// rozmiary w pikselach
	GLuint height;
} TARGAINFO;


GLubyte *LoadTGAImage(char *filename, TARGAINFO *info);

bool LoadTGAMipmap(char *filename);

#endif
