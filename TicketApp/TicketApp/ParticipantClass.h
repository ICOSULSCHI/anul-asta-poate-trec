#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

enum ParticipantCategory { Child, Student, Adult, Senior };



class I_Participant
{
public:
	virtual ~I_Participant() = default;
	virtual void class_interogation() = 0;
	virtual string addSecondName(string secondName) = 0;
	virtual int checkAge(int age) = 0;


};
class Participant : I_Participant
{
protected:
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

	virtual void class_interogation() override
	{
		cout << " Main class - > Participant" << endl;
	}
	//virtual void class_interogation() = 0; // pure virtual function

	virtual string addSecondName(string secondName)
	{
		cout << "Participant's second name is : " << secondName;
		return secondName;
	}

	virtual int checkAge(int age)
	{
		if (age >= 31)
		{
			cout <<  "The Participant is not eligible for student price ";
		}
		return 0;
	}


	friend ostream& operator<<(ostream& out, const Participant& pa);
	friend istream& operator>>(istream& in, Participant& pr);
	friend ofstream& operator<<(ofstream& out, const Participant& pa)
	{
		out.write((char*)&pa.name, sizeof(string));
		out.write((char*)&pa.age, sizeof(int));
		out.write((char*)&pa.over18, sizeof(bool));
		out.write((char*)& pa.category, sizeof(Participant));
		out.write((char*)& pa.nr_of_events_attended, sizeof(int));
	}
	friend ifstream& operator>>(ifstream& in, Participant& pa)
	{
		in.read((char*)&pa.name, sizeof(string));
		in.read((char*)&pa.age, sizeof(int));
		in.read((char*)&pa.over18, sizeof(bool));
		in.read((char*)&pa.category, sizeof(Participant));
		in.read((char*)&pa.nr_of_events_attended, sizeof(int));
	}
	

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

//class studentSTL
//{
//private:
//	vector <Participant>student;
//public:
//	studentSTL(vector <Participant>student) :student()
//	{
//		for (const Participant& p : student)
//		{   
//			this->student.push_back(p);
//		}
//	}
//	studentSTL& operator+=(const Participant& p)
//	{
//		this->student.push_back(p);
//		return *this;
//
//	}
//	friend ostream& operator<<(ostream& out, const studentSTL& s)
//	{
//		for (const Participant& p : s.student)
//		{
//			out << p;
//		}
//		return out;
//	}
//};

class student : public Participant
{
private: 

	int height=0;
	int telephoneNr = 0;
public: 
	student() :Participant(), height(0), telephoneNr(0)
	{
		cout << "Calling default constructor"; 
    }
	student(int participantID, string name, int age, bool over18, ParticipantCategory category, int nr_of_events_attended, int height, int telephoneNr):
		Participant (participantID, name, age, over18, category, nr_of_events_attended),
		height(0), telephoneNr(0)

	{
		if(this->height<0)
		{
			throw "Wrong number ";
		}
		this->height = height;
		this->telephoneNr = telephoneNr;
		if ((this->telephoneNr / 10000) < 1)
		{
			throw "Wrong number ";
		}
	}
	student(const student& s) : Participant(s), height(0), telephoneNr(0)
	{
		if (this->height < 0)
		{
			throw "Wrong number ";
		}
		this->height = s.height;
		this->telephoneNr = s.telephoneNr;
		if (this->telephoneNr < 5)
		{
			throw "Wrong number ";
		}
	}
	student& operator= (const student& s)
	{
		if (this != &s)
		{
			student::operator=(s);

			if (this->height < 0)
			{
				throw "Wrong number ";
			}
			this->height = s.height;
			if (this->telephoneNr < 5)
			{
				throw "Wrong number ";
			}
			this->telephoneNr = s.telephoneNr;
		}
		return *this;
	}
	
	int getHeight()
	{
		return this->height;
	}

	int getPhone()
	{
		return this->telephoneNr;
	}

	void setHeight(int h)
	{
		if (this->height < 0)
		{
			throw "Wrong number ";
		}
		this->height = h;
	}
	void setPhoneNr(int nr)
	{
		if (this->telephoneNr < 5)
		{
			throw "Wrong number ";
		}
		this->telephoneNr = nr;
	}
	friend ostream& operator<< (ostream& out, const student& s);
	friend istream& operator>> (istream& in, student& s);
	

	 void class_interogation() override
	{
		cout << " Derived class -> student " << endl;
	}
	
	  string addSecondName( string secondName) override
	 {
		 cout << "Student's second name is : " << secondName;
		 return secondName;
	 }
	
	  int checkAge(int age) override
	  {
		  if (age >= 31)
		  {
			  cout << "The individual is over 31 years and not eligible for student price ";
		  }
		  return 0;
	  }
};


ostream& operator<< (ostream& out, const student& s)
{
	out << endl << (Participant)s << endl;
	out << "Student's height is : " << s.height << "cm" << endl;
	out << "Student's phone number is: " << s.telephoneNr << endl;
	return out;
}

istream& operator>> (istream& in, student& s)
{
	in >> (Participant&)s; cout << endl;
	cout << (Participant)s;
	cout << "Student's height: "; 
	in >> s.height;
	cout << "Student's phone number: ";
	in >> s.telephoneNr;
	return in;
}

template <typename T, typename Z >
void add(T a, Z b)
{
	cout << a + b;
}

