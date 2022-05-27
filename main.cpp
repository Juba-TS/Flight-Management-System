#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class User
{
private:
	string username;
	string password;
public:
	//constructors
	User()
	{
		username[0] = '\0';
		password[0] = '\0';
	}
	User(string newName, string newPassword)
	{
		username = newName;
		password = newPassword;
	}
	User(const User& newUser)
	{
		username = newUser.username;
		password = newUser.password;

	}
	//setters
	void setUsername(string newName)
	{
		username = newName;
	}
	void setPassword(string newPassword)
	{
		password = newPassword;
	}
	//getters
	string getUsername()
	{
		return username;
	}
	string getPassword()
	{
		return password;
	}
	// Print Function
};

class Passenger :public User
{
private:
	string passengerName;
	string nationality;
	long long int passportNo;
	int ticketsBooked;
	int* ticketId;
public:

	//Constructors
	Passenger()
	{
		passengerName[0] = '\0';
		nationality[0] = '\0';
		passportNo = 0;
		ticketsBooked = 0;
		ticketId = 0;
	}
	Passenger(string newName, string newPassword, string newPassengerName, string newNationality,
		long long int newPassportNo, int totaltickets, int* newticketid) : User(newName, newPassword)
	{
		passengerName = newPassengerName;
		nationality = newNationality;
		passportNo = newPassportNo;
		ticketsBooked = totaltickets;
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newticketid[i];
		}
	}
	Passenger(const User& newUser, const Passenger& newPassenger) :User(newUser)
	{
		passengerName = newPassenger.passengerName;
		nationality = newPassenger.nationality;
		passportNo = newPassenger.passportNo;
		ticketsBooked = newPassenger.ticketsBooked;
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newPassenger.ticketId[i];
		}
	}


	//Setters
	void SetPassengerName(string newPassengerName)
	{
		passengerName = newPassengerName;
	}
	void SetNationality(string newNationality)
	{
		nationality = newNationality;
	}
	void SetPassportNo(long long int newPassportNo)
	{
		passportNo = newPassportNo;
	}
	void SetTicketsBooked(int totaltickets)
	{
		ticketsBooked = totaltickets;
	}
	void SetTicketIds(int* newticketid)
	{
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newticketid[i];
		}
	}

	//Getters
	string GetPassengerName()
	{
		return passengerName;
	}
	string GetNationality()
	{
		return nationality;
	}
	long long int GetPassportNo()
	{
		return passportNo;
	}
	int GetTicketsBooked()
	{
		return ticketsBooked;
	}
	int* GetTicketIds()
	{
		return ticketId;
	}
};

class Admin : public User
{
private:
	string adminName;
public:

	//constructors
	Admin()
	{
		adminName[0] = '\0';

	}
	Admin(string newName, string newPassword, string newAdminName) :User(newName, newPassword)
	{
		adminName = newAdminName;
	}
	Admin(const User& newUser, const Admin& newAdmin) :User(newUser)
	{
		adminName = newAdmin.adminName;
	}
	//setter
	void SetAdminName(string newAdminName)
	{
		adminName = newAdminName;
	}

	//getter
	string GetAdminName()
	{
		return adminName;
	}
};

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

class Date
{
public:
	int day;
	int month;
	int year;

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int newDay, int newMonth, int newYear)
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
};

class Time
{
public:
	int hour;
	int minutes;
	int seconds;

	Time()
	{
		hour = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int newHours, int newMinutes, int newSeconds)
	{
		hour = newHours;
		minutes = newMinutes;
		seconds = newSeconds;
	}
};

class Airline
{
private:
	string airlineName;
	int airlineID;
public:
	Airline()
	{
		airlineName = '\0';
		airlineID = 0;
	}
	Airline(string newName, int newID)
	{
		airlineName = newName;
		airlineID = newID;
	}
	void setAirlineName(string newName)
	{
		airlineName = newName;
	}
	void setAirlineID(int newID)
	{
		airlineID = newID;
	}
	string getAirlineName()
	{
		return airlineName;
	}
	int getAirlineID()
	{
		return airlineID;
	}
};

class InternationalFlight :virtual public Airline
{
private:
	string country;
public:
	InternationalFlight() : Airline()
	{
		country = '\0';
	}
	InternationalFlight(string newName, int newID, string newCountry = "Nothing set") : Airline(newName, newID)
	{
		country = newCountry;
	}
	void setCountry(string newCountry)
	{
		country = newCountry;
	}
	string getCountry()
	{
		return country;
	}
};

