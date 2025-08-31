#include <stdio.h>     // - Just for some ASCII messages
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <time.h>
#include "gl/glut.h"   // - An interface and windows 

#include <random>

#include "visuals.h"   // Header file for our OpenGL functions
#include <math.h>
#include <cmath>

static float tx = 0.0;
static float ty = 0.0;
static float tz = 0.0;

static float tx1 = 0.0;
static float ty1 = 0.0;
static float tz1 = 0.0;
static float tx2 = 0.0;
static float ty2 = 0.0;
static float tz2 = 0.0;

static float toldx1 = 0.0;
static float toldy1 = 0.0;
static float toldz1 = 0.0;

static float toldx2 = 0.0;
static float toldy2 = 0.0;
static float toldz2 = 0.0;

float rot = 0.0;
static float rot1 = 0.0;
static float rot2 = 0.0;
int rotx = 0.0;
int roty = 0.0;
int rotx1 = 0.0;
int roty1 = 0.0;
int rotx2 = 0.0;
int roty2 = 0.0;

int rotx11 = 0.0;
int roty11 = 0.0;
int rotx22 = 0.0;
int roty22 = 0.0;

int rotoldx1=0;
int rotoldy1=0;
int rotoldx2=0;
int rotoldy2=0;

int butoldx1=0;
int butoldy1=0;
int butoldx2=0;
int butoldy2=0;

int rotold1x1=0;
int rotold1y1=0;
int rotold2x2=0;
int rotold2y2=0;

int rx1=0;
int ry1=0;
int rx2=0;
int ry2=0;

float lod=0.0;
int collap=0;
int sphere=0;
int cube=0;
int coverfac=0;

int l21=0;
int l22=0;
int s=0;
int j=0;
int j2=0;
int j11=0;
int j22=0;
int n1=0;
int n2=0;

int obj1=0;
int obj2=0;

using namespace std;

float pi=3.14;

int f11[40000];
int f12[40000];
int f13[40000];

int f21[40000];
int f22[40000];
int f23[40000];

int f11xmax[40000];
int f12xmax[40000];
int f13xmax[40000];

int f11xmin[40000];
int f12xmin[40000];
int f13xmin[40000];

int f21xmax[40000];
int f22xmax[40000];
int f23xmax[40000];

int f21xmin[40000];
int f22xmin[40000];
int f23xmin[40000];

int f11y1max[40000];
int f12y1max[40000];
int f13y1max[40000];

int f11y1min[40000];
int f12y1min[40000];
int f13y1min[40000];

int f21y1max[40000];
int f22y1max[40000];
int f23y1max[40000];

int f21y1min[40000];
int f22y1min[40000];
int f23y1min[40000];

int f11y2max[40000];
int f12y2max[40000];
int f13y2max[40000];

int f11y2min[40000];
int f12y2min[40000];
int f13y2min[40000];

int f21y2max[40000];
int f22y2max[40000];
int f23y2max[40000];

int f21y2min[40000];
int f22y2min[40000];
int f23y2min[40000];

int f11z1max[40000];
int f12z1max[40000];
int f13z1max[40000];

int f11z1min[40000];
int f12z1min[40000];
int f13z1min[40000];

int f11z2max[40000];
int f12z2max[40000];
int f13z2max[40000];

int f11z2min[40000];
int f12z2min[40000];
int f13z2min[40000];

int f11z3max[40000];
int f12z3max[40000];
int f13z3max[40000];

int f11z3min[40000];
int f12z3min[40000];
int f13z3min[40000];

int f11z4max[40000];
int f12z4max[40000];
int f13z4max[40000];

int f11z4min[40000];
int f12z4min[40000];
int f13z4min[40000];

int f21zmax[40000];
int f22zmax[40000];
int f23zmax[40000];

int f21zmin[40000];
int f22zmin[40000];
int f23zmin[40000];

int f21z1max[40000];
int f22z1max[40000];
int f23z1max[40000];

int f21z1min[40000];
int f22z1min[40000];
int f23z1min[40000];

int f21z2max[40000];
int f22z2max[40000];
int f23z2max[40000];

int f21z2min[40000];
int f22z2min[40000];
int f23z2min[40000];

int f21z3max[40000];
int f22z3max[40000];
int f23z3max[40000];

int f21z3min[40000];
int f22z3min[40000];
int f23z3min[40000];

int f21z4max[40000];
int f22z4max[40000];
int f23z4max[40000];

int f21z4min[40000];
int f22z4min[40000];
int f23z4min[40000];

float X1[17000];
float Y1[17000];
float Z1[17000];

float X2[17000];
float Y2[17000];
float Z2[17000];

float length;
float normal[3];
float point1[3];
float point2[3];
float point3[3];

float xmax1=-200;
float ymax1=-200;
float zmax1=-200;

float xmin1=200;
float ymin1=200;
float zmin1=200;

float xmax2=-200;
float ymax2=-200;
float zmax2=-200;

float xmin2=200;
float ymin2=200;
float zmin2=25000;

float Trx=0;
float Try=0;
float Trz=0;

int xold=0;
int yold=0;

int but=0;
int butx=0;
int buty=0;

int sol=1;
int collision=0;
int hier=0;
int hierarchy=0;
int cola[40000];
int colb[40000];

int l1=0;
int l2=0;

int l1xa=0;
int l1xb=0;

int l2xa=0;
int l2xb=0;

int l1ya=0;
int l1yb=0;

int l1ya2=0;
int l1yb2=0;

int l2ya=0;
int l2yb=0;

int l2ya2=0;
int l2yb2=0;

int l1za=0;
int l1zb=0;

int l1za2=0;
int l1zb2=0;

int l1za3=0;
int l1zb3=0;

int l1za4=0;
int l1zb4=0;

int l2za=0;
int l2zb=0;

int l2za2=0;
int l2zb2=0;

int l2za3=0;
int l2zb3=0;

int l2za4=0;
int l2zb4=0;

int tix=0;
int tiy=0;
int tiz=0;

int hierax=0;
int hieray=0;
int hieraz=0;

