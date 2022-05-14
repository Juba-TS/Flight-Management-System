# Flight-Management-System

## `Project Leads:`

Haseeb Zaheer 21L-5171

## `Group Members:`

Sarmad Siddique 21L-5225

Abdul Raheem 21L-5218

## `Project Details:`

*Note: There will be 2 files (flights and passenger list) and 3 main classes (flight, passenger and admin) and some sub classes in this project.*

1. Ask the user to choose whether he is an admin or a passenger.
2. If admin has been chosen:
    1. Ask for login credentials from the user. Check if these credentials are correct.
        1. If incorrect, ask the user for login details again.
        2. If correct, display the Menu for the admin 
3. If passenger has been chosen:
    1. If the user does not have an account:
        1. Ask the user for details and create an account (Will not let user create another account with the same passport number)
    2. If the user already has an account:
        1. Ask for the login details from the passenger.
            1. If incorrect, ask the user for login details again.
            2. If correct, display the menu for the passenger
    3. The user now has the option to choose any option from the displayed menu.

## `Project Classes`

1. User
2. Flights
3. Tickets
4. Passenger
5. Admin

## `Project Links`

1. User is the parent of the passenger and admin class (Inheritance)
2. Flights uses a tickets object (Composition)

## `Project Functionalities`

## `Functions:`

### `Note:`

A lot of these function will have sub functions and in case of display, menu and search functions there will be multiple functions based on their functionality.

## `General & Passenger Functions:`

### `1.Sign-In:`

This function will ask the user whether he is an admin or a passenger. The passenger will be asked if he wants to login or sign up. Depending on his choice the CreateAccount() or SignUp() function will be called.

### `2.Create Account:`

 This function will create a new passenger account if its a new passenger.(wont let the passenger with same passport no. create more than one account)

### `3.Log In:`

This function will check the credentials of the user and let him access the respective database.

### `4.Menu Functions:`

These functions will contain main menu and sub menus for both the admin as well as the passengers.

### `5.Display Flights:`

These Functions will display all/available flights with their data to the admin or the passengers respectively.

### `6.Search Flights:`

These functions will allow the passenger and the admin to search through flights based upon location, time and airline.

### `7.Book Flights:`

This function will allow the passenger to book a flight and add his passport number to the details of the respective Flights object.

### `8.Edit Passenger Details:`

This function will allow the passenger to change his credentials(name, password, nationality).

## `Admin Functions:`

### `9.Function to read data into array of classes:`

This function will be responsible for reading the flight and passenger data into array of classes and the number of passengers and flights in that file.

### `10.Completed Flights:`

This function will allow the admin to search through all the completed flights.

### `11.Add Flights:`

This function will allow the user to add new flights to the file that stores the data of all files.

### `12.Remove Flights:`

This function will allow the admin to delete completed or canceled flights whose data is no more required.

### `13.Edit Flight Details:`

This function will allow the admin to edit the data of a certain flight in the file.

### `14.Display Passengers:`

This function will allow the user to display based  upon the same flight number, nationality or a certain passenger through his passport number.


