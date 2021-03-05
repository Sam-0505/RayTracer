// Ray_Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(ray r)
{
    vec3 unit_dir = unit(r.direction());
    float t = (unit_dir.x() + 1.0) * 0.5;//The x will vary from (-1,1) so map it to (0,1)
    color pcol = t * color(1, 1, 1) + (1 - t) * color(0, 0, 1);
    return pcol;

}
int main()
{
    //Image
    float aspect_ratio = 16.0 / 9.0;
    int img_height = 450;
    int img_width = static_cast<int>(img_height*aspect_ratio);
    
    //Camera
    float viewport_height = 2.0;
    float viewport_width = viewport_height * aspect_ratio;
    float focal_length = 1.0;

    point3 origin;
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    vec3 focal = vec3(0, 0, focal_length);
    point3 upper_left_corner = origin - (horizontal / 2) + (vertical / 2) - focal;

    std::cout << "P3\n" << img_width << "\t" << img_height << "\n" << 255<<"\n";
    for (float j = img_height - 1; j >= 0; j--)
    {
        for (float i = 0; i < img_width; i++)
        {
            float u = i / (img_width-1);
            float v=j / (img_height-1);
            ray r = ray(origin, upper_left_corner+u*horizontal-(1.0-v)*vertical);//starting from upper left corner send rays in a loo
            color pixel_col = ray_color(r);
            write_color(std::cout, pixel_col);
        }
    }
    std::cerr << "\nDone\n";
}