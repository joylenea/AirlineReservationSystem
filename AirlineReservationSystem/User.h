#pragma once
#include <string>


namespace AirlineReservationSystem 
{
	class User
	{
	public:
		User(const std::string& fisrtName, const std::string& lastName, int idNumber);

		//Getters and setters
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		int getIdNumber() const;

		void setSeatNumber(int seatNumber);
		int getSeatNumber() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		int mIdNumber = -1;
		int mSeatNumber = -1;
	};
}