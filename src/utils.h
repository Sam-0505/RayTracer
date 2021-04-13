#pragma once
#define _USE_MATH_DEFINES

#include<math.h>
#include<limits>
#include<memory>
#include<stdlib.h>

#include "ray.h"
#include "vec3.h"

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
inline vec3 rand_small_vec()
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

