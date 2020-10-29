/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>
#include <ctime>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

void Draw_Wallpaper()
{

}
void Idlefunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glPushMatrix();
        glRotatef(60.0,1.0,0.5,0.0);
        glPushMatrix();
            glTranslatef(75.0,-25.0,-25.0);
            glColor3f(0.0,0.0,0.5);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();
            glColor3f(0.0,1.0,0.5);
            glutSolidCube(100);
            glColor3f(0.0,0.0,0.5);
            glutWireCube(100);
        glPushMatrix();
            glTranslatef(-75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-75.0,-25.0,-25.0);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-50.0,-50.0,50.0);
            glColor3f(0.0,0.0,0.0);
            gluDisk(quadratic,0.0,25.0,32,32);
            gluCylinder(quadratic,25.0,25.0,10.0,32,32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50.0,-50.0,50.0);
            glColor3f(0.0,0.0,0.0);
            gluDisk(quadratic,0.0,25.0,32,32);
            gluCylinder(quadratic,25.0,25.0,10.0,32,32);
        glPopMatrix();
//        glPushMatrix();
//            glTranslatef(-50.0,50.0,0.0);
//            glutSolidCube(50);
//        glPopMatrix();
    glPopMatrix();
    glFlush();

    glutPostRedisplay();
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car Simulation");
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0,500.0,-300.0,300.0,-500.0,500.0);
    glutDisplayFunc(Draw_Wallpaper);
    glutIdleFunc(Idlefunc);
    //glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
