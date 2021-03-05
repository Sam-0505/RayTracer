#pragma once
#define RAY_H

#include <iostream>
#include "vec3.h"

class ray
{
	public:
		point3 orig;
		vec3 dir;

	public:
		ray() {}
		ray(point3 origin, vec3 direction)
			:orig(origin), dir(direction)
		{}

		point3 origin() const{ return orig; }
		vec3 direction() const{ return dir; }

		point3 at(float t) const{ return (orig + t * dir); }
};