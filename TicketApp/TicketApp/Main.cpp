
#include "EventClass.h"
#include "ParticipantClass.h"
#include "LocationClass.h"
#include "TicketClass.h"
//
using namespace std;
int main()
{
	cout << " EVENT CLASS  " << endl;

	Event l1;  // default constructor

	cout << endl;
	Event mecifotbal(123, " Real Madrid vs Barcelona", "15 decembrie 2022, ora 22:00", 10000, EventType::Football, true, 90); // constructor with all the parameters
	cout << mecifotbal;  //  << operator
	cout << endl;
	l1 = mecifotbal; // = operator
	cout << l1;
	cout << endl << endl;
	Event copy(mecifotbal); // Copy constructor
	cout << copy;
	cout << endl;
	mecifotbal *= 5; cout << endl; // operator *=
	cout << !mecifotbal;  // ! operator
	cin >> mecifotbal; // >> operator



	cout << " Location CLASS  " << endl;

	Location e;
	Location e1(10);
	cout << endl;

	cout << e1;
	cout << endl;
	int seats[] = { 1,2,3,4,5,6,6,7,8,10 };
	cout << endl;
	Location e2(12, "Vienna", "Theater", seats, 10, Areas::FrontSeats);
	cout << e2;   //   << operator 
	cout << "Operator += : " << endl;
	cout << endl;
	char building[]{ "grand theater" }; // to UPPER CASE
	cout << e2.toUpperCase(building);
	//cin >> e2; // >> operator
	cout << endl;
	Location e4 = e2; // op =
	cout << endl;
	cout << e4;
	cout << endl;
	if (e4 > e2)  // > operator
	{
		cout << "e4 has more rows than e2";

	}
	else
		cout << "e2 has more rows than e4";
	Location e3(e2); // copy constr
	cout << endl;

	cout << e3;
	cout << endl;


	cout << endl;

	cout << e2;
	if (e == e2) // operator ==
	{
		cout << "e si e2 sunt egali " << endl;
	}
	else cout << "\nNu sunt egali";
	cout << endl;

	cout << e2;
	cout << endl;
	cin >> e2; // istream

	//
	cout << " PARTICIPANT CLASS  " << endl;


	Participant p1;
	cout << endl;
	Participant Jimmy(1, "Jimmy", 27, true, ParticipantCategory::Adult, 2);
	cout << endl;
	cout << Jimmy;

	cout << endl;
	cout << ++Jimmy; // ++ OPERATOR
	cout << endl;
	cout << Jimmy++; // Operator ++
	cout << endl;
	cout << " Name of the participant is :  " << (string)Jimmy << endl;  // operator string
	cout << endl;
	p1 = Jimmy; // op =
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Constructorul de copiere : " << endl;
	Participant p2(Jimmy);
	cout << endl;
	cout << p2;
	cout << endl;

	cin >> p2; // >> OPERATOR
	cout << endl;





	cout << " TICKET CLASS  " << endl;

	Ticket t1;
	float Prices[] = { 4.2 , 2.3, 10.2 };
	Ticket t2(Prices, 3); cout << endl;
	cout << t2;
	cout << endl;
	t2.TotalRevenue(Prices);
	Ticket p3(t2); // copy constructor
	cout << p3; cout << endl;
	Ticket p4 = p3; // op =
	cout << p4; cout << endl;
	cout << endl;
	t2.AveragePriceForATicket(Prices);
	cout << t2[2]; // [] operator
	cout << endl;
	cout << "Nr of agents that worked for a ticket " << (int)t2 << endl;  // operator int()
	cin >> t2; // operator >>

return 0;
}