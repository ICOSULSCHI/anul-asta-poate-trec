#include <iostream>
#include <string.h>
using namespace std;

enum EventType {Movie, Concert, Football, Workshop, Theatre, Other };
class Event
{
	
	string location;
	char* eventName;
	int nr_of_tickets_available; 
	int* nr_of_seats;
	EventType type;
	bool hasSponsor;
	static int MIN_NR_TICKETS_BOUGHT; // the minimum number of tickets to be bought in order the event to go on

};
class Location
{
	const int locationID;
	string city; // The city the event is located
	int* nr_seats_available; // depend on the number of rows the location has
	int nr_rows; 

};

class Participant
{
	const int participantID;
	string name;
	int age;
	bool over18;

};

enum TicketType { VIP, FrontSeat, MiddleSeat, UpperSeat };

class Ticket
{
	const int TicketID ;
	bool boughtOnline; // is it bought online or not
	int nr_of_agents; // number of agents that worked to make the ticket
	float price;
};



int main ()
{
	return 0;
}