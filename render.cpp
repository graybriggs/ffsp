

#include "globals.h"
#include "render.h"

#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>



void draw_init(double screen_w, double screen_h) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glViewport(0, 0, screen_w, screen_h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    
    
    //make_perspective(45, screen_w / screen_h, 0.1, 100.0);
    glFrustum(-1, 1, -1, 1, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw_pyramid() {
        

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Right Of Triangle (Front)
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Right Of Triangle (Right)
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f(-1.0f,-1.0f, -1.0f);         // Right Of Triangle (Back)
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Right Of Triangle (Left)
    glEnd();                        // Done Drawing The Pyramid

}

void draw_cube() {

    glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,0.0f);          // Set The Color To Green
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Bottom Left Of The Quad (Top)
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Bottom Right Of The Quad (Top)

        glColor3f(1.0f,0.5f,0.0f);          // Set The Color To Orange
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Top Right Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Top Left Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Bottom)
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Bottom)

        glColor3f(1.0f,0.0f,0.0f);          // Set The Color To Red
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Front)
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Front)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Front)
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Front)

        glColor3f(1.0f,1.0f,0.0f);          // Set The Color To Yellow
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Back)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Back)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Back)
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Back)

        glColor3f(0.0f,0.0f,1.0f);          // Set The Color To Blue
        glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Left)
        glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Right Of The Quad (Left)

        glColor3f(1.0f,0.0f,1.0f);          // Set The Color To Violet
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();                        

}

void draw_triangle() {
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f( -1.0f, -1.0f, 0.0f);
        glVertex3f( 1.0f, -1.0f, 0.0f);
    glEnd();
}

void draw_quad() {
    glBegin(GL_QUADS);
        glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
        glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();
}

void draw_floor() {
    glColor3f(0.9f, 0.8f, 0.9f);
    glScalef(10,1,10);
    glTranslatef(0.0, -1.0f, 0.0f);
    glRotatef(90.0, 0.0f, 0.0f, 1.0f);
    draw_quad();
}

void draw_blocks() {

    float offsetx = 0.0f;
    float offsetz = 0.0f;
    float shift = 12.0f;
    for (int i = 0; i < 20; ++i) {
        glPushMatrix();
        glTranslatef(offsetx, 0.0f, shift + offsetz);
        draw_cube();
        glPopMatrix();
        offsetx += 2.0f;
        if (offsetx > 8.0f) {
            offsetx = 0.0f;
            offsetz += 2.1f;
        }
    }
}


void draw_scene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glTranslatef(0.0f, 0.0f, -3.0f);

    glPushMatrix();
    draw_floor();
    glPopMatrix();

    draw_blocks();

    glPushMatrix();
    glTranslatef(-3.0, 1.0f, 4.0f);
    draw_cube();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45, 1.0f, 1.0f, 1.0f);
    glTranslatef(8.0, 2.0f, 4.0f);
    draw_cube();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(4.0, 1.0f, 2.0f);
    draw_pyramid();
    glPopMatrix();
    //glTranslatef(0.0f, 0.0f, -1.0f);
    
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(0.0f, 2.0 * i + 1.0, 0.0f);
        draw_triangle();
        glPopMatrix();
    }
    glPopMatrix();

}

void render_prepare_scene() {
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    make_perspective(45, SCREEN_WIDTH / SCREEN_HEIGHT, 0.1, 100.0);
    glFrustum(-1, 1, -1, 1, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}