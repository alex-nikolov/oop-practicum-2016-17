#include "queue.h"
#include <iostream>

Queue::Queue() {
	front = back = NULL;
	size = 0;
}

Queue::Queue(Queue const& q) {
	front = back = NULL;
	Node* current = q.front;
	
	while (current) {
		enqueue(current->data);
		current = current->next;
	}
}

Queue::~Queue() {
	while (size > 0)
		dequeue();
}

void Queue::enqueue(double newValue) {
	// Създаваме си нова клетка със съответните данни и next = NULL
	Node* newNode = new Node(newValue, NULL);
	
	// В случая, когато опашката ни е празна, трябва да насочим front
	// към новосъздадената клетка
	if (!front)
		front = newNode;
		
	// Когато опашкат не ни е празна, т.е. има валиден back,
	// пренасочваме next-ът на текущия последен елемент към новата кутия.
	if (back)
		back->next = newNode;

	// Новият последен елемент става новосъздадената кутия.
	back = newNode;
	size++;
}

void Queue::dequeue() {
	if (front) {
		// Пазим си още една връзка към първата кутийка (която ще трябва да изтрием)
		Node* toDelete = front;
		
		// Пренасочваме front към следващата кутия.
		front = front->next;
		
		// Изтриваме първата кутия.
		delete front;
		
		// Ако front стане невалиден, т.е. в опашката е имало един елемент,
		// би следвало да пренасочим и back към NULL, вместо да сочи към освободена памет.
		if (!front)
			back = NULL;

		size--;
	}
}

double& Queue::getFront() {
	return front->data;
}

int Queue::getSize() const {
	return size;
}

void Queue::print() const {
	Node* current = front;
	
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	
	std::cout << std::endl;
}