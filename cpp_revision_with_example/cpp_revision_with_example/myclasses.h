#pragma once
#include <iostream>
using namespace std;



/////////////////// Employee class ///////////////////
class Employee
{
protected: // because I need to access them from the sales class
	string name;
	int emp_ID;
	double salary;
public:
	Employee():name("Unknown"), emp_ID(0),salary(0)  // overloading
	{};
	Employee(string n, int id, float s)
	{
		name = n;
		emp_ID = id;
		salary = s;
	};

	virtual float Get_Total_salary()=0;
	virtual void print()
	{
		cout << "Name: " << name << ". ID: " << emp_ID << ". Salary: " << salary <<endl;
	}
};


/////////////////// Sales class ///////////////////

class Sales: public Employee
{
private:
	float goss_sales;
	float commission_rate;

public:
	Sales(string n, int id, float s,float go,float co):Employee(n,id,s)
	{
		goss_sales = go;
		commission_rate = co;
	};
	float Get_Total_salary()    // overriding pure virtual function
	{
		return salary + (goss_sales * commission_rate);
	};
	void print()  // implementation here is not necessary because it is not pure, I can do override and I can not 
	{
		Employee::print();
		cout << "goss_sales: "  << goss_sales << ".commission_rate: " << commission_rate << endl;

		
	};
};


/////////////////// Engineer class ///////////////////

class Engineer : public Employee
{
private:
	string speciality;
	int experience;
	int overtime_hours;
	float overtime_hour_rate;


public:
	Engineer(string n, int id, float s, string sp, int exp, int over, float othr) :Employee(n, id, s)
	{
		speciality = sp;
		experience = exp;
		overtime_hours = over;
		overtime_hour_rate = othr;

	};
	float Get_Total_salary()
	{
		return salary + (overtime_hours* overtime_hour_rate);
	};
	void print()  // implementation here is not necessary because it is not pure, I can do override and I can not 
	{
		Employee::print();
		cout << "speciality: " << speciality << ".experience: " << experience << ". overtime_hours: " << overtime_hours << ". overtime_hour_rate: " << overtime_hour_rate <<endl;


	};

};