#ifndef ARR_H_
#define ARR_H_

template <typename T>
class Arr {
    int rows, cols;
    T** matrix;

    void erase();
    void copy(Arr<T> const&);

public:
    Arr();
    Arr(Arr<T> const&);
    ~Arr();
    Arr<T>& operator=(Arr<T> const&);

    Arr(int, int);
    T* operator[](int);
	
	int getRows() const;
	int getCols() const;

	void resizeRows();
	void resizeCols();

	// Обърнете внимание на допълнителния template с различно име на параметъра
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, Arr<U> const&);
};

template <typename T>
Arr<T>::Arr() {
    rows = cols = 0;
    matrix = NULL;
}

template <typename T>
Arr<T>::Arr(Arr<T> const& a) {
    copy(a);
}

template <typename T>
Arr<T>::~Arr() {
    erase();
}

template <typename T>
Arr<T>& Arr<T>::operator=(Arr<T> const& a) {
    if (this != &a) {
        erase();
        copy(a);
    }

    return *this;
}

template <typename T>
int Arr<T>::getCols() const {
	return cols;
}

template <typename T>
int Arr<T>::getRows() const {
	return rows;
}

template <typename T>
void Arr<T>::copy(Arr<T> const& a) {
    rows = a.rows;
    cols = a.cols;

	// Създаваме "контейнер", в който ще съхраняваме указатели към редовете
    matrix = new T*[rows];

    for (int i = 0; i < rows; i++) {
		// Създаваме i-тия ред
        matrix[i] = new T[cols];

		// Запълваме i-тия ред
        for (int j = 0; j < cols; j++)
            matrix[i][j] = a.matrix[i][j];
    }
}

template <typename T>
void Arr<T>::erase() {
	// Трием в обратния ред на създаването - първо трием редовете и след това
	// "контейнера", който ги съхранява
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;
}


template <typename T>
Arr<T>::Arr(int r, int c) {
    rows = r;
    cols = c;

    matrix = new T*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new T[cols];
}

template <typename T>
T* Arr<T>::operator[](int index) {
	// Когато напишем a[5][3] = 6 например първо се прилага a[5],
	// резултатът е указател към T (масив), който вече си има операция [],
	// т.е. ние трябва да се погрижим само да върнем 5тия ред.
    return matrix[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Arr<T> const& a) {
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++)
            os << a.matrix[i][j] << " ";
        os << std::endl;
    }

    return os << std::endl;
}

// Функция, която удвоява размера на всеки от редовете (т.е. увеличава колоните)
template <typename T>
void Arr<T>::resizeCols() {
	int newCols = cols * 2;

	for (int i = 0; i < rows; i++) {
		// Копираме i-тия ред.
		T* copyRow = new T[newCols];
		
		for (int j = 0; j < cols; j++)
			copyRow[j] = matrix[i][j];
		// Допълваме с нули новосъздадената част
		for (int j = cols; j < newCols; j++)
			copyRow[j] = 0;
		
		// Освобождатаме паметта от текущия ред и насочваме указателя към новозаделения ред
		delete[] matrix[i];
		matrix[i] = copyRow;
	}

	cols = newCols;
}

// Функция, която увеличава броя на редовете
template <typename T>
void Arr<T>::resizeRows() {
	int newRows = rows * 2;
	
	// За разлика от горната функция, тук ще ни трябва по-голям контейнер
	T** newMatrix = new T*[newRows];
	
	// Насочваме указателите към текущите редове. В момента имаме два достъпа до тях -
	// чрез newMatrix и чрез matrix
	for (int i = 0; i < rows; i++)
		newMatrix[i] = matrix[i];

	// Създаваме нови редове за втората половина от newMatrix
	for (int i = rows; i < newRows; i++) {
		newMatrix[i] = new T[newRows];
		
		for (int j = 0; j < cols; j++)
			newMatrix[i][j] = 0;
	}
	
	// Трием само стария контейнер и насочваме указателя към новия,
	// не сме извършили никакви промени по самите редове
	delete[] matrix;
	matrix = newMatrix;

	rows = newRows;
}

#endif