float radi=0;
template <class T>
bool from_string(T& t,const std::string& s,std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

//-----------------------------------------------------------

void normalize(float *vect){
  length=sqrt(pow(vect[0],2) + pow(vect[1],2)+ pow(vect[2],2));
  //A^2 + B^2 + C^2 = length^2
}

//-----------------------------------------------------------

void crossProduct(float *c,float a[3], float b[3])  //finds the cross product of two vectors
{ 
  c[0]=a[1]*b[2] - b[1]*a[2];
  c[1]=a[2]*b[0] - b[2]*a[0];
  c[2]=a[0]*b[1] - b[0]*a[1];
}

//-----------------------------------------------------------

float innerProduct(float a[3], float b[3])
{
	float c1=0;
	c1=a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
	return c1;
}
//-----------------------------------------------------------

void getFaceNormal(float *norm,float pointa[3],float pointb[3],float pointc[3])
{
  float vect[2][3];
  int a,b;
  float point[3][3];
 
  for (a=0;a<3;++a)
  {
    point[0][a]=pointa[a];    //copies points into point[][]
    point[1][a]=pointb[a];
    point[2][a]=pointc[a];
  }

  for (a=0;a<2;++a)        //calculates vectors from point[0] to point[1]
  {                        //and point[0] to point[2]
	for (b=0;b<3;++b)
	{
		vect[a][b]=point[2-a][b]-point[0][b];     
	}
  }
  crossProduct(norm,vect[0],vect[1]);               //calculates vector at 90� to to 2 vectors
  normalize(norm);                                  //makes the vector length 1
}

//-----------------------------------------------------------

void Import_Objects(char *FileName1,char *FileName2)
{
	
	int k=0;
	l1=0;
	l2=0;
	l21=0;
	l22=0;

	std::string temp;
	std::string A1;
	std::string A2;
	std::string A3;
	std::string A4;
	std::string A5;

	ifstream myfile1(FileName1);
	while(k<1)
	{
		getline(myfile1,temp);
		std::istringstream iss(temp);
		std::getline(iss, A1, ' ');
		std::getline(iss, A2, ' ');
		std::getline(iss, A3, ' ');
		std::getline(iss, A4, ' ');
		if (temp[0]=='v')
		{
			from_string<float>(X1[l1], A2, std::dec);
			if (X1[l1]>xmax1) xmax1=X1[l1];
			if (X1[l1]<xmin1) xmin1=X1[l1];
			from_string<float>(Y1[l1], A3, std::dec);
			if (Y1[l1]>ymax1) ymax1=Y1[l1];
			if (Y1[l1]<ymin1) ymin1=Y1[l1];
			from_string<float>(Z1[l1], A4, std::dec);
			if (Z1[l1]>zmax1) zmax1=Z1[l1];
			if (Z1[l1]<zmin1) zmin1=Z1[l1];
			l1++;
		}
		else if (temp[0]=='f')
		{
			std::getline(iss, A5, ' ');
			from_string<int>(f11[l21], A3, std::dec);
			from_string<int>(f12[l21], A4, std::dec);
			from_string<int>(f13[l21], A5, std::dec);
			l21++;
		}
		if (myfile1.eof())
		{
			k++;
		}
    }
	myfile1.close();
	
	k=0;
	
	ifstream myfile2(FileName2);
	while(k<1)
	{
		getline(myfile2,temp);
		std::istringstream iss(temp);
		std::getline(iss, A1, ' ');
		std::getline(iss, A2, ' ');
		std::getline(iss, A3, ' ');
		std::getline(iss, A4, ' ');
		if (temp[0]=='v')
		{
			from_string<float>(X2[l2], A2, std::dec);
			if (X2[l2]>xmax2) xmax2=X2[l2];
			if (X2[l2]<xmin2) xmin2=X2[l2];
			from_string<float>(Y2[l2], A3, std::dec);
			if (Y2[l2]>ymax2) ymax2=Y2[l2];
			if (Y2[l2]<ymin2) ymin2=Y2[l2];
			from_string<float>(Z2[l2], A4, std::dec);
			if (Z2[l2]>zmax2) zmax2=Z2[l2];
			if (Z2[l2]<zmin2) zmin2=Z2[l2];
			l2++;
		}
		else if (temp[0]=='f')
		{
			std::getline(iss, A5, ' ');
			from_string<int>(f21[l22], A3, std::dec);
			from_string<int>(f22[l22], A4, std::dec);
			from_string<int>(f23[l22], A5, std::dec);
			l22++;
		}
		if (myfile2.eof())
		{
			k++;
		}
    }
	myfile2.close();
}

//-----------------------------------------------------------

void Create_Objects(int l,int n,int col[40000],float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000],float xmax,float ymax,float zmax,float xmin,float ymin,float zmin)
{
	int e=0;
	int r=0;
	int t=0;
	if (hier==1) hierax++;
	if (hier==2) hieray++;
	if (hier==3) hieraz++;
	
	glPushMatrix();

// Object placement at position (0,0,0)
//---------------------------------------------------

	Trx=(-(xmax-xmin)/2)-xmin;
	Try=(-(ymax-ymin)/2)-ymin;
	Trz=(-(zmax-zmin)/2)-zmin;
	
	glTranslatef(Trx,Try,Trz);
	
// Object Design
//---------------------------------------------------

	for (int i=0;i<n;i++)
	{

	// Wired Form
	//--------------------------
	if (sol==0)	glBegin(GL_LINE_LOOP);
	//--------------------------

	// Solid Form
	//--------------------------
	if (sol==1) glBegin(GL_TRIANGLES);
	//--------------------------

		e=f1[i];
		r=f2[i];
		t=f3[i];

		point1[0]=X[e-1];
		point1[1]=Y[e-1];
		point1[2]=Z[e-1];

		point2[0]=X[r-1];
		point2[1]=Y[r-1];
		point2[2]=Z[r-1];

		point3[0]=X[t-1];
		point3[1]=Y[t-1];
		point3[2]=Z[t-1];

		if (col[i]==1) glColor3f(1,0,0);
		else glColor3f(160./255, 82./255, 45./255);

		getFaceNormal (normal,point1,point2,point3);
		glNormal3f(normal[0],normal[1],normal[2]);

		glVertex3f(X[e-1],Y[e-1],Z[e-1]);
		glVertex3f(X[r-1],Y[r-1],Z[r-1]);
		glVertex3f(X[t-1],Y[t-1],Z[t-1]);

		glEnd();
	}

	s++;
//----------------------------------------------------

	glPopMatrix();

// Bounding Sphere
//---------------------------------------------------

	float xrad=0;
	float yrad=0;
	float zrad=0;
	float radius=0;
	float max=0;
	for (int i=0;i<l;i++)
	{
		xrad=(X[i]+Trx);
		yrad=(Y[i]+Try);
		zrad=(Z[i]+Trz);
		radius=sqrt(pow(xrad,2)+pow(yrad,2)+pow(zrad,2));
		if (hierax==1 && X[i]>xmin && radius>max) max=radius;
		if (hierax==2 && X[i]<xmax && radius>max) max=radius;
		if (hieray==1 && Y[i]>ymin && X[i]>xmin && radius>max) max=radius;
		if (hieray==2 && Y[i]<ymax && X[i]>xmin && radius>max) max=radius;
		if (hieray==3 && Y[i]>ymin && X[i]<xmax && radius>max) max=radius;
		if (hieray==4 && Y[i]<ymax && X[i]<xmax && radius>max) max=radius;
		if (hieraz==1 && Z[i]>zmin && Y[i]>ymin && X[i]>xmin && radius>max) max=radius;
		if (hieraz==2 && Z[i]<zmax && Y[i]>ymin && X[i]>xmin && radius>max) max=radius;
		if (hieraz==3 && Z[i]>zmin && Y[i]<ymax && X[i]>xmin && radius>max) max=radius;
		if (hieraz==4 && Z[i]<zmax && Y[i]<ymax && X[i]>xmin && radius>max) max=radius;
		if (hieraz==5 && Z[i]>zmin && Y[i]>ymin && X[i]<xmax && radius>max) max=radius;
		if (hieraz==6 && Z[i]<zmax && Y[i]>ymin && X[i]<xmax && radius>max) max=radius;
		if (hieraz==7 && Z[i]>zmin && Y[i]<ymax && X[i]<xmax && radius>max) max=radius;
		if (hieraz==8 && Z[i]<zmax && Y[i]<ymax && X[i]<xmax && radius>max) max=radius;
		if (hier==0 && radius>max) max=radius;
	}
	radi=max;
	glColor4f(1, 0, 1,0.2);
	if(sphere==1) glutSolidSphere(max,100,100);
//---------------------------------------------------

// AABB
//---------------------------------------------------
	if(cube==1)
	{
		glColor4f(1, 1, 0.3,0.3);
		glScalef(xmax-xmin,ymax-ymin,zmax-zmin);
		glutSolidCube(1);
	}
//---------------------------------------------------

}

