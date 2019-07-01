#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Flight.h"


using namespace std;

namespace AirlineReservationSystem 
{
	Flight::Flight(const std::string& destinationCity, const std::string& departureCity, int flightNumber, int seatsAmount)
		: mDestinationCity(destinationCity), mDepartureCity(departureCity), mFlightNumber(flightNumber) 
	{
		for (int i = 1; i <= seatsAmount; i++) 
		{
			mFreeSeats.push_back(i);
		}
	}
	
	const string& Flight::getDestinationCity() const
	{
		return mDestinationCity;
	}

	const string& Flight::getDepartureCity() const
	{
		return mDepartureCity;
	}

	int Flight::getFlightNumber() const 
	{
		return mFlightNumber;
	}

	vector<int>& Flight::getFreeSeats() 
	{
		return mFreeSeats;
	}

	void Flight::reserveSeat(User& user) 
	{
		mUsers.push_back(user);
		int seatNumber = user.getSeatNumber();
		mFreeSeats.erase(std::remove(mFreeSeats.begin(),
			mFreeSeats.end(), seatNumber), mFreeSeats.end());
	}

	vector<User>& Flight::getPassengers() 
	{
		return mUsers;
	}

	void Flight::display() const
	{
		cout << "#" << getFlightNumber() << " " << getDestinationCity() << " to " << getDepartureCity() << endl;
	}
}