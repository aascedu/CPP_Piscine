#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
}

template<typename T>
Array<T>::~Array()
{
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	new T[n];
}