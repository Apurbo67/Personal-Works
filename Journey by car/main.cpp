#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

GLfloat pos1=0.0f;
GLfloat pos2=-2.0f;


float cloudPosition=0;
float cloudspeed=0.005;

float birdPosition=0;
float birdSpeed=0.01;


bool isCity=true;
bool isVillage=false;


GLfloat carPosition = -0.9f;
GLfloat roadPostion = 0.0f;
GLfloat carSpeed = 0.005f;
GLfloat roadSpeed = 0.02f;
GLfloat sunPosition=0.8f;
GLfloat sunSpeed=0.01f;
GLfloat moonPosition=0.2f;
GLfloat moonSpeed=0.01f;
GLfloat angle=0;
GLboolean day=true;
bool railLineApears=false;
bool trainLeft=false;
bool carWheelMove=true;

void update(int value) {

    cloudPosition +=0.005;
    if(cloudPosition>=1)
    {
        cloudPosition=-1;
    }
    birdPosition+=0.01;;
    if(birdPosition>=1)
    {
        birdPosition=-1;
    }
    if(carPosition >-0.5)
    {
        carSpeed=0;
    }

    if(roadPostion>1.0)
    {
        roadPostion = -1.0f;
    }
    if(sunPosition<0.3f && day == true)
    {
        sunPosition=1.2f;
        day=false;
    }
    if(moonPosition>1.2f && day == false)
    {
        moonPosition=0.3f;
        day=true;
    }
    angle+=45;
    if(angle==360)
    {
        angle=0;
    }

    carPosition+=carSpeed;
    roadPostion+=roadSpeed;
    if(day==true)
    {
        sunPosition-=sunSpeed;
    }
    else
    {
        moonPosition+=moonSpeed;
    }

    if(pos1>=2.0f)
    {
        pos1=-2.0f;
        pos2=0.0f;
    }
    if(pos2>=2.0f)
    {
        pos2=-2.0f;
        pos1=0.0f;
    }

    pos1=pos1+roadSpeed;
    pos2=pos2+roadSpeed;



    //if(traing)
    //trainPosition += speed;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}





void circle(float xc, float yc, float r)
{
    float x=0;
    float y=r;
    int n=7;
    glBegin(GL_POLYGON);
    for(int i=0; i<=n; i++)
    {
        glVertex2f(x+xc,y+yc);
        x=r*sin(3.1416/(2*n)*i);
        y=r*cos(3.1416/(2*n)*i);
    }
    for(int i=n; i>=0; i--)
    {
        glVertex2f(x+xc,-y+yc);
        x=r*sin(3.1416/(2*n)*i);
        y=r*cos(3.1416/(2*n)*i);
    }
    for(int i=0; i<=n; i++)
    {
        glVertex2f(-x+xc,-y+yc);
        x=r*sin(3.1416/(2*n)*i);
        y=r*cos(3.1416/(2*n)*i);
    }
    for(int i=n; i>=0; i--)
    {
        glVertex2f(-x+xc,y+yc);
        x=r*sin(3.1416/(2*n)*i);
        y=r*cos(3.1416/(2*n)*i);
    }
    glEnd();
}

void cloud(float xc, float yc)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(xc, yc+0.05, 0.1f);
    //circle(x-0.1, y, 0.2f);
    //circle(x+0.1, y, 0.2f);
    circle(xc-0.1, yc-0.05, 0.1f);
    circle(xc+0.1, yc-0.05, 0.1f);
    circle(xc, yc-0.1, 0.1f);
}

void roadLine(float xp, float yp, float length)
{
    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 1.00f);

    glVertex2f(-(length/2)+0.02 +xp, yp+0.01);
    glVertex2f(-(length/2) +xp, yp-0.01);
    glVertex2f( (length/2) +xp, yp-0.01);
    glVertex2f( (length/2)+0.02 +xp, yp+0.01);

    glEnd();
}
void roadLines()
{
    roadLine(-0.9f, -0.2f, 0.2f);
    roadLine(-0.6f, -0.2f, 0.2f);
    roadLine(-0.3f, -0.2f, 0.2f);
    roadLine( 0.0f, -0.2f, 0.2f);
    roadLine( 0.3f, -0.2f, 0.2f);
    roadLine( 0.6f, -0.2f, 0.2f);
}
void tree(float xp, float yp)
{
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.18f, 0.18f);
    glVertex2f(-0.10f +xp,  0.0f +yp);
    glVertex2f( 0.10f +xp,  0.0f +yp);
    glVertex2f( 0.05f +xp,  0.05f +yp);
    glVertex2f(-0.05f +xp,  0.05f +yp);

    glVertex2f( 0.05f +xp,  0.2f +yp);
    glVertex2f(-0.05f +xp,  0.2f +yp);
    glVertex2f(-0.05f +xp,  0.05f +yp);
    glVertex2f( 0.05f +xp,  0.05f +yp);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    circle(-0.07f +xp,0.25f +yp, 0.07f);
    circle( 0.07f +xp,0.25f +yp, 0.07f);
    circle( 0.00f +xp,0.25f +yp, 0.07f);
    circle( 0.00f +xp,0.35f +yp, 0.1f);
    circle(-0.10f +xp,0.35f +yp, 0.1f);
    circle( 0.10f +xp,0.35f +yp, 0.1f);
    circle( 0.00f +xp,0.45f +yp, 0.1f);
}
void carWheels()
{
    glColor3f(0.9f, 0.9f, 0.9f);
    circle(0.0f, 0.0f, 0.09f);

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.07f);
    glVertex2f(0.07f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.07f);
    glVertex2f(-0.07f, -0.0f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.5f);
    circle(0.0f, 0.0f, 0.02f);
}
void car(float x, float y)
{
    glPushMatrix();
    glScalef(0.6f, 0.6f, 1.0f);

    glColor3f(0.3f, 0.3f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.32f+x,  0.00f+y);
    glVertex2f(-0.32f+x,  0.14f+y);
    glVertex2f(-0.16f+x,  0.16f+y);
    glVertex2f(-0.04f+x,  0.28f+y);
    glVertex2f( 0.20f+x,  0.28f+y);
    glVertex2f( 0.30f+x,  0.19f+y);
    glVertex2f( 0.40f+x,  0.19f+y);
    glVertex2f( 0.44f+x,  0.09f+y);
    glVertex2f( 0.40f+x,  0.00f+y);
    glEnd();

    ///car's glasses
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);


    glVertex2f(-0.16f+x,  0.16f+y);
    glVertex2f(-0.04f+x,  0.28f+y);

    glEnd();

    ///window

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f, 0.0f);

    glVertex2f(-0.14f+x,  0.16f+y);
    glVertex2f(-0.03f+x,  0.26f+y);
    glVertex2f( 0.07f+x,  0.26f+y);
    glVertex2f( 0.06f+x,  0.16f+y);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f( 0.08f+x,  0.16f+y);
    glVertex2f( 0.09f+x,  0.26f+y);
    glVertex2f( 0.19f+x,  0.26f+y);
    glVertex2f( 0.28f+x,  0.19f+y);
    glVertex2f( 0.26f+x,  0.16f+y);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    //circle(-0.16f+x, 0.0f+y, 0.08f);
    //circle( 0.24f+x, 0.0f+y, 0.08f);
    glPushMatrix();
    glTranslatef(-0.16f+x, 0.0f+y, 0.0f);
    if(carWheelMove)
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    carWheels();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.24f+x, 0.0f+y, 0.0f);
    if(carWheelMove)
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    carWheels();
    glPopMatrix();

    glPopMatrix();
}
void trees2()
{
    glPushMatrix();
    //glScalef(0.5f, 0.5f, 0.0f);
    tree( 0.0f,  0.0f);

    tree(-0.5f,  0.0f);
    tree(-1.0f,  0.0f);
    tree(-1.5f,  0.0f);
    tree(-2.0f,  0.0f);

    tree(0.5f,  0.0f);
    tree(1.0f,  0.0f);
    tree(1.5f,  0.0f);
    tree(2.0f,  0.0f);
    glPopMatrix();
}

