#ifndef APVIEWMATRIX_H
#define APVIEWMATRIX_H

#include "apMatrix4.h"
#include <cmath>
#define Deg2Rad (0.0174533)

class apViewMatrix {

  public:
  apMatrix4* TheLook;

  //CONTSRUCTOR
  apViewMatrix () { TheLook=new apMatrix4(); };
  //DESTRUCTOR
  ~apViewMatrix () { delete TheLook; TheLook=NULL;};


  //METHODS
  void apLookAt(float xE, float yE, float zE, float xA, float yA, float zA, float xU, float yU, float zU){ float ey[]={xE,yE,zE}; float a[]={xA,yA,zA}; float u[]={xU,yU,zU};   apLookAt(ey,a,u);};
  
  void apLookAt(float *eye, float *at, float *up){
    Vector* E = new Vector(3,eye);
    Vector* A = new Vector(3,at);
    Vector* U = new Vector(3,up);

	Vector* Zi = (*A)-E; Vector* Z = Zi->Normalize(); delete Zi;
	Vector* Xi = Z->Cross(U); Vector* X = Xi->Normalize(); delete Xi;
	Vector* Y = X->Cross(Z); Vector *Eye = (*E)*(-1); delete E; delete A; delete U;
	Vector* Z1 = (*Z)*(-1); delete Z;

	apMatrix4 *One = new apMatrix4(X,Y,Z1); delete X; delete Y; delete Z1;
	apMatrix4 *Two = new apMatrix4(Eye, 0); delete Eye;
	apMatrix4 *Three = (*One)*Two; delete One; delete Two;
	apMatrix4 *Four = (*TheLook)*Three; delete TheLook; delete Three;
	TheLook=Four;
	};
/*
  void apPerspective(float fovy, float aR, float zN, float zF){
	float f = 1/tan(fovy/2); float* nv = new float[16];
	nv[0]=-f/aR;	nv[1]=0;	nv[2]=0;	nv[3]=0;
	nv[4]=0;	nv[5]=-f;	nv[6]=0;	nv[7]=0;
	nv[8]=0;	nv[9]=0;	nv[10]=(zN+zF)/(zN-zF);	nv[11]=(2*zN*zF)/(zN-zF);
	nv[12]=0;	nv[13]=0;	nv[14]=-1;	nv[15]=0;
	
	apMatrix4 *One = new apMatrix4(nv);  delete[] nv;
	apMatrix4 *Two = (*TheLook)*One; delete One; delete TheLook;
	TheLook=Two;
	
	};*/
  void apPerspective(float fov, float aspect, float znear, float zfar){
	
    float ymax = znear * tan(fov * Deg2Rad);
    float ymin = -ymax;
    float xmax = ymax * aspect;
    float xmin = ymin * aspect;

  
	float* m = new float[16];
	m[0]=2*znear/(xmax-xmin); m[1]=0; m[2]=(xmax+xmin)/(xmin-xmax); m[3]=0;
	m[4]=0;m[5]=2*znear/(ymax-ymin);m[6]=(ymax+ymin)/(ymin-ymax);m[7]=0;
	m[8]=0;m[9]=0;m[10]=(zfar+znear)/(znear-zfar);m[11]=(2*zfar*znear)/(zfar-znear);
	m[12]=0;m[13]=0;m[14]=1;m[15]=0;
  
	apMatrix4 *One = new apMatrix4(m);  delete[] m;
	apMatrix4 *Two = (*TheLook)*One; delete One; delete TheLook;
	TheLook=Two;
	
	};

  void apViewport(float x, float y, float w, float h){
        float* nv = new float[16];
	nv[0]=w/2;	nv[1]=0;	nv[2]=0;	nv[3]=(w-2)/2;
	nv[4]=0;	nv[5]=-h/2;	nv[6]=0;	nv[7]=(h-2)/2;
	nv[8]=0;	nv[9]=0;	nv[10]=1;	nv[11]=0;
	nv[12]=0;	nv[13]=0;	nv[14]=0;	nv[15]=1;
	
	apMatrix4 *One = new apMatrix4(nv);  delete[] nv;
	apMatrix4 *Two = (*TheLook)*One; delete One; delete TheLook;
	TheLook=Two;
        };

  void Print(void){cout << "The current Looking Matrix:\n";TheLook->Print();};
};

#endif
