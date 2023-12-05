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

/* Event class declaration */
class Event
{
private:
    int eventId;
    string eventName;

public:
    Event(int _eventId, const string &_eventName) : eventId(_eventId), eventName(_eventName) {}

    int getEventId() const
    {
        return eventId;
    }

    const string &getEventName() const
    {
        return eventName;
    }
};


/*Participant class*/
class Participant : protected Student
{
private:
    int id;
    string name;
    vector<Event *> eventsParticipated;

public:
    Participant(int _id, const string &_name) : Student(_id, _name, " "), id(_id), name(_name) {}

    int getId() const
    {
        return id;
    }

    const string &getName() const
    {
        return name;
    }

    const vector<Event *> &getEventsParticipated() const
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
    Student *student1 = new Student(1, "Lata", "imlata1111@gmail.com");

    // Print student information
    cout<<"Student class illutration: ---------->"<<endl;
    cout << "Student ID: " << student1->getId() << endl;
    cout << "Student Name: " << student1->getName() << endl;
    cout << "Student Email: " << student1->getEmail() << endl;
    cout<<endl;

    delete student1;

    /* Core member class illustration */

    CoreMember coreMember(1, "John Doe", "Design");

    /* This will work after implementation of Coordinator class */

    /*Coordinator coordinator1;
    Coordinator coordinator2;

    coreMember.addCoordinator(&coordinator1);
    coreMember.addCoordinator(&coordinator2);

    cout << "Coordinators before removal: " << coreMember.getCoordinators().size() << std::endl;

    coreMember.removeCoordinator(&coordinator1);

    cout << "Coordinators after removal: " << coreMember.getCoordinators().size() << std::endl;
    
    delete student1; */

    /*Participant and event class illustration*/

    Event *event1 = new Event(1, "Coding Contest");
    Event *event2 = new Event(2, "Robotics Competition");

    Participant *participant1 = new Participant(101, "John");
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
