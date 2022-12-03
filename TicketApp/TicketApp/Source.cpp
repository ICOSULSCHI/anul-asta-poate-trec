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
	Event( int ID): eventID(ID), eventName(nullptr), date_time("Unknown"), total_amount_of_tickets_available(0), type(Other), hasSponsor(false), duration(0)
	{
		cout << "Calling the wolf alone" << endl;
	}
	
 

	// Constructor with all parameters
	Event( int eventID, const char* eventName, const char* date_time, int TicketsAmount, EventType type, bool hasSponsor, int duration):eventID(eventID), type(type), hasSponsor(hasSponsor)
	{
		this->setEventName(eventName);
		this->setDateAndTime(date_time);
		this->setTicketsAmount(TicketsAmount);
		this->setDuration(duration);
		
	}
	// COPY CONSTRUCTOR
	Event (const Event& copy): eventID(copy.eventID), type(copy.type), hasSponsor(copy.hasSponsor)
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
	{ return this->hasSponsor; }
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

	void setEventType(string type)
	{
		int i = 0;
		if (type == "Movie")
		{
			i = 0;
		}
		if (type == "Concert")
		{
			i = 1;
		}
		if (type == "Football")
		{
			i = 2;
		}
		if (type == "Workshop")
		{
			i = 3;
		}
		if (type == "Theater")
		{
			i = 4;
		}
		if (type == "Other")
		{
			i = 5;
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
	

	// // Ostream operator //////
	friend ostream& operator<< (ostream& out, Event& e);
	

	// istream OPERATOR // 
	//friend istream& operator >> (istream& in, Event& v)
	//{
	//	cout << "Introduce the event name : ";
	//	char aux[100];
	//	in.getline(aux, 100);
	//	in.clear();
	//	delete[] v.eventName;
	//	v.eventName = new char[strlen(aux) + 1];
	//	strcpy_s(v.eventName,strlen(aux)+1, aux);

	//	cout << "Introduce the date and time : ";
	//	char fax[150];
	//	/*in.ignore();
	//	in.getline(fax, 150);
	//	in.clear();
	//	delete[] v.date_time;
	//	v.date_time = new char[strlen(fax) + 1];*/
	//	strcpy_s(v.date_time, strlen(fax) + 1, fax);


	//	cout << "Introduce the total amount of tickets available: "; in >> v.total_amount_of_tickets_available;
	//	//cout << "Set the event type : "; in >> v.type;
	//	cout << " Say if the event has a sponsor "; in >> v.hasSponsor;
	//	cout << " Insert the duration of the event "; in >> v.duration;
	//	return in;
	//}
	~Event()
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
	}

};
int MAX_NUMBER_OF_TICKETS_AVAILABLE =10000;

ostream& operator<< (ostream& out, Event& e)
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
/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////
enum Areas {FrontSeats, MiddleSeats, UpperSeats};
class Location
{
private:
	const int locationID;
	string city; // The city the event is located
	char* building_type; // The place in the city where event will have place
	int* nr_seats; // number of seats per row
	int nr_rows; 
	/*int seat_number;*/
	Areas area;
	static int maximum_number_of_seat;
public:
	// Default Constructor
	Location() : locationID(0), city("Unknown"), building_type(nullptr), nr_seats(nullptr), nr_rows(0) /*seat_number(0)*/, area(Areas::FrontSeats)
	{
		cout << " Aloha " << endl;
	}

	//Constructor with one parameter 
	Location(const int locationID) : locationID(locationID), city("Unknown"), building_type(nullptr), nr_seats(nullptr), nr_rows(0), /*seat_number(0)*/ area(Areas::FrontSeats)
	{
		cout << "Calling the constructor with one parameter" << endl;
	}

	Location(int locationID, string city, const char* building_type,  int* nr_seats, int nr_rows/*, int seat_number*/, Areas area) : locationID(locationID), area(area)

	{
		this->setTheCity(city);
		this->setTheBuildingType(building_type);
		this->setTheSeat(nr_seats, nr_rows);
		

   }

