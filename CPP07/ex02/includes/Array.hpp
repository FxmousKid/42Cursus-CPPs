/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:42:16 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 22:13:14 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array
{
public:
    Array() : _arr(0), _size(0) {}
    
    Array(unsigned int n) 
    {
        _arr = new T[n];
        _size = n;
    }
    
    Array(const Array& rhs)
    {
        _arr = new T[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = rhs._arr[i];
    }
    
    Array& operator=(const Array& rhs)
    {
        if (this != &rhs)
        {
            if (_arr)
                delete[] _arr;
            
            _arr = new T[rhs._size];
            _size = rhs._size;
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = rhs._arr[i];
        }
        return *this;
    }
    
    ~Array()
    {
        if (_arr)
            delete[] _arr;
    }
    
    T& operator[](unsigned int n)
    {
        if (n >= _size)
            throw OutOfBoundsIndexException();
        return _arr[n];
    }
    
    unsigned int size() const 
    {
        return _size;
    }
    
    class OutOfBoundsIndexException : public std::exception 
    {
    public:
        virtual const char* what() const throw()
        {
            return "Index is out of bounds";
        }
    };

private:
    T* _arr;
    unsigned int _size;
};
