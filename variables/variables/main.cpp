#include <iostream>
using namespace std;


/*
Scope of variable:
	scope is the context within a program in which a variable is valid and can be used.
Local variable: 
	declared within a function (or block)
	can be accessible only within the function or from declaration to the end of the block.
	within nested blocks if no variable with same name exists.
	int sum(int x,int y)   // within a function
		{
		int result;  //local
		result =x+y;
		return result 
		} // outside sum, the variable result doesn't exist

	int main()
		{
			{  // this is block
				int x; //local 
			} // x doesn't exist outside this scope
		}

global variable:
	declared outside of every function definition 
	can be accessed from any function that has no local variables with the same 
	name. In case the function has a local variable with the same name as the global variable. 
	
	int z;  //globale variable. you can use it everywhere (function or block)
	int main()
	{
		{
		}
	}
	int sum(int x,int y)
	{
	}
*/

/*
Scope of a variable 
Using global variables causes side effects
	-a function that uses global variables is not independent
	-If more than one function uses the same global variable and something goes wrong 
	-It is difficult to find what wen wrong and where Problems caused in one area of the program may appear to be from another area.
	-To prevent the global variable to be modified use the Const Keyword.
		Const float pi=3.14


int x = 100;

int main()
{
	int x = 10;
	int y = 50;
	int z = 60;

	cout << "Global X: " << ::x<< " Called from main fuction" << endl; // globle variable Using scope resolution operator
	cout << "Main X: " << x << endl;  // local variable (inside the main).
	cout << "Main y: " << y << endl;
	cout << "Main z: " << z << endl;

	{
		int z, x;
		z = 100;
		x = 250;
		cout << "inner block X: " << x << endl;  // local variable (inside the block)
		cout << "Global X: " << ::x << " Called from a block inside the main fuction" << endl;
		// I can't call the x=10 (in the main)
		cout << "Main y: " << y << endl;
		cout << "Main z: " << z << endl;
	}
};

*/

/*
Static and Automatic Variables 
Automatic variable:
	-memory is allocated at block entry and de-allocated at block exit.
	-by default, variables declared within a block are automatic variables.
	// so the idea that the declaration of any varialbe in a function or block , it will be deleted at the end of the function/block. 
	//If I want to keep the values or variables outside the function/block, use the static.


void issue_ticket(int flight_no, string pname)
{
	static int ticket_no = 0;  // so the value will stay in memory even after the function is closed
	cout << "\t \t*************************** \n";
	cout << "Flight No: " << flight_no << "\n";
	cout << "Ticket No: " << ++ticket_no << "\n";
	cout << "Issued For: " << pname << "\n";
}

int main()
{
	string name;
	cout << "Enter your name as written in your passport \n";
	cin >> name;
	issue_ticket(125, name);
	cout << "Enter your name as written in your passport \n";
	cin >> name;
	issue_ticket(125, name);
	cout << "Enter your name as written in your passport \n";
	cin >> name;
	issue_ticket(125, name);
}
*/


/*
Array: is a collection of fixed number of elements, wherein all of elements have same data types.
Array Basics: 
	-Consecutive group of memory locations that all have the same type.
	-The collection of data is indexed, or numbered, and at starts at 0 and 
	the highest element index is one less than the total number of elements in the array.
One-dimentional array
	-elements are arranged in a list form.
Multi-dimensional array: 
	-elements are arranged in tabular form.

-Syntax for declaring a one-dimensional array:
	Datatype ArrayName [ArraySize];
-ArraySize: any positive integer or constant variable.
			example:
					int num[5];
			example: const int size=5;
						int num[size];
-Accessing array Elements
		Arrayname[element_index]; // starts at 0
		example:
				int list[10];
				list[5]=34;
				cout << list[5];

Array Initialization
	-Consider the declaration
			int list[10];  // array of size 10
	-After declaring the array you can use the For..loop to initialize it with values submmited by the user.
	-Using for loops to access array elements:
			for (int i=0;i<10;i++)
				//process list[i]
	-example:
			for (int i=0;i<10;i++)
				cin >> list[i];

	-Arrays can be initialized during declaration
			-In this case, it is not necessary to specify the size of the array 
				-Size determined by the number of initial values in the braces
			-example 1: int Items[] ={12,32,16,23,45};
			-example 2: int Items[10]={0};  // by default, it will put 0 in all the elements
			-example 2: int Items[10]={5,7,10};  // also I will put zeroes in the non defined values from index 3 to 9
	
	-Copy array to another array (use loop elements)
			int list1 [5]={10,20,30,40,50};
			int list2 [5];
			for (int i=0;i<5;i++)
				list2[i]=list1[i];

Array as Parameter to Function
	-Arrays are passed by reference only
	-The symbol & is not used when declaring an array as a formal parameter  // it will take it directly for the array.
	-The size of the array is usually passed as a parameter to the function
			float calc_Average (float marks [], int size)
			{
			float sum=0;
			for (int i=0; i<size ;i++)
				sum +=marks[i];
			return sum/size;
			}   // this function if it changes here the element of the array, the changes will stay outside the function/block
	-We may add keyword const before array name to Prevent the function from modifying the array elements
			float calc_Average (const float marks [], int size)

	example: Write a program that uses a function to search for an item witin an array 
			bool find_Item(int list[], int searcheditem, int size)
			{
			int indx;
			bool found= false;
			for (indx=0;indx<size;indx++)
				if (list[indx]==searcheditem)
				{
				found=true;
				break;
				}
				return found;
			}
Two Dimensional Array
	-Used when data is provided in a table form.
	-For example, to store 4 Marks for 6 students.
	
	-Two dimensional Array declaration 
		Datatype ArrayName [Rows][Columns];
		example:
			float marks[6][4];
	-Two dimensional Array Initialization 
		-Consider the declaration 
			float marks[6][4];
		-After declaring the array, you can use the For..Loop to initialize it with values submmited by the user.
		-Using 2 nested for loops to access array elements:
			for (int row=0;row<6;row++)
				for (int col=0;col<4;col++)
					cin >> marks[row][col];
		-Two dimensional Arrays can be initialized during declaration 
			example 1: float marks[4][3] ={{20,30,35},
										 {40,45,65},
										 {60,65,75},
										 {80,65,45}}
			example: build a program that build a matrix of 5 rows and 3 columns.
					As the use to enter the values for all the matrix items, 
					print out the sum of all matrix items and print out the sum of the
					diagonal items.	
	-Two dimensional array as a parameter to function 
		-When declaring a two-dimensional array as a formal parameter, you can omit the size 
		of the first dimension, but not the second;
		that is, you must specify the number of columns. 
			void printMatrix(int matrix[][4], int Rows)
			{
			int row, col;
			for(row=0;row<Rows;row++)
			{
				for(col=0;col<4;col++)
					cout << setw(5) <<matrix[row][col];
			cout << "\n";
			}
			
			}

*/

