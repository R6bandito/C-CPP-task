#include "lambda.h"

void SalaryManager::addEmployee(const std::string& name, double salary) {
	Employee tmp_emp;
	tmp_emp.name = name;	tmp_emp.salary = salary;
	employees.push_back(tmp_emp);
}

void SalaryManager::displayEmployees() const {
	auto it = employees.begin(); auto it_end = employees.end();
	std::for_each(it, it_end, [this](const Employee &emp) {
		std::cout << "Name:" << emp.name << "  Salary:" << emp.salary << std::endl;
		});
}

double SalaryManager::calculateAvgSalary() {
	double sum = 0.0;
	for (auto& emp : this->employees) {
		sum += emp.salary;
	}
	return sum / employees.size();
}

double SalaryManager::calculateTotalSalary(){
	double sum = 0.0;
	std::for_each(employees.begin(), employees.end(), [this,&sum](auto& emp) {
		sum += emp.salary;
		});
	return sum;
}


void SalaryManager::displayEmployeesAboveAvgSalary(double avg) {
	std::cout<<std::endl<<"Employees Above Average:" << std::endl;
	std::for_each(this->employees.begin(), this->employees.end(), [this, &avg](auto& emp) {
		if(emp.salary > avg) std::cout << "Name:" << emp.name << "  Salary:" << emp.salary << std::endl;
		});
}


void task_lambda_main() {
	SalaryManager manager;
	double avg = 0.0;
	double total = 0.0;

	manager.addEmployee("John", 1000.0); manager.addEmployee("Jane", 2000.0);
	manager.addEmployee("Mark", 3000.0); manager.addEmployee("Marry", 4000.0);
	manager.addEmployee("Price", 4582.5); manager.addEmployee("Kally", 7214.5);

	avg = manager.calculateAvgSalary();
	total = manager.calculateTotalSalary();
	std::cout << "Average Salary: " << avg << std::endl << "Total Salary: " << total << std::endl<<std::endl;

	manager.displayEmployees();
	manager.displayEmployeesAboveAvgSalary(avg);
}