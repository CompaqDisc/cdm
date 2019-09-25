#pragma once
#include <tuple> // for std::tie
#include <cmath> // for std::sqrt

namespace cdm
{
	template <class T>
	class tvec3
	{
	public:
		union {
			struct {
				T x;
				T y;
				T z;
			};

			struct {
				T r;
				T g;
				T b;
			};
		};

		tvec3(): x(0), y(0), z(0) {}
		tvec3(T _v): x(_v), y(_v), z(_v) {}
		tvec3(T _x, T _y, T _z): x(_x), y(_y), z(_z) {}

		// Arithmetic operators
		tvec3 operator +  (const tvec3& other) { return tvec3( this->x + other.x, this->y + other.y, this->z + other.z ); }
		tvec3 operator -  (const tvec3& other) { return tvec3( this->x - other.x, this->y - other.y, this->z - other.z ); }
		tvec3 operator *  (const T scalar)     { return tvec3( this->x * scalar,  this->y * scalar,  this->z * scalar  ); }
		tvec3 operator /  (const T scalar)     { return tvec3( this->x / scalar,  this->y / scalar,  this->z / scalar  ); }

		// Compound assignment operators
		tvec3& operator += (const tvec3& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
		tvec3& operator -= (const tvec3& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }
		tvec3& operator *= (const T scalar)     { this->x *= scalar;  this->y *= scalar;  this->z *= scalar;  return *this; }
		tvec3& operator /= (const T scalar)     { this->x /= scalar;  this->y /= scalar;  this->z /= scalar;  return *this; }

		// Relational operators
		bool operator == (const tvec3& other) { return this->x == other.x && this->y == other.y && this->z == other.z; }
		bool operator != (const tvec3& other) { return !(*this == other); }
		// (following comparisons expressed in lexigraphic order)
		bool operator <  (const tvec3& other) { return std::tie(this->x, this->y, this->z) < std::tie(other.x, other.y, other.z); }
		bool operator >  (const tvec3& other) { return other < *this; }
		bool operator <= (const tvec3& other) { return !(*this > other); }
		bool operator >= (const tvec3& other) { return !(*this > other); }

		// Indexing operator
		T& operator [] (size_t index) { return (&this->x)[index % 3]; }

		T dot_product(const tvec3& other) { return this->x * other.x + this->y * other.y + this->z * other.z; }
		T magnitude() { return std::sqrt(this->dot_product(*this)); }
		tvec3 normalize() { T m = this->magnitude; return tvec3(this->x / m, this->y / m, this->z / m); }
		tvec3 cross_product(const tvec3& other)
		{
			return tvec3(
				this->y * other.z - this->z * other.y,
				this->z * other.x - this->x * other.z,
				this->x * other.y - this->y * other.x
			);
		}
	};

	typedef tvec3<float>  vec3;
	typedef tvec3<bool>   bvec3;
	typedef tvec3<int>    ivec3;
	typedef tvec3<uint>   uvec3;
	typedef tvec3<double> dvec3;
}