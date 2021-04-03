#ifndef HITTABLE_H
#define HITTABLE_H

#include<iostream>
#include "./vec3.h"
#include "./ray.h"

struct hit_values
{
	float t;
	point3 point;
	vec3 normal;
};

class hittable
{
	public:
		virtual bool on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const = 0;
};

#endif // !HITTABLE_H
