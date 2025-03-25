#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int marks;
    int rollno;
    Student(string n, int m, int r){ // constructer 
        name = n;
        marks = m;
        rollno = r;
    }
};

void print(Student s){ // pass classes in the function
    // this is pass by value not pass by reference 
    // Student &s this is how you pass it by reference 
    cout << s.name << " ";
    cout << s.marks << " ";
    cout << s.rollno << " ";
}


int main(){

    return 0;
}