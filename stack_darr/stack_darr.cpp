// Ниже представлен программный код реализации стека на базе динамического массива.
// Необходимо было обеспечить работу следующих функций: push, pop, top, size, empty и реализовать расширение массива

#include <iostream>

template <class T>
class stack {
private:
	int arr_size = 5;
	T *arr = new T[arr_size];
	int i = -1;

public:
	stack() {}
	bool empty() {
		return i == -1;
	}
	void push(T el) {
		if (i < arr_size) {
			i += 1;
		}
		else {
			arr_size *= 2;
			T *temp = new T[arr_size];
			for (int j = 0; j <= i; j++) {
				temp[j] = arr[j];
			}
			arr = temp;
			i += 1;
		}
		arr[i] = el;
	}
	void pop() {
		if (!empty()) {
			i -= 1;
		}
		else {
			throw "error: empty stack";
			return;
		}
	}
	T top() {
		if (!empty()) {
			return arr[i];
		}
		else {
			throw "error: empty stack";
		}
	}
	size_t size() {
		return i + 1;
	}
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите количество элементов стека: ";
	unsigned int size;
	cin >> size;
	stack<int> s_arr;
	cout << endl << "(push) Введите " << size << " элементов последовательно." << endl;
	for (unsigned i = size; i > 0; i--) {
		int a;
		cout << i << "й элемент: ";
		cin >> a;

		s_arr.push(a);
	}

	cout << endl << "(top) Верхний элемент: " << s_arr.top() << endl;
	cout << "(size) Размер стека: " << s_arr.size() << " = " << size << endl;
	s_arr.pop();
	cout << "(pop) Верхний элемент после удаления: " << s_arr.top() << endl;
	cout << "Создадим временный стек и перенесем в него элементы старого стека.";
	stack <int> temp;
	for (unsigned int i = s_arr.size(); i > 0; i--) {
		cout << endl << "Удалили " << s_arr.top();
		temp.push(s_arr.top());
		s_arr.pop();
	}
	cout << endl << "(empty) Полностью очистили старый стек. Пуст ли он? [" << s_arr.empty() << "]." << endl;

	cout << "Проверим временный стек.";
	for (unsigned int i = temp.size(); i > 0; i--) {
		cout << endl << i << "й элемент: " << temp.top();
		temp.pop();
	}

	return 0;
}