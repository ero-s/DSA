#include "List.h"
#include "node.h"
#include "cstdlib"
#include "iostream"

using namespace std;
class LinkedList : public List{
	node* head, *tail;
	int size;
	
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
			size = 0;
		}
		
		void addNum(int num){
			if(!head){
				cout<<"Adding head"<<endl;
				head = (node*)calloc(1,sizeof(node));
				head->elem = num;
				head->next = NULL;
				tail = head;
				size++;
			}
			else{
				node* n = (node*)calloc(1,sizeof(node));
				n->elem = num;
				tail->next = n;
				tail = n;
				size++;
			}
		}
		
		void printList(){
			node* curr = head;
			while(curr != NULL){
				cout<<curr->elem;
				if(curr->next != NULL){
					cout<<" -> ";
				}
				curr = curr->next;
			}
			
			cout<<endl<<"Size = "<<size<<endl;
		}
		
		int removeHead(){
			node* temp = head;
			int ret = head->elem;
			head = head->next;
			free(temp);
			size--;
			cout<<"Removed head"<<endl;
			return ret;
		}
		
		int removeTail() {
		    if (head == NULL || tail == NULL) {
		        cout << "List is empty" << endl;
		        return -1;
		    }
		
		    node* curr = head;

		    if (head == tail) {
		        int temp = tail->elem;
		        free(tail);
		        head = tail = NULL;
		        size--;
		        cout << "Tail removed, list is now empty" << endl;
		        return temp;
		    }
		
		    
		    while (curr->next != NULL) {
		        if (curr->next == tail) {
		            int temp = tail->elem;
		            free(tail);  
		            tail = curr; 
		            tail->next = NULL;
		            cout << "Tail removed" << endl;
		            size--;
		            return temp;
		        }
		        curr = curr->next;
		    }
			
		    return -1; 
		}
		
		int removeNum(int num) {
			bool found = false;
		    if (head == NULL || tail == NULL) {
		        cout << "List is empty" << endl;
		        return -1;
		    }
		
		    node* curr = head;
		    node* prev = NULL;
		
		    if (head->elem== num) {
		    	int temp = head->elem;
		    	size--;
		        removeHead();
		        return temp;
		        
		    }
		
		    while (curr->next != NULL) {
		        if (curr->elem == num) {
		            int temp = curr->elem;
		            prev->next = curr->next;
		            if(curr == tail){
		            	tail = prev;
					}
		            free(curr);  
		            cout << "Num "<<num<<" removed" << endl;
		            size--;
		            return temp;
		        }
		        prev = curr;
		        curr = curr->next;
		        
		    }
		    return -1;
		}
		
		void addAt(int num, int pos) {
		    if (head == NULL || tail == NULL) {
		        cout << "List is empty" << endl;
		        return;
		    }
		
		    node* curr = head;
		    node* n = new node();
		    node* prev = NULL;
		    int ctr = 1;
		    
		    if(pos == 1){
		    	n->elem = num;
		    	n->next = head;
		    	head = n;
				size++;
				return;
			}
		
		    while (curr->next != NULL) {
		        if (ctr == pos) {
		        	n->elem = num;
		            prev->next = n;
					n->next = curr;
		            if(curr == tail){
		            	curr->next = tail;
					}
		            cout << "Num "<<num<<" added at pos "<<pos<< endl;
		            size++;
		        }
		        ctr++;
		        prev = curr;
		        curr = curr->next;
		    }
		}
		
		int removeAtPos(int pos) {
		    if (head == NULL) {
		        cout << "List is empty" << endl;
		        return -1;
		    }
		
		    node* curr = head;
		    node* prev = NULL;
		    int ctr = 1;
		
		    if (pos == 1) {
		    	int temp = head->elem;
		    	size--;
		        removeHead();
		        return temp;
		    }
		
		    while (curr != NULL) {
		        if (ctr == pos) {
		            int temp = curr->elem;
		            prev->next = curr->next;
		            if(curr == tail){
		            	tail = prev;
					}
		            delete(curr);  
		            cout << "Num "<<temp<<" removed at pos "<<pos<< endl;
		            size--;
		            return temp;
		        }
		        ctr++;
		        prev = curr;
		        curr = curr->next;   
		    }
		}
		
		int getNumAtPos(int pos) {
		    if (head == NULL || tail == NULL) {
		        cout << "List is empty" << endl;
		        return -1;
		    }
		    
		    node* curr = head;
		    int ctr = 1;
		
		    while (curr != NULL) {
		        if (ctr == pos) {
		            int temp = curr->elem;
		            return temp;
		        }
		        ctr++;
		        curr = curr->next;
		    }
		}
		
		void removeAll(){
		    node* curr = head;
		
		    while (curr != NULL) {
		        node* temp = curr; 
		        curr = curr->next; 
		        delete temp; 
		        size--;
		    }
		
		    head = NULL;  // Set head to nullptr after clearing the list
		    cout << "All items removed, size = " << size;
		}

		
		
		
		

};
