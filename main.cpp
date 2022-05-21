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
////istream& operator >> (istream& in, const Passenger& newPasenger)
////{
////
////}

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
	Plane(Ticket* newArr, char newStatus, int newTickets, int newFlightNumber, Time newDeptTime, Time newArrTime, Date newDate, string newName,
		int newID) : InternationalFlight(newName, newID), LocalFlight(newName, newID)
	{
		ticketArray = newArr;
		statusOfFlight = newStatus;
		availableTickets = newTickets;
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
	int getUnbookedTickets()
	{
		int unbookedTickets = 0;
		for (int counter = 0; counter < availableTickets - 1; counter++)
			if (ticketArray[counter].getID() == 0)
				unbookedTickets++;
		return unbookedTickets;
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
	cin >> choice;
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
	cin >> choice;
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
	cin >> choice;
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
	cin >> choice;
	return choice;

}

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

bool CredentialsExist(Passenger* passenger, int& totalPassengers, User tempUser, int& idx)
{
	bool credentialsExist = false;


	for (int i = 0; i < totalPassengers; i++)
	{
		if (tempUser==passenger[i])
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
		if(passportNo==passenger[i].GetPassportNo())
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

bool LoginPortal(Passenger* passenger, int totalPassengers)
{
	Passenger tempUser;
	string tempUsername;
	string tempPassword;
	int index=-1;
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

Passenger SignUp(Passenger* passenger, int& totalPassengers,string PassengerFile)
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

	cout << "\Passenger Name: ";
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
	//InsertPassenger(passenger, totalPassengers, PassengerFile, newPassenger);
	
	//InputPassengerData(passenger, totalPassengers, PassengerFile);

}



int main()
{
	bool isAdmin = false;
	bool isPassenger = false;
	string passengerFile, PlaneFile;
	int totalPassengers = 0, totalPlanes = 0;

	Passenger newPassenger;

	
	PassengerFileName(passengerFile);
	//PlaneFileName(PlaneFile);

	Passenger* PassengerData;
	InputPassengerData(PassengerData, totalPassengers, passengerFile);
	
	// To check if correct passenger input is being saved
	for (int i = 0; i < totalPassengers; i++)
	{
		cout << PassengerData[i]<<endl;
	}
	system("pause");

	Admin Admin1("sussybaka", "juba", "Susmad");

	int choice = 0, choice2 = 0;

	// Testing everything
	choice=MainMenu();
	if (choice == 1)
	{
		isAdmin=LoginPortal(Admin1);
		if(isAdmin)
		{
			AdminMenu();
		}
		
	
	}
	else  if (choice == 2)
	{
		choice2=SignInMenu();
		if (choice2 == 1)
		{
			isPassenger=LoginPortal(PassengerData,totalPassengers);
			if (isPassenger)
			{
				PassengerMenu();
			}
		}
		else if (choice2 == 2)
		{
			newPassenger=SignUp(PassengerData,totalPassengers,passengerFile);
			InsertPassenger(PassengerData, totalPassengers, passengerFile, newPassenger);
			InputPassengerData(PassengerData, totalPassengers, passengerFile);

		}
	}
	
	//check if the the data input and stored is correct
	/*for (int i = 0; i < totalPassengers; i++)
	{
		cout << PassengerData[i]<<endl;
	}*/
	

	
	return 0;
}
