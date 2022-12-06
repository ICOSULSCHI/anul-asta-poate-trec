#pragma once
#include <iostream>
#include <string.h>
using namespace std;

enum Areas { FrontSeats, MiddleSeats, UpperSeats };
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

	// CONSTRUCTOR WITH ALL THE PARAMETERS
	Location(int locationID, string city, const char* building_type, int* nr_seats, int nr_rows/*, int seat_number*/, Areas area) : locationID(locationID)

	{
		this->area = area;
		this->city = city;
		if (this->building_type != nullptr)
		{
			delete[] this->building_type;

		}

		this->building_type = new char[strlen(building_type) + 1];
		strcpy_s(this->building_type, strlen(building_type) + 1, building_type);

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
	// COPY CONSTRUCTOR 
	Location(const Location& c) : locationID(c.locationID), area(c.area)
	{
		this->city = c.city;
		if (this->building_type != nullptr)
		{
			delete[] this->building_type;

		}

		this->building_type = new char[strlen(c.building_type) + 1];
		strcpy_s(this->building_type, strlen(c.building_type) + 1, c.building_type);

		if (this->nr_seats != nullptr)
		{
			delete[] this->nr_seats;
		}

		this->nr_seats = new int[c.nr_rows];
		for (int i = 0; i < c.nr_rows; i++)
		{
			this->nr_seats[i] = c.nr_seats[i];
		}

		this->nr_rows = c.nr_rows;

	}
	//OPERATOR=

	Location operator=(const Location& c)
	{
		this->city = c.city;
		this->area = c.area;
		if (this->building_type != nullptr)
		{
			delete[] this->building_type;

		}

		this->building_type = new char[strlen(c.building_type) + 1];
		strcpy_s(this->building_type, strlen(c.building_type) + 1, c.building_type);

		if (this->nr_seats != nullptr)
		{
			delete[] this->nr_seats;
		}

		this->nr_seats = new int[c.nr_rows];
		for (int i = 0; i < c.nr_rows; i++)
		{
			this->nr_seats[i] = c.nr_seats[i];
		}

		this->nr_rows = c.nr_rows;

		return *this;

	}



	// GETTERS

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
	string setArea()
	{
		switch (this->area)
		{
		case Areas::FrontSeats:
			return "FrontSeats";
		case Areas::MiddleSeats:
			return "MiddleSeats";
		case Areas::UpperSeats:
			return "UpperSeats";

		}
	}

	// SETTERS //

	void setTheCity(string City_Of_The_Event)
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

	void setTheSeat(int* nr_seats, int nr_rows)
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

	// 2 generic methods ////
	// Count the number of seats
	char* toUpperCase(const char* text)
	{
		int size = strlen(text);
		char* newText = new char[size];
		bool allowCap = true;
		for (int i = 0; i < size; i++)
		{
			if (allowCap == true)
			{
				newText[i] = text[i] - 32;
				allowCap = false;
			}
			else
			{
				newText[i] = text[i];
			}
			if (text[i] == ' ')
			{
				allowCap = true;
			}
		}
		return newText;
	}



	// 2 OPERATORS 


	bool operator> (const Location& l)
	{
		return this->nr_rows > l.nr_rows;
	}

	bool operator== (const Location& l)
	{
		bool egal = true;
		for (int i = 0; i < this->nr_rows; i++)
		{
			if (this->nr_seats[i] != l.nr_seats[i])
			{
				egal = false;
			}
		}
		return this->building_type == l.building_type;

	}



	~Location()
	{
		if (this->building_type != nullptr)
		{
			delete[] this->building_type;
		}
		if (this->nr_seats != nullptr)
		{
			delete[] this->nr_seats;
		}
	}

	friend ostream& operator<< (ostream& out, const Location& l);
	friend istream& operator>> (istream& in, Location& l);

};
int maximum_number_of_seats = 10000;
ostream& operator<< (ostream& out, const Location& l)
{
	out << "Location ID is: " << l.locationID << endl
		<< " City where the location of the event is : " << l.city << endl
		<< endl << (l.building_type != nullptr ? "Building Type: " + string(l.building_type) : "No specific type") << endl
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
istream& operator>> (istream& in, Location& l)
{
	cout << endl;
	cout << "Introduce the city : " << endl;
	in >> l.city;
	cout << "The building type is : " << endl;
	char aux[100];
	in.getline(aux, 100);
	in.clear();
	delete[] l.building_type;
	l.building_type = new char[strlen(aux) + 1];
	strcpy_s(l.building_type, strlen(aux) + 1, aux);
	cout << "Introduce the nr of rows : " << endl; in >> l.nr_rows;
	cout << " Introduce the nr of seats : " << endl;
	delete[] l.nr_seats;
	l.nr_seats = new int[l.nr_rows];
	for (int i = 0; i < l.nr_rows; i++)
	{
		cout << " \t Number of seats per row nr -> " << i + 1 << " : "; in >> l.nr_seats[i];
	}

	return in;
}
