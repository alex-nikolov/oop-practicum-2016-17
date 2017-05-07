#include "pet.h"
#include <cstring>

Pet::Pet() {
	name = owner = NULL;
	age = 1;
	cuteness = 100;
}

void Pet::copy(Pet const& p) {
	age = p.age;
	cuteness = p.cuteness;

	name = new char[strlen(p.name) + 1];
	owner = new char[strlen(p.owner) + 1];
	
	strcpy(name, p.name);
	strcpy(owner, p.owner);
}

Pet::Pet(char const* _name, int _age, char const* _owner, int _cuteness) {
	age = _age;
	cuteness = _cuteness;
	
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	
	owner = new char[strlen(_owner) + 1];
	strcpy(owner, _owner);
}

Pet::Pet(Pet const& p) {
	copy(p);
}

void Pet::erase() {
	delete[] name;
	delete[] owner;
}

Pet::~Pet() {
	erase();
}

Pet& Pet::operator=(Pet const& p) {
	if (this != &p)
	{
		erase();
		copy(p);
	}
	return *this;
}

int Pet::getCuteness() const {
	return cuteness;
}

char const* Pet::getName() const {
	return name;
}

void Pet::setName(char const* _name) {
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Pet const& cuterPet(Pet const& first, Pet const& second) {
	if (first.getCuteness() >= second.getCuteness())
		return first;
	return second;
}