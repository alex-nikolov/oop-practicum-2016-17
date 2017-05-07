#include "cate.h"

// Първо извикваме конструктора по подразбиране на Pet
// Той се грижи за член данните на Pet
// Котката се грижи само за собствените си член данни
Cate::Cate() : Pet() {
	lives = 9;
}

// Конструкторът за копиране извиква конструктора за копиране на Pet
// Така всички член данни на Pet, които са част от Cate, се копират
// Остава ни само да копираме собствените член данни
Cate::Cate(Cate const& c) : Pet(c) {
	lives = c.lives;
}

// Отново котката се грижи само за собствените си член данни
// В случая не добавяме нова динамична памет, както при догето, така че нищо не правим
Cate::~Cate() {
}

// Сходно, викаме оператор = за Pet, който се грижи за присвояването на член данните
// на Cate, които са и член данни на Pet
// Работа на класа Cate е да се грижи за собствените си член данни
Cate& Cate::operator=(Cate const& c) {
	if (this != &c) {
		Pet::operator=(c);
		lives = c.lives;
	}

	return *this;
}

Cate::Cate(char const* _name, int _age, char const* _owner, int _cuteness, int _lives)
	: Pet(_name, _age, _owner, _cuteness), lives(_lives) {
}