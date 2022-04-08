#pragma once
#include <iostream>
using namespace std;
class Person
{
private:
	string name;
	string gender;
	float age;
public:
	Person();
	Person(string n, string g, float a);
	Person(string n, string g, long s, float a);
	void set_age(float a);
	float get_age();
	void set_name(string n);
	string get_name();
	void set_gender(string g);
	string get_gender();
	void display();

	// Friend Function and Friend class
	friend void print(Person p); // I am telling the compiler that there is a function 
	// called print, that is defined and declared outside the class, but has the right to access this class (person) attributes and private data.
	 // you don't count this in the number of functions that the class Person has.
	// it will not be inherited for example. this is not a member function.
	friend class printclass;
	~Person();

};

