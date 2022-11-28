#include <iostream>
#include <string.h>
using namespace std;

enum EventType {Movie, Concert, Football, Workshop, Theatre, Other };
class Event
{
private:
	const int eventID;
	char* eventName;
	char date_time[150];
	int total_amount_of_tickets_available; 
	EventType type;
	bool hasSponsor;
	int duration; // how much time the event will take place in minutes
	static int nrEveniment; 
public:
	// Default constructor
	Event() : eventID(++nrEveniment), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other)
	{

	}
};
int nrEveniment=0;

enum Areas {FrontSeats, MiddleSeats, UpperSeats};
class Location
{
private:
	const int locationID;
	string* city; // The city the event is located
	char* building_type; // The place in the city where event will have place
	int* nr_seats; // number of seats per row
	int nr_rows; 
	int seat_number;
	Areas area;
	static int maximum_number_of_seat;
public:


};
int maximum_number_of_seats = 10000;

enum ParticipantCategory {Child, Student, Adult, Senior};

class Participant
{
private:
	const int participantID;
	string* name;
	int age;
	bool over18;
	ParticipantCategory category;
	int nr_of_events_attended;
	static int nrParticipants;
public:
	Participant() : participantID(++nrParticipants)
	{

	}

};
int nrParticipants = 0;

enum TicketType { General, VIP };

class Ticket
{
private:
	const int TicketID ;
	bool IsValid; // is it valid or not ( 
	int nr_of_agents; // number of agents that worked to make the ticket
	float price;
	TicketType type;
	static int ticketNr;
public:

	Ticket(): TicketID(++ticketNr)
	{

	}
};
int ticketNr = 1;


int main ()
{
	return 0;
}