#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"

namespace AirlineReservationSystem 
{
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& destinationCity, const std::string& departureCity,
			int flightNumber, int seatsAmount);

		void display() const;

		//Getters and setters
		const std::string& getDestinationCity() const;

		const std::string& getDepartureCity() const;

		int getFlightNumber() const;


		std::vector<int>& getFreeSeats(); 

		void reserveSeat(User& user);			

		std::vector<User>& getPassengers();

	private:
		std::string mDestinationCity;
		std::string mDepartureCity;
		std::vector<User> mUsers;
		std::vector<int> mFreeSeats;
		int mFlightNumber = -1;
	};
}