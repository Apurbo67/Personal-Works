#include<iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
using namespace std;
# define PI           3.14159265358979323846

GLfloat x=0.0f,  y=0.0f,radius =0.0f,twicePi=2*PI;
int triangleAmount,i ;

GLfloat k = 1.0f,l=1.0,m=1.0f,xx,xx1,yy,yy1;
GLfloat j = 1.0f,position4=0.0f,speed4=0.02f;
GLfloat speed = 0.01f;
GLfloat speed_cloud = 0.001f;
GLfloat speed_plane = 0.01f;
GLfloat position = 0.0f;


void drawBird()
{
    //glPushMatrix();
    int i;

    GLfloat mm=0.182f;
    GLfloat nn=.801f;
    GLfloat radiusmm =.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
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
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
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

    GLfloat mmm=0.062f;
    GLfloat nnn=.801f;
    GLfloat radiusmmm =.01f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmm, nnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
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

    GLfloat mmmm=-0.638f;
    GLfloat nnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmm,nnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    ////4th bird////
    GLfloat mmmmm=-0.518f;
    GLfloat nnnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmmm, nnnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
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



////////////////////////////////////////////////////////////////////////uper row birds

    glTranslatef(-0.200f,0.900f,0.00f);


    {
            glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
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
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
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

     mmm=0.062f;
     nnn=.801f;
     radiusmmm =.01f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmm, nnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
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

     mmmm=-0.638f;
     nnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmm,nnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
            nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    ////4th bird////
     mmmmm=-0.518f;
     nnnnn=.801f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mmmmm, nnnnn); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
            nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
        );
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



    glTranslatef(0.200f,-0.900f,0.00f);



    //glPopMatrix();

}
//cloud
void cloud() {

glPushMatrix();
    glTranslatef(position,0,0);
    glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(-1.6+x,2.07+y);

    }
glEnd();
glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(-1.45+x,2.01+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(-1.30+x,2.07+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(-1.17+x,2.00+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(-1.00+x,2.05+y);

    }
glEnd();
glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(1.6+x,2.07+y);

    }
glEnd();
glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(1.45+x,2.01+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(1.30+x,2.07+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(1.17+x,2.00+y);

    }
glEnd();

glBegin(GL_POLYGON);

    for(int i=0; i<200; i++)

    {

        glColor3ub(255, 255, 255);

        float pi=3.1416;

        float A=(i*2*pi)/200;

        float r=0.2;

        float x = r * cos(A);

        float y = r * sin(A);

        glVertex2f(1.00+x,2.05+y);

    }
glEnd();

glPopMatrix();
//
}


void update_bird(int value) {

    if(position >2.50)
    {
         position = -2.0f;

    }


    position += speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();
	//position = 1.0f;;


	glutTimerFunc(100, update_bird, 0);
}


void update_cloud(int value) {

    if(position >2.50)
    {
         position = -2.0f;

    }


    position += speed_cloud; //position=position-speed;1-.1=.9

	glutPostRedisplay();
	//position = 1.0f;;


	glutTimerFunc(100,update_cloud, 0);
}



void update_plane(int value) {

    if(position >2.20)
    {
         position = -2.0f;

    }


    position += speed_plane; //position=position-speed;1-.1=.9

	glutPostRedisplay();
	//position = 1.0f;;


	glutTimerFunc(100, update_plane, 0);
}


void display_bird() {




glPushMatrix();
glTranslatef(position,0,0);


drawBird();
//drawPlane();
glPopMatrix();




}



void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
    //gluOrtho2D(-2,2,-2,2);
}

void update4(int value) {
    if(position4 <0.0 )
       {

        position4 = 0.1;
       }
    position4 -= speed4; //position=position-speed;1-.1=.9
	glutPostRedisplay();
	glutTimerFunc(100, update4, 0);

}

