int LGT=0;float A=2.0, B=1.5,C,*g=NULL,*n=NULL,*b=NULL,*o=NULL,*r=NULL,*y=NULL,*p=NULL,*t=NULL;int i,j;


static void NullFunc(void){return;}
static void drawRect(void){
  glShadeModel(GL_FLAT);
  A=1.0;
  glPushMatrix();
  glBegin(GL_QUAD_STRIP);    
    glNormal3f(-1,0,0);
    glVertex3f(-A,A,0.25);
    glVertex3f(-A,-A,0.25);
    glVertex3f(-A,A,-0.25);
    glVertex3f(-A,-A,-0.25);

    glNormal3f(0,-1,0);
    glVertex3f(A,-A,0.25);
    glVertex3f(A,-A,-0.25);

    glNormal3f(1,0,0);
    glVertex3f(A,A,0.25);
    glVertex3f(A,A,-0.25);

    glNormal3f(0,1,0);
    glVertex3f(-A,A,0.25);
    glVertex3f(-A,A,-0.25);
  glEnd();

  glPushMatrix();
  for(i=-1;i<2;i+=2){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,i);
      glVertex3f(A,-A,i*0.25);
      glVertex3f(A,A,i*0.25);
      glVertex3f(-A,-A,i*0.25);
      glVertex3f(-A,A,i*0.25);
    glEnd();
  }
  glPopMatrix();
  glPopMatrix();

}

static void drawTrap(void){
  glShadeModel(GL_FLAT);
  A=1.0;B=0.4;C=0.5;
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
      if(i==1)glNormal3f(0,0,1);
      else    glNormal3f(0,0,-1);
      glVertex3f(0.0,A,i*C);
      glVertex3f(B,2*B,i*C);
      glVertex3f(0.0,-A,i*C);
      glVertex3f(B,2*-B,i*C);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);

      glNormal3f(1,3,0);
      glVertex3f(0.0,A,C);
      glVertex3f(0.0,A,0.0);
      glVertex3f(B,2*B,C);
      glVertex3f(B,2*B,0.0);

      glNormal3f(1,0,0);
      glVertex3f(B,2*-B,C);
      glVertex3f(B,2*-B,0.0);

      glNormal3f(-1,-3,0);
      glVertex3f(0.0,-A,C);
      glVertex3f(0.0,-A,0.0);

      glNormal3f(-1,0,0);
      glVertex3f(0.0,A,C);
      glVertex3f(0.0,A,0.0);
  glEnd();
}

