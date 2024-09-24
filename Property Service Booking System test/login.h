#include <iostream>
#include <vector>
#include <fstream> //used to reat and write files
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>


using namespace std;

bool isLoggedin()
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

int main()
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
        cout << "Please restart code and login with your new details" << endl;
    }
     else if (choice == 2)// if user chooses to login
     {
        bool status = isLoggedin();

        if(status) //if isLoggedin() returns false
        {
            system("clear");
            cout << endl;
            cout << "Invalid login!" << endl;
            main();
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
                property_listing1(); //return to the beginning of the main() function
            }
            return 0;


        }
     }

}

