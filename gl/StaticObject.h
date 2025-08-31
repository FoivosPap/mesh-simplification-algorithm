
#ifndef StaticObject_H
#define StaticObject_H

#include "..\ClothModelingMain.h"

//-------------------------------------------------------------------------------

class Meshed3DObject
{
public:



};

//-------------------------------------------------------------------------------
/*! 
	� ����� FullClothModel ���������� �������� �� ����������� ��� ����������� ��� ����� ���� �� 
	���������� ��������� (Layers) ��� ��� ����������� ���
*/

class FullClothModel
{
public:
	int NumOfVertices;
	int NumOfTriangles;
	size_t NumSubs;
	size_t *SubVertices;
	size_t *SubIndexes;
	cmVertexType (*VertexPos)[3];
	size_t *MeshFaces;

	int NumOfMembers_Layer[7];
    int (*VertexLayerIndex)[2];

	ImportLayerInformation(char *FileName);
	ImportOBJfile(char *FileName, int Vers, int Tris);
	FullClothModel(int size);
};


/*! 
	� ����� DualObject ���������� ��� ���������� �� ������� ���� �������� ������������. 
	��������������� ��� ��� ������ ��� ����������� ��� ������ ������������� ����� (convex hull)
*/
class DualObject
{
public:

	int NumOfVertices;
	int NumOfEdges;

	cmVertexType (*VertexPos)[3];
	/*! ���������� ��� �� convex hull */
	cmVertexType *DistanceFromConvexHull;
	/*! ������� �������� ��� �� convex hull */
	cmVertexType MaxDistanceFromHull;
	size_t *MeshEdges;
	cmVertexType *VertexArea;
	int **NeighboursIndex;
	short *NumOfNeighbours;

	/*! Constructor ������ */
	DualObject(int size);
	/*! Destructor ������ */
	~DualObject(){}

private:

};

//-------------------------------------------------------------------------------

/*! 
	� ����� StaticObject ���������� ��� ���������� �� ������� ����������� ��� ������.
	����������� ��� DualObject.
*/
class StaticObject
{
public:
	int NumOfVertices;
	int NumOfTriangles;
	int NumOfConvexTriangles;
	size_t NumSubs;
	size_t *SubVertices;
	size_t *SubIndexes;
	cmVertexType (*VertexPos)[3];
	size_t *MeshFaces;
	size_t *ConvexMeshFaces;
	bool FacesAllocated;
	cmVertexType Translation[3];
	cmVertexType BoundingValues[6];
	cmVertexType Velocity[3];
	DualObject *DualGraph;

	bool FlipNormals;
	StaticObject *ConvexHull;
	bool *VertexBelongsToConvexHull;

	/*! ���������� �������� ������������ */
	void GenerateDualGraph();
	/*! ����������� ���������� �������� ������������ ��� �� convex hull */
	void CalculateDualGraphDistanceFromHull();
	/*! ����������� ������� ���������� �������� ������������ ��� �� convex hull */
	void CalculateEffectiveDualGraphDistanceFromHull();
	/*! ���������� convex hull */
	void GenerateConvexHull();
	/*! �������� convex hull */
	void ImportConvexHull();
	/*! ������� �������� */
	void SetPlane(float Xpos, float Ypos, float Zpos, float disp);
	/*! ������� ������� */
	void SetSphere(SQSphere *sphere);
	/*! ������� ��������� */
	void SetCylinder(SQCylinder *cylinder);
	/*! ���������� ������������ */
	void TranslateObject(float dx, float dy, float dz);
	/*! ���������� ������������ */
	void RotateObject(float **RotMat);
	/*! �������� ������������ ���� ���� ��� ������ */
	void BringObjectToCenter();
	/*! ���������� ���������� ��������� */
	void CreateFaces();
	/*! ������� ���������� */
	void SetScale(cmVertexType Xscale,cmVertexType Yscale,cmVertexType Zscale);
	/*! ������� ��������� ������������ */
	void SetVelocity(cmVertexType veloc1,cmVertexType veloc2,cmVertexType veloc3);
	/*! ������ ��� ���������� ��� ������������� ���������� */
	void FindBoundingValues();
	/*! ���������� ������������� � ��� Y */
	void ExchangeZYmin();
	/*! ���������� ������������� � ��� Y */
	void ExchangeXY();

	/*! Construtor ������ */
	StaticObject(int size);
	/*! Destructor ������ */
	~StaticObject();

	/*! �������� ��������� */
	void ImportMesh(char *FileName);		// ������� ��� ������ *.ver �� ��� ������������� ��� �������
	/*! �������� ���������� ��������� */
	void ImportTris(char *FileName);		// ������� ��� ������ *.tri �� ���� ������� ��� ��������
	/*! ������� ��������� */
	void ExportMesh(char *FileName);		// ������ "
	/*! ������� ���������� ��������� */
	void ExportTris(char *FileName);		// ������ "
	/*! ������� ���������� ��������� ��� convex hull ��� ������������ */
	void ExportConvexTris(char *FileName);	// ������ ��� ������ �� �� ������� ��� convex hull ��� ������������
	/*! ������� ����� ���������� */
	void ExportConvexityMap(char *FileName);// ������ ����� ��������� ��� �� convex hull


	void ImportOBJfile(char *FileName, int Vers, int Tris);

private:
	PQP_REAL R1[3][3], R2[3][3], T1[3], T2[3];
	PQP_REAL p1[3], p2[3], p3[3];
	PQP_DistanceResult distres;

	/*! ����������� ����������� ����� ���������� ��� ������������ */
	void FindConvexBoundariesRecursively(int DualVerIndex, 
										 bool *TriangleProcessed, 
										 bool *ConvexBoundaries, 
										 bool *LiesInsideTheValley);
};

//-------------------------------------------------------------------------------

#endif
