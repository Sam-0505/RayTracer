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
	return rand() / (RAND_MAX);
}

inline float rand_f(float min, float max)
{
	return min + ((max - min) * rand_f());
}



