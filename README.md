# Mesh simplifictaion algorithm based on edge collapse

## About

Hoppe et al. [^1] describe a method, mesh optimization, that can be used to approximate an initial mesh M<sup>0</sup> by a much simpler one.<br>
Their optimization algorithm, reviewed in Section 4.1, traverses the space of possible meshes by successively applying a set of 3 mesh transformations: edge collapse, edge split, and edge swap. We have discovered that in fact a single one of those transforma- tions, edge collapse, is sufficient for effectively simplifying meshes[^2].

### Motivation behind the mesh simplification algorithm

Highly detailed geometric models are necessary to satisfy a growing expectation for realism in computer graphics. Within traditional modeling systems, detailed models are created by applying versatile modeling operations (such as extrusion, constructive solid geometry, and freeform deformations) to a vast array of geometric primitives. For efficient display, these models must usually be tessellated into polygonal approximations—meshes. Detailed meshes are also obtained by scanning physical objects using range scanning systems [^3]. In either case, the resulting complex meshes are expensive to store, transmit, and render, thus motivating a number of practical problems:
* Mesh simplification: The meshes created by modeling and scanning systems are seldom optimized for rendering efficiency, and can frequently be replaced by nearly indistinguishable approximations with far fewer faces. At present, this process often requires significant user intervention. Mesh simplification tools can hope to automate this painstaking task, and permit the porting of a single model to platforms of varying performance.
* Level-of-detail (LOD) approximation: To further improve rendering performance, it is common to define several versions of a model at various levels of detail. A detailed mesh is used when the object is close to the viewer, and coarser approximations are substituted as the object recedes. Since instantaneous switching between LOD meshes may lead to perceptible __“popping”__, one would like to construct smooth visual transitions, geomorphs, between meshes at different resolutions. [^2]

## The impemented algorithm

[This repository](https://github.com/FoivosPap/mesh-simplification-algorithm) is an implementation of the edge collapse transformation, as descibed in [^1]. Two objects are loaded and using the provided menu ([explained here](#ui-menu)) the user can get 2 different LoD approximations by recursively repeating edge collapse. Number of repetitions and the corresponding LoD:
- 1/2 of number of the total meshes' triangles (LoD 2x)
- 9/20 of number of the total meshes' triangles (LoD 10x).  

Additionally, the user is given other options such as collision detection between the objects (for the different LoDs), creation of bounding sphere or AABB (Axis Aligned Bounding Box). Finally, The objects can be divided in 2/4/8 parts for further calculations. 

## Installation

### Prerequisites
1. [Install VS code](https://code.visualstudio.com/Download?_exp_download=fb315fc982)
2. [Install C/C++ Extension](https://code.visualstudio.com/docs/languages/cpp)

### Installation Steps
1. Open VS code
2. Open a terminal in VS code
  - Click terminal in the VS code menu
  - Click new Terminal
3. Download the repository in the desired folder:
  - Move to desired download folder:
```bash
cd "your-download-folder-name"
```
- Clone repository
```bash
git clone https://github.com/FoivosPap/mesh-simplification-algorithm 
```
4. Build the app
```bash
cmake -S . -B build
cmake --build build --config Release
```

5. Run the app
```bash
./build/app
```

## Troubleshooting
In case there is a problem with building and running the application remove the files in build folder:
```bash
rm -rf build
```
Repeat the [Installation Steps (from step 4.)](#installation-steps)

## UI Menu

Right click to access the menu. Options:
- Collision
  - Identify the number of collisions between the meshes of the two objects
- Default
  - Restore default rendering
- LoD 2x
  - 2x LoD approximation
- LoD 10x
  - 2x LoD approximation
- Wireframe
- Bounding Sphere
  - Sphere that bounds the object (whole or each part in hierarchy)
- AABB (Axis Aligned Bounding Box)
  - Square that bounds the object (whole or each part in hierarchy)
- Calculate Coverage Factor
  - Calculate the overage Factor of bounding shere or square
- Hierarchy 1
  - Divide an object in 2 parts
- Hierarchy 2
  - Divide an object in 4 parts
- Hierarchy 3
  - Divide an object in 8 parts

### Navigation
Press:
- Q -> Move left
- W -> Move right
- A -> Move up
- S -> Move down
- Z -> Move forward
- X -> Move backward

The above commands move both objects simutaneously. In order to move one object only,
1. press and hold:
- K -> Choose left object
- L -> Choose right object

2. While holding K or L (for left or right object respectively) press any of the [Navigation buttons](#Navigation) to move that object only.

[^1]: Hoppe, H., DeRose, T., Duchamp, T., McDonald, J., and Stuetzle, W. Mesh optimization. Computer Graphics (SIGGRAPH ’93 Proceedings) (1993), 19–26.
[^2]: Hoppe, Hugues (1996). "Progressive meshes". Proceedings of the 23rd annual conference on Computer graphics and interactive techniques. New York, New York, USA: ACM Press. pp. 99–108. doi:10.1145/237170.237216. ISBN 0-89791-746-4.
[^3]: Curless, B., and Levoy, M. A volumetric method for building complex models from range images. Computer Graphics (SIGGRAPH ’96 Proceedings) (1996), 303–312.