static void drawParl(void){
  glShadeModel(GL_FLAT);
  A=1.0;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
      glNormal3f(0,0,i);
      glVertex3f(-A,A,i*0.5);
      glVertex3f(0.0,A,i*0.5);
      glVertex3f(0.0,-A,i*0.5);
      glVertex3f(A,-A,i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
    glNormal3f(0,1,0);
    glVertex3f(-A,A,0.5);
    glVertex3f(-A,A,0.0);
    glVertex3f(0.0,A,0.5);
    glVertex3f(0.0,A,0.0);

    glNormal3f(3,1,0);
    glVertex3f(A,-A,0.5);
    glVertex3f(A,-A,0.0);

    glNormal3f(0,-1,0);
    glVertex3f(0.0,-A,0.5);
    glVertex3f(0.0,-A,0.0);

    glNormal3f(-3,-1,0);
    glVertex3f(-A,A,0.5);
    glVertex3f(-A,A,0.0);
  glEnd();
  glPopMatrix();
}

static void drawSq(void){
  glShadeModel(GL_FLAT);
  A=1.0;B=0.635;C=0.35;
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
      glNormal3f(0,0,i);
      glVertex3f(-A,A,i*0.5);
      glVertex3f(0.0,-A,i*0.5);
      glVertex3f(0.0,A,i*0.5);

      glVertex3f(A/4,-A,i*0.5);
      glVertex3f(B,-C,i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
    glNormal3f(0,1,0);
    glVertex3f(0.0,A,0.5);
    glVertex3f(0.0,A,0.0);
    glVertex3f(-A,A,0.5);
    glVertex3f(-A,A,0.0);

    glNormal3f(-3,-1,0);
    glVertex3f(0.0,-A,0.5);
    glVertex3f(0.0,-A,0.0);

    glNormal3f(0,-1,0);
    glVertex3f(A/4,-A,0.5);
    glVertex3f(A/4,-A,0.0);

    glNormal3f(1,-1,0);
    glVertex3f(B,-C,0.5);
    glVertex3f(B,-C,0.0);

    glNormal3f(3,1,0);
    glVertex3f(0.0,A,0.5);
    glVertex3f(0.0,A,0.0);
  glEnd();

}

static void drawDim(void){
  glShadeModel(GL_FLAT);
  A=1.0;B=0.635;C=0.35;
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
      glNormal3f(0,0,i);

      glVertex3f(-B,C,i*0.5);
      glVertex3f(-A/4,A,i*0.5);
      glVertex3f(0.0,-A,i*0.5);
      glVertex3f(0.0,A,i*0.5);
      glVertex3f(A/4,-A,i*0.5);
      glVertex3f(B,-C,i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
    glNormal3f(0,1,0);
    glVertex3f(0.0,A,0.5);
    glVertex3f(0.0,A,0.0);
    glVertex3f(-A/4,A,0.5);
    glVertex3f(-A/4,A,0.0);

    glNormal3f(-1,1,0);
    glVertex3f(-B,C,0.5);
    glVertex3f(-B,C,0.0);

    glNormal3f(-1,-2,0);
    glVertex3f(0.0,-A,0.5);
    glVertex3f(0.0,-A,0.0);

    glNormal3f(0,-1,0);
    glVertex3f(A/4,-A,0.5);
    glVertex3f(A/4,-A,0.0);

    glNormal3f(1,-1,0);
    glVertex3f(B,-C,0.5);
    glVertex3f(B,-C,0.0);

    glNormal3f(1,2,0);
    glVertex3f(0.0,A,0.5);
    glVertex3f(0.0,A,0.0);
  glEnd();
}
static void drawCirc(void){
  glShadeModel(GL_SMOOTH);
  A=0.39269;C=6.28;
  glPushMatrix();
  
  for(i=1;i>-1;--i){
    glBegin(1);
    glNormal3f(0,0,i);
    for(B=0; B<C; B+=A){
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  glNormal3f(1,0,0);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),0);
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawCircle(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  drawCirc();
}


static void drawTad(void){
  A=0.26;C=1.70;
  glShadeModel(GL_FLAT);
  glPushMatrix();

  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,i);
    glVertex3f(0.0,1.0,i*0.5);
    glVertex3f(0.0,1.25,i*0.5);
    glVertex3f(1.35,1.25,i*0.5);
    glVertex3f(1.35,0.0,i*0.5);
    glVertex3f(1.2,0.0,i*0.5);
    glEnd();
  }
  
  glBegin(GL_QUAD_STRIP);
    glNormal3f(-1,0,0);
    glVertex3f(0.0,1.0,0.5);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(0.0,1.25,0.5);
    glVertex3f(0.0,1.25,0.0);
    
    glNormal3f(0,1,0);
    glVertex3f(1.35,1.25,0.5);
    glVertex3f(1.35,1.25,0.0);

    glNormal3f(1,0,0);
    glVertex3f(1.35,0.0,0.5);
    glVertex3f(1.35,0.0,0.0);

    glNormal3f(0,-1,0);
    glVertex3f(1.2,0.0,0.5);
    glVertex3f(1.2,0.0,0.0);

    glNormal3f(-1,-1,0);
    glVertex3f(0.0,1.0,0.5);
    glVertex3f(0.0,1.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawPlus(void){
  if(LGT) glColor4fv(p);
  else glColor4fv(n);
  glPushMatrix();
    glScalef(0.7,0.25,1);
    drawRect();
  glPopMatrix();

  glPushMatrix();
    glScalef(0.25,0.7,1);
    drawRect();
  glPopMatrix();
}
static void drawMinus(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
    glScalef(0.7,0.25,1);
    drawRect();
  glPopMatrix();
}
static void drawTimes(void){
  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  glPushMatrix();
    glRotated(45,0,0,1);
    drawPlus();
  glPopMatrix();
}
static void drawDiv(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  glPushMatrix();
    glScalef(0.7,0.125,1);
    drawRect();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0,0.5,-0.25);
    glScalef(0.25,0.25,1);
    drawCirc();
  glPopMatrix(); 
  glPushMatrix();
    glTranslatef(0,-0.5,-0.25);
    glScalef(0.25,0.25,1);
    drawCirc();
  glPopMatrix(); 
}
static void drawCross(){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0,0.5,0);
    glScalef(0.7,0.125,1);
    drawRect();
  glPopMatrix();
  glPushMatrix();
    glScalef(0.25,1,1);
    drawRect();
  glPopMatrix();
}

static void drawTriangle(void){
  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  glShadeModel(GL_SMOOTH);
  A=2.094395;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,i);
    for(B=0; B<C; B+=A)
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
      glNormal3f((GLdouble) -cos(B+A),(GLdouble) -sin(B+A),0);

    for(i=1;i>-1;--i){
//      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),0);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glNormal3f(1,-2,0);
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawHebStar(void){
  if(LGT) glColor4fv(o);
  else glColor4fv(n);
  glPushMatrix();
  glRotatef(30,0,0,1);
  drawTriangle();
  glPushMatrix();
    glScaled(-1,1,1);
    drawTriangle();
  glPopMatrix();
  glPopMatrix();
}
static void drawSquare(void){
  glShadeModel(GL_FLAT);
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  A=1.570796;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,i);
    for(B=0; B<C; B+=A)
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}

static void drawPentagon(void){
  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  glShadeModel(GL_FLAT);
  A=1.2566;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,(GLdouble) i);
    for(B=0; B<C; B+=A)
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawHexagon(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glShadeModel(GL_FLAT);
  A=1.0471976;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    glNormal3f(0,0,i);
    for(B=0; B<C; B+=A)
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawHeptagon(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  glShadeModel(GL_FLAT);
  A=0.897598;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    for(B=0; B<C; B+=A)
      glNormal3f(0,0,i);
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawOctagon(void){
  if(LGT) glColor4fv(p);
  else glColor4fv(n);
  glShadeModel(GL_FLAT);
  A=0.78539816;C=6.28;
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    if(i==1) glNormal3f(0,0,1);
    else     glNormal3f(0,0,-1);
    for(B=0; B<C; B+=A)
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
    glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),0);
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawNonagon(void){
  A=0.6981317;C=6.28;
  glShadeModel(GL_FLAT);
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    for(B=0; B<C; B+=A)
      glNormal3f(0,0,i);
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
static void drawDecagon(void){
  A=0.6283185;C=6.28;
  glShadeModel(GL_FLAT);
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_POLYGON);
    for(B=0; B<C; B+=A)
      glVertex3f(0,0,i*0.5);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    for(i=1;i>-1;--i){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}

static void drawCurvedEdge(void){
  A=0.2617;C=1.66;
  glShadeModel(GL_FLAT);
  glPushMatrix();
  for(i=1;i>-1;--i){
    glBegin(GL_TRIANGLE_STRIP);
    for(B=0; B<C; B+=A){
      if(i==1){
	glNormal3f(0,0,1);
	glVertex3f((GLdouble) cos(B)*0.5,(GLdouble) sin(B)*0.5,(GLdouble) i*0.5);
	glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
	continue;
      }
      glNormal3f(0,0,-1);
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
      glVertex3f((GLdouble) cos(B)*0.5,(GLdouble) sin(B)*0.5,(GLdouble) i*0.5);
    }
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){

    glNormal3f((GLdouble) cos(B),(GLdouble) sin(B),0);
    for(i=1;i>-1;--i){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B),(GLdouble) i*0.5);
    }
  }
  glNormal3f(-1,0,0);
  for(B=B-A; B>-0.26; B-=A){
    for(i=1;i>-1;--i){
      glVertex3f((GLdouble) cos(B)*0.5,(GLdouble) sin(B)*0.5,(GLdouble) i*0.5);
    }
    glNormal3f((GLdouble) -cos(B),(GLdouble) -sin(B),0);
  }
  glNormal3f(0,-1,0);
  glVertex3f(1.0,0.0,0.5);
  glVertex3f(1.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}

static void drawCurvedEdgeh(void){

    drawCurvedEdge();
    glPushMatrix();
      glTranslatef(0.01,0,0);
      glScaled(-1,1,1);
      drawCurvedEdge();
    glPopMatrix();
}

static void drawCurvedEdget(void){

    drawCurvedEdge();
    glPushMatrix();
      glScaled(1,-1,1);
      drawCurvedEdgeh();
    glPopMatrix();
}

static void drawCurvedEdgef(void){

    drawCurvedEdgeh();
    glPushMatrix();
      glScaled(1,-1,1);
      drawCurvedEdgeh();
    glPopMatrix();
}

static void drawEdgedParl(void){

    glPushMatrix();
      drawParl();
      drawCurvedEdgeh();
    glPopMatrix();
}

// ================ SRARTNUMBERS ============== 

static void draw0(void){

  if(LGT) glColor4fv(t);
  else glColor4fv(n);
    glPushMatrix();
      glScaled(1.0,1.5,1.0);
      drawCurvedEdgef();
    glPopMatrix();
}

static void draw9(void){
 
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
    glPushMatrix();
      glTranslatef(0.0,0.6,0.0);
      drawCurvedEdgef();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0,-0.5,0);
      glScaled(1,-1,1);
      drawCurvedEdgeh();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.75,0.0,0.25);
      glScalef(0.25,0.5,1);
      drawRect();
    glPopMatrix();
}
static void draw8(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
    glPushMatrix();
  glTranslatef(0,-0.75,0);
  glScalef(0.9,0.9,1.0);
  
    drawCurvedEdgef();
    glPushMatrix();
      glTranslatef(0.0,1.5,0.0);
      glScalef(0.9,0.9,1.0);
      drawCurvedEdgef();
    glPopMatrix();
    glPopMatrix();

}

static void draw7(void){

  if(LGT) glColor4fv(y);
  else glColor4fv(n);
    glPushMatrix();
      glTranslatef(0.925,-0.075,0);
      glScalef(-1.25,1.25,1.0);
      drawCurvedEdge();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0,1.175,0.25);
      glScalef(0.925,0.3,1);
      drawRect();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.02,-0.825,0.25);
    glScalef(0.31,0.75,1);
    drawRect();
    glPopMatrix();
}

