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
	
	// Функция проверки на пустоту очереди
	bool PEmpty(){
		return head == nullptr;
	}
	
	// Функция взятия элемента из очереди
	string PGet() {
		if (PEmpty()) return "";

		Element *t = head;
		string i = t->value;
		head = t->next;
		if (head == NULL) tail = NULL;
		delete t;
		return i;
	}

	// Функция добавления элемента в очередь
	void PPut(string value){
		Element *t = tail;
		tail = new Element(value);
		if (!head) head = tail;
		else t->next = tail;
	}

};

#endif
