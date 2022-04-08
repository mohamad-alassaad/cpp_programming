#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
	string name;
	string job;
	float salary;
public:
	Employee();
	Employee(string n, string j, float s);
	void set_job(string j);
	void set_Salary(float s);
	void set_name(string n);
	string get_job();
	float get_Salary();
	string get_name();
	void display();
	~Employee();
};



class Student_inf
{
private:
	string name;
	string departement;
	string research_interest;
public:
	Student_inf();
	Student_inf(string d, string r);
	void set_dep(string j);
	void set_resea(float s);
	void set_name(string n);
	string get_dep();
	string get_resea();
	void display();
	~Student_inf();
};



class TeachingAssistant: public Student_inf, public Employee
{
private:
public:
	TeachingAssistant(string n, string j, float s, string d, string ra) :Employee(n, j, s), Student_inf(d, ra){};
	void display();
	~TeachingAssistant() {};
};

