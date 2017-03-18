#include <iostream>
#include "d_array.h"

using namespace std;

int main() {
	DArray d;
	d.print();
	
	for (int i = 0; i < 15; i++)
		d.pushBack(i);
	d.print();
	
	d.setValue(7, 77);
	d.print();
	
	d.setValue(20, 20);
	d.print();
	
	d.deleteAt(7);
	d.print();
	
	d.popBack();
	d.print();
	
	// За да се уверите от смисъла на конструктора за копиране,
	// пробвайте да го премахнете и да видите какъв ще е резултатът от изпълнението
	// на долните редове (освен че първият елемент е сменен и в масивите на двата обекта,
	// забива, защото се опитваме да изтрием една и съща памет два пъти, което не е позволено).
	DArray dCopy = d;
	dCopy.setValue(0, 100);
	dCopy.print();
	d.print();
	
	// Сега за да се убедим от смисъла на деструктора, изтрийте го
	// и обградете целия main в един while(true), пуснете си съответното
	// средство за следене на процесите (за windows - task manager) и наблюдавайте паметта.
}