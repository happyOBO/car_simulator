
#include "car.h"
#include "basic_setting.h"
using namespace std;

Car MyCar(0.0,0.0);

void Draw_Wallpaper()
{

}
void Idlefunc()
{
    pair<GLfloat,GLfloat> loc = MyCar.Return_loc();
    GLfloat z_location = loc.second;
    GLfloat x_location = loc.first;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        gluLookAt(x_location + 50, 100.0, z_location + 50, x_location, 0.0, z_location, 0.0, 1.0, 0.0 );
        //glRotatef(60.0,1.0,3.0,0.0);
        DrawGround();
        Draw_line();
        MyCar.Draw_Car();
    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int p, int k) {
 switch (key) {
 case 'd':
         MyCar.Rotate(true);
         MyCar.Control_velocity(true);
    break;
 case 'a':
         MyCar.Rotate(false);
         MyCar.Control_velocity(true);
    break;
 case 'w':
         MyCar.Control_velocity(true);
    break;
 case 's':
         MyCar.Control_velocity(false);
     break;
 case 32 :

    break;
 default:
     break;

 }
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
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