	const int getLocationID()
	{
		return this->locationID;
	}
	string getCity()
	{
		return this->city;
	}
	char* getBuildingCity()
	{
		return this->building_type;
	}
	int* getNrSeats()
	{
		return this->nr_seats;
	}
	/*int getSeatNumber()
	{
		return this->seat_number;
	}*/
	Areas getArea()
	{
		return this->area;
	}
	static int getMaxNrSeats()
	{
		return maximum_number_of_seat;
	}
	void setArea(string type)
	{
		int i = 0;

		if (type == "FrontSeats")
		{
			i = 0;
		}
		if (type == "MiddleSeats ")
		{
			i = 1;

		}
		if (type == "UpperSeats")
		{
			i = 2;
		}
	}
	void setTheCity(  string City_Of_The_Event)
	{
		

		this->city = City_Of_The_Event;
	}

	void setTheBuildingType(const char* newBuilding)
	{
		if (this->building_type != nullptr)
		{
			delete[] this->building_type;

		}

		this->building_type = new char[strlen(newBuilding) + 1];
		strcpy_s(this->building_type, strlen(newBuilding) + 1, newBuilding);
	}

	void setTheSeat(  int* nr_seats, int nr_rows)
	{
		if (this->nr_seats != nullptr)
		{
			delete[] this->nr_seats;
		}

			this->nr_seats = new int[nr_rows];
			for (int i = 0; i < nr_rows; i++)
			{
				this->nr_seats[i] = nr_seats[i];
			}
		
		this->nr_rows = nr_rows;

	}

	Location operator+(const Location&lo)
	{
		Location copie(*this);
		copie.nr_rows += lo.nr_rows;
		return copie;
	}
	Location& operator ()(int val)
	{
		if (val > 0)
		{
			for (int i = 0; i < this->nr_rows; i++)
			{
				this->nr_seats[i] += val;
			}
			return *this;
		}
		else
		{
			cout << "Invalid input ! ";
				return *this;
		}
	}

	~Location()
	{

	}

