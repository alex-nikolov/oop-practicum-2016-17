#include "queue.h"
#include <iostream>

int main() {
	Queue q;
	
	for (int i = 0; i < 10; i++)
		q.enqueue(i);
	q.print();
	
	for (int i = 0; i < 15; i++)
		q.dequeue();
	q.print();
	
	for (int i = 0; i < 10; i++)
		q.enqueue(i);
	q.print();
	
	Queue r = q;
	r.enqueue(1167);
	r.print();
	q.print();
	
	Queue t;
	Queue tt = t;
	t.print();
	
	q.getFront() += 6;
	q.print();
}