#pragma once
#include <iostream>
using namespace std;


class Shape
{
	string color;
public:
	Shape(string c)
	{
		color = c;
	}

	virtual int area()  // I worte virutal to tell the compiler that this method will be overriding later in the derived classes. 
	{
		cout << "Parent class area: " << endl;
		return 0;
	}
	virtual void draw()
	{
		cout << " Draw Parent Shape in " << color << " Color " << endl;
	}
 virtual void erase()
{
	 cout << "Erase The Parent Shape " << endl;
}
};


// abstract class
class Shape_pure
{
	string color;
public: 
	virtual int area() = 0;  // pure virtual function 
	// the important things is to put "=0". In this case, the class become abstract 
	//and I cannot initiate instances from it. 
	// you will get an error if you do Shape_pure s; in the main.
	// another things is that ,all the derived classes should override for those methods.
	virtual void draw() = 0;
	virtual void erase() = 0;

	//final classifier
	virtual void display() final // final means that no one can override this function in the derived classes.
	{
		cout << "This is shape pure";
	};
};



class Rectangle : public Shape
{
private:
	int length;
	int width;
public:
	Rectangle(int l, int w, string c) :Shape(c)
	{
		length = l;
		width = w;
	}
	 int area()  // I worte virutal to tell the compiler that this method will be overriding later in the derived classes. 
	{
		cout << "Rectangle class area: " << length * width <<  endl;
		return length*width;
	}
	 void draw()
	{
		cout << " Draw Rectangle " << endl;
	}
	 void erase()
	{
		cout << "Erase The Rectangle Shape " << endl;
	}

};

class Circle : public Shape
{
private:
	int radius;
public:
	Circle(int r, string c) :Shape(c)
	{
		radius = r;
	}

	int area()  // I worte virutal to tell the compiler that this method will be overriding later in the derived classes. 
	{
		cout << "Circle class area: " << 3.14*(radius*radius) << endl;
		return  (3.14 * radius * radius);
	}

	void draw()
	{
		cout << " Draw Circle " << endl;
	}
	void erase()
	{
		cout << "Erase The Circle Shape " << endl;
	}

};