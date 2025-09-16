#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

// A central, thread-safe class to manage the fest's budget.
class Treasury
{
private:
    atomic<double> budget; // Atomic for thread-safe financial operations.

    Treasury() : budget(1000.0) {} // Initial budget of 1000.0

public:
    static Treasury &getInstance()
    {
        static Treasury instance;
        return instance;
    }

    Treasury(const Treasury &) = delete;
    void operator=(const Treasury &) = delete;

    void processTransaction(double amount)
    {
        budget = budget + amount;
    }

    double getBudget() const
    {
        return budget;
    }
};

class Student
{
protected:
    int id;
    string name;

public:
    Student(int id, const string &name) : id(id), name(name) {}
    virtual ~Student() = default;
    int getId() const { return id; }
    string getName() const { return name; }
};

class Event
{
public:
    int id;
    string name;
    int seat_limit;
    double ticket_price;
    vector<int> registered_participant_ids;

    Event(int id, const string &name, int limit, double price)
        : id(id), name(name), seat_limit(limit), ticket_price(price) {}

    bool isFull() const
    {
        return registered_participant_ids.size() >= seat_limit;
    }
};

// Role-Based Classes 
class Participant : public Student
{
public:
    Participant(int id, const string &name) : Student(id, name) {}
};
class WorkforceMember : public Student
{
public:
    WorkforceMember(int id, const string &name) : Student(id, name) {}
};
class Coordinator : public WorkforceMember
{
public:
    Coordinator(int id, const string &name) : WorkforceMember(id, name) {}
};
class CoreMember : public WorkforceMember
{
public:
    CoreMember(int id, const string &name) : WorkforceMember(id, name) {}
};

// Central management class for the entire fest.
class TechFest
{
private:
    map<int, shared_ptr<Event>> events;
    map<int, shared_ptr<Participant>> participants;
    vector<shared_ptr<CoreMember>> core_members;
    mutex registration_mutex; // A lock to protect the registration logic

    TechFest() {}

public:
    static TechFest &getInstance()
    {
        static TechFest instance;
        return instance;
    }

    TechFest(const TechFest &) = delete;
    void operator=(const TechFest &) = delete;

    // Setup and Display 
    void addCoreMember(int id, const string &name)
    {
        core_members.push_back(make_shared<CoreMember>(id, name));
    }
    void addParticipant(int id, const string &name)
    {
        participants[id] = make_shared<Participant>(id, name);
    }
    void createEvent(int id, const string &name, int seats, double price)
    {
        events[id] = make_shared<Event>(id, name, seats, price);
    }
    void listCoreMembers() const
    {
        cout << "## Core Members ##" << endl;
        for (const auto &member : core_members)
        {
            cout << "- " << member->getName() << endl;
        }
    }
    void listEvents() const
    {
        cout << "\n## Event Status ##" << endl;
        for (const auto &pair : events)
        {
            cout << "- " << pair.second->name << " | Registered: "
                 << pair.second->registered_participant_ids.size() << "/" << pair.second->seat_limit << endl;
        }
    }

    //  Core Concurrent Functionality 
    void registerForEvent(int participant_id, int event_id)
    {
        lock_guard<mutex> lock(registration_mutex);

        if (!events.count(event_id) || !participants.count(participant_id))
            return;

        auto event = events[event_id];
        auto participant = participants[participant_id];

        if (!event->isFull())
        {
            event->registered_participant_ids.push_back(participant_id);
            // Process the financial transaction safely.
            Treasury::getInstance().processTransaction(event->ticket_price);
            cout << "[Success] " << participant->getName() << " registered for " << event->name << "." << endl;
        }
        else
        {
            cout << "[Failure] " << participant->getName() << " could not register for " << event->name << " (full)." << endl;
        }
    }
};

int main()
{
    TechFest &fest = TechFest::getInstance();
    Treasury &treasury = Treasury::getInstance();

    // 1. Setup the fest
    fest.addCoreMember(101, "Aarav (Core)");
    fest.addParticipant(201, "Lata");
    fest.addParticipant(202, "Vikram");
    fest.addParticipant(203, "Nisha");
    fest.createEvent(901, "CodeSprint Challenge", 2, 50.0); // 2 seats, 50.0 each

    // 2. Display initial state
    fest.listCoreMembers();
    fest.listEvents();
    cout << "Initial Budget: " << treasury.getBudget() << endl;

    // 3. Demonstrate concurrent registration and transactions
    cout << "\n--- Simulating Concurrent Registrations ---" << endl;
    vector<thread> threads;

    // Using push_back to add threads to the vector
    threads.push_back(thread(&TechFest::registerForEvent, &fest, 201, 901)); // Lata
    threads.push_back(thread(&TechFest::registerForEvent, &fest, 202, 901)); // Vikram
    threads.push_back(thread(&TechFest::registerForEvent, &fest, 203, 901)); // Nisha (should fail)

    for (auto &th : threads)
    {
        th.join();
    }

    // 4. Display final state
    fest.listEvents();
    cout << "Final Budget: " << treasury.getBudget() << endl; // Should be 1000 + 50 + 50 = 1100

    return 0;
}