void draw_star()
{
    //star
///////////////////////////////////////////////////
{


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();

}
///////////////////////////////////////////////
glTranslatef(-0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(0.500f,0.400f,0.00f);
////////////////////////////////////////////////
glTranslatef(0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.400f,0.00f);

///////////////////////////////////////////////
glTranslatef(0.500f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.800f,0.00f);

//////////////////////////////////////////////////

glTranslatef(0.900f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.900f,0.800f,0.00f);
////////////////////////////////////////////////////
glTranslatef(-01.900f,-0.800f,0.00f);

{
    {


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();

}
glTranslatef(-0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(0.500f,0.400f,0.00f);

glTranslatef(0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.400f,0.00f);


glTranslatef(0.500f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.800f,0.00f);



glTranslatef(0.900f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.900f,0.800f,0.00f);



}
glTranslatef(01.900f,0.800f,0.00f);

////////////////////////////////////////////////

glTranslatef(01.900f,-0.00f,0.00f);

{
    {


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();

}
glTranslatef(-0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(0.500f,0.400f,0.00f);

glTranslatef(0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.400f,0.00f);


glTranslatef(0.500f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.800f,0.00f);



glTranslatef(0.900f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.900f,0.800f,0.00f);



}
glTranslatef(-01.900f,0.00f,0.00f);

/////////////////////////////////////////////

glTranslatef(01.00f,-0.00f,0.00f);

{
    {


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();

}
glTranslatef(-0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(0.500f,0.400f,0.00f);

glTranslatef(0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.400f,0.00f);


glTranslatef(0.500f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.800f,0.00f);



glTranslatef(0.900f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.900f,0.800f,0.00f);



}
glTranslatef(-01.00f,0.00f,0.00f);
//////////////////////////////////////////////////

/////////////////////////////////////////////

glTranslatef(-0.500f,-0.500f,0.00f);

{
    {


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();

}
glTranslatef(-0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(0.500f,0.400f,0.00f);

glTranslatef(0.500f,-0.400f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.400f,0.00f);


glTranslatef(0.500f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.500f,0.800f,0.00f);



glTranslatef(0.900f,-0.800f,0.00f);
{
    //star
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.12f);
glVertex2f(-2.01f, 2.11f);
glVertex2f(-2.0f, 2.10f);
glVertex2f(-1.99f, 2.11f);

glTranslatef(0.100f,0.00f,0.00f);


glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-2.01f, 2.06f);
glVertex2f(-2.0f, 2.05f);
glVertex2f(-1.99f, 2.06f);

glTranslatef(-0.100f,0.00f,0.00f);
glTranslatef(0.200f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.8f, 2.12f);
glVertex2f(-1.81f, 2.11f);
glVertex2f(-1.8f, 2.10f);
glVertex2f(-1.79f, 2.11f);

glTranslatef(-0.200f,0.00f,0.00f);
glTranslatef(0.300f,0.00f,0.00f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-1.7f, 2.15f);
glVertex2f(-1.71f, 2.14f);
glVertex2f(-1.7f, 2.13f);
glVertex2f(-1.69f, 2.14f);

glTranslatef(-0.300f,0.00f,0.00f);
glTranslatef(0.1500f,0.00f,0.00f);

glVertex2f(-1.5f, 2.15f);
glVertex2f(-1.51f, 2.14f);
glVertex2f(-1.5f, 2.13f);
glVertex2f(-1.49f, 2.14f);

glTranslatef(-0.1500f,0.00f,0.00f);
glTranslatef(0.050f,0.00f,0.00f);

glVertex2f(-1.52f, 2.18f);
glVertex2f(-1.53f, 2.17f);
glVertex2f(-1.52f, 2.16f);
glVertex2f(-1.51f, 2.17f);

glTranslatef(-0.050f,0.00f,0.00f);
glTranslatef(0.00f,-0.300f,0.00f);


glVertex2f(-1.42f, 2.18f);
glVertex2f(-1.43f, 2.17f);
glVertex2f(-1.42f, 2.16f);
glVertex2f(-1.41f, 2.17f);

glTranslatef(0.00f,0.300f,0.00f);
glTranslatef(0.50f,0.00f,0.00f);

glVertex2f(-1.42f, 1.98f);
glVertex2f(-1.43f, 1.97f);
glVertex2f(-1.42f, 1.96f);
glVertex2f(-1.41f, 1.97f);

glTranslatef(-0.500f,0.00f,0.00f);
glTranslatef(0.600f,0.100f,0.00f);

glVertex2f(-1.32f, 2.08f);
glVertex2f(-1.33f, 2.07f);
glVertex2f(-1.32f, 2.06f);
glVertex2f(-1.31f, 2.07f);

glTranslatef(-0.600f,-0.100f,0.00f);
glTranslatef(0.700f,0.200f,0.00f);

glVertex2f(-1.32f, 1.98f);
glVertex2f(-1.33f, 1.97f);
glVertex2f(-1.32f, 1.96f);
glVertex2f(-1.31f, 1.97f);

glTranslatef(-0.700f,-0.200f,0.00f);
glTranslatef(0.90f,-0.300f,0.00f);


glVertex2f(-1.22f, 2.08f);
glVertex2f(-1.23f, 2.07f);
glVertex2f(-1.22f, 2.06f);
glVertex2f(-1.21f, 2.07f);

glTranslatef(-0.90f,0.3f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.22f, 1.98f);
glVertex2f(-1.23f, 1.97f);
glVertex2f(-1.22f, 1.96f);
glVertex2f(-1.21f, 1.97f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.27f, 2.03f);
glVertex2f(-1.28f, 2.02f);
glVertex2f(-1.27f, 2.01f);
glVertex2f(-1.26f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(0.00f,-0.600f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.00f,0.600f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.12f, 2.08f);
glVertex2f(-1.13f, 2.07f);
glVertex2f(-1.12f, 2.06f);
glVertex2f(-1.11f, 2.07f);

glTranslatef(0.00f,0.00f,0.00f);
glTranslatef(-0.700f,-0.300f,0.00f);


glVertex2f(-1.12f, 1.98f);
glVertex2f(-1.13f, 1.97f);
glVertex2f(-1.12f, 1.96f);
glVertex2f(-1.11f, 1.97f);

glTranslatef(0.700f,0.300f,0.00f);
glTranslatef(0.00f,0.00f,0.00f);


glVertex2f(-1.17f, 2.03f);
glVertex2f(-1.18f, 2.02f);
glVertex2f(-1.17f, 2.01f);
glVertex2f(-1.16f, 2.02f);

glTranslatef(0.00f,0.00f,0.00f);


glEnd();
}

glTranslatef(-0.900f,0.800f,0.00f);



}
glTranslatef(0.500f,0.500f,0.00f);
//////////////////////////////////////////////////
}


void Moon()
{

    GLfloat x3=-0.5f;
    GLfloat y3=0.9f;
    GLfloat radius3 =0.1f;
    GLfloat x4=-0.59f;
    GLfloat y4=0.94f;
    GLfloat radius4 =0.15f;
    int i;
	int triangleAmount = 30;

	GLfloat twicePi = 2.0f * PI;
    //glTranslatef(01.700f,01.30f,0.00f);

	//glScalef(01.500f,01.500f,0.00f);
	glTranslatef(02.00f,01.30f,0.00f);
	//glColor3ub(255, 255, 155);
	glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
			    y3 + (radius3 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

/*
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
			    y4 + (radius4 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	*/
	//glLoadIdentity();
glTranslatef(-02.00f,-01.30f,0.00f);
//glScalef(00.66700f,0.666700f,0.00f);
//glTranslatef(-01.700f,-01.30f,0.00f);
}
//plane
 void plane()
{

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
   glTranslatef(-0.8,-0.30f, 0.0f);
    ////plane
    glBegin(GL_QUADS);
    glColor3ub(68,187,255);
    glVertex2f(-1.9f,1.45f);
    glVertex2f(-1.0f,1.45f);
    glVertex2f(-1.0f,1.83f);
    glVertex2f(-1.9f,1.83f);
//FIRST WIND
  //  glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-1.9f,1.83f);
    glVertex2f(-1.60f,1.83f);
    glVertex2f(-1.75f,1.99f);
    glVertex2f(-1.9f,1.99f);
    //2NDWIND
   // glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-1.32f,1.83f);
    glVertex2f(-1.16f,1.83f);
    glVertex2f(-1.22f,1.99f);
    glVertex2f(-1.37f,1.99f);

  //  glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-1.2f,1.50f);
    glVertex2f(-1.5f,1.50f);
    glVertex2f(-1.7f,1.32f);
    glVertex2f(-1.4f,1.32f);


    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(-1.0f,1.45f);
    glVertex2f(-0.6f,1.60f);
    glVertex2f(-1.0f,1.83f);
    glEnd();


    glPopMatrix();

}






 void sun()
{

    GLfloat x3=-0.5f;
    GLfloat y3=0.9f;
    GLfloat radius3 =0.2f;
    GLfloat x4=-0.59f;
    GLfloat y4=0.94f;
    GLfloat radius4 =0.15f;
    int i;
	int triangleAmount = 250;

	GLfloat twicePi = 2.0f * PI;

	glTranslatef(01.700f,01.250f,0.00f);
	glColor3ub(255, 255, 155);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
			    y3 + (radius3 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

/*
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
			    y4 + (radius4 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	*/

	//glLoadIdentity();
glTranslatef(-01.700f,-01.250f,0.00f);


//glScalef(00.66700f,0.666700f,0.00f);
//glTranslatef(-01.700f,-01.30f,0.00f);
}


  void sun_morning()
{

    GLfloat x3=-0.5f;
    GLfloat y3=0.9f;
    GLfloat radius3 =0.2f;
    GLfloat x4=-0.59f;
    GLfloat y4=0.94f;
    GLfloat radius4 =0.15f;
    int i;
	int triangleAmount = 250;

	GLfloat twicePi = 2.0f * PI;

	glTranslatef(02.100f,01.10f,0.00f);
	glColor3ub(255, 140, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
			    y3 + (radius3 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

/*
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
			    y4 + (radius4 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	*/

	//glLoadIdentity();
glTranslatef(-02.100f,-01.10f,0.00f);


//glScalef(00.66700f,0.666700f,0.00f);
//glTranslatef(-01.700f,-01.30f,0.00f);
}



///Rain
void Rain_Drops()
{

          //  glPushMatrix();

      ///First Row
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glLoadIdentity();

	glVertex2f(1,.95f);
	glVertex2f(.99f,.92f);

	glVertex2f(.9f,.95f);
	glVertex2f(.89f,.92f);

	glVertex2f(.8f,.95f);
	glVertex2f(.79f,.92f);

	glVertex2f(.7f,.95f);
	glVertex2f(.69f,.92f);

	glVertex2f(.6f,.95f);
	glVertex2f(.59f,.92f);

	glVertex2f(.5f,.95f);
	glVertex2f(.49f,.92f);

	glVertex2f(.4f,.95f);
	glVertex2f(.39f,.92f);

	glVertex2f(.3f,.95f);
	glVertex2f(.29f,.92f);

	glVertex2f(.2f,.95f);
	glVertex2f(.19f,.92f);

	glVertex2f(.1f,.95f);
	glVertex2f(.09f,.92f);

	glVertex2f(0,.95f);
	glVertex2f(-.01f,.92f);

	glVertex2f(-.1f,.95f);
	glVertex2f(-.11f,.92f);

	glVertex2f(-.2f,.95f);
	glVertex2f(-.21f,.92f);

	glVertex2f(-.3f,.95f);
	glVertex2f(-.31f,.92f);

	glVertex2f(-.4f,.95f);
	glVertex2f(-.41f,.92f);

	glVertex2f(-.5f,.95f);
	glVertex2f(-.51f,.92f);

	glVertex2f(-.6f,.95f);
	glVertex2f(-.61f,.92f);

	glVertex2f(-.7f,.95f);
	glVertex2f(-.71f,.92f);

	glVertex2f(-.8f,.95f);
	glVertex2f(-.81f,.92f);

	glVertex2f(-.9f,.95f);
	glVertex2f(-.91f,.92f);

	glVertex2f(-.99f,.95f);
	glVertex2f(-1,.92f);

	glEnd();



	///2nd Row
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(.98f,.85f);
	glVertex2f(.97f,.82f);

	glVertex2f(.88f,.85f);
	glVertex2f(.87f,.82f);

	glVertex2f(.78f,.85f);
	glVertex2f(.77f,.82f);

	glVertex2f(.68f,.85f);
	glVertex2f(.67f,.82f);

	glVertex2f(.58f,.85f);
	glVertex2f(.57f,.82f);

	glVertex2f(.48f,.85f);
	glVertex2f(.47f,.82f);

	glVertex2f(.38f,.85f);
	glVertex2f(.37f,.82f);

	glVertex2f(.28f,.85f);
	glVertex2f(.27f,.82f);

	glVertex2f(.18f,.85f);
	glVertex2f(.17f,.82f);

	glVertex2f(.08f,.85f);
	glVertex2f(.07f,.82f);

	glVertex2f(-.02f,.85f);
	glVertex2f(-.03f,.82f);

	glVertex2f(-.12f,.85f);
	glVertex2f(-.13f,.82f);

	glVertex2f(-.22f,.85f);
	glVertex2f(-.23f,.82f);

	glVertex2f(-.32f,.85f);
	glVertex2f(-.33f,.82f);

	glVertex2f(-.42f,.85f);
	glVertex2f(-.43f,.82f);

	glVertex2f(-.52f,.85f);
	glVertex2f(-.53f,.82f);

	glVertex2f(-.62f,.85f);
	glVertex2f(-.63f,.82f);

	glVertex2f(-.72f,.85f);
	glVertex2f(-.73f,.82f);

	glVertex2f(-.82f,.85f);
	glVertex2f(-.83f,.82f);

	glVertex2f(-.92f,.85f);
	glVertex2f(-.93f,.82f);

	glVertex2f(-.99f,.85f);
	glVertex2f(-1,.82f);

	glEnd();

	///3rd Row
	glBegin(GL_LINES);
	glColor3f(1,1,1);
//	glVertex2f(1,.75f);
//	glVertex2f(.99f,.72f);

	glVertex2f(.95,.75f);
	glVertex2f(.94f,.72f);

	glVertex2f(.85,.75f);
	glVertex2f(.84f,.72f);

	glVertex2f(.75,.75f);
	glVertex2f(.74f,.72f);

	glVertex2f(.65,.75f);
	glVertex2f(.64f,.72f);

	glVertex2f(.55,.75f);
	glVertex2f(.54f,.72f);

	glVertex2f(.45,.75f);
	glVertex2f(.44f,.72f);

	glVertex2f(.35,.75f);
	glVertex2f(.34f,.72f);

	glVertex2f(.25,.75f);
	glVertex2f(.24f,.72f);

	glVertex2f(.15,.75f);
	glVertex2f(.14f,.72f);

	glVertex2f(.05,.75f);
	glVertex2f(.04f,.72f);

	glVertex2f(-.05,.75f);
	glVertex2f(-.06f,.72f);

	glVertex2f(-.15,.75f);
	glVertex2f(-.16f,.72f);

	glVertex2f(-.25,.75f);
	glVertex2f(-.26f,.72f);

	glVertex2f(-.35,.75f);
	glVertex2f(-.36f,.72f);

	glVertex2f(-.45,.75f);
	glVertex2f(-.46f,.72f);

	glVertex2f(-.55,.75f);
	glVertex2f(-.56f,.72f);

	glVertex2f(-.65,.75f);
	glVertex2f(-.66f,.72f);

	glVertex2f(-.75,.75f);
	glVertex2f(-.76f,.72f);

	glVertex2f(-.85,.75f);
	glVertex2f(-.86f,.72f);

	glVertex2f(-.95,.75f);
	glVertex2f(-.96f,.72f);
	glEnd();


	//glPopMatrix();//glPopMatrix pops the top matrix off the stack
   // j+=0.001f;//j=j+.j=.2








}
void Rain()
{
glLineWidth(0.5);

    glPushMatrix();
glTranslatef(0,position4,0);
Rain_Drops();
   glPopMatrix();

    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-0.3,0);
Rain_Drops();
   glPopMatrix();


    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-0.6,0);
Rain_Drops();
   glPopMatrix();


    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-0.9,0);
Rain_Drops();
   glPopMatrix();


    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-1.2,0);
Rain_Drops();
   glPopMatrix();


    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-1.5,0);
Rain_Drops();
   glPopMatrix();


    glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-1.8,0);
Rain_Drops();
   glPopMatrix();

       glPushMatrix();
glTranslatef(0,position4,0);
glTranslatef(0,-2.2,0);
Rain_Drops();
   glPopMatrix();
}




void building_with_light(){
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
	//right side
glTranslatef(0.11f,0.00f,0.00f);
	glBegin(GL_QUADS);

	glColor3ub(255,255,255);
	glVertex2f(0.7f, 1.0f);
	glColor3ub(255, 153, 51);
    glVertex2f(0.7f, -1.0f);
    glVertex2f(1.4f, -1.0f);
    glColor3ub(255,255,255);
    glVertex2f(1.4f, 1.0f);

    glColor3ub(255, 153, 51);
     glVertex2f(1.4f, -1.0f);
	glVertex2f(1.53f, -1.0f);
    glVertex2f(1.53f, 1.5f);
    glColor3ub(255,255,255);
     glVertex2f(1.4f, 1.5f);

     glColor3ub(255, 153, 51);
     glVertex2f(1.53f, -1.0f);
     glVertex2f(1.67f, -1.0f);
    glVertex2f(1.67f, 1.5f);
    glColor3ub(255,255,255);
     glVertex2f(1.53f, 1.5f);

     glColor3ub(255, 153, 51);
      glVertex2f(1.67f, -1.0f);
     glVertex2f(1.8f, -1.0f);
    glVertex2f(1.8f, 1.5f);
    glColor3ub(255,255,255);
     glVertex2f(1.67f, 1.5f);
     glEnd();
     //box
     glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(0.8f, -1.0f);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, 0.4f);
    glVertex2f(0.8f, 0.4f);
    glEnd();


     glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
      glVertex2f(0.8f, -1.0f);
      glColor3f(0.00,0.00,0.00);
     glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, 0.1f);
     glVertex2f(1.05f, 0.3f);
     glVertex2f(0.8f, 0.1f);
    glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
      glVertex2f(0.95f, -1.0f);
     glVertex2f(1.15f, -1.0f);
    glVertex2f(1.15f, -0.1f);
     glVertex2f(0.95f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
      glVertex2f(0.95f, 0.0f);
     glVertex2f(1.15f, 0.0f);
    glVertex2f(1.15, 0.05f);
     glVertex2f(1.05f, 0.1f);
     glVertex2f(0.95f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
	glVertex2f(0.85f, 1.0f);
     glVertex2f(1.05f, 1.0f);
     glColor3ub(255,255,255);
    glVertex2f(1.05f, 1.05f);
     glVertex2f(0.97f, 1.20f);
     glVertex2f(0.93f, 1.20f);
     glColor3ub(255,255,255);
      glVertex2f(0.85f, 1.05f);
      glEnd();
       //stick
      glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(0.94f, 1.20f);
     glVertex2f(0.95f, 1.20f);
    glVertex2f(0.95f, 1.32f);
     glVertex2f(0.94f, 1.32f);


glEnd();
//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(0.945f, 1.20f);
     glVertex2f(0.955f, 1.22f);
    glVertex2f(0.945f, 1.24f);
     glVertex2f(0.935f, 1.22f);
     glEnd();

//round on stick
GLfloat x=0.945f,  y=1.29f, radius =.01f;
int i;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=0.945f;  y=1.26f; radius =.01f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//doom
	glBegin(GL_POLYGON);
	glColor3ub(255, 102, 0);
    glVertex2f(1.8f, 1.5f);
           glColor3ub(255,255,255);
    glVertex2f(1.85f, 1.5f);
    glVertex2f(1.9f, 1.54f);
    glVertex2f(1.8f, 1.57f);
    glVertex2f(1.4f, 1.57f);
    glVertex2f(1.3f, 1.54f);
    glVertex2f(1.35f, 1.5f);


    glEnd();
    //doom head
    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
    glVertex2f(1.8f, 1.57f);
     glColor3ub(255,255,255);
    glVertex2f(1.8f, 1.7f);
    glVertex2f(1.63f, 1.8f);
    glVertex2f(1.63f, 1.83f);
    glVertex2f(1.57f, 1.83f);
    glVertex2f(1.57f, 1.8f);
    glVertex2f(1.4f, 1.7f);
    glVertex2f(1.4f, 1.57f);
    glEnd();
     glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(1.59f, 1.83f);
     glVertex2f(1.61f, 1.83f);
    glVertex2f(1.61f, 2.1f);
     glVertex2f(1.59f, 2.1f);


glEnd();

//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(1.6f, 1.83f);
     glVertex2f(1.63f, 1.85f);
    glVertex2f(1.6f, 1.88f);
     glVertex2f(1.57f,1.85f);
     glEnd();

//round on stick
 x=1.6f;  y=1.92f; radius =.03f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=1.6f;  y=2.0f; radius =.03f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//long doom
		 x=1.3f;  y=1.3f; radius =.03f;
glColor3ub(255, 153, 51);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(1.27f, 1.3f);
    glVertex2f(1.27f, 1.0f);
    glVertex2f(1.33f, 1.0f);
    glVertex2f(1.33f, 1.3f);
    glEnd();
    //long doom stick
    glBegin(GL_QUADS);
	glColor3ub(1, 1, 1);
	glVertex2f(1.29f, 1.33f);
    glVertex2f(1.3f, 1.33f);
    glVertex2f(1.3f, 1.40f);
    glVertex2f(1.29f, 1.40f);
    glEnd();
    //long doom rectangle


    x=1.294f;  y=1.35f; radius =.015f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//box
	glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(0.82f, 0.47f);
    glVertex2f(0.95f, 0.47f);
    glVertex2f(0.95f, 0.8f);
    glVertex2f(0.82f, 0.8f);

    glVertex2f(0.99f, 0.47f);
    glVertex2f(1.12f, 0.47f);
    glVertex2f(1.12f, 0.8f);
    glVertex2f(0.99f, 0.8f);

    glVertex2f(1.16f, 0.47f);
    glVertex2f(1.28f, 0.47f);
    glVertex2f(1.28f, 0.8f);
    glVertex2f(1.16f, 0.8f);

    glVertex2f(1.32f, 0.47f);
    glVertex2f(1.4f, 0.47f);
    glVertex2f(1.4f, 0.8f);
    glVertex2f(1.32f, 0.8f);

    glVertex2f(1.42f, 0.47f);
    glVertex2f(1.52f, 0.47f);
    glVertex2f(1.52f, 0.8f);
    glVertex2f(1.42f, 0.8f);

    glVertex2f(1.55f, 0.47f);
    glVertex2f(1.65f, 0.47f);
    glVertex2f(1.65f, 0.8f);
    glVertex2f(1.55f, 0.8f);

    glVertex2f(1.69f, 0.47f);
    glVertex2f(1.78f, 0.47f);
    glVertex2f(1.78f, 0.8f);
    glVertex2f(1.69f, 0.8f);

    //down
    glVertex2f(1.32f, 0.4f);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.4f, 0.07f);
    glVertex2f(1.32f, 0.07f);

    glVertex2f(1.42f, 0.4f);
    glVertex2f(1.52f, 0.4f);
    glVertex2f(1.52f, 0.07f);
    glVertex2f(1.42f, 0.07f);

    glVertex2f(1.55f, 0.4f);
    glVertex2f(1.65f, 0.4f);
    glVertex2f(1.65f, 0.07f);
    glVertex2f(1.55f, 0.07f);

    glVertex2f(1.69f, 0.4f);
    glVertex2f(1.78f, 0.4f);
    glVertex2f(1.78f, 0.07f);
    glVertex2f(1.69f, 0.07f);
    //very down
    glVertex2f(1.32f, 0.0f);
    glVertex2f(1.4f, 0.0f);
    glVertex2f(1.4f, -0.33f);
    glVertex2f(1.32f, -0.33f);

    glVertex2f(1.42f, 0.0f);
    glVertex2f(1.52f, 0.0f);
    glVertex2f(1.52f, -0.33f);
    glVertex2f(1.42f, -0.33f);

    glVertex2f(1.55f, 0.0f);
    glVertex2f(1.65f, 0.0f);
    glVertex2f(1.65f, -0.33f);
    glVertex2f(1.55f, -0.33f);

    glVertex2f(1.69f, 0.0f);
    glVertex2f(1.78f, 0.0f);
    glVertex2f(1.78f, -0.33f);
    glVertex2f(1.69f, -0.33f);

    //last down
    glVertex2f(1.32f, -0.4f);
    glVertex2f(1.4f, -0.4f);
    glVertex2f(1.4f, -0.73f);
    glVertex2f(1.32f, -0.73f);

    glVertex2f(1.42f, -0.4f);
    glVertex2f(1.52f, -0.4f);
    glVertex2f(1.52f, -0.73f);
    glVertex2f(1.42f, -0.73f);

    glVertex2f(1.55f, -0.4f);
    glVertex2f(1.65f, -0.4f);
    glVertex2f(1.65f, -0.73f);
    glVertex2f(1.55f, -0.73f);

    glVertex2f(1.69f, -0.4f);
    glVertex2f(1.78f, -0.4f);
    glVertex2f(1.78f, -0.73f);
    glVertex2f(1.69f, -0.73f);

    //for long doom
    glVertex2f(1.44f, 1.45f);
    glVertex2f(1.44f, 1.12f);
    glVertex2f(1.52f, 1.12f);
    glVertex2f(1.52f, 1.45f);

    glVertex2f(1.55f, 1.45f);
    glVertex2f(1.55f, 1.12f);
    glVertex2f(1.65f, 1.12f);
    glVertex2f(1.65f, 1.45f);

    glVertex2f(1.69f, 1.45f);
    glVertex2f(1.69f, 1.12f);
    glVertex2f(1.78f, 1.12f);
    glVertex2f(1.78f, 1.45f);
    glEnd();

    //down part
    /*
    glBegin(GL_QUADS);
	glColor3ub(153, 102, 51);
	glVertex2f(0.7f, -1.0f);
    glVertex2f(0.7f, -1.2f);
    glVertex2f(2.0f, -1.2f);
    glVertex2f(1.8f, -1.0f);
    glEnd();
*/


    glTranslatef(-0.11f,0.00f,0.00f);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


glTranslatef(-0.11f,0.00f,0.00f);

      //left side
	glBegin(GL_QUADS);

	  glColor3ub(205,133,63);
	glVertex2f(-0.7f, 1.0f);
	glColor3ub(255, 153, 51);
    glVertex2f(-0.7f, -1.0f);
    glVertex2f(-1.4f, -1.0f);
      glColor3ub(205,133,63);
    glVertex2f(-1.4f, 1.0f);

    glColor3ub(255, 153, 51);
     glVertex2f(-1.4f, -1.0f);
	glVertex2f(-1.53f, -1.0f);
    glVertex2f(-1.53f, 1.5f);
      glColor3ub(205,133,63);
     glVertex2f(-1.4f, 1.5f);

     glColor3ub(255, 153, 51);
     glVertex2f(-1.53f, -1.0f);
     glVertex2f(-1.67f, -1.0f);
    glVertex2f(-1.67f, 1.5f);
      glColor3ub(205,133,63);
     glVertex2f(-1.53f, 1.5f);

     glColor3ub(255, 153, 51);
      glVertex2f(-1.67f, -1.0f);
     glVertex2f(-1.8f, -1.0f);
    glVertex2f(-1.8f, 1.5f);
      glColor3ub(205,133,63);
     glVertex2f(-1.67f, 1.5f);
     glEnd();

     //box
     glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.8f, -1.0f);
    glVertex2f(-1.3f, -1.0f);
    glVertex2f(-1.3f, 0.4f);
    glVertex2f(-0.8f, 0.4f);
    glEnd();


     glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
      glVertex2f(-0.8f, -1.0f);
      glColor3f(0.00,0.00,0.00);
     glVertex2f(-1.3f, -1.0f);
    glVertex2f(-1.3f, 0.1f);
     glVertex2f(-1.05f, 0.3f);
     glVertex2f(-0.8f, 0.1f);
    glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
      glVertex2f(-0.95f, -1.0f);
     glVertex2f(-1.15f, -1.0f);
    glVertex2f(-1.15f, -0.1f);
     glVertex2f(-0.95f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
      glVertex2f(-0.95f, 0.0f);
     glVertex2f(-1.15f, 0.0f);
    glVertex2f(-1.15, 0.05f);
     glVertex2f(-1.05f, 0.1f);
     glVertex2f(-0.95f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
	glVertex2f(-0.85f, 1.0f);
	 glColor3ub(205,133,63);
     glVertex2f(-1.05f, 1.0f);
    glVertex2f(-1.05f, 1.05f);
     glVertex2f(-0.97f, 1.20f);
     glVertex2f(-0.93f, 1.20f);
      glVertex2f(-0.85f, 1.05f);
      glEnd();
       //stick
      glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-0.94f, 1.20f);
     glVertex2f(-0.95f, 1.20f);
    glVertex2f(-0.95f, 1.32f);
     glVertex2f(-0.94f, 1.32f);


glEnd();
//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(-0.945f, 1.20f);
     glVertex2f(-0.955f, 1.22f);
    glVertex2f(-0.945f, 1.24f);
     glVertex2f(-0.935f, 1.22f);
     glEnd();

//round on stick
 x=-0.945f;  y=1.29f; radius =.01f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=-0.945f;  y=1.26f; radius =.01f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//doom
	glBegin(GL_POLYGON);
	glColor3ub(255, 102, 0);
    glVertex2f(-1.8f, 1.5f);
    glVertex2f(-1.85f, 1.5f);
    glVertex2f(-1.9f, 1.54f);
    glVertex2f(-1.8f, 1.57f);
    glVertex2f(-1.4f, 1.57f);
    glVertex2f(-1.3f, 1.54f);
    glVertex2f(-1.35f, 1.5f);


    glEnd();
    //doom head
    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
    glVertex2f(-1.8f, 1.57f);
     glColor3ub(205,133,63);
    glVertex2f(-1.8f, 1.7f);
    glVertex2f(-1.63f, 1.8f);
    glVertex2f(-1.63f, 1.83f);
    glVertex2f(-1.57f, 1.83f);
    glVertex2f(-1.57f, 1.8f);
    glVertex2f(-1.4f, 1.7f);
    glVertex2f(-1.4f, 1.57f);
    glEnd();
     glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-1.59f, 1.83f);
     glVertex2f(-1.61f, 1.83f);
    glVertex2f(-1.61f, 2.1f);
     glVertex2f(-1.59f, 2.1f);


glEnd();

//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(-1.6f, 1.83f);
     glVertex2f(-1.63f, 1.85f);
    glVertex2f(-1.6f, 1.88f);
     glVertex2f(-1.57f,1.85f);
     glEnd();

//round on stick
 x=-1.6f;  y=1.92f; radius =.03f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=-1.6f;  y=2.0f; radius =.03f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//long doom
		 x=-1.3f;  y=1.3f; radius =.03f;
glColor3ub(255, 153, 51);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(-1.27f, 1.3f);
    glVertex2f(-1.27f, 1.0f);
    glVertex2f(-1.33f, 1.0f);
    glVertex2f(-1.33f, 1.3f);
    glEnd();
    //long doom stick
    glBegin(GL_QUADS);
	glColor3ub(1, 1, 1);
	glVertex2f(-1.29f, 1.33f);
    glVertex2f(-1.3f, 1.33f);
    glVertex2f(-1.3f, 1.40f);
    glVertex2f(-1.29f, 1.40f);
    glEnd();
    //long doom rectangle


    x=-1.294f;  y=1.35f; radius =.015f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//box
	glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.82f, 0.47f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.95f, 0.8f);
    glVertex2f(-0.82f, 0.8f);

    glVertex2f(-0.99f, 0.47f);
    glVertex2f(-1.12f, 0.47f);
    glVertex2f(-1.12f, 0.8f);
    glVertex2f(-0.99f, 0.8f);

    glVertex2f(-1.16f, 0.47f);
    glVertex2f(-1.28f, 0.47f);
    glVertex2f(-1.28f, 0.8f);
    glVertex2f(-1.16f, 0.8f);

    glVertex2f(-1.32f, 0.47f);
    glVertex2f(-1.4f, 0.47f);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.32f, 0.8f);

    glVertex2f(-1.42f, 0.47f);
    glVertex2f(-1.52f, 0.47f);
    glVertex2f(-1.52f, 0.8f);
    glVertex2f(-1.42f, 0.8f);

    glVertex2f(-1.55f, 0.47f);
    glVertex2f(-1.65f, 0.47f);
    glVertex2f(-1.65f, 0.8f);
    glVertex2f(-1.55f, 0.8f);

    glVertex2f(-1.69f, 0.47f);
    glVertex2f(-1.78f, 0.47f);
    glVertex2f(-1.78f, 0.8f);
    glVertex2f(-1.69f, 0.8f);

    //down
    glVertex2f(-1.32f, 0.4f);
    glVertex2f(-1.4f, 0.4f);
    glVertex2f(-1.4f, 0.07f);
    glVertex2f(-1.32f, 0.07f);

    glVertex2f(-1.42f, 0.4f);
    glVertex2f(-1.52f, 0.4f);
    glVertex2f(-1.52f, 0.07f);
    glVertex2f(-1.42f, 0.07f);

    glVertex2f(-1.55f, 0.4f);
    glVertex2f(-1.65f, 0.4f);
    glVertex2f(-1.65f, 0.07f);
    glVertex2f(-1.55f, 0.07f);

    glVertex2f(-1.69f, 0.4f);
    glVertex2f(-1.78f, 0.4f);
    glVertex2f(-1.78f, 0.07f);
    glVertex2f(-1.69f, 0.07f);
    //very down
    glVertex2f(-1.32f, 0.0f);
    glVertex2f(-1.4f, 0.0f);
    glVertex2f(-1.4f, -0.33f);
    glVertex2f(-1.32f, -0.33f);

    glVertex2f(-1.42f, 0.0f);
    glVertex2f(-1.52f, 0.0f);
    glVertex2f(-1.52f, -0.33f);
    glVertex2f(-1.42f, -0.33f);

    glVertex2f(-1.55f, 0.0f);
    glVertex2f(-1.65f, 0.0f);
    glVertex2f(-1.65f, -0.33f);
    glVertex2f(-1.55f, -0.33f);

    glVertex2f(-1.69f, 0.0f);
    glVertex2f(-1.78f, 0.0f);
    glVertex2f(-1.78f, -0.33f);
    glVertex2f(-1.69f, -0.33f);

    //last down
    glVertex2f(-1.32f, -0.4f);
    glVertex2f(-1.4f, -0.4f);
    glVertex2f(-1.4f, -0.73f);
    glVertex2f(-1.32f, -0.73f);

    glVertex2f(-1.42f, -0.4f);
    glVertex2f(-1.52f, -0.4f);
    glVertex2f(-1.52f, -0.73f);
    glVertex2f(-1.42f, -0.73f);

    glVertex2f(-1.55f, -0.4f);
    glVertex2f(-1.65f, -0.4f);
    glVertex2f(-1.65f, -0.73f);
    glVertex2f(-1.55f, -0.73f);

    glVertex2f(-1.69f, -0.4f);
    glVertex2f(-1.78f, -0.4f);
    glVertex2f(-1.78f, -0.73f);
    glVertex2f(-1.69f, -0.73f);

    //for long doom
    glVertex2f(-1.44f, 1.45f);
    glVertex2f(-1.44f, 1.12f);
    glVertex2f(-1.52f, 1.12f);
    glVertex2f(-1.52f, 1.45f);

    glVertex2f(-1.55f, 1.45f);
    glVertex2f(-1.55f, 1.12f);
    glVertex2f(-1.65f, 1.12f);
    glVertex2f(-1.65f, 1.45f);

    glVertex2f(-1.69f, 1.45f);
    glVertex2f(-1.69f, 1.12f);
    glVertex2f(-1.78f, 1.12f);
    glVertex2f(-1.78f, 1.45f);
    glEnd();

    //down part
    /*
    glBegin(GL_QUADS);
	glColor3ub(153, 102, 51);
	glVertex2f(-0.7f, -1.0f);
    glVertex2f(-0.7f, -1.2f);
    glVertex2f(-2.0f, -1.2f);
    glVertex2f(-1.8f, -1.0f);
    glEnd();

    */


