#include <iostream>
#include <string.h>
using namespace std;

enum EventType {Movie, Concert, Football, Workshop, Theatre, Other };
class Event
{
	const int eventID;
	char* eventName;
	int total_amount_of_tickets_available; 
	EventType type;
	bool hasSponsor;
	static int MIN_NR_TICKETS_BOUGHT; // the minimum number of tickets to be bought in order to be able to go to the event

};
int MIN_NR_TICKETS_BOUGHT = 1;

enum LocationArea {FrontSeats, MiddleSeats, UpperSeats};
class Location
{
	const int locationID;
	string* city; // The city the event is located
	char* building_type; // The place in the city where event will have place
	int* nr_seats; // number of seats per row
	int nr_rows; 
	int seat_number;
	LocationArea area;
	static int maximum_number_of_seat;

};
int maximum_number_of_seats = 10000;

enum ParticipantCategory {Child, Student, Adult, Senior};

class Participant
{
	const int participantID;
	string name;
	int age;
	bool over18;
	ParticipantCategory category;

};

enum TicketType { General, VIP };

class Ticket
{
	const int TicketID ;
	bool validTicket; // is it valid or not
	int nr_of_agents; // number of agents that worked to make the ticket
	float price;
	TicketType type;
};



int main ()
{
	return 0;
}