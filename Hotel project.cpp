#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std ;

// Room information struct
struct Room
{
	string roomType;
	string roomNumber;
	double dailyPrice;
};

// Customer information struct
struct Customer
{
	string nationalID;
	string fullName;
	string phoneNumber;
};

// Bills struct
struct Bill
{
	Customer renter;
	Room rentedRoom;
	int numberOfDays;
	double totalPrice;
};

//Global variabls.

Bill bills[100];
Customer customers[100];
Room rooms[100] ;

//--------------Function---------------------------------
// Function to display the main menu.
void displayMainMenu(int numberOfCustomers, int numberOfRooms, int numberOfBills);
void displayEmbloyesMenu(int numberOfCustomers, int &numberOfRooms, int &numberOfBills , int &numberOfRentedRooms);
void displayCustomersMenu(int &numberOfCustomers, int &numberOfRooms, int &numberOfBills ,  int &numberOfRentedRooms);
void writeNewCustomer(Customer customers);
void writeNewRoom(Room rooms);
void addRoom(int &numberOfRooms);
int searchCustomer(int searchOption , int numberOfCustomers);
bool isNewRoom(string roomNumber,  int numberOfRooms);
bool isNew(string phoneNumber,  int numberOfCustomers);
bool isNewID(string nationalID, int numberOfCustomers);
void addCustomer(int &numberOfCustomers);
bool isNumber(string value);
void readData(int &numberOfCustomers , int &numberOfBills , int &numberOfRentedRooms  , int& numberOfRooms);
// Function to delete a room
void deleteRoom(int &numberOfRooms);
// Function to display all rooms
void displayRooms(int numberOfRooms);
// Function to search for a room
int searchRoom(string value , int numberOfRooms);
// Function to write rooms data to a file(Rooms.txt)
void writeRoomsData(int numberOfRooms);
// Function to rent a room for a customer
void rentTheRoom(int & numberOfRooms , int &numberOfBills , int &numberOfRentedRooms);
// Function to delete a rented room
void deleteRentedRoom(int &numberOfRooms , int &numberOfRentedRooms , int found);
void writeNewBills(Bill bills);
// Function to print the new bill
void printTheNewBill(int numberOfBills);
void rentForCustumer(int numberOfCustomers, int &numberOfRooms , int &numberOfBills , int &numberOfRentedRooms  );
void rentForCustumerAPP(int numberOfCustomers, int &numberOfRooms , int &numberOfBills , int &numberOfRentedRooms );

void displayCustomer(int index);

void getInt(int &num);


using namespace std;

	// main:
int main()
{
    int option ;
    int numberOfRooms = 0 , numberOfRentedRooms = 0 ,  numberOfCustomers = 0 , numberOfBills = 0  ;
    // Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Bills.txt", ios::app);
    
    readData(numberOfCustomers , numberOfBills ,  numberOfRentedRooms , numberOfRooms);

   
   do  {
        displayMainMenu ( numberOfCustomers,  numberOfRooms, numberOfBills);
        getInt(option);
        
        switch(option)
        {
            case 1:
                displayEmbloyesMenu ( numberOfCustomers,  numberOfRooms,  numberOfBills , numberOfRentedRooms);
                break;
            case 2:
                displayCustomersMenu ( numberOfCustomers,  numberOfRooms,  numberOfBills , numberOfRentedRooms);
                break;
            case 3:
                cout<<endl<<endl<<"Thanks for using our program"<<endl;
                break;
            default:
				cout << "Please select a valid option. " << endl;
		}
        } while (option!=3);
        
    return 0;
}


//--------------Function---------------------------------
void displayMainMenu(int numberOfCustomers, int numberOfRooms, int numberOfBills)
{
    cout << "---------------------------- AL-Khairi Hotel ----------------------------" << endl;
	cout << "1) Embloyes." << endl;
	cout << "2) Customers." << endl;
	cout << "3) Exit." << endl;
	cout << endl;
	
	cout << "Please enter your choice: ";
}

