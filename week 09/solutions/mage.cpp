#include "Mage.h"
#include <iostream>

void Mage::meleeAttack(Klass* other) {
    other->subtractHp(0.3 * getStrength());
	std::cout << getName() << " hit " << other->getName() << " with his staff." << std::endl; 
}

void Mage::magicAttack(Klass* other) {
    other->subtractHp(3 * getIntellect());
	std::cout << getName() << " casted a fireball at " << other->getName() << "." << std::endl;
}

void Mage::rangedAttack(Klass* other) {
    other->subtractHp(getAgility());
	std::cout << getName() << " threw some rocks at " << other->getName() << "." << std::endl;
}

Mage::Mage(int _hp, char const* _name, int _s, int _i, int _a) : Klass(_hp, _name, _s, _i, _a) {}

Mage::Mage() : Klass() {}
