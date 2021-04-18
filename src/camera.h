#pragma once

#include "vec3.h"
#include "ray.h"
class camera
{
	public:
		point3 origin;
		vec3 horizontal;
		vec3 vertical;
		vec3 focal;
		vec3 upper_left_corner;

	public:
		camera()
		{
			float aspect_ratio = 16.0f / 9.0f;
			float viewport_height = 2.0;
			float viewport_width = viewport_height * aspect_ratio;
			float focal_length = 1.0;

			origin=point3(0,0,0);
			horizontal = vec3(viewport_width, 0, 0);
			vertical = vec3(0, viewport_height, 0);
			focal = vec3(0, 0, focal_length);
			upper_left_corner = origin - (horizontal / 2) + (vertical / 2) - focal;
		}

		ray get_ray(float u,float v)
		{
			ray r = ray(origin, upper_left_corner + u * horizontal - (1.0 - v) * vertical);
			return r;
		}
			
};