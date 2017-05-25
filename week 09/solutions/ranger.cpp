#include "Ranger.h"
#include <iostream>

void Ranger::meleeAttack(Klass* other) {
    other->subtractHp(getStrength());
	std::cout << getName() << " hit " << other->getName() << " with his quiver." << std::endl;
}

void Ranger::magicAttack(Klass* other) {
    other->subtractHp(0.3 * getIntellect());
	std::cout << getName() << " mumbled some words towards " << other->getName() << "." << std::endl;
}

void Ranger::rangedAttack(Klass* other) {
    other->subtractHp(3 * getAgility());
	std::cout << getName() << " shot an arrow at " << other->getName() << " (it struck his knee)." << std::endl;
}

Ranger::Ranger(int _hp, char const* _name, int _s, int _i, int _a) : Klass(_hp, _name, _s, _i, _a) {}

Ranger::Ranger() : Klass() {}