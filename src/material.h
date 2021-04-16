#pragma once

#include "ray.h"
#include "utils.h"
#include "object.h"

struct hit_values;

class material
{
	public:
		virtual bool scatter(ray& r, ray& scatter_ray, vec3& atten, hit_values& hit_val) const = 0;
};