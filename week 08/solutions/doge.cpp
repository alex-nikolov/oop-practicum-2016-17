#include "doge.h"
#include <cstring>

// Първо извикваме конструктора по подразбиране на Pet
// Той се грижи за член данните на Pet
// Догето се грижи само за собствените си член данни
Doge::Doge() : Pet() {
	breed = NULL;
}

// Отново догето се грижи само за собствените си член данни
Doge::~Doge() {
	delete[] breed;
}

void Doge::copy(Doge const& d) {
	breed = new char[strlen(d.breed) + 1];
	strcpy(breed, d.breed);
}

// Конструкторът за копиране извиква конструктора за копиране на Pet
// Така всички член данни на Pet, които са част от Doge, се копират
// Остава ни само да копираме собствените член данни
Doge::Doge(Doge const& d) : Pet(d) {
	copy(d);
}

// Сходно, викаме оператор = за Pet, който се грижи за присвояването на член данните
// на Doge, които са и член данни на Pet
// Работа на класа Doge е да се грижи за собствените си член данни
Doge& Doge::operator=(Doge const& d) {
	if (this != &d) {
		delete[] breed;
		Pet::operator=(d);
		copy(d);
	}

	return *this;
}

Doge::Doge(char const* _name, int _age, char const* _owner, int _cuteness, char const* _breed)
	: Pet(_name, _age, _owner, _cuteness) {
	breed = new char[strlen(_breed) + 1];
	strcpy(breed, _breed);
}