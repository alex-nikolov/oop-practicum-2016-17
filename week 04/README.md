# Week 04

## Опашка

Да се реализира клас `Queue`, представляващ опашка от числа с плаваща запетая, реализирана чрез свързано представяне. За целта да се реализират следните методи:

  - `Queue()` - конструктор по подразбиране
  - `Queue(Queue const&)` - конструктор за копиране
  - `~Queue()` - деструктор
  - `void enqueue(double)` - метод, с който се добавя число към опашката
  - `void dequeue()` - метод, с който се изтрива число от опашката
  - `double& getFront()` - метод, който връща референция към първия елемент в опашката
  - `int getSize() const` - метод, който връща големината на опашката
  - `void print() const` - метод, който отпечатва на екрана съдържанието на опашката