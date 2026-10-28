#include <iostream>
using namespace std;

struct student
{
    string dept;
    string section;
    int marks;
};


int main() {
    // struct 
    // {
    //     string dept;
    //     string section;
    //     int marks;
    // }std1, std2 ; Anonymous struct

    student std1;

    std1.dept = "CSE";
    std1.marks = 97;
    std1.section = "B";

    cout << std1.marks << endl;

    student std2;

    std2.dept = "BCA";
    std2.marks = 76;
    std2.section = "A";

    cout << std2.dept << endl;
    
}