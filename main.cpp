#include<windows.h>
#include <GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>


static GLfloat spin = 0.0;//spin korar jnne initial degree
static float	tx	=  0.0;
static float	ty	=  0.0;
int cc = 0;
int flag = 0,served = 0, colorcount = 0;
int songCount = 0;
float color[8][3] = {{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{0.3,0.7,0.1},{.5,.8,.9}};

void drawTable(){
    glPushMatrix();
    glColor3f(0,0,0);
    glRectf(-80,-65,0,-63);
    glColor3f(1,0,0);
    glRectf(-80,-63,0,-35);
    glColor3f(1,1,0);
    glRectf(-80,-35,0,-30);
    glPopMatrix();
}

void drawCircle(float rx, float ry, int half){
    glPushMatrix();
    glPointSize(3);
    glBegin(GL_POLYGON);
    int i;
    int len = 360;
    if(half == 1)   len = 180;
    for(i=0; i<len; i++){
        float theta = (i*3.1416)/180.0;
        glVertex2f(rx*cos(theta), ry*sin(theta)*(1366.0/768.0));
    }
    glEnd();
    glPopMatrix();
}

void drawFloor(){
    glColor3f(255.0/255.0, 236.0/255.0, 139.0/255.0);
    glRectf(-100,-100,100,-60);
}

void drawWindowTree(){
    int x = 5, y = 7;
    glPushMatrix();
    glColor3f(0,1,0);
    glRectf(-2,-6,30,4);
    glRectf(4.5,4,25,15);

    glPushMatrix();
    glRotatef(90,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,5,0);
    glRotatef(60,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(10,10,0);
    glRotatef(30,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(15,15,0);
    glRotatef(0,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(20,10,0);
    glRotatef(330,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(25,5,0);
    glRotatef(300,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(30,0,0);
    glRotatef(270,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();
    glPopMatrix();
}

void drawCloud1(){
    int x = 3, y = 3;
    glPushMatrix();
    glColor3f(1,1,1);
    glRectf(-1,-2.94,6,0);
    glRectf(-1,0,6,2.5);
    //glRectf(-2,-6,30,4);
    //glRectf(4.5,4,25,15);

    glPushMatrix();
    glRotatef(90,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,1,0);
    glRotatef(60,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2,2,0);
    glRotatef(30,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,3,0);
    glRotatef(0,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,2,0);
    glRotatef(330,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,1,0);
    glRotatef(300,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(6,0,0);
    glRotatef(270,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();
    glPopMatrix();
}


void drawCloud2(){
    float x = 1.5, y = 1.5;
    glPushMatrix();
    glColor3f(1,1,1);
    glRectf(-1,-1.4,6,0);
    glRectf(-1,0,6,2.5);
    //glRectf(-2,-6,30,4);
    //glRectf(4.5,4,25,15);

    glPushMatrix();
    glRotatef(90,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,1,0);
    glRotatef(60,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2,2,0);
    glRotatef(30,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,3,0);
    glRotatef(0,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,2,0);
    glRotatef(330,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,1,0);
    glRotatef(300,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(6,0,0);
    glRotatef(270,0,0,1);
    drawCircle(x,y,1);
    glPopMatrix();
    glPopMatrix();
}

void drawWindow(){
    glPushMatrix();
    glColor3f(139.0/255.0, 105.0/255.0, 20.0/255.0);
    glRectf(20,-55,80,95);
    glColor3f(176.0/255.0, 224.0/255.0, 230.0/255.0 );
    glRectf(21,-53.5,79,45);
    glRectf(21,46.5,79,93.5);
    glColor3f(176.0/255.0, 196.0/255.0, 222.0/255.0 );
    glBegin(GL_POLYGON);
    glVertex2f(21,-53.5);
    glVertex2f(79,-53.5);
    glVertex2f(79,45);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(21,46.5);
    glVertex2f(79,46.5);
    glVertex2f(79,93.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(34.5,-47.5,0);
    drawWindowTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,30,0);
    drawCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,35,0);
    drawCloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(66,25,0);
    drawCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25,80,0);
    drawCloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,75,0);
    drawCloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,60,0);
    drawCloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(68,70,0);
    drawCloud2();
    glPopMatrix();
}

void drawBurger(){
    glColor3f(1, 165.0/255.0, 0 );
    drawCircle(7,6,1);

    glPushMatrix();
    glTranslatef(-4,3,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,4,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,6,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,6,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,3,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glColor3f(1, 0, 0 );
    glRectf(-6.7,-1.5,6.7,0);
    glColor3f(0, 1, 0 );
    glRectf(-6.9,-2.5,6.9,-1.5);
    glColor3f(139.0/255.0, 69.0/255.0, 19.0/255.0 );
    glRectf(-6.9,-5.5,6.9,-2.5);
    glColor3f(1, 1, 0 );
    glRectf(-6.9,-6.5,6.9,-5.5);
    glColor3f(205.0/255.0, 173.0/255.0 , 0 );
    glPushMatrix();
    glTranslated(0,-6.5,0);
    glRotated(180,0,0,1);
    drawCircle(7,1.5,1);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-5,-6.5);
    glVertex2f(-3,-7.5);
    glVertex2f(-1,-6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(1,-6.5);
    glVertex2f(3,-7.5);
    glVertex2f(5,-6.5);
    glEnd();

    glColor3f(0,1,0);
    float xx = -6.9;
    for(;;){
        glBegin(GL_POLYGON);
        glVertex2f(xx,-2.5);
        glVertex2f(xx+.5, -3);
        glVertex2f(xx+1.0, -2.5);
        glEnd();
        xx = xx + 1.0;
        if(xx > 6.9)    break;
    }

}

void drawFrenchFry(){
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5,-1);
    glVertex2f(-4.0,6);
    glVertex2f(-2.5,6);
    glVertex2f(-2.0,8);
    glVertex2f(-0.5,8);

    glEnd();

    glColor3f(139.0/255.0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-5,0);
    glVertex2f(-2.5,-11);
    glVertex2f(2.5,-11);
    glVertex2f(5,0);
    glEnd();

    glColor3f(1,1,1);
    glRotatef(180,0,0,1);
    drawCircle(5,2,1);


}

void drawCoke(){
    ///pipe
    glColor3f(.8,.2,.05);
    glRectf(-6,9,-2.0,10);
    glBegin(GL_POLYGON);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-1,10);
    glVertex2f(-0.5,0);
    glVertex2f(0.5,0);
    glVertex2f(-2,10);
    glEnd();///pipe

    glColor3f(139.0/255.0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-4,0);
    glVertex2f(-2.5,-18);
    glVertex2f(2.5,-18);
    glVertex2f(4,0);
    glEnd();

    glColor3f(1,0,0);
    glRectf(-4.5,0,4.5,2.0);
}

void drawSignBoard(){
    glPushMatrix();
    glColor3f(139.0/255.0, 69.0/255.0, 19.0/255.0 );
    glRectf(-70,28,-10,80);
    ///glColor3f(199.0/255.0,179.0/255.0,179.0/255.0);
    glColor3f(.9,.9,.9);
    glRectf(-69,30,-11,78);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-58,50,0);
    drawBurger();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40,60,0);
    drawCoke();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-23,50,0);
    drawBurger();
    glPopMatrix();
}

void drawUpperDecoration(){
    float r1 = 3.2;
    float r2 = 2.3;
    glColor3f(0,0,0);
    glRectf(-100,80,100,100);
    glBegin(GL_QUADS);
    glVertex2f(-75,80);
    glVertex2f(-52,-30);
    glVertex2f(-28,-30);
    glVertex2f(-5,80);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15,80);
    glVertex2f(20,70);
    glVertex2f(80,70);
    glVertex2f(85,80);
    glEnd();

    glPushMatrix();
    glTranslatef(-95,80,0);
    ///glColor3f(201.0/255.0,201.0/255.0,201.0/255.0);
    glColor3f(color[0][0],color[0][1],color[0][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-87,80,0);
    glColor3f(color[1][0],color[1][1],color[1][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-79,80,0);
    glColor3f(color[2][0],color[2][1],color[2][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,80,0);
    glColor3f(color[3][0],color[3][1],color[3][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5,80,0);
    glColor3f(color[4][0],color[4][1],color[4][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15.5,80,0);
    glColor3f(color[5][0],color[5][1],color[5][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(87,80,0);
    glColor3f(color[6][0],color[6][1],color[6][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(95,80,0);
    glColor3f(color[7][0],color[7][1],color[7][2]);
    drawCircle(r1,r1,0);
    glColor3f(1,1,1);
    drawCircle(r2,r2,0);
    glPopMatrix();
}

void drawChairTable(){
    glColor3f(201.0/255.0,201.0/255.0,201.0/255.0);
    glRectf(0,0,3,30);
    glRectf(12,0,15,30);
    glColor3f(1,0,0);
    glRectf(-1.5,30,16.5,35);

    glColor3f(0,0,0);
    glRectf(-1,5,0,20);
    glRectf(-10,5,-9,20);
    glPushMatrix();
    glTranslated(1.75,0,0);
    glRotatef(5,0,0,1);
    glRectf(-10,20,-9,40);
    glPopMatrix();

    glColor3f(1,0,0);
    glRectf(-9.1,20,0,22);
    glColor3f(0,0,0);
    glRectf(-9.1,22,0,23);

    glColor3f(0,0,0);
    glRectf(15,5,16,20);
    glRectf(25,5,26,20);
    glPushMatrix();
    glTranslated(-2.75,0,0);
    glRotatef(-5,0,0,1);
    glRectf(26,20,27,40);
    glPopMatrix();
    glColor3f(1,0,0);
    glRectf(15,20,25.3,22);
    glColor3f(0,0,0);
    glRectf(15,22,25.3,23);
}

void drawClock(){
    glColor3f(0,0,0);
    drawCircle(6.5,6.5,0);
    glColor3f(1,1,1);
    drawCircle(5.7,5.7,0);
    glColor3f(0,0,0);
    glRectf(0,0,4.8,.8);
    glRectf(0,0,.6,5.2);
    glPushMatrix();
    glTranslatef(.3,.3,0);
    drawCircle(.5,.5,0);
    glPopMatrix();
}

void drawLeaf(int x){
    glColor3f(0,1,0);
    glPushMatrix();
    glRotatef(180,0,0,1);
    drawCircle(3,2.5,1);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-3,-.5);
    glVertex2f(3,-.5);
    glVertex2f(0,x);
    glEnd();
}

void drawTree(){
    glColor3f(.2,.8,.2);
    glRectf(-1,0,-.4,35);
    glPushMatrix();
    glTranslatef(-.7,35,0);
    drawLeaf(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.1,21,0);
    glRotatef(55,0,0,1);
    glColor3f(.2,.8,.2);
    glRectf(-1,5,-.4,10);
    glPushMatrix();
    glTranslatef(-.7,10,0);
    drawLeaf(4);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,25,0);
    glRotatef(150,0,0,1);
    glColor3f(.2,.8,.2);
    glRectf(-1,5,-.4,10);
    glPushMatrix();
    glTranslatef(-.7,10,0);
    drawLeaf(4);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.2,28,0);
    glRotatef(-120,0,0,1);
    glColor3f(.2,.8,.2);
    glRectf(-1,5,-.4,10);
    glPushMatrix();
    glTranslatef(-.7,10,0);
    drawLeaf(4);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2,5,0);
    glRotatef(-40,0,0,1);
    glColor3f(.2,.8,.2);
    glRectf(-1,5,-.4,10);
    glPushMatrix();
    glTranslatef(-.7,10,0);
    drawLeaf(4);
    glPopMatrix();
    glPopMatrix();
}

void drawTab(){
    ///glColor3f(201.0/255.0,201.0/255.0,201.0/255.0);
    glColor3f(1,1,1);
    drawCircle(6,1,0);
    glPushMatrix();
    glRotatef(180,0,0,1);
    drawCircle(6,6,1);
    glPopMatrix();

    glColor3f(0,0,0);
    drawCircle(5,.6,0);

    glPushMatrix();
    glRotatef(6,0,0,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-6,0,0,1);
    drawTree();
    glPopMatrix();
}

void drawTableComponents(){
    glColor3f(0,0,0);
    glRectf(0,0,4,7);
    glColor3f(181/255.0,179.0/255.0,179.0/255.0);
    glRectf(.5,0,3.5,6.2);
    glColor3f(0,0,0);
    glRectf(-1,6.2,5,14.5);
    glColor3f(181/255.0,179.0/255.0,179.0/255.0);
    glRectf(-.5,10.5,4.5,13.5);

    glPushMatrix();
    glTranslatef(5.5,2.6,0);
    glColor3f(0,0,0);
    drawCircle(1.3,1.3,0);
    glColor3f(181/255.0,179.0/255.0,179.0/255.0);
    drawCircle(.7,.7,0);
    glPopMatrix();
}


void b1(){
    ///Last Bun
    glColor3f(205.0/255.0, 173.0/255.0 , 0 );
    glPushMatrix();
    glTranslated(0,-6.5,0);
    glRotated(180,0,0,1);
    drawCircle(7,1.5,1);
    glPopMatrix();///***
}

void b2(){
    ///yellow
    glColor3f(1, 1, 0 );
    glRectf(-6.9,-6.5,6.9,-5.5);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(-5,-6.5);
    glVertex2f(-3,-7.5);
    glVertex2f(-1,-6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(1,-6.5);
    glVertex2f(3,-7.5);
    glVertex2f(5,-6.5);
    glEnd();///***
}

void b3(){
    ///borwn
    glColor3f(139.0/255.0, 69.0/255.0, 19.0/255.0 );
    glRectf(-6.9,-5.5,6.9,-2.5);///***
}

void b4(){
    glColor3f(0, 1, 0 );
    glRectf(-6.9,-2.5,6.9,-1.5);
    glColor3f(0,1,0);
    float xx = -6.9;
    for(;;){
        glBegin(GL_POLYGON);
        glVertex2f(xx,-2.5);
        glVertex2f(xx+.5, -3);
        glVertex2f(xx+1.0, -2.5);
        glEnd();
        xx = xx + 1.0;
        if(xx > 6.9)    break;
    }
}

void b5(){
    ///Red
    glColor3f(1, 0, 0 );
    glRectf(-6.7,-1.5,6.7,0);///***
}

void b7(){
    ///burger dots
    glPushMatrix();
    glTranslatef(-4,3,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,4,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,6,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,6,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,3,0);
    glColor3f(1,1,1);
    drawCircle(.8,.3,0);
    glPopMatrix();///***
}

void b6(){
    ///burgerbun
    glColor3f(1, 165.0/255.0, 0 );
    drawCircle(7,6,1);///***
}

void drawBurgerAnimation(){
    if(cc==1)   b1();
    if(cc==2){
        b1();
        b2();
    }
    if(cc==3){
        b1();
        b2();
        b3();
    }
    if(cc==4){
        b1();
        b2();
        b3();
        b4();
    }
    if(cc==5){
        b1();
        b2();
        b3();
        b4();
        b5();
    }
    if(cc==6){
        b1();
        b2();
        b3();
        b4();
        b5();
        b6();
    }
    if(cc==7){
        b1();
        b2();
        b3();
        b4();
        b5();
        b6();
        b7();
    }
    if(cc==8){
        cc =0;
    }
}

void drawSineCurve(float a){
    int i;
    glPointSize(3.5);
    glBegin(GL_POINTS);
    for(i=0; i<360; i++){
        float theta = (i*3.1416*3)/180;
        glVertex2f( -a*(1368/766) * sin(.6*theta), theta);
    }
    glEnd();
}

void drawSmoke(){
    glPushMatrix();
    glRotatef(20,0,0,1);
    drawSineCurve(1.5);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-20,0,0,1);
    drawSineCurve(-1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.8,7,0);
    drawSineCurve(-1.5);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    if(songCount == 0){
        PlaySound("Song.wav", NULL, SND_FILENAME| SND_ASYNC);
    }
    songCount++;
    if(songCount == 8000)   songCount = 0;
    drawUpperDecoration();
    drawFloor();
    drawTable();
    drawWindow();
    drawSignBoard();
    glPushMatrix();
    glTranslatef(33,-70,0);
    drawChairTable();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,48,0);
    drawClock();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-55,0);
    drawTab();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(90,-55,0);
    drawTab();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-90,-55,0);
    drawTab();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-70,-30,0);
    drawTableComponents();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-14,-30,0);
    drawTableComponents();
    glPopMatrix();

    glPushMatrix();
    if(flag == 1){
        tx +=.2;
        if(tx > 79.2){
            flag = 0;
            ty = ty-5.0;
            served = 1;
        }
    }
    glTranslatef(tx -39.5,ty-21,0);
    drawBurgerAnimation();
    glPopMatrix();

    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glPointSize(1);
    glVertex2d(0,0);
    glEnd();
	glFlush();
}

void init(void)
{
	glClearColor (66.0/255.0, 66.0/255.0, 66.0/255.0,0.0 );
	//glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			cc++;
			tx = 0.0;
			ty = 0.0;
			glutPostRedisplay();
			served = 0;
			break;

		case 's':
		    if(cc == 7 && served == 0){
                flag = 1;
		    }
			 //glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            //glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			//glutIdleFunc(spinDisplay_right);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}


void my_reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100); ///making a coordinate system
    glMatrixMode(GL_MODELVIEW);

}

void changeColor(){
    float a,b,c;
    a = color[7][0];
    b = color[7][1];
    c = color[7][2];
    int i;
    for(i=6; i>=0; i--){
        color[i+1][0] = color[i][0];
        color[i+1][1] = color[i][1];
        color[i+1][2] = color[i][2];
    }
    color[0][0] = a;
    color[0][1] = b;
    color[0][2] = c;
    if(colorcount > 320){
        colorcount=0;
    }

    ///printf("Changed!\n");
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    colorcount++;
    if(colorcount%40 == 0){
        changeColor();
    }
}


int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1366, 768);
	//glutInitWindowPosition (100, 100);
	glutCreateWindow ("Swapnil's Burger House");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutReshapeFunc(my_reshape);
	glutTimerFunc(0, timer,0);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

