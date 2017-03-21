#ifndef QUEUE_H_
#define QUEUE_H_

struct Node {
	double data;
	Node* next;
	
	Node(double d, Node* n) {
		data = d;
		next = n;
	}
};

class Queue {
	Node* front;
	Node* back;
	int size;
public:
	Queue();
	Queue(Queue const&);
	~Queue();
	
	void enqueue(double);
	void dequeue();
	int getSize() const;
	double& getFront();
	void print() const;
};

#endif