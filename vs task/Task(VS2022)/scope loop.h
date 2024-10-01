#ifndef SCOPE_LOOP
#define SCOPE_LOOP

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void scope_loop();

void scope_loop2();

void scope_loop3();

void task_scope_loop_main();

class Student
{
public:
	string name;
	double score;

};

class GradeBook
{
private:
	vector<Student> students;

public:
	void addStudent(const string& name, double score);

	void displayStudents() const;

	double getAverageScore();

	void displayAboveAverageStudents(double avg_gpa) const;
};


#endif // !SCOPE_LOOP