void skyObject()
{
    ///sun
    glPushMatrix();
    glTranslatef(0.6f,sunPosition, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.08f);
    glPopMatrix();

    ///moon
    glPushMatrix();
    glTranslatef(-0.6f,moonPosition, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.08f);
    glPopMatrix();
}
void cityLand()
{
    ///Land around building
    glBegin(GL_QUADS);
    glColor3f(0.98f, 0.60f, 0.20f);
    glVertex2f(-1.00f,  0.5f);
    glVertex2f(-1.00f, -0.1f);
    glVertex2f( 1.00f, -0.1f);
    glVertex2f( 1.00f,  0.5f);
    glEnd();
}
void villgeLand()
{
    glBegin(GL_QUADS);
    glColor3ub(154,205,50);
    glVertex2f(-1.00f,  0.5f);
    glVertex2f(-1.00f, -0.1f);
    glVertex2f( 1.00f, -0.1f);
    glVertex2f( 1.00f,  0.5f);
    glEnd();
}
void water()
{
    ///water
    glBegin(GL_QUADS);
    if(day)
        glColor3ub(85,206,255);
    else
        glColor3f(0.20f, 0.20f, 0.20f);
    glVertex2f(-1.00f,  0.4f);
    glVertex2f(-1.00f,  1.0f);
    glVertex2f( 1.00f,  1.0f);
    glVertex2f( 1.00f,  0.4f);
    glEnd();
}
void window(float x, float y)
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.04f+x, 0.1f+y);
    glVertex2f(0.12f+x, 0.1f+y);
    glVertex2f(0.12f+x, 0.18f+y);
    glVertex2f(0.04f+x, 0.18f+y);
    glEnd();
}
void building()
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.7f, 0.7f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.0f, 0.6f);

    float x=0.15f;
    float m=1.67f;
    glColor3f(0.7f, 0.0f, 0.7f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.5f+x, 0.6f+x*m);
    glVertex2f(0.5f+x, 0.0f+x*m);

    glColor3f(0.4f, 0.6f, 0.2);
    glColor3ub(220, 88, 42);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.5f+x, 0.6f+x*m);
    glVertex2f(x, 0.6f+x*m);

    glEnd();

    window(0.0f, 0.0f);
    window(0.15f, 0.0f);
    window(0.3f, 0.0f);

    window(0.0f, 0.12f);
    window(0.15f, 0.12f);
    window(0.3f, 0.12f);

    window(0.0f, 0.24f);
    window(0.15f, 0.24f);
    window(0.3f, 0.24f);

    window(0.0f, 0.36f);
    window(0.15f, 0.36f);
    window(0.3f, 0.36f);

    //window(0.0f, 0.45f);
    //window(0.15f, 0.45f);
    //window(0.3f, 0.45f);

    //glPopMatrix();
}