class LocalFlight : virtual public Airline
{
private:
	string city;
public:
	LocalFlight() : Airline()
	{
		city = '\0';
	}
	LocalFlight(string newName, int newID, string newCity = "Nothing set") : Airline(newName, newID)
	{
		city = newCity;
	}
	void setCity(string newCity)
	{
		city = newCity;
	}
	string getCity()
	{
		return city;
	}
};

class Plane : public InternationalFlight, public LocalFlight
{
private:
	Ticket* ticketArray;
	char statusOfFlight;	//O for ontime, D for delayed, M for Missed
	int availableTickets;
	int bookedTickets;
	int flightNumber;
	Time departureTime;
	Time arrivalTime;
	Date flightDate;
public:
	Plane()
	{
		ticketArray = NULL;
		statusOfFlight = '\0';
		availableTickets = 0;
		bookedTickets = 0;
		flightNumber = 0;
		flightDate.day = 0;
		flightDate.month = 0;
		flightDate.year = 0;
		departureTime.hour = 0;
		departureTime.minutes = 0;
		departureTime.seconds = 0;
		arrivalTime.hour = 0;
		arrivalTime.minutes = 0;
		arrivalTime.seconds = 0;
	}

	Plane(Ticket* newArr, char newStatus, int newTickets, int newBookedTickets ,int newFlightNumber, Time newDeptTime, Time newArrTime, Date newDate, string newName,
		int newID) : InternationalFlight(newName, newID), LocalFlight(newName, newID)
	{
		ticketArray = newArr;
		statusOfFlight = newStatus;
		availableTickets = newTickets;
		bookedTickets = newBookedTickets;
		flightNumber = newFlightNumber;
		flightDate.day = newDate.day;
		flightDate.month = newDate.month;
		flightDate.year = newDate.year;
		departureTime.hour = newDeptTime.hour;
		departureTime.minutes = newDeptTime.minutes;
		departureTime.seconds = newDeptTime.seconds;
		arrivalTime.hour = newArrTime.hour;
		arrivalTime.minutes = newArrTime.minutes;
		arrivalTime.seconds = newArrTime.seconds;
	}

	// Setters
	void setTicketArr(Ticket* newArr)
	{
		ticketArray = newArr;
	}
	void setStatusOfFlight(char newStatus)
	{
		statusOfFlight = newStatus;
	}
	void setAvailableTickets(int newAvailableTickets)
	{
		availableTickets = newAvailableTickets;
	}
	void setBookedTickets(int newBookedTickets)
	{
		bookedTickets = newBookedTickets;
	}
	void setFlightNumber(int newFlight)
	{
		flightNumber = newFlight;
	}
	void setDepartureTime(Time newDeptTime)
	{
		departureTime.hour = newDeptTime.hour;
		departureTime.minutes = newDeptTime.minutes;
		departureTime.seconds = newDeptTime.seconds;
	}
	void setArrivalTime(Time newArrivalTime)
	{
		arrivalTime.hour = newArrivalTime.hour;
		arrivalTime.minutes = newArrivalTime.minutes;
		arrivalTime.seconds = newArrivalTime.seconds;
	}
	void setDate(Date newDate)
	{
		flightDate.day = newDate.day;
		flightDate.month = newDate.month;
		flightDate.year = newDate.year;
	}

	// Getters
	Ticket* getTickets()
	{
		return ticketArray;
	}
	char getStatusOfFlight()
	{
		return statusOfFlight;
	}
	int getAvailableTickets()
	{
		return availableTickets;
	}
	int getBookedTickets()
	{
		return bookedTickets;
	}
	int getUnbookedTickets()
	{
		return availableTickets - bookedTickets;
	}
	int getFlightNumber()
	{
		return flightNumber;
	}
	Time getDepartureTime()
	{
		return departureTime;
	}
	Time getArrivalTime()
	{
		return arrivalTime;
	}
	Date getDate()
	{
		return flightDate;
	}
};

void MainMenu()
{
	system("CLS");
	cout << "Welcome to the Flight Management System!!" << endl;
	cout << endl;
	cout << "Choose one of the options down below!" << endl;
	cout << "1. For Admin" << endl;
	cout << "2. For Passenger" << endl;
	cout << "0. To exit the program" << endl;
	cout << "=> ";
}

void AdminMenu()
{
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Search through completed flights" << endl;
	cout << "2. Add new flights to the database" << endl;
	cout << "3. Remove flights from the database" << endl;
	cout << "4. Edit details of a flight" << endl;
	cout << "5. Display Passengers (Based on flight number, nationality or passport number)" << endl;
	cout << "6. Search through flights" << endl;
	cout << "=> ";
}

