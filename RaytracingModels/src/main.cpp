#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shader.h"
#include <cmath>
#define GLM_FORCE_RADIANS 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace Raytracer148;
using namespace Eigen;


// References:
// http://www.3dcpptutorials.sk/index.php?id=16
// https://github.com/cemuyuk/RayTracing


int main() {
    Image im(400, 400);
    Scene scene;                  
    Vector3d center, ambient, diffuser, specular, vec0, vec1, vec2;// something, twoV1, twoV2;
    ////////////////////////////////////////////////////////////////////////////
    ///sphere1
    ambient[0] = .5;
    ambient[1] = 0;
    ambient[2] = 0;
    ///
    diffuser[0] = 0.5;
    diffuser[1] = 0;    
    diffuser[2] = 0;
    ///
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    ///
    center[0] = 0;
    center[1] = 0;
    center[2] = 4;
    scene.addShape(new Sphere(center, 2, ambient, diffuser, specular));
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ///sphere2
    ambient[0] = 0;
    ambient[1] = 0;           
    ambient[2] = .5;
    ///
    diffuser[0] = 0;
    diffuser[1] = 0;
    diffuser[2] = 0.5;
    ///
    center[0] = -.5;
    center[1] = 1;
    center[2] = 2.5;
    scene.addShape(new Sphere(center, .5, ambient, diffuser, specular));
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ///sphere3
    ambient[0] = 0;
    ambient[1] = 0.5;
    ambient[2] = 0;
    ///
    diffuser[0] = 0;             
    diffuser[1] = 0.5;
    diffuser[2] = 0;
    ///
    center[0] = 0.5;
    center[1] = 1.25;
    center[2] = 2.75;
    scene.addShape(new Sphere(center, .5, ambient, diffuser, specular));
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ///Triangle
    ambient[0] = 0;
    ambient[1] = 0.5;      
    ambient[2] = 0.5;
    ///
    diffuser[0] = 0;
    diffuser[1] = 0.5;
    diffuser[2] = 0.5;
    ///
    vec0[0] = -0.5;
    vec0[1] = 0;
    vec0[2] = 0.5;
    ///
    vec1[0] = 0.5;
    vec1[1] = -1;
    vec1[2] = 1.5;
    ///
    vec2[0] = 0;
    vec2[1] = 0.5;
    vec2[2] = 1.8;
    scene.addShape(new Triangle(vec0, vec1, vec2, ambient, diffuser, specular));
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    scene.render(im);
    im.writePNG("test.png");
   
    return 0;

}
