#include <iostream>
#include <string.h>
using namespace std;

enum EventType {Movie, Concert, Football, Workshop, Theatre, Other };
class Event
{
	
	string location;
	char* eventName;
	int nr_of_tickets_available; 
	float* ticket_price;
	EventType type;
	bool IsOnline;

};
class Location
{
	string city; // The city the event is located
	int* nr_seats_available; // depend on the number of rows the location has
	int nr_rows; 

};

class Participant
{

};

enum TicketType { VIP, FrontSeat, MiddleSeat, UpperSeat };

class Ticket
{
	
};



int main ()
{
	return 0;
}