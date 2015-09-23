#ifndef VECTOR_H
#define VECTOR_H
#include "Matrix.h"

class Vector: public Matrix {

  public:
  //CONTSRUCTORS
  Vector (const int a, const int b, float *c) { cout << "You cannot specify width for Vectors\n";  };
  Vector (const int a, const int b) { cout << "You cannot specify width for Vectors\n"; };
  Vector (const int a, float* v) : Matrix(1,a,v)  {};
  Vector (const int a, float c) : Matrix(1,a,c) {};
  Vector (const int a, const int b, float c) { cout << "You cannot specify width for Vectors\n";  };
  Vector (const int a) : Matrix(1,a) {};

  //DOT PRODUCT
  float Dot(Vector* a) {
    if(h != a->h){ cout<<"Sorry, the vector dimentions in Dot product don't agree"; return(0); }
    float value = 0;
    for(int i=0; i<h; ++i) value += (v[i]*a->v[i]);
    return(value);
  };

  //CROSS PRODUCT
  Vector* Cross(Vector* a){
    if((h != a->h) || (h != 3)){ cout<<"Sorry, the vector dimentions in Cross product don't agree"; exit(1);}
    float* nv = new float[3];
    nv[0] = (v[1]*a->v[2] - v[2]*a->v[1]);
    nv[1] = (v[2]*a->v[0] - v[0]*a->v[2]);
    nv[2] = (v[0]*a->v[1] - v[1]*a->v[0]);
    Vector* RM = new Vector(3,nv);
    delete[] nv;
    return(RM);
  };

  //*********Overridden Operator Overloaders***********
  Vector* operator - (Vector* a){ Matrix *m1=this; Matrix *m2=a;
    Matrix *m = (*m1)-m2;  Vector *r = new Vector(m->w,m->v); 
    delete m; return r;    };
  Vector* operator + (Vector* a){ Matrix *m1=this; Matrix *m2=a;
    Matrix *m = (*m1)+m2;  Vector *r = new Vector(m->w,m->v); 
    delete m; return r;    };
  Vector* operator * (const float a){ Matrix *m1=this;
    Matrix *m = (*m1)*a;  Vector *r = new Vector(m->w,m->v); 
    delete m; return r;    };
  Vector* operator / (const float a){ Matrix *m1=this;
    Matrix *m = (*m1)/a;  Vector *r = new Vector(m->w,m->v); 
    delete m; return r;    };

  //*********Overridden Other Matrix Operators********
  Vector* Normalize(void){ Matrix *m1 = this; Matrix *m=m1->Normalize();
    Vector *r = new Vector(m->w,m->v);  delete m; return r;    };
};

#endif
