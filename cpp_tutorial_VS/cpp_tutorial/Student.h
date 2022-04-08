#pragma once
#include "Person.h"
class Student : public Person
{
	/*
	* note about :public Person 
	#Public mode:
	if we drive a child class from a public parent class.Then the public member of the parent class
	becomes a public member for the child class and protected members of parent class becomes protected members of the child class.

	#Protected mode
	if we drive child class from a protected base class, then the public, as well as the protected member of the parent class, becomes the protected members of the child class. 

	#Private mode
	if we drive a child class from a private base class, then the public, as we as protected members, become private for the derived class.
	
	
	Private members of a base class cannot be directly accessed in the derived class in any circumstance.
	*/


	// just writing like this means That I did the inheritance of the person class. I got everything from the person class. example, it will call the constructors of the base class.

 // add the additional things to the Student class
private:
	int level;
	float GPA;
	string depart;
public:

	Student(string n, string g, float a, int l, float gp, string d):Person(n,g,a)  // example 11
	{
		level = l;
		GPA = gp;
		depart = d;
	}
	void set_level(int l)  // notice that I can also not just declare the functions in the .h file. but also I can declare them, not very logic but okay you can do it. because remeber the .h file is copied to where it is called. and in cpp I know that I can declare the function and define it later.
	{
		level = l;   
	}
	void set_GPA(float g)
	{
		GPA = g;
	}
	void set_depart(string d)
	{
		depart = d;
	}
	string get_depart()
	{
		return depart;
	}

	void display()
	{
		Person::display(); // I called the previous function in order not to re-write it 
		cout << "Depart = " << depart << " .Level= " << level << " .GPA= " << GPA << endl;

	}

};

