#pragma once

#include "material.h"
#include "utils.h"

struct hit_values;
class lambertian :public material
{
	public:
		color albedo;

	public:
		lambertian(color a)
			:albedo(a)
		{}

		virtual bool scatter(ray& r, ray& scatter_ray, vec3& atten, hit_values& hit_val) const override;
};

bool lambertian::scatter(ray& r, ray& scatter_ray, vec3& atten, hit_values& hit_val) const 
{

	vec3 scatter_dir = hit_val.normal + unit(rand_small_vec());//Making the rand vector unit vector improves the probability distribution
	scatter_ray = ray(hit_val.point, scatter_dir);

	atten = albedo;
	return true;
}