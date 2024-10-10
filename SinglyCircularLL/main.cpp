#include <iostream>
#include "SinglyCircularLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	SinglyCircularLinkedList* l = new SinglyCircularLinkedList();
	int choice;
	
	l->addLast(1);
	l->addLast(2);
	l->addLast(3);
	l->addFirst(4);
	
	l->print(); 
	l->removeLast(); 
	l->print();   

	l->print();
	
//	while(true){
//		cout<<"Enter an option:"<<endl;
//		cout<<"1. addFirst"<<endl;
//		cout<<"2. addLast"<<endl;
//		cout<<"3. rotate"<<endl;
//		cout<<"4. print"<<endl;
//		cin>>choice;
//		
//		switch(choice){
//			case 1:{
//				int num;
//				cout<<"Enter num to add: ";
//				cin>>num;
//				l->addFirst(num);
//				break;
//			}
//			case 2:{
//				int num;
//				cout<<"Enter num to add: ";
//				cin>>num;
//				l->addLast(num);
//				break;
//			}
//			case 3:{
//				int num;
//				cout<<"Enter num of turn: ";
//				cin>>num;
//				l->rotate(num);
//				break;
//			}
//			case 4:{
//				l->print();
//				break;
//			}
//		}
//	}
	
	return 0;
}
