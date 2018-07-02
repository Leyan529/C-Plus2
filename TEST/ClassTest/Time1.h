// Fig. 10.17: Time1.h
// Cascading member function calls.

// Time1 class definition.
// Member functions defined in Time1.cpp.
#ifndef TIME_H
#define TIME_H

class Time1 
{
public:
   Time1( int = 0, int = 0, int = 0 ); // default constructor

   // set functions (the Time1 & return types enable cascading)
   Time1 &setTime( int, int, int ); // set hour, minute, second
   Time1 &setHour( int ); // set hour
   Time1 &setMinute( int ); // set minute
   Time1 &setSecond( int ); // set second

   // get functions (normally declared const)
   int getHour() const; // return hour
   int getMinute() const; // return minute
   int getSecond() const; // return second

   // print functions (normally declared const)
   void printUniversal() const; // print universal Time1
   void printStandard() const; // print standard Time1
private:
   int hour; // 0 - 23 (24-hour clock format)
   int minute; // 0 - 59
   int second; // 0 - 59
}; // end class Time1

#endif

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
