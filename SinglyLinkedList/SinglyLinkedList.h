#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;
class SinglyLinkedList : public List{
	Node* head;
	Node* tail;
	int size;
	
	public:
		SinglyLinkedList(){
			head = NULL;
			tail = NULL;
			size = 0;
		}
		
		void add(int num){
			Node* n = new Node();
			n->elem = num;
			
			if(!head){
				head = n;
				head->next = tail;
				tail = n;
			}
			else{
				tail->next = n;
				tail = n;
				tail->next = NULL;
			}
			size++;
		}
		
		void flip() {
	        if (size <= 1) return;
	
	        Node* current = head;
	        Node* prev = NULL;
	        Node* next = NULL;
	
	        tail = head;
	
	        while (current) {
	            next = current->next;
	            current->next = prev;
	            prev = current;
	            current = next;
	        }
	        head = prev;
	    }
	    
		void print(){
			cout<<"Size: "<<size<<endl;
			Node* curr = head;
			while(curr){
				cout<<curr->elem;
				if(curr->next != NULL){
					cout<<" -> ";
				}
				curr = curr->next;
			}
			cout<<endl;
		}
	
	
	
};