	friend ostream& operator<< (ostream& out, const Location& l); 
	

};
int maximum_number_of_seats = 10000;
ostream& operator<< (ostream& out, const Location& l)
{
	out << "Location ID is: " << l.locationID << endl
		<< " City where the location of the event is : " << l.city << endl
		<< " The building type is : " << " , " << endl
		<< " Locatia are : " << l.nr_rows << " randuri " << endl
		<< " Si locuri/rand : " << endl;
	if (l.nr_seats != nullptr)
	{
		for (int i = 0; i < l.nr_rows; i++)
		{
			out << l.nr_seats[i] << " ";
		}
	}
	else
		out << " - ";
	return out;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////

enum ParticipantCategory {Child, Student, Adult, Senior};

class Participant
{
private:
	const int participantID;
	string name;
	int age;
	bool over18;
	ParticipantCategory category;
	int nr_of_events_attended;

	static int MIN_NAME_SIZE; 
public:
	// Default Constructor
	Participant() : participantID(0), name("Unknown"), age(0), over18(false), category(Child), nr_of_events_attended(0)
	{
		cout << "Default constructor for PARTCIPANT";
	}

	// Constructor with all the parameters
	Participant(int participantID, string name, int age, bool over18, ParticipantCategory category, int nr_of_events_attended) : participantID(participantID), over18(over18), category(category)
	{
		this->setName(name);
		this->setAge(age);
		this->setNrEvents(nr_of_events_attended);
	}
	string getName()
	{
		return this->name;
	}
	void  setName(string newName)
	{

		/*if (newName.size() < Participant::MIN_NAME_SIZE)
		{
			throw  "The name is too short ";
		}*/
		this->name = newName;
	}

	int getAge()
	{
		return this->age;
	}
	void setAge(int ageCopy)
	{
		/*if (this->age < 0)
		{
			throw "Enter a valid age ";
		}*/
		this->age = ageCopy;
	}
	bool isOver()
	{
		return this->over18;
	}
	int getNrEvents()
	{
		return this->nr_of_events_attended;
   }
	void setNrEvents(int newEvent)
	{
		/*if (this->nr_of_events_attended < 0)
		{
			throw "Invalid number";
		}*/
		this->nr_of_events_attended = newEvent;
	}
	static int getMinSize()
	{
		return MIN_NAME_SIZE;
	}
	ParticipantCategory getCategory()
	{
		return this->category;
	}
	void setCategory(string category)
	{
		int i = 0;
		if (category == "Adult")
			i = 2;
		if (category == "Child")
			i = 0;
		if (category == "Student")
			i = 1;
		if (category == "Senior")
			i = 3;
	}

	Participant(const Participant& copy):participantID(copy.participantID), over18(copy.over18), category(copy.category)
	{
		this->setName(copy.name);
		this->setAge(copy.age);
		this->setNrEvents(copy.nr_of_events_attended);
	}
	Participant& operator= (const Participant& o)
	{
		this->setName(o.name);
		this->setAge(o.age);
		this->setNrEvents(o.nr_of_events_attended);
		this->over18 = o.over18;
		this->category = o.category;
		return *this;
	}
	Participant operator++ ()
	{
		this->age++;
		return *this;
	}
	Participant operator-(const Participant& p)
	{
		Participant copy(*this);
		copy.nr_of_events_attended -= p.nr_of_events_attended;
		return copy;
	}
	friend ostream& operator<<(ostream& out, const Participant& pa);
	friend istream& operator>>(istream& in, Participant& pr);
};
int MIN_NAME_SIZE= 2;

ostream& operator<< (ostream& out, const Participant& pa)
{
	out << "Participant ID is: " << pa.participantID << endl;
	out << "Name: " << pa.name << endl;
	out << "Age: " << pa.age << endl;
	out << "Is over 18 ? : " << pa.over18 << endl;
	out << "Number of events attended to: " << pa.nr_of_events_attended << endl;
	out << " Participant category : " << pa.category << endl;
	return out;
}

istream& operator>>(istream& in, Participant& pr)
{
	cout << "Introduce the name of the Participant: ";                    
	in >> pr.name; 
	cout << "Introduce the Participant's age : ";
	in >> pr.age;
	cout << "Is the Participant over 18 ? "; 
	in >> pr.over18;
	/*cout << "Category: ";
	in >> pr.category;*/
	cout << " Number of events attended to : ";
	in >> pr.nr_of_events_attended;
	return in;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////// Another Class //////////////////////////

enum TicketType { General, VIP };

class Ticket
{
private:
	const int TicketID ;
	bool IsValid; // is it valid or not ( 
	int nr_of_agents; // number of agents that worked to make the ticket
	float* price;
	int nr_of_tickets;
	TicketType type;
	static int MIN_NUMBER_OF_TICKETS; // that need to be bought in order to be able to attend an event
public:
	// Default constructor
	Ticket(): TicketID(0), IsValid(false), nr_of_agents(0), price(nullptr), type(General), nr_of_tickets(0)
	{

	}






	// 2 generic methods :   the Max price of the tickets,  the total sum made from tickets
};
int MIN_NUMBER_OF_TICKETS = 1;


//int main ()
//{
//	//// Tests for the EVENT CLASS
//	
//	//Event l1;  // default constructor
//
//	//cout << endl;
//	//Event mecifotbal(123, " Real Madrid vs Barcelona", "15 decembrie 2022, ora 22:00", 10000, EventType::Football, true, 90); // constructor with all the parameters
//	//cout << mecifotbal;  //  << operator
//	//cout << endl;
//	//l1 = mecifotbal; // = operator
//	//cout << l1;
//	//cout << endl << endl;
//	//Event copy(mecifotbal); // Copy constructor
//	//cout << copy;
//	//cout << endl; 
//	//
//	//mecifotbal *= 5; cout << endl; // operator *=
//
//	//cout << !mecifotbal;  // ! operator
//
//	// TESTS FOR THE LOCATION CLASS
//
////	Location e;
////	/*Location e1(10); */
////	/*cout << e1; */ 
////	int seats[] = { 1,2,3,4,5,6,6,7,8 };
////	/*string buildings[] = { " la " , "s"};*/
////	
////Location e2(12, "Vienna" , "Theater ", seats, 10, Areas::FrontSeats);
////cout << e2;   //   << operator c
////cout << endl;
////
////e2 + 3;  // + operator
////cout << e2;
////e2(1); // operator ()
////cout << e2;
//
//
//// PARTICIPANT CLASSSSS//////////////////////////////////////////
//	//Participant p1;
//	//cout << endl;
//	//Participant Jimmy(1, "Jimmy", 27, true, ParticipantCategory::Adult, 2);
//	//cout << endl;
//	//cout << Jimmy;
//	//cout << endl;
//	//cout << ++Jimmy; // ++ OPERATOR
//	//cout << endl;
//	//p1 = Jimmy;
//	//cout << p1;
//	//cout << endl;
//	//cout << "Constructorul de copiere : " << endl;
//	//Participant p2(Jimmy);
//	//cout << p2;
//	//cout << endl;
//
//	//cin >> p2; // >> OPERATOR
//
//	return 0;
//
//}