glTranslatef(0.11f,0.00f,0.00f);


// drawing axis

    //glLoadIdentity();

}
void tushar_with_light()
{
    //  Tushar
{


// squre + door

 glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.70+0.2, 1.00+0.2);
glColor3ub(255,153,51);
glVertex2f(0.70+0.2, -1.00);
glColor3ub(255,153,51);

glVertex2f(-0.70-0.2, -1.00);
 glColor3ub(205,133,63);
//glColor3f(1.00f,0.00f,0.00f);
glVertex2f(-0.70-0.2, 1.00+0.2);
glEnd();


//float xx1 = 0.70f, yy1= 1.00f; // Tushar
//???????????????????????
// door                                                         // door
{


//base 1

/*
 glBegin(GL_QUADS);
//glColor3ub(255,255,255);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);
//glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();


//2
 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);

glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();
glColor3ub(128,128,128);

*/
glColor3f(0.00f,0.00f,0.00f);
//+3
		 x=0.120f;  y=0.0f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//-3

			 x=-0.120f;  y=0.0f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-4


				 x=-0.110f;  y=0.05f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//4

				 x=0.110f;  y=0.05f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-5

				 x=-0.09f;  y=0.1f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//5

					 x=0.09f;  y=0.1f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-6

					 x=-0.05f;  y=0.15f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//6


					 x=0.05f;  y=0.15f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//door base


 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);

glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();
glColor3ub(128,128,128);


//7
//door up

 glBegin(GL_TRIANGLES);
 //glColor3f(1.00f,1.00f,1.00f);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(0.29f, 0.15f);
glVertex2f(-0.29f, 0.15f);
glColor3f(0.00f,0.00f,0.00f);
//glColor3f(1.00f,1.00f,1.00f);
glVertex2f(-0.0f, 0.55f);


glEnd();
//??????????????????????????
// small door




//base 1
 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.18f, -0.30);
glVertex2f(0.18f, -0.30f);
glVertex2f(0.18f, -01.0f);
glVertex2f(-0.18f, -01.0f);
glEnd();


//-2

					 x=-0.08f;  y=-0.29f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//2

					 x=0.08f;  y=-0.29f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//-3

					 x=-0.07f;  y=-0.25f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//3

					 x=0.07f;  y=-0.25f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//4



					 x=0.05f;  y=-0.2f; triangleAmount =100;radius =.103f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-4


					 x=-0.05f;  y=-0.2f; triangleAmount =100;radius =.103f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//5
glTranslatef(0.00f,0.025f,0.00f);

	 glBegin(GL_TRIANGLES);
 glColor3f(0.00f,0.00f,0.00f);

glVertex2f(-0.13f, -0.15f);
glVertex2f(0.13f, -0.15f);
glVertex2f(-0.0f, 0.05f);


glEnd();


glTranslatef(0.00f,-0.025f,0.00f);
}
////////////////// end door ///////////////////////////

//???????????????????????
///////////////////////////                       //piler  1
glTranslatef(-0.050f,0.00f,0.00f);
{



 glBegin(GL_QUADS);
 glColor3ub(244,164,96);
//glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.68f, 01.30f);
glVertex2f(0.68f, -01.0f);
glVertex2f(0.75f, -01.0f);
glColor3f(1.00f,1.00f,1.00f);
glVertex2f(0.75f, 01.30f);

glEnd();





					 x=0.715f;  y=01.32f; triangleAmount =100;radius =.035f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





	 glBegin(GL_POLYGON);
// glColor3f(01.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.30f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.30f);

glEnd();




glBegin(GL_QUADS);
 //glColor3f(1.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.350f);
glVertex2f(0.73f, 01.40f);

glVertex2f(0.70f, 01.40f);
glVertex2f(0.680f, 01.350f);
glEnd();




  // piler zig zap art                                                 // piler zig zap art

//1

glTranslatef(0.00f,-0.40f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,0.40f,0.00f);


//2

glTranslatef(0.00f,-0.80f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,0.80f,0.00f);



//3
glTranslatef(0.00f,-01.20f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.20f,0.00f);


//4
glTranslatef(0.00f,-01.60f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.60f,0.00f);


//5
glTranslatef(0.00f,-02.30f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,02.30f,0.00f);


//5
//uper stick

glTranslatef(0.00f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.35f);
glVertex2f(0.719f, 01.50f);

glVertex2f(0.710f, 01.50f);
glVertex2f(0.710f, 01.35f);

glEnd();

glTranslatef(0.00f,-0.04f,0.00f);

/*
//side bar
//2 sid
glTranslatef(0.0310f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.718f, -01.05f);
glVertex2f(0.718f, 01.28f);

glEnd();

glTranslatef(-0.0310f,-0.04f,0.00f);


//middle side

//glTranslatef(-0.0590f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

//glTranslatef(0.0590f,-0.04f,0.00f);




//-2 side

glTranslatef(-0.0250f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.705f, 01.28f);
glVertex2f(0.705f, -01.05f);

glVertex2f(0.706f, -01.05f);
glVertex2f(0.706f, 01.28f);

glEnd();

*/

glTranslatef(0.0250f,-0.04f,0.00f);

}
glTranslatef(0.050f,0.00f,0.00f);



