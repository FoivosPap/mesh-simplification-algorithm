#define COLLISION 1
#define DEF 2
#define LOD2 3
#define LOD5 4
#define WIREFRAME 5
#define BSPHERE 6
#define AABB 7
#define COVFAC 8
#define HIER1 9
#define HIER2 10
#define HIER3 11

//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 

void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void Keyboard(unsigned char key,int x,int y);
void KeyboardUp(unsigned char key,int x,int y);
// Functions for handling keyboard events.

void Mouse(int button,int state,int x,int y); 
// Function for handling mouse events

void MouseMove(int x,int y);

void MenuSelect(int choice);