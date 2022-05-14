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

int main ()
{
    cout << "Hello World \n";
    
    yes
    
    return o;
}
