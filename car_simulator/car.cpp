#include "car.h"

const double PI = 3.14159;

Car::Car(GLfloat x, GLfloat z)
    : car_x(x), car_z(z) , car_velocity(0.0), car_rotate(-180.0)
{
}

void Car::Draw_Car()
{
    Friction();
    glPushMatrix();
        car_x += car_velocity*cos(-PI/180 *car_rotate);
        car_z += car_velocity*sin(-PI/180 *car_rotate);
        glTranslatef(car_x ,0.0,car_z);
        glRotatef(car_rotate ,0.0,1.0,0.0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();

        if(( -315 < car_rotate && car_rotate< -135) || ( 135 < car_rotate && car_rotate< 315) )
        {

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
            glPushMatrix();
                glColor3f(0.95,0.95,0.95);
                glutSolidCube(100);
                //glColor3f(0.0,0.0,0.5);
                //glutWireCube(100);
            glPopMatrix();
            glPushMatrix();
                glColor3f(0.4,0.39,0.97);
                glTranslatef(-75.0,-25.0,25.0);
                glutSolidCube(50);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-75.0,-25.0,-25.0);
                glutSolidCube(50);
            glPopMatrix();

        }
        else
        {
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
                //glColor3f(0.0,0.0,0.5);
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
        }

//        draw tires
//        glPushMatrix();
//            glTranslatef(-50.0,-50.0,50.0);
//            glColor3f(0.0,0.0,0.0);
//            gluDisk(quadratic,0.0,25.0,32,32);
//            gluCylinder(quadratic,25.0,25.0,10.0,32,32);
//        glPopMatrix();
//        glPushMatrix();
//            glTranslatef(50.0,-50.0,50.0);
//            glColor3f(0.0,0.0,0.0);
//            gluDisk(quadratic,0.0,25.0,32,32);
//            gluCylinder(quadratic,25.0,25.0,10.0,32,32);
//        glPopMatrix();
//        glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


pair <GLfloat, GLfloat> Car::Return_loc()
{
    return make_pair(car_x,car_z);
}

void Car::Control_velocity(bool is_accel)
{
    cout<<car_rotate<<":"<<sin(PI/180 *car_rotate)<<" "<<cos(PI/180 *car_rotate)<<" "<<endl;

    if(is_accel && car_velocity < 50.0)
    {
        car_velocity += 0.8;
    }
    else if(!is_accel && -50.0 < car_velocity )
    {
            car_velocity -= 0.8;
    }
}

void Car::move_car(GLfloat add_x, GLfloat add_z)
{
    car_x -= 3*add_x;
    car_z -= 3*add_z;
}


void Car::Friction()
{

    if(car_velocity > 0)
        car_velocity -= 0.05;
    else if(car_velocity < 0)
        car_velocity += 0.05;
}
void Car::Rotate(bool is_right)
{
    if(is_right)
    {

        car_rotate -= 2.0;
    }
    else
        car_rotate += 2.0;

//    cout<<car_rotate<<endl;
    if(car_rotate>= 360.0 || car_rotate <= -360.0)
        car_rotate = 0.0;
}
