//============================================================================
// Name        : .cpp
// Author      : Fajr Naveed
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include "GamePlay.h"
#include"Menu.h"
#include"Movement.h"
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
int GamePlay::A[6][6] = { {} };
bool Menu::startmenu = false;
bool Menu::stop = true;
int Movement::a1 = 0;
int Movement::a2 = 0;
int Movement::b1 = 0;
int Movement::b2 = 0;
int Movement::Ginti = 0;
int GamePlay::score = 0;
int GamePlay::timelimit = 200;
bool Menu::weee  = true;
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	GamePlay B;
	Menu A;
	DrawString(10, 960, "Score=", colors[ORANGE]);
	DrawString(80, 960, Num2Str(B.getscore()), colors[MISTY_ROSE]);
	DrawString(840, 960, " Press Esc to Exit", colors[ORANGE]);
	DrawLine( 40,130 ,200,130 , 25, colors[DARK_BLUE]);
	DrawString(40, 120, "REARRANGE", colors[ORANGE]);
	DrawString(700, 120, " Press P to pause and U to resume", colors[ORANGE]);


	DrawString(500 , 960, " Time left: ", colors[ORANGE]);
	DrawString(600, 960, Num2Str(B.getlimit()), colors[MISTY_ROSE]);

	if (A.getStop() == true)
	{
		if (B.getlimit() == 0)
		{
			B.setStartup_menu(false);
			B.setlimit(200);
		}
		if (A.getStartup_menu() == false)
		{
			A.startup_menu();
		}

		else
		{

			B.DisplayRand();
			B.LinesDraw();


			//DrawString(90, 960, "Moves=30", colors[MISTY_ROSE]);
			B.Disapear();
			B.Drop();
			//B.setscore(0);
		}
	}
	else if (A.getStop() == false)
	{
		B.DisplayRand();
		B.LinesDraw();
	}

	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {

	GamePlay A;
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	 if (key == 'p' || key == 'P') //Key for placing the bomb
	{

			A.setStop(false);
	
		
		//do something if b is pressed
	}
	 if (key == 'u' || key == 'U')
	 {
		 A.setStop(true);
	 }
	if (key == 'S' || key == 's')
	{
		A.setStartup_menu(true);
	}
	glutPostRedisplay();
	
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	GamePlay B;
	Menu A;
	if (A.getStartup_menu() == true)
	{
		if (A.getStop() == true)
		{
			B.TimeLimit();
		}
	}
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
enum GameState
{
	Ready,Over
};
GameState g = Ready;

void MouseClicked(int button, int state, int x, int y) {
	cout << "x" << x <<"    "<<  "y" <<y<<endl;
	GamePlay A;
	Movement B;
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;
		if ((x >= 235 && x <=560 ) && (y >= 230 && y <=309 ) && A.getStartup_menu() == false)
		{
			A.setStartup_menu(true);
		}
		if ((x >= 30 && x <= 240) && (y >= 615 && y <= 750))
		{
			A.Random();
			A.DisplayRand();
		}
		if (state == GLUT_UP && g == Ready)
		{
			if (B.getGinti() == 0)
			{
				cout << "click one " << endl;
				(B.seta1((y-130) / 80));
				(B.setb1((x - 280) / 80));
				B.setGinti(1);
			}
			else if (B.getGinti() == 1)
			{
				cout << "click two " << endl;
				(B.seta2((y-130) / 80));
				(B.setb2((x - 280) / 80));
				A.Slide(B.geta1(), B.getb1(), B.geta2(), B.getb2());
				B.setGinti(0);
			}
		}
		
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;
	}

	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	GamePlay A;
	A.Random();


	int width = 1020, height = 1020; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Fajr Naveed"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
