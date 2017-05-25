#ifndef _RANGER_H
#define _RANGER_H

#include "klass.h"

class Ranger : public Klass {
public:
    Ranger(int, char const*, int, int, int);
	Ranger();

    void meleeAttack(Klass*);
    void rangedAttack(Klass*);
    void magicAttack(Klass*);
};

#endif // _RANGER_H
