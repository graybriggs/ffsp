#include "geometry.h"

#include <GL/gl.h>

void geometry::cube() {

    glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,0.0f);          // Set The Color To Green
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Bottom Left Of The Quad (Top)
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Bottom Right Of The Quad (Top)
        
        
        glColor3f(1.0f,0.5f,0.0f);          // Set The Color To Orange
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Top Right Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Top Left Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Bottom)
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Bottom)

        glColor3f(1.0f,0.0f,0.0f);          // Set The Color To Red
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Front)
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Front)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Front)
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Front)
        
        glColor3f(1.0f,1.0f,0.0f);          // Set The Color To Yellow
        glNormal3f( 1.0f, 0.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Back)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Back)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Back)
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Back)
        
        
        glColor3f(0.0f,0.0f,1.0f);          // Set The Color To Blue
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Left)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Left)
        
        glColor3f(1.0f,0.0f,1.0f);          // Set The Color To Violet
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();   
}

void geometry::pyramid()
{
    // single face normals
    glBegin(GL_TRIANGLES);

    // ---------- Front ----------
    glNormal3f(0.0f, 0.447214f, 0.894427f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);

    // ---------- Right ----------
    glNormal3f(0.894427f, 0.447214f, 0.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);

    // ---------- Back ----------
    glNormal3f(0.0f, 0.447214f, -0.894427f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    // ---------- Left ----------
    glNormal3f(-0.894427f, 0.447214f, 0.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);

    glEnd();
}

void geometry::triangle() {
    
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f( -1.0f, -1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, 0.0f);
    glEnd();
}

void geometry::plane_triangle() {
    
    // ??
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f( -1.0f, -1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, 0.0f);
    glEnd();
}

void geometry::quad() {
    // ??
    glBegin(GL_QUADS);
        //glNormal3f(1.0f, 0.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
        
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();
}

void geometry::plane_quad() {

    glBegin(GL_QUADS);
        //glNormal3f(1.0f, 0.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();
}

void geometry::line(float start_x, float start_y, float end_x, float end_y) {

    glColor3f(0.0f, 1.0f, 0.0f); 
    glLineWidth(0.01f);
    glBegin(GL_LINES);
        //glVertex2f(-50.0f, 0.0f);
        //glVertex2f(50.0f, 0.0f);
        glVertex2f(start_x, start_y);
        glVertex2f(end_x, end_y);
    glEnd();
}