//-----------------------------------------------------------

int Min_Area(int n,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000])
{
	int e=0;
	int r=0;
	int t=0;
	float a=0;
	float b=0;
	float c=0;
	int minareacount=0;
	float ar=0;
	float min=1000;

	for (int i=0;i<n;i++)
	{
		e=f1[i];
		r=f2[i];
		t=f3[i];
		a=sqrt(pow((X[e-1]-X[r-1]),2)+pow((Y[e-1]-Y[r-1]),2)+pow((Z[e-1]-Z[r-1]),2));
		b=sqrt(pow((X[e-1]-X[t-1]),2)+pow((Y[e-1]-Y[t-1]),2)+pow((Z[e-1]-Z[t-1]),2));
		c=sqrt(pow((X[t-1]-X[r-1]),2)+pow((Y[t-1]-Y[r-1]),2)+pow((Z[t-1]-Z[r-1]),2));
		ar=sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b))/4;    //Heron's Formula
		if (ar<min)
		{
			min=ar;
			minareacount=i;
		}
	}
	return minareacount;
}

//-----------------------------------------------------------

void Collision_F()
{
	for (int i=0;i<l21;i++) cola[i]=0;
	for (int i=0;i<l22;i++) colb[i]=0;
	int k=0;
	int g=0;
	int r=0;
	int o=0;
	int g1=0;
	int r1=0;
	int o1=0;
	float c[3];
	float c1[3];
	float c2[3];
	float c3[3];
	float n[3];
	float e[3];
	float d=0;
	float t=0;
	float temp=0;
	float u2=0;
	float u3=0;
	float Trx1=0;
	float Try1=0;
	float Trz1=0;
	float Trx2=0;
	float Try2=0;
	float Trz2=0;
	int colnumber=0;
	Trx1=(-(xmax1-xmin1)/2)-xmin1;
	Try1=(-(ymax1-ymin1)/2)-ymin1;
	Trz1=(-(zmax1-zmin1)/2)-zmin1;
	Trx2=(-(xmax2-xmin2)/2)-xmin2;
	Try2=(-(ymax2-ymin2)/2)-ymin2;
	Trz2=(-(zmax2-zmin2)/2)-zmin2;
	for (int i=0;i<l21;i++)
	{
		g=f11[i];
		r=f12[i];
		o=f13[i];
		c2[0]=X1[g-1]-X1[r-1];
		c2[1]=Y1[g-1]-Y1[r-1];
		c2[2]=Z1[g-1]-Z1[r-1];
		c3[0]=X1[o-1]-X1[r-1];
		c3[1]=Y1[o-1]-Y1[r-1];
		c3[2]=Z1[o-1]-Z1[r-1];
		for (int k=0;k<l22;k++)
		{
			g1=f21[k];
			r1=f22[k];
			o1=f23[k];
			c1[0]=X2[g1-1]-X2[r1-1];
			c1[1]=Y2[g1-1]-Y2[r1-1];
			c1[2]=Z2[g1-1]-Z2[r1-1];
			c[0]=(X2[g1-1]+Trx2+tx2+100)-(X1[r-1]+Trx1+tx1-100);
			c[1]=(Y2[g1-1]+Try2+ty2)-(Y1[r-1]+Try1+ty1);
			c[2]=(Z2[g1-1]+Trz2+tz2-150)-(Z1[r-1]+Trz1+tz1-150);
			crossProduct(n,c2,c3);
			crossProduct(e,c1,c);
			d=innerProduct(c1,n);
			temp=innerProduct(c,n);
			t=temp/d;
			temp=innerProduct(c3,e);
			u2=temp/d;
			c2[0]=-c2[0];
			c2[1]=-c2[1];
			c2[2]=-c2[2];
			temp=innerProduct(c2,e);
			u3=temp/d;
			if (u2>=0 && u2<=1 && u3>=0 && u3<=1 && t>=0 && t<=1) 
			{
				cola[i]=1;
				colb[k]=1;
			}
			c1[0]=X2[o1-1]-X2[r1-1];
			c1[1]=Y2[o1-1]-Y2[r1-1];
			c1[2]=Z2[o1-1]-Z2[r1-1];
			c[0]=(X2[o1-1]+Trx2+tx2+100)-(X1[r-1]+Trx1+tx1-100);
			c[1]=(Y2[o1-1]+Try2+ty2)-(Y1[r-1]+Try1+ty1);
			c[2]=(Z2[o1-1]+Trz2+tz2-150)-(Z1[r-1]+Trz1+tz1-150);
			crossProduct(n,c2,c3);
			crossProduct(e,c1,c);
			d=innerProduct(c1,n);
			temp=innerProduct(c,n);
			t=temp/d;
			temp=innerProduct(c3,e);
			u2=temp/d;
			c2[0]=-c2[0];
			c2[1]=-c2[1];
			c2[2]=-c2[2];
			temp=innerProduct(c2,e);
			u3=temp/d;
			if (u2>=0 && u2<=1 && u3>=0 && u3<=1 && t>=0 && t<=1) 
			{
				cola[i]=1;
				colb[k]=1;
			}
			c1[0]=X2[g1-1]-X2[o1-1];
			c1[1]=Y2[g1-1]-Y2[o1-1];
			c1[2]=Z2[g1-1]-Z2[o1-1];
			c[0]=(X2[g1-1]+Trx2+tx2+100)-(X1[r-1]+Trx1+tx1-100);
			c[1]=(Y2[g1-1]+Try2+ty2)-(Y1[r-1]+Try1+ty1);
			c[2]=(Z2[g1-1]+Trz2+tz2-150)-(Z1[r-1]+Trz1+tz1-150);
			crossProduct(n,c2,c3);
			crossProduct(e,c1,c);
			d=innerProduct(c1,n);
			temp=innerProduct(c,n);
			t=temp/d;
			temp=innerProduct(c3,e);
			u2=temp/d;
			c2[0]=-c2[0];
			c2[1]=-c2[1];
			c2[2]=-c2[2];
			temp=innerProduct(c2,e);
			u3=temp/d;
			if (u2>=0 && u2<=1 && u3>=0 && u3<=1 && t>=0 && t<=1) 
			{
				cola[i]=1;
				colb[k]=1;
			}
			if (colb[k]==1) colnumber++;
		}
	}
	printf("number of collisions:%d\n",colnumber);
	collision=0;
}

