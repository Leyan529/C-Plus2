// Fig. 10.13: Employee1.cpp
// Employee1 class member-function definitions.
#include <iostream>
#include "Employee1.h" // Employee1 class definition
#include "Date1.h" // Date1 class definition
using namespace std;

// constructor uses member initializer list to pass initializer 
// values to constructors of member objects  
Employee1::Employee1( const string &first, const string &last,
   const Date1 &dateOfBirth, const Date1 &dateOfHire )
   : firstName( first ), // initialize firstName
     lastName( last ), // initialize lastName
     birthDate( dateOfBirth ), // initialize birthDate
     hireDate( dateOfHire ) // initialize hireDate
{
   // output Employee1 object to show when constructor is called
   cout << "Employee1 object constructor: " 
      << firstName << ' ' << lastName << endl;
} // end Employee1 constructor

// print Employee1 object
void Employee1::print() const
{
   cout << lastName << ", " << firstName << "  Hired: ";
   hireDate.print();
   cout << "  Birthday: ";
   birthDate.print();
   cout << endl;
} // end function print

// output Employee1 object to show when its destructor is called
Employee1::~Employee1()
{ 
   cout << "Employee1 object destructor: " 
      << lastName << ", " << firstName << endl;
} // end ~Employee1 destructor

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
