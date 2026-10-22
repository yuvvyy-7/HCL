//Q.4. Define a struct Student with attributes id, name, and gpa. Create an array of three
// Student records, populate them from user input, and output the details of the student
// with the highest GPA.



#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    double gpa;
};

int main() {
const int n = 3;
Student classroom[n];

for(int i = 0; i < n; i++) {
    cout << "Enter details of Student " << i+1 << ": \n";
    cout << "Id: ";
    cin >> classroom[i].id;
    cout << "\n";
    cout << "Name: ";
    cin >> classroom[i].name;
    cout << "\n";
    cout << "GPA: ";
    cin >> classroom[i].gpa;
    cout << "\n";
}

double maxGpa = 0;
int index;

for(int i = 0; i < n; i++) {
    if(classroom[i].gpa > maxGpa) {
        maxGpa = classroom[i].gpa;
        index = i;
    }
}


cout << "\n====== Student with highest GPA ====== \n";
cout << "Name: " << classroom[index].name << endl;
cout << "Id: " << classroom[index].id << endl;
cout << "GPA: " << classroom[index].gpa << endl;

return 0;
}