// Fig. 10.11: Date1.cpp
// Date1 class member-function definitions.
#include <iostream>
#include "Date1.h" // include Date1 class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date1::Date1( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
   {                     
      month = 1; // invalid month set to 1
      cout << "Invalid month (" << mn << ") set to 1.\n";
   } // end else

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date1 object to show when its constructor is called
   cout << "Date1 object constructor for Date1 ";
   print();                   
   cout << endl;
} // end Date1 constructor

// print Date1 object in form month/day/year
void Date1::print() const
{
   cout << month << '/' << day << '/' << year; 
} // end function print

// output Date1 object to show when its destructor is called
Date1::~Date1()
{ 
   cout << "Date1 object destructor for Date1 ";
   print();
   cout << endl;
} // end ~Date1 destructor

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
int Date1::checkDay( int testDay ) const
{
   static const int daysPerMonth[ monthsPerYear + 1 ] = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || 
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   cout << "Invalid day (" << testDay << ") set to 1.\n";
   return 1; // leave object in consistent state if bad value
} // end function checkDay

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
