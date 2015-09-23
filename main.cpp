#include "apWrapGL.h"
#include "image.h"

void drawShapes(int cube){

  float z=1.5;

  switch(cube){
    case 0:
      glPushMatrix();
        glTranslatef(0,0,z);
        drawM();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslatef(0,0,z);
        drawN();
      glPopMatrix();
      glPushMatrix();
        glRotated(180,0,1,0);
        glTranslatef(0,0,z);
        drawO();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,0,1,0);
        glTranslatef(0,0,z);
        drawP();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,1,0,0);
        glTranslatef(0,0,z);
        drawTriangle();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,1,0,0);
        glTranslatef(0,0,z);
        drawSquare();
      glPopMatrix();
      break;
    case 1:    
      glPushMatrix();
        glTranslatef(0,0,z);
        drawE();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslatef(0,0,z);
        drawF();
      glPopMatrix();
      glPushMatrix();
        glRotated(180,0,1,0);
        glTranslatef(0,0,z);
        drawG();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,0,1,0);
        glTranslatef(0,0,z);
        drawH();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,1,0,0);
        glTranslatef(0,0,z);
        drawDiv();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,1,0,0);
        glTranslatef(0,0,z);
        drawTimes();
      glPopMatrix();
      break;
    case 2:    
      glPushMatrix();
        glTranslatef(0,0,z);
        drawU();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslatef(0,0,z);
        drawV();
      glPopMatrix();
      glPushMatrix();
        glRotated(180,0,1,0);
        glTranslatef(0,0,z);
        drawW();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,0,1,0);
        glTranslatef(0,0,z);
        drawX();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,1,0,0);
        glTranslatef(0,0,z);
        drawHexagon();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,1,0,0);
        glTranslatef(0,0,z);
        drawOctagon();
      glPopMatrix();
      break;
    case 3:    
      glPushMatrix();
        glTranslatef(0,0,z);
        drawA();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslatef(0,0,z);
        drawB();
      glPopMatrix();
      glPushMatrix();
        glRotated(180,0,1,0);
        glTranslatef(0,0,z);
        drawC();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,0,1,0);
        glTranslatef(0,0,z);
        drawD();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,1,0,0);
        glTranslatef(0,0,z);
        drawHebStar();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,1,0,0);
        glTranslatef(0,0,z);
        drawCross();
      glPopMatrix();
      break;
    case 4:    
      glPushMatrix();
        glTranslatef(0,0,z);
        drawY();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslatef(0,0,z);
        drawZ();
      glPopMatrix();
      glPushMatrix();
        glRotated(180,0,1,0);
        glTranslatef(0,0,z);
        drawPentagon();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,0,1,0);
        glTranslatef(0,0,z);
        drawCircle();
      glPopMatrix();
      glPushMatrix();
        glRotated(90,1,0,0);
        glTranslatef(0,0,z);
        drawMinus();
      glPopMatrix();
      glPushMatrix();
        glRotated(-90,1,0,0);
        glTranslatef(0,0,z);
        drawPlus();
      glPopMatrix();
      break;
    default:
      break;
  }
}


// ======= ENDLETTERS ======== 
static void drawBeveledCube(int col){
  A=2.0; B=1.5;
  glShadeModel(GL_SMOOTH);
  glPushMatrix();
  for(int i=0;i<3;++i){
    for(int j=0;j<2;++j){
      glRotated(j*90,0,1,0);
      glBegin(4);
        glVertex3f(A,A,A);
        glVertex3f(B,B,A);
        glVertex3f(A,-A,A);
        glVertex3f(B,-B,A);

        glVertex3f(-A,-A,A);
        glVertex3f(-B,-B,A);

        glVertex3f(-A,A,A);
        glVertex3f(-B,B,A);

        glVertex3f(A,A,A);
        glVertex3f(B,B,A);
      glEnd();
      glBegin(4);
        glVertex3f(B,B,B);
        glVertex3f(B,B,A);
        glVertex3f(B,-B,B);
        glVertex3f(B,-B,A);

        glVertex3f(-B,-B,B);
        glVertex3f(-B,-B,A);

        glVertex3f(-B,B,B);
        glVertex3f(-B,B,A);

        glVertex3f(-B,-B,B);
        glVertex3f(-B,-B,A);
       glEnd();
      glBegin(1);
        glVertex3f(B,-B,B);
        glVertex3f(B,B,B);
        glVertex3f(-B,-B,B);
        glVertex3f(-B,B,B);
      glEnd();
    }
    glPushMatrix();
    glRotated(90,1,0,0);
    }
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  return;
  }

// MAIN FUNCT
int main(int argc, char** argv){

  glutInit(argc, argv);
  glutInitWindowSize(750,750);
  glutInitWindowPosition(100, 80);

  INIT();

  for(numPic=0;numPic<FrameNum;numPic++){
	//if(numPic!=55 && numPic!=16)continue;

	  //cout<< numPic<<endl;
	  glViewport(0,0, 750, 750);
	  gluPerspective(45, 1, .1, 60);
	  if(numPic<FrameNum/2) gluLookAt(-22.4*(sin((float)numPic/(float)FrameNum*12.6))+0.01,3,22.4*(cos((float)numPic/(float)FrameNum*12.6))+0.01,0,0,0,0,-1,0);
	  else gluLookAt(0.01,25.3*(sin((float)numPic/(float)FrameNum*12.6))+3,22.4*(cos((float)numPic/(float)FrameNum*12.6))+0.01,0,0,0,0,-1,0);
    //gluLookAt(0.01,3,16.4+0.01,0,0,0,0,-1,0);
    glLoadIdentity();

/*
    glScalef(5,5,5);
    drawRect();
    glutSwapBuffers();
    continue;
*/

  glLoadIdentity();
  DrawNums();

  glLoadIdentity();
  glPushMatrix();
	
  glPushMatrix();
  glPushMatrix();
		glTranslated(0,0,-9.5);
		glRotated((float)numPic/(float)FrameNum*1020,0,1,0);
		drawBeveledCube(1);
    drawShapes(0);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-9,0,5);
    glRotated(-(float)numPic/(float)FrameNum*1020,0,1,0);
    drawBeveledCube(1);
    drawShapes(3);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(9,0,5);
    glRotated((float)numPic/(float)FrameNum*1020,0,1,0);
    drawBeveledCube(1);
    drawShapes(4);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-6,0,-3);
    glRotated((float)numPic/(float)FrameNum*1020,0,1,0);
    drawBeveledCube(1);
    drawShapes(1);
  glPopMatrix();
                
  glPushMatrix();
    glTranslatef(6,0,-3);
    glRotated(-(float)numPic/(float)FrameNum*1020,0,1,0);
    drawBeveledCube(1);
    drawShapes(2);
  glPopMatrix();

  glPopMatrix();

	glutSwapBuffers();
	
}stop(0);

}