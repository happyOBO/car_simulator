#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

class Car {
private :
    GLfloat car_x;
    GLfloat car_z;
    GLfloat car_velocity;
    GLfloat car_rotate;
public :
    Car(GLfloat x, GLfloat z);
    pair <GLfloat, GLfloat> Return_loc();
    void Draw_Car();
    //void Control_velocity(bool is_accel);
    void move_car(GLfloat add_x, GLfloat add_z);
    void Rotate(bool is_right);
    void Friction();
};


#endif // CAR_H_INCLUDED
