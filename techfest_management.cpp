#include <bits/stdc++.h>
using namespace std;

/* Student class */
class Student {
protected:
    int id;
    string name;

public:
    Student(int _id, const std::string& _name) : id(_id), name(_name) {}

    int getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }
};

int main() {
    
    /* Student class illustration */
    Student *student1 = new Student(1, "Lata");

    // Print student information
    cout << "Student ID: " << student1->getId() << endl;
    cout << "Student Name: " << student1->getName() << endl;

    delete student1;
    
    return 0;
}
