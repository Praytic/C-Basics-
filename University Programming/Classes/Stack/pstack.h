#ifndef PSTACK
#define PSTACK

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PStack
{
private:

    struct Element{
        string value;
        Element* next;
        Element(string value, Element* next) {
            this->value = value;
            this->next = next;
        }
    };

    Element* head;
    int sizeOfStack;

public:

    PStack() : head(nullptr), sizeOfStack(0){}

    bool empty(){
        return head == nullptr;
    }

    void push(string u){
        sizeOfStack++;
        head = new Element(u, head);
    }

    string pop() {
        if (empty()) return "";
        sizeOfStack--;
        Element *r = head;
		string i = r->value;
		head = r->next;
		delete r;
		return i;
    }

    string top(){
        if (empty()) return "";
        return head->value;
    }

    ~PStack(){}
};

#endif
