#pragma once

#include "material.h"
#include "utils.h"

class lambertian :public material
{
	public:
		color albedo;

	public:
		lambertian(color a)
			:albedo(a)
		{}

		virtual bool scatter(ray& r, ray& scatter_ray, color& atten, hit_values& hit_val) const override;
};

bool lambertian::scatter(ray& r, ray& scatter_ray, color& atten, hit_values& hit_val) const 
{

	vec3 scatter_dir = hit_val.normal + unit(rand_in_unit_sphere());//Making the rand vector unit vector improves the probability distribution
	if (check_small_vac(scatter_dir))
		scatter_dir = hit_val.normal;
	scatter_ray = ray(hit_val.point, scatter_dir);
	//std::cerr << "Me lambertion hu\n";
	atten = albedo;
	return true;
}