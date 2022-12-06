#pragma once
#include <iostream>
#include <string.h>
using namespace std;
enum EventType { Movie, Concert, Football, Workshop, Theater, Other };
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
	Event(int ID) : eventID(ID), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << "Calling the wolf alone" << endl;
	}



	// Constructor with all parameters
	Event(int eventID, const char* eventName, const char* date_time, int TicketsAmount, EventType type, bool hasSponsor, int duration) :eventID(eventID), type(type), hasSponsor(hasSponsor)
	{
		this->setEventName(eventName);
		this->setDateAndTime(date_time);
		this->setTicketsAmount(TicketsAmount);
		this->setDuration(duration);

	}
	// COPY CONSTRUCTOR
	Event(const Event& copy) : eventID(copy.eventID), type(copy.type), hasSponsor(copy.hasSponsor)
	{
		this->setEventName(copy.eventName);
		this->setDateAndTime(copy.date_time);
		this->setTicketsAmount(copy.total_amount_of_tickets_available);
		this->setDuration(copy.duration);
	}
	// = Operator

	Event& operator= (const Event& event)
	{
		this->setEventName(event.eventName);
		this->setDateAndTime(event.date_time);
		this->setTicketsAmount(event.total_amount_of_tickets_available);
		this->setDuration(event.duration);
		this->hasSponsor = event.hasSponsor;
		this->type = event.type;
		return *this;
	}


	// GETTERs
	const int getEventID() const
	{
		return this->eventID;
	}

	const char* geteventName() const
	{
		return this->eventName;
	}
	const char* getDateandTime()const
	{
		return this->date_time;
	}
	int getTotalAmount() const
	{
		return this->total_amount_of_tickets_available;
	}

	bool getHasSponsor() const
	{
		return this->hasSponsor;
	}
	int getDuration() const
	{
		return this->duration;
	}
	static int getMaxNoTickets()
	{
		return MAX_NUMBER_OF_TICKETS_AVAILABLE;
	}
	EventType getType()
	{
		return this->type;
	}

	// SETTERs
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

	string setEventType()
	{
		switch (this->type)
		{
		case EventType::Concert:
			return "Concert";
		case EventType::Movie:
			return "Movie";
		case EventType::Theater:
			return "Theater";
		case EventType::Football:
			return "Ftoball";
		case EventType::Other:
			return "Other";
		}
	}

	// Overloading the *= operator
	void operator *=(float value)
	{
		this->total_amount_of_tickets_available *= value;
	}

	// Overloading the operator !
	Event& operator! ()
	{
		this->hasSponsor = !this->hasSponsor;
		return *this;
	}
	// 2 Generic methods ///



	// // Ostream/ istream operator //////
	friend ostream& operator<< (ostream& out, const Event& e);
	friend istream& operator>> (istream& in, Event& v);

	~Event()
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
	}

};
int MAX_NUMBER_OF_TICKETS_AVAILABLE = 50000;

ostream& operator<< (ostream& out, const Event& e)
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
istream& operator>>(istream& in, Event& v)
{
	cout << "Introduce the event name : ";
	char aux[100];
	in.getline(aux, 100);
	in.clear();
	delete[] v.eventName;
	v.eventName = new char[strlen(aux) + 1];
	strcpy_s(v.eventName, strlen(aux) + 1, aux);

	cout << "Introduce the date and time : ";
	in >> v.date_time;


	cout << "Introduce the total amount of tickets available: "; in >> v.total_amount_of_tickets_available;
	//cout << "Set the event type : "; in >> v.type;
	cout << " Say if the event has a sponsor "; in >> v.hasSponsor;
	cout << " Insert the duration of the event "; in >> v.duration;
	return in;
}