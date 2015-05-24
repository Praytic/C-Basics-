#ifndef PSTACK
#define PSTACK

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PStack
{
private:
	// Информационное поле элемента стека, которое содержит
	// значение и указатель на следующий элемент
    struct Element{
        string value;
        Element* next;
		// Конструктор информационного поля элемента
        Element(string value, Element* next) {
            this->value = value;
            this->next = next;
        }
    };
	// Каждый экземпляр класса хранит указатель на последний
	// добавленный элемент и размер стека
    Element* head;
    int sizeOfStack;

public:
	// Конструктор, деструктор
    PStack() : head(nullptr), sizeOfStack(0){}
    ~PStack(){}
	// Метод проверки на пустоту
    bool empty(){
        return head == nullptr;
    }
	// Метод добавления элемента в стек
    void push(string u){
		// Увеличиваем размер стека на 1 и смещаем
		// указатель head на новый элемент
        sizeOfStack++;
        head = new Element(u, head);
    }
	// Метод взятия элемента из стека
    string pop() {
		// Если стек не пуст, то уменьшаем размер стека
		// и переприсваиваем указатель head предыдущему после
		// текущего верхнего элемента и возвращаем его значение
        if (empty()) return "";
        sizeOfStack--;
        Element *r = head;
		string i = r->value;
		head = r->next;
		delete r;
		return i;
    }
	// Метод возвращает верхний элемент стека без удаления
    string top(){
        if (empty()) return "";
        return head->value;
    }
};

#endif