//???????????????????????
///////////////////////////                       //piler  2
//glTranslatef(-01.450f,0.0f,0.00f);
glTranslatef(-01.42f,0.05f,0.00f);

{




 glBegin(GL_QUADS);
 glColor3ub(244,164,96);
//glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.68f, 01.30f);
glVertex2f(0.68f, -01.0f);
glColor3ub(205,133,63);
glVertex2f(0.75f, -01.0f);
glColor3f(1.00f,1.00f,1.00f);
glVertex2f(0.75f, 01.30f);

glEnd();





					 x=0.715f;  y=01.32f; triangleAmount =100;radius =.035f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





	 glBegin(GL_POLYGON);
// glColor3f(01.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.30f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.30f);

glEnd();




glBegin(GL_QUADS);
 //glColor3f(1.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.350f);
glVertex2f(0.73f, 01.40f);

glVertex2f(0.70f, 01.40f);
glVertex2f(0.680f, 01.350f);
glEnd();




  // piler zig zap art                                                 // piler zig zap art

//1

glTranslatef(0.00f,-0.40f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,0.40f,0.00f);


//2

glTranslatef(0.00f,-0.80f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,0.80f,0.00f);



//3
glTranslatef(0.00f,-01.20f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.20f,0.00f);


//4
glTranslatef(0.00f,-01.60f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.60f,0.00f);


//5
glTranslatef(0.00f,-02.30f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,02.30f,0.00f);


//5
//uper stick

glTranslatef(0.00f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.35f);
glVertex2f(0.719f, 01.50f);

glVertex2f(0.710f, 01.50f);
glVertex2f(0.710f, 01.35f);

glEnd();

glTranslatef(0.00f,-0.04f,0.00f);

/*
//side bar
//2 sid
glTranslatef(0.0310f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

glTranslatef(-0.0310f,-0.04f,0.00f);


//middle side

//glTranslatef(-0.0590f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

//glTranslatef(0.0590f,-0.04f,0.00f);




//-2 side

glTranslatef(-0.0250f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.705f, 01.28f);
glVertex2f(0.705f, -01.05f);

glVertex2f(0.706f, -01.05f);
glVertex2f(0.706f, 01.28f);

glEnd();

glTranslatef(0.0250f,-0.04f,0.00f);





*/
}
glTranslatef(01.40f,-0.01f,0.00f);



//??????????????????????
//doom

//	float xx1 = 0.70f, yy1= 1.00f; // Tushar
{
// level 1                                     // level 1



 glBegin(GL_QUADS);
 glColor3f(1.00f,1.00f,1.00f);

glVertex2f(0.13f, 01.35f);
glVertex2f(0.13f, 1.2f);
glVertex2f(-0.13f, 1.2f);
glVertex2f(-0.13f, 1.35f);

glEnd();


glBegin(GL_QUADS);
 glColor3f(1.00f,0.00f,0.00f);
glVertex2f(-0.13f, 01.2f);
glVertex2f(-0.13f, 1.35f);
glVertex2f(-0.3f, 1.3f);
glVertex2f(-0.3f, 1.2f);


glEnd();

glBegin(GL_QUADS);
 glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.13f, 01.2f);
glVertex2f(0.13f, 1.35f);
glVertex2f(0.3f, 1.3f);
glVertex2f(0.3f, 1.2f);


glEnd();
// level 1                                     // level 1

// level 2                                     // level 2

//153,92,0
glBegin(GL_QUADS);
 glColor3ub(11, 61, 15);

glVertex2f(0.13f, 01.35f);
glVertex2f(0.13f, 1.38f);
glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.13f, 1.35f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(153,92,0);

glVertex2f(-0.13f, 1.35f);
glVertex2f(-0.3f, 1.3f);
glVertex2f(-0.3f, 1.33f);
glVertex2f(-0.13f, 1.38f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(153,92,0);
glVertex2f(0.13f, 01.35f);
glVertex2f(0.3f, 1.3f);
glVertex2f(0.3f, 1.33f);
glVertex2f(0.13f, 1.38f);


glEnd();


// level 2                                     // level 2

// level 3                                     // level 3

//51,31,0
glBegin(GL_QUADS);
 glColor3ub(51,31,0);

glVertex2f(0.13f, 01.45f);
glVertex2f(0.13f, 1.38f);
glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.13f, 1.45f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(51,31,0);

glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.3f, 1.33f);
glVertex2f(-0.3f, 1.37f);
glVertex2f(-0.13f, 1.45f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(51,31,0);
glVertex2f(0.13f, 01.38f);
glVertex2f(0.3f, 1.33f);
glVertex2f(0.3f, 1.37f);
glVertex2f(0.13f, 1.45f);


glEnd();


// level 3                                     // level 3

// level 4                                     // level 4   // main circle doom


glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(0.13f, 01.60f);
glVertex2f(0.135f, 1.45f);
glVertex2f(-0.14f, 1.45f);
glVertex2f(-0.13f, 1.60f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.13f, 1.60f);
glVertex2f(-0.28f, 1.60f);
glVertex2f(-0.29f, 1.37f);
glVertex2f(-0.13f, 1.45f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.13f, 1.60f);
glVertex2f(0.28f, 1.60f);
glVertex2f(0.29f, 1.37f);
glVertex2f(0.13f, 1.45f);


glEnd();





// level 4                                     // level 4

// level 5                                     // level 5


glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(0.12f, 01.70f);
glVertex2f(0.13f, 1.60f);
glVertex2f(-0.13f, 1.60f);
glVertex2f(-0.12f, 1.70f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.12f, 1.70f);
glVertex2f(-0.26f, 1.70f);
glVertex2f(-0.28f, 1.60f);
glVertex2f(-0.13f, 1.60f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.12f, 1.70f);
glVertex2f(0.26f, 1.70f);
glVertex2f(0.28f, 1.60f);
glVertex2f(0.13f, 1.60f);


glEnd();





// level 5                                     // level 5

// level 6                                     // level 6


glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(0.11f, 01.80f);
glVertex2f(0.12f, 1.70f);
glVertex2f(-0.12f, 1.70f);
glVertex2f(-0.11f, 1.80f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.11f, 1.80f);
glVertex2f(-0.23f, 1.80f);
glVertex2f(-0.26f, 1.70f);
glVertex2f(-0.12f, 1.70f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.11f, 1.80f);
glVertex2f(0.23f, 1.80f);
glVertex2f(0.26f, 1.70f);
glVertex2f(0.12f, 1.70f);


glEnd();





// level 6                                     // level 6

// level 7                                     // level 7


glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(0.09f, 01.90f);
glVertex2f(0.11f, 1.80f);
glVertex2f(-0.11f, 1.80f);
glVertex2f(-0.09f, 1.90f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(-0.08f, 1.90f);
glVertex2f(-0.14f, 1.90f);
glVertex2f(-0.23f, 1.80f);
glVertex2f(-0.11f, 1.80f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,0,0);
glVertex2f(0.08f, 1.90f);
glVertex2f(0.14f, 1.90f);
glVertex2f(0.23f, 1.80f);
glVertex2f(0.11f, 1.80f);


glEnd();





// level 7                                     // level 7



// level 8                                     // level 8


glBegin(GL_QUADS);
 glColor3ub(11, 61, 15);

glVertex2f(0.01f, 02.00f);
glVertex2f(0.08f, 1.90f);
glVertex2f(-0.08f, 1.90f);
glVertex2f(-0.01f, 2.00f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(-0.01f, 2.0f);
glVertex2f(-0.01f, 2.0f);
glVertex2f(-0.14f, 1.90f);
glVertex2f(-0.084f, 1.90f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(0.01f, 2.0f);
glVertex2f(0.01f, 2.0f);
glVertex2f(0.14f, 1.90f);
glVertex2f(0.084f, 1.90f);


glEnd();





// level 8                                     // level 8


//end lavel                                         //end level of main doom

/*
 x=0.0f;  y=02.01f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

*/


	/////
//stick
glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-0.005f, 2.00f);
glVertex2f(-0.005f, 2.3f);
glVertex2f(0.005f, 2.3f);
glVertex2f(0.005f, 2.00f);


glEnd();


// rectangle on stick

glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(0.0f, 2.0f);
glVertex2f(0.03f, 2.02f);
glVertex2f(0.0f, 2.05f);
glVertex2f(-0.03f, 2.02f);
glEnd();



//glTranslatef(0.00f,0.10f,0.00f);

	glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(0.0f, 2.0f);
glVertex2f(0.03f, 2.02f);
glVertex2f(0.0f, 2.05f);
glVertex2f(-0.03f, 2.02f);



glEnd();

//glLoadIdentity();
	////

//glTranslatef(0.00f,0.0f,0.00f);





	 x=0.0f;  y=02.08f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=0.0f;  y=02.14f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//end lavel                                         //end level of main doom

/*
int lineAmount = 100; //# of triangles used to draw circle
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


*/

/*
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


*/





}










//??????????????????????????????   start      ????????????????????????????????????
// measurment


	//???????????????????????????????????????????????????????????????????????
	 //boz                                                        box

{
    glColor3ub(255, 166, 77);
    {



/*

   glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.28f, 0.37f);
    glVertex2f(-0.35f, 0.37f);
    glVertex2f(-0.35f, 0.68f);
    glVertex2f(-0.28f, 0.68f);

    glEnd();




*/


  //    glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.38f, -0.65f);
    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.45f, 0.850f);
    glVertex2f(-0.38f, 0.850f);

    glEnd();




glTranslatef(0.80f,0.00f,0.00f);

    glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.38f, -0.65f);
    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.45f, 0.850f);
    glVertex2f(-0.38f, 0.850f);

    glEnd();

glTranslatef(-0.80f,0.00f,0.00f);




//  glColor3ub(255, 166, 77);



    glEnd();



//glTranslatef(0.00f,-0.600f,0.00f);





   // glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(0.35f, 0.67f);
    glVertex2f(-0.38f, 0.67f);
    glVertex2f(-0.38f, 0.85f);
    glVertex2f(0.35f, 0.85f);

    glEnd();
}

//???????????????????????


// 2nd  side  box coloum


{



 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





 //glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}



/////////////////////////////////////
//???????????????
//3 rd side boz colum


glTranslatef(01.070f,0.00f,0.00f);


{



 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(-01.070f,0.00f,0.00f);


//???????????????????????????????
//4th colum  of box

glTranslatef(01.35f,0.00f,0.00f);


{



// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(-01.35f,0.00f,0.00f);

//6 th colum box

glTranslatef(-0.27f,0.00f,0.00f);


{



// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(0.27f,0.00f,0.00f);

}


//????????????????????????????????????????????????????????????????????????

//botom stair
{



glTranslatef(0.00f,0.300f,0.00f);

           glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(01.91f, -01.3f);
    glVertex2f(-01.92f,- 01.3f);
    glVertex2f(-01.92f,- 01.37f);
    glVertex2f(01.91f, -01.37f);

    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);




           glColor3ub(128,128,128);
	glBegin(GL_QUADS);
	glVertex2f(01.91f, -01.07f);
    glVertex2f(-01.92f,- 01.07f);
    glVertex2f(-02.02f,- 01.30f);
    glVertex2f(02.02f, -01.30f);

    glEnd();



   glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(02.02f, -01.3f);
    glVertex2f(-02.02f,- 01.3f);
    glVertex2f(-02.02f,- 01.37f);
    glVertex2f(02.02f, -01.37f);

    glEnd();
//????????????????????????????????????????????????????????????????????????
//pond

	glBegin(GL_QUADS);
	 glColor3f(0.00f,0.00f,0.00f);
	glVertex2f(00.40f, -01.13f);
//	 glColor3f(01.00f,01.00f,01.00f);
    glVertex2f(-00.40f,- 01.13f);
 glColor3f(0.00f,0.00f,0.00f);
    glVertex2f(-00.50f,- 01.23f);
     glColor3f(01.00f,01.00f,01.00f);
    glVertex2f(00.50f, -01.23f);

    glEnd();




//?????????????????????????????????????????????????????????????????
//mark on the whole building
//left

glTranslatef(0.00f,0.300f,0.00f);
glColor3ub(205,133,63);
           //glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.820f, 0.580f);
    glVertex2f(-01.91f, 0.580f);
    glVertex2f(-01.91f, 00.60f);
    glVertex2f(-0.820f, 0.60f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);

//right


glTranslatef(0.00f,0.300f,0.00f);

      glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.580f);
    glVertex2f(01.91f, 0.580f);
    glVertex2f(01.91f, 00.60f);
    glVertex2f(0.820f, 0.60f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);

//middle

glTranslatef(0.00f,0.300f,0.00f);

   glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.75f);
    glVertex2f(-0.82f, 0.75f);
    glVertex2f(-0.82f, 00.73f);
    glVertex2f(0.820f, 0.73f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);


//link right
glTranslatef(0.00f,0.330f,0.00f);

   glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.57f);
    glVertex2f(0.83f, 0.57f);
    glVertex2f(0.83f, 00.719f);
    glVertex2f(0.820f, 0.719f);


    glEnd();
glTranslatef(0.00f,-0.330f,0.00f);

//link left

glTranslatef(0.00f,0.330f,0.00f);

      glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(-0.820f, 0.57f);
    glVertex2f(-0.83f, 0.57f);
    glVertex2f(-0.83f, 00.719f);
    glVertex2f(-0.820f, 0.719f);


    glEnd();
glTranslatef(0.00f,-0.330f,0.00f);



}


}


}

