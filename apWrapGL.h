#include "apViewMatrix.h"
#include "apModelView.h"
#include "apDraw.h"
typedef void (*F_PTR)(void);
typedef void (*Fk_PTR)(unsigned char, int, int);
typedef float GLfloat;
typedef float GLdouble;
typedef float GLint;
typedef float GLuint;
typedef float GLubyte;

int GL_QUADS=4,GL_TRIANGLE_STRIP=3,GL_QUAD_STRIP=3,GL_POLYGON=4; int PicWid,PicHei,numPic=0;
int GL_PROJECTION,GL_DEPTH_TEST,GL_LIGHTING,GL_LIGHT0,GL_COLOR_MATRIAL,GL_NORMALIZE;
int GL_AMBIENT,GL_SPECULAR,GL_POSITION,GL_DIFFUSE,GL_FRONT_AND_BACK;
int GL_SHININESS,GL_FLAT,GL_COLOR_MATERIAL,GL_TEXTURE_2D,GLUT_LEFT_BUTTON,GLUT_DOWN,GLUT_UP;
int GL_MODELVIEW,GL_SMOOTH;

apPPMatrix *VAP=NULL;   //CM DM
apViewMatrix* OAP=NULL; //TheLook
apModelView* MAP=NULL;  //current push-pop
apDraw *DAP=NULL;       // begin-end-vertex
Matrix *M=NULL,*M1=NULL,*M2=NULL;         //maintanace Matrix

 F_PTR apDrawFunc;
 F_PTR apIdleFunc;

void glutInit(int ad,char**sf){OAP=new apViewMatrix(); MAP=new apModelView();  return;}
void glutInitWindowSize(int ad,int sf){PicWid=ad;PicHei=sf;VAP=new apPPMatrix(PicWid,PicHei);}
void glutInitWindowPosition(int ad,int sf){return;}
void glEnable(int ad){return;}
void glDisable(int ad){return;}
void glLoadIdentity(void){MAP->apLoadIdentity();};
void glutDisplayFunc( F_PTR f) {apDrawFunc=f;}
void glutIdleFunc( F_PTR f) {apIdleFunc=f;}
void glutKeyboardFunc(Fk_PTR f) {return;}
void glMatrixMode(int ad){return;}
void glutMainLoop(void){(*apDrawFunc)();}
void glutPostRedisplay(void){(*apDrawFunc)();}
void glutSwapBuffers(void){
  VAP->Print(numPic); delete VAP; VAP=new apPPMatrix(PicWid,PicHei); //reset Drawing buffer
  delete OAP; OAP=new apViewMatrix(); //reset the Looking Matrix
  delete MAP; MAP=new apModelView();  //reset the Moving Matrix 
  if(DAP!=NULL) {delete DAP;DAP=NULL;}}// cout<<endl; }

void glPopMatrix(void){MAP->apPopMatrix();}
void glPushMatrix(void){MAP->apPushMatrix();}
void glRotatef(float ad,float sf,float dg, float fh){MAP->apRotate((float)ad,(float)sf,(float)dg,(float)fh);}
void glRotated(double ad,double sf,double dg, double fh){MAP->apRotate((float)ad,(float)sf,(float)dg,(float)fh);}
void glScalef(float ad,float sf,float dg){MAP->apScale((float)ad,(float)sf,(float)dg);}
void glScaled(float ad,float sf,float dg){MAP->apScale((float)ad,(float)sf,(float)dg);}
void glTranslatef(float ad,float sf,float dg){MAP->apTranslate((float)ad,(float)sf,(float)dg);}
void glTranslated(float ad,float sf,float dg){MAP->apTranslate((float)ad,(float)sf,(float)dg);}

void glBegin(int ad){DAP = new apDraw(); DAP->apBegin(ad);}
void glEnd(void){DAP->apEnd(VAP); delete DAP; DAP=NULL;}
void glNormal3f(float ad,float sf, float dg){return;}
void glVertex3f(float ad,float sf,float dg){float *yup=new float[4];
  //cout <<ad<<' '<<sf<<' '<<dg<<'\n';
  yup[0]=ad;yup[1]=sf;yup[2]=dg;yup[3]=1;
  M = (*OAP->TheLook)*(MAP->current); M1=new Matrix(1,4,yup); delete[] yup;
  M2=(*M)*M1; delete M; delete M1; //M2->Print(); 
  //M2->v[0]=(M2->v[0])/M2->v[3]; M2->v[1]=(M2->v[1])/M2->v[3];
  M2->v[2]*=-1; 
  //M2->v[3]=(M2->v[3])/M2->v[3]; M2->v[2]*=(-1);
  M=(*M2)/(M2->v[2]); //M2->Print();
  //M=(*M2)/(M2->v[3]);
  float tild = M->v[3]; M->v[3]=M->v[2];M->v[2]=tild;
  //M->v[2]+=(M2->v[4]/M2->v[3]); delete M2; M->Print();
  DAP->apVertex(M,VAP); //M->Print(); 
  delete M2; delete M; 
  M=NULL;M1=NULL;M2=NULL;}

void glColor4fv(float *ad){return;}
void glColor3f(float ad,float sf,float dg){return;}
void glapInvert(void){if(VAP!=NULL)VAP->apInvert();}

void glutCreateWindow(char*ad){return;}
void glViewport(float ad,float sf,float dg,float fh){OAP->apViewport(ad,sf,dg,fh);}
void gluPerspective(float ad,float sf,float dg,float fh){OAP->apPerspective(ad,sf,dg,fh);}
void gluLookAt(float ad,float sf,float dg,float fh,float zc,float xv,float cb,float vn,float bm){
  OAP->apLookAt(ad,sf,dg,fh,zc,xv,cb,vn,bm);}

void glLightfv(int ad,int sf,float*dg){return;}
void glMaterialfv(int ad,int sf,float *dg){return;}
void glMaterialf(int ad,int sf,float dg){return;}
void glShadeModel(int ad){return;}

void stop(int ad){ if(OAP!=NULL)delete OAP; if(VAP!=NULL)delete VAP; 
	if(MAP!=NULL)delete MAP; if(DAP!=NULL)delete DAP; exit(ad);}


void glTexCoord2f(float,float){return;}