void buildingSc()
{
    glPushMatrix();
    glScalef(0.5f, 0.5f, 1.0f);
    building();
    glPopMatrix();
}
buildings()
{

    ///row 1 col 1
    glPushMatrix();
    glTranslatef(-0.9f+0.36f/1.67f, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    ///row 2 col 1
    glPushMatrix();
    glTranslatef(-0.9+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    ///row 3 col 1
    glPushMatrix();
    glTranslatef(-0.9f, 0.0f, 0.0f);
    //buildingSc();
    glPopMatrix();

    ///row 1 col 2
    glPushMatrix();
    glTranslatef(-0.6+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    ///row 2 col 2
    glPushMatrix();
    glTranslatef(-0.6+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    ///row 3 col 2
    glPushMatrix();
    glTranslatef(-0.6f, 0.0f, 0.0f);
    //buildingSc();
    glPopMatrix();

    ///row 1 col 3
    glPushMatrix();
    glTranslatef(-0.3+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 0.0f, 0.0f);
    //buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    //buildingSc();
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.0, -0.05);
    glVertex2f(0.37/1.67, 0.32);
    glVertex2f(0.37/1.67+0.25, 0.32);
    glVertex2f(0.25, -0.05);
    glEnd();

    glPushMatrix();
    glTranslatef(0.3+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3+0.2/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    //buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    //buildingSc();
    glPopMatrix();

}

void boat(){


        glPushMatrix();
        glTranslatef(-0.5, 0.0f, 0.0f);
        glPushMatrix();
        glScalef(0.0015f, 0.0015f, 1.00f);

    glColor3ub(30,30,30);
    glBegin(GL_POLYGON);
    glVertex2f(100,50);
    glVertex2f(0,100);
    glVertex2f(400,100);
    glVertex2f(300,50);
    glEnd();

    glColor3ub(155,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(50,100);
    glVertex2f(50,120);
    glVertex2f(350,120);
    glVertex2f(350,100);
    glEnd();

    glColor3ub(10,30,128);
    glBegin(GL_POLYGON);
    glVertex2f(70,120);
    glVertex2f(70,140);
    glVertex2f(330,140);
    glVertex2f(330,120);
    glEnd();

    glColor3ub(255,155,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();

    glPushMatrix();
    glTranslatef(50,0,1);
    glColor3ub(255,120,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,0,1);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,0,1);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();

    glPushMatrix();
    glTranslatef(75,0,0);

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,0,0);

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);

    glEnd();
    glPopMatrix();

        glPopMatrix();
        glPopMatrix();

}


float getX(float x){

return x/750.00;

}

float getY(float y){

return y/400.00;

}

float getR(float x){

return x/255.00;

}

float getG(float y){

return y/255.00;

}



float getB(float x){

return x/255.00;

}

void mosque()
{

    ///right side wall
    glBegin(GL_POLYGON);

    glColor3d(0.1, 0.30, 0.219);
    glVertex2f(getX(-100), getY(36));
    glVertex2f(getX(-70), getY(36+30*1.67));
    glVertex2f(getX(-70), getY(36+30*1.67+114));
    glVertex2f(getX(-100), getY(150));

	glEnd();

    ///top wall
    glBegin(GL_POLYGON);
    glColor3d(0.1, 0.30, 0.219);

    glVertex2f(getX(-350), getY(150));
    glVertex2f(getX(-100), getY(150));
    glVertex2f(getX(-70), getY(36+30*1.67+114));
    glVertex2f(getX(-320), getY(36+30*1.67+114));

	glEnd();

	glColor3f(1,1,1);
	glLineWidth(2.00f);
	glBegin(GL_LINES);

    glVertex2f(getX(-350), getY(150));
    glVertex2f(getX(-100), getY(150));

    glVertex2f(getX(-100), getY(150));
    glVertex2f(getX(-70), getY(36+30*1.67+114));

    glVertex2f(getX(-70), getY(36+30*1.67+114));
    glVertex2f(getX(-320), getY(36+30*1.67+114));

    glVertex2f(getX(-320), getY(36+30*1.67+114));
    glVertex2f(getX(-350), getY(150));

    glVertex2f(getX(-100), getY(36));
    glVertex2f(getX(-70), getY(36+30*1.67));

    glVertex2f(getX(-70), getY(36+30*1.67));
    glVertex2f(getX(-70), getY(36+30*1.67+114));

    glVertex2f(getX(-70), getY(36+30*1.67+114));
    glVertex2f(getX(-100), getY(150));

    glVertex2f(getX(-100), getY(150));
    glVertex2f(getX(-100), getY(36));

    glEnd();

    ///front wall
    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);

        glVertex2f(getX(-350), getY(36));
        glVertex2f(getX(-350), getY(150));
        glVertex2f(getX(-100), getY(150));
        glVertex2f(getX(-100), getY(36));

	glEnd();


    ///mosque door
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex2f(getX(-320-10), getY(38));
        glVertex2f(getX(-320-10), getY(85));
        glVertex2f(getX(-280-10), getY(85));
        glVertex2f(getX(-280-10), getY(38));
	glEnd();

    ///mos door2
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);

        glVertex2f(getX(-320+70), getY(38));

        glVertex2f(getX(-320+70), getY(85));

        glVertex2f(getX(-280+70), getY(85));

        glVertex2f(getX(-280+70), getY(38));
	glEnd();

    glBegin(GL_POLYGON);
     glColor3d(getR(205),getG(133),getB(63));
        glVertex2f(getX(-228), getY(38));
        glVertex2f(getX(-228), getY(85));
        glVertex2f(getX(-232), getY(85));
        glVertex2f(getX(-232), getY(38));
	glEnd();

    ///tomb
    glPushMatrix();
    glTranslatef(-.305,0.23,0.0);
        glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.03;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex2f(getX(-320+150), getY(38));
        glVertex2f(getX(-320+150), getY(85));
        glVertex2f(getX(-280+150), getY(85));
        glVertex2f(getX(-280+150), getY(38));
	glEnd();

    ///mosque line
    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex2f(getX(-350), getY(105));
        glVertex2f(getX(-350), getY(108));
        glVertex2f(getX(-100), getY(108));
        glVertex2f(getX(-100), getY(105));
	glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex2f(getX(-350), getY(105+10));
        glVertex2f(getX(-350), getY(109+10));
        glVertex2f(getX(-100), getY(109+10));
        glVertex2f(getX(-100), getY(105+10));
	glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1,1,1);
        glVertex2f(getX(-350), getY(105+10+10));
        glVertex2f(getX(-350), getY(108+10+10));
        glVertex2f(getX(-100), getY(108+10+10));
        glVertex2f(getX(-100), getY(105+10+10));
	glEnd();

///dome

    glPushMatrix();
    glTranslatef(-.305,0.37,0.0);
        glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.03;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

///beside dome

    glPushMatrix();
    glTranslatef(-.20,0.37,0.0);
    glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.03;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

    ///beside
    glPushMatrix();
    glTranslatef(-.40,0.37,0.0);
        glColor3d(0.18, 0.38, 0.28);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.03;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);
        glVertex2f(getX(-245), getY(155));
        glVertex2f(getX(-245), getY(180));
        glVertex2f(getX(-215), getY(180));
        glVertex2f(getX(-215), getY(155));
	glEnd();

///

    glPushMatrix();
    glTranslatef(-.305,0.45,0.0);
        glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.025;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);
        glVertex2f(getX(-243), getY(185));
        glVertex2f(getX(-243), getY(215));
        glVertex2f(getX(-218), getY(215));
        glVertex2f(getX(-218), getY(185));
	glEnd();

    glPushMatrix();
    glTranslatef(-.305,0.53,0.0);
        glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.023;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);
        glVertex2f(getX(-240), getY(215));
        glVertex2f(getX(-240), getY(245));
        glVertex2f(getX(-220), getY(245));
        glVertex2f(getX(-220), getY(215));
	glEnd();

    glPushMatrix();
    glTranslatef(-.3065,0.62,0.0);
        glColor3d(0.18, 0.38, 0.28);
        glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=.0205;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
        glEnd();
    glPopMatrix();


    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);
        glVertex2f(getX(-238), getY(245));
        glVertex2f(getX(-238), getY(275));
        glVertex2f(getX(-223), getY(275));
        glVertex2f(getX(-223), getY(245));
	glEnd();

    glBegin(GL_POLYGON);
    glColor3d(0.18, 0.38, 0.28);
        glVertex2f(getX(-235), getY(275));
        glVertex2f(getX(-235), getY(285));
        glVertex2f(getX(-228), getY(285));
        glVertex2f(getX(-228), getY(275));
	glEnd();
}



void busstop_top()

{
      //bus stop
    glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(0.380,0.650);
    glVertex2f(0.420,0.710);
    glVertex2f(0.730,0.710);
    glVertex2f(0.700,0.650);
    glEnd();

    glColor3ub(200,200,200);
    glBegin(GL_POLYGON);
    glVertex2f(0.380,0.650);
    glVertex2f(0.380,0.630);
    glVertex2f(0.690,0.630);
    glVertex2f(0.680,0.650);
    glEnd();



    glColor3ub(0.200,0.200,0.200);
    glBegin(GL_POLYGON);
    glVertex2f(0.690,0.630);
    glVertex2f(0.680,0.650);
    glVertex2f(0.730,0.710);
    glVertex2f(0.735,0.685);
    glEnd();
}

void busstop_left()

{

    glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(0.390,0.675);
    glVertex2f(0.390,0.865);
    glVertex2f(0.415,0.895);
    glVertex2f(0.415,0.735);
    glEnd();

}
//bus stop

void busstop()

