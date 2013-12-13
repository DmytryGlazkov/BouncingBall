#pragma once

#include "libs/OpenGL/glut.h"
#include "libs/FreeImage/FreeImage.h"
#include <iostream>

#pragma comment(lib, "./libs/FreeImage/FreeImage.lib")

using namespace std;

class Texture
{
public:
	FREE_IMAGE_FORMAT format;
	FIBITMAP * img;
	GLubyte* texture;
	char* pixels;
	GLuint texID;
	int w,h;

	Texture(char* cr){
		FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(cr,0);
		FIBITMAP* imagen = FreeImage_Load(formato, cr);

		FIBITMAP* temp = imagen;
		imagen = FreeImage_ConvertTo32Bits(imagen);
		FreeImage_Unload(temp);

		int w = FreeImage_GetWidth(imagen);
		int h = FreeImage_GetHeight(imagen);
		cout<<"The size of the image is: "<<cr<<" es "<<w<<"*"<<h<<endl; //Some debugging code

		texture = new GLubyte[4*w*h];
		char* pixeles = (char*)FreeImage_GetBits(imagen);
		//FreeImage loads in BGR format, so you need to swap some bytes(Or use GL_BGR).

		for(int j= 0; j<w*h; j++){
			texture[j*4+0]= pixeles[j*4+2];
			texture[j*4+1]= pixeles[j*4+1];
			texture[j*4+2]= pixeles[j*4+0];
			texture[j*4+3]= pixeles[j*4+3];
			//cout<<j<<": "<<textura[j*4+0]<<"**"<<textura[j*4+1]<<"**"<<textura[j*4+2]<<"**"<<textura[j*4+3]<<endl;
		}

	}

	void gen()
	{
		glEnable(GL_TEXTURE_2D);
		glGenTextures(1, &texID);
		GLenum huboError = glGetError();
			cout<<"There was an error loading the texture " << huboError<<endl;
		glBindTexture(GL_TEXTURE_2D, texID);
		huboError = glGetError();
			cout<<"There was an error loading the texture " << huboError<<endl;
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, w, h, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)texture);
		huboError = glGetError();
			cout<<"There was an error loading the texture " << huboError<<endl;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		huboError = glGetError();
			cout<<"There was an error loading the texture " << huboError<<endl;
	}
private:
	Texture(){};
};