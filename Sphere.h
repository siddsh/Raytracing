#pragma once
#include"vec3.cpp"
#include <cstdlib> 
#include <cstdio> 
#include <fstream> 
#include <cassert> 
#include <algorithm>


typedef Vec3<float> Vec3f;
/**Sphere class with attributes like center radius reflectivity and transparency and its natural colour*/
class Sphere
{
public:
    Vec3f center;                           /// position of the sphere 
    float radius, radius2;                  /// sphere radius and radius^2 
    Vec3f surfaceColor, emissionColor;      /// surface color and emission (light) 
    float transparency, reflection;         /// surface transparency and reflectivity 
    Sphere(
        const Vec3f& c,
        const float& r,
        const Vec3f& sc,
        const float& refl = 0,
        const float& transp = 0,
        const Vec3f& ec = 0) :
        center(c), radius(r), radius2(r* r), surfaceColor(sc), emissionColor(ec),
        transparency(transp), reflection(refl)
    { /* empty */
    }
    /**Finds the intersection point of the raydir and the spheres*/
    bool intersect(const Vec3f& rayorig, const Vec3f& raydir, float& t0, float& t1) const
    {
        Vec3f l = center - rayorig;
        float tca = l.dot(raydir);
        if (tca < 0) return false;
        float d2 = l.dot(l) - tca * tca;
        if (d2 > radius2) return false;
        float thc = sqrt(radius2 - d2);
        t0 = tca - thc;
        t1 = tca + thc;

        return true;
    }
};