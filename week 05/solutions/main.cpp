#include <iostream>
#include "set.h"

using namespace std;

int main() {
	Set a, b;

	for (int times = 0; times < 1; times++)
		for (int i = 0; i < 5; i++)
			a += i;

	for (int i = 3; i < 7; i++)
		b += i;

	cout << a << endl;

	Set _union = a + b;
	cout << _union << a << b << endl;

	a += b;
	cout << a << b << endl;

	Set __union = a + 5;
	cout << __union << endl;

	__union -= 3;
	cout << __union << a << endl;

	__union -= a;
	cout << __union << endl;

	Set dif = a - b;
	cout << a << b << dif << endl;

	Set diff = a - 5;
	cout << a << diff << endl;

	Set inter = a ^ b;
	cout << a << b << inter << endl;

	a ^= b;
	cout << a << endl;

	cout << (a == a) << endl;

	Set copyA = a;
	cout << (copyA == a) << endl;

	copyA += 100;
	cout << (copyA == a) << endl;
}