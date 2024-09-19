#include <iostream>
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList* l = new LinkedList();
	int num, pos, choice, output;
	
	do{
		cout<<"\n\nLinked Lists (Enter number of choice): "<<endl;
		cout<<"1. Add"<<endl;
		cout<<"2. Add At"<<endl;
		cout<<"3. Remove Num"<<endl;
		cout<<"4. Remove Head"<<endl;
		cout<<"5. Remove At"<<endl;
		cout<<"6. Remove Tail"<<endl;
		cout<<"7. Remove All"<<endl;
		cout<<"8. Get Num at Pos"<<endl;
		cout<<"9. Print List"<<endl;
		
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter number to add: ";
				cin>>num;
				l->addNum(num);
				break;
			case 2:
				cout<<"Enter number to add: ";
				cin>>num;
				cout<<"Enter position to add at: ";
				cin>>pos;
				l->addAt(num, pos);
				break;
			case 3:
				cout<<"Enter number to remove: ";
				cin>>num;
				l->removeNum(num);
				break;
			case 4:
				l->removeHead();
				break;
			case 5:
				cout<<"Enter position to remove at: ";
				cin>>pos;
				l->removeAtPos(pos);
				break;
			case 6:
				l->removeTail();
				break;
				
			case 7:
				l->removeAll();
				break;
			case 8:
				cout<<"Enter position to get num at: ";
				cin>>pos;
				cout<<"Num at pos "<<pos<<" is "<<l->getNumAtPos(pos);
				break;
			
			case 9:
				cout<<endl;
				l->printList();
		}
		
		
	}while(true);
}
