#include "klass.h"
#include <cstring>
#include <algorithm>

Klass::Klass(int _hp, char const* _name, int s, int i, int a) {
    hp = _hp;
    strength = s;
    intellect = i;	
    agility = a;

    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Klass::subtractHp(int amount) {
    hp = std::max(hp - amount, 0);
}

int Klass::getStrength() const {
    return strength;
}

int Klass::getIntellect() const {
    return intellect;
}

int Klass::getAgility() const {
    return agility;
}

bool Klass::isAlive() const {
    return hp > 0;
}

char const* Klass::getName() const {
	return name;
}

Klass::Klass() {
	hp = strength = intellect = agility = 0;
	name = NULL;
}

Klass::~Klass() {
	delete[] name;
}

Klass::Klass(Klass const& k) {
	copy(k);
}

Klass& Klass::operator=(Klass const& k) {
	if (this != &k) {
		delete[] name;
		copy(k);
	}
	
	return *this;
}

void Klass::copy(Klass const& k) {
	strength = k.strength;
	intellect = k.intellect;
	agility = k.agility;
	hp = k.hp;

	name = new char[strlen(k.name) + 1];
	strcpy(name, k.name);
}