//-----------------------------------------------------------

int Hierarchy_Levelx(int l,int n,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000],float xmax,float ymax,float zmax,float xmin,float ymin,float zmin,int *f1max,int *f2max,int *f3max,int *f1min,int *f2min,int *f3min)
{
	int e=0;
	int r=0;
	int t=0;
	int k1=0;
	int k2=0;
	for (int i=0;i<n;i++)
	{
		e=f1[i];
		r=f2[i];
		t=f3[i];
		if (X[e-1]>=((xmax-xmin)/2)+xmin && X[r-1]>=((xmax-xmin)/2)+xmin && X[t-1]>=((xmax-xmin)/2)+xmin)
		{
			f1max[k1]=f1[i];
			f2max[k1]=f2[i];
			f3max[k1]=f3[i];
			k1++;
		}
		if (X[e-1]<((xmax-xmin)/2)+xmin && X[r-1]<((xmax-xmin)/2)+xmin && X[t-1]<((xmax-xmin)/2)+xmin)
		{
			f1min[k2]=f1[i];
			f2min[k2]=f2[i];
			f3min[k2]=f3[i];
			k2++;
		}
	}
	tix++;
	if (tix%2==1) return k1;
	else return k2;
}

//-----------------------------------------------------------

int Hierarchy_Levely(int l,int n,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000],float xmax,float ymax,float zmax,float xmin,float ymin,float zmin,int *f1max,int *f2max,int *f3max,int *f1min,int *f2min,int *f3min)
{
	int e=0;
	int r=0;
	int t=0;
	int k1=0;
	int k2=0;
	for (int i=0;i<n;i++)
	{
		e=f1[i];
		r=f2[i];
		t=f3[i];
		if (Y[e-1]>=((ymax-ymin)/2)+ymin && Y[r-1]>=((ymax-ymin)/2)+ymin && Y[t-1]>=((ymax-ymin)/2)+ymin)
		{
			f1max[k1]=f1[i];
			f2max[k1]=f2[i];
			f3max[k1]=f3[i];
			k1++;
		}
		if (Y[e-1]<((ymax-ymin)/2)+ymin && Y[r-1]<((ymax-ymin)/2)+ymin && Y[t-1]<((ymax-ymin)/2)+ymin)
		{
			f1min[k2]=f1[i];
			f2min[k2]=f2[i];
			f3min[k2]=f3[i];
			k2++;
		}
	}
	tiy++;
	if (tiy%2==1) return k1;
	else return k2;
}

//-----------------------------------------------------------

int Hierarchy_Levelz(int l,int n,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000],float xmax,float ymax,float zmax,float xmin,float ymin,float zmin,int *f1max,int *f2max,int *f3max,int *f1min,int *f2min,int *f3min)
{
	int e=0;
	int r=0;
	int t=0;
	int k1=0;
	int k2=0;
	for (int i=0;i<n;i++)
	{
		e=f1[i];
		r=f2[i];
		t=f3[i];
		if (Z[e-1]>=((zmax-zmin)/2)+zmin && Z[r-1]>=((zmax-zmin)/2)+zmin && Z[t-1]>=((zmax-zmin)/2)+zmin)
		{
			f1max[k1]=f1[i];
			f2max[k1]=f2[i];
			f3max[k1]=f3[i];
			k1++;
		}
		if (Z[e-1]<((zmax-zmin)/2)+zmin && Z[r-1]<((zmax-zmin)/2)+zmin && Z[t-1]<((zmax-zmin)/2)+zmin)
		{
			f1min[k2]=f1[i];
			f2min[k2]=f2[i];
			f3min[k2]=f3[i];
			k2++;
		}
	}
	tiz++;
	if (tiz%2==1) return k1;
	else return k2;
}

//-----------------------------------------------------------

int Edge_Collapse(int n,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000])
{
	int e=0;
	int r=0;
	int t=0;
	int h=n;
	int min=0;
	int temp=0;
	for (float i=0;i<n*lod;i++)
	{
		min=Min_Area(h,X,Y,Z,f1,f2,f3);
		e=f1[min];
		r=f2[min];
		t=f3[min];
		temp=h;
		h=0;
		for (int k=0;k<temp;k++)
		{

			if (f1[k]==r)
			{
				f1[k]=e;
			}
			if (f2[k]==r)
			{
				f2[k]=e;
			}
			if (f3[k]==r)
			{
				f3[k]=e;
			}
			if (!(f1[k]==f2[k]) && !(f2[k]==f3[k]) && !(f1[k]==f3[k]))
			{
				f1[h]=f1[k];
				f2[h]=f2[k];
				f3[h]=f3[k];
				h++;
			}
		}
	}
	printf("Initial Number of Triangles:%d Remaining Triangles:%d\n",n,h);
	return h;
}

//-----------------------------------------------------------

void Keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 'e' : exit(0);
		break;
	case 'q' : tx-=2.0f;
		break;
	case 'w' : tx+=2.0f;
		break;
	case 'a' : ty-=2.0f;
		break;
	case 's' : ty+=2.0f;
		break;
	case 'z' : tz-=2.0f;
		break;
	case 'x' : tz+=2.0f;
		break;
	case 'k' : obj1=1;
		if (but==1)
		{
			if (j2==0)
			{
				butoldx2=butx;
				butoldy2=buty;
			}
			j2=1;
			j22=0;
		}
		break;
	case 'l' : obj2=1;
		if (but==1)
		{
			if (j==0)
			{
				butoldx1=butx;
				butoldy1=buty;
			}
			j=1;
			j11=0;
		}
		break;
	default : break;
	}

	glutPostRedisplay();

}

//-----------------------------------------------------------

void KeyboardUp(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 'k': obj1=0;
		if (but==1)
		{
			if (j22==0)
			{
				rx2=rotold2x2;
				ry2=rotold2y2;
			}
			j22=1;
			j2=0;
		}
		break;
	case 'l': obj2=0;
		if (but==1)
		{
			if (j11==0)
			{
				rx1=rotold1x1;
				ry1=rotold1y1;
			}
			j11=1;
			j=0;
		}
		break;
	}
}

//-----------------------------------------------------------

void MouseMove(int x,int y)
{
	butx=x;
	buty=y;
}

