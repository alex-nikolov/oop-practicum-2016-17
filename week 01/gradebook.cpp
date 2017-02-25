#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 50;

struct Student {
    char name[31];
    double grade;

    Student() {
        name[0] = '\0';
        grade = 2;
    }

    Student(const char* _name, double _grade) {
        strncpy(name, _name, 30);
        name[30] = '\0';
        grade = _grade;
    }
};

struct Gradebook {
    Student students[MAX_SIZE];
    int currentSize;

    Gradebook() {
        currentSize = 0;
    }

    void addStudent(Student s) {
        if (currentSize < MAX_SIZE)
            students[currentSize++] = s;
    }

    // Приемаме, че искаме да преханем само първия студент с дадено име
    void removeStudent(const char* name) {
        for (int i = 0; i < currentSize; i++) {
            if (!strcmp(students[i].name, name)) {
                for (int j = i; j < currentSize - 1; j++)
                    students[j] = students[j + 1];

                currentSize--;
                break;
            }
        }
    }

    void sort() {
        for (int i = 0; i < currentSize - 1; i++) {
            for (int j = i + 1; j < currentSize; j++) {
                if (strcmp(students[i].name, students[j].name) == 1)
                    swap(students[i], students[j]);
            }
        }
    }

    void displayByGrade(double grade) {
        for (int i = 0; i < currentSize; i++)
            if (students[i].grade >= grade)
                cout << "Name: " << students[i].name
                     << ", grade: " << students[i].grade << endl;
    }
};

int main() {
    Student ivan("Ivan", 4.5);
    Student pesho("Pesho", 5);
    Student georgi("Georgi", 4.75);

    Gradebook book;
    book.addStudent(ivan);
    book.addStudent(pesho);
    book.addStudent(georgi);

    book.displayByGrade(4.6);
    cout << endl;

    book.sort();
    book.displayByGrade(4.6);
    cout << endl;

    book.removeStudent("Ivan");
    book.displayByGrade(0);
}
