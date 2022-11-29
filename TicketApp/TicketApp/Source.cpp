#include <iostream>
#include <string.h>
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
	static int MAX_NUMBER_OF_TICKETS_AVAILABLE; 
public:


	// Default constructor
	Event() : eventID(0), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << " Calling the majestic constructor" << endl;
	}

	// Constructor with one parameter 
	Event( int eventID): eventID(eventID), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << "Calling the wolf alone" << endl;
	}
	
 

	// Constructor with all parameters
	Event( int eventID, const char* eventName, const char* date_time, int TicketsAmount, EventType type, bool hasSponsor, int duration):eventID(eventID), type(type), hasSponsor(true)
	{
		this->setEventName(eventName);
		this->setDateAndTime(date_time);
		this->setTicketsAmount(TicketsAmount);
		this->setDuration(duration);

	}

	void setEventName(const char* eventNameCopy)
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
		this->eventName = new char[strlen(eventNameCopy) + 1];
		strcpy_s(this->eventName, strlen(eventNameCopy) + 1, eventNameCopy);
	}
	void setDateAndTime(const char* newDate_Time)
	{
		int DateAndTimeAvailable = sizeof(this->date_time);
		if (strlen(newDate_Time) + 1 > DateAndTimeAvailable)
		{
			throw exception("Date and Time are too long");
		}

		strcpy_s(this->date_time, strlen(newDate_Time) + 1, newDate_Time);
	}
	void setTicketsAmount(int TicketsAmount)
	{
	/*	if (this->total_amount_of_tickets_available > Event::MAX_NUMBER_OF_TICKETS_AVAILABLE)
		{
			throw exception(" There are no more available tickets");
		}*/
		this->total_amount_of_tickets_available = TicketsAmount;
	}
	
	void setDuration(int newDuration)
	{
		if (this->duration < 0)
		{
			throw " Not enough time for a decent event";
		}
		this->duration = newDuration;
	}

	friend ostream& operator<< (ostream& out, Event& e)
	{
		out << "Event ID is " << e.eventID << " ," << endl
			<< "Event Name : " << e.eventName << ", " << endl
			<< " Date and time : " << e.date_time << " , " << endl 
			<< "Total amount of tickets available : " << e.total_amount_of_tickets_available << " , " << endl
			<< " Event type is : " << e.type << " , " << endl
			<< " The event has a sponsor " << e.hasSponsor << " , " << endl
			<< " The duration of the event is " << e.duration << " minutes." << endl;
	
		return out;
		
	}
	friend istream& operator >> (istream& in, Event& v)
	{
		cout << "Introduce the event name : ";
		char aux[100];
		in.getline(aux, 100);
		in.clear();
		delete[] v.eventName;
		v.eventName = new char[strlen(aux) + 1];
		strcpy_s(v.eventName,strlen(aux)+1, aux);

		cout << "Introduce the date and time : ";
		char fax[150];
		in.ignore();
		in.getline(fax, 150);
		in.clear();
		delete[] v.date_time;
		
		strcpy_s(v.date_time, strlen(fax) + 1, fax);


		cout << "Introduce the total amount of tickets available: "; in >> v.total_amount_of_tickets_available;
		//cout << "Set the event type : "; in >> v.type;
		cout << " Say if the event has a sponsor "; in >> v.hasSponsor;
		cout << " Insert the duration of the event "; in >> v.duration;
		return in;
	}

};
int MAX_NUMBER_OF_TICKETS_AVAILABLE =10000;
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
	static int MIN_NAME_SIZE; 
public:
	// Default Constructor
	Participant() : participantID(0), name(nullptr), age(0), over18(false), category(Child), nr_of_events_attended(0)
	{

	}
	// Constructor with one parameter
	

};
int MIN_NAME_SIZE= 2;
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
	Event l2 (10);
	Event mecifotbal(123, " Real Madrid vs Barcelona", "15 decembrie 2022, ora 22:00", 10000, EventType::Football, true, 90);
	cout << mecifotbal;
	return 0;

}