static void draw6(void){

  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
  glRotated(180,0,0,1);
  draw9();
  glPopMatrix();
}

static void draw5(void){

  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  glPushMatrix();
  glTranslatef(0.0,-0.5,0.0);
  glScalef(1.0,1.1,1.0);

  drawCurvedEdget();

  glPushMatrix();
  glScalef(0.4,0.25,1);
  glTranslatef(-0.9,3.0,0.25);
  drawRect();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.25,0.5,1);
  glTranslatef(-2.6,2.0,0.25);
  drawRect();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(0.9,0.25,1);
  glTranslatef(0.0,6.0,0.25);
  drawRect();
  glPopMatrix();
  glPopMatrix();
}
static void draw4(void){
  
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  glPushMatrix();
  glPushMatrix();
  glScalef(1.0,0.9,1.0);
  glTranslatef(-0.3,0.9,0.0);
  glRotated(-40,0,0,1);
  drawTrap();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.25,1.5,1.0);
  glTranslatef(2.0,0.0,0.25);
  drawRect();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(0.9,0.25,1.0);
  glTranslatef(0.0,-0.5,0.25);
  drawRect();
  glPopMatrix();
  glRotated(-45,0,0,1);
  glPopMatrix();
}

static void draw3(void){

  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  glPushMatrix();
    glTranslated(0.0,0.65,0.5);
    glScalef(1.0,0.9,1.0);
    glPushMatrix();
      glTranslatef(0.0,-1.5,-0.5);
      drawCurvedEdget();
    glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
    glTranslated(0,0.65,0);
    glScaled(1,-1,1);
    drawCurvedEdget();
  glPopMatrix();
}

