
#include <iostream>
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
	Queue<int> q4 = { 1, 2, 3, 4,5,8,9 };
	Queue<int> q3{ q2 };
	Queue<int> q5{q4};
	cout << q1;
	cout << q2;
	cout << q3;
	cout << q4;

	cout << q2.size() << endl;
	cout << q5;
	//q1 = q3;
	cout << q1;
	cout << "----------------------------" << endl;
	cout << q1;
	cout << q3;
	
	q1.swap(q3);
	cout << "----------------------------" << endl;
	cout << q1;
	cout << q3;
	cout << q1.size() << endl;
	cout << q3.size() << endl;
	cout << "----------------------------" << endl;
	cout << q4;
	//q4.pop();
	//q4.pop();
	cout << q4;
	//q2 == q4;
	cout << (q2 == q4) << endl;
	cout << (q5 == q4) << endl;

	Queue<int> q6;
	cout << q6;
	cin >> q6;
	cout << q6;
	return 0;
}

