#ifndef _WARRIOR_H
#define _WARRIOR_H

#include "klass.h"

class Warrior : public Klass {
	char* swordName;
	
	void copy(Warrior const&);
public:
    Warrior(int, char const*, int, int, int, char const*);
	Warrior();
	Warrior(Warrior const&);
	~Warrior();
	Warrior& operator=(Warrior const&);

    void meleeAttack(Klass*);
    void rangedAttack(Klass*);
    void magicAttack(Klass*);
};

#endif // _Mage_H
