
#include <iostream>
#include <fstream>
#include "queue.h"
#ifdef WIN32
#include <Windows.h>
#endif

using namespace std;

int main()
{
#ifdef WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
		Queue<int> q1;
		Queue<int> q2 = { 1, 2, 3, 4 };
		Queue<int> q3{ q2 };
		cout << q2 << endl;
		cout << q3 << endl;
		q1.swap(q3);
		cout << q1 << endl;
		cout << boolalpha << q3.empty();
		cout << q1.size() << endl;
		q3.push(5);
		cout << q3 << endl;
		ofstream output{ "Queue<T>.bin" };
		output << q3;
		Queue<int> q4;
		ifstream input{ "Queue<T>.bin" };
		input >> q4;
		cout << (q4 == q3) << endl;
		cout << q4.front() << endl;
		cout << q4.back() << endl;
		q4.pop();
		cout << q4 << endl;
		q4.front() = 6;
}

