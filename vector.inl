#include "vector.h"

template <typename T> 
T SetValue();

template<>
int SetValue()
{
	int value = 0;
	std::cin >> value;
	return value;
}

template<>
float SetValue()
{
	float value = 0.0;
	std::cin >> value;
	return value;
}

template<>
double SetValue()
{
	double value = 0.0;
	std::cin >> value;
	return value;
}

template<>
std::complex<float> SetValue()
{
	float real = 0.0, imag = 0.0;
	std::cout << "real = ";
	std::cin >> real;
	std::cout << "\timag = ";
	std::cin >> imag;
	return std::complex<float>(real, imag);
}

template<>
std::complex<double> SetValue()
{
	double real = 0.0, imag = 0.0;
	std::cout << "real = ";
	std::cin >> real;
	std::cout << "\timag = ";
	std::cin >> imag;
	return std::complex<double>(real, imag);
}

template <typename T>
Vector<T>::Vector(const int size)
{
	data = std::vector<T>(size);
}

template <typename T> 
T& Vector<T>::operator[](const int index)
{
	if (index < 0 || (unsigned)index >= data.size())
		throw InvalidIndex();
	return data[index];
}

template <typename T> 
std::istream& operator>> (std::istream& in, Vector<T>& v)
{
	auto i = 0;
	for (auto& value : v.data)
	{
		std::cout << "[" << i++ << "] = ";
		value = SetValue<T>();
	}
	return in;
}

template <typename T> 
std::ostream& operator<< (std::ostream& out, const Vector<T>& v)
{
	out << "[  ";
	for (const auto& value : v.data)
	{
		out << value << "  ";
	}
	out << "]";
	return out;
}

template <typename T> 
Vector<T> Vector<T>::operator+(const Vector<T>& v)
{
	if (data.size() != v.data.size())
		throw DimensionInequality();
	Vector res(*this);
	auto iter = v.data.begin();
	for (auto& value : res.data)
		value += *(iter++);
	return res;
}

template <typename T> 
Vector<T> Vector<T>::operator-(const Vector<T>& v)
{
	if (data.size() != v.data.size())
		throw DimensionInequality();
	Vector res(*this);
	auto iter = v.data.cbegin();
	for (auto& value : res.data)
		value -= *(iter++);
	return res;
}

template <typename T> 
T Vector<T>::operator*(const Vector<T>& v)
{
	if (data.size() != v.data.size())
		throw DimensionInequality();
	T res = 0;
	for (auto iterA = data.cbegin(), iterB = v.data.cbegin(); iterA < data.cend() || iterB < v.data.cend(); ++iterA, ++iterB)
		res += (*iterA) * (*iterB);
	return res;
}

template <typename T> 
Vector<T> Vector<T>::operator*(const T value)
{
	Vector res(*this);
	for (auto& v : res.data)
		v *= value;
	return res;
}

template <typename T> 
Vector<T> operator* (const T value, Vector<T> v)
{
	return (v * value);
}

template <typename T> 
Vector<T> Vector<T>::operator/ (const T value)
{
	if (value == (T)0)
		throw ZeroDividing();
	Vector res(*this);
	for (auto& v : res.data)
		v /= value;
	return res;
}

template <typename T> 
bool Vector<T>::operator==(const Vector<T>& v) const
{
	if (data.size() != v.data.size())
		throw DimensionInequality();
	return (data == v.data);
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& v) const
{
	return !(*this == v);
}