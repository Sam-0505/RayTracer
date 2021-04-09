#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "./vec3.h"
#include "utils.h"

void write_color(std::ostream &out,color &pixel_col, int samples)
{
	//If number of samples is x, x number color values were added using fractional ray values
	//Now we average out the values which gives anti-aliasing effect
	color pixCol = pixel_col /(1.0*samples);
	//std::cout << static_cast<int>(256 * clamp(pixCol.x(), 0, 0.99)) << "\t"
		//<< static_cast<int>(256 * clamp(pixCol.y(), 0, 0.99)) << "\t"
		//<< static_cast<int>(256 * clamp(pixCol.z(), 0, 0.99)) << "\n";

	out << static_cast<int>(256 * clamp(pixCol.x(),0,0.99)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.y(),0,0.99)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.z(),0,0.99))<<"\n";
}
#endif
