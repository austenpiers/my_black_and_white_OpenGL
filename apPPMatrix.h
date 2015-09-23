#ifndef APPPMATRIX_H
#define APPPMATRIX_H

#include "Matrix.h"
#include <stdlib.h>
#include <fstream>

class apPPMatrix{

  public:
  Matrix *CM;  Matrix *DM; bool invert;
  //********CONTSRUCTORS************
  apPPMatrix(float h, float w) {invert=true;float m=255; 
    CM = new Matrix(w,h,(float)255); DM = new Matrix(w,h,(m*3));};
  //********DESTRUCTOR************
  ~apPPMatrix(){delete CM; delete DM;};

  void apInvert(void){invert=(!invert);}


  //********DRAWING**********
  void apDrawLine(Matrix *P1, Matrix *P2,int color){

	//record the line vector
    float val[]={-1,-1,1,0};
    Matrix *L = (*P1)-P2;
    for(int jk=0;jk<4;jk++){
      if(L->v[jk]<0) {val[jk]*=-1; L->v[jk]*=-1;}  }

    //find unit distance vector
    Matrix *uL = L->Normalize();      //uL->Print();
    Matrix *Ud = new Matrix(4,1,val); //Ud->Print();

    //init. error vars and find the direction
    float r[]={0,0}; int wd=0;
    if(L->v[0]<L->v[1]) {wd=1;}//cout<<" in Y\n(Dx=";}
	//else cout<<" in X\n(Dy=";

    //cout<<r[0]<<","<<r[1]<<")\n";

    //use direction to manipulate change
    Matrix *UL = (*uL)/(uL->v[wd]); delete uL; //UL->Print();
    float ended = L->v[wd]; //if(!thickness) {++ended;}
    int d=1-wd;

    //Hold the start-points of the line-segment, then error
    float x[] = {P1->v[0], P1->v[1], P1->v[2]};
    float er[2]; er[0]=UL->v[d]; er[1]=UL->v[2];
    delete UL; 	delete L;
    float collar=255; if(color!=0) collar=0; 

    //cout<<er[0]<<","<<er[1]<<")\n";
	int WAAAPPP=1;
    for(int i=0; i<ended; i++,r[0]=r[0]+er[0],r[1]=r[1]+er[1],x[wd]=x[wd]+Ud->v[wd])
    {
	WAAAPPP=1;

      while(r[1]>=0.5) { x[2] += Ud->v[2]; r[1]-=1;}

	//cout<<' ';
      if(x[2]>((DM->v[(int)x[0]+(int)(CM->w)*(int)x[1]]))) WAAAPPP=0;
      if(x[0]<0 || x[0]>(CM->w) || x[1]<0 || x[1]>(CM->h)) WAAAPPP=0;
	
      if(WAAAPPP==1){
      	CM->v[(int)x[0]+(int)(CM->w)*(int)x[1]] = collar;
	//if(wd) {CM->v[(int)x[0]+(int)(CM->w)*(int)x[1]+1] = collar;DM->v[(int)x[0]+(int)(CM->w)*(int)x[1]+1] = x[2];}
        //else {CM->v[(int)x[0]+(int)(CM->w)*((int)x[1]+1)] = collar;DM->v[(int)x[0]+(int)(CM->w)*((int)x[1]+1)] = x[2];}
	DM->v[(int)x[0]+(int)(CM->w)*(int)x[1]] = x[2];
	}

      while(r[0]>0.5) {// x[d] += Ud->v[d]; r[0]-=1;
	if(WAAAPPP==1){
      	CM->v[(int)x[0]+(CM->w)*(int)x[1]] = collar;
      	DM->v[(int)x[0]+(CM->w)*(int)x[1]] = x[2];}
        x[d] += Ud->v[d];	 r[0]-=1;}

      //while(r[1]>=0.5) { x[2] += Ud->v[2]; r[1]-=1;}
    }
    delete Ud;
  };


