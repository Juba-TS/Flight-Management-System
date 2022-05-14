#include <iostream>

using namespace std;
class User
{
private:
	string username;
	string password;
public:
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
	void setUsername(string newName);
	void setPassword(string newPassword);
	string getUsername();
	string getPassword();
	// Print Function
};
class Admin: public User
{
private:
	string adminName;
public:
	Admin();
	/*Admin(string adminName) : User(string newUsername, string newPassword);*/
	// Getter Setter

};
class Passenger: public User
{
	// Data Members (Private)
	// Passenger name, passport number, Nationality, BookedTickets(noofticketsbooked)
};
class Flight
{
	// Data Members
	// Airline, Flight Number, Departure time, arrival time, Type(Domestic or international),
	// City / Country, Available Tickets, TicketArray (object of ticket class), statusOfFlight(On-time, delayed, missed)
};
class Ticket 
{
	// Data Members
	// Ticket ID, Passport Number
};
int main ()
{
    cout << "Hello World \n";
    
    yes
    
    return o;
}
