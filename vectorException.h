#pragma once
#include <iostream>

class VectorException
{
	char* error;
public:
	VectorException(const char* str);
	~VectorException();
	char* getError() const;
};

class InvalidValue : public VectorException
{
public:
	InvalidValue();
};

class InvalidIndex : public VectorException
{
public:
	InvalidIndex();
};

class DimensionInequality  : public VectorException
{
public:
	DimensionInequality();
};

class ZeroDividing : public VectorException
{
public:
	ZeroDividing();
};

class EpsInvalidRange : public VectorException
{
public:
	EpsInvalidRange();
};