void salem()
{
glTranslatef(0.00f,-0.3550f,0.00f);

{



// measurment




    glBegin(GL_QUADS);
     glColor3ub(11, 61, 15);
    glVertex2f(-2.1,-2.3f);
    glVertex2f( 2.1f,-2.3f);
    glVertex2f( 2.1f,-1.1f);
    glVertex2f(-2.1f,-1.1f);
    glEnd();



    //road
 glBegin(GL_QUADS);
    glColor3ub(160,160,160);
    glVertex2f(-1.9f,-2.3f);
    glVertex2f(1.9f,-2.3f);
    glVertex2f(1.2f,-1.0f);
    glVertex2f(-1.2f,-1.0f);
    glEnd();






    //  Black line
 glBegin(GL_QUADS);
   glColor3ub(0, 0, 0  );
    glVertex2f(-1.11f,-2.3f);
    glVertex2f( 1.02f, -2.3f);
    glVertex2f( 0.59f, -1.08f);
    glVertex2f( -0.58f, -1.08f);
glEnd();



//wall







    glBegin(GL_QUADS);
glColor3ub(0, 255, 255 );
    glVertex2f(-1.08f,-2.3f);
    glVertex2f( 0.98f, -2.3f);
    glVertex2f( 0.55f, -1.1f);
    glVertex2f( -0.55f, -1.1f);
glEnd();



    //tiles
 glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-1.04f,-2.2f);
              glVertex2f(0.955f, -2.2f);
              glEnd();



               glBegin(GL_LINES);
              glColor3ub(128, 128, 128 );
              glVertex2f(-0.95f,-2.0f);
              glVertex2f(0.88f, -2.0f);
              glEnd();



               glBegin(GL_LINES);
              glColor3ub(128, 128, 128 );
              glVertex2f(-0.87f,-1.8f);
              glVertex2f(0.798f, -1.8f);
              glEnd();
              glBegin(GL_LINES);
              glColor3ub(128, 128, 128 );
              glVertex2f(-0.78f,-1.6f);
              glVertex2f(0.73f, -1.6f);
              glEnd();
              glBegin(GL_LINES);
              glColor3ub(128, 128, 128 );
              glVertex2f(-0.69f,-1.4f);
              glVertex2f(0.66f, -1.4f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.59f,-1.17f);
              glVertex2f(0.59f, -1.17f);
              glEnd();
//vertical line
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-1.04f,-2.3f);
              glVertex2f(-0.51f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.98f,-2.3f);
              glVertex2f(-0.45f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.92f,-2.3f);
              glVertex2f(-0.39f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.86f,-2.3f);
              glVertex2f(-0.33f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.80f,-2.3f);
              glVertex2f(-0.27f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.74f,-2.3f);
              glVertex2f(-0.21f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.68f,-2.3f);
              glVertex2f(-0.15f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.62f,-2.3f);
              glVertex2f(-0.09f, -1.1f);
              glEnd();



               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.56f,-2.3f);
              glVertex2f(-0.03f, -1.1f);
              glEnd();



              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
              glVertex2f(-0.51f,-2.3f);
              glVertex2f(0.03f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.92f, -2.3f);
            glVertex2f( 0.49f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.86f, -2.3f);
            glVertex2f( 0.43f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.81f, -2.3f);
            glVertex2f( 0.37f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.75f, -2.3f);
            glVertex2f( 0.31f, -1.1f);
              glEnd();
              glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.25f, -2.3f);
            glVertex2f( 0.25f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.19f, -2.3f);
            glVertex2f( 0.19f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.13f, -2.3f);
            glVertex2f( 0.13f, -1.1f);
              glEnd();
               glBegin(GL_LINES);
             glColor3ub(128, 128, 128 );
             glVertex2f( 0.07f, -2.3f);
            glVertex2f( 0.07f, -1.1f);
              glEnd();




//middle
     glBegin(GL_QUADS);
    glColor3ub(96, 96, 96 );
    glVertex2f(-0.9f,-2.3f);
    glVertex2f( 0.8f, -2.3f);
    glVertex2f( 0.5f, -1.2f);
    glVertex2f( -0.5f, -1.2f);
    glEnd();



    //Water
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.12f, -2.3f);
    glVertex2f( -0.009f, -2.3f);
    glVertex2f( -0.038f, -2.1f);
    glVertex2f( -0.09f, -2.1f);
    glEnd();





glBegin(GL_POLYGON);



for(int i=0;i<200;i++)



{



glColor3ub(255, 255, 255);



float pi=3.1416;



float A=(i*2*pi)/200;



float r=0.06;



float x = r * cos(A);



float y = r * sin(A);



glVertex2f(-0.062+x,-2.1+y);



}



glEnd();



//water 2





 glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.12f, -1.97f);
    glVertex2f( -0.009f, -1.97f);
    glVertex2f( -0.038f, -1.77f);
    glVertex2f( -0.09f, -1.77f);
    glEnd();





glBegin(GL_POLYGON);



for(int i=0;i<200;i++)



{



glColor3ub(255, 255, 255);



float pi=3.1416;



float A=(i*2*pi)/200;



float r=0.06;



float x = r * cos(A);



float y = r * sin(A);



glVertex2f(-0.062+x,-1.76+y);



}



glEnd();



    //water 3
     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.12f, -1.58f);
    glVertex2f( -0.009f, -1.58f);
    glVertex2f( -0.038f, -1.4f);
    glVertex2f( -0.09f, -1.4f);
    glEnd();



glBegin(GL_POLYGON);



for(int i=0;i<200;i++)



{



glColor3ub(255, 255, 255);



float pi=3.1416;



float A=(i*2*pi)/200;



float r=0.06;



float x = r * cos(A);



float y = r * sin(A);



glVertex2f(-0.062+x,-1.36+y);



}



