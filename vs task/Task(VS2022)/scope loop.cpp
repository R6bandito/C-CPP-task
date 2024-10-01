#include "scope loop.h"

/*You need to design a simple student performance management system 
that can store students' names and achievements and provide some basic statistical functions.
*/
void scope_loop() {	//example 1
	vector<int> vec;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++) {
		vec.push_back(i * 2);
	}

	for (int i : vec) {
		cout << i<<"  ";
	}
	cout << endl;

	for (int n : arr) {
		cout << n << "  ";
	}
	cout << endl;
}

void scope_loop2() {	//example 2	Traversing List container
	list<string> lst = {"Hello","World","C++"};
	for (auto& str : lst) {
		cout << str << "  ";
	}
	cout << endl;
}

void scope_loop3() {	//example 3 
	int i = 0;
	vector<string> vec = { "Foo","Bar","Baz" };

	for (auto& str : vec) {
		i++;
		if (i > 2) {
			str += "Additional";
		}
		cout << str << "  ";
	}
	cout << endl;
}

void GradeBook::addStudent(const string& name, double gpa) {
	Student s;
	s.name = name;
	s.score = gpa;
	this->students.push_back(s);
}

double GradeBook::getAverageScore() {
	double sum = 0.0;
	for (auto& stu : students) {	//for (Student stu : students)
		sum += stu.score;
	}
	return sum / students.size();
}

void GradeBook::displayStudents() const {
	int i = 1;
	for (auto& stu : students) {
		cout << i++ << " Student Name: " << stu.name << " Score: " << stu.score << endl;
	}
}

void GradeBook::displayAboveAverageStudents(double avg_gpa) const {
	cout<<"Students Above Average:"<<endl;
	for (auto& stu : students) {
		if (stu.score > avg_gpa) {
			cout << stu.name << " " << stu.score << endl;
		}
	}
}

void task_scope_loop_main() {
	double avg_gpa = 0.0;
	GradeBook book;

	book.addStudent("Mike", 3.7); book.addStudent("John", 3.8);
	book.addStudent("Jane", 3.9); book.addStudent("Mark", 3.5);
	book.addStudent("Marry", 3.4); book.addStudent("Rosy", 2.7);
	book.addStudent("Kally", 2.9); book.addStudent("Price", 3.0);

	avg_gpa = book.getAverageScore();

	book.displayStudents();
	cout << endl <<endl<< "Average Score: " << avg_gpa << endl<<endl<<endl;
	book.displayAboveAverageStudents(avg_gpa);
}