/*
int main()
{
	//Write a program that ask the user to enter 10 Employee salaries
	//and store them, then add a bonus of 10% for each employee and print out
	//the average salary value.

	float sum = 0.0;
	float salaries[10];
	for (int i = 0; i <= 9; i++)
	{
		cout << "Enter salary for employee no " << i + 1 << endl;
		cin >> salaries[i];
	}
	for (int indx = 0; indx <= 9; indx++)
	{
		salaries[indx] += salaries[indx] * 0.10;
	}
	for (int i = 0; i < 10; i++)
	{
		sum += salaries[i];
	}
	cout << "The Average salary is " << sum / 10 << endl;
}
*/


/*
Struct
Struct: Collection of a fixed number of components(members), accessed by name.
	-Members may be of different type.
	-For example: to store a student record which includes different data items like 
	(student_no,Fname,Lname,Total_Marks,GPA,...).
	-Syntax for Defining Struct is:
		Struct struct_name
		{
			Datatype identifier1;
			Datatype identifier2;
			.
			.
			.Datatype identifiern;
		};
	-example: to store an employee data like(emp_no,fname,lname,salary,bonus,net_salary);
	struct employee
	{
	int emp_no;
	string fname;
	string lname;
	float salary;
	float bonus;
	float net_salary;
	};

	-Assignment and comparison 
		-Value of one struct variable can be assigned to another struct variable of the same type using an assignment statement.
		-example:
			employee emp1,emp2;
			emp2=emp1;
		copies the contents of emp1 into emp2;
		-Compare struct variables member-wise
			-No aggregate raltional operations allowed (==,<,>,...) 
		-To compare the values of emp1 and emp2
		if(emp1.emp_no==emp2.emp_no && emp1.fname==emp2.fname&& emp1.salary=emp2.salary)
		{
		}
	-struct variables and functions
		-a struct variable can be passed as a parameter by value or by reference. 
		-a function can return a value of type struct
		struct distance_type
		{
		int feet;
		float inches;
		};
		distance_type Add_distances(distance_type d1,distance_type d2);
		int main()
			{
			}
		distance_type Add_distances(distance_type d1,distance_type d2)
		{
		distance_type result;
		result.feet=d1.feet+ d2.feet;
		result.inches =d1.inches+d2.inches;
		return result;
		}
	-Arrays in structs
		struct Student
		{
		int student_no;
		string name;
		float GPA;
		float marks[3];
		};
		int main()
		{
		Student s1;
		s1.student_no=120;
		s1.sname="MoMo";
		s1.GPA=3.56;
		s1.marks[0]=80;
		s1.marks[1]=70;
		s1.marks[2]=90;
		}
	-Structs in Arrays
		struct employee
		{
		int emp_no;
		string fname;
		string lname;
		float salary;
		float bonus;
		float net_salary;
		};
		int main()
		{
		employee arr[5];
		arr[0].emp_no=12;
		arr[0].fname="MoMO";
		arr[0].lname="that";
		arr[0].salary=3000;
		arr[0].bonus=500;
		arr[0].net_salary=arr[0].salary+arr[0].bonus;
		}
	-structs within a struct
		you can do that of course. 
*/

struct employee
{
int emp_no;
string fname;
string lname;
float salary;
float bonus;
float net_salary;
};

int main()
{
	employee e1, e2;
	e1.emp_no = 10;
	e1.fname = "MOMO";
	e1.lname = "that";
	e1.salary = 3000;
	e1.bonus = 500;
	e1.net_salary = e1.salary + e1.bonus;
}