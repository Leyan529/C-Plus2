#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
void Constructor();
void StringCompare();
void Sub_SwapStr();

void Characterist();
void printStatistics(const string &);

void Find();
void erase();
void insert();
void toCStr();
void Iterator();
void streamProcessing1();
void streamProcessing2();
void StringTest() {

	//Constructor();
	//StringCompare();
	//Sub_SwapStr();
	//Characterist();
	//Find();
	//erase();
	//insert();
	//toCStr();
	//Iterator();
	//streamProcessing1();
	streamProcessing2();
	system("pause");
}

void Constructor()
{
	string name1("abc");
	string name2(3, 'x'); //

	cout <<"name1: "<< name1 
		<< " , name2: " << name2 << endl;

	string string1("cat");
	string string2; // initialized to the empty string
	string string3; // initialized to the empty string

	string2 = string1; // assign string1 to string2
	string3.assign(string1); // assign string1 to string3
	cout << "string1: " << string1 << "\nstring2: " << string2
		<< "\nstring3: " << string3 << "\n\n";

	// modify string2 and string3 
	string2[0] = string3[2] = 'r';

	cout << "After modification of string2 and string3:\n" << "string1: "
		<< string1 << "\nstring2: " << string2 << "\nstring3: ";

	// demonstrating member function at
	for (int i = 0; i < string3.length(); i++)
		cout << string3.at(i);  //逐一輸出string3字元

	// declare string4 and string5
	string string4(string1 + "apult"); // 串接
	string string5;

	// overloaded +=                               
	string3 += "pet"; // create "carpet"           
	string1.append("acomb"); // create "catacomb"

							 // append subscript locations 4 through end of string1 to
							 // create string "comb" (string5 was initially empty)
	string5.append(string1, 4, string1.length() - 4);

	cout << "\n\nAfter concatenation:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << "\nstring5: " << string5 << endl;

}

void StringCompare()
{
	string string1("Testing the comparison functions.");
	string string2("Hello");
	string string3("stinger");
	string string4(string2);

	cout << "string1: " << string1 << "\nstring2: " << string2
		<< "\nstring3: " << string3 << "\nstring4: " << string4 << "\n\n";

	// comparing string1 and string4
	if (string1 == string4)
		cout << "string1 == string4\n";
	else // string1 != string4 
	{
		if (string1 > string4)
			cout << "string1 > string4\n";
		else // string1 < string4
			cout << "string1 < string4\n";
	} // end else

	  // comparing string1 and string2
	int result = string1.compare(string2);

	if (result == 0)
		cout << "string1.compare( string2 ) == 0\n";
	else // result != 0
	{
		if (result > 0)
			cout << "string1.compare( string2 ) > 0\n";
		else // result < 0
			cout << "string1.compare( string2 ) < 0\n";
	} // end else

	  // comparing string1 (elements 2-5) and string3 (elements 0-5)
	result = string1.compare(2, 5, string3, 0, 5);

	if (result == 0)
		cout << "string1.compare( 2, 5, string3, 0, 5 ) == 0\n";
	else // result != 0
	{
		if (result > 0)
			cout << "string1.compare( 2, 5, string3, 0, 5 ) > 0\n";
		else // result < 0
			cout << "string1.compare( 2, 5, string3, 0, 5 ) < 0\n";
	} // end else

	  // comparing string2 and string4
	result = string4.compare(0, string2.length(), string2);

	if (result == 0)
		cout << "string4.compare( 0, string2.length(), "
		<< "string2 ) == 0" << endl;
	else // result != 0
	{
		if (result > 0)
			cout << "string4.compare( 0, string2.length(), "
			<< "string2 ) > 0" << endl;
		else // result < 0
			cout << "string4.compare( 0, string2.length(), "
			<< "string2 ) < 0" << endl;
	} // end else

	  // comparing string2 and string4
	result = string2.compare(0, 3, string4);

	if (result == 0)
		cout << "string2.compare( 0, 3, string4 ) == 0" << endl;
	else // result != 0
	{
		if (result > 0)
			cout << "string2.compare( 0, 3, string4 ) > 0" << endl;
		else // result < 0
			cout << "string2.compare( 0, 3, string4 ) < 0" << endl;
	} // end else
}

