#include "basic_setting.h"

void Draw_line()
{
    //x axis : red, y axis : green, z axis : blue
    //glMatrixMode(GL_MODELVIEW);
    GLfloat line_width = 20.0;
    GLfloat line_height = 50.0;
    glColor3f(0.07,0.15,0.27);
    glPushMatrix();
        for(int i = 0; i< 200; i++)
        {
            int tmp = i %100;
            if(i < 100) tmp = -i;
            glPushMatrix();
                glTranslatef(200.0 * tmp, 0.0,0.0);
                glBegin(GL_POLYGON);
                    glVertex3f(-line_height ,0.0, -line_width);
                    glVertex3f(-line_height ,0.0, +line_width);
                    glVertex3f(line_height ,0.0, line_width);
                    glVertex3f( line_height ,0.0, -line_width);
                glEnd();
            glPopMatrix();
        }
        for(int i = 0; i< 200; i++)
        {
            int tmp = i %100;
            if(i < 100) tmp = -i;
            glPushMatrix();
                glRotatef(90.0,0.0,1.0,0.0);
                glTranslatef(200.0 * tmp, 0.0,0.0);
                glBegin(GL_POLYGON);
                    glVertex3f(-line_height ,0.0, -line_width);
                    glVertex3f(-line_height ,0.0, +line_width);
                    glVertex3f(line_height ,0.0, line_width);
                    glVertex3f( line_height ,0.0, -line_width);
                glEnd();
            glPopMatrix();
        }

    glPopMatrix();
}

void DrawGround()
{
    GLfloat ground_size = 10000.0;
    GLfloat road_size = 150.0;
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(0.74,0.73,0.99);
        glVertex3f(- ground_size ,0.0, -ground_size);
        glVertex3f(- ground_size ,0.0, +ground_size);
        glVertex3f( ground_size ,0.0, ground_size);
        glVertex3f( ground_size ,0.0, -ground_size);
    glEnd();


    glColor3f(0.17,0.35,0.62);
    glBegin(GL_POLYGON);
        glVertex3f(- ground_size ,0.0, -road_size);
        glVertex3f(- ground_size ,0.0, +road_size);
        glVertex3f( ground_size ,0.0, road_size);
        glVertex3f( ground_size ,0.0, -road_size);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- road_size ,0.0, -ground_size);
        glVertex3f(- road_size ,0.0, +ground_size);
        glVertex3f( road_size ,0.0, ground_size);
        glVertex3f( road_size ,0.0, -ground_size);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- (ground_size / 10 - 2 * road_size)  ,0.0, road_size);
        glVertex3f(- ground_size / 10 ,0.0, road_size);
        glVertex3f( -road_size ,0.0, ground_size / 10);
        glVertex3f( -road_size ,0.0, (ground_size / 10 - 2 * road_size));
    glEnd();

    glPushMatrix();
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(- (ground_size / 10 - 2 * road_size)  ,0.0, road_size);
        glVertex3f(- ground_size / 10 ,0.0, road_size);
        glVertex3f( -road_size ,0.0, ground_size / 10);
        glVertex3f( -road_size ,0.0, (ground_size / 10 - 2 * road_size));
    glEnd();

    glPushMatrix();
        glRotatef(90.0, 0.0, 2.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(- (ground_size / 10 - 2 * road_size)  ,0.0, road_size);
        glVertex3f(- ground_size / 10 ,0.0, road_size);
        glVertex3f( -road_size ,0.0, ground_size / 10);
        glVertex3f( -road_size ,0.0, (ground_size / 10 - 2 * road_size));
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