glEnd();



    //left tree
    glTranslatef(-0.10f,0.00f,0.00f);
  glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-1.85f,-2.3f);
    glVertex2f( -1.82f,-2.3f);
    glVertex2f( -1.82f,-1.95f);
    glVertex2f(-1.85f,-1.95f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(-2.1f,-2.09f);
    glVertex2f(-1.6f,-2.09f);
    glVertex2f(-1.8f,-1.90f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(-2.06f,-1.98f);
    glVertex2f(-1.61f,-1.98f);
    glVertex2f(-1.8f,-1.80f);
    glEnd();


     glBegin(GL_TRIANGLES);
    glColor3ub( 60, 128, 3);
    glVertex2f(-2.02f,-1.89f);
    glVertex2f(-1.62f,-1.89f);
    glVertex2f(-1.81f,-1.75f);



    glEnd();
    glTranslatef(0.10f,0.00f,0.00f);
//left second treew



 glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-1.85f,-1.70f);
    glVertex2f( -1.82f,-1.70f);
    glVertex2f( -1.82f,-1.55f);
    glVertex2f(-1.85f,-1.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(-2.1f,-1.55f);
    glVertex2f(-1.6f,-1.55f);
    glVertex2f(-1.81f,-1.41f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(-2.06f,-1.46f);
    glVertex2f(-1.61f,-1.46f);
    glVertex2f(-1.8f,-1.31f);
     glEnd();


     glBegin(GL_TRIANGLES);
    glColor3ub( 60, 128, 3);
    glVertex2f(-2.02f,-1.37f);
    glVertex2f(-1.62f,-1.37f);
    glVertex2f(-1.81f,-1.22f);



    glEnd();





////



    ////



    //Right tree





     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(1.87f,-1.70f);
    glVertex2f( 1.84f,-1.70f);
    glVertex2f( 1.84f,-1.55f);
    glVertex2f(1.87f,-1.55f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(2.1f,-1.55f);
    glVertex2f(1.6f,-1.55f);
    glVertex2f(1.82f,-1.41f);
glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(2.06f,-1.46f);
    glVertex2f(1.61f,-1.46f);
    glVertex2f(1.81f,-1.31f);
glEnd();


     glBegin(GL_TRIANGLES);
    glColor3ub( 60, 128, 3);
    glVertex2f(2.02f,-1.37f);
    glVertex2f(1.62f,-1.37f);
    glVertex2f(1.82f,-1.22f);



    glEnd();






//right second treew

glTranslatef(0.10f,0.00f,0.00f);

 glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(1.85f,-2.3f);
    glVertex2f( 1.82f,-2.3f);
    glVertex2f( 1.82f,-1.95f);
    glVertex2f(1.85f,-1.95f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(2.1f,-2.09f);
    glVertex2f(1.6f,-2.09f);
    glVertex2f(1.8f,-1.90f);
   glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(60, 128, 3);
    glVertex2f(2.06f,-1.98f);
    glVertex2f(1.61f,-1.98f);
    glVertex2f(1.8f,-1.80f);

    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3ub( 60, 128, 3);
    glVertex2f(2.02f,-1.89f);
    glVertex2f(1.62f,-1.89f);
    glVertex2f(1.81f,-1.75f);



    glEnd();



glTranslatef(-0.10f,0.00f,0.00f);


//

glLoadIdentity();


// drawing axis

/*
	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();
*/





}

    glTranslatef(0.00f,0.3550f,0.00f);
    glFlush();
}


void building_no_light(){
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;
	//right side
glTranslatef(0.11f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(0.7f, 1.0f);
    glVertex2f(0.7f, -1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(1.4f, 1.0f);

    glColor3ub(255, 153, 51);
     glVertex2f(1.4f, -1.0f);
	glVertex2f(1.53f, -1.0f);
    glVertex2f(1.53f, 1.5f);
     glVertex2f(1.4f, 1.5f);

     glColor3ub(255, 153, 51);
     glVertex2f(1.53f, -1.0f);
     glVertex2f(1.67f, -1.0f);
    glVertex2f(1.67f, 1.5f);
     glVertex2f(1.53f, 1.5f);

     glColor3ub(255, 153, 51);
      glVertex2f(1.67f, -1.0f);
     glVertex2f(1.8f, -1.0f);
    glVertex2f(1.8f, 1.5f);
     glVertex2f(1.67f, 1.5f);
     glEnd();
     //box
     glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(0.8f, -1.0f);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, 0.4f);
    glVertex2f(0.8f, 0.4f);
    glEnd();


       glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
      glVertex2f(0.8f, -1.0f);
      glColor3f(0.00,0.00,0.00);
     glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, 0.1f);
     glVertex2f(1.05f, 0.3f);
     glVertex2f(0.8f, 0.1f);
    glEnd();


      glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
      glVertex2f(0.95f, -1.0f);
     glVertex2f(1.15f, -1.0f);
    glVertex2f(1.15f, -0.1f);
     glVertex2f(0.95f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
      glVertex2f(0.95f, 0.0f);
     glVertex2f(1.15f, 0.0f);
    glVertex2f(1.15, 0.05f);
     glVertex2f(1.05f, 0.1f);
     glVertex2f(0.95f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
	glVertex2f(0.85f, 1.0f);
     glVertex2f(1.05f, 1.0f);
    glVertex2f(1.05f, 1.05f);
     glVertex2f(0.97f, 1.20f);
     glVertex2f(0.93f, 1.20f);
      glVertex2f(0.85f, 1.05f);
      glEnd();
       //stick
      glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(0.94f, 1.20f);
     glVertex2f(0.95f, 1.20f);
    glVertex2f(0.95f, 1.32f);
     glVertex2f(0.94f, 1.32f);


glEnd();
//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(0.945f, 1.20f);
     glVertex2f(0.955f, 1.22f);
    glVertex2f(0.945f, 1.24f);
     glVertex2f(0.935f, 1.22f);
     glEnd();

//round on stick
GLfloat x=0.945f,  y=1.29f, radius =.01f;
int i;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=0.945f;  y=1.26f; radius =.01f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//doom
	glBegin(GL_POLYGON);
	glColor3ub(255, 102, 0);
    glVertex2f(1.8f, 1.5f);
    glVertex2f(1.85f, 1.5f);
    glVertex2f(1.9f, 1.54f);
    glVertex2f(1.8f, 1.57f);
    glVertex2f(1.4f, 1.57f);
    glVertex2f(1.3f, 1.54f);
    glVertex2f(1.35f, 1.5f);


    glEnd();
    //doom head
    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
    glVertex2f(1.8f, 1.57f);
    glVertex2f(1.8f, 1.7f);
    glVertex2f(1.63f, 1.8f);
    glVertex2f(1.63f, 1.83f);
    glVertex2f(1.57f, 1.83f);
    glVertex2f(1.57f, 1.8f);
    glVertex2f(1.4f, 1.7f);
    glVertex2f(1.4f, 1.57f);
    glEnd();
     glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(1.59f, 1.83f);
     glVertex2f(1.61f, 1.83f);
    glVertex2f(1.61f, 2.1f);
     glVertex2f(1.59f, 2.1f);


glEnd();

//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(1.6f, 1.83f);
     glVertex2f(1.63f, 1.85f);
    glVertex2f(1.6f, 1.88f);
     glVertex2f(1.57f,1.85f);
     glEnd();

//round on stick
 x=1.6f;  y=1.92f; radius =.03f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=1.6f;  y=2.0f; radius =.03f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//long doom
		 x=1.3f;  y=1.3f; radius =.03f;
glColor3ub(255, 153, 51);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(1.27f, 1.3f);
    glVertex2f(1.27f, 1.0f);
    glVertex2f(1.33f, 1.0f);
    glVertex2f(1.33f, 1.3f);
    glEnd();
    //long doom stick
    glBegin(GL_QUADS);
	glColor3ub(1, 1, 1);
	glVertex2f(1.29f, 1.33f);
    glVertex2f(1.3f, 1.33f);
    glVertex2f(1.3f, 1.40f);
    glVertex2f(1.29f, 1.40f);
    glEnd();
    //long doom rectangle


    x=1.294f;  y=1.35f; radius =.015f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//box
	glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(0.82f, 0.47f);
    glVertex2f(0.95f, 0.47f);
    glVertex2f(0.95f, 0.8f);
    glVertex2f(0.82f, 0.8f);

    glVertex2f(0.99f, 0.47f);
    glVertex2f(1.12f, 0.47f);
    glVertex2f(1.12f, 0.8f);
    glVertex2f(0.99f, 0.8f);

    glVertex2f(1.16f, 0.47f);
    glVertex2f(1.28f, 0.47f);
    glVertex2f(1.28f, 0.8f);
    glVertex2f(1.16f, 0.8f);

    glVertex2f(1.32f, 0.47f);
    glVertex2f(1.4f, 0.47f);
    glVertex2f(1.4f, 0.8f);
    glVertex2f(1.32f, 0.8f);

    glVertex2f(1.42f, 0.47f);
    glVertex2f(1.52f, 0.47f);
    glVertex2f(1.52f, 0.8f);
    glVertex2f(1.42f, 0.8f);

    glVertex2f(1.55f, 0.47f);
    glVertex2f(1.65f, 0.47f);
    glVertex2f(1.65f, 0.8f);
    glVertex2f(1.55f, 0.8f);

    glVertex2f(1.69f, 0.47f);
    glVertex2f(1.78f, 0.47f);
    glVertex2f(1.78f, 0.8f);
    glVertex2f(1.69f, 0.8f);

    //down
    glVertex2f(1.32f, 0.4f);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.4f, 0.07f);
    glVertex2f(1.32f, 0.07f);

    glVertex2f(1.42f, 0.4f);
    glVertex2f(1.52f, 0.4f);
    glVertex2f(1.52f, 0.07f);
    glVertex2f(1.42f, 0.07f);

    glVertex2f(1.55f, 0.4f);
    glVertex2f(1.65f, 0.4f);
    glVertex2f(1.65f, 0.07f);
    glVertex2f(1.55f, 0.07f);

    glVertex2f(1.69f, 0.4f);
    glVertex2f(1.78f, 0.4f);
    glVertex2f(1.78f, 0.07f);
    glVertex2f(1.69f, 0.07f);
    //very down
    glVertex2f(1.32f, 0.0f);
    glVertex2f(1.4f, 0.0f);
    glVertex2f(1.4f, -0.33f);
    glVertex2f(1.32f, -0.33f);

    glVertex2f(1.42f, 0.0f);
    glVertex2f(1.52f, 0.0f);
    glVertex2f(1.52f, -0.33f);
    glVertex2f(1.42f, -0.33f);

    glVertex2f(1.55f, 0.0f);
    glVertex2f(1.65f, 0.0f);
    glVertex2f(1.65f, -0.33f);
    glVertex2f(1.55f, -0.33f);

    glVertex2f(1.69f, 0.0f);
    glVertex2f(1.78f, 0.0f);
    glVertex2f(1.78f, -0.33f);
    glVertex2f(1.69f, -0.33f);

    //last down
    glVertex2f(1.32f, -0.4f);
    glVertex2f(1.4f, -0.4f);
    glVertex2f(1.4f, -0.73f);
    glVertex2f(1.32f, -0.73f);

    glVertex2f(1.42f, -0.4f);
    glVertex2f(1.52f, -0.4f);
    glVertex2f(1.52f, -0.73f);
    glVertex2f(1.42f, -0.73f);

    glVertex2f(1.55f, -0.4f);
    glVertex2f(1.65f, -0.4f);
    glVertex2f(1.65f, -0.73f);
    glVertex2f(1.55f, -0.73f);

    glVertex2f(1.69f, -0.4f);
    glVertex2f(1.78f, -0.4f);
    glVertex2f(1.78f, -0.73f);
    glVertex2f(1.69f, -0.73f);

    //for long doom
    glVertex2f(1.44f, 1.45f);
    glVertex2f(1.44f, 1.12f);
    glVertex2f(1.52f, 1.12f);
    glVertex2f(1.52f, 1.45f);

    glVertex2f(1.55f, 1.45f);
    glVertex2f(1.55f, 1.12f);
    glVertex2f(1.65f, 1.12f);
    glVertex2f(1.65f, 1.45f);

    glVertex2f(1.69f, 1.45f);
    glVertex2f(1.69f, 1.12f);
    glVertex2f(1.78f, 1.12f);
    glVertex2f(1.78f, 1.45f);
    glEnd();

    //down part
    /*
    glBegin(GL_QUADS);
	glColor3ub(153, 102, 51);
	glVertex2f(0.7f, -1.0f);
    glVertex2f(0.7f, -1.2f);
    glVertex2f(2.0f, -1.2f);
    glVertex2f(1.8f, -1.0f);
    glEnd();
*/


    glTranslatef(-0.11f,0.00f,0.00f);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


glTranslatef(-0.11f,0.00f,0.00f);

      //left side
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(-0.7f, 1.0f);
    glVertex2f(-0.7f, -1.0f);
    glVertex2f(-1.4f, -1.0f);
    glVertex2f(-1.4f, 1.0f);

    glColor3ub(255, 153, 51);
     glVertex2f(-1.4f, -1.0f);
	glVertex2f(-1.53f, -1.0f);
    glVertex2f(-1.53f, 1.5f);
     glVertex2f(-1.4f, 1.5f);

     glColor3ub(255, 153, 51);
     glVertex2f(-1.53f, -1.0f);
     glVertex2f(-1.67f, -1.0f);
    glVertex2f(-1.67f, 1.5f);
     glVertex2f(-1.53f, 1.5f);

     glColor3ub(255, 153, 51);
      glVertex2f(-1.67f, -1.0f);
     glVertex2f(-1.8f, -1.0f);
    glVertex2f(-1.8f, 1.5f);
     glVertex2f(-1.67f, 1.5f);
     glEnd();

     //box
     glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.8f, -1.0f);
    glVertex2f(-1.3f, -1.0f);
    glVertex2f(-1.3f, 0.4f);
    glVertex2f(-0.8f, 0.4f);
    glEnd();


        glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
      glVertex2f(-0.8f, -1.0f);
      glColor3f(0.00,0.00,0.00);
     glVertex2f(-1.3f, -1.0f);
    glVertex2f(-1.3f, 0.1f);
     glVertex2f(-1.05f, 0.3f);
     glVertex2f(-0.8f, 0.1f);
    glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
      glVertex2f(-0.95f, -1.0f);
     glVertex2f(-1.15f, -1.0f);
    glVertex2f(-1.15f, -0.1f);
     glVertex2f(-0.95f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
      glVertex2f(-0.95f, 0.0f);
     glVertex2f(-1.15f, 0.0f);
    glVertex2f(-1.15, 0.05f);
     glVertex2f(-1.05f, 0.1f);
     glVertex2f(-0.95f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
	glVertex2f(-0.85f, 1.0f);
     glVertex2f(-1.05f, 1.0f);
    glVertex2f(-1.05f, 1.05f);
     glVertex2f(-0.97f, 1.20f);
     glVertex2f(-0.93f, 1.20f);
      glVertex2f(-0.85f, 1.05f);
      glEnd();
       //stick
      glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-0.94f, 1.20f);
     glVertex2f(-0.95f, 1.20f);
    glVertex2f(-0.95f, 1.32f);
     glVertex2f(-0.94f, 1.32f);


glEnd();
//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(-0.945f, 1.20f);
     glVertex2f(-0.955f, 1.22f);
    glVertex2f(-0.945f, 1.24f);
     glVertex2f(-0.935f, 1.22f);
     glEnd();

//round on stick
 x=-0.945f;  y=1.29f; radius =.01f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=-0.945f;  y=1.26f; radius =.01f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//doom
	glBegin(GL_POLYGON);
	glColor3ub(255, 102, 0);
    glVertex2f(-1.8f, 1.5f);
    glVertex2f(-1.85f, 1.5f);
    glVertex2f(-1.9f, 1.54f);
    glVertex2f(-1.8f, 1.57f);
    glVertex2f(-1.4f, 1.57f);
    glVertex2f(-1.3f, 1.54f);
    glVertex2f(-1.35f, 1.5f);


    glEnd();
    //doom head
    glBegin(GL_POLYGON);
	glColor3ub(255, 153, 51);
    glVertex2f(-1.8f, 1.57f);
    glVertex2f(-1.8f, 1.7f);
    glVertex2f(-1.63f, 1.8f);
    glVertex2f(-1.63f, 1.83f);
    glVertex2f(-1.57f, 1.83f);
    glVertex2f(-1.57f, 1.8f);
    glVertex2f(-1.4f, 1.7f);
    glVertex2f(-1.4f, 1.57f);
    glEnd();
     glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-1.59f, 1.83f);
     glVertex2f(-1.61f, 1.83f);
    glVertex2f(-1.61f, 2.1f);
     glVertex2f(-1.59f, 2.1f);


glEnd();

//rectanagle on stick
glBegin(GL_QUADS);
glColor3ub(11, 61, 15);

glVertex2f(-1.6f, 1.83f);
     glVertex2f(-1.63f, 1.85f);
    glVertex2f(-1.6f, 1.88f);
     glVertex2f(-1.57f,1.85f);
     glEnd();

//round on stick
 x=-1.6f;  y=1.92f; radius =.03f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=-1.6f;  y=2.0f; radius =.03f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	//long doom
		 x=-1.3f;  y=1.3f; radius =.03f;
glColor3ub(255, 153, 51);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 153, 51);
	glVertex2f(-1.27f, 1.3f);
    glVertex2f(-1.27f, 1.0f);
    glVertex2f(-1.33f, 1.0f);
    glVertex2f(-1.33f, 1.3f);
    glEnd();
    //long doom stick
    glBegin(GL_QUADS);
	glColor3ub(1, 1, 1);
	glVertex2f(-1.29f, 1.33f);
    glVertex2f(-1.3f, 1.33f);
    glVertex2f(-1.3f, 1.40f);
    glVertex2f(-1.29f, 1.40f);
    glEnd();
    //long doom rectangle


    x=-1.294f;  y=1.35f; radius =.015f;
glColor3ub(11, 61, 15);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//box
	glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.82f, 0.47f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.95f, 0.8f);
    glVertex2f(-0.82f, 0.8f);

    glVertex2f(-0.99f, 0.47f);
    glVertex2f(-1.12f, 0.47f);
    glVertex2f(-1.12f, 0.8f);
    glVertex2f(-0.99f, 0.8f);

    glVertex2f(-1.16f, 0.47f);
    glVertex2f(-1.28f, 0.47f);
    glVertex2f(-1.28f, 0.8f);
    glVertex2f(-1.16f, 0.8f);

    glVertex2f(-1.32f, 0.47f);
    glVertex2f(-1.4f, 0.47f);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.32f, 0.8f);

    glVertex2f(-1.42f, 0.47f);
    glVertex2f(-1.52f, 0.47f);
    glVertex2f(-1.52f, 0.8f);
    glVertex2f(-1.42f, 0.8f);

    glVertex2f(-1.55f, 0.47f);
    glVertex2f(-1.65f, 0.47f);
    glVertex2f(-1.65f, 0.8f);
    glVertex2f(-1.55f, 0.8f);

    glVertex2f(-1.69f, 0.47f);
    glVertex2f(-1.78f, 0.47f);
    glVertex2f(-1.78f, 0.8f);
    glVertex2f(-1.69f, 0.8f);

    //down
    glVertex2f(-1.32f, 0.4f);
    glVertex2f(-1.4f, 0.4f);
    glVertex2f(-1.4f, 0.07f);
    glVertex2f(-1.32f, 0.07f);

    glVertex2f(-1.42f, 0.4f);
    glVertex2f(-1.52f, 0.4f);
    glVertex2f(-1.52f, 0.07f);
    glVertex2f(-1.42f, 0.07f);

    glVertex2f(-1.55f, 0.4f);
    glVertex2f(-1.65f, 0.4f);
    glVertex2f(-1.65f, 0.07f);
    glVertex2f(-1.55f, 0.07f);

    glVertex2f(-1.69f, 0.4f);
    glVertex2f(-1.78f, 0.4f);
    glVertex2f(-1.78f, 0.07f);
    glVertex2f(-1.69f, 0.07f);
    //very down
    glVertex2f(-1.32f, 0.0f);
    glVertex2f(-1.4f, 0.0f);
    glVertex2f(-1.4f, -0.33f);
    glVertex2f(-1.32f, -0.33f);

    glVertex2f(-1.42f, 0.0f);
    glVertex2f(-1.52f, 0.0f);
    glVertex2f(-1.52f, -0.33f);
    glVertex2f(-1.42f, -0.33f);

    glVertex2f(-1.55f, 0.0f);
    glVertex2f(-1.65f, 0.0f);
    glVertex2f(-1.65f, -0.33f);
    glVertex2f(-1.55f, -0.33f);

    glVertex2f(-1.69f, 0.0f);
    glVertex2f(-1.78f, 0.0f);
    glVertex2f(-1.78f, -0.33f);
    glVertex2f(-1.69f, -0.33f);

    //last down
    glVertex2f(-1.32f, -0.4f);
    glVertex2f(-1.4f, -0.4f);
    glVertex2f(-1.4f, -0.73f);
    glVertex2f(-1.32f, -0.73f);

    glVertex2f(-1.42f, -0.4f);
    glVertex2f(-1.52f, -0.4f);
    glVertex2f(-1.52f, -0.73f);
    glVertex2f(-1.42f, -0.73f);

    glVertex2f(-1.55f, -0.4f);
    glVertex2f(-1.65f, -0.4f);
    glVertex2f(-1.65f, -0.73f);
    glVertex2f(-1.55f, -0.73f);

    glVertex2f(-1.69f, -0.4f);
    glVertex2f(-1.78f, -0.4f);
    glVertex2f(-1.78f, -0.73f);
    glVertex2f(-1.69f, -0.73f);

    //for long doom
    glVertex2f(-1.44f, 1.45f);
    glVertex2f(-1.44f, 1.12f);
    glVertex2f(-1.52f, 1.12f);
    glVertex2f(-1.52f, 1.45f);

    glVertex2f(-1.55f, 1.45f);
    glVertex2f(-1.55f, 1.12f);
    glVertex2f(-1.65f, 1.12f);
    glVertex2f(-1.65f, 1.45f);

    glVertex2f(-1.69f, 1.45f);
    glVertex2f(-1.69f, 1.12f);
    glVertex2f(-1.78f, 1.12f);
    glVertex2f(-1.78f, 1.45f);
    glEnd();

    //down part
    /*
    glBegin(GL_QUADS);
	glColor3ub(153, 102, 51);
	glVertex2f(-0.7f, -1.0f);
    glVertex2f(-0.7f, -1.2f);
    glVertex2f(-2.0f, -1.2f);
    glVertex2f(-1.8f, -1.0f);
    glEnd();

    */


glTranslatef(0.11f,0.00f,0.00f);


// drawing axis

    //glLoadIdentity();

}
void tushar_no_light()

{


// squre + door

 glBegin(GL_QUADS);
glColor3ub(255,153,51);
glVertex2f(0.70+0.2, 1.00+0.2);
glVertex2f(0.70+0.2, -1.00);
glVertex2f(-0.70-0.2, -1.00);
glVertex2f(-0.70-0.2, 1.00+0.2);
glEnd();


//float xx1 = 0.70f, yy1= 1.00f; // Tushar
//???????????????????????
// door                                                         // door
{


//base 1

/*
 glBegin(GL_QUADS);
//glColor3ub(255,255,255);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);
//glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();


//2
 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);

glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();
glColor3ub(128,128,128);

*/
glColor3f(0.00f,0.00f,0.00f);
//+3
		 x=0.120f;  y=0.0f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//-3

			 x=-0.120f;  y=0.0f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-4


				 x=-0.110f;  y=0.05f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//4

				 x=0.110f;  y=0.05f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-5

				 x=-0.09f;  y=0.1f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//5

					 x=0.09f;  y=0.1f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-6

					 x=-0.05f;  y=0.15f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//6


					 x=0.05f;  y=0.15f; triangleAmount =100;radius =.2f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//door base


 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.32f, 0.0);
glVertex2f(0.32f, 0.0f);

glColor3ub(255,255,255);
glVertex2f(0.32f, -01.0f);
glVertex2f(-0.32f, -01.0f);
glEnd();
glColor3ub(128,128,128);


//7
//door up

 glBegin(GL_TRIANGLES);
 //glColor3f(1.00f,1.00f,1.00f);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(0.29f, 0.15f);
glVertex2f(-0.29f, 0.15f);
glColor3f(0.00f,0.00f,0.00f);
//glColor3f(1.00f,1.00f,1.00f);
glVertex2f(-0.0f, 0.55f);


glEnd();
//??????????????????????????
// small door




//base 1
 glBegin(GL_QUADS);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(-0.18f, -0.30);
glVertex2f(0.18f, -0.30f);
glVertex2f(0.18f, -01.0f);
glVertex2f(-0.18f, -01.0f);
glEnd();


//-2

					 x=-0.08f;  y=-0.29f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//2

					 x=0.08f;  y=-0.29f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


//-3

					 x=-0.07f;  y=-0.25f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//3

					 x=0.07f;  y=-0.25f; triangleAmount =100;radius =.1f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//4



					 x=0.05f;  y=-0.2f; triangleAmount =100;radius =.103f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



//-4


					 x=-0.05f;  y=-0.2f; triangleAmount =100;radius =.103f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//5
glTranslatef(0.00f,0.025f,0.00f);

	 glBegin(GL_TRIANGLES);
 glColor3f(0.00f,0.00f,0.00f);

glVertex2f(-0.13f, -0.15f);
glVertex2f(0.13f, -0.15f);
glVertex2f(-0.0f, 0.05f);


glEnd();


glTranslatef(0.00f,-0.025f,0.00f);
}
////////////////// end door ///////////////////////////

