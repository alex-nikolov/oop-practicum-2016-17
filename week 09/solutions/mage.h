#ifndef _MAGE_H
#define _MAGE_H

#include "klass.h"

class Mage : public Klass {
public:
    Mage(int, char const*, int, int, int);
	Mage();

    void meleeAttack(Klass*);
    void rangedAttack(Klass*);
    void magicAttack(Klass*);
};

#endif // _MAGE_H
