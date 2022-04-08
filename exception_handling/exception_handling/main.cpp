#include <iostream>
using namespace std;


int main()
{

/*
Introduction: 
Exceptions:
	-Indicate problems that occur during a program's execution
	-A c++ exception is a response to an exceptional circumstance that arises while 
	a program is running, such as an attempt to divide by zero
Exception handling:
	-Can resolve exceptions 
		-Allow a program to continue executing or 
		-notify the user of the problem and 
		-terminate the program in a controlled manner
	-Makes programs robust and fault-tolerant
	-An exception is a class
		-Usually derived from one of the system's exception base classes
	-Exception Class is the standard C++ base class for all exceptions
	-Provides derived classes with virtual functions what()
		-Returns the exception's stored error message
	-If an exceptional or error situation occurs, program throws an object of that class.
	-Exceptions provide a way to transfer control from one part of a program to another. three
	keywords: try , catch , throw are used.
		-try : A try block identifies a block of code for which particular exceptions will
				be activated. It's followed by one or more catch blocks.
		-throw: A program throws an exception when a problem shows up. This is done using a throw keyword.
		-catch - A program catches an exception with an exception handler at the place in a program where you 
				want to handle the problem. The catch keyword indicates the catching of an exception.

*/

/*
// example 1
	int x = 0, y = 0;
	cout << "Enter Value for X and Y " << endl;
	cin >> x;
	cin >> y;

	try
	{
		if (y == 0)
			throw exception();
		cout << x / y << endl;
	}
	catch (exception e)
	{
		cout << e.what();  // print what is the exception
		cout << "Unhandled exception, Please review your input" << endl;
		
	}
	cout << "The program continued" << endl;
	cout << x + y + 100 << endl;
*/

/*
// example 2
	int x = 0, y = 0;
	cout << "Enter Value for X and Y " << endl;
	cin >> x;
	cin >> y;

	try
	{
		if (y == 0)
			throw (500);  // But I should handle it right !
		cout << x / y << endl;
	}
	catch (int e)
	{
		cout << e << endl;
		cout << " Division by Zero Exception" << endl;
		cout << "Y must be other than zero"<< endl;

	}
	cout << "The program continued" << endl;
	cout << x + y + 100 << endl;
*/

/*
// example 3
	int x = 0, y = 0;
	cout << "Enter Value for X and Y " << endl;
	cin >> x;
	cin >> y;

	try
	{
		if (x < 30)  // it will catch the errors by order 
			throw "x exception";
		if (y == 0)
			throw (500);  // But I should handle it right !
		cout << x / y << endl;
	}
	catch (int e)
	{
		cout << e << endl;
		cout << " Division by Zero Exception" << endl;
		cout << "Y must be other than zero" << endl;

	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "X must be greater than 30" << endl;

	}

	cout << "The program continued" << endl;
	cout << x + y + 100 << endl;

*/

	// example 3
	int x = 0, y = 0;
	cout << "Enter Value for X and Y " << endl;
	cin >> x;
	cin >> y;

	try
	{
		if (x < 30)  // it will catch the errors by order 
			throw "x exception";
		if (y == 0)
			throw (500);  // But I should handle it right !
		cout << x / y << endl;
	}
	catch (...)  // general catch block. in case I don't know or I didn't do enough analysis of kinds of errors.
	{
		cout << "Unhandled Exception" << endl;
		cout << "Contact the system admin" << endl;
	}


	cout << "The program continued" << endl;
	cout << x + y + 100 << endl;



	return 0;
}
