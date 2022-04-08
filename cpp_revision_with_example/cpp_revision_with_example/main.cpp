#include <iostream>
#include "myclasses.h"
using namespace std;



int main()
{
	Employee* emp_ptr;  // to check the polymorphism idea 
	Sales s1("MOMO",120,5000,50000,0.10);
	Engineer e1("Pierro",150,7000,"SW En",5,10,50);

	emp_ptr = &s1; // I used the pointer to point to the sales s1 adress 
	emp_ptr->Get_Total_salary();
	emp_ptr->print();

	emp_ptr = &e1; // I used the pointer to point to the engineer s1 adress 
	emp_ptr->Get_Total_salary();
	emp_ptr->print();


	return 0;
};
