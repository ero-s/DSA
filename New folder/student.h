#include <iostream>
using namespace std;
class Student {
	public:
	string name;
	int stress;
	int id;
	
	string course;
		
		Student(){
			name = "";
			stress = 0;
			id = 0;
			course = "";
		}
		
		~Student(){
			cout<<"Removed Student"<<endl;			
		}
		
};
