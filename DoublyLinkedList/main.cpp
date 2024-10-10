#include <iostream>
#include "DoublyLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	DoublyLinkedList* dl1 = new DoublyLinkedList();
	DoublyLinkedList* dl2 = new DoublyLinkedList();
	
	dl1->add(3);
	dl1->add(5);
	dl1->add(6);
	dl1->add(4);
	dl1->print();
	dl1->add(2);
	dl1->print();
	dl1->add(1);
	dl1->print();
	
	dl2->add(3);
	dl2->add(6);
	dl2->add(4);
	dl2->print();
	dl2->add(2);
	dl2->print();
	dl2->add(1);
	dl2->print();
	
	
	
	dl1->combine(dl2);
	dl1->print();
	return 0;
}