void displayEmbloyesMenu(int numberOfCustomers, int &numberOfRooms, int &numberOfBills , int &numberOfRentedRooms)
{
    int option ;
    double totalSales ;
    do 
    {	
    	cout << "---------------------------- Embloyes Menu ----------------------------" << endl;
    		// Loop through the bills array to calculate the total sales
    	if(numberOfBills>0)
    	{

    		for (int i = 0; i < numberOfBills; i++)
			{
				totalSales = totalSales + bills[i].totalPrice;
			}
			 cout<<"Total sales: " << totalSales <<"\t" ;
		}
    	cout << "Number Of Customers [ " << numberOfCustomers << " ]" << "\tNumber Of Rooms are availble[ " << numberOfRooms << " ]" << "\tNumber Of Rented rooms[ " << numberOfRentedRooms << " ]"  << endl;
    	cout << "1) Rent a room for a customer." << endl;
    	cout << "2) Add new room." << endl;
    	cout << "3) Delete a room." << endl;
    	cout << "4) search for a Customer." << endl;
    	cout << "5) display all availble rooms."<<endl;
    	cout << "6) Exit." << endl;
    
    	cout << endl;
    	
    	cout << "Please enter your choice: ";
    	getInt(option);
    	
    	switch(option)
    	{
    	    case 1 :
    	    	{
    	    		if(numberOfCustomers==0)
	    	    	{
	    	    		cout<<"there are no customers to rent a room."<<endl;
					}
					else if(numberOfRooms==0)
					{
						cout<<"there are no rooms to rent"<<endl;
					}
					else
					{
						rentForCustumer(numberOfCustomers, numberOfRooms , numberOfBills ,numberOfRentedRooms );
					}
					
				}
    	    	
    	        break;
    	    case 2 :
    	        addRoom(numberOfRooms);
    	        break;
    	    case 3 :
    	        deleteRoom(numberOfRooms);
    	        break;
    	    case 4 :
    	    	{
    	    		 if (numberOfCustomers == 0)
						{
							cout << "Sorry ... there are no customers to search." << endl;
						}
					else
					{
						cout << "----------- Search Customer -----------" << endl;
		    		    cout << "1- Search by national ID." << endl;
		    		    cout << "2- Search by phone number." << endl << endl;
		    		    int searchOption;
		    		    // Get the choice from the user
		    		    cout << "Please enter your choice: ";
		    		    getInt(searchOption);
		    		    int index = (searchCustomer(searchOption , numberOfCustomers));
		    	       if(index>=0)
		    	       {
		    	           cout<<"Customer found"<<endl<<endl;
		    	           displayCustomer(index);
		    	       }
		    	       else
					   {
					   	cout<<"Customer not found"<<endl;
					   }
					}
	    	    		
				}
	        	    
	    	       break;
    		case 5 :
    			displayRooms(numberOfRooms);
    	        break;
    	    case 6 :
    	    	//exit
    	        break;
    	    default:
    		    cout << "Please select a valid option. " << endl;
    	}
    }while(option != 6);

}


void displayCustomersMenu(int &numberOfCustomers, int &numberOfRooms, int &numberOfBills , int &numberOfRentedRooms)
{
    int option;
    do 
    {
        cout << "---------------------------- Customers Menu ----------------------------" << endl;
    	cout << "1) Rent a room." << endl;
    	cout << "2) Sign up." << endl;
    	cout << "3) Exit." << endl;
    	cout << endl;
    	
    	cout << "Please enter your choice: ";
    	getInt(option);
    	
    	switch(option)
    	{
    	    case 1 :
    	    	 if(numberOfRooms==0)
					{
						cout<<"there are no rooms to rent"<<endl;
					}
					else
					{
    	     			rentForCustumerAPP(numberOfCustomers, numberOfRooms , numberOfBills ,numberOfRentedRooms ); 
    	     	    }
    	        break;
    	    case 2 :
    	        addCustomer(numberOfCustomers);
    	        break;
    	    case 3 :
    	        //Exit
    	        break;
    	    default:
				cout << "Please select a valid option. " << endl;
    	}
    }while(option!=3);
	
}

