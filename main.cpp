

#include <stdio.h>     // - Just for some ASCII messages
#include "gl/glut.h"   // - An interface and windows 
                       //   management library
#include "visuals.h"   // Header file for our OpenGL functions



////////////////// State Variables ////////////////////////
float t=0.0; ///Time

/////////////// Main Program ///////////////////////////


int main(int argc, char* argv[])
{ 
  
  // initialize GLUT library state
  glutInit(&argc, argv);
	
  // Set up the display using the GLUT functions to 
  // get rid of the window setup details:
  // - Use true RGB colour mode ( and transparency )
  // - Enable double buffering for faster window update
  // - Allocate a Depth-Buffer in the system memory or 
  //   in the video memory if 3D acceleration available	
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
 
  
  // Define the main window size and initial position 
  // ( upper left corner, boundaries included )
  glutInitWindowSize(1900,1000);
  glutInitWindowPosition(0,0);
  
  // Create and label the main window
  glutCreateWindow("Window");
  
  // Configure various properties of the OpenGL rendering context
  Setup();
  
  // Callbacks for the GL and GLUT events:
  // The rendering function


  glutDisplayFunc(Render);
  glutReshapeFunc(Resize);
  glutIdleFunc(Idle);
  glutKeyboardFunc(Keyboard);
  glutKeyboardUpFunc(KeyboardUp);
  glutMouseFunc(Mouse);
  glutMotionFunc(MouseMove);

  glutCreateMenu(MenuSelect);
  glutAddMenuEntry("Collision",COLLISION);
  glutAddMenuEntry("Default",DEF);
  glutAddMenuEntry("LOD 2x",LOD2);
  glutAddMenuEntry("LOD 10x",LOD5);
  glutAddMenuEntry("Wireframe",WIREFRAME);
  glutAddMenuEntry("Bounding Sphere",BSPHERE);
  glutAddMenuEntry("AABB",AABB);
  glutAddMenuEntry("Calculate COVERAGE FACTOR",COVFAC);
  glutAddMenuEntry("Hierarchy 1",HIER1);
  glutAddMenuEntry("Hierarchy 2",HIER2);
  glutAddMenuEntry("Hierarchy 3",HIER3);
    // attach the menu to the right button
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  //Enter main event handling loop
  glutMainLoop();
  return 0;

}  