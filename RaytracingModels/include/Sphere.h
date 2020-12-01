#ifndef SPHERE_H
#define SPHERE_H
#include "Shape.h"

namespace Raytracer148 {
	class Sphere : public Shape {
	////////////////////////////////////////////////////////////////////////////
	public:
		Sphere(Eigen::Vector3d& center, float radius, Eigen::Vector3d& ambient, Eigen::Vector3d& diffuser, Eigen::Vector3d& specular) :
			c(center), r(radius) {
			ka = ambient;
			kd = diffuser;
			ks = specular;
		}
		virtual HitRecord intersect(const Ray& ray);
	////////////////////////////////////////////////////////////////////////////
	private:
		Eigen::Vector3d c;
		double r;
	};
}

#endif