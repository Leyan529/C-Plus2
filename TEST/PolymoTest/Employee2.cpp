// Fig. 13.14: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee2.h" // Employee class definition
using namespace std;

// constructor
Employee2::Employee2( const string &first, const string &last,
   const string &ssn )
   : firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
   // empty body 
} // end Employee constructor

// set first name
void Employee2::setFirstName( const string &first ) 
{ 
   firstName = first;  
} // end function setFirstName

// return first name
string Employee2::getFirstName() const 
{ 
   return firstName;  
} // end function getFirstName

// set last name
void Employee2::setLastName( const string &last )
{
   lastName = last;   
} // end function setLastName

// return last name
string Employee2::getLastName() const
{
   return lastName;   
} // end function getLastName

// set social security number
void Employee2::setSocialSecurityNumber( const string &ssn )
{
   socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee2::getSocialSecurityNumber() const
{
   return socialSecurityNumber;   
} // end function getSocialSecurityNumber

// print Employee's information (virtual, but not pure virtual)
void Employee2::print() const
{ 
   cout << getFirstName() << ' ' << getLastName() 
      << "\nsocial security number: " << getSocialSecurityNumber(); 
} // end function print

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
