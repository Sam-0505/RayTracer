#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "./vec3.h"

void write_color(std::ostream &out,color &pixCol)
{
	out << static_cast<int>(255.999 * pixCol.x()) << "\t"
		<< static_cast<int>(255.999 * pixCol.y()) << "\t"
		<< static_cast<int>(255.999 * pixCol.z())<<"\n";
}
#endif
