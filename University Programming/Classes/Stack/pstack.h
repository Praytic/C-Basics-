#ifndef PSTACK
#define PSTACK

#include <iostream>

using namespace std;

template <class Type>
class PStack
{
private:

    struct Element{
        Type value;
        Element* next;
        Element(Type value, Element* next) {
            this->value = value;
            this->next = nullptr;
        }
    };

    Element* head;
    int sizeOfQueue;

public:

    PQueue() : head(nullptr), sizeOfQueue(0){}

    bool empty(){
        return head == nullptr;
    }

    void push(Type value){
        sizeOfQueue++;
        head = new Element(value, head);
    }

    void get(){
        if (empty()) return;
        sizeOfQueue--;
        head = head->next;
    }

    void pop() {
        if (empty()) return;
        sizeOfStack--;
        head = head->next;
    }

    Type top(){
        if (empty()) return 0;
        return head->value;
    }

    ~PStack(){}
};

#endif

