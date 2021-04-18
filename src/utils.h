#pragma once
#define _USE_MATH_DEFINES

//This header file contains multiple utility fucntions used throughout the program 
//These functions are used multiple times in different sections of the code

#include<math.h>
#include<limits>
#include<memory>
#include<stdlib.h>

#include "ray.h"
#include "vec3.h"
#include "object.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const float infinity = std::numeric_limits<float>::infinity();
const float pi =static_cast<float>(M_PI);

inline float degtorad(float deg)
{
	float rad = (deg * pi) / 180.0f;
}

inline float rand_f()
{

	float f= rand();
	float n = f / (RAND_MAX);
	return n;
}

inline float rand_f(float min, float max)
{
	return min + ((max - min) * rand_f());
}

inline float clamp(float k,float x, float y)//K is clamped between x and y
{
	if (k < x)
		return x;
	else if (k > y)
		return y;
	else
		return k;
}

inline vec3 rand_vec()
{
	return vec3(rand_f(), rand_f(), rand_f());
}

inline vec3 rand_vec(float min,float max)
{
	return vec3(rand_f(min,max), rand_f(min,max), rand_f(min,max));
}

//Get a vector with length less than 1
inline vec3 rand_in_unit_sphere()
{
	while (true)
	{
		vec3 v = rand_vec(-1, 1);//These can or cannot be less than length 1
		if (v.length() > 1)
			continue;
		else
			return v;
	}
}

inline bool check_small_vac(vec3 v) 
{
	float k = (float)1e-8;
	return (fabs(v[0]) < k) && (fabs(v[1]) < k) && (fabs(v[2]) < k);
}

inline ray reflect(ray& r,hit_values& hit_val)
{
	vec3 dir = unit(r.direction());
	vec3 perpendicular = dot(dir, hit_val.normal) * hit_val.normal;
	vec3 parallel = dir - perpendicular;
	vec3 reflect_dir = parallel - perpendicular;
	return ray(hit_val.point, reflect_dir);
}