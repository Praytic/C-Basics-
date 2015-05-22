#ifndef PQUEUE
#define PQUEUE

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PQueue
{
private:

	// ������, ������� �������� ������� �������
	struct Element{
		string value;
		Element* next;
		Element(string value) {
			this->value = value;
			this->next = nullptr;
		}
	};
	// ��������� �� ������ � ����� �������
	Element* head;
	Element* tail;

public:

	PQueue() : head(nullptr), tail(nullptr){}
	~PQueue(){}
	
	// ������� �������� �� ������� �������
	bool PEmpty(){
		return head == nullptr;
	}
	
	// ������� ������ �������� �� �������
	string PGet() {
		if (PEmpty()) return "";

		Element *t = head;
		string i = t->value;
		head = t->next;
		if (head == NULL) tail = NULL;
		delete t;
		return i;
	}

	// ������� ���������� �������� � �������
	void PPut(string value){
		Element *t = tail;
		tail = new Element(value);
		if (!head) head = tail;
		else t->next = tail;
	}

};

#endif