///////////////////////////                       //piler  1
glTranslatef(-0.050f,0.00f,0.00f);
{



 glBegin(GL_QUADS);
 glColor3ub(244,164,96);
//glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.68f, 01.30f);
glVertex2f(0.68f, -01.0f);
glVertex2f(0.75f, -01.0f);
glVertex2f(0.75f, 01.30f);

glEnd();





					 x=0.715f;  y=01.32f; triangleAmount =100;radius =.035f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





	 glBegin(GL_POLYGON);
// glColor3f(01.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.30f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.30f);

glEnd();




glBegin(GL_QUADS);
 //glColor3f(1.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.350f);
glVertex2f(0.73f, 01.40f);

glVertex2f(0.70f, 01.40f);
glVertex2f(0.680f, 01.350f);
glEnd();




  // piler zig zap art                                                 // piler zig zap art

//1

glTranslatef(0.00f,-0.40f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,0.40f,0.00f);


//2

glTranslatef(0.00f,-0.80f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,0.80f,0.00f);



//3
glTranslatef(0.00f,-01.20f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.20f,0.00f);


//4
glTranslatef(0.00f,-01.60f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.60f,0.00f);


//5
glTranslatef(0.00f,-02.30f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,02.30f,0.00f);


//5
//uper stick

glTranslatef(0.00f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.35f);
glVertex2f(0.719f, 01.50f);

glVertex2f(0.710f, 01.50f);
glVertex2f(0.710f, 01.35f);

glEnd();

glTranslatef(0.00f,-0.04f,0.00f);

/*
//side bar
//2 sid
glTranslatef(0.0310f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.718f, -01.05f);
glVertex2f(0.718f, 01.28f);

glEnd();

glTranslatef(-0.0310f,-0.04f,0.00f);


//middle side

//glTranslatef(-0.0590f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

//glTranslatef(0.0590f,-0.04f,0.00f);




//-2 side

glTranslatef(-0.0250f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.705f, 01.28f);
glVertex2f(0.705f, -01.05f);

glVertex2f(0.706f, -01.05f);
glVertex2f(0.706f, 01.28f);

glEnd();

*/

glTranslatef(0.0250f,-0.04f,0.00f);

}
glTranslatef(0.050f,0.00f,0.00f);



//???????????????????????
///////////////////////////                       //piler  2
//glTranslatef(-01.450f,0.0f,0.00f);
glTranslatef(-01.42f,0.05f,0.00f);

{




 glBegin(GL_QUADS);
 glColor3ub(244,164,96);
//glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.68f, 01.30f);
glVertex2f(0.68f, -01.0f);
glVertex2f(0.75f, -01.0f);
glVertex2f(0.75f, 01.30f);

glEnd();





					 x=0.715f;  y=01.32f; triangleAmount =100;radius =.035f;
glColor3f(0.00f,0.00f,0.00f);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





	 glBegin(GL_POLYGON);
// glColor3f(01.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.30f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.30f);

glEnd();




glBegin(GL_QUADS);
 //glColor3f(1.00f,0.00f,0.00f);
glColor3ub(255,153,51);
 //glVertex2f(0.72f, 01.40f);
glVertex2f(0.75f, 01.350f);
glVertex2f(0.73f, 01.40f);

glVertex2f(0.70f, 01.40f);
glVertex2f(0.680f, 01.350f);
glEnd();




  // piler zig zap art                                                 // piler zig zap art

//1

glTranslatef(0.00f,-0.40f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,0.40f,0.00f);


//2

glTranslatef(0.00f,-0.80f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,0.80f,0.00f);



//3
glTranslatef(0.00f,-01.20f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.20f,0.00f);


//4
glTranslatef(0.00f,-01.60f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.34f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.34f);

glEnd();

glTranslatef(0.00f,01.60f,0.00f);


//5
glTranslatef(0.00f,-02.30f,0.00f);
	 glBegin(GL_POLYGON);
 glColor3f(01.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.75f, 01.33f);
glVertex2f(0.75f, 01.350f);

glVertex2f(0.680f, 01.350f);
glVertex2f(0.680f, 01.33f);

glEnd();

glTranslatef(0.00f,02.30f,0.00f);


//5
//uper stick

glTranslatef(0.00f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.35f);
glVertex2f(0.719f, 01.50f);

glVertex2f(0.710f, 01.50f);
glVertex2f(0.710f, 01.35f);

glEnd();

glTranslatef(0.00f,-0.04f,0.00f);

/*
//side bar
//2 sid
glTranslatef(0.0310f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

glTranslatef(-0.0310f,-0.04f,0.00f);


//middle side

//glTranslatef(-0.0590f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.719f, 01.28f);
glVertex2f(0.719f, -01.05f);

glVertex2f(0.715f, -01.05f);
glVertex2f(0.715f, 01.28f);

glEnd();

//glTranslatef(0.0590f,-0.04f,0.00f);




//-2 side

glTranslatef(-0.0250f,0.04f,0.00f);
	 glBegin(GL_QUADS);
 glColor3f(0.00f,0.00f,0.00f);
//glColor3ub(255,153,51);
glVertex2f(0.705f, 01.28f);
glVertex2f(0.705f, -01.05f);

glVertex2f(0.706f, -01.05f);
glVertex2f(0.706f, 01.28f);

glEnd();

glTranslatef(0.0250f,-0.04f,0.00f);





*/
}
glTranslatef(01.40f,-0.01f,0.00f);



//??????????????????????
//doom

//	float xx1 = 0.70f, yy1= 1.00f; // Tushar
{
// level 1                                     // level 1



 glBegin(GL_QUADS);
 glColor3f(1.00f,1.00f,1.00f);

glVertex2f(0.13f, 01.35f);
glVertex2f(0.13f, 1.2f);
glVertex2f(-0.13f, 1.2f);
glVertex2f(-0.13f, 1.35f);

glEnd();


glBegin(GL_QUADS);
 glColor3f(1.00f,0.00f,0.00f);
glVertex2f(-0.13f, 01.2f);
glVertex2f(-0.13f, 1.35f);
glVertex2f(-0.3f, 1.3f);
glVertex2f(-0.3f, 1.2f);


glEnd();

glBegin(GL_QUADS);
 glColor3f(1.00f,0.00f,0.00f);
glVertex2f(0.13f, 01.2f);
glVertex2f(0.13f, 1.35f);
glVertex2f(0.3f, 1.3f);
glVertex2f(0.3f, 1.2f);


glEnd();
// level 1                                     // level 1

// level 2                                     // level 2

//153,92,0
glBegin(GL_QUADS);
 glColor3ub(11, 61, 15);

glVertex2f(0.13f, 01.35f);
glVertex2f(0.13f, 1.38f);
glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.13f, 1.35f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(153,92,0);

glVertex2f(-0.13f, 1.35f);
glVertex2f(-0.3f, 1.3f);
glVertex2f(-0.3f, 1.33f);
glVertex2f(-0.13f, 1.38f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(153,92,0);
glVertex2f(0.13f, 01.35f);
glVertex2f(0.3f, 1.3f);
glVertex2f(0.3f, 1.33f);
glVertex2f(0.13f, 1.38f);


glEnd();


// level 2                                     // level 2

// level 3                                     // level 3

//51,31,0
glBegin(GL_QUADS);
 glColor3ub(51,31,0);

glVertex2f(0.13f, 01.45f);
glVertex2f(0.13f, 1.38f);
glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.13f, 1.45f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(51,31,0);

glVertex2f(-0.13f, 1.38f);
glVertex2f(-0.3f, 1.33f);
glVertex2f(-0.3f, 1.37f);
glVertex2f(-0.13f, 1.45f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(51,31,0);
glVertex2f(0.13f, 01.38f);
glVertex2f(0.3f, 1.33f);
glVertex2f(0.3f, 1.37f);
glVertex2f(0.13f, 1.45f);


glEnd();


// level 3                                     // level 3

// level 4                                     // level 4   // main circle doom


glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(0.13f, 01.60f);
glVertex2f(0.135f, 1.45f);
glVertex2f(-0.14f, 1.45f);
glVertex2f(-0.13f, 1.60f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.13f, 1.60f);
glVertex2f(-0.28f, 1.60f);
glVertex2f(-0.29f, 1.37f);
glVertex2f(-0.13f, 1.45f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.13f, 1.60f);
glVertex2f(0.28f, 1.60f);
glVertex2f(0.29f, 1.37f);
glVertex2f(0.13f, 1.45f);


glEnd();





// level 4                                     // level 4

// level 5                                     // level 5


glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(0.12f, 01.70f);
glVertex2f(0.13f, 1.60f);
glVertex2f(-0.13f, 1.60f);
glVertex2f(-0.12f, 1.70f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.12f, 1.70f);
glVertex2f(-0.26f, 1.70f);
glVertex2f(-0.28f, 1.60f);
glVertex2f(-0.13f, 1.60f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.12f, 1.70f);
glVertex2f(0.26f, 1.70f);
glVertex2f(0.28f, 1.60f);
glVertex2f(0.13f, 1.60f);


glEnd();





// level 5                                     // level 5

// level 6                                     // level 6


glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(0.11f, 01.80f);
glVertex2f(0.12f, 1.70f);
glVertex2f(-0.12f, 1.70f);
glVertex2f(-0.11f, 1.80f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,255,255);

glVertex2f(-0.11f, 1.80f);
glVertex2f(-0.23f, 1.80f);
glVertex2f(-0.26f, 1.70f);
glVertex2f(-0.12f, 1.70f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(0.11f, 1.80f);
glVertex2f(0.23f, 1.80f);
glVertex2f(0.26f, 1.70f);
glVertex2f(0.12f, 1.70f);


glEnd();





// level 6                                     // level 6

// level 7                                     // level 7


glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(0.09f, 01.90f);
glVertex2f(0.11f, 1.80f);
glVertex2f(-0.11f, 1.80f);
glVertex2f(-0.09f, 1.90f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(255,0,0);

glVertex2f(-0.08f, 1.90f);
glVertex2f(-0.14f, 1.90f);
glVertex2f(-0.23f, 1.80f);
glVertex2f(-0.11f, 1.80f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(255,0,0);
glVertex2f(0.08f, 1.90f);
glVertex2f(0.14f, 1.90f);
glVertex2f(0.23f, 1.80f);
glVertex2f(0.11f, 1.80f);


glEnd();





// level 7                                     // level 7



// level 8                                     // level 8


glBegin(GL_QUADS);
 glColor3ub(11, 61, 15);

glVertex2f(0.01f, 02.00f);
glVertex2f(0.08f, 1.90f);
glVertex2f(-0.08f, 1.90f);
glVertex2f(-0.01f, 2.00f);

glEnd();

glBegin(GL_QUADS);
 glColor3ub(0,0,0);

glVertex2f(-0.01f, 2.0f);
glVertex2f(-0.01f, 2.0f);
glVertex2f(-0.14f, 1.90f);
glVertex2f(-0.084f, 1.90f);


glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(0.01f, 2.0f);
glVertex2f(0.01f, 2.0f);
glVertex2f(0.14f, 1.90f);
glVertex2f(0.084f, 1.90f);


glEnd();





// level 8                                     // level 8


//end lavel                                         //end level of main doom

/*
 x=0.0f;  y=02.01f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

*/


	/////
//stick
glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f(-0.005f, 2.00f);
glVertex2f(-0.005f, 2.3f);
glVertex2f(0.005f, 2.3f);
glVertex2f(0.005f, 2.00f);


glEnd();


// rectangle on stick

glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(0.0f, 2.0f);
glVertex2f(0.03f, 2.02f);
glVertex2f(0.0f, 2.05f);
glVertex2f(-0.03f, 2.02f);
glEnd();



//glTranslatef(0.00f,0.10f,0.00f);

	glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(0.0f, 2.0f);
glVertex2f(0.03f, 2.02f);
glVertex2f(0.0f, 2.05f);
glVertex2f(-0.03f, 2.02f);



glEnd();

//glLoadIdentity();
	////

//glTranslatef(0.00f,0.0f,0.00f);





	 x=0.0f;  y=02.08f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


		 x=0.0f;  y=02.14f; radius =.02f;

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();





//end lavel                                         //end level of main doom

/*
int lineAmount = 100; //# of triangles used to draw circle
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


*/

/*
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


*/





}










//??????????????????????????????   start      ????????????????????????????????????
// measurment


	//???????????????????????????????????????????????????????????????????????
	 //boz                                                        box

{
    glColor3ub(255, 166, 77);
    {



/*

   glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.28f, 0.37f);
    glVertex2f(-0.35f, 0.37f);
    glVertex2f(-0.35f, 0.68f);
    glVertex2f(-0.28f, 0.68f);

    glEnd();




*/


  //    glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.38f, -0.65f);
    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.45f, 0.850f);
    glVertex2f(-0.38f, 0.850f);

    glEnd();




glTranslatef(0.80f,0.00f,0.00f);

    glColor3ub(255, 166, 77);
	glBegin(GL_QUADS);
	glVertex2f(-0.38f, -0.65f);
    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.45f, 0.850f);
    glVertex2f(-0.38f, 0.850f);

    glEnd();

glTranslatef(-0.80f,0.00f,0.00f);




//  glColor3ub(255, 166, 77);



    glEnd();



//glTranslatef(0.00f,-0.600f,0.00f);





   // glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(0.35f, 0.67f);
    glVertex2f(-0.38f, 0.67f);
    glVertex2f(-0.38f, 0.85f);
    glVertex2f(0.35f, 0.85f);

    glEnd();
}

//???????????????????????


// 2nd  side  box coloum


{



 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





 //glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}



/////////////////////////////////////
//???????????????
//3 rd side boz colum


glTranslatef(01.070f,0.00f,0.00f);


{



 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(-01.070f,0.00f,0.00f);


//???????????????????????????????
//4th colum  of box

glTranslatef(01.35f,0.00f,0.00f);


{



// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(-01.35f,0.00f,0.00f);

//6 th colum box

glTranslatef(-0.27f,0.00f,0.00f);


{



// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.620f, 0.62f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.48f, 0.84f);
    glVertex2f(-0.620f, 0.84f);

    glEnd();


// glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();




glTranslatef(0.00f,-0.350f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.350f,0.00f);



glTranslatef(0.00f,-0.70f,0.00f);

 //glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, 0.27f);
    glVertex2f(-0.62f, 0.27f);
    glVertex2f(-0.62f, 0.58f);
    glVertex2f(-0.47f, 0.58f);

    glEnd();

glTranslatef(0.00f,0.70f,0.00f);





// glColor3f(1.00f,1.00f,1.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47f, -0.47f);
    glVertex2f(-0.62f, -0.47f);
    glVertex2f(-0.62f, -0.65f);
    glVertex2f(-0.47f, -0.65f);

    glEnd();

}

glTranslatef(0.27f,0.00f,0.00f);

}


//????????????????????????????????????????????????????????????????????????

//botom stair
{



glTranslatef(0.00f,0.300f,0.00f);

           glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(01.91f, -01.3f);
    glVertex2f(-01.92f,- 01.3f);
    glVertex2f(-01.92f,- 01.37f);
    glVertex2f(01.91f, -01.37f);

    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);




           glColor3ub(128,128,128);
	glBegin(GL_QUADS);
	glVertex2f(01.91f, -01.07f);
    glVertex2f(-01.92f,- 01.07f);
    glVertex2f(-02.02f,- 01.30f);
    glVertex2f(02.02f, -01.30f);

    glEnd();



   glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(02.02f, -01.3f);
    glVertex2f(-02.02f,- 01.3f);
    glVertex2f(-02.02f,- 01.37f);
    glVertex2f(02.02f, -01.37f);

    glEnd();



//?????????????????????????????????????????????????????????????????
//mark on the whole building
//left

glTranslatef(0.00f,0.300f,0.00f);
glColor3ub(205,133,63);
           //glColor3f(0.00f,0.00f,0.00f);
	glBegin(GL_QUADS);
	glVertex2f(-0.820f, 0.580f);
    glVertex2f(-01.91f, 0.580f);
    glVertex2f(-01.91f, 00.60f);
    glVertex2f(-0.820f, 0.60f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);

//right


glTranslatef(0.00f,0.300f,0.00f);

      glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.580f);
    glVertex2f(01.91f, 0.580f);
    glVertex2f(01.91f, 00.60f);
    glVertex2f(0.820f, 0.60f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);

//middle

glTranslatef(0.00f,0.300f,0.00f);

   glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.75f);
    glVertex2f(-0.82f, 0.75f);
    glVertex2f(-0.82f, 00.73f);
    glVertex2f(0.820f, 0.73f);


    glEnd();

glTranslatef(0.00f,-0.30f,0.00f);


//link right
glTranslatef(0.00f,0.330f,0.00f);

   glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(0.820f, 0.57f);
    glVertex2f(0.83f, 0.57f);
    glVertex2f(0.83f, 00.719f);
    glVertex2f(0.820f, 0.719f);


    glEnd();
glTranslatef(0.00f,-0.330f,0.00f);

//link left

glTranslatef(0.00f,0.330f,0.00f);

      glColor3ub(205,133,63);
	glBegin(GL_QUADS);
	glVertex2f(-0.820f, 0.57f);
    glVertex2f(-0.83f, 0.57f);
    glVertex2f(-0.83f, 00.719f);
    glVertex2f(-0.820f, 0.719f);


    glEnd();
glTranslatef(0.00f,-0.330f,0.00f);

//????????????????????????????????????????????????????????????????????????
//pond

	glBegin(GL_QUADS);
	 glColor3f(0.00f,0.00f,0.00f);
	glVertex2f(00.40f, -01.13f);
//	 glColor3f(01.00f,01.00f,01.00f);
    glVertex2f(-00.40f,- 01.13f);
 glColor3f(0.00f,0.00f,0.00f);
    glVertex2f(-00.50f,- 01.23f);
     glColor3f(01.00f,01.00f,01.00f);
    glVertex2f(00.50f, -01.23f);

    glEnd();


}


}




void display_day_rain()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;// nishar
	float xx1 = 0.70f, yy1= 1.00f; // Tushar

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


// Clouds



	 glBegin(GL_QUADS);
glColor3ub(153, 204, 255);
glVertex2f(2.1, 2.1+0.2);
//glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glColor3ub(153, 204, 255);
glColor3b(0.00f,0.00f,0.00f);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();



//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();



/*

building_no_light();
tushar_no_light();
salem();


*/









building_with_light();
sun();


//	Star();
tushar_with_light();
salem();
Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();
/*	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();



*/









    glFlush();
	  // Render now




}





void display_day()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;
	float xx1 = 0.70f, yy1= 1.00f;

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;







// Clouds



// Clouds



	 glBegin(GL_QUADS);
glColor3ub(153, 204, 255);
glVertex2f(2.1, 2.1+0.2);
//glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glColor3ub(153, 204, 255);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();







/*
    ////plane
    glBegin(GL_QUADS);
    glColor3ub(68,187,255);
    glVertex2f(-0.1f,0.6f);
    glVertex2f(0.4f,0.6f);
    glVertex2f(0.4f,0.8f);
    glVertex2f(-0.1f,0.8f);
//FIRST WIND
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(0.1f,0.5f);
    glVertex2f(0.25f,0.5f);
    glVertex2f(0.15f,0.65f);
    glVertex2f(-0.02f,0.65f);
    //2NDWIND
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-0.02f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.1f,0.9f);
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(0.3f,0.8f);
    glVertex2f(0.4f,0.8f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.35f,0.9f);


    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.1f,0.6f);
    glVertex2f(-0.1f,0.8f);
    glEnd();



	 glBegin(GL_QUADS);
glColor3ub(153, 204, 255);
glVertex2f(2.1, 2.1+0.2);
//glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glColor3ub(153, 204, 255);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();

*/






//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();


/*

building_no_light();
tushar_no_light();
salem();


*/








plane();

cloud();
building_with_light();

sun();
//	Star();
tushar_with_light();

salem();



//Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();
/*	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();


*/










    glFlush();
	  // Render now




}