{
    ///bus stop
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
        glVertex2f(0.380,0.650);
        glVertex2f(0.420,0.750);
        glVertex2f(0.720,0.750);
        glVertex2f(0.680,0.650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
        glVertex2f(0.380,0.650);
        glVertex2f(0.380,0.630);
        glVertex2f(0.690,0.630);
        glVertex2f(0.680,0.650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
        glVertex2f(0.690,0.630);
        glVertex2f(0.680,0.650);
        glVertex2f(0.720,0.750);
        glVertex2f(0.730,0.730);
    glEnd();

    glPushMatrix();
    glTranslatef(0,0.200,0);
    glColor3ub(50,50,80);
        busstop_top();
	glPopMatrix();
	///bus stop left
        busstop_left();
	///bus stop right
	glPushMatrix();
    glTranslatef(0.300,0,0);
        busstop_left();
	glPopMatrix();

}


void buildingsWithMosque()
{

    glPushMatrix();
    glTranslatef(-0.9f+0.36f/1.67f, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.9+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.25, 0.08, 0);
    glScalef(1.6, 1.2, 1);
    mosque();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.0, -0.05);
    glVertex2f(0.37/1.67, 0.32);
    glVertex2f(0.37/1.67+0.25, 0.32);
    glVertex2f(0.25, -0.05);
    glEnd();

    glPushMatrix();
    glTranslatef(0.3+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3+0.2/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6+0.36/1.67, 0.36f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6+0.18/1.67, 0.18f, 0.0f);
    buildingSc();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.35f, -0.6f, 0.0f);
    glScalef(1.8, 1, 1);
    busstop();
    glPopMatrix();

    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.9,-0.);
    glVertex2f(-0.9+0.15/1.67,0.15);
    glVertex2f(-0.05+0.15/1.67,0.15);
    glVertex2f(-0.05,-0.);
    glEnd();

}
void villageHouse()
{
    ///front
    glColor3ub(255,69,0);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 0.4);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.5, 0);
    glEnd();

    ///right
    glColor3f(0.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.7, 0.2*1.67);
    glVertex2f(0.7, 0.4+0.2*1.67);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.5, 0);
    glEnd();

    /// front top
    glColor3ub(255,215,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0.4);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.25, 0.6);
    glEnd();

    ///right top

    glColor3ub(255,69,0);
    glBegin(GL_QUADS);
    glVertex2f(0.25, 0.6);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.7, 0.4+0.2*1.67);
    glVertex2f(0.5, 0.6+0.2*1.67-0.2);
    glEnd();

    ///door
    glColor3f(0.5f, 0.5f, 1.0f);
    glColor3ub(255,215,0);
    glBegin(GL_QUADS);
    glVertex2f(0.56, 0.06*1.67);
    glVertex2f(0.56, 0.06*1.67+0.3);
    glVertex2f(0.64, 0.14*1.67+0.3);
    glVertex2f(0.64, 0.14*1.67);
    glEnd();

    ///left window
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.2);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0.11, 0.2);
    glVertex2f(0.11, 0.3);

    glVertex2f(0.13, 0.2);
    glVertex2f(0.13, 0.3);

    glVertex2f(0.15, 0.2);
    glVertex2f(0.15, 0.3);

    glVertex2f(0.17, 0.2);
    glVertex2f(0.17, 0.3);

    glVertex2f(0.19, 0.2);
    glVertex2f(0.19, 0.3);

    glEnd();

    ///right window
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.4, 0.2);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0.31, 0.2);
    glVertex2f(0.31, 0.3);

    glVertex2f(0.33, 0.2);
    glVertex2f(0.33, 0.3);

    glVertex2f(0.35, 0.2);
    glVertex2f(0.35, 0.3);

    glVertex2f(0.37, 0.2);
    glVertex2f(0.37, 0.3);

    glVertex2f(0.39, 0.2);
    glVertex2f(0.39, 0.3);

    glEnd();

}

