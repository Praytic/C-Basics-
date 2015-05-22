#ifndef PSINGLELIST
#define PSINGLELIST

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in ("input.txt");

class ListException: public exception
{
public:
	ListException(const string & message = ""): exception(message.c_str()) {}
};

template <class item>
class PSingleList
{
protected:

	// ��������� �������� ������
	// ����������� ��������� �������� �
	// ���������� �� ���������
	struct Element{
		item value;
		Element* next;
		Element(item x) : value(x), next(0) {}
	};
	
	// ��������� ������ ������
	// ������ � ���� ��������� ��
	// ��������� �������, ������ ����������
	// � �����, ������������ ����� ��
	// ���� ������������ ���������
	Element *head;
	int sizeOfSL;
	string topString;
	Element *PFind(int index) {
		if ((index < 1) || (index > sizeOfSL)) {
			return NULL;
		}

		Element *cur = head;
		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}
		return cur;
	}

public:

	PSingleList() : head(0), sizeOfSL(0){}
	~PSingleList() {
		while(!PEmpty()) {
			PRemove(1);
		}
	}

	// ������� ��������� ������ �� �������
	bool PEmpty() {
		return head == 0;
	}

	// ������� ���������� ������ ������
	int PSize() {
		return sizeOfSL;
	}
	
	// ������� ���������� ������� � ������ ��������
	item PGet(int index) {
		if ((index < 1) || (index > sizeOfSL + 1)) {
			throw ListException("insert error");
		}

		Element *r = PFind(index);
		item i = r-> value;
		return i;
	}
	
	// ������� ��������� ������� � ������
	void PInsert(int index, item value){
		if ((index < 1) || (index > sizeOfSL + 1)) {
			return;
		}

		if (index == sizeOfSL + 1) 
			topString = value;
		Element *newPtr = new Element(value);
		sizeOfSL = PSize() + 1;

		if (index == 1) {
			newPtr->next = head;
			head = newPtr;
		}
		else {
			Element *prev = PFind(index - 1);
			newPtr->next = prev->next;
			prev->next = newPtr;
		}
	}

	// ������� ��������� ��� �������� �� ����� � ������
	void PRowInsert(){
		string s;
		Element *current = head;
		Element *previous;
		while (!in.eof()) {
			in >> s;
			topString = s;
			sizeOfSL = PSize() + 1;
			current = new Element(s);

			if (sizeOfSL == 1) {
				current->next = head;
				head = current;
				previous = current;
			}
			else {
				previous->next = current;
				previous = previous->next;
			}
		}
	}
	
	// ������� ������� ������� �� ������
	void PRemove(int index) {
		if ((index < 1) || (index > sizeOfSL + 1)) {
			return;
		}

		Element *cur;
		sizeOfSL--;
		if (index == 1) {
			cur = head;
			head = head->next;
		}
		else {
			Element *prev = PFind(index - 1);
			cur = prev->next;
			prev->next = cur->next;
		}
		cur->next = NULL;
		delete cur;
	}
	
	// ������� �������� ���� ������ � ������
	void PPrint() {
		for (Element *cur = head; cur != NULL; cur = cur-> next)
			cout << cur->value << ' ';
		cout << endl;
	}

	// ������� ������
	int problemSolver (PSingleList &custom) {
		int num = 0;
		//custom.PRemove(custom.PSize());
		for (int i = 1; i < custom.PSize(); i++) {
			if (topString == custom.PGet(i)) {
				num++;
				custom.PRemove(i);
			}
		}
		return num;
	}
};


#endif
