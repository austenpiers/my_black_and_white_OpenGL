#include "functs4U.h"

int FrameNum = 128;
int tick,tock,tic,toc;

static void (*E[6])(void);
static void (*O[6])(void);

void INIT(void){
  O[0]=draw1;
  E[0]=draw2;
  O[1]=draw3;
  E[1]=draw4;
  O[2]=draw5;
  E[2]=draw6;
  O[3]=draw7;
  E[3]=draw8;
  O[4]=draw9;
  E[4]=draw10;
  O[5]=NullFunc;
  E[6]=NullFunc;
  tick=0;
  tock=0;
  tic=-FrameNum/10;
  toc=0;
}


void idle(void){
  tick++;
  tic++;
  if(tick>FrameNum/6 && tock<6){ tick=0; tock+=1;}
  if(tic>FrameNum/6){ tic=0; toc+=1;}
  if(toc>4)stop(0);
}

void DrawNums(void){

	float curPic = 10/(float)FrameNum;
  glPushMatrix();
    glRotatef(10,0,1,0);
    if(tick<FrameNum/10){
      glTranslatef(0,0,-2);
      glRotatef((float)50*(1 - (float)tick*curPic),0,1,0);
      glTranslatef(0,0, (float)15*((float)tick*curPic - 1));
    }
    else
      glTranslatef(0,0, (float)22*((float)tick*curPic - 1));
    (*O[tock])();
  glPopMatrix();

  if(tic>0){
  glPushMatrix();
    glRotatef(-10,0,1,0);
    if(tic<FrameNum/10){
      glTranslatef(0,0,-2);
      glRotatef((float)50*((float)tic*curPic-1),0,1,0);
      glTranslatef(0,0, (float)15*((float)tic*curPic - 1));
    }
    else
      glTranslatef(0,0, (float)22*((float)tic*curPic - 1));
    (*E[toc])();
  glPopMatrix();
  }
  idle();
}
