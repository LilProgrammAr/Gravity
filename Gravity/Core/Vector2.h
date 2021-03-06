#pragma once
#ifndef CLASS_VECTOR2_H
#define CLASS_VECTOR2_H

#include <SFML/Graphics.hpp>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////

namespace core {
	template<typename T> class Vector2;

	using Vector2i = Vector2<int>;
	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;

	template<typename T>
	class Vector2
	{
	public:
		Vector2();
		Vector2(T x, T y);
		~Vector2() = default;

		////////////////////////////////////////////////////////////////////////////
		///Returns normalised version of this vector
		///(Vector with same direction but with length 1)
		////////////////////////////////////////////////////////////////////////////
		Vector2 normalized() const;
		T length() const noexcept;

		////////////////////////////////////////////////////////////////////////////
		///Returns sum of two vectors
		///Example:
		///vector2i a(5, 7), b(6, 8);
		///auto c = a + b // c.x == 11, c.y == 15 
		////////////////////////////////////////////////////////////////////////////
		template<typename A> Vector2 operator+(const Vector2<A>& rhs) const;

		////////////////////////////////////////////////////////////////////////////
		///Returns difference of two vectors
		///Example:
		///vector2i a(5, 7), b(6, 6);
		///auto c = a - b // c.x == -1, c.y == 1
		////////////////////////////////////////////////////////////////////////////
		template<typename A> Vector2 operator-(const Vector2<A>& rhs) const;

		////////////////////////////////////////////////////////////////////////////
		///Returns a vector, multiplied by some scalar
		///Example:
		///vector2i a(5, 7);
		///auto c = a * 5 // c.x == 25, c.y == 35
		////////////////////////////////////////////////////////////////////////////
		template<typename A> Vector2 operator*(const A& rhs) const;

		////////////////////////////////////////////////////////////////////////////
		///Returns a vector, divided by some scalar
		///Example:
		///vector2i a(8, 16);
		///auto c = a / 4 // c.x == 2, c.y == 4
		////////////////////////////////////////////////////////////////////////////
		template<typename A> Vector2 operator/(const A& rhs) const;


		 operator sf::Vector2i();
		 operator sf::Vector2f();
		 operator sf::Vector2u();


		T x, y;
	};

	template<typename T>
	inline Vector2<T>::Vector2() : x(0), y(0) {}

	template<typename T>
	inline Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

	template<typename T>
	inline Vector2<T> Vector2<T>::normalized() const
	{
		auto length = length();
		return Vector2<T>(x / length, y / length);
	}

	template<typename T>
	inline T Vector2<T>::length() const noexcept
	{
		return sqrt(x*x + y*y);
	}

	template<typename T>
	template<typename A>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<A>& rhs) const
	{
		return Vector2(this->x + rhs.x, this->y + rhs.y);
	}

	template<typename T>
	template<typename A>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<A>& rhs) const
	{
		return Vector2(this->x - rhs.x, this->y - rhs.y);
	}

	template<typename T>
	template<typename A>
	inline Vector2<T> Vector2<T>::operator*(const A & rhs) const
	{
		return Vector2(this->x * rhs, this->y * rhs);
	}

	template<typename T>
	template<typename A>
	inline Vector2<T> Vector2<T>::operator/(const A & rhs) const
	{
		return Vector2(this->x / rhs, this->y / rhs);
	}

	template<typename T>
	inline Vector2<T>::operator sf::Vector2i()
	{
		return sf::Vector2i(static_cast<int>(this->x),
							  static_cast<int>(this->y));
	}
	template<typename T>
	inline Vector2<T>::operator sf::Vector2f()
	{
		return sf::Vector2f(static_cast<float>(this->x),
							  static_cast<float>(this->y));
	}
	template<typename T>
	inline Vector2<T>::operator sf::Vector2u()
	{
		return sf::Vector2u(static_cast<unsigned int>(this->x),
							  static_cast<unsigned int>(this->y));
	}
}
#endif //CLASS_VECTOR2_H