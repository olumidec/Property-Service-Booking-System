#include <iostream> //Input-Output stream
#include <fstream> //File stream for input/output operations
#include <vector> // Vector container for dynamic arrays
#include <string> //Header guard to prevent multiple incusion of headers
#ifndef Properties_H

using namespace std;



class Properties //Declaration of class
{
private://private attributes to help the rounding up of the class.
 
    
    string address;
    double price;
    string props;
    char newProps;
    

    


public:
    Properties(); //default constructor

    //Method to set address and price 
    void setFulladdress();
    void setPrice();

    void searchProperty();
    void viewAllProperties();
    void buyProperty();
     
    //getter functions
    bool addProperty();
    int property_listing1();
    bool isLoggedin();
    int mainDashboard();
    string getFulladdress()const;
    double getPrice()const;


};

#endif //Properties_H