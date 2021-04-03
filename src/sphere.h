#pragma

#include<iostream>
#include "vec3.h"
#include "hittable.h"
#include "ray.h"

class sphere : public hittable
{
	public:
		point3 center;
		float radius;

		virtual bool on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const override;
};

bool sphere::on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const
{
    // When solving a sphere equation with a ray, the final equation is a quadratic eqn:(t^2)(b⋅b)+2tb⋅(A−C)+(A−C)⋅(A−C)−r2=0
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float half_b = dot(r.direction(), oc);
    float c = dot(oc, oc) - (radius * radius);
    float small_d = half_b * half_b - a * c;//This is discriminent, if positive the ray hits the sphere otherwise not

    if (small_d < 0.0)
        return false;
    float root = (-half_b - sqrt(small_d)) / a;
    if (root<tmin || root>tmax)
    {
        root = (-half_b + sqrt(small_d)) / a;
        if (root<tmin || root>tmax)
            return false;
    }

    hit_val.t = root;
    hit_val.point = r.at(root);
    hit_val.normal = unit(hit_val.point - center);
    return true;
}