//-----------------------------------------------------------

void Mouse(int button,int state,int x,int y)
{
	
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		butx=x;
		buty=y;
		xold=x;
		yold=y;
		but=1;
	}
	
	 if(state == GLUT_UP  && button == GLUT_LEFT_BUTTON) but=0;
	 
	 glutPostRedisplay();

}

//-----------------------------------------------------------

void Volume(int ltr,float X[17000],float Y[17000],float Z[17000],int f1[40000],int f2[40000],int f3[40000],float xmax,float ymax,float zmax,float xmin,float ymin,float zmin)
{
	int internal=0;
	int internal1=0;
	int g=0;
	int r=0;
	int o=0;
	float c[3];
	float c1[3];
	float c2[3];
	float c3[3];
	float n[3];
	float e[3];
	float d=0;
	float t=0;
	float temp=0;
	float u2=0;
	float u3=0;
	for (int i=xmin;i<xmax;i=i+(xmax-xmin)/10)
	{
		for (int k=ymin;k<ymax;k=k+(ymax-ymin)/10)
		{
			for (int l=zmin;l<zmax;l=l+(zmax-zmin)/10)
			{
				c1[0]=i-xmin;
				c1[1]=k-ymin;
				c1[2]=l-zmin;
				internal=0;
				for (int tr=0;tr<ltr;tr++)
				{
					g=f1[tr];
					r=f2[tr];
					o=f3[tr];
					c[0]=i-(X[g-1]);
					c[1]=k-(Y[g-1]);
					c[2]=l-(Z[g-1]);
					c2[0]=X[r-1]-X[g-1];
					c2[1]=Y[r-1]-Y[g-1];
					c2[2]=Z[r-1]-Z[g-1];
					c3[0]=X[o-1]-X[g-1];
					c3[1]=Y[o-1]-Y[g-1];
					c3[2]=Z[o-1]-Z[g-1];
					crossProduct(n,c2,c3);
					crossProduct(e,c1,c);
					d=innerProduct(c1,n);
					temp=innerProduct(c,n);
					t=temp/d;
					temp=innerProduct(c3,e);
					u2=temp/d;
					c2[0]=-c2[0];
					c2[1]=-c2[1];
					c2[2]=-c2[2];
					temp=innerProduct(c2,e);
					u3=temp/d;
					if (u2>=0 && u2<=1 && u3>=0 && u3<=1 && t>=0 && t<=1) 
					{
						internal++;
					}
				}
				if (internal%2==1)
				{
					internal1++;
				}
			}
		}
	}
	float volbb=(xmax-xmin)*(ymax-ymin)*(zmax-zmin);
	float volsphere=(4/3)*pi*(pow(radi,3));
	float volobj=internal1*((xmax-xmin)/10)*((ymax-ymin)/10)*((zmax-zmin)/10);
	printf("Coverage Factor of AABB:%f and Coverage Factor of Sphere:%f\n",volobj/volbb,volobj/volsphere);
}

//----------------------------------------------------------

void MenuSelect(int choice)
{
	switch (choice) {
		case COLLISION : collision=1; break;
		case DEF : 
			{
				hier=0;
				sol=1;
				collap=0;
				s=0;
				sphere=0;
				cube=0;
			} break;
		case LOD2 :
			{
				lod=0.25;
				collap=1;
			} break;
		case LOD5 :
			{
				lod=0.44;
				collap=1;
			} break;
		case WIREFRAME : sol=0; break;
		case BSPHERE : sphere=1; break;
		case AABB : cube=1; break;
		case COVFAC : coverfac=1; break;
		case HIER1 : 
			{
				hier=1;
				hierarchy=1;
			} break;
		case HIER2 : 
			{
				hier=2;
				hierarchy=2;
			} break;
		case HIER3 : 
			{
				hier=3;
				hierarchy=3;
			} break;
	}
}

