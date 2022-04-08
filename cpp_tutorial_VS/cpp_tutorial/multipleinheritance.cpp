#include "multipleinheritance.h"

Employee::Employee()
{
}

Employee::Employee(string n, string j, float s):name(n),job(j),salary(s)
{
}

void Employee::set_job(string j)
{
	job = j;
}

void Employee::set_Salary(float s)
{
	salary = s;
}

void Employee::set_name(string n)
{
	name = n;
}

string Employee::get_job()
{
	return job;
}

float Employee::get_Salary()
{
	return salary;
}

string Employee::get_name()
{
	return name;
}

void Employee::display()
{
	cout << "This is " << name<< ". the job is "<< job <<". with a salary of : "<< salary<<endl;
}

Employee::~Employee()
{
}

Student_inf::Student_inf()
{
}

Student_inf::Student_inf(string d, string r)
{
	departement = d;
	research_interest = r;
}

void Student_inf::set_dep(string j)
{
	departement = j;
}

void Student_inf::set_resea(float s)
{
	research_interest = s;

}

string Student_inf::get_dep()
{
	return departement;
}

void Student_inf::set_name(string n)
{
	name=n;
}

string Student_inf::get_resea()
{
	return research_interest;
}

void Student_inf::display()
{
	cout << "The departement is: " <<departement << " with research interests of: " << research_interest<< endl;
}

Student_inf::~Student_inf()
{
}

void TeachingAssistant::display()
{
	Employee::display();
	Student_inf::display();
}
