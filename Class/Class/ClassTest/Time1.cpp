// Fig. 10.18: Time1.cpp 
// Time1 class member-function definitions.
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Time1.h" // Time1 class definition
using namespace std;

// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time1::Time1( int hr, int min, int sec )
{
   setTime( hr, min, sec ); 
} // end Time1 constructor

// set values of hour, minute, and second
Time1 &Time1::setTime( int h, int m, int s ) // note Time1 & return
{
   setHour( h );
   setMinute( m );
   setSecond( s ); 
   return *this; // enables cascading
} // end function setTime

// set hour value
Time1 &Time1::setHour( int h ) // note Time1 & return
{
   hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
   return *this; // enables cascading
} // end function setHour

// set minute value
Time1 &Time1::setMinute( int m ) // note Time1 & return
{
   minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
   return *this; // enables cascading
} // end function setMinute

// set second value
Time1 &Time1::setSecond( int s ) // note Time1 & return
{
   second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
   return *this; // enables cascading
} // end function setSecond

// get hour value
int Time1::getHour() const 
{
   return hour; 
} // end function getHour

// get minute value
int Time1::getMinute() const 
{ 
   return minute; 
} // end function getMinute

// get second value
int Time1::getSecond() const
{
   return second; 
} // end function getSecond

// print Time1 in universal-Time1 format (HH:MM:SS) 
void Time1::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << hour << ":"
      << setw( 2 ) << minute << ":" << setw( 2 ) << second;
} // end function printUniversal

// print Time1 in standard-Time1 format (HH:MM:SS AM or PM)
void Time1::printStandard() const
{
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << minute
      << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

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
