// Ray_Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "obj_list.h"
#include "object.h"
#include "utils.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"

using std::make_shared;
using std::shared_ptr;

color ray_color(ray r,obj_list& scene,int bounce);
//float hit_sphere(const point3& center, float radius, const ray& r);

color ray_color(ray r,obj_list& scene,int bounce)
{
    hit_values hit_val;
    if (bounce <= 0)
    {
        std::cerr << "Bounces finished\n";
        return color(1, 0, 0);
    }
    if(scene.on_hit(0.001, infinity, r, hit_val))
    {
        //point3 target = hit_val.point + hit_val.normal + unit(rand_small_vec());
        ray scatter_ray;
        color atten;
        if(hit_val.mat->scatter(r,scatter_ray,atten,hit_val))
            return atten * (ray_color(scatter_ray, scene, bounce - 1));
        return color(0, 0, 0);
        //color pcol = 0.5 * (hit_val.normal + 1);//clustured the values of normal from (-1,1) to (0,1)
        //return pcol;
    }
    vec3 unit_dir = unit(r.direction());
    float i = (unit_dir.y() + 1.0) * 0.5;//The x will vary from (-1,1) so map it to (0,1)
    color pcol = (1 - i) * color(1, 1, 1) + i * color(0.5, 0.5, 1);
    return pcol;
}

int main()
{
    //Image
    float aspect_ratio = 16.0 / 9.0;
    int img_height = 360;
    int img_width = static_cast<int>(img_height*aspect_ratio);
    
    //Camera
    float viewport_height = 2.0;
    float viewport_width = viewport_height * aspect_ratio;
    float focal_length = 1.0;

    //Set the viewport
    point3 origin;
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    vec3 focal = vec3(0, 0, focal_length);
    point3 upper_left_corner = origin - (horizontal / 2) + (vertical / 2) - focal;

    //Set the scene
    //Add the objects in the scene
    obj_list scene;

    shared_ptr<lambertian> mat = make_shared<lambertian>(color(1, 1, 0));

    scene.add(make_shared<sphere>(point3(0, 0, -1), 0.5,mat));
    scene.add(make_shared<sphere>(point3(0, -100.5, -1), 100,mat));

    //Camera 
    camera cam = camera();

    //Rendering settings
    int samples = 10;
    int max_bounces=10;

    std::cout << "P3\n" << img_width << "\t" << img_height << "\n" << 255<<"\n";
    for (float j = img_height - 1; j >= 0; j--)
    {
        for (float i = 0; i < img_width; i++)
        {
            color pixel_col=color(0,0,0);
            for (int k = 0; k < samples; k++)
            {
                float u = (i+rand_f())/ (img_width - 1);
                float v = (j+rand_f())/ (img_height - 1);
                ray r = cam.get_ray(u, v);
                pixel_col += ray_color(r, scene,max_bounces);
            }
            write_color(std::cout, pixel_col,samples);
        }
    }
    std::cerr << "\nDone\n";
}