void villageHouseSc()
{
    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    villageHouse();
    glPopMatrix();
}
void villageHouse2()
{
    ///front wall
    glColor3f(0.5f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 0.25);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.5, 0);
    glEnd();
    ///left top
    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.25-0.02*0.67);
    glVertex2f(0.485, 0.25-0.02*0.67);
    glVertex2f(0.6, 0.35);
    glVertex2f(0.15, 0.35);
    glEnd();

    ///right side top
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.6, 0.35);
    glVertex2f(0.72, 0.3);
    glEnd();

    ///right side wall
    glColor3f(0.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.5, 0);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.72, 0.3);
    glVertex2f(0.72, 0.08);
    glEnd();

    ///left bottom side
    glColor3f(0.2, 0.2, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0);
    glVertex2f(0.72, 0.08);
    glVertex2f(0.75, 0.05);
    glVertex2f(0.5, -0.05);
    glEnd();
    ///right bottom side
    glColor3f(0.2, 0.2, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0.5, 0);
    glVertex2f(0.5, -0.05);
    glVertex2f(-0.02, -0.05);
    glEnd();

    ///door
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.2, 0);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.3, 0.15);
    glVertex2f(0.3, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_LINES);

    glVertex2f(0.2, 0);
    glVertex2f(0.2, 0.15);

    glVertex2f(0.2, 0.15);
    glVertex2f(0.3, 0.15);

    glVertex2f(0.3, 0.15);
    glVertex2f(0.3, 0);

    glVertex2f(0.3, 0);
    glVertex2f(0.2, 0);

    glEnd();

    ///left front window
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.05, 0.10);
    glVertex2f(0.05, 0.16);
    glVertex2f(0.15, 0.16);
    glVertex2f(0.15, 0.10);
    glEnd();

    ///border
    glColor3f(0, 0, 0);
    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_LINES);

    glVertex2f(0.05, 0.10);
    glVertex2f(0.05, 0.16);

    glVertex2f(0.05, 0.16);
    glVertex2f(0.15, 0.16);

    glVertex2f(0.15, 0.16);
    glVertex2f(0.15, 0.10);

    glVertex2f(0.15, 0.10);
    glVertex2f(0.05, 0.10);
    glEnd();

    ///grill
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0.06, 0.10);
    glVertex2f(0.06, 0.16);

    glBegin(GL_LINES);
    glVertex2f(0.08, 0.10);
    glVertex2f(0.08, 0.16);

    glBegin(GL_LINES);
    glVertex2f(0.1, 0.10);
    glVertex2f(0.1, 0.16);


    glBegin(GL_LINES);
    glVertex2f(0.12, 0.10);
    glVertex2f(0.12, 0.16);


    glVertex2f(0.14, 0.16);
    glVertex2f(0.14, 0.10);
    glEnd();



    ///right front window
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.35, 0.10);
    glVertex2f(0.35, 0.16);
    glVertex2f(0.45, 0.16);
    glVertex2f(0.45, 0.10);
    glEnd();

    ///grill
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0.36, 0.10);
    glVertex2f(0.36, 0.16);

    glBegin(GL_LINES);
    glVertex2f(0.38, 0.10);
    glVertex2f(0.38, 0.16);

    glBegin(GL_LINES);
    glVertex2f(0.4, 0.10);
    glVertex2f(0.4, 0.16);


    glBegin(GL_LINES);
    glVertex2f(0.42, 0.10);
    glVertex2f(0.42, 0.16);


    glVertex2f(0.44, 0.16);
    glVertex2f(0.44, 0.10);
    glEnd();

    ///right side window
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.56, 0.1);
    glVertex2f(0.56, 0.2);
    glVertex2f(0.66, 0.2+0.1*0.23);
    glVertex2f(0.66, 0.1+0.1*0.23+0.01);
    glEnd();

    ///grill
    glColor3f(0,0,0);
    glBegin(GL_LINES);

    glVertex2f(0.57, 0.2+0.01*0.23);
    glVertex2f(0.57, 0.1+0.01*0.23);

    glVertex2f(0.585, 0.2+0.025*0.23);
    glVertex2f(0.585, 0.1+0.025*0.23);

    glVertex2f(0.6, 0.2+0.04*0.23);
    glVertex2f(0.6, 0.1+0.04*0.23);

    glVertex2f(0.615, 0.2+0.055*0.23);
    glVertex2f(0.615, 0.1+0.055*0.23+0.005);

    glVertex2f(0.63, 0.2+0.07*0.23);
    glVertex2f(0.63, 0.1+0.07*0.23+0.005);

    glVertex2f(0.645, 0.2+0.085*0.23);
    glVertex2f(0.645, 0.1+0.085*0.23+0.005);

    glEnd();

}
void river1()
{
    ///upper side green field
    glColor3ub(50,255,50);
    glColor3ub(154,205,50);
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.38);
    glVertex2f( 1, -0.38);
    glVertex2f( 1, -1);
    glVertex2f(-1, -1);
    glEnd();

    /// river bank side water
    glColor3ub(100,149,237);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1, -0.5);//1
    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.8, -0.5);

    glVertex2f(-0.8, -0.5);//2
    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.6, -0.5);

    glVertex2f(-0.6, -0.5);//3
    glVertex2f(-0.5, -0.45);
    glVertex2f(-0.4, -0.5);

    glVertex2f(-0.4, -0.5);//4
    glVertex2f(-0.3, -0.45);
    glVertex2f(-0.2, -0.5);

    glVertex2f(-0.2, -0.5);//5
    glVertex2f(-0.1, -0.45);
    glVertex2f( 0.0, -0.5);

    glVertex2f( 0.0, -0.5);//6
    glVertex2f( 0.1, -0.45);
    glVertex2f( 0.2, -0.5);

    glVertex2f( 0.2, -0.5);//7
    glVertex2f( 0.3, -0.45);
    glVertex2f( 0.4, -0.5);

    glVertex2f( 0.4, -0.5);
    glVertex2f( 0.5, -0.45);
    glVertex2f( 0.6, -0.5);

    glVertex2f( 0.6, -0.5);
    glVertex2f( 0.7, -0.45);
    glVertex2f( 0.8, -0.5);

    glVertex2f( 0.8, -0.5);
    glVertex2f( 0.9, -0.45);
    glVertex2f( 1.0, -0.5);
    glEnd();

    ///river bank
    glLineWidth(3);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-1, -0.5);//1
    glVertex2f(-0.9, -0.45);

    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.8, -0.5);

    glVertex2f(-0.8, -0.5);//2
    glVertex2f(-0.7, -0.45);

    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.6, -0.5);

    glVertex2f(-0.6, -0.5);//3
    glVertex2f(-0.5, -0.45);

    glVertex2f(-0.5, -0.45);
    glVertex2f(-0.4, -0.5);

    glVertex2f(-0.4, -0.5);//4
    glVertex2f(-0.3, -0.45);

    glVertex2f(-0.3, -0.45);
    glVertex2f(-0.2, -0.5);

    glVertex2f(-0.2, -0.5);//5
    glVertex2f(-0.1, -0.45);

    glVertex2f(-0.1, -0.45);
    glVertex2f( 0.0, -0.5);

    glVertex2f( 0.0, -0.5);//6
    glVertex2f( 0.1, -0.45);

    glVertex2f( 0.1, -0.45);
    glVertex2f( 0.2, -0.5);

    glVertex2f( 0.2, -0.5);//7
    glVertex2f( 0.3, -0.45);

    glVertex2f( 0.3, -0.45);
    glVertex2f( 0.4, -0.5);

    glVertex2f( 0.4, -0.5);
    glVertex2f( 0.5, -0.45);

    glVertex2f( 0.5, -0.45);
    glVertex2f( 0.6, -0.5);

    glVertex2f( 0.6, -0.5);
    glVertex2f( 0.7, -0.45);

    glVertex2f( 0.7, -0.45);
    glVertex2f( 0.8, -0.5);

    glVertex2f( 0.8, -0.5);
    glVertex2f( 0.9, -0.45);

    glVertex2f( 0.9, -0.45);
    glVertex2f( 1.0, -0.5);
    glEnd();

    ///main water
    glColor3ub(100,149,237);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.5);
    glVertex2f( 1,-0.5);
    glVertex2f( 1, -1);
    glVertex2f(-1, -1);
    glEnd();
}


void grass()

{
    glPushMatrix();
    glScalef(2, 2, 1.0f);

    glColor3ub(0,102,51);

    glBegin(GL_QUADS);

    glVertex2f(0.150,0.150);

    glVertex2f(0.150,0.170);

    glVertex2f(0.230,0.170);

    glVertex2f(0.230,0.150);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.190,0.150);
    glVertex2f(0.210,0.150);
    glVertex2f(0.200,0.300);
    glEnd();




    glBegin(GL_POLYGON);

    glVertex2f(0.195,0.150);

    glVertex2f(0.215,0.150);

    glVertex2f(0.210,0.295);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.200,0.150);

    glVertex2f(0.215,0.150);

    glVertex2f(0.220,0.280);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.210, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.230, 0.270);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.230, 0.260);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.245, 0.250);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.255, 0.240);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.265, 0.230);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.270, 0.220);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.275, 0.210);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.280, 0.205);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.285, 0.200);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.290, 0.190);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.200, 0.150);

    glVertex2f(0.190, 0.295);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.175, 0.150);

    glVertex2f(0.195, 0.150);

    glVertex2f(0.185, 0.285);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.185, 0.150);

    glVertex2f(0.180, 0.275);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.170, 0.265);

    glEnd();







    glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.160, 0.255);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.150, 0.245);

    glEnd();



      glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.145, 0.235);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.140, 0.225);

    glEnd();





       glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.135, 0.220);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.124, 0.210);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.125, 0.210);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.120, 0.200);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.110, 0.195);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.100, 0.185);

    glEnd();






    glPopMatrix();

}



