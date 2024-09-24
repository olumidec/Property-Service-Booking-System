# Properties Class

## Overview

The `Properties` class is designed to manage properties within my program . It provides functionality for setting and retrieving property information, searching for properties, viewing property listings, and buying properties.

## Usage

The use of the  `Properties` class in my C++ project consists of :

1. Including the `Properties` header file in my source files:

   ```cpp
   #include "Properties.h"

## Create intance of 'Properties' class
Properties property;

## Dependencies
My class relies on the following standard C++ libaries:
`iostream`
`fstream`
`vector`
`string`
We need to ensure that these libaries are available in the development environment.

## Class memebers

## Private Attributes

`address`: string - Holds the address of the property.
`price`: double - Stores the price of the property.
`props`: string - Additional property information.
`newProps`: char - Indicates whether the property is new.

## Public Member Functions

`Properties()`: Constructor.
`void setFulladdress()`: Sets the full address of the property.
`void setPrice()`: Sets the price of the property.
`void searchProperty()`: Searches for a property.
`void viewAllProperties()`: Displays all properties.
`void buyProperty()`: Buys a property.
`bool addProperty()`: Adds a new property.
`int property_listing1()`: Lists properties.
`bool isLoggedin()`: Checks if the user is logged in.
`int mainDashboard()`: Displays the main dashboard.
`string getFulladdress()const`: Retrieves the full address of the property.
`double getPrice()const`: Retrieves the price of the property.


