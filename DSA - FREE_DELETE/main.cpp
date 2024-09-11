#include <iostream>
#include "course.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout << sizeof(Course);
	Course* csit = new Course();
	Course* cpe = new Course();
	Course* current = new Course();
	current = csit;
	Student* s;
	char op;
	string removed;
	while (true) {
		cout << "Op(aDD, pRINT, rEMOVE, dELETE, cHECK, sWITCH): ";
		cin  >> op;
		switch (op) {
			case 'a':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				current->addStudent(s);
				break;
			case 'p':
				current->print();
				break;
			
			case 'r':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				removed = current->removeStudent(s);
				cout<<"Removed: "<<removed<<endl;
				break;
				
			case 'c':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				current->checkAddress(s);
				break;
				
			case 's':
				current = (current == csit)? cpe : csit;
				break;
				
			case 'd':
				delete (current);
				
		}
	}
	return 0;
}
