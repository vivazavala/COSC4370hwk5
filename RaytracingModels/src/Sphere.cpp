#include "Sphere.h"
#include <limits>


using namespace Raytracer148;
using namespace Eigen;
using namespace std;

HitRecord Sphere::intersect(const Ray& ray) {
    HitRecord result;
    result.t = -1;
    //////////////////////////////////////////////////////////
    double at = ray.direction.squaredNorm();
    double bt = 2 * ray.direction.dot(ray.origin - c);
    double ct = (ray.origin - c).squaredNorm() - r * r;
    double discriminant = bt * bt - 4 * at * ct;

    if (discriminant < numeric_limits<double>::epsilon()) 
    { 
        return result; 
    }

    double t0 = (-bt - sqrt(discriminant)) / (2 * at);
    double t1 = (-bt + sqrt(discriminant)) / (2 * at);
    ////////////////////////////////////////////////////////////////////////////
    if (t1 < numeric_limits<double>::epsilon()) 
    {
        return result; 
    }
    if (t0 > numeric_limits<double>::epsilon()) 
    { 
        result.t = t0; 
    }
    else 
    {
        result.t = t1;
    }
    ////////////////////////////////////////////////////////////////////////////
    result.position = ray.origin + result.t * ray.direction;
    result.normal = (result.position - c).normalized();
    result.sh = this;

    return result;
}