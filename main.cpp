//* Tablero
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat s = 10.0f;

void init(){
    glClearColor(0.0, 1.0, 0.9, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10,10,-10,10,-10,10);
}


void ejes(){
    //EjesDeReferencia
    glBegin (GL_LINES);
    glColor3f(1.0,0.0,0.0); //rojo
    glVertex3f (-1000.0, 0.0, 0.0);
    glVertex3f (1000.0, 0.0, 0.0);
    glColor3f(0.0,1.0,0.0); //verde
    glVertex3f ( 0.0, -1000.0, 0.0);
    glVertex3f ( 0.0,1000.0, 0.0);
    glColor3f(1.0,1.0,1.0); //blanco
    glVertex3f ( 0.0, 0.0, -1000.0);
    glVertex3f ( 0.0, 0.0,1000.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
  	glPushMatrix();
  	//ejes();
  	//glRotatef(180,1,0,0);
    glRotatef(45,1,0,0);
    glRotatef(15,0,1,0);
    glScalef(s, s, s);
   // gluPerspective(40, 30, 1.0, 200.0);
    GLfloat ejez=-1.0f,ejex=-0.855f,cons=0.25f;
    int col=0;
    for(int z=0; z<=6;z++){
        ejex=-0.90;
        for(int x=0; x<=6;x++){
             if(col==0){
                glColor3f(0,0,0);
                col=1;
            }
            else{
                glColor3f( 1.0, 1.0, 1.0 );
                col=0;
            }
           glBegin(GL_QUADS);
                glVertex3f(ejex,0,ejez);
                glVertex3f(ejex+cons,0,ejez);
               glVertex3f(ejex+cons,0,ejez+cons);
                glVertex3f(ejex,0,ejez+cons);
            glEnd();
            glFlush();     
            ejex=ejex+cons;
        }
        ejez=ejez+cons;
    }
    glPopMatrix();
    glutSwapBuffers();
}
int main(int agrc, char ** argv){
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(150, 200);
    glutInitWindowSize(800, 600);
    glutCreateWindow ("Tablero");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
