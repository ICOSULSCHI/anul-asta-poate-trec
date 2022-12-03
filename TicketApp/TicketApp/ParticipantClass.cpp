//#include <iostream>
//#include <string>
//
//using namespace std;
//
//enum ParticipantCategory { Child, Student, Adult, Senior };
//
//class Participant
//{
//private:
//	const int participantID;
//	string name;
//	int age;
//	bool over18;
//	ParticipantCategory category;
//	int nr_of_events_attended;
//
//	static int MIN_NAME_SIZE;
//public:
//	// Default Constructor
//	Participant() : participantID(0), name("Unknown"), age(0), over18(false), category(Child), nr_of_events_attended(0)
//	{
//		cout << "Default constructor for PARTCIPANT";
//	}
//
//	// Constructor with all the parameters
//	Participant(int participantID, string name, int age, bool over18, ParticipantCategory category, int nr_of_events_attended) : participantID(participantID), over18(over18), category(category)
//	{
//		this->setName(name);
//		this->setAge(age);
//		this->setNrEvents(nr_of_events_attended);
//	}
//	string getName()
//	{
//		return this->name;
//	}
//	void  setName(string newName)
//	{
//
//		/*if (newName.size() < Participant::MIN_NAME_SIZE)
//		{
//			throw  "The name is too short ";
//		}*/
//		this->name = newName;
//	}
//
//	int getAge()
//	{
//		return this->age;
//	}
//	void setAge(int ageCopy)
//	{
//		/*if (this->age < 0)
//		{
//			throw "Enter a valid age ";
//		}*/
//		this->age = ageCopy;
//	}
//	bool isOver()
//	{
//		return this->over18;
//	}
//	int getNrEvents()
//	{
//		return this->nr_of_events_attended;
//	}
//	void setNrEvents(int newEvent)
//	{
//		/*if (this->nr_of_events_attended < 0)
//		{
//			throw "Invalid number";
//		}*/
//		this->nr_of_events_attended = newEvent;
//	}
//	static int getMinSize()
//	{
//		return MIN_NAME_SIZE;
//	}
//	ParticipantCategory getCategory()
//	{
//		return this->category;
//	}
//	void setCategory(string category)
//	{
//		int i = 0;
//		if (category == "Adult")
//			i = 2;
//		if (category == "Child")
//			i = 0;
//		if (category == "Student")
//			i = 1;
//		if (category == "Senior")
//			i = 3;
//	}
//
//	Participant(const Participant& copy) :participantID(copy.participantID), over18(copy.over18), category(copy.category)
//	{
//		this->setName(copy.name);
//		this->setAge(copy.age);
//		this->setNrEvents(copy.nr_of_events_attended);
//	}
//	Participant& operator= (const Participant& o)
//	{
//		this->setName(o.name);
//		this->setAge(o.age);
//		this->setNrEvents(o.nr_of_events_attended);
//		this->over18 = o.over18;
//		this->category = o.category;
//		return *this;
//	}
//	Participant operator++ ()
//	{
//		this->age++;
//		return *this;
//	}
//	Participant operator-(const Participant& p)
//	{
//		Participant copy(*this);
//		copy.nr_of_events_attended -= p.nr_of_events_attended;
//		return copy;
//	}
//	friend ostream& operator<<(ostream& out, const Participant& pa);
//	friend istream& operator>>(istream& in, Participant& pr);
//};
////int MIN_NAME_SIZE = 2;
//
////ostream& operator<< (ostream& out, const Participant& pa)
////{
////	out << "Participant ID is: " << pa.participantID << endl;
////	out << "Name: " << pa.name << endl;
////	out << "Age: " << pa.age << endl;
////	out << "Is over 18 ? : " << pa.over18 << endl;
////	out << "Number of events attended to: " << pa.nr_of_events_attended << endl;
////	out << " Participant category : " << pa.category << endl;
////	return out;
////}
////
////istream& operator>>(istream& in, Participant& pr)
////{
////	cout << "Introduce the name of the Participant: ";
////	in >> pr.name;
////	cout << "Introduce the Participant's age : ";
////	in >> pr.age;
////	cout << "Is the Participant over 18 ? ";
////	in >> pr.over18;
////	/*cout << "Category: ";
////	in >> pr.category;*/
////	cout << " Number of events attended to : ";
////	in >> pr.nr_of_events_attended;
////	return in;
////}