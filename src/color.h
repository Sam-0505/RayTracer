#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "./vec3.h"
#include "utils.h"

void write_color(std::ostream &out,color &pixel_col, int samples)
{
	//If number of samples is x, x number color values were added using fractional ray values
	//Now we average out the values which gives anti-aliasing effect
	color pixCol = (pixel_col /(1.0f*samples));
	pixCol = pixCol.sqrt();
	/*std::cerr << static_cast<int>(256 * clamp(pixCol.x(), 0.0f, 0.9999f)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.y(), 0.0f, 0.9999f)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.z(), 0.0f, 0.9999f)) << "\n";*/

	out << static_cast<int>(256 * clamp(pixCol.x(),0.0f,0.99f)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.y(),0.0f,0.99f)) << "\t"
		<< static_cast<int>(256 * clamp(pixCol.z(),0.0f,0.99f))<<"\n";
}
#endif
