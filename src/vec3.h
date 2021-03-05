#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
	public:
		float e[3];

	public:
		vec3()
			: e{ 0,0,0 }
		{}

		vec3(float e0, float e1, float e2)
			:e{ e0,e1,e2 }
		{}

		float x() const { return e[0]; }
		float y() const { return e[1]; }
		float z() const { return e[2]; }

		float operator[](int i) const { return e[i]; }
		float& operator[](int i) { return e[i]; }

		vec3& operator-() 
		{ 
			e[0] = -e[0]; 
			e[1] = -e[1];
			e[2] = -e[2];
			return *this;//Returns the reference to the current object
		}

		vec3& operator+=(const vec3& v)
		{
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		vec3& operator-=(const vec3& v)
		{
			e[0] -= v.e[0];
			e[1] -= v.e[1];
			e[2] -= v.e[2];
			return *this;
		}

		vec3& operator*=(const float x)
		{
			e[0] *= x;
			e[1] *= x;
			e[2] *= x;
			return *this;
		}

		vec3& operator/=(const float x)
		{
			e[0] *= 1 / x;
			e[1] *= 1 / x;
			e[2] *= 1 / x;
			return *this;
		}

		float length_sqr() const
		{
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}

		float length() const
		{
			float sqrLen = length_sqr();
			return std::sqrt(sqrLen);
		}

};

//Creating aliases
using point = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream &out, vec3 &v)
{
	return out << v.e[0] << "\t" << v.e[1] << "\t" << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const float& t, const vec3& u)
{
	return vec3(u.e[0] * t, u.e[1] * t, u.e[2] * t);
}

inline vec3 operator*(const vec3 &u, const float &t)
{
	return t * u;
}

inline vec3 operator/(const vec3 &u, const float &t)
{
	return (1 / t) * u;
}

inline float dot(const vec3& u, const vec3& v)
{
	return (u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2]);
}

inline vec3 cross(const vec3& u, const vec3& v)
{
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], u.e[2] * v.e[0] - u.e[0] * v.e[2], u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit(vec3 u)
{
	return u / u.length();
}

#endif