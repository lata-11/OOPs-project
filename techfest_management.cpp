#include <bits/stdc++.h>
using namespace std;

class Student
{
protected:
    int id;
    string name;
    string email;

public:
    Student() {}
    ~Student() {}
    void setId()
    {
        cout << "Enter the id of the student:-" << endl;
        cin >> id;
    }
    void setName()
    {
        cout << "Enter the name of the student:-" << endl;
        cin >> name;
    }
    void setEmail()
    {
        cout << "Enter the email-id of the student:-" << endl;
        cin >> email;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }
};

class Logistics : public Student
{
public:
    Logistics(string name) { cout << name << " is managing  logistics." << endl; }
};
class Treasury : public Student
{
public:
    Treasury(string name) { cout << name << " is managing  treasury." << endl; }
};
class Website : public Student
{
public:
    Website(string name) { cout << name << " is managing website." << endl; }
};

class WorkforceMember : public Student
{
private:
    string role;
    string task_assigned;
    bool taskCompleted;

public:
    WorkforceMember()
    {
    }
    void assignRole()
    {
        cout << "Enter the role to be assigned to the particular workforce member(Logistics, treasury or website)" << endl;
        cin >> role;
        if (role == "Logistics")
        {
            string name = this->getName();
            Logistics log1(name);
        }

        if (role == "Treasury")
        {
            string name = this->getName();
            Treasury tres1(name);
        }
        if (role == "website")
        {
            string name = this->getName();
            Website web1(name);
        }
    }
    string getRole()
    {
        return role;
    }
    void performTask()
    {
        cout << this->getName() << " under " << role << " is performing a task." << endl;
        taskCompleted = true;
    }

    void assignTask()
    {
        string task;
        cout << "Enter the task to be assigned:-" << endl;
        getline(cin >> ws, task);
        cout << this->getName() << " has been assigned the task: " << task << endl;
    }

    void markTaskCompleted()
    {
        if (taskCompleted)
        {
            cout << this->getName() << " under " << role << " task has completed the task." << endl;
        }
        else
        {
            cout << this->getName() << " under " << role << " task hasn't completed the task." << endl;
        }
    }
};
class Coordinator : public Student
{
public:
    Coordinator() {}
    vector<WorkforceMember> workforce;
    void assignTaskToWorkforce()
    {
        cout << this->getName() << " is assigning a task to the workforce." << endl;
        for (auto &member : workforce)
        {
            member.performTask();
        }
    }

    void reportToCoreMember()
    {
        cout << this->getName() << " is reporting to a core member." << endl;
    }

    void addWorkforceMember(WorkforceMember w1)
    {
        if (w1.getRole() == "Logistics")
        {

            workforce.push_back(w1);
        }
        else if (w1.getRole() == "Treasury")
        {

            workforce.push_back(w1);
        }
        else if (w1.getRole() == "Website")
        {

            workforce.push_back(w1);
        }

        cout << "Added workforce member: " << w1.getName() << " to " << this->getName() << endl;
    }
};

class CoreMember : public Student
{
private:
    string specialization;
    vector<Coordinator *> coordinators;

public:
    CoreMember()
    {
    }

    void setSpecialization()
    {
        cout << "Enter the specialization of the core member(Director, Producer, Outreach coordinator):-" << endl;
        cin >> specialization;
    }
    string getSpecialization()
    {
        return specialization;
    }

    vector<Coordinator *> getCoordinators()
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
/* Event class declaration */
class Event
{
private:
    int eventId;
    string eventName;

public:
    Event(int _eventId, const string &_eventName) : eventId(_eventId), eventName(_eventName) {}

    int getEventId() 
    {
        return eventId;
    }

    string getEventName()
    {
        return eventName;
    }
};

/*Participant class*/
class Participant : public Student
{
private:
    
    vector<Event *> eventsParticipated;

public:
    

  Participant() {}

    int getId() 
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    vector<Event *> getEventsParticipated() 
    {
        return eventsParticipated;
    }

    void participateInEvent(Event *event)
    {
        eventsParticipated.push_back(event);
    }

    void withdrawFromEvent(Event *event)
    {

        for (auto it = eventsParticipated.begin(); it != eventsParticipated.end(); ++it)
        {

            if (*it == event)
            {
                eventsParticipated.erase(it);
                cout << getName() << " withdrew from event: " << event->getEventName() << endl;
                return;
            }
        }

        cout << getName() << " is not participating in event: " << event->getEventName() << endl;
    }
};
int main()
{

    /* Student class illustration */
    // Student student1;
    // student1.setId();
    // student1.setName();
    // student1.setEmail();

    // // Print student information
    // cout << "Student class illutration: ---------->" << endl;
    // cout << "Student ID: " << student1.getId() << endl;
    // cout << "Student Name: " << student1.getName() << endl;
    // cout << "Student Email: " << student1.getEmail() << endl;
    // cout << endl;

    /*cout << "Workforce and coordinator class illutration: ---------->" << endl;
     cout << endl;
     cout << "Give details of workforce---->" << endl;
     cout << endl;
     WorkforceMember wf1;
     wf1.setId();
     wf1.setName();
     wf1.setEmail();
     wf1.assignRole();
     wf1.assignTask();

     WorkforceMember wf2;
     wf2.setId();
     wf2.setName();
     wf2.setEmail();
     wf2.assignRole();
     wf2.assignTask();
     cout << endl;
     cout << "Now give the details of co-ordinator: " << endl;
     cout << endl;
     Coordinator c1;
     c1.setId();
     c1.setName();
     c1.setEmail();
     c1.addWorkforceMember(wf1);
     c1.addWorkforceMember(wf2);
     c1.reportToCoreMember();
     c1.assignTaskToWorkforce(); */

    /* Core member class illustration */

    // cout << "Core-member class illutration: ---------->" << endl;
    // cout << endl;
    // CoreMember coreMember;
    // coreMember.setSpecialization();
    // coreMember.addCoordinator(&c1);
    // cout << "Coordinator " << c1.getName() << " is under " << coreMember.getSpecialization() << endl;
    // cout << endl;
    // cout << "Now performing removal of coordinator option:----------->" << endl;
    // cout << endl;
    // cout << "Coordinators before removal: " << coreMember.getCoordinators().size() << std::endl;

    // coreMember.removeCoordinator(&c1);
    // cout << endl;
    // cout << "Coordinators after removal: " << coreMember.getCoordinators().size() << std::endl;
    // cout << endl;

    // /*Participant and event class illustration*/

    Event *event1 = new Event(1, "Coding Contest");
    Event *event2 = new Event(2, "Robotics Competition");

    Participant *participant1 = new Participant();
    participant1->setId();
    participant1->setName();
    participant1->setEmail();
    participant1->participateInEvent(event1);
    participant1->participateInEvent(event2);

    cout<<"Participant and event class illutration: ---------->"<<endl;
    cout<<endl;
    cout << "Events participated by " << participant1->getName() << ": " << endl;
    for (const auto &event : participant1->getEventsParticipated())
    {
        cout << event->getEventName() << endl;
    }

    participant1->withdrawFromEvent(event1);

    cout<<endl;
    cout << "Events participated by " << participant1->getName() << " after withdrawal: " << endl;
    for (const auto &event : participant1->getEventsParticipated())
    {
        cout << event->getEventName() << endl;
    }
    cout<<endl;
    delete event1;
    delete event2;
    delete participant1;

    return 0;
}
