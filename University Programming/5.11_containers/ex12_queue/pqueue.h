#ifndef PQUEUE
#define PQUEUE

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PQueue
{
private:
	// Данные, которые содержит элемент очереди
	struct Element{
		string value;
		Element* next;
		Element(string value) {
			this->value = value;
			this->next = nullptr;
		}
	};
	// Указатели на начало и конец очереди
	Element* head;
	Element* tail;

public:

	PQueue() : head(nullptr), tail(nullptr){}
	~PQueue(){}
	
	// Метод проверки на пустоту очереди
	bool PEmpty(){
		return head == nullptr;
	}
	
	// Метод взятия элемента из очереди
	string PGet() {
		if (PEmpty()) return "";
		// Принцип работы метода такойже, как у стека,
		// но в очереди нужно еще обнулить указатель tail
		Element *t = head;
		string i = t->value;
		head = t->next;
		if (head == NULL) tail = NULL;
		delete t;
		return i;
	}

	// Метод добавления элемента в очередь
	void PPut(string value){
		// Добавление происходит в конец очереди, так как
		// в начале находится первый добавленный элемент
		// Для того, чтобы добавить элемент, нужно переместить
		// указатель tail на новый, и если это не первый добавленный
		// элемент, то указатель next будет указывать на следующий
		// в очереди элемент, иначе next будет инициализирован
		// nullptr, а head будет указывать на этот единственный элемент
		Element *t = tail;
		tail = new Element(value);
		if (!head) head = tail;
		else t->next = tail;
	}

};

#endif
