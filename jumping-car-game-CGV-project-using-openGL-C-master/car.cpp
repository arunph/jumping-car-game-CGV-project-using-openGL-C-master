#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include <iostream>
#include <string>
int a=0,b=60,xn=0,y4=60,g=200,h=60,c;

//Track Score
int score = 0;




//For Display TEXT
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1,200,1,200);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	
}

void car(int x,int y)
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,y+0.5);
	glVertex2i(x,y+8);
	glVertex2i(x-2,y+12);
	glVertex2i(x,y+10);
	glVertex2i(x+5,y+15);
	glVertex2i(x+20,y+15);
	glVertex2i(x+25,y+9);
	glVertex2i(x+30,y+9);
	glVertex2i(x+32,y+7);
	glVertex2i(x+32,y+0.5);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x+6,y);
	glVertex2i(x+7,y+5);
	glVertex2i(x+9,y+7);
	glVertex2i(x+11,y+5);
	glVertex2i(x+12,y);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x+21,y);
	glVertex2i(x+22,y+5);
	glVertex2i(x+24,y+7);
	glVertex2i(x+26,y+5);
	glVertex2i(x+27,y);
	glEnd();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x+9,y);
	glEnd();
	glBegin(GL_POINTS);
	glVertex2i(x+24,y);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex2i(x+7,y+8);
	glVertex2i(x+7,y+13);
	glVertex2i(x+14,y+13);
	glVertex2i(x+14,y+8);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex2i(x+16,y+8);
	glVertex2i(x+20,y+13);
	glVertex2i(x+24,y+8);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	
	//Score Board
     glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(80,97);
    glVertex2f(100,97);
    glVertex2f(100,98-8);
    glVertex2f(80,98-8);
    glEnd();
	//Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95,(void *)font3,buffer);
   
   
	
	}
	


void obs(int x,int y)
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,y-2);
	glVertex2i(x+2,y+12);
	glVertex2i(x+4,y+1);
	glVertex2i(x+6,y+12);
	glVertex2i(x+8,y+1);
	glVertex2i(x+9,y-2);
	glEnd();
	glFlush();
}

void chardraw(GLubyte key,GLint x,GLint y)
{
	if(key=='s')
	{
		y4=y4+40;
	}
	glFlush();
}

void axis(int p,int q)
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0,q-3);
	glVertex2i(200,q-5);
	glVertex2i(0,q-5);
	glEnd();
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	car(xn,y4);
	obs(g,h);
	axis(a,b);
	glFlush();
}




void change1()
{
	if(xn>200)
	{
		y4=60;
		xn=0;
	}
	if(y4>60)
		y4--;
	g--;
	score++;
	if(g<0)
	{
		g=200;
	}
	xn+=1;
	

	Sleep(25);
	if(xn==g-28&&y4>=60&&y4<=70)
	{
		glColor3f(1.0,0.0,0.0);
		char string[]="GAME OVER";
		glRasterPos2f(100,100);
		int len=strlen(string);
		for(int i=0;i<len;i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		}
		glFlush();
		Sleep(2000);
		xn=0;
		g=200;
		score=0;
	}
	glutPostRedisplay();
}
void change2()
{
	if(xn>200)
	{
		y4=60;
		xn=0;
	}
	if(y4>60)
		y4--;
	g--;
	score++;
	if(g<0)
	{
		g=200;
	}
	xn+=1;
	

	Sleep(15);
	if(xn==g-28&&y4>=60&&y4<=70)
	{
		glColor3f(1.0,0.0,0.0);
		char string[]="GAME OVER";
		glRasterPos2f(100,100);
		int len=strlen(string);
		for(int i=0;i<len;i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		}
		glFlush();
		Sleep(2000);
		xn=0;
		g=200;
		score=0;
	}
	glutPostRedisplay();
}
void change3()
{
	if(xn>200)
	{
		y4=60;
		xn=0;
	}
	if(y4>60)
		y4--;
	g--;
	score++;
	if(g<0)
	{
		g=200;
	}
	xn+=1;
	

	Sleep(5);
	if(xn==g-28&&y4>=60&&y4<=70)
	{
		glColor3f(1.0,0.0,0.0);
		char string[]="GAME OVER";
		glRasterPos2f(100,100);
		int len=strlen(string);
		for(int i=0;i<len;i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		}
		glFlush();
		Sleep(2000);
		xn=0;
		g=200;
		score=0;
	}
	glutPostRedisplay();
}
void main(int argc,char *argv[])
{
	int i,j,ch;
	glutInit(&argc,argv);
	printf("MENU\n1.EASY\n2.MEDIUM\n3.DIFFICULT\n4.exit\nenter your choice\t");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:void change1();
		c=1;
		break;
	case 2:void change2();
		c=2;
		break;
	case 3:void change3();
	c=3;
		break;
	case 4:exit(0);
		break;
	default:printf("invalid choice");
	break;
	}
	glutInitWindowSize(2000,2000);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("JUMPING CAR");
    init();
    glutDisplayFunc(init);
	glutDisplayFunc(display);
	if(c==1)
	{
    glutIdleFunc(change1);
	}
	else if(c==2)
	{
    glutIdleFunc(change2);
	}
	else if(c==3)
	{
	 glutIdleFunc(change3);
	}
	glutKeyboardFunc(chardraw);
	glutMainLoop();
	}




