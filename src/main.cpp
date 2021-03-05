// Ray_Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"
#include "color.h"

int main()
{
    int img_height = 480;
    int img_width = 640;

    std::cout << "P3\n" << img_width << "\t" << img_height << "\n" << 255<<"\n";
    for (float j = img_height - 1; j >= 0; j--)
    {
        for (float i = 0; i < img_width; i++)
        {
            float r = i / (img_width - 1);
            float g = j / (img_height - 1);
            float b = 0.25;
            color pixel = color(r, g, b);
            write_color(std::cout, pixel);

            /*
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            std::cout << ir << "\t" << ig << "\t" << ib << "\n";
            */
        }
    }
    std::cerr << "\nDone\n";
}