#pragma once
#include <iostream>
#include <string.h>
using namespace std;

enum ParticipantCategory { Child, Student, Adult, Senior };

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
	// GETTERS AND SETTERS
	const int getID()
	{
		return this->participantID;
	}
	string getName()
	{
		return this->name;
	}
	void  setName(string newName)
	{

		if (newName.size() < 0)
		{
			throw  "The name is too short ";
		}
		else
			this->name = newName;
	}

	int getAge()
	{
		return this->age;
	}
	void setAge(int ageCopy)
	{
		if (ageCopy < 0)
		{
			throw "Enter a valid age ";
		}
		else
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
		}
		else*/
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
	string setCategory()
	{
		switch (this->category)
		{
		case ParticipantCategory::Adult:
			return "Adult";
		case ParticipantCategory::Child:
			return "Child";
		case ParticipantCategory::Student:
			return "Student";
		case ParticipantCategory::Senior:
			return "Senior";

		}
	}
	// COPY CONSTRUCTOR /////////////
	Participant(const Participant& copy) :participantID(copy.participantID), over18(copy.over18), category(copy.category)
	{
		this->setName(copy.name);
		this->setAge(copy.age);
		this->setNrEvents(copy.nr_of_events_attended);
	}

	// OPERATOR= /////////////////////
	Participant& operator= (const Participant& o)
	{
		this->setName(o.name);
		this->setAge(o.age);
		this->setNrEvents(o.nr_of_events_attended);
		this->over18 = o.over18;
		this->category = o.category;
		return *this;
	}

	// 2 OPERATORS 
	Participant operator++ ()
	{
		this->age++;
		return *this;
	}
	Participant operator++(int)
	{
		Participant copy = *this;
		this->age++;
		return copy;
	}
	operator string()
	{
		return this->name;
	}

	// 2 GENERIC METHODS 




	friend ostream& operator<<(ostream& out, const Participant& pa);
	friend istream& operator>>(istream& in, Participant& pr);


};
int MIN_NAME_SIZE = 2;

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
	if (pr.age > 0)
	{
		cout << "Introduce the Participant's age : ";
		in >> pr.age;
	}
	else throw "Not born yet";

	cout << "Is the Participant over 18 ? ";
	in >> pr.over18;
	/*cout << "Category: ";
	in >> pr.category;*/
	cout << " Number of events attended to : ";
	in >> pr.nr_of_events_attended;
	return in;
}