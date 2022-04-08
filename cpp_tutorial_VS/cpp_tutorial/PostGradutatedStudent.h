#pragma once
#include "Student.h"
class PostGradutatedStudent :
    public Student
{
private: string research_interest;
public:
    PostGradutatedStudent(string n, string g, float a, int l, float gp, string d, string rarea) :Student(n, g, a, l, gp, d)
    {
        research_interest = rarea;
    }
        void set_research_interest(string rarea)
    {
        research_interest=rarea;
    }
    string get_research_interest()
    {
        return research_interest;
    }

    void display()
    {
        Student::display();
        cout << "The research interests are: " << research_interest << endl;
    }
};

