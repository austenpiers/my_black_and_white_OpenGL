#ifndef APMATRIX4_H
#define APMATRIX4_H

#include "Vector.h"

class apMatrix4 : public Matrix {

  public:
  //********CONTSRUCTORS************
  apMatrix4 () : Matrix(4) {};
  apMatrix4 (int a) : Matrix(4,(float) a) {};
  apMatrix4 (float a) : Matrix(4,a) {};
  apMatrix4 (double a) : Matrix(4,(float) a) {};

  apMatrix4 (const int a, int b) : Matrix(4,4,(float)b) {};
  apMatrix4 (const int a, float c) : Matrix(4,4,c) {};
  apMatrix4 (const int a, double c) : Matrix(4,4,(float)c){};

  apMatrix4 (float* pv) : Matrix(4,4,pv) {};

  apMatrix4 (const int a, float* v) {cout << "You cannot specify Dimentions for apMatrix4\n";};
  apMatrix4 (const int a, const int b, float c) {cout << "You cannot specify Dimentions for apMatrix4\n";};
  apMatrix4 (const int a, const int b, float *c) {cout << "You cannot specify Dimentions for apMatrix4\n";};

  apMatrix4 (Vector* a) : Matrix(4,4) { v=new float[16];
	v[0]=a->v[0]; 	v[1]=0; 	v[2]=0; 	v[3]=0;
        v[4]=0; 	v[5]=a->v[1]; 	v[6]=0; 	v[7]=0; 
        v[8]=0; 	v[9]=0; 	v[10]=a->v[2];	v[11]=0; 
        v[12]=0;	v[13]=0;	v[14]=0;	v[15]=1; 
  };
  apMatrix4 (Vector* a,int o) : Matrix(4,4) { v=new float[16];
        v[0]=1;         v[1]=0;         v[2]=0;         v[3]=a->v[0];
        v[4]=0;         v[5]=1;         v[6]=0;         v[7]=a->v[1];
        v[8]=0;         v[9]=0;         v[10]=1;        v[11]=a->v[2];
        v[12]=0;        v[13]=0;        v[14]=0;        v[15]=1;
  };
  apMatrix4 (Vector* b,Vector* a) : Matrix(4,4) { v=new float[16];
        v[0]=b->v[0];         v[1]=0;         v[2]=0;         v[3]=a->v[0];
        v[4]=0;         v[5]=b->v[1];         v[6]=0;         v[7]=a->v[1];
        v[8]=0;         v[9]=0;         v[10]=b->v[2];        v[11]=a->v[2];
        v[12]=0;        v[13]=0;        v[14]=0;        v[15]=1;
  };
  apMatrix4 (Vector* a,Vector* b,Vector* c,Vector* d) : Matrix(4,4) { v=new float[16];
        v[0]=a->v[0];         v[1]=b->v[0];         v[2]=c->v[0];         v[3]=d->v[0];
        v[4]=a->v[1];         v[5]=b->v[1];         v[6]=c->v[1];         v[7]=d->v[1];
        v[8]=a->v[2];         v[9]=b->v[2];         v[10]=c->v[2];        v[11]=d->v[2];
        v[12]=0;        v[13]=0;        v[14]=0;        v[15]=1;
  };
  apMatrix4 (Vector* a,Vector* b,Vector* c) : Matrix(4,4) { v=new float[16];
        v[0]=a->v[0];         v[1]=a->v[1];         v[2]=a->v[2];         v[3]=0;
        v[4]=b->v[0];         v[5]=b->v[1];         v[6]=b->v[2];         v[7]=0;
        v[8]=c->v[0];         v[9]=c->v[1];         v[10]=c->v[2];        v[11]=0;
        v[12]=0;        v[13]=0;        v[14]=0;        v[15]=1;
  };

/*
  apMatrix4 (Vector* a) : h(4),w(4) { v=new float[16];

  };
*/ 

  //*********Overridden Operator Overloaders***********
  apMatrix4* operator - (apMatrix4* a){ Matrix *m1=this; Matrix *m2=a;
    Matrix *m = (*m1)-m2;  apMatrix4 *r = new apMatrix4(m->v); 
    delete m; return r;    };
  apMatrix4* operator + (apMatrix4* a){ Matrix *m1=this; Matrix *m2=a;
    Matrix *m = (*m1)+m2;  apMatrix4 *r = new apMatrix4(m->v); 
    delete m; return r;    };
  apMatrix4* operator * (apMatrix4* a){ Matrix *m1=this; Matrix *m2=a;
    Matrix *m = (*m1)*m2;  apMatrix4 *r = new apMatrix4(m->v); 
    delete m; return r;    };
  apMatrix4* operator * (const float a){ Matrix *m1=this;
    Matrix *m = (*m1)*a;  apMatrix4 *r = new apMatrix4(m->v); 
    delete m; return r;    };
  apMatrix4* operator / (const float a){ Matrix *m1=this;
    Matrix *m = (*m1)/a;  apMatrix4 *r = new apMatrix4(m->v); 
    delete m; return r;    };

  //*********Overridden Other Matrix Operators********
  apMatrix4* Transpose(void){ Matrix *m1 = this; Matrix *m=m1->Transpose();
    apMatrix4 *r = new apMatrix4(m->v);  delete m; return r;    };
  apMatrix4* Normalize(void){ Matrix *m1 = this; Matrix *m=m1->Normalize();
    apMatrix4 *r = new apMatrix4(m->v);  delete m; return r;    };
};

#endif

