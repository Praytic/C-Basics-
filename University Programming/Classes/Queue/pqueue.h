#ifndef PQUEUE
#define PQUEUE

#include <iostream>

using namespace std;

template <class Type>
class PQueue
{
private:

    struct Element{
        Type value;
        Element* next;
        Element(Type value) {
            this->value = value;
            this->next = nullptr;
        }
    };

    Element* head;
    Element* tail;
    int sizeOfQueue;

public:

    PQueue() : head(nullptr),tail(nullptr), sizeOfQueue(0){}

    bool empty(){
        return head == nullptr;
    }

    void put(Type value){
        sizeOfQueue++;
        Element* ptr = tail;
        tail = new Element(value);

        if (head == nullptr)
            head = tail;
        else
            ptr->next = tail;
    }

    void get(){
        if (empty()) return /*0*/;
        sizeOfQueue--;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
    }

    Type show(){
        if (empty()) return 0;
        return head->value;
    }

    ~PQueue(){}
};

#endif

