#include "Scene.h"
#include <cmath>
#include <tgmath.h>
#include <iostream>
#include "stdlib.h"

using namespace Raytracer148;
using namespace std;
using namespace Eigen;

HitRecord Scene::closestHit(const Ray& ray) {
    HitRecord result;
    result.t = -1;
    bool found = false;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        HitRecord r = shapes[i]->intersect(ray);
        if (r.t > std::numeric_limits<double>::epsilon() && (!found || r.t < result.t)) {
            result = r;
            found = true;
        }
    }
    return result;
}

Vector3d Scene::traceHelper(const Ray& ray, int counter) {

    HitRecord r = closestHit(ray);
    HitRecord srec;

    Vector3d result;
    result[0] = result[1] = result[2] = 0;

    if (r.t < numeric_limits<double>::epsilon()) return result;

    result = r.sh->ka;
    r.position = ray.origin + r.t * ray.direction - ray.direction * 0.00000000000001;


    Vector3d viewDir, lightDir, norm, halfVector;
    float sp, temp;

    viewDir[0] = 0;
    viewDir[1] = 0;
    viewDir[2] = 1;

    norm = r.normal.normalized();

    lightDir = (lightPos - r.position).normalized();
    double dot = lightDir.dot(r.normal);
    if (dot < 0) dot = 0;

    Ray sray;
    sray.origin = r.position;
    sray.direction = lightDir.normalized();
    srec = closestHit(sray);

    halfVector = (-ray.direction.normalized() + lightDir).normalized();
    temp = norm.dot(halfVector);
    if (temp < 0) {
        temp = 0;
    }

    sp = pow(temp, 64);

    if (srec.t > 0 && srec.t < 1) {	
        result = result + r.sh->ks * sp + r.sh->kd * dot;
    }
    else {
        result = result + r.sh->ks * sp + r.sh->kd * dot;
    }

    Vector3d ref;
    ref = ray.direction.normalized() - 2 * (ray.direction.normalized().dot(r.normal)) * r.normal;
    Ray reflectingRay;
    reflectingRay.origin = r.position;
    reflectingRay.direction = ref;

    float km = 0.35;
    if (counter > 5) {
        return result;
    }
    else {
        counter++;
        return result = result + km * traceHelper(reflectingRay, counter);
    }
    return result;
}

Vector3d Scene::trace(const Ray& ray) {
    return traceHelper(ray, 1);
}

void Scene::render(Image& image) {
    // We make the assumption that the camera is located at (0,0,0)
    // and that the image plane happens in the square from (-1,-1,1)
    // to (1,1,1).

    float rndm;
    int n = 4, size = image.getWidth();
    Vector3d c;	
    assert(image.getWidth() == image.getHeight());
    double pixelSize = 2.0 / size;

    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++) {
            Ray curRay;
            curRay.origin[0] = curRay.origin[1] = curRay.origin[2] = 0;
            c[0] = c[1] = c[2] = 0;
            for (int q = 0; q < n; q++) {
                for (int r = 0; r < n; r++) {
                    rndm = ((float)rand()) / (float)RAND_MAX;
                    curRay.direction[0] = (x + (q + rndm) / 4) * pixelSize - 1;
                    curRay.direction[1] = 1 - (y + (r + rndm) / 4) * pixelSize;
                    curRay.direction[2] = 1;
                    c = c + trace(curRay);
                }
            }
            c = c / pow(n, 2);
            image.setColor(x, y, c[0], c[1], c[2]);
        }
}