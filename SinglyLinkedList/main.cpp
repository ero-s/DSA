#include <iostream>
#include "SinglyLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	SinglyLinkedList* l = new SinglyLinkedList();
	
	l->add(1);
	l->add(2);
	l->add(3);
	l->print();

	l->flip();
	l->print();
	return 0;
}
