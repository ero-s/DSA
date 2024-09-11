#include <iostream>
#include "course.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout << sizeof(Course);
	Course* csit = new Course();
	Student* s;
	char op;
	string removed;
	while (true) {
		cout << "Op(aDD, pRINT, rEMOVE, dELETE, cHECK): ";
		cin  >> op;
		switch (op) {
			case 'a':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				csit->addStudent(s);
				break;
			case 'p':
				csit->print();
				break;
			
			case 'r':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				removed = csit->removeStudent(s);
				cout<<"Removed: "<<removed<<endl;
				break;
				
			case 'c':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				csit->checkAddress(s);
				break;
				
			case 'd':
				delete (csit);
				return 0;
		}
	}
}