// Function to add new customer.
void addCustomer(int &numberOfCustomers)
{
	
	// Declare variable to store the phone number before check if it is true
	string phoneNumber, nationalID;
	
	//Title of the menu
	cout << "------------------ New Customer ------------------" << endl;

	// Get the national ID of the customer
	cout << "Enter the national ID: ";
	cin>>nationalID;
	if(isNumber(nationalID) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid national ID\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	if(isNewID(nationalID , numberOfCustomers) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the customer is already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	cout <<"Enter the full Name: ";
	cin.ignore(); // To clear the input buffer.
	getline(cin, customers[numberOfCustomers].fullName);
	cout << "Enter the phone number: ";
	cin>>phoneNumber;
	if(isNumber(phoneNumber) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid phoneNumber\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	if(isNew(phoneNumber , numberOfCustomers) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the customer is already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	customers[numberOfCustomers].nationalID = nationalID;
	customers[numberOfCustomers].phoneNumber = phoneNumber;
	numberOfCustomers++;
	int index=numberOfCustomers-1;
	writeNewCustomer(customers[index]);
	cout<<"CONGRATULATIONS you created an account with us successfully "<< endl;
		return;
	}

//Function to check if the nationalID of the new customer is new or not
bool isNewID(string nationalID, int numberOfCustomers)
{
	for (int i = 0; i < numberOfCustomers; i++)
	{
		if (nationalID == customers[i].nationalID)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

//Function to check if the phone number of the new customer is new or not
bool isNew(string phoneNumber,  int numberOfCustomers)
{
	for (int i = 0; i < numberOfCustomers; i++)
	{
		if (phoneNumber == customers[i].phoneNumber)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

//Function to check if the room Number of the new Room is new or not
bool isNewRoom(string roomNumber,  int numberOfRooms)
{
	for (int i = 0; i < numberOfRooms; i++)
	{
		if (roomNumber == rooms[i].roomNumber)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

int searchCustomer(int searchOption , int numberOfCustomers)
{
	
    	// Declare a variable to store the search key
    	string value;
    	
    	do
    	{
    		// Search by national ID
    		if (searchOption == 1)
    		{
    			// Get the national ID from the user
    			cout << "Enter the national ID of the customer: ";
    			cin.ignore();
    			getline(cin,value);    			
    			// Loop through the array of customers to check if the customer is exist
    			for (int i =0; i<numberOfCustomers; i++)
    			{
    				// If the customer is found
    				if (value == customers[i].nationalID)
    				{ 
    					// return the index
    					return i;
    				}
    			}
    			return-1 ;
    		}	
    		
    		// Search by phone number
    		else if (searchOption == 2)
    		{
    			// Get the phone number from the user
    			cout << "Enter the phone number of the customer: ";
    			cin.ignore();
    			getline(cin,value);
    			
    			// Loop through the array of customers to check if the customer is exist
    			for (int i =0; i<numberOfCustomers; i++)
    			{
    				// If the customer is found
    				if (value == customers[i].phoneNumber)
    				{ 
    					// return the index
    					return i;
    				}
    			}
    			return-1 ;
    		}
    		else
    		{
    			cout << "Please enter a valid number [1 or 2]: ";
    			getInt(searchOption);
    		}	
    	} while (searchOption != 1 || searchOption != 2);
	
}
void addRoom(int &numberOfRooms)
{
	// Declare variables
	int option;
	string RoomNumber;
	double price ;
	
	//Title
	cout << "------------------ Add Room ------------------" << endl;
	
	cout<<"Enter the Room Number: ";
	cin>>RoomNumber;
	if(isNumber(RoomNumber) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid Room Number\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	// Check if the room is already exists
	if(isNewRoom(RoomNumber, numberOfRooms) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the Room already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	//If the Room Number is valid and new, complete the adding process
	rooms[numberOfRooms].roomNumber = RoomNumber;
	// Get the daily price 
	cout<<"Enter the Room daily price (SR): ";
	cin >> price;
		while(cin.fail())
	{
		// Continue to get input until get a number
		cout << "Please enter a valid number" <<endl;
		cout << "Enter the Room daily price (SR): ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> price;
	}	
	
	rooms[numberOfRooms].dailyPrice=price ;
	
	// Loop to be sure the user choose a correct room type 
	do
	{
		// Display the options 
		cout << "--------room Type:-------- " << endl;
		cout << "1) sweet-room." << endl;
		cout << "2) studio." << endl;
		cout << "3) apartment." << endl;
		
		// Get the choice from the user 
		cout<<"Choose the room type [From 1 to 3]: ";
		getInt(option);
	
		// Check for the choice
		if(option == 1)
		{
			rooms[numberOfRooms].roomType = "sweet-room"; 
		}
		else if (option == 2)
		{
            rooms[numberOfRooms].roomType = "studio";		}
		else if (option == 3)
		{
            rooms[numberOfRooms].roomType = "apartment";		}
		else
		{
			cout << endl << "Please Enter a valid option " << endl << endl;
		}
		
	} while (option <= 0 || option > 3 ); 

	numberOfRooms++;
	
	writeNewRoom(rooms[numberOfRooms-1]);
	
	// Success message
	cout << "The Room has been added successfully!\n" << endl;
}


// Function to write the data of the new room into "Rooms.txt"
void writeNewRoom(Room rooms)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Rooms.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Write the data of the new car to "Rooms.txt"
		outFile << "=================================================================================\n";
		outFile << "Room number: " << rooms.roomNumber << endl;
		outFile << "Daily price: " << rooms.dailyPrice << endl;
		outFile << "Room type: " << rooms.roomType << endl;
		// Close the file
		outFile.close();
	}
}



void getInt(int &num)
{
    cin >> num;
    while(cin.fail())
    {
    // Continue to get input until get an int
    cout << "Please enter a number: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin >> num;
    }
}

// Function to write the data of the new customer into "Customers.txt"
void writeNewCustomer(Customer customers)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Customers.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Write the data of the new customer to "Customers.txt"
		outFile << "=================================================================================\n";
		outFile << "Full name: " << customers.fullName << endl;
		outFile << "Phone number: " << customers.phoneNumber << endl;
		outFile << "National ID: " << customers.nationalID << endl;	
		
		// Close the file
		outFile.close();
	}
}

// Function to display customer
void displayCustomer(int index)
{

		// Print the labels 
		cout << endl;
		cout << left << setw(15) << "National ID: " << setw(30) <<"Full Name: " << setw(25) <<"Phone Number: "  << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		
		
			cout << left << setw(15) << customers[index].nationalID <<setw(30) <<customers[index].fullName << setw(27) << customers[index].phoneNumber <<  endl;

		cout << "--------------------------------------------------------------------------" << endl << endl<<endl<<endl;
	
}
bool isNumber(string value)
{
	// Declare a variable to store the length of the string
	int length = value.length();
	
	// Loop through each character on the string to check if it is digit 
	for (int i = 0; i < length; i++)
	{
		if (isdigit(value[i]) == false)
		{
			// If there is a non-digit character on string end the function and return false
			return false;
		}
	}
	
	// If all characters are digits return true 
	return true;
}

// Function to read Data 
void readData(int &numberOfCustomers , int &numberOfBills,  int &numberOfRentedRooms , int& numberOfRooms)
{
	// Declare stream variables
	fstream customersIn;
	fstream roomsIn;
	fstream billsIn;
	cout << "\n";
	
	// --- Read customers data ---
	
	// open the file
	customersIn.open("Customers.txt", ios::in);

	// Check if the file is open
	if (customersIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while(!customersIn.eof())
		{
			// Read the data from the file "Customers.txt"
			customersIn.ignore(100, ':');
			customersIn.ignore();
			getline(customersIn, customers[numberOfCustomers].fullName);
			customersIn.ignore(14);
			getline(customersIn, customers[numberOfCustomers].phoneNumber);
			customersIn.ignore(13);
			getline(customersIn, customers[numberOfCustomers].nationalID);
			
			numberOfCustomers++;
		}
		numberOfCustomers--;
		
		// Display the number of imported customers
		cout << "------- [ " << numberOfCustomers <<" ]"<< " Customers imported successfully! -------" << endl;
		
		// Close the file
		customersIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No customers imported, please add customers (from customers menu) to save them for the next time." << endl;
	}
	
	// --- Read rooms data ---
	
	// Open the file
	roomsIn.open("Rooms.txt", ios::in);
	
	// Check if the file is open
	if (roomsIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while (!roomsIn.eof())
		{
			// Read the data from the file "Rooms.txt"
			roomsIn.ignore(100, ':');
			roomsIn.ignore();
			getline(roomsIn, rooms[numberOfRooms].roomNumber);
			roomsIn.ignore(13);
			roomsIn >> rooms[numberOfRooms].dailyPrice;
			roomsIn.ignore(11);
			roomsIn >> rooms[numberOfRooms].roomType;
			numberOfRooms++;
		}
		numberOfRooms--;	
		
		// Display the number of imported rooms
		cout << "------- [ " << numberOfRooms <<" ]"<< " Rooms imported successfully! ------------" << endl;
		
		// Close the file
		roomsIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No rooms imported, please add rooms (from embloyes menu) to save them for the next time." << endl;
	}
	// --- Read bills data ---
	
	// Open the file
	billsIn.open("Bills.txt", ios::in);
	
	// Check if the file is open
	if (billsIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while(!billsIn.eof())
		{
			// Read the data from the file "BillsData.txt"
			billsIn.ignore(100, ':');
			billsIn.ignore();
			getline(billsIn, bills[numberOfBills].renter.fullName);
			billsIn.ignore(14);
			billsIn >> bills[numberOfBills].renter.phoneNumber;
			billsIn.ignore(13);
			billsIn >> bills[numberOfBills].rentedRoom.dailyPrice;
			billsIn.ignore(11);
			billsIn >> bills[numberOfBills].rentedRoom.roomType;
			billsIn.ignore(13);
			getline(billsIn, bills[numberOfBills].rentedRoom.roomNumber);
			billsIn.ignore(16);
			billsIn >> bills[numberOfBills].numberOfDays;
			billsIn.ignore(13);
			billsIn >> bills[numberOfBills].totalPrice;
			numberOfRentedRooms++;
			numberOfBills++;
		}
		numberOfRentedRooms--;
		numberOfBills--;	
		
		// Display the number of imported customers
		cout << "------- [ " << numberOfBills <<" ]"<< " Bills imported successfully! -----------" << endl;
		
		// Close the file
		billsIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No bills imported, please add bills (from bills menu) to save them for the next time." << endl;
	}

	cout << "\n\n";
}

// Function to delete a room
void deleteRoom(int &numberOfRooms)
{
	// Check if there are rooms
	if (numberOfRooms == 0)
	{
	cout << "Sorry there are no rooms to delete." << endl;
	}
	
	else 
	{
		// Declare variables
		int index = -1;
		string roomNum;
	
		// Display all rooms to the user
		displayRooms(numberOfRooms);
		
		cout << "Enter the room number: ";
		cin >> roomNum;
		
		// Search for the room by the room number
		index = searchRoom(roomNum , numberOfRooms);
		
		// If found >= 0 it means the room is found  
		if (index >= 0)
	    {
			//  Delete the room
			for (int i = index; i < numberOfRooms-1; i++)
	    	{
	            rooms[i]	= rooms[i+1];
			}
			
			// Decrement the number of rooms by one
			numberOfRooms--;
			
			// Write the room data, after the delete, into a file(Rooms.txt)
			writeRoomsData(numberOfRooms);
			
			// Success message
	       	cout<< " The room has been deleted successfully." << endl;  
		}
		
		// If the room is not found
		else
		{
			cout << "Wrong Room number, The room does not exist .. Please try again. " << endl;
		}
	}
}


// Function to display all rooms
void displayRooms(int numberOfRooms)
{
	//Check if there are rooms
	if (numberOfRooms == 0)
	{
		cout << "Sorry there are no rooms to display." << endl;
	}
	
	else 
	{
		// Print the labels 
		cout << endl;
		cout << left << setw(30) <<"Room number:" << setw(20) <<"Room Type:" << setw(20) << "Daily Price:" << endl;
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		
		// Loop through the array of roooms and print them
		for (int i = 0; i < numberOfRooms; i++)
		{
			cout << left << setw(30) <<rooms[i].roomNumber << setw(20) << rooms[i].roomType << setw(20) << rooms[i].dailyPrice << setw(10) << endl;
		}
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
	}
}


// Function to search for a room
int searchRoom(string value , int numberOfRooms)
{

	// Loop through the array of rooms and search for the index
	for (int i =0; i<numberOfRooms; i++)
	{
		if (value == rooms[i].roomNumber)
		{ 
			// If the room is found return the index
			return i;
		}
	}
	
	// If the room is not found return -1 
	return -1;
}

// Function to write rooms data to a file(Rooms.txt)
void writeRoomsData(int numberOfRooms)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Rooms.txt", ios::out);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Loop through rooms array
		for (int i =0; i<numberOfRooms; i++)
		{
			// Write the data to "Rooms.txt"
			outFile << "=================================================================================\n";
			outFile << "Room number: " << rooms[i].roomNumber << endl;
			outFile << "Daily price: " << rooms[i].dailyPrice << endl;
			outFile << "Room type: " << rooms[i].roomType << endl;
		}
		
		// Close the file
		outFile.close();
	}
}

// Function to rent a room for a customer
void rentTheRoom(int &numberOfRooms , int &numberOfBills , int &numberOfRentedRooms)					
{
	// Declare variables
	string roomNum;
	int days;
	
	// Display all rooms to the user
	cout<<"Please select a room form the list by the room number:"<<endl;
	displayRooms(numberOfRooms);
	
	while(true)
	{
		// Get the room number 
		cout << "Enter the room number: " << endl;
		cin >> roomNum;
		
		// Loop until the user enter a number
		while (isNumber(roomNum) == false)
		{
			cout << "Sorry, please enter a valid room number: "<<endl;
			cin >> roomNum;
		}
	
		// Search for the index of the requested room
		int index = searchRoom(roomNum , numberOfRooms);
		
		// If index >= 0 it means the room is found  
		if (index >= 0)
		{
			// Loop if the user enter a 0 days
			do
			{
				// Get the number of days 
				cout<<"Enter the number of days: "<<endl;
				getInt(days);			
			}while (days == 0); 
			
			// Initialize the total price (Days * Daily price of the room)
			bills[numberOfBills].totalPrice = days * rooms[index].dailyPrice;
			bills[numberOfBills].numberOfDays = days;
			bills[numberOfBills].rentedRoom = rooms[index];
			numberOfRentedRooms++;
			writeNewBills(bills[numberOfBills]);
			deleteRentedRoom(numberOfRooms , numberOfRentedRooms ,index);
			
			// Print the new bill to the user
			printTheNewBill(numberOfBills);			
			// Increment the number of bills by one
			numberOfBills++;
			cout << "The bill has been saved successfully!\n" << endl;
			
			// Break the loop if the the creating bill done
			break;
		}
		
		// If the Room number is incorrect
		else
		{
			cout<<"Sorry wrong room number, Please enter the correct room number"<<endl;
		}		
	}
}
	
// Function to delete a rented room
void deleteRentedRoom(int &numberOfRooms , int &numberOfRentedRooms , int found)
{	
		
		
		if (found >= 0)
	    {
			//  Delete the room from the rooms file
			for (int i = found; i < numberOfRooms-1; i++)
	    	{
	            rooms[i] = rooms[i+1];
			}
			
			numberOfRooms=numberOfRooms-1;
			// Write the rooms data, after the rent, into a file(Rooms.txt)
			writeRoomsData(numberOfRooms);
			
			
		}
	
}


void writeNewBills(Bill bills)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Bills.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
			// Write the data 
			outFile << "=================================================================================\n";
			outFile << "Renter name: " << bills.renter.fullName << endl;
			outFile << "Phone number: " << bills.renter.phoneNumber << endl;
			outFile << "Daily price: " << bills.rentedRoom.dailyPrice << endl;
			outFile << "room type: " << bills.rentedRoom.roomType << endl;
			outFile << "Room number: " << bills.rentedRoom.roomNumber << endl;
			outFile << "Number of days: " << bills.numberOfDays << endl;
			outFile << "Total price: " << bills.totalPrice << endl;
		
		// Close the file
		outFile.close();
	}
}

// Function to print the new bill
void printTheNewBill(int numberOfBills)
{
	// Print the bill information
	cout << endl;
	cout << "------------------ The Bill ------------------" << endl;
	cout<<"Customer name:  "<<bills[numberOfBills].renter.fullName<<endl;
	cout<<"Customer phone: "<<bills[numberOfBills].renter.phoneNumber<<endl;
	cout<<"The rented Room is: "<< bills[numberOfBills].rentedRoom.roomNumber << " - " << bills[numberOfBills].rentedRoom.roomType <<endl;
	
	// Print how many days the room is rented
	if(bills[numberOfBills].numberOfDays>=2)
	{
		cout<<"The room is rented for "<<bills[numberOfBills].numberOfDays<<" days."<<endl;
	}
	if(bills[numberOfBills].numberOfDays == 1)
	{
		cout<<"The room is rented for 1 day."<<endl;
	}	
	
	// Print the total price	
	cout<<"\nYour total price is: "<< bills[numberOfBills].totalPrice <<endl;
	cout << "----------------------------------------------" << endl << endl;
}

void rentForCustumer(int numberOfCustomers, int &numberOfRooms , int &numberOfBills , int &numberOfRentedRooms )
{

	// Declare a variabl to get the choice from the user
	int searchOption;
	
	cout << "----------- Rent a room for a customer -----------" << endl;
	cout << "1- Search by national ID." << endl;
	cout << "2- Search by phone number." << endl << endl;

	// Get the choice from the user
	cout << "Please enter your choice: ";
	getInt(searchOption);
	
	// Search for the index of the requested customer and store it
	int found = searchCustomer(searchOption , numberOfCustomers);
	
	// If found >= that means the customers is exist 
	if (found >= 0)
	{
		// Set the requested customer as the renter in the bill 
		bills[numberOfBills].renter = customers[found];
		
		// Complete the rental proccess
		rentTheRoom(numberOfRooms , numberOfBills , numberOfRentedRooms);
	}
	
	// If found less than 0 that means the customers is not exist 
	else
	{
		cout << "Wrong phone number, The customer does not exist .. Please try again. " << endl;
	}	
}

void rentForCustumerAPP(int numberOfCustomers, int &numberOfRooms , int &numberOfBills , int &numberOfRentedRooms )
{
	int  IDIndex = -1 , phoneIndex = -1;
	string ID , phone;
	// Declare a variabl to get the choice from the user
	int searchOption;
	
	cout << "----------- Rent a room for -----------" << endl;
	cout << "1- please enter your national ID: " ;
	cin.ignore();
	getline(cin,ID);
	cout << "2- please enter your phone number: " ;
	getline(cin,phone);
		
	for (int i =0; i<numberOfCustomers; i++)
    {
   		// If the customer is found
   		if (ID == customers[i].nationalID)
   		{ 
			IDIndex = i;
    	}
   	}

	// Loop through the array of customers to check if the customer is exist
  	for (int i =0; i<numberOfCustomers; i++)
   	{
   		// If the customer is found
    	if (phone == customers[i].phoneNumber)
   		{ 
   		// return the index
   		phoneIndex = i;
    	}
   	}
   	if(phoneIndex<0)
   	{
   		cout<<"wrong phone number!!"<<endl;
		   return ;	
	}
 	if(IDIndex<0)
   	{
   		cout<<"wrong ID number!!"<<endl;
		   return ;	
	}
	else if(IDIndex==phoneIndex)
	{
		// Set the requested customer as the renter in the bill 
		bills[numberOfBills].renter = customers[IDIndex];
		
		// Complete the rental proccess
		rentTheRoom(numberOfRooms , numberOfBills , numberOfRentedRooms);
	}
	
}

