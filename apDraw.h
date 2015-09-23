#ifndef APDRAW_H
#define APDRAW_H

#include "apPPMatrix.h"
#include <deque>

class apDraw{

  public:
  deque<Matrix*> Points;  int drawType; 
  bool drawing, rtu, first;
  //********CONTSRUCTORS************
  apDraw(void) : drawing(false),rtu(false),first(true) {};

  //********DESTRUCTOR************
  ~apDraw(){while(!Points.empty()) Points.pop_back(); };
  
  // **************OPENGL COMMANDS***********
  void apBegin(int type) {drawing=true; drawType=type;};
  void apEnd( apPPMatrix *me) {drawing=false; 
    if(Points.size()>1) me->apDrawLine(Points[0],Points[1],0);  
    while(!Points.empty())  Points.pop_back();};

  void apVertex(Matrix *nPt, apPPMatrix *me){

     //nPt->v[2]*=1000; nPt->v[2]=(int)(nPt->v[2])%100; nPt->v[2]=(float)(nPt->v[2])/10;
      //nPt->Print();
     //if((nPt->v[2]!=nPt->v[2]) || nPt->v[2]>0){nPt->v[2]=-255;cout<<"WeHaveAnIssue\n";}

    if(!drawing) {cout << "Sorry there are no current objects\n";exit(0);}
    Matrix *cp = new Matrix(1,4,nPt->v);
    Points.push_back(cp);

//	cout<< Points.size()<<endl;

    if(Points.size()>2) {
      switch(drawType){
      case 0:
      	me->apDrawTriangle(Points[0],Points[1],Points[2],-1);
      	break;
      case 1:
      	me->apDrawTriangle(Points[0],Points[1],Points[2],0);
      	break;
      case 2:
      	if(!rtu) me->apDrawTriangle(Points[0],Points[1],Points[2],1);
      	else  me->apDrawTriangle(Points[2],Points[1],Points[0],1);
      	break;
      case 3:
      	if(first)  me->apDrawTriangle(Points[0],Points[1],Points[2],2);
      	else me->apDrawTriangle(Points[2],Points[0],Points[1],1);
      	break;
      case 4:
      	me->apDrawTriangle(Points[0],Points[1],Points[2],3);
      	break;
      defalt:
      	me->apDrawTriangle(Points[0],Points[1],Points[2],4);
      	break;
      }
      Points.pop_front();
      rtu=(!rtu); first = false;
    }
  };

};

#endif
