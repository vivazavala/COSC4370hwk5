#include <stdio.h>
#include "Triangle.h"
#include <limits>


using namespace Raytracer148;
using namespace Eigen;
using namespace std;


HitRecord Triangle::intersect(const Ray& ray) {
    HitRecord result;
    result.t = -1;

    Matrix3d MatA, MatBheta, MatGama, MatT;
    double t, bheta, gamma;

    MatA(0, 0) =a1[0] - b1[0];
    MatA(0, 1) =a1[0] - c1[0];
    MatA(0, 2) = ray.direction[0];
    MatA(1, 0) =a1[1] - b1[1];
    MatA(1, 1) =a1[1] - c1[1];
    MatA(1, 2) = ray.direction[1];
    MatA(2, 0) =a1[2] - b1[2];
    MatA(2, 1) =a1[2] - c1[2];
    MatA(2, 2) = ray.direction[2];

    MatBheta(0, 0) =a1[0] - ray.origin[0];
    MatBheta(0, 1) =a1[0] - c1[0];
    MatBheta(0, 2) = ray.direction[0];
    MatBheta(1, 0) =a1[1] - ray.origin[1];
    MatBheta(1, 1) =a1[1] - c1[1];
    MatBheta(1, 2) = ray.direction[1];
    MatBheta(2, 0) =a1[2] - ray.origin[2];
    MatBheta(2, 1) =a1[2] - c1[2];
    MatBheta(2, 2) = ray.direction[2];

    MatGama(0, 0) =a1[0] - b1[0];
    MatGama(0, 1) =a1[0] - ray.origin[0];
    MatGama(0, 2) = ray.direction[0];
    MatGama(1, 0) =a1[1] - b1[1];
    MatGama(1, 1) =a1[1] - ray.origin[1];
    MatGama(1, 2) = ray.direction[1];
    MatGama(2, 0) =a1[2] - b1[2];
    MatGama(2, 1) =a1[2] - ray.origin[2];
    MatGama(2, 2) = ray.direction[2];

    MatT(0, 0) =a1[0] - b1[0];
    MatT(0, 1) =a1[0] - c1[0];
    MatT(0, 2) =a1[0] - ray.origin[0];
    MatT(1, 0) =a1[1] - b1[1];
    MatT(1, 1) =a1[1] - c1[1];
    MatT(1, 2) =a1[1] - ray.origin[1];
    MatT(2, 0) =a1[2] - b1[2];
    MatT(2, 1) =a1[2] - c1[2];
    MatT(2, 2) =a1[2] - ray.origin[2];

    t = MatT.determinant() / MatA.determinant();
    bheta = MatBheta.determinant() / MatA.determinant();
    gamma = MatGama.determinant() / MatA.determinant();

    if (t < 0) {
        return result;
    }
    if (gamma < 0 || gamma>1) {
        return result;
    }
    if (bheta<0 || bheta>(1 - gamma)) {
        return result;
    }

    result.t = t;
    result.position = ray.origin + result.t * ray.direction;
    result.normal = -(b1 -a1).cross(c1 -a1);
    result.sh = this;

    return result;
}

