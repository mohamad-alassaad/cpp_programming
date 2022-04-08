#pragma once
#include <string>
#include <iostream>
using namespace std;

///  The car class ////////////

class Car
{
private:
	string maker;
	int model;
	string color;
	static int countcars;  // shared variables to all instances of the class.
public:
	void setMaker(string m);
	string getMaker();
	void setModel(int m);
	int getModel();  // right click on quick implementation and choose to write the function int the .cpp file
	int getCarcount();
	Car();
	Car(string m, int mo, string colo);
	~Car();
};


///  The calculator class ////////////
class Calculator
{
private:
public:
	int add(int num1, int num2);
	int add(int num1, int num2, int num3);
	float add(float num1, float num2);
	string add(string a, string b);
	Calculator();
	~Calculator();
};



///  The distance class ////////////

class Distance
{
private:
	int feet;
	float inches;

public:
	Distance();
	Distance(int f, float i);
	void setDistance(int f, float i);
	void print();
	Distance add_distance(Distance d2);

	Distance operator +(Distance d2)
	{
		int f = feet + d2.feet;
		int i = inches + d2.inches;
		return Distance(f, i);
	}
	Distance operator -(Distance d2)
	{
		int f = feet - d2.feet;
		int i = inches - d2.inches;
		return Distance(f, i);
	}


	~Distance();
};


///  The calculator class ////////////
class Calculator_1     // utility class. 
{
private:
public:
	static int add(int num1, int num2);
	static int add(int num1, int num2, int num3);
	static int multiply(int num1, int num2);
	static float add(float num1, float num2);
	static string add(string a, string b);
	Calculator_1();
	~Calculator_1();
};



///// class Counter /////////
class Counter
{
private:
	unsigned int count;
public:
	Counter() : count(0) {}
	Counter(int c): count(c) {}
	int get_count() { return count; }
	Counter operator ++()  // pre-fix of the operator
	{
		++count;
		return Counter(count);
	}
	Counter operator --()  // pre-fix of the operator
	{
		--count;
		return Counter(count);
	}

	Counter operator ++(int)  // post-fix of the operator
	{
		count++;
		return Counter(count);
	}
	Counter operator --(int)  // post-fix of the operator
	{
		count--;
		return Counter(count);
	}
};






////// Base class //////////

class Base
{
	int x;
public:
	//Default constructor
	Base()
	{
		x = 0;
		cout << "Base default constructor \n";
	}

};


////  Derived class ///////////

class Derived : public Base
{
	int y;
public:
	// default constructor 
	Derived()
	{
		y = 0;
		cout << "Derived default constructor \n";
	}
	// Parameterized constructor 
	Derived(int i)
	{
		y = i;
		cout << "Derived parameterized constructor \n";
	}
};