
void LoginPortal(Admin  admin)
{
	User tempUser;
	string tempUsername;
	string tempPassword;
	char choice;
	
	while (tempUser != admin)
	{

		system("CLS");
		cout << "Welcome to Admin Login Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;
		tempUser.setUsername(tempUsername);
		cout << "\nPassword: ";
		cin >> tempPassword;
		tempUser.setPassword(tempPassword);

		//for (int i = 0; i < size; i++)
		//{
		if (tempUser == admin)
		{
			cout  <<admin.GetAdminName()<< " Welcome to Flight Management System \n";
		}
		else
		{
			
			cout << "\nInvalid Username or Password \n\n";
			cout << "Press y to retry \t Press any key to exit\n";
			cin >> choice;
			if (choice == 'y')
			{
				continue;
			}
			else 
			{
				break;
			}
			
		}
		//}
	}
}
void LoginPortal(Passenger  passenger)
{
	User tempUser;
	string tempUsername;
	string tempPassword;
	char choice;

	while (tempUser != passenger)
	{

		system("CLS");
		cout << "Welcome to Passenger Login Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;
		tempUser.setUsername(tempUsername);
		cout << "\nPassword: ";
		cin >> tempPassword;
		tempUser.setPassword(tempPassword);

		//for (int i = 0; i < size; i++)
		//{
		if (tempUser == passenger)
		{
			cout <<passenger.GetPassengerName() << " Welcome to Flight Management System \n";
		}
		else
		{

			cout << "\nInvalid Username or Password \n\n";
			cout << "Press y to retry \t Press any key to exit\n";
			cin >> choice;
			if (choice == 'y')
			{
				continue;
			}
			else
			{
				break;
			}

		}
		//}
	}
}
void SignUp(Passenger passenger)
{
	Passenger newPassenger;
	string tempUsername;
	string tempPassword;
	string tempPassengerName;
	string tempNationality;
	long long int tempPassportNo;
	

	char choice,anykey;
	

	do
	{

		system("CLS");
		cout << "Welcome to Passenger Sign Up Portal \n\n\n";
		cout << "Username: ";
		cin >> tempUsername;
		newPassenger.setUsername(tempUsername);

		if (tempUsername == passenger.getUsername())
		{
			cout << "The username is already taken \n";

			cout << "Press y to re enter \t Press any key to exit\n";
			cin >> choice;
			if (choice == 'y')
			{
				continue;
			}
			else
			{
				break;
			}

		}

		else
		{
			cout << "\nPassword: ";
			cin >> tempPassword;
			newPassenger.setPassword(tempPassword);

			//cout << endl << newPassenger.getUsername() << endl << newPassenger.getPassword();

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
				newPassenger.SetPassportNo(tempPassportNo);
				if (tempPassportNo == passenger.GetPassportNo())
				{
					cout << "\nPassport No already exists \n";
					//system("pause");
				}
			} while (newPassenger.GetPassportNo() == passenger.GetPassportNo());			
		}
		
	} while (newPassenger.getUsername() == passenger.getUsername());

	cout << newPassenger.getUsername() << endl;
	cout << newPassenger.getPassword() << endl;
	cout << newPassenger.GetPassengerName() << endl;
	cout << newPassenger.GetNationality() << endl;
	cout << newPassenger.GetPassportNo() << endl;
	cout << newPassenger.GetTicketsBooked() << endl;
	cout << newPassenger.GetTicketIds() << endl;



}
