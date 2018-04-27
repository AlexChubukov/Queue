
#ifndef queue_h
#define queue_h
#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
struct ForwardList {
	ForwardList *next;
	T data;
};

template <typename T>
class Queue {
	ForwardList<T> *begin, *end;
public:
	Queue();
	Queue(std::initializer_list<T> list);
	Queue(const Queue& q);
	auto swap(Queue& q) -> void;
	auto operator=(const Queue<T>& q);
	auto empty() -> bool;
	auto size()->size_t;
	auto push(T value) -> void;                // Добавление в конец очереди        
	auto pop() -> void;                  // Удалить первый в очереди элемент
	auto front()->T&;                  // Обратиться к первому элементу очереди
	auto back()->T&;                   // Обратиться к последнему элементу очереди
	bool operator==(const Queue& q);
	friend auto operator<<(std::ostream& out, Queue<T>& q)->std::ostream&{
		if (q.empty()) {
			stream << "Очередь пуста" << endl;
			return stream;
		}
		ForwardList<T> *p = q.get_begin();
		for (; p != q.get_end();) {
			stream << p->data << "|";
			p = p->next;
		}
		stream << p->data << endl;
		return stream;
	}
	friend auto operator >> (std::istream& stream, Queue<T>& q)->std::istream&{
		cout << "Введите число в очередь: ";
		T value;
		stream >> value;
		q.push(value);
		return stream;
	}
	//template <typename T1> friend auto operator<<(std::ostream&, const Queue<T1>&)->std::ostream&;
	//template <typename T1> friend auto operator>>(istream&, Queue<T1>&)->istream&;
	~Queue();
	ForwardList<T>* get_begin();
	ForwardList<T>* get_end();

};



template<typename T>
Queue<T>::Queue()
{
	begin = end= nullptr;
}

template<typename T>
Queue<T>::Queue(std::initializer_list<T> list)
{
	for (auto& item : list) {
		push(item);
	}
}

template<typename T>
Queue<T>::Queue(const Queue & q)
{
	ForwardList<T> *p = q.begin;
	begin = end = nullptr;
	while (p != nullptr) {
		push(p->data);
		p =p->next;
	}
}

template<typename T>
auto Queue<T>::swap(Queue & q) -> void
{
	Queue<T> temp{ q };
	q = *this;
	*this = temp;
}

template<typename T>
auto Queue<T>::operator=(const Queue<T> & q)
{
	while (begin != nullptr) {
		ForwardList<T> *node_copy = begin->next;
		delete begin;
		begin = node_copy;
	}
	ForwardList<T> *p = q.begin;
	begin = end = nullptr;
	while (p != nullptr) {
		push(p->data);
		p = p->next;
	}
}

template<typename T>
auto Queue<T>::empty() -> bool
{
	if (begin == nullptr)
		return true;
	return false;
}

template<typename T>
auto Queue<T>::size() -> size_t
{
	ForwardList<T> *p = begin;
	size_t i=0;
	while (p != nullptr) {
		i++;
		p = p->next;
	}
	return i;
}

template<typename T>
auto Queue<T>::push(T value) -> void
{
	ForwardList<T> *p = begin;
	if (p == nullptr) {
		end=begin= new ForwardList<T>{ nullptr,value };
		return;
	}
	while (p->next != nullptr) {
		p = p->next;
	}
	end = p->next = new ForwardList<T>{ nullptr,value };
}

template<typename T>
auto Queue<T>::pop() -> void
{
	ForwardList<T> *temp = begin;
	begin = begin->next;
	delete temp;
}

template<typename T>
auto Queue<T>::front() -> T &
{
	return begin->data;
}

template<typename T>
auto Queue<T>::back() -> T &
{
	return end->data;
}

template<typename T>
bool Queue<T>::operator==(const Queue & q)
{
	Queue temp{ q };
	if (this->size() == temp.size()) {
		ForwardList<T> *temp1 = q.begin;
		ForwardList<T> *temp2 = begin;
		while (temp1 != nullptr) {
			if (temp1->data != temp2->data) {
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}
	return false;
}

template<typename T>
Queue<T>::~Queue()
{
	while (begin != nullptr)
	{
		ForwardList<T> *node_copy = begin->next;
		delete begin;
		begin = node_copy;
	}
}

template<typename T>
ForwardList<T>* Queue<T>::get_begin() {
	return begin;
}
template<typename T>
ForwardList<T>* Queue<T>::get_end() {
	return end;
}

#endif


