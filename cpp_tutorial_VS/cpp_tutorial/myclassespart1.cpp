#include "myclassespart1.h"   // important a3mela include, kermel yshuf l declaration lal attributes and the methods.
#include <iostream>
using namespace std;







///////////// The car class  ////////////////////
int Car::countcars = 0;   // initialization of the static variable here !!! it should be initialized outside the class. 
							// lifetime of static variables does not depend on instances of the class but on the lifetime of the program.

//constructors
// this is the default constructor.
/*
Car::Car()   // example 3: constructor is a special method (same name of class, no return value, automatically called when an object is created
{
	maker = "Honda";    // maker is a variable that is declared in the .h file
	model = 2019;
	color = "white";
	cout << "maker, model and color attributes are initialized.";
}
*/

// this is constructor overloading.
Car::Car():maker("Honda"),model(2019),color("white")  // example 4: inialization list
{
	cout << "maker, model and color attributes are initialized." << "\n";
	countcars++;
}
// this is another constructor overloading.
Car::Car(string m, int mo, string colo):maker(m),model(mo),color(colo)
{
	cout << "maker, model and color attributes are initialized by the user." << "\n";
}




Car::~Car()   // destructor is a special method (same name of the class with ~, no return value, automatically called when an object life time is ended
{
	cout << "The life time of the class Car is ended";
	countcars--;
}


void Car::setMaker(string m)   // typeofreturnfunction nameofclass::functionintheclass(...)
{
	maker = m;  // already maker is declared in the h file. he knows it. also I put #include "Car.h" and because the same class is changing it, so its okay 

}
string Car::getMaker()
{
	return maker;
}

void Car::setModel(int m)
{
	model = m;
}

int Car::getModel()
{
	return model;
}

int Car::getCarcount()
{
	return countcars;
}




////////////// The calculator class   ////////////////

int Calculator::add(int num1, int num2)
{
	return num1+num2;
}

int Calculator::add(int num1, int num2, int num3)
{
	return num1+ num2+ num3;
}

float Calculator::add(float num1, float num2)
{
	return num1+num2;
}

string Calculator::add(string a, string b)
{
	return a+ " " +b;
}

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

Distance::Distance():feet(0),inches(0.0f)
{
}

Distance::Distance(int f, float i):feet(f),inches(i)
{
}

void Distance::setDistance(int f, float i)
{
	feet = f;
	inches = i;
}

void Distance::print()
{
	cout << "Feet: " << feet << "    " << " Inches: " << inches << "\n";
}

Distance Distance::add_distance(Distance d2)
{
	Distance result;
	result.feet=feet + d2.feet;  // I can access the .feet attribute even if it is private because I am in the same class.
	result.inches = inches+d2.inches;
	return result;
}

Distance::~Distance()
{
}






////////////// The calculator_1 class   //////////////// utility class

int Calculator_1::add(int num1, int num2)
{
	return num1 + num2;
}

int Calculator_1::add(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
}

int Calculator_1::multiply(int num1, int num2)
{
	return num1*num2;
}


float Calculator_1::add(float num1, float num2)
{
	return num1 + num2;
}

string Calculator_1::add(string a, string b)
{
	return a + " " + b;
}

Calculator_1::Calculator_1()
{
}

Calculator_1::~Calculator_1()
{
}




