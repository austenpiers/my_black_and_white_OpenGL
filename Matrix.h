#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Matrix{
 public:
  const int h,w;
  float *v;

  // **********Constructors*********
  Matrix () : h(0),w(0) { v = new float[1]; v[0]=0; };
  Matrix (const int a, const int b, float *c) : w(a), h(b) { const int dim = w*h; v = new float[dim]; 
    for (int i=0; i<dim; ++i)
      { v[i] = c[i];}   };
  //Make a-by-b Matrix with values 1
  Matrix (const int a, int b) : w(a), h(b) { const int dim = w*h; v = new float[dim];
	for(int i=0; i<dim; ++i) v[i]=1;};
  //Make a-by-b Matrix with values c
  Matrix (const int a, const int b, float c) : w(a), h(b) { const int dim = w*h; v = new float[dim];
        for(int i=0; i<dim; ++i) v[i]=c;};

  //Make a-by-a Identiy Matrix multiplied by c
  Matrix (const int a, float c) : w(a), h(a) { int dim = a*a; v = new float[dim]; 
    for(int i=0,j=0; j<dim; ++i) {  if(i==j) { v[i]=c; j+=(a+1); continue; } v[i]=0;}  };
  //Make a-by-a Identity Matrix
  Matrix (int a) : w(a), h(a) { int dim = a*a; v = new float[dim]; 
    for(int i=0,j=0; i<dim; ++i) {  if(i==j) { v[i]=1; j+=(a+1); continue; } v[i]=0;}  };

  //Copy Constructor
  Matrix (Matrix& Mc) : h(Mc.h),w(Mc.w) {int dim=h*w; v=new float[dim]; for(int i=0;i<dim;++i) v[i]=Mc.v[i];};

  //***********Getters***********
  const int& getWidth() {return w;};
  const int& getHeight() {return h;};
  float* getValues() {return v;};

  //*********Operator Overloaders***********
  Matrix* operator + (Matrix*);
  Matrix* operator - (Matrix*);
  Matrix* operator * (Matrix*);
  Matrix* operator * (const float);
  Matrix* operator / (const float);

  //*********Other Matrix Operators********
  Matrix* Transpose(void);
  Matrix* Normalize(void);  
  
  //Class Operators
  void Print(void);

  //Destructor
  ~Matrix(){ delete[] v;};
};



//ADDING
Matrix* Matrix::operator+ (Matrix* Mr){
  if(getHeight() != Mr->getHeight() || getWidth() != Mr->getWidth()){
    cout << "Sorry, Matrix dimentions do not agree during addition.\n";
    Matrix* Nul = new Matrix();
    return(Nul); 
  }

  const int th = Mr->getHeight(), tw = Mr->getWidth(), td = th*tw;
  float* nv = new float[td];
  float* v1 = getValues(); float* v2 = Mr->getValues();

  for (int i = 0; i < td; ++i)  nv[i] = v1[i]+v2[i];

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}

//SUBTRACTION
Matrix* Matrix::operator- (Matrix* Mr){
  if(getHeight() != Mr->getHeight() || getWidth() != Mr->getWidth()){
    cout << "Sorry, Matrix dimentions do not agree during subtraction.\n";
    Matrix* Nul = new Matrix();
    return(Nul);
  }

  const int th = Mr->getHeight(), tw = Mr->getWidth(), td = th*tw;
  float* nv = new float[td];
  float* v1 = getValues(); float* v2 = Mr->getValues();

  for (int i = 0; i < td; ++i)  nv[i] = v1[i]-v2[i];

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}


//MULTIPLYING SCALAR
Matrix* Matrix::operator* (const float p){

  const int th = getHeight(), tw = getWidth(), td = th*tw;
  float* nv = new float[th*tw];
  float* v1 = getValues();

  for (int i = 0; i < td; ++i)  nv[i] = v1[i]*p;

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}

//DIVISION SCALAR
Matrix* Matrix::operator/ (const float p){

  const int th = getHeight(), tw = getWidth(), td = th*tw;
  float* nv = new float[th*tw];
  float* v1 = getValues();

  for (int i = 0; i < td; ++i)  nv[i] = v1[i]/p;

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}


//MULTIPLYING MATRIX
Matrix* Matrix::operator* (Matrix* Mr){
  if(getWidth() != Mr->getHeight()){
    cout << "Sorry, Matrix dimentions do not agree during Multiplication.\n";
    Matrix* Nul = new Matrix();
    return(Nul);
  }
 
  const int th = getHeight(), tw = Mr->getWidth(), mid = getWidth(), dim = th*tw;
  float* nv = new float[dim];
  
  for(int hi = 0; hi < th; ++hi){
    for(int wi = 0; wi < tw; ++wi){
      nv[hi*tw + wi] = 0;
      for(int mi = 0; mi < mid; ++mi)
	nv[hi*tw + wi] = nv[hi*tw + wi] + v[hi*mid+mi] * Mr->v[mi*tw+wi];
    }
  }

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}

//TRANSPOSING MATRICIES
Matrix* Matrix::Transpose (void){

  const int th = getHeight(), tw = getWidth();
  float* td = getValues();
  float* nv = new float[th*tw];

  for(int hi = 0; hi < th; ++hi){
    for(int wi = 0; wi < tw; ++wi)
      nv[hi*tw+wi] = td[wi*th+hi];
  }

  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}

//NORMALIZE MATRICIES
Matrix* Matrix::Normalize (void){

  const int th = getHeight(), tw = getWidth();
  float norm = 0;
  float* td = getValues();
  
  for(int hi = 0; hi < th; ++hi){
    for(int wi = 0; wi < tw; ++wi)
      norm = norm + (td[wi*th+hi] * td[wi*th+hi]);
  }
  norm = sqrt(norm);
  float* nv = new float[th*tw];
  for(int hi = 0; hi < th; ++hi){
    for(int wi = 0; wi < tw; ++wi)
      nv[wi*th+hi] = td[wi*th+hi]/norm;
  }
  
  Matrix* RM = new Matrix(th,tw,nv);
  delete[] nv;
  return(RM);
}

//PRINTING MATRIX ENTRIES
void Matrix::Print(void){
  const int th = getHeight(), tw = getWidth();
  float* td = getValues();

  for(int hi = 0; hi < th; ++hi){
    for(int wi = 0; wi < tw; ++wi){
      cout<<v[hi*tw+wi]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
  return;
}

#endif
