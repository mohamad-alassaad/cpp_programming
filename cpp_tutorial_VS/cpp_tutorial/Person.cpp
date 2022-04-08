#include "Person.h"
#include <iostream>
using namespace std;
Person::Person() :name("Unknown"), gender("Unknown"), age(0)
{
}
Person::Person(string n, string g, float a) : name(n), gender(g), age(a)
{
}
;
Person::Person(string n, string g, long s, float a):name(n),gender(g),age(a)
{
}
void Person::set_age(float a)
{
	age = a;
}
float Person::get_age()
{
	return age;
}
void Person::set_name(string n)
{
	name = n;
}
void Person::set_gender(string g)
{
	gender = g;
}

string Person::get_gender()
{
	return gender;
}
string Person::get_name()
{
	return name;
}

void Person::display()
{
	cout << "This is " << name << ". The gender is " << gender << " and the age is: " << age << endl;
}
;



Person::~Person()
{
};