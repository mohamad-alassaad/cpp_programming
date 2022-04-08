////////////////////////////////////   OPP course //////////////////////////////////////


1-intro
oop is based on programming paradigm "Objects"
object is comprised of:  Object-> Data and Operations()

2-class and objects
example: class Student --> we can create student1, student2,....
if you want to in the future add attribute or functions to the class student, it will be easy. 

3-create your first class
public class Rectangle 
{ 
	private:                  // to change these values, use public methods, in that cases, you can put your conditions on the changes, the user can not change the values as he wishes, but by conditions 
		float length;
		float width;
	public:
		void setLength(float len)
			{
			if (len >=0)
				{length=len;}
			else
				{cout<< "Error, Please enter positive value";}
			}

}