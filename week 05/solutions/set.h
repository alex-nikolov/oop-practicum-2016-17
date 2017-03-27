#ifndef _SET_H
#define _SET_H

#include <iostream>

class Set
{
	double* array;
	int size;
	int capacity;
	
	void resize();
	void copy(Set const&);
	bool full() const;
	void deleteIndex(int);
public:
	Set();
	Set(Set const&);
	~Set();
	Set& operator=(Set const&);
	
	bool contains(double) const;

	bool operator==(Set const&) const;

	Set operator+(double) const;
	Set& operator+=(double);

	Set operator+(Set const&) const;
	Set& operator+=(Set const&);
	
	Set operator^(Set const&) const;
	Set& operator^=(Set const&);

	Set operator-(double) const;
	Set& operator-=(double);
	
	Set operator-(Set const&) const;
	Set& operator-=(Set const&);
	
	friend std::ostream& operator<<(std::ostream&, Set const&);
};



#endif