void grassAtRiverBank()
{
    ///grass 1 at river bank
        glPushMatrix();
            glTranslatef(-0.8, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

    ///grass 2 at river bank
        glPushMatrix();
            glTranslatef(-0.5, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

    ///grass 3 at river bank
        glPushMatrix();
            glTranslatef(-0.2, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

    ///grass 4 at river bank
        glPushMatrix();
            glTranslatef( 0.1, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

    ///grass 5 at river bank
        glPushMatrix();
            glTranslatef( 0.4, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

    ///grass 6 at river bank
        glPushMatrix();
            glTranslatef( 0.7, -0.55, 0);
            glPushMatrix();
                glScalef(0.4, 0.4, 1);
                grass();
            glPopMatrix();
        glPopMatrix();

}
void trainSingleLine(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
        glBegin(GL_QUADS);
        glColor3ub(110,110,10);
        glVertex2f(-1, -0.8);
        glVertex2f(-1+0.25/1.67, -0.55);
        glVertex2f( -0.9+0.25/1.67, -0.55);
        glVertex2f( -0.9, -0.8);
        glEnd();
    glPopMatrix();
}
void train2(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);

    glBegin(GL_QUADS);
    glColor3f(0.6,1,0.5);
    glVertex2f(0, -0.75);
    glVertex2f(0  , -0.55);
    glVertex2f(0.6, -0.55);
    glVertex2f(0.6, -0.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.05, -0.65);
    glVertex2f(0.05  , -0.58);
    glVertex2f(0.15, -0.58);
    glVertex2f(0.15, -0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.2, -0.65);
    glVertex2f(0.2  , -0.58);
    glVertex2f(0.3, -0.58);
    glVertex2f(0.3, -0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.35, -0.65);
    glVertex2f(0.35  , -0.58);
    glVertex2f(0.45, -0.58);
    glVertex2f(0.45, -0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.48, -0.75);
    glVertex2f(0.48  , -0.58);
    glVertex2f(0.57, -0.58);
    glVertex2f(0.57, -0.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0.5,0.5);
    glVertex2f(0.6+0.15/1.67, -0.4);
    glVertex2f(0.6+0.15/1.67, -0.6);
    glVertex2f(0.6, -0.75);
    glVertex2f(0.6, -0.55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex2f(0.6+0.15/1.67, -0.4);
    glVertex2f(0.0+0.15/1.67, -0.4);
    glVertex2f(0.0, -0.55);
    glVertex2f(0.6, -0.55);
    glEnd();
    glPopMatrix();
}
void trainAllSingleLines()
{
    ///main train line
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-1, -0.8);
    glVertex2f(-1, -0.55);
    glVertex2f( 1, -0.55);
    glVertex2f( 1, -0.8);
    glEnd();

    trainSingleLine(-0.2,0);
    trainSingleLine(0,0);
    trainSingleLine(0.2,0);
    trainSingleLine(0.4,0);
    trainSingleLine(0.6,0);
    trainSingleLine(0.8,0);
    trainSingleLine(1.0,0);
    trainSingleLine(1.2,0);
    trainSingleLine(1.4,0);
    trainSingleLine(1.6,0);
    trainSingleLine(1.8,0);
}
void railLine2()
{
    glBegin(GL_QUADS);
    //glColor3ub(255,218,185);
    glVertex2f(-1, -0.7);
    glVertex2f(-1, -0.5);
    glVertex2f( 1, -0.7);
    glVertex2f( 1, -0.5);
    glEnd();

    trainAllSingleLines();

    train2(-0.62,0);
    train2(-0,0);
    train2(0.62,0);
}





#define PI 3.1416
void cloud1()

{
    int i;
	GLfloat x=.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(x+(radius*cos(i* twicePi/triangleAmount)), y+(radius*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
GLfloat a=.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(a+(radius*cos(i* twicePi/triangleAmount)), b+(radius*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

	GLfloat c=.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(c+(radius*cos(i* twicePi/triangleAmount)), d+(radius*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

	GLfloat e=.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(e+(radius*cos(i* twicePi/triangleAmount)), f+(radius*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

	GLfloat g=.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(g+(radius*cos(i* twicePi/triangleAmount)), h+(radius*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
}
void bird()

{
       int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;

	int triangleAmount = 20;

	GLfloat twicePi = 2.0f * PI;



	glBegin(GL_TRIANGLE_FAN);

	    glColor3ub(225, 225, 208);

		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mm+(radiusmm*cos(i* twicePi/triangleAmount)), nn+(radiusmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );  //birds downside
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f); // white wings
    glVertex2f(0.14f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);  //shadow wings
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();

	/////2nd bird////

	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmm+(radiusmmm*cos(i* twicePi/triangleAmount)),nnn+(radiusmmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

	/////3rd bird/////

	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmmm+(radiusmmm*cos(i* twicePi/triangleAmount)), nnnn+(radiusmmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++)
        {
			glVertex2f(mmmmm+(radiusmm*cos(i* twicePi/triangleAmount)), nnnnn+(radiusmm*sin(i*twicePi/triangleAmount)));
		}
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

}
void fence()

{

     glLineWidth(4);

     glBegin(GL_LINES);

    glColor3ub(0, 0, 0);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(-0.6f,-0.1f);


    glVertex2f(-1.0f,-0.05f);

    glVertex2f(-0.6f,-0.05f);




    glVertex2f(-1.0f,0.0f);

    glVertex2f(-0.6f,0.0f);



    glVertex2f(-1.0f,0.05f);

    glVertex2f(-0.6f,0.05f);





    glVertex2f(-1.0f,0.1f);

    glVertex2f(-0.6f,0.1f);




    glVertex2f(-0.95f,0.13f);

    glVertex2f(-0.95f,-0.12f);




    glVertex2f(-0.9f,0.13f);

    glVertex2f(-0.9f,-0.12f);




    glVertex2f(-0.85f,0.13f);

    glVertex2f(-0.85f,-0.12f);





    glVertex2f(-0.8f,0.13f);

    glVertex2f(-0.8f,-0.12f);



    glVertex2f(-0.75f,0.13f);

    glVertex2f(-0.75f,-0.12f);



    glVertex2f(-0.7f,0.13f);

    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);

    glVertex2f(-0.65f,-0.12f);



    glEnd();

}

void backgroundtree()

{

    //pamtrees body

    glBegin(GL_POLYGON);

	glColor3ub(102, 51, 0);

	glVertex2f(-0.52f,0.45f);

	glVertex2f(-0.48f, 0.45f);

	glVertex2f(-0.48f,0.62f);

    glVertex2f(-0.5f,0.64f);

    glVertex2f(-0.52f,0.62f);

    glEnd();



    glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

    glVertex2f(-0.5f,0.64f);

    glVertex2f(-0.52f,0.62f);

    glVertex2f(-0.58f,0.6f);

	glVertex2f(-0.55f, 0.63f);

	glVertex2f(-0.58f,0.66f);

	glVertex2f(-0.52f,0.66f);

	glVertex2f(-0.52f, 0.72f);

	glVertex2f(-0.5f,0.69f);     //palm tree leaves

	glVertex2f(-0.48f,0.72f);

	glVertex2f(-0.48f, 0.66f);

	glVertex2f(-0.42f,0.66f);

	glVertex2f(-0.45f,0.63f);

	glVertex2f(-0.42f, 0.6f);

	glVertex2f(-0.48f,0.62f);

    glEnd();



    glBegin(GL_POLYGON);

	glColor3ub(102, 51, 0);

	glVertex2f(0.52f,0.45f);

	glVertex2f(0.48f, 0.45f);

	glVertex2f(0.48f,0.62f);

    glVertex2f(0.5f,0.64f);

    glVertex2f(0.52f,0.62f);

    glEnd();

     glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

    glVertex2f(0.5f,0.64f);

    glVertex2f(0.52f,0.62f);

    glVertex2f(0.58f,0.6f);

	glVertex2f(0.55f, 0.63f);

	glVertex2f(0.58f,0.66f);

	glVertex2f(0.52f,0.66f);

	glVertex2f(0.52f, 0.72f);

	glVertex2f(0.5f,0.69f);///

	glVertex2f(0.48f,0.72f);

	glVertex2f(0.48f, 0.66f);

	glVertex2f(0.42f,0.66f);

	glVertex2f(0.45f,0.63f);

	glVertex2f(0.42f, 0.6f);

	glVertex2f(0.48f,0.62f);

    glEnd();  //palm tree end



  	glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

	glVertex2f(-1.0f,0.45f);

	glVertex2f(-0.98f, 0.5f);

    glVertex2f(-0.93f, 0.56);

    glVertex2f(-0.9f,0.6f);

    glVertex2f(-0.82f, 0.64);

    glVertex2f(-0.75f, 0.67); //hill 1

    glVertex2f(-0.68f, 0.64);

     glVertex2f(-0.6f,0.6f);

     glVertex2f(-0.57f, 0.56);

     glVertex2f(-0.52f, 0.5f);

     glVertex2f(-0.5f,0.45f);

     glVertex2f(-1.0f,0.45f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

	glVertex2f(1.0f,0.45f);

	glVertex2f(0.98f, 0.5f);

    glVertex2f(0.93f, 0.56);

    glVertex2f(0.9f,0.6f);

    glVertex2f(0.82f, 0.64);

    glVertex2f(0.75f, 0.67); //hill 2

    glVertex2f(0.68f, 0.64);

     glVertex2f(0.6f,0.6f);

     glVertex2f(0.57f, 0.56);

     glVertex2f(0.52f, 0.5f);

     glVertex2f(0.5f,0.45f);

     glVertex2f(1.0f,0.45f);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3ub(34,139,34);
	///glColor3ub(0, 0, 0);

	glVertex2f(-0.5f,0.45f);

	glVertex2f(-0.48f, 0.5f);

    glVertex2f(-0.45f, 0.56);

    glVertex2f(-0.42f,0.6f);

    glVertex2f(-0.37f, 0.62); //hill 3

    glVertex2f(-0.32f, 0.6);

    glVertex2f(-0.29f, 0.56f);

     glVertex2f(-0.27f, 0.5f);

    glVertex2f(-0.25f,0.45f);

    glEnd();



    glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

	glVertex2f(0.5f,0.45f);

	glVertex2f(0.48f, 0.5f);

    glVertex2f(0.45f, 0.56);

    glVertex2f(0.42f,0.6f);

    glVertex2f(0.37f, 0.62);// hill 4

    glVertex2f(0.32f, 0.6);

    glVertex2f(0.29f, 0.56f);

     glVertex2f(0.27f, 0.5f);

    glVertex2f(0.25f,0.45f);

    glEnd();



    glBegin(GL_POLYGON);

	glColor3ub(34,139,34);

	glVertex2f(-.25f,0.45f);

	glVertex2f(-0.23f, 0.5f);

    glVertex2f(-0.18f, 0.56);

    glVertex2f(-0.15f,0.6f);

    glVertex2f(-0.07f, 0.64);

    glVertex2f(-0.00f, 0.67); //hill 5

    glVertex2f(0.07f, 0.64);

    glVertex2f(0.15f,0.6f);

    glVertex2f(0.18f, 0.56);

    glVertex2f(0.23f, 0.5f);

    glVertex2f(.25f,0.45f);

	glEnd();
}

void straw()
{
    glColor3ub(184,18,11);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-0.37,0.5);
    glVertex2f(-0.37,0.65);
    glEnd();
    glLineWidth(2);

	glBegin(GL_POLYGON);

	glColor3ub(218,165,32);///golden rod
	///glColor3ub(0, 0, 0);

	glVertex2f(-0.5f,0.45f);

	glVertex2f(-0.48f, 0.5f);

    glVertex2f(-0.45f, 0.56);

    glVertex2f(-0.42f,0.6f);

    glVertex2f(-0.37f, 0.62);

    glVertex2f(-0.32f, 0.6);

    glVertex2f(-0.29f, 0.56f);

     glVertex2f(-0.27f, 0.5f);

    glVertex2f(-0.25f,0.45f);

    glEnd();

}
void boat2()

{



 glBegin(GL_POLYGON);

	glColor3ub(0, 0, 0);

	glVertex2f(0.63f, -0.53f);

	glVertex2f(0.53f, -0.53f);

	glVertex2f(0.43f, -0.5f);

	glVertex2f(0.53f, -0.6f);

	glVertex2f(0.78f, -0.6f);

	glVertex2f(0.88f, -0.5f);

	glVertex2f(0.78f, -0.53f);

	glVertex2f(0.73f, -0.53f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(122, 122, 82);

	glVertex2f(0.43f, -0.5f);

	glVertex2f(0.53f, -0.53f);

	glVertex2f(0.63f, -0.53f);

	glVertex2f(0.73f, -0.53f);

	glVertex2f(0.78f, -0.53f);

	glVertex2f(0.88f, -0.5f);////

	glVertex2f(0.78f, -0.48f);

	glVertex2f(0.73f, -0.48f);

	glVertex2f(0.63f, -0.48f);

	glVertex2f(0.53f, -0.48f);

	glVertex2f(0.43f, -0.5f);

	glEnd();



	glLineWidth(3);

    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);

	glVertex2f(0.88f, -0.5f);////

	glVertex2f(0.78f, -0.48f);

	glVertex2f(0.78f, -0.48f);

	glVertex2f(0.73f, -0.48f);

	glVertex2f(0.73f, -0.48f);

	glVertex2f(0.63f, -0.48f);

	glVertex2f(0.63f, -0.48f);

	glVertex2f(0.53f, -0.48f);

	glVertex2f(0.53f, -0.48f);

	glVertex2f(0.43f, -0.5f);

    glEnd();



    glLineWidth(9);

    glBegin(GL_LINES);

    glColor3ub(0,0, 0);

	glVertex2f(0.53f, -0.48f);

	glVertex2f(0.53f, -0.535f);

	glVertex2f(0.63f, -0.48f);

	glVertex2f(0.63f, -0.535f);

	glVertex2f(0.73f, -0.48f);

	glVertex2f(0.73f, -0.535f);

	glVertex2f(0.81f, -0.48f);

	glVertex2f(0.81f, -0.535f);

    glEnd();



    glLineWidth(6);

    glBegin(GL_LINES);
    glColor3ub(204, 153, 0);
	glVertex2f(0.38f, -0.38f);
	glVertex2f(0.4f, -0.53f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
	glVertex2f(0.38f, -0.42f);
	glVertex2f(0.43f, -0.5f);
    glEnd();

}







void cityScenery()
{
    cityLand();
    glPushMatrix();
    glTranslatef(pos1, 0.0f, 0.0f);
        buildings();
        roadLines();
        river1();
        grassAtRiverBank();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pos2, 0.0f, 0.0f);
    ///only buildings();
        buildingsWithMosque();
        roadLines();
        river1();
        grassAtRiverBank();
    glPopMatrix();

    ///sheep
    glPushMatrix();
        glTranslatef(+0.5,-1.0, 0);
        glPushMatrix();
            glScalef(1.7,1.7,1);
            boat();
        glPopMatrix();
    glPopMatrix();
}


///clouds
void clouds()
{
    cloud1();

    glPushMatrix();
    glTranslatef(-0.4, 0,0);
    cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0,0);
    cloud1();
    glPopMatrix();
}
void villageScenery()
{

    glPushMatrix();

    ///background tree
    glPushMatrix();
    glTranslatef(0, 0.05, 0);
    backgroundtree();
    glPopMatrix();


    /// straw
    glPushMatrix();
    glTranslatef( 0.1, -0.85,0);
    glPushMatrix();
    glScalef(1.8, 2.5, 1);
    straw();
    glPopMatrix();
    glPopMatrix();
    ///village house 2
    glPushMatrix();
        glTranslatef(-0.6, 0.3, 0);
            villageHouse2();
    glPopMatrix();
    ///tree behind house 2
    tree(0.5,0.2);



    ///road to village house 2
    glColor3f(0.4, 0.4,0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.1);
    glVertex2f(-0.8+0.32/1.67,0.22);
    glVertex2f(-0.3+0.32/1.67,0.22);
    glVertex2f(-0.3,-0.1);
    glEnd();

    ///village house 1
    villageHouseSc();
    tree(0,-0.05);
    ///green field
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex2f(0.45, 0);
    glVertex2f(0.45+0.3/1.67, 0.3);
    glVertex2f(0.9+0.3/1.67, 0.3);
    glVertex2f(0.9, 0);
    glEnd();

    ///green field border
    glBegin(GL_QUADS);
    glColor3f(0.7,0.2,0.7);
    glVertex2f(0.45, 0.2);
    glVertex2f(0.45, 0);
    glVertex2f(0.45+0.3/1.67, 0.3);
    glVertex2f(0.45+0.3/1.67, 0.3+0.15);
    glEnd();


    ///green field border
    glBegin(GL_QUADS);
    glColor3f(0.8,0.4,0);
    glVertex2f(0.45+0.3/1.67, 0.3);
    glVertex2f(0.45+0.3/1.67, 0.3+0.15);
    glVertex2f(0.9+0.3/1.67, 0.3+0.15);
    glVertex2f(0.9+0.3/1.67, 0.3);
    glEnd();


    ///cloud(0, 0.8);
    //tree(0,0);
    //glTranslatef(0, -0.05, 0);

    glPopMatrix();

    ///grass 1
        glPushMatrix();
            glTranslatef(-1.1, -0.2, 0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1);
                grass();
            glPopMatrix();
        glPopMatrix();


    ///grass 2
        glPushMatrix();
            glTranslatef(-1.0, -0.1, 0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1);
                grass();
            glPopMatrix();
        glPopMatrix();


    ///grass 3
        glPushMatrix();
            glTranslatef(-1.2, -0.1, 0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1);
                grass();
            glPopMatrix();
        glPopMatrix();


    ///grass 4
        glPushMatrix();
            glTranslatef(-0.9, -0.0, 0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1);
                grass();
            glPopMatrix();
        glPopMatrix();


    ///grass 5
        glPushMatrix();
            glTranslatef(-1.1, -0.0, 0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1);
                grass();
            glPopMatrix();
        glPopMatrix();


    ///river
    river1();
    grassAtRiverBank();

    ///roadlines && car
    roadLines();
    glPushMatrix();
    glTranslatef(-carPosition,-0.2f, 0.0f);
    //car(0.0f, -0.2f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.75, 0.1, 0);
    glPushMatrix();
    glScalef(1.3,1,1);
    fence();
    glPopMatrix();
    glPopMatrix();

    ///
    ///boat
    glPushMatrix();
    glTranslatef(0,0, 0);
    boat2();
    glPopMatrix();

}
void AllScenery()
{
    ///background
    water();
    skyObject();
    ///clouds
        glPushMatrix();
        glTranslatef(-cloudPosition, 0, 0);
        clouds();
        glPopMatrix();
    ///bird
        glPushMatrix();
        glTranslatef(birdPosition,0.15,0);
        bird();
        glPopMatrix();
    ///background end
    ///car
    if(isCity)
    {
        cityScenery();
    }
    if(isVillage)
    {
        villgeLand();

        glPushMatrix();
        glTranslatef(pos1, 0, 0);
        villageScenery();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(pos2, 0, 0);
        villageScenery();
        glPopMatrix();

    ///sheep
    glPushMatrix();
        glTranslatef(+0.5,-1.0, 0);
        glPushMatrix();
            glScalef(1.7,1.7,1);
            boat();
        glPopMatrix();
    glPopMatrix();

    }

    glPushMatrix();
    glTranslatef(-carPosition,-0.2f, 0.0f);
    car(0.0f, -0.2f);
    glPopMatrix();
    ///car end
}
void display()
{
    glClearColor(0.4, 0.4, 0.4, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    AllScenery();

    glFlush();

}

void handleMouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON)
{

    if(roadSpeed>=0.01)
    {
        roadSpeed-=0.005;
    }
    if (roadSpeed==0)
    {
        carWheelMove=false;
    }

    carSpeed = 0.005f;
}
if (button == GLUT_RIGHT_BUTTON)
{
    if(roadSpeed<=0.5)
    {
        roadSpeed+=0.005;
    }
    carWheelMove=true;
    carSpeed = 0.005f;
}
if (button == GLUT_MIDDLE_BUTTON)
{
    roadSpeed=0;
    carWheelMove=false;
    carSpeed = 0;
}
glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {
    switch (key)
    {
        case 'c':
            isCity=true;
            isVillage=false;
            break;

        case 'v':
            isCity=false;
            isVillage=true;
            break;

    }
        glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize(700, 700);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);
   glutTimerFunc(100, update, 0);
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);

   glutMainLoop();
   return 0;
}
/// add cloud , village house, river, boat, bird, tree
///
