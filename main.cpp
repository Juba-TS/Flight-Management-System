#include <iostream>

using namespace std;

class Ticket
{
private:
	int ticketID;
	int passportNumber;
public:
	Ticket()
	{
		ticketID = 0;
		passportNumber = 0;
	}
	Ticket(int newID, int newPass)
	{
		ticketID = newID;
		passportNumber = newPass;
	}
	void setID(int newID)
	{
		ticketID = newID;
	}
	void setPassportNumber(int newPass)
	{
		passportNumber = newPass;
	}
	int getID()
	{
		return ticketID;
	}
	int getPassportNumber()
	{
		return passportNumber;
	}
};
class Flight
{
private:
	Ticket* ticketArray;
	string airline;
	string country;
	char statusOfFlight;	//O for ontime, D for delayed, M for Missed
	char type;	// D for domestic I for international
	int availableTickets;
	int flightNumber;
	int departureTime[3];	// hr min sec
	int arrivalTime[3];
	int date[3];		//day month year
public:
	Flight()
	{
		ticketArray = NULL;
		airline = '\0';
		country = '\0';
		statusOfFlight = '\0';
		type = '\0';
		availableTickets = 0;
		flightNumber = 0;
		for (int counter = 0;counter < 3;counter++)
		{
			departureTime[counter] = 0;
			arrivalTime[counter] = 0;
		}
	}
	Flight(Ticket* newArr, string newAirline, string newCountry,
		char newStatus, char newType, int newTickets, int newFlightNumber, int newDeptTime[], int newArrTime[],int newDates[])
	{
		ticketArray = newArr;
		airline = newAirline;
		country = newCountry;
		statusOfFlight = newStatus;
		type = newType;
		availableTickets = newTickets;
		flightNumber = newFlightNumber;
		for (int counter = 0;counter < 3;counter++)
		{
			departureTime[counter] = newDeptTime[counter];
			arrivalTime[counter] = newArrTime[counter];
		}
	}

	// Setters
	void setTicketArr(Ticket* newArr)
	{
		ticketArray = newArr;
	}
	void setAirline(string newAirline)
	{
		airline = newAirline;
	}
	void setCountry(string newCountry)
	{
		country = newCountry;
	}
	void setStatusOfFlight(char newStatus)
	{
		statusOfFlight = newStatus;
	}
	void setType(char newType)
	{
		type = newType;
	}
	void setAvailableTickets(int newAvailableTickets)
	{
		availableTickets = newAvailableTickets;
	}
	void setFlightNumber(int newFlight)
	{
		flightNumber = newFlight;
	}
	void setDepartureTime(int newDeptTimes[])
	{
		for (int counter = 0;counter < 3;counter++)
			departureTime[counter] = newDeptTimes[counter];
	}
	void setArrivalTime(int newArrivalTimes[])
	{
		for (int counter = 0;counter < 3;counter++)
			arrivalTime[counter] = newArrivalTimes[counter];
	}
	void setDate(int newDates[])
	{
		for (int counter = 0;counter < 3;counter++)
			date[counter] = newDates[counter];
	}

	// Getters
}
int main ()
{
    cout << "Hello World \n";
    
    yes
    
    return o;
}
