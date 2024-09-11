#include <cstdlib>
#include <cmath>
#include "student.h"
class Course {
	Student** students;
	int size;
	int capacity;
	
	public:
	Course() {
		size = 0;
		capacity = 5;
		cout << "Allocating " << capacity * sizeof(Student) << " bytes" << endl;
		students = (Student**) malloc(capacity * sizeof(Student*));
	}
	
	void addStudent(Student* s) {
		if (size == capacity) {
			capacity = capacity * 1.5;
			students = (Student**) realloc(students, capacity * sizeof(Student*));
		}
		cout << "ADDING " << s->name << endl;
		students[size] = s;
		size++;
		cout << "MANA" << endl;
	}
	
	string removeStudent(Student* s){
		string temp;
		bool flag = false;
		int i;
		for(i = 0; i < size; i++){
			if(students[i]->name == s->name){
				temp = students[i]->name;
				flag = true;
				delete students[i];
				for(int j = i; j < size-1; j++){
					students[j] = students[j+1];
				}
				
				i--;
				size--;
				
				if(size < capacity * 2.0/3){
					capacity = ceil(capacity * 0.75);
					if(capacity < 5){
						capacity = 5;
					}
					students = (Student**)realloc(students,capacity * sizeof(Student*));
				}
				
			}
				
		}	
		if(flag) return temp;
		return "";
	}
	
	void print() {
		cout << "Student Size: " << size <<"/"<<capacity<< endl;
		for (int i = 0; i<size; i++) {
			cout << i+1 << ". " << students[i]->name << endl;
		}
	}
	
	~Course(){
		cout<<"Deleting Course..."<<endl;
		for(int i = 0; i < size; i++){
			delete (students[i]);
		}
		free (students);
	}
};