//-----------------------------------------------------------
void Render()
{    
	//CLEARS FRAME BUFFER ie COLOR BUFFER& DEPTH BUFFER (1.0)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clean up the colour of the window
													   // and the depth buffer
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	// Calculation of Rotate,Translate

	if (but==1)
	{
		if (obj1==1 || (obj1==0 && obj2==0))
		{
			rotx1=butx-xold+rotoldx1-rotold1x1;
			roty1=buty-yold+rotoldy1-rotold1y1;
		}
		else
		{
			rotold1x1=rx1+butx-butoldx1;
			rotold1y1=ry1+buty-butoldy1;
		}
		if (obj2==1 || (obj1==0 && obj2==0))
		{
			rotx2=butx-xold+rotoldx2-rotold2x2;
			roty2=buty-yold+rotoldy2-rotold2y2;
		}
		else
		{
			rotold2x2=rx2+butx-butoldx2;
			rotold2y2=ry2+buty-butoldy2;
		}
	}
	else
	{
		rotoldx1=rotx1;
		rotoldy1=roty1;
		rotoldx2=rotx2;
		rotoldy2=roty2;
		rotold1x1=0;
		rotold1y1=0;
		rotold2x2=0;
		rotold2y2=0;
	}
	if (obj1==1)
	{
		toldx2=tx-tx2;
		toldy2=ty-ty2;
		toldz2=tz-tz2;
	}
	if (obj2==1)
	{
		toldx1=tx-tx1;
		toldy1=ty-ty1;
		toldz1=tz-tz1;
	}

	if (obj1==1 || (obj1==0 && obj2==0))
	{
		tx1=tx-toldx1;
		ty1=ty-toldy1;
		tz1=tz-toldz1;
	}
	if (obj2==1 || (obj1==0 && obj2==0))
	{
		tx2=tx-toldx2;
		ty2=ty-toldy2;
		tz2=tz-toldz2;
	}

//--------------------------------------------

	if (s==0) 
	{
		Import_Objects("Model_1.obj","Model_2.obj");
		for (int i=0;i<=l21;i++) cola[i]=0;
		for (int i=0;i<=l22;i++) colb[i]=0;
	}
	if (collision==1) Collision_F();
	if (collap==1)
	{
		l21=Edge_Collapse(l21,X1,Y1,Z1,f11,f12,f13);
		l22=Edge_Collapse(l22,X2,Y2,Z2,f21,f22,f23);
		collap=0;
	}
	glPushMatrix();
	glTranslatef(-100,0,-150);
	glTranslatef(tx1,ty1,tz1);
	glRotatef(rotx1,1,0,0);
	glRotatef(roty1,0,1,0);
	if (hier>=1)
	{
		if (hierarchy>=1)
		{
			l1xa=Hierarchy_Levelx(l1,l21,X1,Y1,Z1,f11,f12,f13,xmax1,ymax1,zmax1,xmin1,ymin1,zmin1,f11xmax,f12xmax,f13xmax,f11xmin,f12xmin,f13xmin);
			l1xb=Hierarchy_Levelx(l1,l21,X1,Y1,Z1,f11,f12,f13,xmax1,ymax1,zmax1,xmin1,ymin1,zmin1,f11xmax,f12xmax,f13xmax,f11xmin,f12xmin,f13xmin);
			tix=0;
			
		}
		if (hier==1) 
		{	
			glPushMatrix();
			glTranslatef(50,0,0);
			Create_Objects(l1,l1xa,cola,X1,Y1,Z1,f11xmax,f12xmax,f13xmax,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1xa,X1,Y1,Z1,f11xmax,f12xmax,f13xmax,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,0,0);
			Create_Objects(l1,l1xb,cola,X1,Y1,Z1,f11xmin,f12xmin,f13xmin,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1xb,X1,Y1,Z1,f11xmin,f12xmin,f13xmin,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,ymin1,zmin1);
			glPopMatrix();
			hierax=0;
		}
		if (hierarchy>=2) 
		{
			l1ya=Hierarchy_Levely(l1,l1xa,X1,Y1,Z1,f11xmax,f12xmax,f13xmax,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1,f11y1max,f12y1max,f13y1max,f11y1min,f12y1min,f13y1min);
			l1yb=Hierarchy_Levely(l1,l1xa,X1,Y1,Z1,f11xmax,f12xmax,f13xmax,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1,f11y1max,f12y1max,f13y1max,f11y1min,f12y1min,f13y1min);
			tiy=0;
			l1ya2=Hierarchy_Levely(l1,l1xb,X1,Y1,Z1,f11xmin,f12xmin,f13xmin,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,ymin1,zmin1,f11y2max,f12y2max,f13y2max,f11y2min,f12y2min,f13y2min);
			l1yb2=Hierarchy_Levely(l1,l1xb,X1,Y1,Z1,f11xmin,f12xmin,f13xmin,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,ymin1,zmin1,f11y2max,f12y2max,f13y2max,f11y2min,f12y2min,f13y2min);
			tiy=0;
		}
		if (hier==2) 
		{	
			glPushMatrix();
			glTranslatef(50,40,0);
			Create_Objects(l1,l1ya,cola,X1,Y1,Z1,f11y1max,f12y1max,f13y1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			if (coverfac==1) Volume(l1ya,X1,Y1,Z1,f11y1max,f12y1max,f13y1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,0);
			Create_Objects(l1,l1yb,cola,X1,Y1,Z1,f11y1min,f12y1min,f13y1min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1yb,X1,Y1,Z1,f11y1min,f12y1min,f13y1min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,0);
			Create_Objects(l1,l1ya2,cola,X1,Y1,Z1,f11y2max,f12y2max,f13y2max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			if (coverfac==1) Volume(l1ya2,X1,Y1,Z1,f11y2max,f12y2max,f13y2max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,0);
			Create_Objects(l1,l1yb2,cola,X1,Y1,Z1,f11y2min,f12y2min,f13y2min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1yb2,X1,Y1,Z1,f11y2min,f12y2min,f13y2min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,zmin1);
			glPopMatrix();
			hieray=0;
		}
		if (hierarchy==3) 
		{
			l1za=Hierarchy_Levelz(l1,l1ya,X1,Y1,Z1,f11y1max,f12y1max,f13y1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1,f11z1max,f12z1max,f13z1max,f11z1min,f12z1min,f13z1min);
			l1zb=Hierarchy_Levelz(l1,l1ya,X1,Y1,Z1,f11y1max,f12y1max,f13y1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1,f11z1max,f12z1max,f13z1max,f11z1min,f12z1min,f13z1min);
			tiz=0;
			l1za2=Hierarchy_Levelz(l1,l1yb,X1,Y1,Z1,f11y1min,f12y1min,f13y1min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1,f11z2max,f12z2max,f13z2max,f11z2min,f12z2min,f13z2min);
			l1zb2=Hierarchy_Levelz(l1,l1yb,X1,Y1,Z1,f11y1min,f12y1min,f13y1min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,zmin1,f11z2max,f12z2max,f13z2max,f11z2min,f12z2min,f13z2min);
			tiz=0;
			l1za3=Hierarchy_Levelz(l1,l1ya2,X1,Y1,Z1,f11y2max,f12y2max,f13y2max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,zmin1,f11z3max,f12z3max,f13z3max,f11z3min,f12z3min,f13z3min);
			l1zb3=Hierarchy_Levelz(l1,l1ya2,X1,Y1,Z1,f11y2max,f12y2max,f13y2max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,zmin1,f11z3max,f12z3max,f13z3max,f11z3min,f12z3min,f13z3min);
			tiz=0;
			l1za4=Hierarchy_Levelz(l1,l1yb2,X1,Y1,Z1,f11y2min,f12y2min,f13y2min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,zmin1,f11z4max,f12z4max,f13z4max,f11z4min,f12z4min,f13z4min);
			l1zb4=Hierarchy_Levelz(l1,l1yb2,X1,Y1,Z1,f11y2min,f12y2min,f13y2min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,zmin1,f11z4max,f12z4max,f13z4max,f11z4min,f12z4min,f13z4min);
			tiz=0;
		}
		if (hier==3) 
		{	
			glPushMatrix();
			glTranslatef(50,40,40);
			Create_Objects(l1,l1za,cola,X1,Y1,Z1,f11z1max,f12z1max,f13z1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,((zmax1-zmin1)/2)+zmin1);
			if (coverfac==1) Volume(l1yb2,X1,Y1,Z1,f11z1max,f12z1max,f13z1max,xmax1,ymax1,zmax1,((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,((zmax1-zmin1)/2)+zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,40,-40);
			Create_Objects(l1,l1zb,cola,X1,Y1,Z1,f11z1min,f12z1min,f13z1min,xmax1,ymax1,zmax1-((zmax1-zmin1)/2),((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			if (coverfac==1) Volume(l1zb,X1,Y1,Z1,f11z1min,f12z1min,f13z1min,xmax1,ymax1,zmax1-((zmax1-zmin1)/2),((xmax1-xmin1)/2)+xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,40);
			Create_Objects(l1,l1za2,cola,X1,Y1,Z1,f11z2max,f12z2max,f13z2max,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,((zmax1-zmin1)/2)+zmin1);
			if (coverfac==1) Volume(l1za2,X1,Y1,Z1,f11z2max,f12z2max,f13z2max,xmax1,ymax1-((ymax1-ymin1)/2),zmax1,((xmax1-xmin1)/2)+xmin1,ymin1,((zmax1-zmin1)/2)+zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,-40);
			Create_Objects(l1,l1zb2,cola,X1,Y1,Z1,f11z2min,f12z2min,f13z2min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1-((zmax1-zmin1)/2),((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1zb2,X1,Y1,Z1,f11z2min,f12z2min,f13z2min,xmax1,ymax1-((ymax1-ymin1)/2),zmax1-((zmax1-zmin1)/2),((xmax1-xmin1)/2)+xmin1,ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,40);
			Create_Objects(l1,l1za3,cola,X1,Y1,Z1,f11z3max,f12z3max,f13z3max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,((zmax1-zmin1)/2)+zmin1);
			if (coverfac==1) Volume(l1za3,X1,Y1,Z1,f11z3max,f12z3max,f13z3max,xmax1-((xmax1-xmin1)/2),ymax1,zmax1,xmin1,((ymax1-ymin1)/2)+ymin1,((zmax1-zmin1)/2)+zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,-40);
			Create_Objects(l1,l1zb3,cola,X1,Y1,Z1,f11z3min,f12z3min,f13z3min,xmax1-((xmax1-xmin1)/2),ymax1,zmax1-((zmax1-zmin1)/2),xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			if (coverfac==1) Volume(l1zb3,X1,Y1,Z1,f11z3min,f12z3min,f13z3min,xmax1-((xmax1-xmin1)/2),ymax1,zmax1-((zmax1-zmin1)/2),xmin1,((ymax1-ymin1)/2)+ymin1,zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,40);
			Create_Objects(l1,l1za4,cola,X1,Y1,Z1,f11z4max,f12z4max,f13z4max,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,((zmax1-zmin1)/2)+zmin1);
			if (coverfac==1) Volume(l1za4,X1,Y1,Z1,f11z4max,f12z4max,f13z4max,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1,xmin1,ymin1,((zmax1-zmin1)/2)+zmin1);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,-40);
			Create_Objects(l1,l1zb4,cola,X1,Y1,Z1,f11z4min,f12z4min,f13z4min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1-((zmax1-zmin1)/2),xmin1,ymin1,zmin1);
			if (coverfac==1) Volume(l1zb4,X1,Y1,Z1,f11z4min,f12z4min,f13z4min,xmax1-((xmax1-xmin1)/2),ymax1-((ymax1-ymin1)/2),zmax1-((zmax1-zmin1)/2),xmin1,ymin1,zmin1);
			glPopMatrix();
			hieraz=0;
		}
	}
	else
	{
		Create_Objects(l1,l21,cola,X1,Y1,Z1,f11,f12,f13,xmax1,ymax1,zmax1,xmin1,ymin1,zmin1);
		if (coverfac==1) Volume(l21,X1,Y1,Z1,f11,f12,f13,xmax1,ymax1,zmax1,xmin1,ymin1,zmin1);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100,0,-150);
	glTranslatef(tx2,ty2,tz2);
	glRotatef(rotx2,1,0,0);
	glRotatef(roty2,0,1,0);
	if (hier>=1)
	{
		if (hierarchy>=1)
		{
			l2xa=Hierarchy_Levelx(l2,l22,X2,Y2,Z2,f21,f22,f23,xmax2,ymax2,zmax2,xmin2,ymin2,zmin2,f21xmax,f22xmax,f23xmax,f21xmin,f22xmin,f23xmin);
			l2xb=Hierarchy_Levelx(l2,l22,X2,Y2,Z2,f21,f22,f23,xmax2,ymax2,zmax2,xmin2,ymin2,zmin2,f21xmax,f22xmax,f23xmax,f21xmin,f22xmin,f23xmin);
			tix=0;
			
		}
		if (hier==1) 
		{	
			glPushMatrix();
			glTranslatef(50,0,0);
			Create_Objects(l2,l2xa,colb,X2,Y2,Z2,f21xmax,f22xmax,f23xmax,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2xa,X2,Y2,Z2,f21xmax,f22xmax,f23xmax,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,0,0);
			Create_Objects(l2,l2xb,colb,X2,Y2,Z2,f21xmin,f22xmin,f23xmin,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2xb,X2,Y2,Z2,f21xmin,f22xmin,f23xmin,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,ymin2,zmin2);
			glPopMatrix();
			hierax=0;
		}
		if (hierarchy>=2) 
		{
			l2ya=Hierarchy_Levely(l2,l2xa,X2,Y2,Z2,f21xmax,f22xmax,f23xmax,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2,f21y1max,f22y1max,f23y1max,f21y1min,f22y1min,f23y1min);
			l2yb=Hierarchy_Levely(l2,l2xa,X2,Y2,Z2,f21xmax,f22xmax,f23xmax,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2,f21y1max,f22y1max,f23y1max,f21y1min,f22y1min,f23y1min);
			tiy=0;
			l2ya2=Hierarchy_Levely(l2,l2xb,X2,Y2,Z2,f21xmin,f22xmin,f23xmin,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,ymin2,zmin2,f21y2max,f22y2max,f23y2max,f21y2min,f22y2min,f23y2min);
			l2yb2=Hierarchy_Levely(l2,l2xb,X2,Y2,Z2,f21xmin,f22xmin,f23xmin,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,ymin2,zmin2,f21y2max,f22y2max,f23y2max,f21y2min,f22y2min,f23y2min);
			tiy=0;
		}
		if (hier==2) 
		{	
			glPushMatrix();
			glTranslatef(50,40,0);
			Create_Objects(l2,l2ya,colb,X2,Y2,Z2,f21y1max,f22y1max,f23y1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			if (coverfac==1) Volume(l2ya,X2,Y2,Z2,f21y1max,f22y1max,f23y1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,0);
			Create_Objects(l2,l2yb,colb,X2,Y2,Z2,f21y1min,f22y1min,f23y1min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2yb,X2,Y2,Z2,f21y1min,f22y1min,f23y1min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,0);
			Create_Objects(l2,l2ya2,colb,X2,Y2,Z2,f21y2max,f22y2max,f23y2max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			if (coverfac==1) Volume(l2ya2,X2,Y2,Z2,f21y2max,f22y2max,f23y2max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,0);
			Create_Objects(l2,l2yb2,colb,X2,Y2,Z2,f21y2min,f22y2min,f23y2min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2yb2,X2,Y2,Z2,f21y2min,f22y2min,f23y2min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,zmin2);
			glPopMatrix();
			hieray=0;
		}
		if (hierarchy==3) 
		{
			l2za=Hierarchy_Levelz(l2,l2ya,X2,Y2,Z2,f21y1max,f22y1max,f23y1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2,f21z1max,f22z1max,f23z1max,f21z1min,f22z1min,f23z1min);
			l2zb=Hierarchy_Levelz(l2,l2ya,X2,Y2,Z2,f21y1max,f22y1max,f23y1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2,f21z1max,f22z1max,f23z1max,f21z1min,f22z1min,f23z1min);
			tiz=0;
			l2za2=Hierarchy_Levelz(l2,l2yb,X2,Y2,Z2,f21y1min,f22y1min,f23y1min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2,f21z2max,f22z2max,f23z2max,f21z2min,f22z2min,f23z2min);
			l2zb2=Hierarchy_Levelz(l2,l2yb,X2,Y2,Z2,f21y1min,f22y1min,f23y1min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,zmin2,f21z2max,f22z2max,f23z2max,f21z2min,f22z2min,f23z2min);
			tiz=0;
			l2za3=Hierarchy_Levelz(l2,l2ya2,X2,Y2,Z2,f21y2max,f22y2max,f23y2max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,zmin2,f21z3max,f22z3max,f23z3max,f21z3min,f22z3min,f23z3min);
			l2zb3=Hierarchy_Levelz(l2,l2ya2,X2,Y2,Z2,f21y2max,f22y2max,f23y2max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,zmin2,f21z3max,f22z3max,f23z3max,f21z3min,f22z3min,f23z3min);
			tiz=0;
			l2za4=Hierarchy_Levelz(l2yb2,l22,X2,Y2,Z2,f21y2min,f22y2min,f23y2min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,zmin2,f21z4max,f22z4max,f23z4max,f21z4min,f22z4min,f23z4min);
			l2zb4=Hierarchy_Levelz(l2yb2,l22,X2,Y2,Z2,f21y2min,f22y2min,f23y2min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,zmin2,f21z4max,f22z4max,f23z4max,f21z4min,f22z4min,f23z4min);
			tiz=0;
		}
		if (hier==3) 
		{	
			glPushMatrix();
			glTranslatef(50,40,40);
			Create_Objects(l2,l2za,colb,X2,Y2,Z2,f21z1max,f22z1max,f23z1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,((zmax2-zmin2)/2)+zmin2);
			if (coverfac==1) Volume(l2za,X2,Y2,Z2,f21z1max,f22z1max,f23z1max,xmax2,ymax2,zmax2,((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,((zmax2-zmin2)/2)+zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,40,-40);
			Create_Objects(l2,l2zb,colb,X2,Y2,Z2,f21z1min,f22z1min,f23z1min,xmax2,ymax2,zmax2-((zmax2-zmin2)/2),((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			if (coverfac==1) Volume(l2zb,X2,Y2,Z2,f21z1min,f22z1min,f23z1min,xmax2,ymax2,zmax2-((zmax2-zmin2)/2),((xmax2-xmin2)/2)+xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,40);
			Create_Objects(l2,l2za2,colb,X2,Y2,Z2,f21z2max,f22z2max,f23z2max,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,((zmax2-zmin2)/2)+zmin2);
			if (coverfac==1) Volume(l2za2,X2,Y2,Z2,f21z2max,f22z2max,f23z2max,xmax2,ymax2-((ymax2-ymin2)/2),zmax2,((xmax2-xmin2)/2)+xmin2,ymin2,((zmax2-zmin2)/2)+zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50,-40,-40);
			Create_Objects(l2,l2zb2,colb,X2,Y2,Z2,f21z2min,f22z2min,f23z2min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2-((zmax2-zmin2)/2),((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2zb2,X2,Y2,Z2,f21z2min,f22z2min,f23z2min,xmax2,ymax2-((ymax2-ymin2)/2),zmax2-((zmax2-zmin2)/2),((xmax2-xmin2)/2)+xmin2,ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,40);
			Create_Objects(l2,l2za3,colb,X2,Y2,Z2,f21z3max,f22z3max,f23z3max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,((zmax2-zmin2)/2)+zmin2);
			if (coverfac==1) Volume(l2za3,X2,Y2,Z2,f21z3max,f22z3max,f23z3max,xmax2-((xmax2-xmin2)/2),ymax2,zmax2,xmin2,((ymax2-ymin2)/2)+ymin2,((zmax2-zmin2)/2)+zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,40,-40);
			Create_Objects(l2,l2zb3,colb,X2,Y2,Z2,f21z3min,f22z3min,f23z3min,xmax2-((xmax2-xmin2)/2),ymax2,zmax2-((zmax2-zmin2)/2),xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			if (coverfac==1) Volume(l2zb3,X2,Y2,Z2,f21z3min,f22z3min,f23z3min,xmax2-((xmax2-xmin2)/2),ymax2,zmax2-((zmax2-zmin2)/2),xmin2,((ymax2-ymin2)/2)+ymin2,zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,40);
			Create_Objects(l2,l2za4,colb,X2,Y2,Z2,f21z4max,f22z4max,f23z4max,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,((zmax2-zmin2)/2)+zmin2);
			if (coverfac==1) Volume(l2za4,X2,Y2,Z2,f21z4max,f22z4max,f23z4max,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2,xmin2,ymin2,((zmax2-zmin2)/2)+zmin2);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50,-40,-40);
			Create_Objects(l2,l2zb4,colb,X2,Y2,Z2,f21z4min,f22z4min,f23z4min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2-((zmax2-zmin2)/2),xmin2,ymin2,zmin2);
			if (coverfac==1) Volume(l2zb4,X2,Y2,Z2,f21z4min,f22z4min,f23z4min,xmax2-((xmax2-xmin2)/2),ymax2-((ymax2-ymin2)/2),zmax2-((zmax2-zmin2)/2),xmin2,ymin2,zmin2);
			glPopMatrix();
			hieraz=0;
		}
		hierarchy=0;
	}
	else 
	{
		Create_Objects(l2,l22,colb,X2,Y2,Z2,f21,f22,f23,xmax2,ymax2,zmax2,xmin2,ymin2,zmin2);
		if (coverfac==1) Volume(l22,X2,Y2,Z2,f21,f22,f23,xmax2,ymax2,zmax2,xmin2,ymin2,zmin2);
	}
	coverfac=0;
	glPopMatrix();
 
  glutSwapBuffers();             // All drawing commands applied to the 
                                 // hidden buffer, so now, bring forward
                                 // the hidden buffer and hide the visible one
}

//-----------------------------------------------------------

void Resize(int w, int h)
{ 
  // define the visible area of the window ( in pixels )
  if (h==0) h=1;
  glViewport(0,0,w,h); 

  // Setup viewing volume

  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
 
  gluPerspective(90.0, (float)w/(float)h, 1.0, 1500.0);
}

//-----------------------------------------------------------

void Idle()
{

	glutPostRedisplay();
}

//-----------------------------------------------------------

void Setup() 
{ 
	glEnable(GL_NORMALIZE);

	//Parameter handling
	glShadeModel (GL_SMOOTH);
	
	//(02)
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);  //renders a fragment if its z value is less or equal of the stored value
	glClearDepth(1);
    
	// (06) // polygon rendering mode
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

	//Set up light source
	GLfloat light_position[] = { 0.0, 30.0, 50.0, 0.0 };
	glLightfv( GL_LIGHT0, GL_POSITION, light_position);

	GLfloat ambientLight[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat diffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };

	   
	glLightfv( GL_LIGHT0, GL_AMBIENT, ambientLight );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, specularLight );

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// (04)
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	//(01) BLENDING
   glEnable(GL_BLEND);
   glFrontFace(GL_CW);
    // incoming //  // stored //
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Black background
	glClearColor(0.0f,0.0f,0.0f,1.0f);

}

//-----------------------------------------------------------