#include <bits/stdc++.h>
using namespace std;

/* Student class */
class Student
{
protected:
    int id;
    string name;
    string email;

public:
    Student(int _id, const string &_name, const string &_email) : id(_id), name(_name), email(_email) {}

    int getId() const
    {
        return id;
    }

    const string &getName() const
    {
        return name;
    }

    const string &getEmail() const
    {
        return email;
    }
};

int main()
{

    /* Student class illustration */
    Student *student1 = new Student(1, "Lata", "imlata1111@gmail.com");

    // Print student information
    cout << "Student ID: " << student1->getId() << endl;
    cout << "Student Name: " << student1->getName() << endl;
    cout << "Student Email: " << student1->getEmail() << endl;

    delete student1;

    return 0;
}
