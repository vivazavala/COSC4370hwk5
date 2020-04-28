#ifndef Triangle_h
#define Triangle_h
#include "Shape.h"

namespace Raytracer148 {
    class Triangle : public Shape {
    public:
        Triangle(Eigen::Vector3d& vZero, Eigen::Vector3d& vOne, Eigen::Vector3d& vTwo, Eigen::Vector3d& amb, Eigen::Vector3d& diff, Eigen::Vector3d& spec) :
            a1(vZero), b1(vOne), c1(vTwo)
        {
            ka = amb;
            kd = diff;
            ks = spec;
        }
        virtual HitRecord intersect(const Ray& ray);
    private:
        Eigen::Vector3d a1;
        Eigen::Vector3d b1;
        Eigen::Vector3d c1;
    };
}

#endif 