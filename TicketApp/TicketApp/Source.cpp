#include <iostream>
#include <string.h>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;

enum EventType {Movie, Concert, Football, Workshop, Theater, Other };
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
	static int MAX_NUMBER_OF_EVENTS_TO_ATTEND_ONE_EVENING; 
public:
	// Default constructor
	Event() : eventID(0), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << " Calling the majestic constructor" << endl;
	}

	// Constructor with one parameter 
	Event( int eventID): eventID(eventID), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << "Calling the alone wolf" << endl;
	}
	// Constructor with all parameters
	Event( int eventID, char* eventName, char date_time[150], int total_amount_of_tickets_available, EventType type, bool hasSponsor, int duration): eventID(eventID)
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName,strlen(eventName)+1, eventName);

		strcpy_s(this->date_time,strlen(date_time)+1, date_time);
		this->total_amount_of_tickets_available = total_amount_of_tickets_available;
		this->type = type;
		this->hasSponsor = hasSponsor;
		this->duration = duration;

	}


};
int MAX_NUMBER_OF_EVENTS_TO_ATTEND_ONE_EVENING =1;
/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////
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
	// Default Constructor
	Location() : locationID(0), city(nullptr), building_type(nullptr), nr_seats(nullptr), nr_rows(0), seat_number(0), area(FrontSeats)
	{
		cout << " Aloha " << endl;
	}
	//Constructor with one parameter 
	Location(const int locationID) : locationID(locationID), city(nullptr), building_type(nullptr), nr_seats(nullptr), nr_rows(0), seat_number(0), area(FrontSeats)
	{
		cout << "Calling the constructor with one parameter" << endl;
	}
};
int maximum_number_of_seats = 10000;

/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////

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
	static int MIN_NR_OF_PART; // minimum number of participants that the event needs to take place
public:
	// Default Constructor
	Participant() : participantID(0), name(nullptr), age(0), over18(false), category(Child), nr_of_events_attended(0)
	{

	}

};
int MIN_NR_OF_PART = 1;
/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////

enum TicketType { General, VIP };

class Ticket
{
private:
	const int TicketID ;
	bool IsValid; // is it valid or not ( 
	int nr_of_agents; // number of agents that worked to make the ticket
	float price;
	TicketType type;
	static int MIN_NUMBER_OF_TICKETS; // that need to be bought in order to be able to attend an event
public:
	// Default constructor
	Ticket(): TicketID(0), IsValid(false), nr_of_agents(0), price(0.0), type(General)
	{

	}
};
int MIN_NUMBER_OF_TICKETS = 1;


int main ()
{
	Event l1;
	Event l2(123);
	Event mecifotbal(123, " Real Madrid vs Barcelona", "15 decembrie 2022, ora 22:00", 10000, EventType::Football, true, 90);
	return 0;
}