  //********DRAWING TRIANGLES**********
  void apDrawTriangle(Matrix *P1, Matrix *P2, Matrix *P3,int sides){

	float ZERO = 0.0002;

	int xmin=(int)P1->v[0],xmax=(int)P1->v[0];
	int ymin=(int)P1->v[1],ymax=(int)P1->v[1];

	if(xmin>(int)P2->v[0]) xmin=(int)P2->v[0];
        if(ymin>(int)P2->v[1]) ymin=(int)P2->v[1];
        if(xmin>(int)P3->v[0]) xmin=(int)P3->v[0];
        if(ymin>(int)P3->v[1]) ymin=(int)P3->v[1];
        if(xmax<(int)P2->v[0]) xmax=(int)P2->v[0]+1;
        if(ymax<(int)P2->v[1]) ymax=(int)P2->v[1]+1;
        if(xmax<(int)P3->v[0]) xmax=(int)P3->v[0]+1;
        if(ymax<(int)P3->v[1]) ymax=(int)P3->v[1]+1;


	for(int lastshot=0;lastshot<2;lastshot++){

	float normval01[]={(P1->v[1])-(P2->v[1]),(P2->v[0])-(P1->v[0]),(P1->v[0])*(P2->v[1])-(P1->v[1])*(P2->v[0])};
        float normval12[]={(P2->v[1])-(P3->v[1]),(P3->v[0])-(P2->v[0]),(P2->v[0])*(P3->v[1])-(P2->v[1])*(P3->v[0])};
        float normval20[]={(P3->v[1])-(P1->v[1]),(P1->v[0])-(P3->v[0]),(P3->v[0])*(P1->v[1])-(P3->v[1])*(P1->v[0])};
	float zvals[] = {P1->v[2],P2->v[2],P3->v[2]};



	Vector *p1;Vector *p3;

	p1 = new Vector(3,P1->v);p3 = new Vector(3,P3->v);	

	Vector *p2 = new Vector(3,P2->v);

	//if(invert){Matrix *terpar=P1;P1=P3;P3=terpar;}

	Vector *f01=new Vector(3,normval01); Vector *f12=new Vector(3,normval12); Vector *f20=new Vector(3,normval20);
	Vector *XY = new Vector(3); Vector *abg= new Vector(3); Vector *ABG;
	Vector *Zvec = new Vector(3,zvals); Vector *Ones = new Vector(3);
  //Zvec->Print();
	//cout<<"----------p1--------\n";p1->Print();

	for(float xit=xmin+0.5;xit<=xmax+0.5;xit++){
		XY->v[0]=xit;
		for(float yit=ymin+0.5;yit<=ymax+0.5;yit++){
			XY->v[1]=yit;
			abg->v[0]=(f01->Dot(XY)/(p1->Dot(XY)));
      abg->v[1]=(f12->Dot(XY)/(p2->Dot(XY)));
      abg->v[2]=(f20->Dot(XY)/(p3->Dot(XY)));
      if((abg->v[0]>=0.0000)&&(abg->v[1]>=0.0000)&&(abg->v[2]>=0.0000)){
				abg->v[0]*=(p1->Dot(XY));
       	abg->v[1]*=(p2->Dot(XY));
	      abg->v[2]*=(p3->Dot(XY));
				if(xit<0 || xit>CM->w) continue;
			   	float depth = (abg->Dot(Zvec))/(Ones->Dot(abg));
				  int index = xit+(int)(CM->w)*yit-(int)(CM->w)/2;
				  //cout << "dep: "<<depth << '\n';
				  if(depth<DM->v[index]){
            CM->v[index] = 0;
            DM->v[index] = depth;//+0.0002;
          }
			}
    }
	}

	//P1->v[2]=((f01->Dot(p1)));:w
	//if(yesss) cout<< "we did that    ";
	delete f01; delete f12; delete f20; delete XY; delete abg; delete Zvec; delete Ones; delete p1; delete p2; delete p3;
if(invert) {Matrix *tmp = P1; P1=P3; P3=tmp;}
}
	//draw sides
    if(sides>0) apDrawLine(P1,P2,0);
    //if(sides>0) apDrawLine(P2,P1,0);
    if(sides>1) apDrawLine(P1,P3,0);
    //if(sides>1) apDrawLine(P3,P1,0);
    if(sides>2) apDrawLine(P2,P3,0);
    //if(sides>2) apDrawLine(P3,P2,0);
    //Matrix *tmp = P1; P1=P3; P3=tmp;
  };

  //*******PRINT PPM**********
  void Print(int fiNu) {
    
    char buffer[11]; int ct,counter;
    char*FN= new char[15];
    sprintf(buffer,"%d",fiNu);
    for(counter=0;buffer[counter]!='\0';++counter); 
    counter = 10-counter;
    for(ct=0;buffer[ct]!='\0';ct++) FN[counter+ct]=buffer[ct];
    for(ct=0;ct<counter;ct++) FN[ct]='0';

    FN[10]='.';FN[11]='p';FN[12]='p';FN[13]='m';FN[14]='\0';
    
    ofstream myfile;
    myfile.open (FN);
    myfile << "P6\n"<<CM->w<<' '<<CM->h<<"\n255\n";
    int dim = CM->h*CM->w;
    for(int i=0;i<dim;i++) myfile<<(char)CM->v[i]<<(char)CM->v[i]<<(char)CM->v[i];
    myfile.close();
    
  };

};

#endif
