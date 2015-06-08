#ifndef PSINGLELIST
#define PSINGLELIST

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in ("input.txt");

// Класс исключения, который выдает сообщение
// об ошибки при вызове
class ListException: public exception
{
public:
	ListException(const string & message = ""): exception(message.c_str()) {}
};

// Класс является шаблонным
template <class item>
class PSingleList
{
protected:

	// Структура элемента списка описывается
	// значением элемента и указателем на следующий
	struct Element{
		item value;
		Element* next;
		Element(item x) : value(x), next(0) {}
	};
	
	// Остальные данные класса хранят в себе указатель на
	// начальный элемент, размер контейнера, значение верхнего
	// элемента списка и метод, производящий поиск по
	// всем содержащимся элементам
	Element *head;
	int sizeOfSL;
	item topElement;
	// Метод возвращает элемент списка под нужным индексом
	Element *PFind(int index) {
		if ((index < 1) || (index > sizeOfSL)) {
			return NULL;
		}
		// В начале указатель устанавливается на head,
		// затем смещаем указатель до нужного индекса
		Element *cur = head;
		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}
		return cur;
	}

public:
	// Конструктор и деструктор
	PSingleList() : head(0), sizeOfSL(0){}
	~PSingleList() {
		while(!PEmpty()) {
			PRemove(1);
		}
	}

	// Метод проверяет список на пустоту
	bool PEmpty() {
		return head == 0;
	}

	// Метод возвращает размер списка
	int PSize() {
		return sizeOfSL;
	}
	
	// Метод возвращает элемент с нужным индексом
	item PGet(int index) {
		if ((index < 1) || (index > sizeOfSL + 1)) {
			throw ListException("PGet error");
		}
		// Для нахождения элемент с нужным индексом
		// запускается метод PFind
		Element *r = PFind(index);
		item i = r-> value;
		return i;
	}
	
	// Метод добавляет элемент в список
	void PInsert(int index, item value){
		if ((index < 1) || (index > sizeOfSL + 1)) {
			return;
		}
		// Обновление верхнего элемента
		if (index == sizeOfSL + 1) 
			topElement = value;
		Element *newPtr = new Element(value);
		sizeOfSL = PSize() + 1;
		// Если список пуст, то указатель добавляемого
		// элемента будет указаывать на nullptr, так как
		// head инициализирован nullptr, а указателю head
		// присваивается этот новый элемент
		if (index == 1) {
			newPtr->next = head;
			head = newPtr;
		}
		// Если же список не пуст, то мы должны найти
		// элемент, после которого стоит вставляемый элемент
		// и скопировать его указатель нашему новому
		// элементу, в то время как его указатель установить
		// на наш новый элемент
		else {
			Element *prev = PFind(index - 1);
			newPtr->next = prev->next;
			prev->next = newPtr;
		}
	}

	// Метод добавляет все элементы из файла в список
	void PRowInsert(){
		item s;
		Element *current = head;
		Element *previous;
		// Проводим те же действия, что и с методом PInsert,
		// только считываем мы подряд, поэтому нам не нужно
		// использовать поиск по индексу, так как мы
		// будем сохрнанять значение предыдущего элемента
		while (!in.eof()) {
			in >> s;
			topElement = s;
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
	
	// Метод удаляет элемент из списка
	void PRemove(int index) {
		if ((index < 1) || (index > sizeOfSL + 1)) {
			return;
		}
		// При удалении элемента мы переприсваиваем указатель
		// предыдущего элемента на следующий за удаленным
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
	// Функция удаляет все элементы списка, которые равны topElement
	int PRowRemove() {
		// Для двух исключений кол-во удаленных элементов
		// будет равно 0, и ничего не нужно удалять
		if(sizeOfSL == 0 || sizeOfSL == 1) return 0;

		int deleted = 0;
		Element *cur = head;
		// Запускаем цикл, который будет проверять второй
		// следующий элемента от текущего, и если он будет
		// равен topElement, то мы его удалим, иначе
		// простой перейдем к следующему
		while (cur->next->next != nullptr) {
			if (cur->next->value == topElement) {
				deleted++;
				sizeOfSL--;
				Element *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else cur = cur->next;
		}
		// В цикле мы не проверяем первый элемент, так как
		// идем от него, следовательно нужно его проверить
		// является ли он совпадающим с topElement и удалить
		// его при необходимости
		if (head->value == topElement) {
			deleted++;
			sizeOfSL--;
			Element *tmp = head;
			head = head->next;
			delete tmp;
		}
		return deleted;
	}
	
	// Метод печатает весь список с начала
	void PPrint() {
		for (Element *cur = head; cur != NULL; cur = cur-> next)
			cout << cur->value << ' ';
		cout << endl;
	}
};


#endif