void Sub_SwapStr()
{
	string string1("The airplane landed on time.");

	// retrieve substring "plane" which
	// begins at subscript 7 and consists of 5 characters
	cout << "orignal: " << string1 << endl <<
		"SbStr(7, 5) : " << string1.substr(7, 5) << endl;

	cout << "********************************" << endl;

	string first("one");
	string second("two");

	// output strings
	cout << "Before swap:\n first: " << first << "\nsecond: " << second;

	first.swap(second); // swap strings

	cout << "\n\nAfter swap:\n first: " << first
		<< "\nsecond: " << second << endl;
}

void Characterist()
{
	string string1; // empty string

	cout << "Statistics before input:\n" << boolalpha;
	printStatistics(string1);

	// read in only "tomato" from "tomato soup"
	cout << "\n\nEnter a string: ";
	cin >> string1; // delimited by whitespace
	cout << "The string entered was: " << string1;

	cout << "\nStatistics after input:\n";
	printStatistics(string1);

	// read in "soup"
	cin >> string1; // delimited by whitespace
	cout << "\n\nThe remaining string is: " << string1 << endl;
	printStatistics(string1);

	// append 46 characters to string1
	string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
	cout << "\n\nstring1 is now: " << string1 << endl;
	printStatistics(string1);

	// add 10 elements to string1
	string1.resize(string1.length() + 10);
	cout << "\n\nStats after resizing by (length + 10):\n";
	printStatistics(string1);

	cout << endl;
}
void printStatistics(const string &stringRef)
{
	cout << "capacity: " << stringRef.capacity() << "\nmax size: "
		<< stringRef.max_size() << "\nsize: " << stringRef.size()
		<< "\nlength: " << stringRef.length()
		<< "\nempty: " << stringRef.empty() << endl;
} // end printStatistics

void Find()
{
	string string1("noon is 12 pm; midnight is not.");
	int location;

	// find "is" at location 5 and 24
	cout << "Original string:\n" << string1
		<< "\n\n(find) \"is\" was found at: " << string1.find("is")
		<< "\n(rfind) \"is\" was found at: " << string1.rfind("is");

	// find 'o' at location 1
	location = string1.find_first_of("misop");
	cout << "\n\n(find_first_of) found '" << string1[location]
		<< "' from the group \"misop\" at: " << location;

	// find 'o' at location 29
	location = string1.find_last_of("misop");
	cout << "\n\n(find_last_of) found '" << string1[location]
		<< "' from the group \"misop\" at: " << location;

	// find '1' at location 8 
	location = string1.find_first_not_of("noi spm");
	cout << "\n\n(find_first_not_of) '" << string1[location]
		<< "' is not contained in \"noi spm\" and was found at: "
		<< location;

	// find '.' at location 12
	location = string1.find_first_not_of("12noi spm");
	cout << "\n\n(find_first_not_of) '" << string1[location]
		<< "' is not contained in \"12noi spm\" and was "
		<< "found at: " << location << endl;

	// search for characters not in string1
	location = string1.find_first_not_of(
		"noon is 12 pm; midnight is not.");
	cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
		<< " returned: " << location << endl;
}

void erase()
{
	string string1("The values in any left subtree"
		"\nare less than the value in the"
		"\nparent node and the values in"
		"\nany right subtree are greater"
		"\nthan the value in the parent node");

	cout << "Original string:\n" << string1 << endl << endl;

	// remove all characters from (and including) location 62 
	// through the end of string1
	string1.erase(62); //刪除從第62字元以後的所有字元

	// output new string
	cout << "Original string after erase:\n" << string1
		<< "\n\nAfter first replacement:\n";

	int position = string1.find(" "); // find first space

									  // replace all spaces with period
	while (position != string::npos)
	{
		string1.replace(position, 1, "."); //將尋找到的空白字元換成逗點
		position = string1.find(" ", position + 1); //從搜尋到位置的下一個位置繼續搜尋
	} // end while

	cout << string1 << "\n\nAfter second replacement:\n";

	position = string1.find("."); // find first period

								  // replace all periods with two semicolons
								  // NOTE: this will overwrite characters
	while (position != string::npos)
	{
		string1.replace(position, 2, "xxxxx;;yyy", 5, 2);
		position = string1.find(".", position + 1);
	} // end while

	cout << string1 << endl;
}

