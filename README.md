# OOPs-project

## Problem Statement
Develop a comprehensive Tech Fest Management system in C++ using Object-Oriented principles. The system will model a student-run event, with a clear hierarchy of responsibilities:

Senior students act as Core Members.

Core Members oversee Coordinators.

Each Coordinator is assigned to a specific department (Logistics, Website, Treasury), where they manage tasks.

The system must support various types of Events, each with a limited number of tickets. Student Participants can browse and book tickets for these events.

The core technical challenges are:

### Concurrent Booking: The ticket booking process must be highly concurrent. The system must safely handle numerous simultaneous registration requests for the same event without overbooking, using thread-safe mechanisms.

### Thread-Safe Financial Transactions: To add a layer of realism, the Treasury department will manage a central fest budget. Each event registration will trigger a financial transaction (e.g., adding ticket revenue), and event setup will have associated costs. All operations modifying the central budget must be atomic and thread-safe to prevent data corruption and ensure the financial records are always consistent, even when thousands of transactions occur concurrently.

The final main function should act as a control interface, allowing a user to display information (like the names of coordinators and core members, event status) and trigger actions (like registering for events).