void display_morning()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;// nishar
	float xx1 = 0.70f, yy1= 1.00f; // Tushar

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


// Clouds



	 glBegin(GL_QUADS);
glColor3ub(153, 204, 255);
glVertex2f(2.1, 2.1+0.2);
//glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glColor3ub(153, 204, 255);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();



//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();


/*

building_no_light();
tushar_no_light();
salem();


*/








sun_morning();
building_no_light();
//sun();


//	Star();
tushar_no_light();
display_bird();
salem();

//Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();
/*	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();


*/










    glFlush();
	  // Render now




}


void display_morning_rain()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;
	float xx1 = 0.70f, yy1= 1.00f;

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


// Clouds



	 glBegin(GL_QUADS);
glColor3ub(153, 204, 255);
glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 2.1+0.2);
glColor3b(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glColor3ub(153, 204, 255);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();



//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();



/*

building_no_light();
tushar_no_light();
salem();


*/









building_no_light();
//Moon();


//	Star();
tushar_no_light();
//display_bird();
salem();
Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();
/*	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();

*/











    glFlush();
	  // Render now




}

void display_night() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;// nishar
	float xx1 = 0.70f, yy1= 1.00f; // Tushar

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


// Clouds



	 glBegin(GL_QUADS);
glColor3f(1.00f,1.00f,1.00f);

glVertex2f(2.1, 2.1+0.2);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();





draw_star();

//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();


/*

building_no_light();
tushar_no_light();
salem();


*/









building_with_light();
Moon();


//	Star();
tushar_with_light();
salem();
//Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();
/*	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();



*/









    glFlush();
	  // Render now



}


void display_night_rain() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 float b=0.20f;
 float a=2.1f;
 	float xx= 1.80f, yy=1.00f  ;// nishar
	float xx1 = 0.70f, yy1= 1.00f; // Tushar

 gluOrtho2D(-2.1,2.1,-2.3,2.3);    // modifiying the drawing space -----> gluOrtho2D(left,right,bottom,top)

 // gluOrtho2D(-4,4,-4,4);

	int i;

	GLfloat x=0.0f; GLfloat y=01.4f; GLfloat radius =.3f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


// Clouds



	 glBegin(GL_QUADS);
    glColor3f(0.00f,0.00f,0.00f);
//glColor3f(1.00f,1.00f,1.00f);
glVertex2f(2.1, 2.1+0.2);
glColor3f(0.00f,0.00f,0.00f);
glVertex2f(2.1, 0.0f);
glVertex2f(-2.1, 0.0f);
glVertex2f(-2.1, 2.1+0.2);
glEnd();



//Grass




//glScaled(0.2,0.2,0);
	 glBegin(GL_QUADS);
glColor3ub(11, 61, 15);
glVertex2f(2.1, 0.0f);
glVertex2f(2.1, -2.1-0.20);
glVertex2f(-2.1, -2.1-0.20);
glVertex2f(-2.1, 0.0f);
glEnd();



/*

building_no_light();
tushar_no_light();
salem();


*/









building_no_light();
//Moon();


//	Star();
tushar_no_light();
salem();
Rain();



//????????????????????????????????????????????
// drawing axis

    glLoadIdentity();

/*
	glBegin(GL_LINES);
	            // Each set of 4 vertices form a quad
	glColor3ub(255, 128, 0); // Red
	glVertex2f(-2.0f, 0.0f);    // x, y
	glVertex2f(2.0f, 0.00f);    // x, y
glColor3ub(255, 128, 0);

     glVertex2f(0.00f, 2.00f);
    glVertex2f(0.00f, -2.0f);

    glEnd();


*/










    glFlush();
	  // Render now



}










void sound0()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);


}
void sound1()
{

    PlaySound("morning.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void sound2()
{

    PlaySound("day.wav", NULL, SND_ASYNC|SND_FILENAME);


}




void sound3()
{

    PlaySound("night.wav", NULL, SND_ASYNC|SND_FILENAME);


}

void sound4()
{

    PlaySound("morning_rain.wav", NULL, SND_ASYNC|SND_FILENAME);


}


void sound5()
{

    PlaySound("day_rain.wav", NULL, SND_ASYNC|SND_FILENAME);


}

void sound6()
{

    PlaySound("night_rain.wav", NULL, SND_ASYNC|SND_FILENAME);


}



void control_morning(int val)
{


            glLoadIdentity();
         glutDisplayFunc(display_morning);

         sound1();
         glutPostRedisplay();


}


void control_morning_rain(int val)
{


            glLoadIdentity();
         glutDisplayFunc(display_morning_rain);

         sound4();
         glutPostRedisplay();


}


void control_day(int val)
{


            glLoadIdentity();
         glutDisplayFunc(display_day);

         sound2();
         glutPostRedisplay();
}


void control_day_rain(int val)
{


            glLoadIdentity();
         glutDisplayFunc(display_day_rain);

         sound5();
         glutPostRedisplay();
}



void control_night(int val)
{

              glLoadIdentity();
            glutDisplayFunc(display_night);

        sound3();
         glutPostRedisplay();


}

void control_night_rain(int val)
{

              glLoadIdentity();
            glutDisplayFunc(display_night_rain);

        sound6();
         glutPostRedisplay();


}





void automatic_view()
{


    glutTimerFunc(1500,control_morning,0);
    glutTimerFunc(6500,control_morning_rain,0);
glutTimerFunc(9500,control_day,0);
glutTimerFunc(12500,control_day_rain,0);

glutTimerFunc(16500,control_night,0);
glutTimerFunc(20000,control_night_rain,0);



}




/*

void all()
{
    automatic_view();
}
*/


void SpecialInput(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
speed=.5;
break;
case GLUT_KEY_DOWN:
speed=.001;
break;
case GLUT_KEY_LEFT:
speed=.01;
break;
case GLUT_KEY_RIGHT:
speed=.03;
break;}
glutPostRedisplay();
}



void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			speed4 += 0.1f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{speed4 -= 0.1f;
			}
			if (button == GLUT_MIDDLE_BUTTON)
	{
	    speed4 -= 0.0f;

			}
	glutPostRedisplay();

	}


void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case '1':

glLoadIdentity();
         glutDisplayFunc(display_morning);

         sound1();
         glutPostRedisplay();

    break;

case '2':

glLoadIdentity();
         glutDisplayFunc(display_day);

         sound2();
         glutPostRedisplay();

    break;



case '3':
glutDisplayFunc(display_night);

sound3();
         glutPostRedisplay();
    break;


case '4':
glutDisplayFunc(display_morning_rain);

sound4();
         glutPostRedisplay();
    break;




case '5':
glutDisplayFunc(display_day_rain);

sound5();
         glutPostRedisplay();
    break;



    case '6':
glutDisplayFunc(display_night_rain);

sound6();
         glutPostRedisplay();
    break;





        case '*':
glutDisplayFunc(automatic_view);

//sound4();
         glutPostRedisplay();
    break;


	}
}







/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

     cout<< "after automatically playing all the views , please follow the instructions for more futures  : "<<endl<<endl;
     cout<< "morning view  press      ->  ' 1 '  "<<endl;
     cout<< "day view  press          ->  ' 2 '  "<<endl;
     cout<< "night view  press        ->  ' 3 '  "<<endl;
     cout<< "morning raining view press-> ' 4 '  "<<endl;
     cout<< "day rainging view press   -> ' 5 '  "<<endl;
     cout<< "night rainging view press  ->' 6 '  "<<endl<<endl<<endl;
     cout<< "bird,cloud,plane speed   very high        press                 ->'  up Key '  "<<endl;
     cout<< "bird,cloud,plane speed       high          press                 ->' Right Key'  "<<endl;
     cout<< "bird,cloud,plane speed     Very Low        press                 ->' Down Key '  "<<endl;
     cout<< "bird,cloud,plane speed       Low      (actual speed )  press     ->' Left Key '  "<<endl<<endl<<endl;

     cout<< "Rain speed  Low                  click  on the mouse               ->' Right click  '  "<<endl;
     cout<< "Rain speed  High                 click  on the mouse             ->'   Left click   '  "<<endl;
     cout<< "Rain speed  same                 click  on the mouse             ->'   middle click   '  "<<endl;




	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display_morning); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);//
	glutTimerFunc(100, update4, 0);
glutTimerFunc(100, update_bird, 0);
glutTimerFunc(100, update_plane, 0);
glutTimerFunc(100, update_cloud, 0);
automatic_view();

   glutKeyboardFunc(handleKeypress);

   glutMouseFunc(handleMouse);
  glutSpecialFunc(SpecialInput);




//SpecialInput();
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}

