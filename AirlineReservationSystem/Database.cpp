
#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace AirlineReservationSystem 
{

	void Database::addFlight(Flight& flight) 
	{ 
		mFlights.push_back(flight); 
	}

	Flight& Database::getFlight(int flightNumber) 
	{ 
		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == flightNumber) 
			{
				return flight;
			}
		}
		throw logic_error("Flight Number could not be found.");
	}

	vector<Flight>& Database::getAllFlight() { return mFlights; }
}