void insert()
{
	string string1("beginning end");
	string string2("middle ");
	string string3("12345678");
	string string4("xx");

	cout << "Initial strings:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << "\n\n";

	// insert "middle" at location 10 in string1
	string1.insert(10, string2);

	// insert "xx" at location 3 in string3
	string3.insert(3, string4, 0, string::npos);

	cout << "Strings after insert:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << endl;
}

void toCStr()
{
	string string1("STRINGS"); // string constructor with char* arg
	const char *ptr1 = 0; // initialize *ptr1
	int length = string1.length();
	char *ptr2 = new char[length + 1]; // including null

									   // copy characters from string1 into allocated memory
	string1.copy(ptr2, length, 0); // copy string1 to ptr2 char*
	ptr2[length] = '\0'; // add null terminator

	cout << "string string1 is " << string1
		<< "\nstring1 converted to a C-Style string is "
		<< string1.c_str() << "\nptr1 is ";

	// Assign to pointer ptr1 the const char * returned by
	// function data(). NOTE: this is a potentially dangerous
	// assignment. If string1 is modified, pointer ptr1 can
	// become invalid.
	ptr1 = string1.data();

	// output each character using pointer
	for (int i = 0; i < length; i++)
		cout << *(ptr1 + i); // use pointer arithmetic

	cout << "\nptr2 is " << ptr2 << endl;
	delete[] ptr2; // reclaim dynamically allocated memory
}

void Iterator()
{
	string string1("Testing iterators");
	string::const_iterator iterator1 = string1.begin();

	cout << "string1 = " << string1
		<< "\n(Using iterator iterator1) string1 is: ";

	// iterate through string
	while (iterator1 != string1.end())
	{
		cout << *iterator1; // 用迭代器依序走訪每個字元
		iterator1++; // advance iterator to next char
	} // end while

	cout << endl;
}

void streamProcessing1()
{
	ostringstream outputString; // create ostringstream instance

	string string1("Output of several data types ");
	string string2("to an ostringstream object:");
	string string3("\n        double: ");
	string string4("\n           int: ");
	string string5("\naddress of int: ");

	double double1 = 123.4567;
	int integer = 22;

	// output strings, double and int to ostringstream outputString         
	outputString << string1 << string2 << string3 << double1
		<< string4 << integer << string5 << &integer;

	// call str to obtain string contents of the ostringstream
	cout << "outputString contains:\n" << outputString.str();

	// add additional characters and call str to output string
	outputString << "\nmore characters added";
	//cout 輸出ostringstream串流裡的所有文字訊息
	cout << "\n\nafter additional stream insertions,\n"
		<< "outputString contains:\n" << outputString.str() << endl;
}

void streamProcessing2()
{
	string input("Input test 123 4.7 A");
	istringstream inputString(input);
	string string1;
	string string2;
	int integer;
	double double1;
	char character;

	//istringstream 接收輸入字串,遇空格則結束
	inputString >> string1 >> string2 >> integer >> double1 >> character;

	cout << "The following items were extracted\n"
		<< "from the istringstream object:" << "\nstring: " << string1
		<< "\nstring: " << string2 << "\n   int: " << integer
		<< "\ndouble: " << double1 << "\n  char: " << character;

	// attempt to read from empty stream
	long value;
	inputString >> value; //inputString讀入空變數,串流狀態為EOF

	// test stream results
	if (inputString.good()) //inputString裡沒有任何資料,good旗標為false
		cout << "\n\nlong value is: " << value << endl;
	else
		cout << "\n\ninputString is empty" << endl;
}
