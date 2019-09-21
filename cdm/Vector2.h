#pragma once
#include <tuple> // for std::tie

namespace cdm
{
	template <class T>
	class Vector2
	{
	public:
		T x;
		T y;

		Vector2(): x(0), y(0) {}
		Vector2(T _x, T _y): x(_x), y(_y) {}

		// Arithmetic operators
		Vector2 operator +	(const Vector2& other)	{ return Vector2( this->x + other.x, this->y + other.y ); }
		Vector2 operator -	(const Vector2& other)	{ return Vector2( this->x - other.x, this->y - other.y ); }
		Vector2 operator *	(const T scalar)	{ return Vector2( this->x * scalar,  this->y * scalar  ); }
		Vector2 operator /	(const T scalar)	{ return Vector2( this->x / scalar,  this->y / scalar  ); }

		// Compound assignment operators
		Vector2 operator +=	(const Vector2& other)	{ return Vector2( this->x + other.x, this->y + other.y ); }
		Vector2 operator -=	(const Vector2& other)	{ return Vector2( this->x - other.x, this->y - other.y ); }
		Vector2 operator *=	(const T scalar)	{ return Vector2( this->x * scalar,  this->y * scalar  ); }
		Vector2 operator /=	(const T scalar)	{ return Vector2( this->x / scalar,  this->y / scalar  ); }

		// Relational operators
		bool operator == (const Vector2& other) { return this->x == other.x && this->y == other.y; }
		bool operator != (const Vector2& other) { return !(*this == other); }
		// (following comparisons expressed in lexigraphic order)
		bool operator <  (const Vector2& other) { return std::tie(this->x, other.y) < std::tie(this->x, other.y); }
		bool operator >  (const Vector2& other) { return other < *this; }
		bool operator <= (const Vector2& other) { return !(*this > other); }
		bool operator >= (const Vector2& other) { return !(*this > other); }
	};
}