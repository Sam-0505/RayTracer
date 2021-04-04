#pragma once
#define _USE_MATH_DEFINES

#include<math.h>
#include<limits>
#include<memory>

#include "ray.h"
#include "vec3.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const float infinity = std::numeric_limits<float>::infinity();
const float pi = M_PI;

inline float degtorad(float deg)
{
	return (deg * pi) / 180.0;
}

