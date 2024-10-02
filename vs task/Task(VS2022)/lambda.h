/*
Title: Employee Salary Management System 
Background: 
You need to design a simple employee salary management system that can store employee names and salaries and provide some basic statistical functions. 

Requirements: 
Create a class named Employee, containing the following member variables: 

std::string name: employee name 
double salary: employee salary 
Create a class named Salary Manager, containing the following member variables: 

std::vector<Employee> employees: dynamic array for storing employee objects 
In the Salary Manager class, provide the following member functions: 

void add Employee(const std::string& name, double salary): add employee information. 
void display Employees(): output the names and salaries of all employees. 
double calculate Total Salary(): calculate and return the total salary of all employees. 
double calculate Average Salary(): calculate and return the average salary of all employees. 
void display Above Average Salaries(): use lambda expressions to output the names and salaries of all employees with salaries above the average. 
In the main function, simulate the employee salary management operation: 

Create a Salary Manager object. 
Prompt the user to enter the employee name and salary until the user chooses to stop. 
Display all employee information. 
Calculate and output the total salary and average salary. 
Display the information of all employees with higher than average salary.
*/

#ifndef LAMBDA_H
#define LAMBDA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void task_lambda_main();

struct Employee {
	std::string name;
	double salary;
	Employee(): name("Default Name"), salary(0.0) { }
};

class SalaryManager {
private:
	std::vector<Employee> employees;

public:
	void addEmployee(const std::string& name, double salary);	// add an employee

	void displayEmployees() const;	// display all employees

	double calculateAvgSalary(); // calculate average salary

	double calculateTotalSalary(); // calculate total salary

	void displayEmployeesAboveAvgSalary(double avg);	// display employees above average salary

};

#endif // LAMBDA_H