static void draw2(void){

  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
  glTranslatef(0.01,-1,0);
    glScaled(-1,1,1);
    drawCurvedEdge();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.01,-1.25,0.25);
    glScalef(1.0,0.25,1);
    drawRect();
  glPopMatrix();
  
  glPushMatrix();
    glScaled(1,-1,1);
    glTranslatef(0,-0.5,0);
    drawCurvedEdget();
  glPopMatrix();
}

static void draw1(void){
  if(LGT) glColor4fv(t);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0.0,0.0,0.25);
  
    glScalef(1.2,1.2,1.0);

    glPushMatrix();
      glTranslatef(-0.77,1.25,-0.25);
      glScalef(1.0,-1.0,1.0);
      drawCurvedEdge();
    glPopMatrix();

    glPushMatrix();
      glScalef(0.25,1.25,1);
      drawRect();
    glPopMatrix();
  glPopMatrix();
}

static void draw10(void){

  draw1();glTranslatef(1.4,0.0,0.0);
  draw0();
}


// =========== ENDNUMBERS ============== \\


static void drawTopEdgew(void){
  glPushMatrix();
  glScalef(1.0,0.125,1.0);
  drawCirc();
  glPopMatrix();
}

static void drawTopEdget(void){
  glPushMatrix();
  glScalef(0.7,0.125,1.0);
  drawCirc();
  glPopMatrix();
}

