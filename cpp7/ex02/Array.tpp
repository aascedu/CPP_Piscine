#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	this->_array = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
	for (unsigned int i = 0; i < this->_size; i++)	{
		new(&this->_array[i]) T();
	}
	
}

template<typename T>
Array<T>::Array(const Array<T> &ref)
{
	this->_size = ref.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		(this->_array[i]) = (ref._array[i]);
	}
}


template<typename T>
Array<T>	&Array<T>::operator=( const Array<T> &ref )
{
	delete[] this->_array;
	this->_size = ref.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++) {
		(this->_array[i]) = (ref._array[i]);
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[]( unsigned int i )
{
	if (i >= this->size())
		throw Array<T>::OutOfBoundsException();
	return (this->_array[i]);
}


template<typename T>
T	&Array<T>::operator[]( unsigned int i ) const
{
	if (i >= this->size())
		throw Array<T>::OutOfBoundsException();
	return (this->_array[i]);
}

template<typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index is out of bounds.");
}

template<typename T>
unsigned int	Array<T>::size( void ) const
{
	return (this->_size);
}
