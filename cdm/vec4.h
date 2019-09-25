#pragma once
#include <tuple> // for std::tie
#include <cmath> // for std::sqrt

namespace cdm
{
	template <class T>
	class tvec4
	{
	public:
		union {
			struct {
				T x;
				T y;
				T z;
				T w;
			};

			struct {
				T r;
				T g;
				T b;
				T a;
			};
		};

		tvec4(): x(0), y(0), z(0), w(1) {}
		tvec4(T _v): x(), y(), z() {}
		tvec4(T _x, T _y, T _z): x(_x), y(_y), z(_z), w(1) {}
		tvec4(T _x, T _y, T _z, T _w): x(_x), y(_y), z(_z), w(_w) {}

		// Arithmetic operators
		tvec4 operator +  (const tvec4& other) { return tvec4( this->x + other.x, this->y + other.y, this->z + other.z ); }
		tvec4 operator -  (const tvec4& other) { return tvec4( this->x - other.x, this->y - other.y, this->z - other.z ); }
		tvec4 operator *  (const T scalar)     { return tvec4( this->x * scalar,  this->y * scalar,  this->z * scalar  ); }
		tvec4 operator /  (const T scalar)     { return tvec4( this->x / scalar,  this->y / scalar,  this->z / scalar  ); }

		// Compound assignment operators
		tvec4& operator += (const tvec4& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
		tvec4& operator -= (const tvec4& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }
		tvec4& operator *= (const T scalar)     { this->x *= scalar;  this->y *= scalar;  this->z *= scalar;  return *this; }
		tvec4& operator /= (const T scalar)     { this->x /= scalar;  this->y /= scalar;  this->z /= scalar;  return *this; }

		// Relational operators
		bool operator == (const tvec4& other) { return this->x == other.x && this->y == other.y && this->z == other.z; }
		bool operator != (const tvec4& other) { return !(*this == other); }
		// (following comparisons expressed in lexigraphic order)
		bool operator <  (const tvec4& other) { return std::tie(this->x, this->y, this->z) < std::tie(other.x, other.y, other.z); }
		bool operator >  (const tvec4& other) { return other < *this; }
		bool operator <= (const tvec4& other) { return !(*this > other); }
		bool operator >= (const tvec4& other) { return !(*this > other); }

		// Indexing operator
		T& operator [] (size_t index) { return (&this->x)[index % 3]; }

		T dot_product(const tvec4& other) { return this->x * other.x + this->y * other.y + this->z * other.z; }
		T magnitude() { return std::sqrt(this->dot_product(*this)); }
		tvec4 normalize() { T m = this->magnitude; return tvec4(this->x / m, this->y / m, this->z / m); }
		tvec4 cross_product(const tvec4& other)
		{
			return tvec4(
				this->y * other.z - this->z * other.y,
				this->z * other.x - this->x * other.z,
				this->x * other.y - this->y * other.x
			);
		}
	};

	typedef tvec4<float>  vec4;
	typedef tvec4<bool>   bvec4;
	typedef tvec4<int>    ivec4;
	typedef tvec4<uint>   uvec4;
	typedef tvec4<double> dvec4;
}