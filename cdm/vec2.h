#pragma once
#include <tuple> // for std::tie
#include <cmath> // for std::sqrt

namespace cdm
{
	template <class T>
	class tvec2
	{
	public:
		union {
			struct {
				T x;
				T y;
			};

			struct {
				T u;
				T v;
			};
		};

		tvec2(): x(0), y(0) {}
		tvec2(T _v): x(_v), y(_v) {}
		tvec2(T _x, T _y): x(_x), y(_y) {}

		// Arithmetic operators
		tvec2 operator +  (const tvec2& other) { return tvec2( this->x + other.x, this->y + other.y ); }
		tvec2 operator -  (const tvec2& other) { return tvec2( this->x - other.x, this->y - other.y ); }
		tvec2 operator *  (const T scalar)     { return tvec2( this->x * scalar,  this->y * scalar  ); }
		tvec2 operator /  (const T scalar)     { return tvec2( this->x / scalar,  this->y / scalar  ); }

		// Compound assignment operators
		tvec2& operator += (const tvec2& other) { this->x += other.x; this->y += other.y; return *this; }
		tvec2& operator -= (const tvec2& other) { this->x -= other.x; this->y -= other.y; return *this; }
		tvec2& operator *= (const T scalar)     { this->x *= scalar;  this->y *= scalar;  return *this; }
		tvec2& operator /= (const T scalar)     { this->x /= scalar;  this->y /= scalar;  return *this; }

		// Relational operators
		bool operator == (const tvec2& other) { return this->x == other.x && this->y == other.y; }
		bool operator != (const tvec2& other) { return !(*this == other); }
		// (following comparisons expressed in lexigraphic order)
		bool operator <  (const tvec2& other) { return std::tie(this->x, this->y) < std::tie(other.x, other.y); }
		bool operator >  (const tvec2& other) { return other < *this; }
		bool operator <= (const tvec2& other) { return !(*this > other); }
		bool operator >= (const tvec2& other) { return !(*this > other); }

		// Indexing operator
		T& operator [] (size_t index) { return (&this->x)[index % 2]; }

		T dot_product(const tvec2& other) { return this->x * other.x + this->y * other.y; }
		T magnitude() { return std::sqrt(this->dot_product(*this)); }
		tvec2 normalize() { T m = this->magnitude(); return tvec2(this->x / m, this->y / m); }
	};

	typedef tvec2<float>  vec2;
	typedef tvec2<bool>   bvec2;
	typedef tvec2<int>    ivec2;
	typedef tvec2<uint>   uvec2;
	typedef tvec2<double> dvec2;
}