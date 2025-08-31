
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
	Η κλάση FullClothModel αποθηκεύει ολόκληρο το αντικείμενο που αντιστοιχεί στο ρούχο μαζί με 
	πληροφορία ιεραρχίας (Layers) για την προσομοίωσή του
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
	Η κλάση DualObject δημιουργεί και αποθηκεύει το συζηγές ενός στατικού αντικειμένου. 
	Χρησιμοποιείται για την εύρεση και επεξεργασία του κυρτού περιβάλλοντος θόλου (convex hull)
*/
class DualObject
{
public:

	int NumOfVertices;
	int NumOfEdges;

	cmVertexType (*VertexPos)[3];
	/*! Αποστάσεις από το convex hull */
	cmVertexType *DistanceFromConvexHull;
	/*! Μέγιστη απόσταση από το convex hull */
	cmVertexType MaxDistanceFromHull;
	size_t *MeshEdges;
	cmVertexType *VertexArea;
	int **NeighboursIndex;
	short *NumOfNeighbours;

	/*! Constructor κλάσης */
	DualObject(int size);
	/*! Destructor κλάσης */
	~DualObject(){}

private:

};

//-------------------------------------------------------------------------------

/*! 
	Η κλάση StaticObject αποθηκεύει και χειρίζεται τα στατικά αντικείμενα της σκηνής.
	Χρησιμοποεί την DualObject.
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

	/*! Δημιουργία συζηγούς αντικειμένου */
	void GenerateDualGraph();
	/*! Υπολογισμός αποστάσεων συζηγούς αντικειμένου από το convex hull */
	void CalculateDualGraphDistanceFromHull();
	/*! Υπολογισμός ενεργών αποστάσεων συζηγούς αντικειμένου από το convex hull */
	void CalculateEffectiveDualGraphDistanceFromHull();
	/*! Δημιουργία convex hull */
	void GenerateConvexHull();
	/*! Εισαγωγή convex hull */
	void ImportConvexHull();
	/*! Ορισμός επιπέδου */
	void SetPlane(float Xpos, float Ypos, float Zpos, float disp);
	/*! Ορισμός σφαίρας */
	void SetSphere(SQSphere *sphere);
	/*! Ορισμός κυλίνδρου */
	void SetCylinder(SQCylinder *cylinder);
	/*! Μετατόπιση αντικειμένου */
	void TranslateObject(float dx, float dy, float dz);
	/*! Περιστροφή αντικειμένου */
	void RotateObject(float **RotMat);
	/*! Μεταφορά αντικειμένου στην αρχή των αξόνων */
	void BringObjectToCenter();
	/*! Δημιουργία τριγωνικών συνδέσεων */
	void CreateFaces();
	/*! Ορισμός κλιμάκωσης */
	void SetScale(cmVertexType Xscale,cmVertexType Yscale,cmVertexType Zscale);
	/*! Ορισμός ταχύτητας αντικειμένου */
	void SetVelocity(cmVertexType veloc1,cmVertexType veloc2,cmVertexType veloc3);
	/*! Εύρεση των παραμέτρων της περιβάλλουσας γεωμετρίας */
	void FindBoundingValues();
	/*! Αντιστροφή συντεταγμένων Ζ και Y */
	void ExchangeZYmin();
	/*! Αντιστροφή συντεταγμένων Χ και Y */
	void ExchangeXY();

	/*! Construtor κλάσης */
	StaticObject(int size);
	/*! Destructor κλάσης */
	~StaticObject();

	/*! Εισαγωγή πλέγματος */
	void ImportMesh(char *FileName);		// Εισάγει ένα αρχείο *.ver με τις συντεταγμένες των σημείων
	/*! Εισαγωγή τριγωνικών συνδέσεων */
	void ImportTris(char *FileName);		// Εισάγει ένα αρχείο *.tri με τους δείκτες των τριγώνων
	/*! Εξαγωγή πλέγματος */
	void ExportMesh(char *FileName);		// Εξάγει "
	/*! Εξαγωγή τριγωνικών συνδέσεων */
	void ExportTris(char *FileName);		// Εξάγει "
	/*! Εξαγωγή τριγωνικών συνδέσεων του convex hull Του αντικειμένου */
	void ExportConvexTris(char *FileName);	// Εξάγει ένα αρχείο με τα τρίγωνα του convex hull του αντικειμένου
	/*! Εξαγωγή χάρτη κυρτότητας */
	void ExportConvexityMap(char *FileName);// Εξάγει χάρτη απόστασης από το convex hull


	void ImportOBJfile(char *FileName, int Vers, int Tris);

private:
	PQP_REAL R1[3][3], R2[3][3], T1[3], T2[3];
	PQP_REAL p1[3], p2[3], p3[3];
	PQP_DistanceResult distres;

	/*! Αναδρομικός υπολογισμός ακμών κυρτότητας του αντικειμένου */
	void FindConvexBoundariesRecursively(int DualVerIndex, 
										 bool *TriangleProcessed, 
										 bool *ConvexBoundaries, 
										 bool *LiesInsideTheValley);
};

//-------------------------------------------------------------------------------

#endif
