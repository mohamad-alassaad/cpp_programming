
// include external libraries
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "string.h"           // include string

using namespace std;

//include local libraries
#include "myclassespart1.h"  // I included the declaration of class car.
#include "Student.h"
#include "PostGradutatedStudent.h"  // example 12
#include "multipleinheritance.h"  // example 13
#include "Polymorphism.h"   // example 14
///////////////////////  Example one   ////////////////////////////////////////////////
/*
// create class
class Rectangle
{
private:
	//private attributes, only accessible inside the class.
	float length;
	float width;
public:
	//set function
	void setLength(float len)
	{
		if (len >= 0) { length = len; }
		else { cout << "Please enter positive values"; }
	}
	//get function
	float getLength()
	{
		return length;
	}
	void setWidth(float wid)
	{
		if (wid >= 0) { width = wid; }
		else { cout << "Please enter positive values"; }
	}
	float getWidth()
	{
		return length;
	}
	float getArea()
	{
		return length * width;
	}
};

*/



/*
* example 2: the car example
The class can be seperated into 2 files 
header file .h
	contains the declaration of all the class members
	only attributes declaration and methods prototypes

Implementation file .cpp
	contains the implementation of the class methods.

the main advantage of this seperation, is that you hide the 
implementation for other developpers (good if you write the code,  bad if you try to understand another code)
if someone need to use or understand your code. it is enough
to him to read the header file.
*/



void print(Person p)
{
	cout << "The basic Data of person " << endl;
	cout << "name " << p.name << "Age = " << p.age << "gender= " << p.gender << endl;
	// the access of the private attributes of p couldn't happen it the function is not
	// defined as friendly inside the Person class.
};

class printclass
{
public: 
	void print_1(Person p)
	{
		cout << "The basic Data of person " << endl;
		cout << "name " << p.name << "Age = " << p.age << "gender= " << p.gender << endl;
	};

};


