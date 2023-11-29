#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::const_iterator		const_iterator;
		typename std::stack<T>::container_type::iterator		begin();
		typename std::stack<T>::container_type::const_iterator	cbegin() const;
		typename std::stack<T>::container_type::iterator		end();
		typename std::stack<T>::container_type::const_iterator	cend() const;
		typename std::stack<T>::container_type::iterator		rend();
		typename std::stack<T>::container_type::const_iterator	crend() const;
		typename std::stack<T>::container_type::iterator		rbegin();
		typename std::stack<T>::container_type::const_iterator	crbegin() const;
};

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin() const
{
	return (std::stack<T>::c.cbegin());
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend() const
{
	return (std::stack<T>::c.cend());
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::crend() const
{
	return (std::stack<T>::c.crend());
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::crbegin() const
{
	return (std::stack<T>::c.crbegin());
}


#endif