static void drawOCurve(void){
  A=0.2617;C=1.66;
  glShadeModel(GL_FLAT);
  glPushMatrix();
  for(i=1;i>-2;i-=2){
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0,0,i);
    for(B=0,j=3; B<C; B+=A){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B)*(1+0.1),(GLdouble) i*0.25);
      glVertex3f((GLdouble) cos(B)*(0.5-j*0.075),(GLdouble) sin(B)*(0.5+0.1*j),(GLdouble) i*(0.25));
    }
    glEnd();
  }
  glBegin(GL_QUAD_STRIP);
  for(B=0; B<C; B+=A){
    glNormal3f((GLdouble) cos(B),(GLdouble) sin(B)*(1+0.1),0);
    for(i=1;i>-2;i-=2){
      glVertex3f((GLdouble) cos(B),(GLdouble) sin(B)*(1+0.1),(GLdouble) i*0.25);
    }
  }
  for(B=B-A; B>0; B-=A){
    glNormal3f((GLdouble) -cos(B)*(0.5-j*0.075),(GLdouble) -sin(B)*(0.5+0.1*j),0);
    for(i=1;i>-2;i-=2){
      glVertex3f((GLdouble) cos(B)*(0.5-j*0.075),(GLdouble) sin(B)*(0.5+0.1*j),(GLdouble) i*0.25);
    }
  }
  glVertex3f(0.5-j*0.075,0.0,0.25);
  glVertex3f(0.5-j*0.075,0.0,-0.25);
  glEnd();
  glPopMatrix();
}

static void drawOCurveh(void){
  glPushMatrix();
  drawOCurve();
  glPushMatrix();
    glScaled(1,-1,1);
    drawOCurve();
  glPopMatrix();
  glPopMatrix();
}

static void drawCParl1(void){
  glPushMatrix();
    glScaled(1.5,1.0,1);
    drawParl();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-0.75,1.0,0.0);
    drawTopEdgew();
  glPopMatrix();
}

static void drawCParl(void){
  glPushMatrix();
  drawCParl1();
  glPushMatrix();
    glTranslatef(0.75,-1,0.0);
    drawTopEdgew();
  glPopMatrix();
  glPopMatrix();
}

static void drawCTrap(void){
  glPushMatrix();
    glScaled(-1.5,1.0,1.0);
    glRotated(30,0,0,1);
    drawTrap();
  glPopMatrix();

  glPushMatrix();
    glTranslated(0.5,1.0,0.0);
    drawTopEdget();
  glPopMatrix();
}

static void drawCTrap1(void){
  glPushMatrix();
    glScaled(-1.5,1.0,1.0);
    drawTrap();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-0.25,0.9,0.0);
    drawTopEdget();
  glPopMatrix();
}

static void drawCSq(void){
  glPushMatrix();
    glScaled(1.25,1.0,1);
    drawSq();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-0.55,1.0,0.0);
    drawTopEdgew();
  glPopMatrix();
}

static void drawCSq1(void){
  glPushMatrix();
  glScalef(0.75,1.0,1.0);
  glRotated(180,0,0,1);
  drawCParl1();
  glPopMatrix();
}
static void drawCOC1(void){
  glPushMatrix();
    glTranslated(0.2,0,0);
    glScalef(1,-2.0,1);
    drawOCurve();
  glPopMatrix();

  glPushMatrix();
    glTranslated(0.9,0,-0.25);
    drawTopEdget();
  glPopMatrix();
}

static void drawCOC(void){
  glPushMatrix();
    glTranslated(0.05,-1.2,-0.25);
    glScalef(1.35,1,1);
    glRotated(180,0,0,1);
    drawCurvedEdge();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-0.95,-0.7,0);
    glScaled(0.35,0.6,1);
    drawRect();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-1,0.,-0.25);
    drawTopEdget();
  glPopMatrix();
}

