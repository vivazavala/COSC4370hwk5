#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shader.h"
#include <cmath>

/*
Referenced: 
http://www.3dcpptutorials.sk/index.php?id=16
https://github.com/cemuyuk/RayTracing
*/


#define GLM_FORCE_RADIANS 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
    Image im(400, 400);

    Scene scene;                  
    Vector3d center, amb, diff, spec, oneV0, oneV1, oneV2, twoV0, twoV1, twoV2;

    amb[0] = 0;
    amb[1] = 0;
    amb[2] = .5;

    diff[0] = 0.5;
    diff[1] = 0.5;      //////1st sphere
    diff[2] = 0;

    spec[0] = 1.0;
    spec[1] = 1.0;
    spec[2] = 1.0;

    center[0] = 0;
    center[1] = 0;
    center[2] = 4;
    scene.addShape(new Sphere(center, 2, amb, diff, spec));


    amb[0] = 0;
    amb[1] = .5;            /////////2nd sphere
    amb[2] = 0;

    diff[0] = 0.25;
    diff[1] = 0;
    diff[2] = 0.5;

    center[0] = -.5;
    center[1] = 1;
    center[2] = 2.5;
    scene.addShape(new Sphere(center, .5, amb, diff, spec));

 
    amb[0] = 0.5;
    amb[1] = 0;
    amb[2] = 0;

    diff[0] = 0.5;             ////////3rd sphere
    diff[1] = 0;
    diff[2] = 0.5;

    center[0] = 0.5;
    center[1] = 1.25;
    center[2] = 2.75;
    scene.addShape(new Sphere(center, .5, amb, diff, spec));

    
    amb[0] = 0.584;
    amb[1] = 0;      ////////triangle
    amb[2] = 0.290;

    diff[0] = .8;
    diff[1] = 0;
    diff[2] = 0;

    oneV0[0] = -0.5;
    oneV0[1] = 0;
    oneV0[2] = 0.5;

    oneV1[0] = 0.5;
    oneV1[1] = -1;
    oneV1[2] = 1.5;

    oneV2[0] = 0;
    oneV2[1] = 0.5;
    oneV2[2] = 1.8;
    scene.addShape(new Triangle(oneV0, oneV1, oneV2, amb, diff, spec));

    scene.render(im);
    im.writePNG("test.png");
   
    return 0;

}