int main()  // any cpp file, I put in it the main function, it will be the client code. not necessary name it main.cpp 
{
	/*
	//example 1: create first class
	Rectangle box;
	box.setLength(0.5);
	box.setWidth(0.5);
	cout << "The area of the box is: " << box.getArea();
	*/

	//example 2: create your first class   
	/*
	Car c1;
	c1.setMaker("Honda");
	c1.setModel(2018);
	cout << "This Car is made by " << c1.getMaker() << "\n";
	cout << "The Car model is " << c1.getModel() << "\n";
	*/
	

	// example 3: constructors
	/*
	Car c2;    // I inialised the maker and model in the constructor direclty (default values). the initialization is done outside the body of the constructor
	cout << "This car made by: " << c2.getMaker() << "\n";
	cout << "This car model is: " << c2.getModel() << "\n";

	*/

	// example 4: constructors Initialization list (prefered to do) . it differ in the speed of the execution if you do inialize the attributes inside the constructor
	/*
	Car c2("Honda",2019,"green");    // I inialised the maker and model in the constructor direclty (default values). the initialization is done outside the body of the constructor
	cout << "This car made by: " << c2.getMaker() << "\n";
	cout << "This car model is: " << c2.getModel() << "\n";
	*/


	// example 5: method overloading 
	/*
	Calculator k1;   // default constructor
	cout << "this is the first overload " << k1.add(3, 7) << "\n";  // it is written the number of the overloads when you hover on the function
	cout << "this is the second overload " << k1.add(3, 7,5) << "\n";  // it is written the number of the overloads when you hover on the function
	cout << "this is the third overload " << k1.add((float)3.9, (float)7.6) << "\n";  // it is written the number of the overloads when you hover on the function
	cout << "this is the forth overload " << k1.add("Hello", "World") << "\n";  // it is written the number of the overloads when you hover on the function
	*/


	// example 6: the default copy constructor
	// I want to make an object from specific class but this object is a copy from another object 
	/*
	Car c1;
	Car c2("Mercedes", 2021, "black");
	Car c3(c2);   // this will copy the values in c2 to c3 . by value not by reference !!!
	Car c4 = c1;  // another way to copy the values stored in c1 to c4. by value not by reference !!!
	cout << "C1  maker is :" << c1.getMaker() << "\n";
	cout << "C2  maker is :" << c2.getMaker() << "\n";
	cout << "C3  maker is :" << c3.getMaker() << "\n";
	cout << "C4  maker is :" << c4.getMaker() << "\n";
	c2.setMaker("Not Mercedes");
	cout << "C2  maker is :" << c2.getMaker() << "\n";
	cout << "C3  maker is :" << c3.getMaker() << "\n";
	*/




	// example 7:  Passing objects to methods. 
	/*
	Distance d1(4,(float)6.5);
	Distance d2(5, (float)6);
	cout << "Distance d1: \n";
	d1.print();
	cout << "Distance d2: \n";
	d2.print();
	Distance d3=d2.add_distance(d1);
	cout << "Distance d3=d1+d2: \n";
	d3.print();
	Distance d4(d2.add_distance(d1));
	cout << "Distance d4=d1+d2: \n";
	d4.print();
	*/

	// example 8: Static class Members (attributes)
	/*
	Static fields and static methods do not belong to a single instance of a class
	A static data item is useful when all objects of the same class must share a common information 
	its lifetime is the entire program. It continues to exist even if there are no objects of the class
	To invoke a static method or a static field, use the class name, rather than the instance name.
	*/


	/*
	Car c1;
	cout << "Counter reached: " << c1.getCarcount() << "\n";
	Car c2;
	cout << "Counter reached: " << c2.getCarcount() << "\n";
	Car c3;
	cout << "Counter reached: " << c3.getCarcount() << "\n";
	*/


	/*
	Static methods are convenient because they may be called at the class level. 
	They are typically used to create utility classes
	Static methods may not communicate with instance fields, only static fields.
	for this reason you may create classes with static methods. 
	for example the class "calculator", it is more logical that you want to use the "add" function 
	directly, instead of each time create an object of that class and use the add function, this is not logic and
	takes a lot from the memory allocation for each object, that is why better to create the "add" function 
	as a static method. next I will create "calculator_1" class like this.
	utility classes are like services you think about it.
	*/

	/*
	cout << "2+5= " << Calculator_1::add(2, 5) << "\n";
	cout << "2+5+6= " << Calculator_1::add(2, 5,6) << "\n";
	cout << "2*5= " << Calculator_1::multiply(2, 5) << "\n";
	*/





	// example 9: Operator Overloading
	/*
	int i = 5, j = 10;
	cout << i + j << endl;  // this is the "+" operator.
	*/


	/*
	The term operator overloading refers to 
	giving the normal C++ operators, such as +,*,<=, and +=.
	additional meanings when they are applied to user-defined data types.
	operator overloading is one of the most exciting features of object-oriented programming. 
	it can transform complex program listings into easy ones. 
	the operator keyword is used to overload operators. 
	*/

/*
	Counter cu1(5);
	Counter cu2(10);
	Counter cu3 = ++cu1;
	Counter cu4 = --cu2;
	cout << cu3.get_count() << endl;
	cout << cu4.get_count() << endl;

	int ik = 7;
	ik++; // post-fix
	++ik; // pre-fix
	Counter cu5 = cu1++;
	Counter cu6 = cu2--;
	cout << cu5.get_count() << endl;
	cout << cu6.get_count() << endl;

	Distance d10(3, 4);
	Distance d11(13, 14);
	Distance d12 = d10 + d11;
	d12.print();

*/




	// example 10: inheritance
	/*
	Inheritance - What Is Inheritance ?
	Inheritance is probably the most powerful feature of object-oriented programming, after classes themselves.
	Inheritance is the process of creating new classes, called derived classes, from existing or base classes.
	The derived class inherits all the capabilities of the base class but can add its own features. And the base 
	class in unchanged by this process.
	Inheritance permits code reusability
	Reusing existing code saves time and money and increases a program's reliability.
	*/

	/*
	The relationship between a Base Class and an derived class is called an "is a" relationship.
	-a post gradutate student "is a" Student.
	-an Employee "is a" Person 
	-Salaried Employee "is a" Employee
	-a car "is a" vehicle.
	A specialized object class has:
	-all of the characteristics of the general object, plus
	-additional characteristics that make it special
	In object-oriented programming, inheritance is used to create an "is a" relationship among classes.
	*/


/*
	Student s1;
	s1.display();  // without doing anything, I inherited everything from the class Person.
	s1.set_name("Momo");
	s1.set_gender("Male");
	s1.set_age(26);
	s1.display();

	s1.set_depart("ELEC");
	s1.set_GPA(3.5);

*/


	// example 11: Inheritance - Calling Base Class Constructors
	/*
	Order of constructor call with inheritance in c++
	Whether derived class's default construtor is called or parameterized is called, base class's default constructor is always called inside them.
	To call base class's parameterized constructor inside derived class's parameterized constructor, we must mention it expecitly while declaring derived class's parameterized constructor.
	
	*/
	//Base b;
	//Derived d1;
	//Derived d2(10);


	//Student s1("Momo", "Male", 15, 5, 3.5, "ELEC");
	//s1.display();  // this should be re-created in the local class in order to display also the local attributes about the student itself.


	// example 12: Inheritance - Function Overriding
	/*
	Function Overriding:
	It is the redefinition of base class function in its derived class with same signature
	this is different that overloading that we did before
	Function overloading:
	It provides multiple definitions of the function by changing signature i.e changing number of parameters, change datatype of parameters 
	It can be done in base as well as derived class. 
	*/
	//s1.display();   // after re-writing the display in the class Student.
	// note:
	// function overriding can't be done in the same class (logical), different than function overloading (can be in the same class)

	//PostGradutatedStudent sr1("Momo", "Male", 15, 5, 3.5, "ELEC","Computer Vision");
	//sr1.display();



	//example 13: OOP - Multiple Inheritance
	/*
	Multiple inheritance occurs when a class inherits from more than one base class. So the class can inherit features from multiple base classes in the same time.
	Unlike other oriented programming languages, C++ allow this important features to programmers

	*/
	/*
	TeachingAssistant ta("Momo", "TA", 5000, "ELEC", "DataBases");
	ta.set_Salary(50000);
	// what if I have same function name in the two base classes ?
	// in this case, you put the name of the base class
	ta.Employee::set_name("Momi");
	ta.Student_inf::set_name("Moma");
	ta.display();
	*/



	// example 14: what is polymorphism ?
	/*
	-Polymorphism is an object-oriented programming concept that refers 
	to the ability of a variable, function, or object to take on multiple forms 
	-with polymorphism, class objects belonging to the same hierarchical tree (inherited
	from a common parent class) may have functions with the same name, but with different behaviors.
	-Types of polymorphism:
		compile time polymorphism: method overloading
		run time polymorphism: method overriding
	-Functions Overriding using Virtual Functions
		- a virtual function is a member function which is declared witha a base class and is 
		re-defined (Overriden) by a derived class. When you refer to a derived class object 
		using a pointer to the base class, you can call a virtual function for that object and 
		execute the derived class's version of the function. 
		- Virutal functions ensure that the correct function is called for an object, 
		regardless of the type of reference (or pointer) used for function call.
		example:
		base class Shape and derived classes: Rectangle, Box, Circle
		Shape* shap_ptr; 
		shap_ptr can point to Shape or Rectangle or Box or Circle, because the relation between Rectange, Box or Circle with the Shape is a "is a" relationship 
		so when I use the virtual function, it will allows me to use the pointer to point to the derived or override functions in the derived classes not in the base class.
		so the override function will be called depending on the type of the object that I am point to.
	*/

/*
	Shape* shap_ptr;
	Rectangle rec(10, 7, "Red");
	Circle c(5, "Yellow");
	shap_ptr = &rec;  // I am telling the pointer to point to the real address of the Rectangle
	shap_ptr->area();   // calling the area method in the Rectangle class.
	shap_ptr->draw();  // always when using the pointers, you use "->" instead of "."


	shap_ptr = &c;  // I am telling the pointer to point to the real address of the Circle
	shap_ptr->area();
	shap_ptr->draw();   // calling the area method in the Circle class.


	// if I didnt use the "virtual" and let the same code, the code will run, but the pointer will run the
	//functions of the base class (this is called static pointing or static linking), so it will only look at the functions in the base class.
*/

// example 15: Abstract Class - Final Classifier
/*
Abstract Classes - Interfaces
-An interface (Abstract Class) describes the behavior or capabilities of a c++
class without committing to a particular implementation of that class.
-The purpose of an abstract class is to provide the Desired base class Form 
which will be inherited by other classes in the class hierarchy.
-Abstract classes cannot be used to instantiate objects and serves only as an interface.
-A class is made abstract by  declaring at least one of its functions as pure virtual function.

final classifier
when I write final after a method, It is like saying, this method is not allowed
to be override in derived classes.

see class shape_pure in the .h file 
*/


// example 16:  Friend Function and Friend Class
/*
-A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class.
-The prototypes for friend functions appear in the class definition. 
-friends are not member functions

see class Person
see the print(Person p) function that I defined before the main.
*/
Person x("Momo", "Male", 26);
print(x);  // the friendly function that I defined before the main


/*
this can evolve and be "Friend class"
Friend class:
-just like friend functions, we can also have a friend class.
-friend class can access private and protected members of the class to which it is a friend.
-note that the friendship is not mutual unless we make it so.
-the friendship of the class is not inherited. This means that as class B is a friend 
of class A, it will not be a friend of the subclasses of class A.
see printclass before the main and the person class.
*/
	Person x1("Momo_1", "Male_1", 26);
	printclass pc1;
	pc1.print_1(x1);




	return 0;
}
