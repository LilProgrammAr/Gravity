#pragma once
#ifndef CLASS_VECTOR2_H
#define CLASS_VECTOR2_H

#include <SFML/Graphics.hpp>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////

template<typename T> class vector2;

using vector2i = vector2<int>;
using vector2f = vector2<float>;
using vector2d = vector2<double>;

template<typename T>
class vector2
{
public:
	vector2();
	vector2(T x, T y);
	~vector2() = default;

	////////////////////////////////////////////////////////////////////////////
	///Returns normalised version of this vector
	///(Vector with same direction but with length 1)
	////////////////////////////////////////////////////////////////////////////
	vector2 normalized() const;

	////////////////////////////////////////////////////////////////////////////
	///Returns sum of two vectors
	///Example:
	///vector2<int> a(5, 7), b(6, 8);
	///auto c = a + b // c.x == 11, c.y == 15 
	////////////////////////////////////////////////////////////////////////////
	template<typename A> vector2 operator+(const vector2<A>& rhs) const;

	////////////////////////////////////////////////////////////////////////////
	///Returns difference of two vectors
	///Example:
	///vector2<int> a(5, 7), b(6, 6);
	///auto c = a - b // c.x == -1, c.y == 1
	////////////////////////////////////////////////////////////////////////////
	template<typename A> vector2 operator-(const vector2<A>& rhs) const;

	////////////////////////////////////////////////////////////////////////////
	///Returns a vector, multiplied by some scalar
	///Example:
	///vector2<int> a(5, 7);
	///auto c = a * 5 // c.x == 25, c.y == 35
	////////////////////////////////////////////////////////////////////////////
	template<typename A> vector2 operator*(const A& rhs) const;

	////////////////////////////////////////////////////////////////////////////
	///Returns a vector, divided by some scalar
	///Example:
	///vector2<int> a(8, 16);
	///auto c = a / 4 // c.x == 2, c.y == 4
	////////////////////////////////////////////////////////////////////////////
	template<typename A> vector2 operator/(const A& rhs) const;


	operator sf::Vector2f();
	operator sf::Vector2i();


	T x, y;
};

template<typename T>
inline vector2<T>::vector2() : x(0), y(0) {}

template<typename T>
inline vector2<T>::vector2(T x, T y) : x(x), y(y) {}

template<typename T>
inline vector2<T> vector2<T>::normalized() const
{
	auto length = dynamic_cast<double>(sqrt(x * x + y * y));
	return vector2(x / length, y / length);
}

template<typename T>
inline vector2<T>::operator sf::Vector2f()
{
	return sf::Vector2f(dynamic_cast<float>(this->x), 
						dynamic_cast<float>(this->y));
}

template<typename T>
inline vector2<T>::operator sf::Vector2i()
{
	return sf::Vector2i(dynamic_cast<int>(this->x),
						dynamic_cast<int>(this->y));
}

template<typename T>
template<typename A>
inline vector2<T> vector2<T>::operator+(const vector2<A>& rhs) const
{
	return vector2(this->x + rhs.x, this->y + rhs.y);
}

template<typename T>
template<typename A>
inline vector2<T> vector2<T>::operator-(const vector2<A>& rhs) const
{
	return vector2(this->x - rhs.x, this->y - rhs.y);
}

template<typename T>
template<typename A>
inline vector2<T> vector2<T>::operator*(const A & rhs) const
{
	return vector2(this->x * rhs, this->y * rhs);
}

template<typename T>
template<typename A>
inline vector2<T> vector2<T>::operator/(const A & rhs) const
{
	return vector2(this->x / rhs, this->y / rhs);
}

#endif //CLASS_VECTOR2_H