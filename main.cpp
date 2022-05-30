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

	bool operator == (const User& newUser)
	{
		if (username == newUser.username && password == newUser.password)
		{
			return true;
		}
		else
			return false;
	}
	bool operator !=(const User& newUser)
	{
		if (username != newUser.username && password != newUser.password)
		{
			return true;
		}
		else
			return false;
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
	void DeleteTicketIds()
	{
		delete[] ticketId;
		ticketId = nullptr;
	}
	//operator overloading
	friend ostream& operator << (ostream& out, const Passenger& newPasenger);
	friend ostream& operator << (ostream& out, const Passenger& newPasenger);
	//friend istream& operator >> (istream& in, const Passenger& newPasenger);



};
ostream& operator << (ostream& out, Passenger& newPassenger)
{


	cout << newPassenger.getUsername() << ", ";
	cout << newPassenger.getPassword() << ", ";
	cout << newPassenger.GetPassengerName() << ", ";
	cout << newPassenger.GetNationality() << ", ";
	cout << newPassenger.GetPassportNo() << ", ";
	cout << newPassenger.GetTicketsBooked() << ",";
	int* tickets = newPassenger.GetTicketIds();
	for (int j = 0; j < newPassenger.GetTicketsBooked(); j++)
	{
		cout << " " << tickets[j];
	}
	cout << ".";

	return out;

}



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
	Date(const Date& copyObj)
	{
		day = copyObj.day;
		month = copyObj.month;
		year = copyObj.year;
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
	Time(const Time& newObj)
	{
		hour = newObj.hour;
		minutes = newObj.minutes;
		seconds = newObj.seconds;
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
		airlineID = -1;
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
	char statusOfFlight;	//O for ontime, D for delayed, M for Missed, C for completed
	int availableTickets;
	int bookedTickets;
	int flightNumber;
	Time departureTime;
	Time arrivalTime;
	Date flightDate;
public:
	Plane() :InternationalFlight(), LocalFlight()
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

	Plane(Ticket* newArr, char newStatus, int newTickets, int newBookedTickets, int newFlightNumber, Time newDeptTime, Time newArrTime, Date newDate, string newName,
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
	Plane(const Plane& obj)
	{
		ticketArray = obj.ticketArray;
		statusOfFlight = obj.statusOfFlight;
		availableTickets = obj.availableTickets;
		bookedTickets = obj.bookedTickets;
		flightNumber = obj.flightNumber;
		flightDate = obj.flightDate;
		departureTime = obj.departureTime;
		arrivalTime = obj.arrivalTime;
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
	~Plane()
	{
		delete[] ticketArray;
	}
};

////////////////////////////////////////////Menu Functions Start Here////////////////////////////////
int getChoice()
{
	int choice = 0;

	cin >> choice;
	while (!cin.good())
	{
		cout << "Invalid Input (Wrong Data Type)\n";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "=>";
		cin >> choice;
	}
	return choice;
}


int MainMenu()
{
	int choice = 0;
	system("CLS");
	cout << "Welcome to the Flight Management System!!" << endl;
	cout << endl;
	cout << "Choose one of the options down below!" << endl;
	cout << "1. For Admin" << endl;
	cout << "2. For Passenger" << endl;
	cout << "0. To exit the program" << endl;
	cout << "=> ";
	choice = getChoice();
	return choice;

}
int SignInMenu()
{
	int choice = 0;
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Log In" << endl;
	cout << "2. Sign Up" << endl;
	cout << "0. To exit the program" << endl;
	cout << "=> ";
	choice = getChoice();
	return choice;
}

int AdminMenu()
{
	int choice = 0;
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Search through completed flights" << endl;
	cout << "2. Add new flights to the database" << endl;
	cout << "3. Remove flights from the database" << endl;
	cout << "4. Edit details of a flight" << endl;
	cout << "5. Display Passengers (Based on flight number, nationality or passport number)" << endl;
	cout << "6. Search through flights" << endl;
	cout << "=> ";
	choice = getChoice();
	return choice;

}

int PassengerMenu()
{
	int choice = 0;
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Display available flights" << endl;
	cout << "2. Book a flight" << endl;
	cout << "3. Edit your details (Passenger details)" << endl;
	cout << "4. Search through flights" << endl;
	cout << "=> ";
	choice = getChoice();
	return choice;

}
int EditTicketMenu()
{
	int choice = 0;
	system("CLS");
	cout << "Choose whatever you would like to do:" << endl;
	cout << "1. Add Ticket" << endl;
	cout << "2. Delete Ticket" << endl;
	cout << "=> ";
	choice = getChoice();
	return choice;

}

/////////////////////////////////////////////////////Menu Functions ENd here/////////////////////////////////////////////////////////

//////////////////////////////////////////////////////Sarmad's Input Functions Start here///////////////////////////////////////////////

void PassengerFileName(string& passengerFile)
{

	cout << "Enter the name of file containing passenger records (filename should have its file type at the end e.g passengers.dat): ";
	getline(cin, passengerFile, '\n');

}
void PlaneFileName(string& PassengerFile)
{

	cout << "Enter the name of file containing plane records (filename should have its file type at the end e.g planes.dat): ";
	getline(cin, PassengerFile, '\n');

}
void InputPassengerData(Passenger*& PassengerData, int& totalPassengers, string PassengerFile)
{
	ifstream fin;
	totalPassengers = 0;
	if (!PassengerData)
	{
		delete[] PassengerData;
	}

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
		if (c > 0)
		{
			fin.ignore();
		}
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

		if (bookedTickets == 0)
		{
			fin >> ticketID;
			fin >> passportNo;

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
void OutputPlaneData(Plane* PlaneData, const int totalPlanes, const string PlaneFile)
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
			if (j == (PlaneData[i].getBookedTickets()) - 1)
			{
				fout << ".";
			}
			else
			{
				fout << ", ";
			}
		}

		if (PlaneData[i].getBookedTickets() == 0)
		{
			fout << "0 0.";
		}
		fout << endl;
	}
	fout.close();
}

///////////////////////////////////////////////////////////SArmad's Functions end here///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////Haseeb's functions Start Here///////////////////////////////////////////////////////////////////////////////////////////

Plane returnFlight(Plane* obj, const int totalPlanes, const int searchNum)	// If flight number same, returns the object with same flight number
{
	for (int counter = 0; counter < totalPlanes; counter++)
	{
		if (obj->getFlightNumber() == searchNum)
		{
			cout << "Flight Found!" << endl;
			return obj[counter];
		}
	}
	return Plane();
}
void FlightDisplay(Plane obj)	// Displays specific flight sent as parameter
{
	Time tempTime = obj.getDepartureTime();
	Date tempDate = obj.getDate();
	cout << "Available number of booked Tickets: " << obj.getBookedTickets() << endl;
	cout << "Available number of unbooked Tickets: " << obj.getUnbookedTickets() << endl;
	cout << "Flight Status: " << obj.getStatusOfFlight() << endl;
	cout << "Flight Number: " << obj.getFlightNumber() << endl;
	cout << "Flight Date: " << tempDate.day << "/" << tempDate.month << "/" << tempDate.year << endl;
	cout << "Departure Time: " << tempTime.hour << ":" << tempTime.minutes << ":" << tempTime.seconds << endl;
	tempTime = obj.getArrivalTime();
	cout << "Arrival Time: " << tempTime.hour << ":" << tempTime.minutes << ":" << tempTime.seconds << endl << endl;
}
void InputFlightDetails(Plane*& obj, const int position)
{
	string airlineName, city, country;
	int airlineID, avaiableTickets, bookedTickets, flightID, ticketID, passportNum;
	char status;
	Time arrivalTime, departureTime;
	Date newDate;

	cin.ignore();
	cout << "Enter the Airline Name: ";
	getline(cin, airlineName);
	cout << "Enter the Airline ID: ";
	cin >> airlineID;
	while (airlineID < 0)
	{
		cout << "Invalid Airline ID. Please enter again: ";
		cin >> airlineID;
	}
	cin.ignore();
	cout << "Enter the city of the flight: ";
	getline(cin, city);
	cin.ignore();
	cout << "Enter the country of the flight: ";
	getline(cin, country);
	cout << "Enter the status of the flight: ";
	cin >> status;
	status = toupper(status);
	while (status != 'C' && status != 'O' && status != 'M' && status != 'D')
	{
		cout << "Invalid status. Please enter again: ";
		cin >> status;
		status = toupper(status);
	}
	cout << "Enter the available number tickets of the flight: ";
	cin >> avaiableTickets;
	while (avaiableTickets < 0)
	{
		cout << "Invalid Airline ID. Please enter again: ";
		cin >> avaiableTickets;
	}
	cout << "Enter the number of booked tickets of the flight: ";
	cin >> bookedTickets;
	while (bookedTickets < 0)
	{
		cout << "Invalid Airline ID. Please enter again: ";
		cin >> bookedTickets;
	}
	cout << "Enter the flight ID: ";
	cin >> flightID;
	while (flightID < 0)
	{
		cout << "Invalid Airline ID. Please enter again: ";
		cin >> flightID;
	}

	cout << "Enter the Date\n";
	cout << "Enter Day: ";
	cin >> newDate.day;
	while (newDate.day < 0 || newDate.day > 31)
	{
		cout << "Invalid day entered. Please enter again: ";
		cin >> newDate.day;
	}
	cout << "Enter Month: ";
	cin >> newDate.month;
	while (newDate.month < 0 || newDate.month > 12)
	{
		cout << "Invalid day entered. Please enter again: ";
		cin >> newDate.month;
	}
	cout << "Enter year: ";
	cin >> newDate.year;
	while (newDate.year < 2022)
	{
		cout << "Invalid day entered. Please enter again: ";
		cin >> newDate.year;
	}

	cout << "Enter the Arrival Time\n";
	cout << "Enter hours: ";
	cin >> arrivalTime.hour;
	while (arrivalTime.hour > 24 || arrivalTime.hour < 0)
	{
		cout << "Invalid hours. Try again: ";
		cin >> arrivalTime.hour;
	}
	cout << "Enter minutes: ";
	cin >> arrivalTime.minutes;
	while (arrivalTime.minutes > 60 || arrivalTime.minutes < 0)
	{
		cout << "Invalid minutes. Try again: ";
		cin >> arrivalTime.minutes;
	}
	cout << "Enter seconds: ";
	cin >> arrivalTime.seconds;
	while (arrivalTime.seconds > 60 || arrivalTime.hour < 0)
	{
		cout << "Invalid seconds. Try again: ";
		cin >> arrivalTime.seconds;
	}

	cout << "Enter the Departure Time\n";
	cout << "Enter hours: ";
	cin >> departureTime.hour;
	while (departureTime.hour > 24 || departureTime.hour < 0)
	{
		cout << "Invalid hours. Try again: ";
		cin >> departureTime.hour;
	}
	cout << "Enter minutes: ";
	cin >> departureTime.minutes;
	while (departureTime.minutes > 60 || departureTime.minutes < 0)
	{
		cout << "Invalid minutes. Try again: ";
		cin >> departureTime.minutes;
	}
	cout << "Enter seconds: ";
	cin >> departureTime.seconds;
	while (departureTime.seconds > 60 || departureTime.hour < 0)
	{
		cout << "Invalid seconds. Try again: ";
		cin >> departureTime.seconds;
	}

	Ticket* newArr = new Ticket[avaiableTickets];
	for (int counter = 0; counter < avaiableTickets; counter++)
	{
		cout << "Enter Ticket ID: ";
		cin >> ticketID;
		while (ticketID < 0)
		{
			cout << "Invalid Ticket ID. Try again: ";
			cin >> ticketID;
		}
		cout << "Enter the Passport Number: ";
		cin >> passportNum;
		while (passportNum < 0)
		{
			cout << "Invalid Passport Number. Try again: ";
			cin >> passportNum;
		}
		cout << endl;
		newArr[counter].setID(ticketID);
		newArr[counter].setPassportNumber(passportNum);
	}

	obj[position].setAirlineID(airlineID);
	obj[position].setAirlineName(airlineName);
	obj[position].setCity(city);
	obj[position].setCountry(country);
	obj[position].setStatusOfFlight(status);
	obj[position].setAvailableTickets(avaiableTickets);
	obj[position].setBookedTickets(bookedTickets);
	obj[position].setFlightNumber(flightID);
	obj[position].setDate(newDate);
	obj[position].setArrivalTime(arrivalTime);
	obj[position].setDepartureTime(departureTime);
	obj[position].setTicketArr(newArr);
}


Plane CompletedFlights(Plane obj)
{
	if (toupper(obj.getStatusOfFlight()) == 'C')
		return obj;
	else
		return Plane();
}
void DisplayFlights(Plane* obj, const int totalPlanes)
{
	for (int counter = 0; counter < totalPlanes; counter++)
	{
		Time tempTime = obj[counter].getDepartureTime();
		Date tempDate = obj[counter].getDate();
		cout << "Available number of booked Tickets: " << obj[counter].getBookedTickets() << endl;
		cout << "Available number of unbooked Tickets: " << obj[counter].getUnbookedTickets() << endl;
		cout << "Flight Status: " << obj[counter].getStatusOfFlight() << endl;
		cout << "Flight Number: " << obj[counter].getFlightNumber() << endl;
		cout << "Flight Date: " << tempDate.day << "/" << tempDate.month << "/" << tempDate.year << endl;
		cout << "Departure Time: " << tempTime.hour << ":" << tempTime.minutes << ":" << tempTime.seconds << endl;
		tempTime = obj[counter].getArrivalTime();
		cout << "Arrival Time: " << tempTime.hour << ":" << tempTime.minutes << ":" << tempTime.seconds << endl << endl;
	}
	system("pause");
}
void SearchFlights(Plane* obj, const int totalPlanes)
{
	system("CLS");
	Plane tempObj;
	int option = 0;
	int tempChoice = 0;
	int flightNum = 0;
	bool Found = false;
	string searchTemp;

	cout << "What would you like to search by? " << endl;
	cout << "1. By Flight Number" << endl;
	cout << "2. By Location" << endl;
	cout << "3. By Time" << endl;
	cout << "4. By Airline" << endl;
	cout << "5. By completed flights" << endl;
	cout << "0. Exit Search Flights Menu" << endl;
	cout << "=> ";
	option = getChoice();
	cout << endl;
	system("CLS");

	if (option == 1)
	{
		cout << "Enter the Flight Number: ";
		cin >> flightNum;
		while (flightNum < 0)
		{
			cout << "Invalid Flight Number has been entered. Please try again: ";
			cin >> flightNum;
		}
		tempObj = returnFlight(obj, totalPlanes, flightNum);
		if (tempObj.getAirlineID() != 0)
			FlightDisplay(tempObj);
	}
	else if (option == 2)
	{
		cout << "Enter choice" << endl;
		cout << "1. Search by City" << endl;
		cout << "2. Search by Country\n=> ";
		tempChoice = getChoice();
		while (tempChoice <= 0 || tempChoice > 2)
		{
			cout << "Invalid choice. Please input again\n=> ";
			tempChoice = getChoice();
		}
		system("CLS");

		cin.ignore();
		cout << "Enter search value: ";
		getline(cin, searchTemp);

		if (tempChoice == 1)
		{
			for (int counter = 0; counter < totalPlanes; counter++)
			{
				if (searchTemp.compare(obj[counter].getCity()) == 0)
					FlightDisplay(obj[counter]);
			}
		}
		else
		{
			for (int counter = 0; counter < totalPlanes; counter++)
			{
				if (searchTemp.compare(obj[counter].getCountry()) == 0)
				{
					FlightDisplay(obj[counter]);
					Found = true;
				}
			}
		}
	}
	else if (option == 3)
	{
		Time objTime;
		Time objTime2;
		cout << "Enter choice" << endl;
		cout << "1. Search by Arrival Time" << endl;
		cout << "2. Search by Departure Time\n=> ";
		tempChoice = getChoice();

		while (tempChoice <= 0 || tempChoice > 2)
		{
			cout << "Invalid choice. Please input again\n=> ";
			tempChoice = getChoice();
		}
		system("CLS");

		cout << "Enter hours: ";
		cin >> objTime.hour;
		while (objTime.hour > 24 || objTime.hour < 0)
		{
			cout << "Invalid hours. Try again: ";
			cin >> objTime.hour;
		}
		cout << "Enter minutes: ";
		cin >> objTime.minutes;
		while (objTime.minutes > 60 || objTime.minutes < 0)
		{
			cout << "Invalid minutes. Try again: ";
			cin >> objTime.minutes;
		}
		cout << "Enter seconds: ";
		cin >> objTime.seconds;
		while (objTime.seconds > 60 || objTime.hour < 0)
		{
			cout << "Invalid seconds. Try again: ";
			cin >> objTime.seconds;
		}

		if (tempChoice == 1)
		{
			for (int counter = 0; counter < totalPlanes; counter++)
			{
				objTime2 = obj[counter].getArrivalTime();
				if (objTime2.hour == objTime.hour && objTime2.minutes == objTime.minutes && objTime2.seconds == objTime.seconds)
				{
					FlightDisplay(obj[counter]);
					Found = true;
				}
			}
		}
		else
		{
			for (int counter = 0; counter < totalPlanes; counter++)
			{
				objTime2 = obj[counter].getDepartureTime();
				if (objTime2.hour == objTime.hour && objTime2.minutes == objTime.minutes && objTime2.seconds == objTime.seconds)
				{
					FlightDisplay(obj[counter]);
					Found = true;
				}
			}
		}
	}
	else if (option == 4)
	{

		cout << "Enter choice: " << endl;
		cout << "1. Search by Airline Name" << endl;
		cout << "2. Search by Airline ID\n=> ";
		tempChoice = getChoice();
		while (tempChoice < 0 || tempChoice>2)
		{
			cout << "Invalid Choice. Please try again\n=> ";
			tempChoice = getChoice();
		}

		if (tempChoice == 1)
		{
			system("CLS");

			string airlineName;

			cin.ignore();
			cout << "Enter the Airline Name: ";
			getline(cin, airlineName);

			for (int counter = 0; counter < totalPlanes; counter++)
			{
				if (airlineName.compare(obj[counter].getAirlineName()) == 0)
				{
					FlightDisplay(obj[counter]);
					Found = true;
				}
			}
		}
		else
		{
			system("CLS");

			int searchID;

			cout << "Enter the Airline ID: ";
			cin >> searchID;
			while (searchID < 0)
			{
				cout << "Invalid Input. Please try again: ";
				cin >> searchID;
			}

			for (int counter = 0; counter < totalPlanes; counter++)
			{
				if (searchID == obj[counter].getAirlineID())
				{
					FlightDisplay(obj[counter]);
					Found = true;
				}
			}
		}
	}
	else if (option == 5)
	{
		for (int counter = 0; counter < totalPlanes; counter++)
		{
			tempObj = CompletedFlights(obj[counter]);
			if (tempObj.getAirlineID() != -1)
			{
				FlightDisplay(obj[counter]);
				Found = true;
			}
		}
	}
	if (!Found)
	{
		cout << "No flight was found!" << endl;
	}
	cout << endl;
}
void EditFlightDetails(Plane*& obj, int& totalPlanes, const string fileName)
{
	system("CLS");
	int flightID;
	bool Found = false;

	cout << "First search for the specific flight\n";
	cout << "Enter the flight ID: ";
	cin >> flightID;

	while (flightID < 0)
	{
		cout << "Invalid flight ID. Please enter again: ";
		cin >> flightID;
	}

	for (int counter = 0; counter < totalPlanes && !Found; counter++)
	{
		if (obj[counter].getFlightNumber() == flightID)
		{
			Found = true;
			InputFlightDetails(obj, counter);
			OutputPlaneData(obj, totalPlanes, fileName);
			InputPlaneData(obj, totalPlanes, fileName);
			FlightDisplay(obj[counter]);
		}
	}
	if (!Found)
		cout << "The Flight was not found!" << endl;
	else
		cout << "The Flight was found and edited!" << endl;

	cout << endl;
}

//////////////////////////////////////////Haseeb's Functions end here///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////Abdul Raheem's Functions's start here////////////////////////////////////////////////////////////////////////////////////////////////////////
bool CredentialsExist(Passenger* passenger, int& totalPassengers, User tempUser, int& idx)
{
	bool credentialsExist = false;


	for (int i = 0; i < totalPassengers; i++)
	{
		if (tempUser == passenger[i])
		{
			credentialsExist = true;
			idx = i;
			break;
		}
	}
	return credentialsExist;
}
bool CredentialsExist(Passenger* passenger, int& totalPassengers, string username)
{
	bool credentialsExist = false;
	for (int i = 0; i < totalPassengers; i++)
	{
		if (username == passenger[i].getUsername())
		{
			credentialsExist = true;
			break;
		}
	}
	return credentialsExist;
}
bool CredentialsExist(Passenger* passenger, int& totalPassengers, long long int passportNo)
{
	bool credentialsExist = false;
	for (int i = 0; i < totalPassengers; i++)
	{
		if (passportNo == passenger[i].GetPassportNo())
			credentialsExist = true;

		break;
	}
	return credentialsExist;
}
bool LoginPortal(Admin  admin)
{
	User tempUser;
	string tempUsername;
	string tempPassword;
	char choice;
	bool isAdmin = false;

	do
	{
		system("CLS");
		cout << "Welcome to Admin Login Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;
		tempUser.setUsername(tempUsername);
		cout << "\nPassword: ";
		cin >> tempPassword;
		tempUser.setPassword(tempPassword);

		if (tempUser == admin)
		{
			isAdmin = true;
			cout << admin.GetAdminName() << " Welcome to Flight Management System \n";

			system("pause");
			break;
		}

		else
		{

			cout << "\nInvalid Username or Password \n\n";
			cout << "Press y to retry \t Press any key to exit\n";
			cin >> choice;
			if (choice != 'y')
			{
				break;
			}
			else
			{
				continue;
			}

		}

	} while (tempUser != admin);

	return isAdmin;
}
bool LoginPortal(Passenger* passenger, int totalPassengers, int& index)
{
	Passenger tempUser;
	string tempUsername;
	string tempPassword;
	bool isPassenger = false;
	do
	{
		system("CLS");
		cout << "Welcome to Passenger Log In Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;
		cout << "\nPassword: ";
		cin >> tempPassword;
		tempUser.setUsername(tempUsername);
		tempUser.setPassword(tempPassword);
		if (CredentialsExist(passenger, totalPassengers, tempUser, index))
			break;
		else if (!CredentialsExist(passenger, totalPassengers, tempUser, index))
		{

			cout << "The username or password is incorrect\n";
			cout << "Kindly re enter \n";
			system("pause");
			continue;
		}


	} while (!CredentialsExist(passenger, totalPassengers, tempUser, index));

	if (CredentialsExist(passenger, totalPassengers, tempUser, index))
	{
		isPassenger = true;
		tempUser.SetPassengerName(passenger[index].GetPassengerName());
		cout << system("CLS");
		cout << tempUser.GetPassengerName() << " Welcome to Flight Management System \n";
		system("pause");

	}
	return isPassenger;

}
void InsertPassenger(Passenger* passenger, int& totalPassengers, string PassengerFile, Passenger newPassenger)
{

	ofstream fout;
	fout.open(PassengerFile);

	for (int i = 0; i < totalPassengers; i++)
	{
		fout << passenger[i].getUsername() << ", ";
		fout << passenger[i].getPassword() << ", ";
		fout << passenger[i].GetPassengerName() << ", ";
		fout << passenger[i].GetNationality() << ", ";
		fout << passenger[i].GetPassportNo() << ", ";
		fout << passenger[i].GetTicketsBooked() << ",";
		int* tickets = passenger[i].GetTicketIds();
		for (int j = 0; j < passenger[i].GetTicketsBooked(); j++)
		{
			fout << " " << tickets[j];
		}
		fout << ".\n";

	}

	fout << newPassenger.getUsername() << ", ";
	fout << newPassenger.getPassword() << ", ";
	fout << newPassenger.GetPassengerName() << ", ";
	fout << newPassenger.GetNationality() << ", ";
	fout << newPassenger.GetPassportNo() << ", ";
	fout << newPassenger.GetTicketsBooked() << ",";
	int* tickets = newPassenger.GetTicketIds();
	for (int j = 0; j < newPassenger.GetTicketsBooked(); j++)
	{
		fout << " " << tickets[j];
	}
	fout << ".\n";
	fout.close();

}
void InsertPassenger(Passenger* passenger, int& totalPassengers, string PassengerFile)
{

	ofstream fout;
	fout.open(PassengerFile);

	for (int i = 0; i < totalPassengers; i++)
	{
		fout << passenger[i].getUsername() << ", ";
		fout << passenger[i].getPassword() << ", ";
		fout << passenger[i].GetPassengerName() << ", ";
		fout << passenger[i].GetNationality() << ", ";
		fout << passenger[i].GetPassportNo() << ", ";
		fout << passenger[i].GetTicketsBooked() << ",";
		int* tickets = passenger[i].GetTicketIds();
		for (int j = 0; j < passenger[i].GetTicketsBooked(); j++)
		{
			fout << " " << tickets[j];
		}
		fout << ".\n";

	}
	fout.close();

}
Passenger SignUp(Passenger* passenger, int& totalPassengers, string PassengerFile)
{
	Passenger newPassenger;
	string tempUsername;
	string tempPassword;
	string tempPassengerName;
	string tempNationality;
	long long int tempPassportNo;

	char choice;

	do
	{
		system("CLS");
		cout << "Welcome to Passenger Sign Up Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;


		if (CredentialsExist(passenger, totalPassengers, tempUsername))
		{

			cout << "The username is already taken \n";
			cout << "Kindly enter another username \n";
			system("pause");
		}
		else
			break;

	} while (CredentialsExist(passenger, totalPassengers, tempUsername));
	if (!CredentialsExist(passenger, totalPassengers, tempUsername))
	{
		newPassenger.setUsername(tempUsername);
	}

	cout << "\nPassword: ";
	cin >> tempPassword;
	newPassenger.setPassword(tempPassword);

	cout << "\nPassenger Name: ";
	cin >> tempPassengerName;
	newPassenger.SetPassengerName(tempPassengerName);

	cout << "\nNationality: ";
	cin >> tempNationality;
	newPassenger.SetNationality(tempNationality);

	do
	{
		cout << "\nPassport No: ";
		cin >> tempPassportNo;

		if (CredentialsExist(passenger, totalPassengers, tempPassportNo))
		{
			cout << "\nPassport No already exists \n";
			cout << "Check your Passport No and re enter \n";
			system("pause");
		}

	} while (CredentialsExist(passenger, totalPassengers, tempPassportNo));

	if (!CredentialsExist(passenger, totalPassengers, tempPassportNo))
	{
		newPassenger.SetPassportNo(tempPassportNo);
	}
	return newPassenger;

}
//int SearchPassenger(Passenger* passenger, int& totalPassengers, string username)
//{
//	for (int i = 0; i < totalPassengers; i++)
//	{
//		if (passenger[i].getUsername() == username)
//		{
//			break;
//			return i;
//		}
//		else
//		{
//			cout << "The user doesn't exist\n";
//			system("pause");
//			i = -1;
//			return i;
//		}
//	}
//}
void EditUsername(Passenger* passenger, int& totalPassengers, int index)
{
	string tempUsername;
	do {
		cout << "Enter New Username\n";
		cout << "=>";
		cin >> tempUsername;

		if (!CredentialsExist(passenger, totalPassengers, tempUsername))
		{
			passenger[index].setUsername(tempUsername);
			break;
		}
		else if (CredentialsExist(passenger, totalPassengers, tempUsername))
		{
			cout << "The username is unavailable\n";
			continue;
		}

	} while (CredentialsExist(passenger, totalPassengers, tempUsername));

	cout << "New Information:\n" << passenger[index] << endl;
}
void EditPassword(Passenger* passenger, int& totalPassengers, int index)
{
	string tempPassword;

	cout << "Enter New Password\n";
	cout << "=>";
	cin >> tempPassword;

	passenger[index].setPassword(tempPassword);

	cout << "New Information:\n" << passenger[index] << endl;
}
void EditPassengerName(Passenger* passenger, int& totalPassengers, int index)
{
	string tempPassengerName;

	cout << "Enter New PassengerName\n";
	cout << "=>";
	cin >> tempPassengerName;

	passenger[index].SetPassengerName(tempPassengerName);

	cout << "New Information:\n" << passenger[index] << endl;
}
void EditNationality(Passenger* passenger, int& totalPassengers, int index)
{
	string tempNationality;

	cout << "Enter New Nationality\n";
	cout << "=>";
	cin >> tempNationality;

	passenger[index].SetNationality(tempNationality);

	cout << "New Information:\n" << passenger[index] << endl;
}
//void EditTotalTickets(Passenger* passenger, int& totalPassengers, int index)
//{
//	int tempTotalTickets = 0;
//	cout << "Enter New Number of Total Tickets\n";
//	cout << "=>";
//	cin >> tempTotalTickets;
//	passenger[index].SetTicketsBooked(tempTotalTickets);
//
//}
//void AddTicket(Passenger* passenger, int& totalPassengers, int index)
//{
//	int newTicketID=0;
//	cout << "Enter New Ticket Id\n";
//	cout << "=>";
//	cin >> newTicketID;
//
//
//
//	int* tempTicketIds = new int[totalPassengers + 1];
//	tempTicketIds = passenger[index].GetTicketIds();
//	passenger[index].DeleteTicketIds();
//
//	tempTicketIds[totalPassengers] = newTicketID;
//	passenger[index].SetTicketIds(tempTicketIds);
//
//	
//	
//}
//void DeleteTicket(Passenger* passenger, int& totalPassengers, int index)
//{
//
//}
//void EditTicketIDs(Passenger* passenger, int& totalPassengers, int index)
//{
//	int choice = -1;
//	int* tempticketId;
//	///////////////////Continuefrom here
//
//	choice = EditTicketMenu();
//
//	if (choice == 1)
//	{
//		AddTicket(passenger,totalPassengers,index);
//	}
//	else if (choice == 2)
//	{
//		DeleteTicket(passenger, totalPassengers, index);
//	}
//
//}
void EditPassengerDetails(Passenger* passenger, int& totalPassengers, int index)
{
	int choice = 0;

	
	cout << "User information:\n";
	cout << passenger[index];
	cout << endl;
	system("pause");
	system("CLS");
	cout << "What do you want to edit?\n";
	cout << "1. Username" << endl;
	cout << "2. Password" << endl;
	cout << "3. Passenger Name" << endl;
	cout << "4. Nationality" << endl;
	cout << "=> ";
	choice = getChoice();

	if (choice == 1)
	{
		EditUsername(passenger, totalPassengers, index);
	}
	if (choice == 2)
	{
		EditPassword(passenger, totalPassengers, index);
	}
	if (choice == 3)
	{
		EditPassengerName(passenger, totalPassengers, index);
	}
	if (choice == 4)
	{
		EditNationality(passenger, totalPassengers, index);
	}
	//if (choice == 5)
	//{
	//	EditTotalTickets(passenger, totalPassengers, index);
	//}
	//if (choice == 6)
	//{
	//	EditTicketIDs(passenger, totalPassengers, index);
	//}


}
bool TicketAvailable(Plane*& obj, int FlightNum, int ticketID)
{
	bool ticketAvailable = true;
	Ticket* tempTickets = obj[FlightNum].getTickets();

	for (int i = 0; i < obj[FlightNum].getBookedTickets(); i++)
	{
		if (ticketID == tempTickets[i].getID())
		{
			ticketAvailable = false;
			break;
		}
	}

	return ticketAvailable;
}
int returnFlightIndex(Plane* obj, const int totalPlanes, int tempFlightID)	// If flight number same, returns the object with same flight number
{
	int	index = -1;
	for (int counter = 0; counter < totalPlanes; counter++)
	{
		if (obj[counter].getFlightNumber() == tempFlightID)
		{
			cout << "Flight Found!" << endl;
			index = counter;
			break;

		}
		else
		{
			index = -1;
		}
	}
	return index;

}
void InputFlightDetails(Plane*& obj, const int FlightNum, long long int passportno)
{

	int avaiableTickets, bookedTickets, ticketID, passportNum;

	Ticket tempTicket;
	bookedTickets = obj[FlightNum].getBookedTickets();
	bookedTickets++;
	obj[FlightNum].setBookedTickets(bookedTickets);


	cout << "Enter Ticket ID\n";
	ticketID = getChoice();

	while (!TicketAvailable(obj, FlightNum, ticketID))
	{
		cout << "Ticket ID already exists\n";
		cout << "Enter Ticket ID\n";
		ticketID = getChoice();

	}
	if (TicketAvailable(obj, FlightNum, ticketID))
	{
		tempTicket.setID(ticketID);
	}
	tempTicket.setPassportNumber(passportno);


	Ticket* newArr = obj[FlightNum].getTickets();
	newArr[bookedTickets - 1] = tempTicket;
	obj[FlightNum].setTicketArr(newArr);
	cout << "\nCongratulations your flight is booked\n";

}
bool FlightExists(Plane*& obj, int& totalPlanes, int flightNum)
{
	bool flightExist = false;
	for (int i = 0; i < totalPlanes; i++)
	{
		if (flightNum == obj[i].getFlightNumber())
		{
			flightExist = true;
			break;
		}
	}
	return flightExist;
}
int GetFlightID(Plane*& obj, int& totalPlanes)
{
	int flightNum = 0;

	cout << "Enter Flight Num:";
	flightNum = getChoice();
	while (!FlightExists(obj, totalPlanes, flightNum))
	{
		if (FlightExists(obj, totalPlanes, flightNum))
		{
			return flightNum;
		}
		else if (!FlightExists(obj, totalPlanes, flightNum))
		{
			cout << "Invalid Flight Num: \n";
			cout << "Enter Flight Num:";
			flightNum = getChoice();

		}
	}
	return flightNum;
}
void BookTickets(Plane*& obj, int& totalPlanes, const string fileName, long long int passportno)
{
	int flightNum = 0, flightIndex = -1;
	
	DisplayFlights(obj, totalPlanes);
	flightNum = GetFlightID(obj, totalPlanes);
	flightIndex = returnFlightIndex(obj, totalPlanes, flightNum);
	
	while (obj[flightIndex].getBookedTickets() == obj[flightIndex].getAvailableTickets())
	{
		if (obj[flightIndex].getBookedTickets() == obj[flightIndex].getAvailableTickets())
		{
			cout << "The Flight is full \n";
			DisplayFlights(obj, totalPlanes);
			flightNum = GetFlightID(obj, totalPlanes);
			flightIndex = returnFlightIndex(obj, totalPlanes, flightNum);

		}
	}
	InputFlightDetails(obj, flightIndex, passportno);


}

int GetPassengerTickets(Plane*& obj, const int totalPlanes)
{
	int passengerTickets = 0;
	int totalbookedtickets = 0;
	for (int i = 0; i < totalPlanes; i++)
	{
		totalbookedtickets += obj[i].getBookedTickets();

	}
	return totalbookedtickets;
}

Ticket* SearchTicketIDs(Ticket* arrTicket, const int availableTickets, const int passportNum)
{
	Ticket* tempTicket = new Ticket[availableTickets];
	bool atleastOne = false;
	int count = 0;

	for (int counter = 0; counter < availableTickets; counter++)
	{
		if (arrTicket[counter].getPassportNumber() == passportNum)
		{
			tempTicket[count].setID(arrTicket[counter].getID());
			atleastOne = true;
			count++;
		}
	}
	return tempTicket;
}
int PassengerTickets(Ticket* arrTicket, const int availableTickets, const int passportNum)
{

	bool atleastOne = false;
	int count = 0;

	for (int counter = 0; counter < availableTickets; counter++)
	{
		if (arrTicket[counter].getPassportNumber() == passportNum)
		{
			atleastOne = true;
			count++;
		}
	}
	return count;
}
void EditPassengerTickets(Plane*& obj, const int totalPlanes, Passenger*& PassengerData, int index)
{
	int totalbookedTickets = 0;



	for (int i = 0; i < totalPlanes; i++)
	{
		totalbookedTickets += PassengerTickets(obj[i].getTickets(), obj[i].getBookedTickets(), PassengerData[index].GetPassportNo());
	}

	int* passengersticket = new int[totalbookedTickets];
	Ticket* tempTicket = 0;

	
	for (int i = 0; i < totalbookedTickets;)
	{
		for (int j = 0; j < totalPlanes; j++)
		{

			{
				tempTicket = SearchTicketIDs(obj[j].getTickets(), obj[j].getBookedTickets(), PassengerData[index].GetPassportNo());

			}
			for (int k = 0; k < obj[j].getBookedTickets(); k++)
			{
				if (tempTicket[k].getID() != 0)
				{
					passengersticket[i] = tempTicket[k].getID();
					i++;
				}
			}

		}
	}

	PassengerData[index].SetTicketsBooked(totalbookedTickets);
	PassengerData[index].SetTicketIds(passengersticket);

}
void DisplayPassengerDetails(Passenger* passenger, int& totalPassengers)
{
	for (int i = 0; i < totalPassengers; i++)
	{
		cout << passenger[i];
	}
}
void DisplayPassengerDetails(Passenger* passenger, int& totalPassengers, string tempNationality)
{
	for (int i = 0; i < totalPassengers; i++)
	{
		if (passenger[i].GetNationality() == tempNationality)
		{
			cout << passenger[i] << endl;

		}
	}
}
long long int getvalidpptno()
{
	int choice = 0;

	cin >> choice;
	while (!cin.good())
	{
		cout << "Invalid Input (Wrong Data Type)\n";
		cin.clear();
		cin.ignore(std::numeric_limits<long long int>::max(), '\n');
		cout << "=>";
		cin >> choice;
	}
	return choice;
}
long long int GetPassportNo()
{
	long long int tempPassportno = 0;
	cout << "Enter Passort Number: \n";
	tempPassportno = getvalidpptno();
	return tempPassportno;
}
void DisplayPassengerDetails(Passenger* passenger, int& totalPassengers, long long int tempPassportNo)
{

	for (int i = 0; i < totalPassengers; i++)
	{
		if (passenger[i].GetPassportNo() == tempPassportNo)
		{
			cout << passenger[i] << endl;
			break;

		}
	}
}
void DisplayPassengerDetails(Plane*& obj, int& totalPlanes, Passenger* passenger, int& totalPassengers)
{
	int flightNum = 0, flightIndex = -1,tempTotalTickets=0;
	Ticket* tempTickets = 0;
	DisplayFlights(obj, totalPlanes);
	flightNum = GetFlightID(obj, totalPlanes);
	flightIndex = returnFlightIndex(obj, totalPlanes, flightNum);
	tempTotalTickets = obj[flightIndex].getBookedTickets();
	tempTickets = obj[flightIndex].getTickets();
	
	for (int i = 0; i < tempTotalTickets; i++)
	{
		DisplayPassengerDetails(passenger, totalPassengers, tempTickets[i].getPassportNumber());
	}
	system("pause");
	
	
}


int main()
{
	bool isAdmin = false;
	bool isPassenger = false;
	string passengerFile, PlaneFile;
	int totalPassengers = 0, totalPlanes = 0;
	int userchoice = 0, signInChoice = 0, choice3 = 0;
	Passenger newPassenger;
	int index = -1;
	Passenger* PassengerData;
	Plane* PlaneData = nullptr;
	Admin Admin1("sussybaka", "juba", "Susmad");
	

	PlaneFileName(PlaneFile);
	PassengerFileName(passengerFile);

	InputPassengerData(PassengerData, totalPassengers, passengerFile);
	InputPlaneData(PlaneData, totalPlanes, PlaneFile);

	DisplayPassengerDetails(PlaneData, totalPlanes, PassengerData, totalPassengers);



	//DisplayFlights(PlaneData, totalPlanes);


	
	//SearchFlights(PlaneData, totalPlanes);
	//EditFlightDetails(PlaneData, totalPlanes, PlaneFile);
	//DisplayFlights(PlaneData, totalPlanes);

	// Testing everything
	userchoice = MainMenu();

	if (userchoice == 1)
	{
		isAdmin = LoginPortal(Admin1);
		if (isAdmin)
		{
			AdminMenu();
		}

	}
	else  if (userchoice == 2)
	{
		signInChoice = SignInMenu();
		if (signInChoice == 1)
		{
			isPassenger = LoginPortal(PassengerData, totalPassengers, index);
			if (isPassenger)
			{
				choice3 = PassengerMenu();
				if (choice3 == 3)
				{
					EditPassengerDetails(PassengerData, totalPassengers, index);
					InsertPassenger(PassengerData, totalPassengers, passengerFile);
					InputPassengerData(PassengerData, totalPassengers, passengerFile);
				}


				else if (choice3 == 2)
				{
					long long int tempPassportNo = PassengerData[index].GetPassportNo();
					BookTickets(PlaneData, totalPlanes, PlaneFile, tempPassportNo);
					OutputPlaneData(PlaneData, totalPlanes, PlaneFile);
					InputPlaneData(PlaneData, totalPlanes, PlaneFile);
					EditPassengerTickets(PlaneData, totalPlanes, PassengerData, index);
					InsertPassenger(PassengerData, totalPassengers, passengerFile);
					InputPassengerData(PassengerData, totalPassengers, passengerFile);
				}
			}

		}
		else if (signInChoice == 2)
		{
			newPassenger = SignUp(PassengerData, totalPassengers, passengerFile);
			InsertPassenger(PassengerData, totalPassengers, passengerFile, newPassenger);
			InputPassengerData(PassengerData, totalPassengers, passengerFile);

		}
	}


	return 0;
}
