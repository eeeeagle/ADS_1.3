#pragma once
#include "vectorException.h"
#include <cmath>
#include <complex>
#include <vector>

template <typename T>
class Vector
{
	std::vector<T> data;
public:
	Vector(const int size = 2);
	T& operator [] (const int index);
	template<class T> friend std::istream& operator>> (std::istream& in, Vector<T>& v);
	template<class T> friend std::ostream& operator<< (std::ostream& out, const Vector<T>& v);
	Vector operator + (const Vector<T>& v);
	Vector operator - (const Vector<T>& v);
	T operator * (const Vector<T>& v);
	template<class T> friend Vector<T> operator* (const T value, Vector<T> v);
	Vector operator * (const T value);
	Vector operator / (const T value);
	bool operator == (const Vector<T>& v) const;
	bool operator != (const Vector<T>& v) const;
};