static void drawCTad(void){
  drawTad();
  glPushMatrix();
    glRotated(-90,0,0,1);
    glTranslated(-0.6,1.25,0.0);
    glScaled(1.25,1.0,1.0);
    drawTopEdget();
  glPopMatrix();
}

static void drawBar(void){
  glPushMatrix();
  glScalef(0.375,1.0,1);
  drawRect();
  glPopMatrix();
}

static void drawBarf1(void){
  drawBar();
  glPushMatrix();
  glTranslatef(0.0,-1.0,-0.25);
  glScaled(0.625,1,1);
  drawTopEdgew();
  glPopMatrix();
}

static void drawBarf2(void){
  drawBarf1();
  glPushMatrix();
  glTranslatef(0.0,1.0,-0.25);
  glScaled(0.625,1,1);
  drawTopEdgew();
  glPopMatrix();
}
static void drawBarf1h(void){
  drawBarf1();
  glPushMatrix();
  glTranslatef(-0.25,0.875,-0.25);
  glScaled(0.625,1,1);
  drawTopEdget();
  glPopMatrix();
}
static void drawBarh(void){
  drawBar();
  glPushMatrix();
  glTranslatef(-0.25,-0.875,-0.25);
  glScaled(0.625,1,1);
  drawTopEdget();
  glPopMatrix();
}
static void drawBarh2(void){
  drawBarh();
  glPushMatrix();
  glTranslatef(-0.25,0.875,-0.25);
  glScaled(0.625,1,1);
  drawTopEdget();
  glPopMatrix();
}

// ====== STARTLETTERS ======== 


static void drawZ(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0.05,0,0);
    glScaled(-1,1,1);
    drawParl();
  glPopMatrix();

 
  glPushMatrix();
    glTranslatef(-0.05,0.4,0);
    glScalef(-0.5,0.5,1);
    drawCTad();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.15,-0.4,0);
    glScalef(0.5,-0.45,1);
    drawCTad();
  glPopMatrix();
}


static void drawY(void){
  
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  glPushMatrix();
  glTranslatef(-0.2,-0.15,0);
  glScalef(1.1,1.1,1);
  
  glPushMatrix();
    glTranslatef(-0.3,0.4,0);
    glScalef(-0.6,0.5,1);
    drawCTrap();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0,-0.3,0);
    glScalef(-0.6,-0.6,1);
    drawCTrap1();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.8,0.6,0);
    glScalef(0.5,0.4,1);
    drawCTrap();
  glPopMatrix();

  glPopMatrix();
}

static void drawX(void){

  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  glPushMatrix();
    glScalef(0.95,0.85,1);

  glPushMatrix();
    glScaled(0.55,1.,1);
    drawCParl();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.82,0.55,0);
    glScalef(0.45,0.5,1.0);
    drawCTrap();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(-0.82,-0.55,0);
    glScalef(-0.45,-0.5,1.0);
    drawCTrap();
  glPopMatrix();

  glPopMatrix();
}

static void drawW(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  
  glPushMatrix();
  glTranslatef(0.25,0,0);
  glScalef(0.8,1,1);

  glPushMatrix();
    glTranslated(0,-0.2,0);
    glScaled(0.9,0.9,1);
    drawDim();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-0.95,-0.15,0);
    glScalef(0.75,0.9,1);
    drawCSq();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.9,0.14,0);
    glScalef(0.45,0.6,1.0);
    drawCTrap();
  glPopMatrix();

  glPopMatrix();
}

static void drawV(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(-0.2,-0.1,0);
    glScalef(1,1.1,1);

  glPushMatrix();
    glTranslatef(0,-0.1,0);
    glScalef(0.75,0.85,1);
    drawCSq();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.95,0.2,0);
    glScalef(0.45,0.6,1.0);
    drawCTrap();
  glPopMatrix();
  
  glPopMatrix();
}

static void drawU(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0.1,0.8,0.25);
    glScalef(0.8,0.9,1);
    drawCOC();
    drawCOC1();
  glPopMatrix();
}

static void drawP(void){
  
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(-0.2,0,0.25);
    drawBarf1h();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.3,0.4,0.25);
    glScalef(0.85,0.5,1.0);
    drawOCurveh();
  glPopMatrix();
}
static void drawO(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0.1,0,0.25);
    drawOCurveh();
  glPushMatrix();
    glScaled(-1,1,1);
    glTranslatef(0.125,0,0);
    drawOCurveh();
  glPopMatrix();
  glPopMatrix();
}

