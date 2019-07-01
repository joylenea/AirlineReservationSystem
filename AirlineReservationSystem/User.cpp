#include "stdafx.h"
#include <string>
#include <vector>
#include "User.h"


using namespace std;

namespace AirlineReservationSystem {
	User::User(const std::string& fisrtName, const std::string& lastName, int idNumber)
		: mFirstName(fisrtName), mLastName(lastName), mIdNumber(idNumber){}

	const std::string& User::getFirstName() const 
	{
		return mFirstName;
	}

	const std::string& User::getLastName() const 
	{
		return mLastName;
	}

	int User::getIdNumber() const 
	{
		return mIdNumber;
	}

	void User::setSeatNumber(int seatNumber) 
	{
		mSeatNumber = seatNumber;
	}

	int User::getSeatNumber() const {
		return mSeatNumber;
	}
}