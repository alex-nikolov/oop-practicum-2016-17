#include <iostream>

#include "doge.h"
#include "cate.h"

using namespace std;

int main() {
	Cate garfield("Garfield", 10, "Penko", 20, 6);
	Doge rex("Rex", 2, "Gunther", 9001, "German shepherd");

	//Проверка на конструктора за копиране
	Cate g = garfield;
	g.setName("Gar");
	cout << g.getName() << endl << garfield.getName() << endl << endl;
	
	Doge r = rex;
	r.setName("R3x");
	cout << r.getName() << endl << rex.getName() << endl << endl;
	
	//Проверка на оператор =
	g = garfield;
	g.setName("Garry");
	cout << g.getName() << endl << garfield.getName() << endl << endl;
	
	r = rex;
	r.setName("Rexie");
	cout << r.getName() << endl << rex.getName() << endl << endl;
	Pet const& winner = cuterPet(garfield, rex);

	cout << "By far, the cuter pet is " << winner.getName();
}