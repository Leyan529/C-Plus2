// Fig. 10.8: Increment1.cpp
// Erroneous attempt to initialize a constant of a built-in data 
// type by assignment.
#include <iostream>
#include "Increment1.h" // include definition of class Increment1
using namespace std;

// constructor; constant member 'Increment1' is not initialized 
Increment1::Increment1( int c, int i )
{ 
   count = c; // allowed because count is not constant
   //Increment1 = i; // ERROR: Cannot modify a const object (compile error)
} // end constructor Increment1

// print count and Increment1 values
void Increment1::print() const
{
   cout << "count = " << count << ", Increment1 = " << increment << endl;
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
