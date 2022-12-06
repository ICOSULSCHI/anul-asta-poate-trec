#pragma once
#include <iostream>
#include <string.h>
using namespace std;

enum TicketType { General, VIP };

class Ticket
{
private:
	const int TicketID;
	bool IsValid; // is it valid or not ( 
	int nr_of_agents; // number of agents that worked to make the ticket
	float* price;
	int nr_of_tickets;
	TicketType type;
	static int MIN_NUMBER_OF_TICKETS; // that need to be bought in order to be able to attend an event
public:
	// Default constructor
	Ticket() : TicketID(0), IsValid(false), nr_of_agents(0), price(nullptr), type(General), nr_of_tickets(0)
	{
		cout << " Default constructor called ";
	}
	Ticket(float* newPrice, int nr_of_tickets) :TicketID(0), IsValid(false), nr_of_agents(1), type(General)
	{
		if (this->price != nullptr)
		{
			delete[] this->price;
		}
		this->price = new float[nr_of_tickets];
		for (int i = 0; i < nr_of_tickets; i++)
		{
			this->price[i] = newPrice[i];
		}
		this->nr_of_tickets = nr_of_tickets;
	}

	// COPY CONSTRUCTOR

	Ticket(const Ticket& t) : TicketID(t.TicketID), IsValid(t.IsValid), nr_of_agents(t.nr_of_agents), type(t.type)
	{
		if (this->price != nullptr)
		{
			delete[] this->price;
		}
		this->price = new float[t.nr_of_tickets];
		for (int i = 0; i < t.nr_of_tickets; i++)
		{
			this->price[i] = t.price[i];
		}
		this->nr_of_tickets = t.nr_of_tickets;
	}
	//OPERATOR = 
	Ticket operator= (const Ticket& t)
	{
		if (this->price != nullptr)
		{
			delete[] this->price;
		}
		this->price = new float[t.nr_of_tickets];
		for (int i = 0; i < t.nr_of_tickets; i++)
		{
			this->price[i] = t.price[i];
		}
		this->nr_of_tickets = t.nr_of_tickets;
		this->IsValid = t.IsValid;
		this->nr_of_agents = t.nr_of_agents;
		this->type = t.type;
		return *this;

	}


	// GETTERS
	const int getID()
	{
		return this->TicketID;
	}
	bool isValid()
	{
		return this->IsValid;
	}
	int getNrAgents()
	{
		return this->nr_of_agents;
	}
	int getnrTickets()
	{
		return this->nr_of_tickets;
	}
	float* getPrices()
	{
		return this->price;
	}
	TicketType getType()
	{
		return this->type;
	}
	static int getMinimumNr()
	{
		return MIN_NUMBER_OF_TICKETS;
	}

	// SETTERS

	void setIfValid(bool is)
	{
		is = false;
		if (this->IsValid == true)
			is == true;
		else
			is == false;
	}
	void setNrAgents(int nr)
	{
		if (this->nr_of_agents > 0)
			this->nr_of_agents = nr;
		else
			throw "Try again";
	}
	string setType()
	{
		switch (this->type)
		{
		case TicketType::General:
			return "General";
		case TicketType::VIP:
			return "VIP";
		}

	}
	void setPrice(float* newPrice, int otherNR)
	{
		if (this->price != nullptr)
		{
			delete[] this->price;
		}
		this->price = new float[otherNR];
		for (int i = 0; i < otherNR; i++)
		{
			this->price[i] = newPrice[i];
		}
		this->nr_of_tickets = otherNR;
	}





	// 2 OVERLOADED OPERATORS

	float operator[](int index)
	{
		if (index >= 0 && index < this->nr_of_tickets)
		{
			return this->price[index];
		}
		else
		{
			throw  " Invalid index";
		}
	}

	explicit operator int()
	{
		return this->nr_of_agents;
	}


	// 2 GENERIC METHODS 

	// Total Revenue
	void TotalRevenue(float* prices)
	{

		float sum = 0;
		for (int i = 0; i < this->nr_of_tickets; i++)
		{
			sum += prices[i];
		}
		cout << "Total Revenue for the sold tickets : " << sum;



	}

	// Average price for a ticket
	void AveragePriceForATicket(float* prices)
	{
		float average = 0;
		float sum = 0;
		for (int i = 0; i < this->nr_of_tickets; i++)
		{
			sum += prices[i];
		}
		cout << "Average price for a ticket: " << sum / nr_of_tickets;

	}

	~Ticket()
	{
		if (this->price != nullptr)
		{
			cout << " Call the destructor " << endl;
			delete[] this->price;
		}
	}



	friend istream& operator>> (istream& in, Ticket& t);
	friend ostream& operator<< (ostream& out, Ticket& t);




};
int MIN_NUMBER_OF_TICKETS = 1;

ostream& operator<< (ostream& out, Ticket& t)
{
	out << "Ticket ID: " << t.TicketID << endl;
	out << "Is Valid  ( 1 for Yes, 0 for No): " << t.IsValid << endl;
	out << "Number of agents that worked for the ticket: " << t.nr_of_agents << endl;
	out << "Ticket type: " << t.type << endl;
	out << "Number of tickets sold: " << t.nr_of_tickets << endl;
	for (int i = 0; i < t.nr_of_tickets; i++)
	{
		out << "Price for the ticket nr" << i + 1 << " : " << t.price[i] << endl;

	}

	return out;
}
istream& operator>> (istream& in, Ticket& t)
{
	cout << "Introduce the number of agents that  worked on a ticket : ";
	in >> t.nr_of_agents; cout << endl;
	cout << "Is Valid ( 1 for YES, 0 for NO ) ? : " << endl;
	in >> t.IsValid;
	cout << " NR of tickets : " << endl;
	in >> t.nr_of_tickets;

	delete[] t.price;
	t.price = new float[t.nr_of_tickets];
	for (int i = 0; i < t.nr_of_tickets; i++)
	{
		cout << "Price for the ";
		cout << "ticket nr " << i + 1 << " : ";
		in >> t.price[i];
	}
	return in;
}