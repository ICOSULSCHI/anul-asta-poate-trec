//#include <iostream>
//#include <string>
//using namespace std;
//
//enum Areas { FrontSeats, MiddleSeats, UpperSeats };
//class Location
//{
//private:
//	const int locationID;
//	string city; // The city the event is located
//	char* building_type; // The place in the city where event will have place
//	int* nr_seats; // number of seats per row
//	int nr_rows;
//	/*int seat_number;*/
//	Areas area;
//	static int maximum_number_of_seat;
//public:
//	// Default Constructor
//	Location() : locationID(0), city("Unknown"), building_type(nullptr), nr_seats(nullptr), nr_rows(0) /*seat_number(0)*/, area(Areas::FrontSeats)
//	{
//		cout << " Aloha " << endl;
//	}
//
//	//Constructor with one parameter 
//	Location(const int locationID) : locationID(locationID), city("Unknown"), building_type(nullptr), nr_seats(nullptr), nr_rows(0), /*seat_number(0)*/ area(Areas::FrontSeats)
//	{
//		cout << "Calling the constructor with one parameter" << endl;
//	}
//
//	Location(int locationID, string city, const char* building_type, int* nr_seats, int nr_rows/*, int seat_number*/, Areas area) : locationID(locationID), area(area)
//
//	{
//		this->setTheCity(city);
//		this->setTheBuildingType(building_type);
//		this->setTheSeat(nr_seats, nr_rows);
//
//
//	}
//
//	const int getLocationID()
//	{
//		return this->locationID;
//	}
//	string getCity()
//	{
//		return this->city;
//	}
//	char* getBuildingCity()
//	{
//		return this->building_type;
//	}
//	int* getNrSeats()
//	{
//		return this->nr_seats;
//	}
//	/*int getSeatNumber()
//	{
//		return this->seat_number;
//	}*/
//	Areas getArea()
//	{
//		return this->area;
//	}
//	static int getMaxNrSeats()
//	{
//		return maximum_number_of_seat;
//	}
//	void setArea(string type)
//	{
//		int i = 0;
//
//		if (type == "FrontSeats")
//		{
//			i = 0;
//		}
//		if (type == "MiddleSeats ")
//		{
//			i = 1;
//
//		}
//		if (type == "UpperSeats")
//		{
//			i = 2;
//		}
//	}
//	void setTheCity(string City_Of_The_Event)
//	{
//
//
//		this->city = City_Of_The_Event;
//	}
//
//	void setTheBuildingType(const char* newBuilding)
//	{
//		if (this->building_type != nullptr)
//		{
//			delete[] this->building_type;
//
//		}
//
//		this->building_type = new char[strlen(newBuilding) + 1];
//		strcpy_s(this->building_type, strlen(newBuilding) + 1, newBuilding);
//	}
//
//	void setTheSeat(int* nr_seats, int nr_rows)
//	{
//		if (this->nr_seats != nullptr)
//		{
//			delete[] this->nr_seats;
//		}
//
//		this->nr_seats = new int[nr_rows];
//		for (int i = 0; i < nr_rows; i++)
//		{
//			this->nr_seats[i] = nr_seats[i];
//		}
//
//		this->nr_rows = nr_rows;
//
//	}
//
//	Location operator+(const Location& lo)
//	{
//		Location copie(*this);
//		copie.nr_rows += lo.nr_rows;
//		return copie;
//	}
//	Location& operator ()(int val)
//	{
//		if (val > 0)
//		{
//			for (int i = 0; i < this->nr_rows; i++)
//			{
//				this->nr_seats[i] += val;
//			}
//			return *this;
//		}
//		else
//		{
//			cout << "Invalid input ! ";
//			return *this;
//		}
//	}
//
//	~Location()
//	{
//
//	}
//
//	friend ostream& operator<< (ostream& out, const Location& l);
//
//
//};
//int maximum_number_of_seats = 10000;
//ostream& operator<< (ostream& out, const Location& l)
//{
//	out << "Location ID is: " << l.locationID << endl
//		<< " City where the location of the event is : " << l.city << endl
//		<< " The building type is : " << " , " << endl
//		<< " Locatia are : " << l.nr_rows << " randuri " << endl
//		<< " Si locuri/rand : " << endl;
//	if (l.nr_seats != nullptr)
//	{
//		for (int i = 0; i < l.nr_rows; i++)
//		{
//			out << l.nr_seats[i] << " ";
//		}
//	}
//	else
//		out << " - ";
//	return out;
//}