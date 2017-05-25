#include <iostream>
#include <ctime>
#include <cstdlib>

#include "mage.h"
#include "warrior.h"
#include "ranger.h"

using namespace std;

typedef void (Klass::*attackFuncs)(Klass*);

void battle(Klass* first, Klass* second) {
   Klass* participants[2] = { first, second };
   srand(time(NULL));
   int playerIndex, funcIndex;
   
   // Създаваме си масив от указатели към член функции на Klass със сигнатурата
   // void foo(Klass*) (точно каквато е сигнатурата на функциите ни за атака)
   attackFuncs funcArr[3] = { &Klass::meleeAttack, &Klass::magicAttack, &Klass::rangedAttack };

   while (first->isAlive() && second->isAlive()) {
        playerIndex = rand() % 2;
		funcIndex = rand() % 3;
        (participants[playerIndex]->*funcArr[funcIndex])(participants[1 - playerIndex]);
   }
   
   Klass* winner = first->isAlive() ? first : second;
   
   cout << endl << winner->getName() << " stands victorious. " << endl;
}

int main() {
	Klass* w = new Warrior(1000, "Aragorn", 100, 6, 40, "Mecho");
    Klass* m = new Mage(1000, "Gandalf", 5, 100, 40);
    Klass* r = new Ranger(1000, "Legolas", 30, 30, 100);
	
	battle(w, m);

	delete w;
	delete m;
	delete r;
}

