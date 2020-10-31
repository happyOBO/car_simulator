#include "car.h"

Car::Car(GLfloat x, GLfloat z)
    : car_x(x), car_z(z) , car_velocity(0.0), car_rotate(0.0)
{
}

void Car::Draw_Car()
{
    if(car_velocity > 0.1) Control_velocity(false);
    glPushMatrix();
        glRotatef(1.0 * car_rotate ,0.0,1.0,0.0);
        car_x -= car_velocity;
        glTranslatef(car_x ,0.0,0.0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();

        glPushMatrix();
            glColor3f(0.4,0.39,0.97);
            glTranslatef(-75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-75.0,-25.0,-25.0);
            glutSolidCube(50);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.95,0.95,0.95);
            glutSolidCube(100);
            glColor3f(0.0,0.0,0.5);
            //glutWireCube(100);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.4,0.39,0.97);
            glTranslatef(75.0,-25.0,-25.0);
            //glColor3f(0.0,0.0,0.5);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();

        //draw tires
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
    glPopMatrix();
}


pair <GLfloat, GLfloat> Car::Return_loc()
{
    return make_pair(car_x,car_z);
}

void Car::Control_velocity(bool is_accel)
{

    if(is_accel && car_velocity < 70.0)
    {
        car_velocity += 1.0;
    }
    else
    {
        if(car_velocity > 0)
            cout<<"hello"<<endl;
            car_velocity -= 0.05;
    }
}
void Car::Rotate(bool is_right)
{
    if(is_right)
    {

        car_rotate -= 1.0;
    }
    else
        car_rotate += 1.0;

    cout<<car_rotate<<endl;
    if(car_rotate>= 72.0 || car_rotate <= -72.0)
        car_rotate = 0.0;
}