void PassengerMenu()
{
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Display available flights" << endl;
	cout << "2. Book a flight" << endl;
	cout << "3. Edit your details (Passenger details)" << endl;
	cout << "4. Search through flights" << endl;
	cout << "=> ";
}

void PassengerFileName(string &passengerFile)
{

	cout << "Enter the name of file containing passenger records (filename should have its file type at the end e.g passengers.dat): ";
	getline(cin, passengerFile, '\n');

}
void PlaneFileName(string &PassengerFile)
{

	cout << "Enter the name of file containing plane records (filename should have its file type at the end e.g planes.dat): ";
	getline(cin, PassengerFile, '\n');

}

void InputPassengerData(Passenger*& PassengerData, int& totalPassengers, string PassengerFile)
{
	delete[] PassengerData;

	ifstream fin;
	totalPassengers = 0;
	char c;
	fin.open(PassengerFile);

	while (!(fin.eof()))
	{
		fin >> c;
		
		if (c == '.')
		{
			totalPassengers++;
		}
	}
	fin.close();

	totalPassengers--;

	PassengerData = new Passenger[totalPassengers];

	string username, password, passengername, nationality;
	int TotalTickets;
	long long int passportNo;
	int* ticketids;

	fin.open(PassengerFile);
	for (int c = 0; c < totalPassengers; c++)
	{
		getline(fin, username, ',');
		fin.ignore();
		getline(fin, password, ',');
		fin.ignore();
		getline(fin, passengername, ',');
		fin.ignore();
		getline(fin, nationality, ',');
		fin.ignore();
		fin >> passportNo;
		fin.ignore();
		fin >> TotalTickets;
		fin.ignore();

		ticketids = new int[TotalTickets];

		for (int i = 0; i < TotalTickets; i++)
		{
			fin >> ticketids[i];
			
		}

		fin.ignore();
		
		PassengerData[c].setUsername(username);
		PassengerData[c].setPassword(password);
		PassengerData[c].SetPassengerName(passengername);
		PassengerData[c].SetNationality(nationality);
		PassengerData[c].SetPassportNo(passportNo);
		PassengerData[c].SetTicketsBooked(TotalTickets);
		PassengerData[c].SetTicketIds(ticketids);
	}
	fin.close();
}

void InputPlaneData(Plane*& PlaneData, int& totalPlanes, string PlaneFile)
{
	delete[] PlaneData;

	ifstream fin;
	totalPlanes = 0;
	char c;
	fin.open(PlaneFile);

	while (!(fin.eof()))
	{
		fin >> c;

		if (c == '.')
		{
			totalPlanes++;
		}
	}
	fin.close();

	totalPlanes--;

	PlaneData = new Plane[totalPlanes];

	string airlineName, country, city;
	char status;
	Time departure, arrival;
	Date flightDate;
	int airlineID = 0, availableTickets = 0, flightNo = 0, bookedTickets = 0;

	fin.open(PlaneFile);
	for (int i = 0; i < totalPlanes; i++)
	{
		getline(fin, airlineName, ',');
		fin.ignore();
		fin >> airlineID;
		fin.ignore(2);
		getline(fin, city, ',');
		fin.ignore();
		getline(fin, country, ',');
		fin.ignore();
		fin >> status;
		fin.ignore();
		fin >> availableTickets;
		fin.ignore();
		fin >> bookedTickets;
		fin.ignore();
		fin >> flightNo;
		fin.ignore();
		fin >> arrival.hour;
		fin.ignore();
		fin >> arrival.minutes;
		fin.ignore();
		fin >> arrival.seconds;
		fin.ignore();
		fin >> departure.hour;
		fin.ignore();
		fin >> departure.minutes;
		fin.ignore();
		fin >> departure.seconds;
		fin.ignore();
		fin >> flightDate.day;
		fin.ignore();
		fin >> flightDate.month;
		fin.ignore();
		fin >> flightDate.year;
		fin.ignore();

		Ticket* tickets = new Ticket[availableTickets];
		int ticketID = 0, passportNo = 0;
		for (int j = 0; j < bookedTickets; j++)
		{
			fin >> ticketID;
			fin >> passportNo;

			tickets[j].setID(ticketID);
			tickets[j].setPassportNumber(passportNo);
			
			fin.ignore();
		}
		fin.ignore();

		PlaneData[i].setAirlineName(airlineName);
		PlaneData[i].setAirlineID(airlineID);
		PlaneData[i].setCountry(country);
		PlaneData[i].setCity(city);
		PlaneData[i].setDate(flightDate);
		PlaneData[i].setArrivalTime(arrival);
		PlaneData[i].setDepartureTime(departure);
		PlaneData[i].setAvailableTickets(availableTickets);
		PlaneData[i].setBookedTickets(bookedTickets);
		PlaneData[i].setFlightNumber(flightNo);
		PlaneData[i].setStatusOfFlight(status);
		PlaneData[i].setTicketArr(tickets);
	}
	fin.close();
}

