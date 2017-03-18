#ifndef D_ARRAY_H_
#define D_ARRAY_H_

class DArray {
	double* arr;
	int size;
	int capacity;

	void resize();
public:
	DArray();
	DArray(DArray const&);
	~DArray();
	
	void setValue(int, double);
	void pushBack(double);
	void popBack();
	void deleteAt(int);

	double getValue(int) const;
	int getSize() const;
	void print() const;
};

#endif