static void drawM(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  
  glPushMatrix();
  glScaled(0.8,0.9,1);
 
  glPushMatrix();
    glTranslatef(1.1,0,0.25);
    glScalef(0.5,1,1);
    drawBarf2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-0.5,0,0);
    glScalef(-0.8,1,1);
    drawCTrap();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-1.1,-0.3,0);
    glScalef(-0.6,-0.9,1);
    drawCTrap1();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.4,0.1,0);
    glScalef(0.6,1,1);
    glRotated(-37,0,0,1);
    drawTrap();
  glPopMatrix();

  glPopMatrix();
}

static void drawN(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  
  glPushMatrix();
  glScaled(0.9,1,1);
  glPushMatrix();
    glScaled(0.75,1,1);
    drawCParl();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1.1,0.25,0);
    glScalef(0.5,0.85,1.0);
    drawCTrap1();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(-1.1,-0.25,0);
    glScalef(-0.5,-0.85,1.0);
    drawCTrap1();
  glPopMatrix();
  glPopMatrix();
}

static void drawH(void){
  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(-0.5,0,0.25);
    drawBarf2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.7,0,0.25);
    glScalef(-0.8,1,1);
    drawBarf2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.07,0,0.25);
    glScalef(0.25,0.25,1);
    drawRect();
  glPopMatrix();
}

static void drawG(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(0.05,0,0.25);
    glScalef(-1.25,1,1);
    drawOCurveh();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.15,0.35,0);
    glScalef(0.5,0.6,1);
    drawCTad();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.05,-0.2,0.25);
    glScalef(0.75,0.4,1);
    drawCOC1();
  glPopMatrix();
}
static void drawF(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(-0.25,0,0.25);
    glScaled(1,1,1);
    drawBarf1h();
  glPopMatrix();

 
  glPushMatrix();
    glTranslatef(0.25,0.4,0);
    glScalef(0.5,0.5,1);
    drawCTad();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.25,-0.25,0);
    glScalef(0.25,0.25,1);
    drawCTad();
  glPopMatrix();
}

static void drawE(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(-0.25,0,0.25);
    glScaled(1,1,1);
    drawBarh2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.25,0.4,0);
    glScalef(0.5,0.5,1);
    drawCTad();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.25,-0.45,0);
    glScalef(0.5,-0.45,1);
    drawCTad();
  glPopMatrix();
  
  glPushMatrix();
    glTranslatef(0.25,-0.25,0);
    glScalef(0.25,0.25,1);
    drawCTad();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.25,0.25,0);
    glScalef(0.25,-0.25,1);
    drawCTad();
  glPopMatrix();
}

static void drawD(void){
  if(LGT) glColor4fv(g);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(-0.25,0,0.25);
    drawBarh2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.25,0,0.25);
    glScalef(1.0,0.9,1.0);
    drawOCurveh();
  glPopMatrix();
}

static void drawC(void){
  if(LGT) glColor4fv(y);
  else glColor4fv(n);
  glPushMatrix();
    glTranslatef(0.25,0,0.25);
    glScalef(-1.25,1,1);
    drawOCurveh();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.35,0.45,0);
    glScalef(0.5,0.5,1);
    drawCTad();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.35,-0.45,0);
    glScalef(0.5,-0.45,1);
    drawCTad();
  glPopMatrix();
}


static void drawB(void){
  if(LGT) glColor4fv(r);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslatef(-0.25,0,0.25);
    drawBarh2();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.25,0.5,0.25);
    glScalef(0.75,0.4,1.0);
    drawOCurveh();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.25,-0.5,0.25);
    glScalef(0.75,0.5,1.0);
    drawOCurveh();
  glPopMatrix();
}

static void drawA(void){
  if(LGT) glColor4fv(b);
  else glColor4fv(n);
  
  glPushMatrix();
    glTranslated(0.5,0,0);
    glScalef(0.75,1,1);
    drawCSq1();
  glPopMatrix();

  glPushMatrix();
    glTranslated(-0.75,0,0);
    glScalef(-0.5,-1,1);
    drawCTrap();
  glPopMatrix();

  glPushMatrix();
    glTranslated(0,-0.4,0);
    glScaled(0.5,1,1);
    glRotated(90,0,0,1);
    drawTrap();
  glPopMatrix();
}