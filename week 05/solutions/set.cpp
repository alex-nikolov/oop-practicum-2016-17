#include "set.h"

Set::Set() {
	array = new double[5];
	capacity = 5;
	size = 0;
}

// В конструктора за копиране създаваме самия обект, така че
// трябва само да копираме всичко от подавания.
Set::Set(Set const& rs) {
	copy(rs);
}

void Set::copy(Set const& rs) {
	capacity = rs.capacity;
	size = rs.size;
	array = new double[capacity];
	
	for (int i = 0; i < size; i++)
		array[i] = rs.array[i];
}

Set::~Set() {
	delete[] array;
}

void Set::resize() {
	capacity *= 1.5;
	double* newArray = new double[capacity];
	
	for (int i = 0; i < size; i++)
		newArray[i] = array[i];
		
	delete[] array;
	array = newArray;
}

Set& Set::operator=(Set const& rs) {
	// Проверка за присвояване от вида x = x.
	if (this != &rs) {
		// Освобождаваме динамичната памет.
		delete[] array;
		
		// Копираме от подадения обект.
		copy(rs);
	}

	return *this;
}

bool Set::operator==(Set const& rs) const {
	if (rs.size != size)
		return false;

	for (int i = 0; i < rs.size; i++)
		if (!contains(rs.array[i]))
			return false;

	return true;
}

bool Set::contains(double value) const {
	for (int i = 0; i < size; i++)
		if (array[i] == value)
			return true;
	
	return false;
}

bool Set::full() const {
	return size == capacity;
}

Set& Set::operator+=(double value) {
	if (!contains(value)) {
		if (full())
			resize();
		
		array[size++] = value;
	}
	
	return *this;
}

Set& Set::operator+=(Set const& rs) {
	for (int i = 0; i < rs.size; i++)
		// Тук използваме += за Set и double.
		*this += rs.array[i];

	return *this;
}

Set Set::operator+(double value) const {
	Set temp = *this;
	return temp += value;
}

Set Set::operator+(Set const& rs) const {
	Set unionSet = *this;
	return unionSet += rs;
}

void Set::deleteIndex(int indexToDelete) {
	for (int i = indexToDelete; i < size - 1; i++)
		array[i] = array[i + 1];
	
	size--;
}

Set& Set::operator-=(double value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value)
			deleteIndex(i);
	}
	
	return *this;
}

Set& Set::operator-=(Set const& rs) {
	for (int i = 0; i < rs.size; i++)
		*this -= rs.array[i];

	return *this;
}

Set Set::operator-(double value) const {
	Set temp = *this;
	return temp -= value;
}

Set Set::operator-(Set const& rs) const {
	Set complement = *this;
	return complement -= rs;
}

Set& Set::operator^=(Set const& rs) {
	for (int i = size - 1; i >= 0; i--)
		if (!rs.contains(array[i]))
			deleteIndex(i);
	
	return *this;
}

Set Set::operator^(Set const& rs) const {
	Set intersection = *this;
	return intersection ^= rs;
}

std::ostream& operator<<(std::ostream& os, Set const& s) {
	os << "{ ";
	for (int i = 0; i < s.size; i++)
		os << s.array[i] << " ";

	return os << "}" << std::endl;
}