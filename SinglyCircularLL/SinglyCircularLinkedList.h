#include "List.h"
#include "Node.h"
#include <iostream>
#include <cstdlib>

using namespace std;
class SinglyCircularLinkedList : public List{
	Node* tail;
	int size;
	
	public:
		SinglyCircularLinkedList(){
			tail = NULL;
			size = 0;
		}
		
		void addFirst(int num){
			Node* n = new Node();
			n->elem = num;
			
			if(!tail){
				tail = n;
				n->next = n;
			}
			else{
				n->next = tail->next;
				tail->next = n;
			}
			cout<<"Number "<<num<<" has been added ahead"<<endl;
			size++;
		}
		
		void addLast(int num){
			Node* n = new Node();
	        n->elem = num;
	
	        if (!tail) {
	            tail = n;
	            n->next = n;
	        } else {
	            n->next = tail->next;
	            tail->next = n; 
	            tail = n;      
	        }
	        cout << "Number "<<num<<" has been added behind" << endl;
	        size++;
	    }
		
		void rotate(int turn){
			for(int i = 0; i < turn; i++){
				tail = tail->next;
			}
		}
		
		void removeLast(){
			if (size == 0) {
		        cout << "List is empty. Cannot remove last element." << endl;
		        return;
		    }
		
		    if (size == 1) {
		        delete tail; 
		        tail = NULL; 
		    } 
			else {
		        Node* current = tail->next; 
		        while (current->next != tail) { 
		            current = current->next;
		    	}
		        current->next = tail->next; 
		        delete tail; 
		        tail = current; 
		    }
		    size--; 
		    cout << "Last element removed." << endl;
		}
		
		void print(){
			if (size == 0) {
	            cout << "List is empty" << endl;
	            return;
	        }
	        for (int i = 0; i < size; i++) {
	            cout << tail->next->elem;  
	            if (i != size - 1) {
	                cout << " -> ";
	            }
	            rotate(1);
	        }
	        cout << endl;
	    }
};
