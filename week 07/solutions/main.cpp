#include <iostream>
#include "array_2d.h"

using namespace std;

int main() {
	Arr<double> a(5, 3);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = i + j;

	a.resizeCols();
	a.resizeRows();

	cout << a;
}