#pragma once

#include<iostream>
#include "./vec3.h"
#include "./ray.h"
#include "material.h"

struct hit_values
{
	float t;
	point3 point;
	vec3 normal;
	std::shared_ptr<material> mat;
	bool front_face;

	/*
	We want to set the normal opposite to direction of the ray hitting them
	So if the ray is hitting from outside, it will be the front face and the dot product of outward normal and ray will be negative=> opposite direction =>no change
	if the ray is hitting from inside, it will be the back face and the dot product of outward normal and ray will be positive => opposite direction =>no change
	*/

	inline void set_normal(const ray& r, vec3 out_normal)
	{
		front_face = dot(r.direction(), out_normal) < 0;
		normal = front_face ? out_normal : -out_normal;
	}
};

class object
{
	public:
		virtual bool on_hit(float tmin, float tmax, const ray& r, hit_values& hit_val) const = 0;
};