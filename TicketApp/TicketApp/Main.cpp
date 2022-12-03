//
//#include "EventClass.cpp"
//#include "ParticipantClass.cpp"
//#include "LocationClass.cpp"
//#include "TicketClass.cpp"
//
//using namespace std;
//
//
//int main()
//{
//	// Tests for the EVENT CLASS
//
//	Event l1;  // default constructor
//
//	cout << endl;
//	Event mecifotbal(123, " Real Madrid vs Barcelona", "15 decembrie 2022, ora 22:00", 10000, EventType::Football, true, 90); // constructor with all the parameters
//	cout << mecifotbal;  //  << operator
//	cout << endl;
//	l1 = mecifotbal; // = operator
//	cout << l1;
//	cout << endl << endl;
//	Event copy(mecifotbal); // Copy constructor
//	cout << copy;
//	cout << endl; 
//	
//	mecifotbal *= 5; cout << endl; // operator *=
//
//	cout << !mecifotbal;  // ! operator
//
//
//
//
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
//
//
//
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
//
//
//
//	// TICKET CLASS /////////////////////////////////////////////////////
//
//
//	return 0;
//}