#include "Warrior.h"
#include <iostream>
#include <cstring>

void Warrior::meleeAttack(Klass* other) {
    other->subtractHp(3 * getStrength());
	std::cout << getName() << " swung his mighty sword at " << other->getName() << "." << std::endl;
}

void Warrior::magicAttack(Klass* other) {
    other->subtractHp(0.3 * getIntellect());
	std::cout << getName() << " mumbled some words at " << other->getName() << "." << std::endl;
}

void Warrior::rangedAttack(Klass* other) {
    other->subtractHp(getAgility());
	std::cout << getName() << " threw some sand at " << other->getName() << "." << std::endl;
}

Warrior::Warrior(int _hp, char const* _name, int _s, int _i, int _a, char const* _swordName) : Klass(_hp, _name, _s, _i, _a) {
	swordName = new char[strlen(_swordName) + 1];
	strcpy(swordName, _swordName);
}

Warrior::Warrior() : Klass() {
	swordName = NULL;
}

Warrior::Warrior(Warrior const& w) : Klass(w) {
	copy(w);
}

Warrior::~Warrior() {
	delete[] swordName;
}

Warrior& Warrior::operator=(Warrior const& w) {
	if (this != &w) {
		delete[] swordName;
		Klass::operator=(w);
		copy(w);
	}
	
	return *this;
}

void Warrior::copy(Warrior const& w) {
	swordName = new char[strlen(w.swordName) + 1];
	strcpy(swordName, w.swordName);
}