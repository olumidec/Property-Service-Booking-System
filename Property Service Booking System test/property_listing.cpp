#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "property_listing.h"
#include <fstream> //used to reat and write files
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>


using namespace std;

//Constructor forthe properties class
Properties::Properties(){
    address = "4 avenue";
    price = 34.99;
}

//Method to set full address of prop
void  Properties::setFulladdress()
{
    string setFulladdress;

    while(true)
    {
        cout << "Enter addres of  the property: ";
        getline(cin, setFulladdress);

        if (setFulladdress.empty())
        {
            cout << "Address not set" << endl;
        }
        else
        {
            cout << "Your address is " << setFulladdress << endl;
            address = setFulladdress;
            break;
        }
    }
}

//Method to set price of prop
void Properties::setPrice()
{
    string setPrice;

    while(true)
    {
        cout << "Enter Price of  the property: ";
        cin >> setPrice;

        if (setPrice.empty())
        {
            cout << " Price not set" << endl;
        }
        else
        {
            cout << "Your Price is " << setPrice << endl;
            price = stod(setPrice);
            break;
        }
    }

}

//Method to retreive the price of the property
string Properties::getFulladdress()const
{
    return address;
}

double Properties::getPrice()const
{
    return price;
}
bool Properties::isLoggedin()
{
    string username, password;
    string un, pw; //comparison strings
    cout << "Enter username: ";
    cin>> username;
    cout << "Enter a password: ";
    cin>> password;

    ifstream read(username + ",txt"); //ifstream reads the files
    getline(read, un); //reads username
    getline(read, pw); //reads password

    if(un == username && pw == password)  //if both un & password are same true
    {
        return true;
    }
    else
    {
        return false;
    }
    
}



//Method to display main dashboard
int Properties::mainDashboard()
{
    int choice;

    cout << endl;
    cout<<"Main Menu" << endl;
    cout<<"________________________________" << endl;
    cout<<"1. Register" << endl;
    cout<<"2.Login" << endl;
    cout<< endl;
    cout<<"Your choice: ";
    cin>>choice;

    if (choice == 1)
    {
        string username, password;
        cout<< "Registration" << endl;
        cout<< endl;
        cout<< "Select a username: ";
        cin>> username;
        cout<< "Select a password: ";
        cin>> password;

        ofstream file; //ofstream creating the file for the users data to be stored
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Welcome" << username << "!" << endl;
        int choiceThree;


        cout << "**************************************" << endl;
        cout << "----------------WELLCOME------------" << endl;
        cout << "**************************************" << endl;
        cout << endl;
        cout << "DASHBOARD" << endl;
        cout << "No new messages." << endl; //example of what could appear on the user dashboard
        cout << endl;
        cout << "1. Sign Out" << endl;
        cout << "2. Access the Main Menu" << endl;
        cout << "Your choice: " << endl;
        cin >> choiceThree;

        if(choiceThree == 1)
            {
                system("exit"); //exits program
            }
        else if(choiceThree == 2)
            {
                //return to the beginning of the main() function
                property_listing1();
            }
        else if(choiceThree >= 3)
        {
            cout << "Wrong number pick again" << endl;
            mainDashboard();
            return 0;
        }
    }
     else if (choice == 2)// if user chooses to login
     {
        bool status = isLoggedin();

        if(status) //if isLoggedin() returns false
        {
            system("clear");
            cout << endl;
            cout << "Invalid login!" << endl;
            mainDashboard();
            return 0;

        }
        else //if isLoggedin() returns true, the dashboard is displayed
        {
            cout << "Successfully logged in!" << endl;
            cout << endl;

            int choiceTwo;

            // Display dashboard and welcome your uer back
            cout << "**************************************" << endl;
            cout << "-------------WELLCOME BACK!------------" << endl;
            cout << "**************************************" << endl;
            cout << endl;
            cout << "DASHBOARD" << endl;
            cout << "No new messages." << endl; //example of what could appear on the user dashboard
            cout << endl;
            cout << "1. Sign Out" << endl;
            cout << "2. Access the Main Menu" << endl;
            cout << "Your choice: " << endl;
            cin >> choiceTwo;

            if(choiceTwo == 1)
            {
                system("exit"); //exits program
            }
            else if(choiceTwo == 2)
            {
                //return to the beginning of the main() function
                property_listing1();
            }
            else if(choiceTwo >= 3)
            {
                cout << "Wrong number pick again" << endl;
                mainDashboard();
                return 0;
            }


        }
    }
    else if(choice >=3)
    {
        cout << "Invalid choice please pick again" << endl;
        mainDashboard();
    }
    
    return 0;

}


// Function to add a property to the listing
bool Properties::addProperty() {

    setFulladdress();
    setPrice();

    cout << "The address of the property is " << getFulladdress() << endl;
    cout << "The Price of the property is" << getPrice() << endl ;
    cout << "Successfully added property" << endl;
    const string filePath = "text.txt";

    ofstream outfile(filePath, ios::app);
    if (outfile.is_open())
    {
        outfile<< address << "," << price << endl;
        outfile.close();
        
    }
    else{
        cerr << "Unable to open file" << filePath << endl;
    }
    return true;
}

// Function to search for properties
void Properties::searchProperty() {
    cout << "Search functionality is under construction. Will be added soon" << endl;
}

// Function to display all properties in the listing
void Properties::viewAllProperties() 
{

    const string filePath = "text.txt";
    ifstream infile(filePath);

    if(infile.is_open())
    {
        cout << "Properties in the listing are: " << endl;
        string line;
        while (getline(infile, line))
        {
            stringstream ss(line);
            getline(ss, address ,',');
            ss >> price;
            cout << "Address:" <<address << ",Price: " << price << endl;
        }
        infile.close();
    }else {
        cerr << "Unable to open file" <<filePath << endl;
    }
}

// Function to buy a property
void Properties::buyProperty()
{
    int buychoice;
    viewAllProperties();
    cout << "Enter the number of the property you want to Book: ";
    cin >> buychoice;

    //Open the file again to read the selected property
    const string filePath = "text.txt";
    ifstream infile(filePath);

    if (infile.is_open())
    {
        string line;
        int index =1;
        while (getline(infile, line))
        {
            if (index == buychoice)
            {
                stringstream ss(line);
                getline(ss, address, ',');
                ss >> price;
                cout << "You have chosen to book Property: " <<endl;
                cout << "Address: " << address << "| Price :" << price << endl;
                //Performs purchase operation here
                break;
                //Exits the loop after finding the selected property
            }
            index++;
        }
        infile.close();
    } else{
        cerr << "Unable to open file" << filePath << endl;
    }
}
 
 // Function to interact with the property listing service here
int Properties::property_listing1(){
    int choice;

    do {
        cout << "_______________________________________" <<endl;
        cout << "|         Property Listing Service     | "<<endl;
        cout << "|______________________________________|" <<endl;
        cout << "1. Add Property" << endl;
        cout << "2. Search Property" << endl;
        cout << "3. View All Properties" << endl;
        cout << "4. Book Property" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();// Ignore newline character
                addProperty();
                break;
            case 2:
                searchProperty();
                break;
            case 3:
                viewAllProperties();
                break;
            case 4:
                buyProperty();
                break;
            case 5:
                cout << "*************************" << endl;
                cout << "*        GOODBYE        *" << endl;
                cout << "*************************" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

