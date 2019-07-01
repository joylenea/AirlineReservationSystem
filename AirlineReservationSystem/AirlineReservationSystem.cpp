#include "stdafx.h"
#include <iostream>
#include "Database.h"
#include "Database.h"
#include "User.h"
#include "Flight.h"


using namespace std;
using namespace AirlineReservationSystem;

int displayMenu();
void reserveSeat(Database& db);
void displayFlightSchedule(Database& db);
void displayPassengerInfo(Database& db);
void displayFlightInfo(Database& db);
void userTicketInfo(Database& db);
Flight& chooseFlight(Database& db);


int main()
{
	Database airlineDB;

	Flight f1("Los Angeles", "London", 1, 200);
	Flight f2("Seattle", "Munich", 2, 120);
	Flight f3("San Diego", "Copenhagen",3, 90);
	Flight f4("Tokyo", "New York", 4, 120);
	Flight f5("Chicago", "Manila", 5, 190);

	airlineDB.addFlight(f1);
	airlineDB.addFlight(f2);
	airlineDB.addFlight(f3);
	airlineDB.addFlight(f4);
	airlineDB.addFlight(f5);

	while (true) 
	{
		int selection = displayMenu();
		switch (selection) 
		{
		case 0:
			return 0;
		case 1:
			reserveSeat(airlineDB);
			break;
		case 2:
			displayFlightSchedule(airlineDB);
			break;
		case 3:
			displayPassengerInfo(airlineDB);
			break;
		case 4:
			displayFlightInfo(airlineDB);
			break;
		case 5:
			userTicketInfo(airlineDB);
			break;
		default:
			cerr << "Unknown Command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "::::::::::::::::::::::::::::::::::" << endl;
	cout << "::: Airline Reservation System :::" << endl;
	cout << "::::::::::::::::::::::::::::::::::" << endl;
	cout << endl;
	cout << "Please select from the following:" << endl;
	cout << "1) Seat Reservation" << endl;
	cout << "2) Flight Schedule" << endl;
	cout << "3) Passenger Information" << endl;
	cout << "4) Flight Details" << endl;
	cout << "5) User Ticket Information" << endl;
	cout << "0) Quit" << endl;
	cout << ".................................." << endl;
	cout << endl;
	cout << "--> ";

	cin >> selection;

	return selection;
}

void displayFlightSchedule(Database& db) 
{
	vector<Flight>& allFlights = db.getAllFlight();
	for (Flight& f : allFlights) {
		f.display();
	}
}

Flight& chooseFlight(Database& db) 
{
	int flightId;
	cout << "Choose Flight Number " << endl;
	displayFlightSchedule(db);
	cin >> flightId;
	Flight& flight = db.getFlight(flightId);
	return flight;
}

User& getUserData() 
{
	string firstName;
	string lastName;
	int userId;
	cout << "Enter First Name:";
	cin >> firstName;
	cout << "Enter Last Name:";
	cin >> lastName;
	cout << "Enter Passport ID Number: ";
	cin >> userId;

	User* user = new User(firstName, lastName, userId);
	return *user;
}

void reserveSeat(Database& db)
{
	int chosenSeat;

	Flight& flight = chooseFlight(db);
	vector<int>& freeSeats = flight.getFreeSeats();
	for (int seat : freeSeats) 
	{
		cout << seat << " ";
	}
	cout << endl << "Select a Seat " << endl;
	cin >> chosenSeat;

	User& user = getUserData();
	user.setSeatNumber(chosenSeat);
	flight.reserveSeat(user);
}

void displayPassengerInfo(Database& db) 
{

	Flight& flight = chooseFlight(db);

	vector<User>& users = flight.getPassengers();
	for (User& user : users) {
		cout << "Passenger Information:" << endl;
		cout << "-------------------------" << endl;
		cout << "Seat Number: " << user.getSeatNumber() << endl;
		cout << "Name: " << user.getFirstName() << " " << user.getLastName() << endl;
		cout << "Flight Number: " << flight.getFlightNumber() << endl;
		cout << "Departing From: " << flight.getDepartureCity() << "\n" << "Arriving In: " << flight.getDestinationCity() << endl;
		cout << endl;
	}
}

void userTicketInfo(Database& db)
{
	Flight& flight = chooseFlight(db);

	int userId;
	cout << "Please Enter Passport ID Number: ";
	cin >> userId;

	vector<User>& users = flight.getPassengers();
	bool userFound = false;
	for (User& user : users) {
		if (userId == user.getIdNumber()) 
		{
			userFound = true;
			cout << "Passenger Information:" << endl;
			cout << "-------------------------" << endl;
			cout << "Name: " << user.getFirstName() << " " << user.getLastName() << endl;
			cout << "Flight Number: " << flight.getFlightNumber() << endl;
			cout << "Departing From: " << flight.getDepartureCity() << "\n" << "Arriving In: " << flight.getDestinationCity() << endl;
			cout << "Seat Number: " << user.getSeatNumber() << endl;
			cout << endl;
		}
	}
	if (userFound == false) 
	{
		cout << "Passenger could not be found." << endl;
	}
}

void displayFlightInfo(Database& db) 
{
	Flight& flight = chooseFlight(db);
	flight.display();
	vector<int>& freeSeats = flight.getFreeSeats();
	vector<User>& seatsBooked = flight.getPassengers();
	cout << "Open Seats Remaining: " << freeSeats.size() << endl;
	cout << "Seats Reserved: " << seatsBooked.size() << endl;
}


