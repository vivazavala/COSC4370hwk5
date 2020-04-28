#ifndef SPHERE_H
#define SPHERE_H
#include "Shape.h"

namespace Raytracer148 {
	class Sphere : public Shape {
	public:
		Sphere(Eigen::Vector3d& center, float radius, Eigen::Vector3d& amb, Eigen::Vector3d& diff, Eigen::Vector3d& spec) :
			c(center), r(radius) {
			ka = amb;
			kd = diff;
			ks = spec;
		}
		virtual HitRecord intersect(const Ray& ray);
	private:
		Eigen::Vector3d c;
		double r;
	};
}

#endif