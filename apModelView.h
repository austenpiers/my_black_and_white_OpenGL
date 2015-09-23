#ifndef APMODELVIEW_H
#define APMODELVIEW_H

#include "apMatrix4.h"
#include <cmath>
#include <stack>
#define Deg2Rad (0.0174533)

class apModelView {

  public:
  stack <apMatrix4*> apMatrixStack;
  apMatrix4* current;
  
  //CONTSRUCTOR
  apModelView () { current=new apMatrix4(); apMatrix4* tmp = new apMatrix4(); apMatrixStack.push(tmp); tmp=NULL;};
  //DESTRUCTOR
  ~apModelView () {apLoadIdentity();  apMatrixStack.pop(); delete current;};


  //METHODS
  void apPushMatrix() {apMatrix4* tmp = new apMatrix4(current->v); apMatrixStack.push(tmp); };
  
  void apPopMatrix()	{ 
     delete current; current = new apMatrix4(apMatrixStack.top()->v);
    apMatrixStack.pop();
	   if(apMatrixStack.size()<1)
        {  apMatrix4* tmp = new apMatrix4(); apMatrixStack.push(tmp); }
   };

  void apLoadIdentity(){ while(apMatrixStack.size()>1) apPopMatrix(); };  

  //------Drawing Operations-----
  //ROTATE
  void apRotate(float degree, float x, float y, float z) {
	float* nv=new float[16]; float c = cos(degree*Deg2Rad), s = sin(degree*Deg2Rad);
	nv[0]=x*x*(1-c)+c;	nv[1]=x*y*(1-c)-z*s;	nv[2]=x*z*(1-c)+y*s;	nv[3]=0;
	nv[4]=y*x*(1-c)+z*s;	nv[5]=y*y*(1-c)+c;	nv[6]=y*z*(1-c)-x*s;	nv[7]=0;
	nv[8]=x*z*(1-c)-y*s;	nv[9]=y*z*(1-c)+x*s;	nv[10]=z*z*(1-c)+c;	nv[11]=0;
	nv[12]=0;	nv[13]=0;	nv[14]=0;	nv[15]=1;
	apMatrix4 *r=new apMatrix4(nv); delete[] nv;
	apMatrix4 *n=(*current)*r; delete r; delete current;
	current = n;	};

  //SCALE
  void apScale(float x, float y, float z) {\
  //if(x<0||y<0||z<0) cout<< "vals:" <<x<<' '<<y<<' '<<z<<endl;
	float* nv = new float[3]; nv[0]=x; nv[1]=y; nv[2]=z;
	Vector* Vtmp = new Vector(3,nv);  delete[] nv;
	apMatrix4 *r = new apMatrix4(Vtmp); delete Vtmp;
	apMatrix4 *n = (*current)*r; delete r; delete current; 
	current = n;	};

  //TRANSLATE
  void apTranslate(float x, float y, float z) {
        float* nv = new float[3]; nv[0]=x; nv[1]=y; nv[2]=z;
        Vector* Vtmp = new Vector(3,nv); delete[] nv;
        apMatrix4 *r = new apMatrix4(Vtmp,0); delete Vtmp; 
        apMatrix4 *n = (*current)*r; delete r; delete current; 
        current = n;	};

  void Print(){
    cout << "TOP OF STACK:\n";
    apMatrixStack.top()->Print();
    cout << "CURRENT:\n";
    current->Print();
  };
};

#endif

