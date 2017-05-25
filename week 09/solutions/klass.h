#ifndef _KLASS_H
#define _KLASS_H

class Klass {
    int hp;
    char* name;
    int strength;
    int intellect;
    int agility;
	
	void copy(Klass const&);
public:
    Klass(int, char const*, int, int, int);
	Klass();
	Klass(Klass const&);
	virtual ~Klass(); //Пробвайте да изтриете virtual и вижте, че ще има memory leak при Warrior
	Klass& operator=(Klass const&);

	// Декларираме си чисти виртуални функции, т.е. освобождаваме се от задължението да ги имплементираме
	// По този начин Klass става абстрактен клас и не можем да създаваме обекти от него (указатели и псевдоними са позволени)
    virtual void meleeAttack(Klass*) = 0;
    virtual void rangedAttack(Klass*) = 0;
    virtual void magicAttack(Klass*) = 0;

    void subtractHp(int);
    bool isAlive() const;

    int getStrength() const;
    int getIntellect() const;
    int getAgility() const;
	
	char const* getName() const;
};

#endif // _KLASS_H

