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

/* Coordinator class declaration */
class Coordinator;

/* Core member class */
class CoreMember : protected Student
{
private:
    int id;
    string name;
    string specialization;
    vector<Coordinator *> coordinators;

public:
    CoreMember(int _id, const string &_name, const string &_specialization)
        : Student(_id, _name, ""), id(_id), name(_name), specialization(_specialization) {}

    int getId() const
    {
        return id;
    }

    const string &getName() const
    {
        return name;
    }

    const string &getSpecialization() const
    {
        return specialization;
    }

    const vector<Coordinator *> &getCoordinators() const
    {
        return coordinators;
    }

    void addCoordinator(Coordinator *coordinator)
    {
        coordinators.push_back(coordinator);
    }

    void removeCoordinator(Coordinator *coordinator)
    {
        for (auto it = coordinators.begin(); it != coordinators.end(); ++it)
        {
            if (*it == coordinator)
            {
                coordinators.erase(it);
                break;
            }
        }
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

    /* Core member class illustration */

    CoreMember coreMember(1, "John Doe", "Programming");

    /* This will work after implementation of Coordinator class */
    /*Coordinator coordinator1;
    Coordinator coordinator2;

    coreMember.addCoordinator(&coordinator1);
    coreMember.addCoordinator(&coordinator2);

    cout << "Coordinators before removal: " << coreMember.getCoordinators().size() << std::endl;

    coreMember.removeCoordinator(&coordinator1);

    cout << "Coordinators after removal: " << coreMember.getCoordinators().size() << std::endl;*/

    return 0;
}
