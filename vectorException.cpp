#include "vectorException.h"

VectorException::VectorException(const char* msg)
{
	int size = strlen(msg) + 1;
	error = new char[size];
	strncpy_s(error, size, msg, size - 1);
}

VectorException::~VectorException()
{
	delete[] error;
}

char* VectorException::getError() const
{
	return error;
}

InvalidValue::InvalidValue()
	: VectorException("Invalid value")
{};

InvalidIndex::InvalidIndex()
	: VectorException("Invalid index")
{};

DimensionInequality::DimensionInequality()
	: VectorException("Inequality of dimensions of vectors")
{};

ZeroDividing::ZeroDividing()
	: VectorException("Dividing to 0 is impossible")
{};

EpsInvalidRange::EpsInvalidRange()
	: VectorException("eps must be in range 0 < eps < 1")
{};