void OutputPlaneData( Plane* PlaneData, const int totalPlanes, const string PlaneFile)
{
	ofstream fout;
	fout.open(PlaneFile);
	for (int i = 0; i < totalPlanes; i++)
	{
		Time arrival = PlaneData[i].getArrivalTime();
		Time departure = PlaneData[i].getDepartureTime();
		Date dateflight = PlaneData[i].getDate();
		Ticket* tickets = PlaneData[i].getTickets();

		fout << PlaneData[i].getAirlineName() << ", ";
		fout << PlaneData[i].getAirlineID() << ", ";
		fout << PlaneData[i].getCity() << ", ";
		fout << PlaneData[i].getCountry() << ", ";
		fout << PlaneData[i].getStatusOfFlight() << ", ";
		fout << PlaneData[i].getAvailableTickets() << ", ";
		fout << PlaneData[i].getBookedTickets() << ", ";
		fout << PlaneData[i].getFlightNumber() << ", ";
		fout << arrival.hour << ":" << arrival.minutes << ":" << arrival.seconds << ", ";
		fout << departure.hour << ":" << departure.minutes << ":" << departure.seconds << ", ";
		fout << dateflight.day << "/" << dateflight.month << "/" << dateflight.year << ", ";

		for (int j = 0; j < (PlaneData[i].getBookedTickets()); j++)
		{
			fout << tickets[j].getID() << " " << tickets[j].getPassportNumber();
			if (j == ( PlaneData[i].getBookedTickets()) - 1)
			{
				fout << ".";
			}
			else
			{
				fout << ", ";
			}
		}
		fout << endl;
	}
}



int main()
{
	string passengerFile, PlaneFile;
	PassengerFileName(passengerFile);
	PlaneFileName(PlaneFile);

	int totalPassengers = 0, totalPlanes = 0;

	Passenger* PassengerData = nullptr;
	InputPassengerData(PassengerData, totalPassengers, passengerFile);

	Plane* PlaneData = nullptr;
	InputPlaneData(PlaneData, totalPlanes, PlaneFile);
	
	OutputPlaneData(PlaneData, totalPlanes, PlaneFile);

	

	//To check whther Plane input is working or not

	for (int i = 0; i < totalPlanes; i++)
	{
		Time arrival = PlaneData[i].getArrivalTime();
		Time departure = PlaneData[i].getDepartureTime();
		Date dateflight = PlaneData[i].getDate();
		Ticket* tickets = PlaneData[i].getTickets();

		cout << PlaneData[i].getAirlineName() << ", ";
		cout << PlaneData[i].getAirlineID() << ", ";
		cout << PlaneData[i].getCity() << ", ";
		cout << PlaneData[i].getCountry() << ", ";
		cout << PlaneData[i].getStatusOfFlight() << ", ";
		cout << PlaneData[i].getAvailableTickets() << ", ";
		cout << PlaneData[i].getBookedTickets() << ", ";
		cout << PlaneData[i].getFlightNumber() << ", ";
		cout << arrival.hour << ":" << arrival.minutes << ":" << arrival.seconds << ", ";
		cout << departure.hour << ":" << departure.minutes << ":" << departure.seconds << ", ";
		cout << dateflight.day << "/" << dateflight.month << "/" << dateflight.year << ", ";

		for (int j = 0; j < (PlaneData[i].getBookedTickets()); j++)
		{
			cout << tickets[j].getID() << " " << tickets[j].getPassportNumber();
			if (j == (PlaneData[i].getBookedTickets()) - 1)
			{
				cout << ".";
			}
			else
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
	




	//To check if correct passenger input is being saved
	/*for (int i = 0; i < totalPassengers; i++)
	{
		cout << PassengerData[i].getUsername() << " ";
		cout << PassengerData[i].getPassword() << " ";
		cout << PassengerData[i].GetPassengerName() << " ";
		cout << PassengerData[i].GetNationality() << " ";
		cout << PassengerData[i].GetPassportNo() << " ";
		cout << PassengerData[i].GetTicketsBooked() << " ";

		int* tickets = PassengerData[i].GetTicketIds();

		for (int j = 0; j < PassengerData[i].GetTicketsBooked(); j++)
		{
			cout << tickets[j] << " ";
		}
	}*/

	

	// Testing everything
	//MainMenu();
	//AdminMenu();
	//PassengerMenu();

	




	return 0;
}
