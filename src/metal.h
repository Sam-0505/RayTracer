#pragma once

#include "material.h"
#include "utils.h"
#include "object.h"


struct hit_values;
class metal :public material
{
public:
	color albedo;
	float fuzz;

public:
	metal(color a,float f)
		:albedo(a),
		fuzz(f < 1 ? f : 1)
	{}

	virtual bool scatter(ray& r, ray& scatter_ray, color& atten, hit_values& hit_val) const override;
};

bool metal::scatter(ray& r, ray& scatter_ray, color& atten, hit_values& hit_val) const
{
	scatter_ray = reflect(r,hit_val);//here the scattering not random, instead there is ideal reflection
	scatter_ray.dir = scatter_ray.direction() + fuzz * rand_in_unit_sphere();
	atten = albedo;
	return (dot(scatter_ray.direction(),hit_val.normal)>0);
}
