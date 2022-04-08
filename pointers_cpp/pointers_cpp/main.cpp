#include <iostream>
using namespace std;





void swap(double& x, double& y)
{
	double tmp = x;
	x = y; // access variable by its alias name.
	y = tmp;
};

void swap(double* ptr1, double* ptr2)
{
	double tmp = *ptr1;
	*ptr1 = *ptr2; // de-referencing pointer
	*ptr2 = tmp;
};






int main()  // special function, written once, whereever it is. it will be executed first. No need to the .cpp file to be named main.cpp. it could be anything
{

/*
Pointers:
-each variable in a program occupies a part of the computer's memory, for example
an integer variable occupies 4 bytes of memory.
-The location of the piece of memory used to store a variable is called the address
of that variable.
-An address is some kind of number similar to house numbers in a street that is used to
locate the information stored in that particular variable.
example 
int i;   address of i --> 0x1054     10101011 
						  0x1055     00001111
						  0x1056	 10001000
						  0x1057	 11100011
------------------------------------------------
char c;  address of c --> 0x1058     00111011
						  0x1059	 10111100
						  0x1060	 11001100


- A pointer varialbe is a variable that holds address values 
- Each data type has its own pointer variable, pointer to int, 
pointer to double, pointer to char, ...
-C/C++ uses the address-of operator & to get the adress of an 
variable and contents-of operator * to access the value of the variable
pointed to

int i=17;
int* ptr;  // defines a pointer to an integer variable.
ptr=&i;   // assign the address of x to pointer
cout << *ptr << endl; prints contents of variable i.


example1:
int i=17;          adress start at: 0x1054
int* ptr; // create a address variable of type int. 
ptr=&i;   // store in this address variable, the address of i which is 0x1054
cout << *ptr << endl;  // this de-refrence operator will get what ever value inside the address 0x1054, in this case 17
example2:
int x;
x=12;
int* ptr;
ptr = &x;
cout << *ptr;
*ptr+=5  // this will update the value of x to become 12+5=17
	
*/
	/*
	int x;
	x = 12;
	int* ptr;
	ptr = &x;
	cout << ptr << endl;
	cout << *ptr << endl;
	*ptr += 10;
	cout << x << endl;
	cout << *ptr << endl;
	*/




	// to see what is happening in the memory
	//Debug -> step over (to see what is happening step by step)


	/*
	
	Using a pointer to access the elements of a string
	a string is an array of characters
	char msg[]="Hello";    // in the memory "H","e","l","l","o","\0"
	// the name of the array (msg) is itself a pointer, pointer to the first element in the array.
	// for example at "H", the adress is 3000
	char* ptr;                     
	ptr =msg;   // 3000
	*ptr ='M';  // change the "H" to "M"
	ptr++;      // so now I am pointing to "e"
	//here is the importance of specifying the data type of the 'ptr'
	// so I know how much I will do ++, for example, if it was int, it will jump 4 bytes
	//but here I am specifying char,so It will jump only one byte, and will land on the address that contains "e"
	*ptr='a';  // change "e" to "a"
	// finally we changed "Hello" to "Mallo"
	*/

	/*
	Pointers and Arrays
	-Arrays can be accessed using pointers
	-The name of an array is also a constant pointer to the data type of the elements stored in the array. so this constant pointer can't point to something else other than its array.
	int array[5]={23,5,12,34,17}; // array of 5 ints
	for (int i=0;i<5; i++)
		cout << array[i] << endl; using index to access elements
	for (int i=0;i<5; i++)
		cout << *(array+i) << endl; using pointer to access elements
	// array is of type pointer to integer.	
	*/

/*
	char msg[] = "Hello";
	char* ptr;
	ptr = msg;
	*ptr = 'M';
	ptr++;
	*ptr = 'A';
	ptr += 2;
	*ptr = 'k';
	cout << msg << endl;

	int arr[5] = { 23,5,12,34,17 };
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;
	for (int i = 0; i < 5; i++)
		cout << *(arr + i) << endl;

*/


/*
Pointers as Function Arguments 
- C/C++ offers three different ways to pass arguments to a function 
	-by value: void f(int x);  // the value of variable x in the orginal program stay the same, the function create a copy
	-by reference: void f(int& x); // any update that will happens on the variable x now, will change also x in the original program
	-by pointer: void f(int* x);  // also the same as reference, any update on the varialbe x, will stay and affect the original value of x in the main program.
	
- In passing by value the function obtains only a local copy of the variable, so that
changes to the local variable have no impact on the argument with which the function was invoked.

- In passing by reference and passing by pointer the function manipulates the original variable rather than only a copy of it.

see the function that I wrote before the main.
*/
double a = 3.0;
double b = 5.0;
swap(a, b);  // call by reference to variables a and b
cout << a << b << endl;
cout << "--------------------" << endl;
swap(&a, &b); // call by pointer using the addresses
cout << a << b << endl;

/*
Pointers are a lot used in data structures

*/

	return 0;
}
