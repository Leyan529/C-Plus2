#include <iomanip>
#include <iostream>
using namespace std;

void inputStreamTest1();
void inputStreamTest2();
void inputStreamTest3();
void inputStreamTest4();
void inputStreamTest5();

ostream& bell(ostream& output) {
	return output << '\a';
}
ostream& carriageReturn(ostream& output) {
	return output << '\r';
}
ostream& tab(ostream& output) {
	return output << '\t';
}
ostream& endLine(ostream& output) {
	return output << '\n' << flush;
}
void ownInputStreamTest();
void outputStreamTest1();
void outputStreamTest2();
void SaveStreamSettingTest();
void streamErrorStateTest();


void StreamTest() {
	//inputStreamTest1();
	//inputStreamTest2();
	//inputStreamTest3();
	//inputStreamTest4();
	//inputStreamTest5();

	//ownInputStreamTest();
	//outputStreamTest1();
	//outputStreamTest2();
	//SaveStreamSettingTest();
	streamErrorStateTest();
	system("pause");
}

void inputStreamTest1()
{
	char *a = "BASIC";//字符指针指向'B'
	for (int i = 4; i >= 0; i--)
		cout.put(*(a + i));                  //从最后一个字符开始输出
	cout.put('\n');

	char *b = "BASIC";
	for (int i = 4; i >= 0; i--)
		putchar(*(b + i));
	putchar('\n');

	cout << "---------------------------------" << endl;

	const char *const word = "again";

	// display value of char *, then display value of char *
	// static_cast to void *
	cout << "Value of word is: " << word << endl
		<< "將word靜態轉型為<const void *>: "
		<< static_cast< const void * >(word) << endl;
}

void inputStreamTest2()
{
	int character; // use int, because char cannot represent EOF

				   // prompt user to enter line of text
	cout << "Before input, cin.eof() is " << cin.eof() << endl
		<< "Enter a sentence followed by end-of-file:" << endl;

	// use get to read each character; use put to display it
	while ((character = cin.get()) != EOF) // EOF (ctrl+z字元)
		cout.put(character); //輸出輸入字元

	// display end-of-file character
	cout << "\nEOF in this system is: " << character << endl;
	cout << "After input of EOF, cin.eof() is " << cin.eof() << endl;
}

void inputStreamTest3()
{
	const int SIZE = 80;
	char buffer1[SIZE];
	char buffer2[SIZE];


	cout << "輸入序列:" << endl;

	cin >> buffer1; //將輸入串流的資料直接流向buffer1
	cout << "\n輸出 buffer1" << endl << buffer1 << "\n\n";

	cin.get(buffer2, SIZE); //cin.get(字元緩衝區,緩衝區大小)用來接收一行字符串,可以接收空格
	cout << "\n輸出 buffer2" << endl << buffer2 << "\n\n";

	cin.clear();
	cout << "---------------------------------" << endl;

	char buffer3[SIZE];
	cin.getline(buffer3, SIZE); // 接受一個字符串，可以接收空格並輸出
	cout << "\n輸出 buffer3" << endl << buffer3 << "\n\n";

	cin.clear();
	cout << "---------------------------------" << endl;
	char buffer[SIZE]; // create array of 80 characters

					   
	cout << "Enter a sentence:" << endl;
	cin.read(buffer, 20); //cin.read(buffer,num) : 從輸入串流讀取num個字元放入緩衝區

	
	cout << endl << "The sentence entered was:" << endl;
	cout.write(buffer, cin.gcount()); //cout.write(buffer,num) : 從緩衝區讀取num個字元輸出到輸出串流
	cout << endl;
}

void inputStreamTest4()
{	
	int number;

	cout << "Enter a decimal number: ";
	cin >> number; // input number

				   // use hex stream manipulator to show hexadecimal number
	cout << number << " in hexadecimal is: " << hex
		<< number << endl;

	// use oct stream manipulator to show octal number
	cout << dec << number << " in octal is: "
		<< oct << number << endl;

	// use setbase stream manipulator to show decimal number
	cout << setbase(10) << number << " in decimal is: "
		<< number << endl;
}

void inputStreamTest5()
{
	double root2 = sqrt(2.0); // calculate square root of 2
	int places; // precision, vary from 0-9

	cout << "Square root of 2 with precisions 0-9." << endl
		<< "Precision set by ios_base member function "
		<< "precision:" << endl;

	cout << fixed; // use fixed point format

				   // display square root using ios_base function precision
	for (places = 0; places <= 9; places++)
	{
		cout.precision(places);
		cout << root2 << endl;
	} // end for

	cout << "\nPrecision set by stream manipulator "
		<< "setprecision:" << endl;

	// set precision for each digit, then display square root
	for (places = 0; places <= 9; places++)
		cout << setprecision(places) << root2 << endl;

	cin.clear();
	cout << "---------------------------------" << endl;

	int widthValue = 4;
	char sentence[10];

	cout << "Enter a sentence:" << endl;
	cin.width(5); //設置輸入寬度為7，不足用空格填充

				  // set field width, then display characters based on that width 
	while (cin >> sentence)
	{
		cout.width(widthValue++);
		cout << sentence << endl;
		cin.width(5); // input 5 more characters from sentence
	} // end while
}

void ownInputStreamTest()
{
	cout << "Testing the tab manipulator:" << endLine
		<< 'a' << tab << 'b' << tab << 'c' << endLine;

	cout << "Testing the carriageReturn and bell manipulators:"
		<< endLine << "..........";

	cout << endLine; 

	cout << bell; // use bell manipulator (\a. 換頁字元)
				  
	cout << carriageReturn << "-----" << endLine; // use  carriageReturn (\r. 換頁字元.)
}

void outputStreamTest1()
{
	cout << "Before using showpoint" << endl
		<< "9.9900 prints as: " << 9.9900 << endl
		<< "9.9000 prints as: " << 9.9000 << endl
		<< "9.0000 prints as: " << 9.0000 << endl << endl;

	// display double value after showpoint
	cout << showpoint
		<< "After using showpoint" << endl
		<< "9.9900 prints as: " << 9.9900 << endl
		<< "9.9000 prints as: " << 9.9000 << endl
		<< "9.0000 prints as: " << 9.0000 << endl;

	cout <<"---------------------------------"<< endl;

	int x = 12345;

	// display x right justified (default)
	cout << "Default is right justified:" << endl
		<< setw(10) << x;

	// use left manipulator to display x left justified
	cout << "\n\nUse std::left to left justify x:\n"
		<< left << setw(10) << x;

	// use right manipulator to display x right justified
	cout << "\n\nUse std::right to right justify x:\n"
		<< right << setw(10) << x << endl;

	cout << "---------------------------------" << endl;

	cout << internal << showpos << setw(10) << 123 << endl;
	// internal (輸出串流國際格式)
	// 字串靠左對齊，數字靠右對齊，並且中間空格預設塞入填充字符。

	cout << "---------------------------------" << endl;	
}

void outputStreamTest2()
{
	int x = 10000;

	// display x
	cout << x << " printed as int right and left justified\n"
		<< "and as hex with internal justification.\n"
		<< "Using the default pad character (space):" << endl;

	// display x with base
	cout << showbase << setw(10) << x << endl;

	// display x with left justification
	cout << left << setw(10) << x << endl;

	// display x as hex with internal justification
	cout << internal << setw(10) << hex << x << endl << endl;

	cout << "Using various padding characters:" << endl;

	// display x using padded characters (right justification)
	cout << right;
	cout.fill('*');
	cout << setw(10) << dec << x << endl;

	// display x using padded characters (left justification)
	cout << left << setw(10) << setfill('%') << x << endl;

	// display x using padded characters (internal justification)
	cout << internal << setw(10) << setfill('^') << hex
		<< x << endl;

	cout << "---------------------------------" << endl;

	cout << "Printing uppercase letters in scientific" << endl
		<< "notation exponents and hexadecimal values:" << endl;

	// use std:uppercase to display uppercase letters; use std::hex and 
	// std::showbase to display hexadecimal value and its base
	cout << uppercase << 4.345e10 << endl  //轉大寫
		<< hex << showbase << 123456789 << endl; //轉16進制

	cout << "---------------------------------" << endl;

	bool booleanValue = true;

	// display default true booleanValue
	cout << "booleanValue is " << booleanValue << endl;

	// display booleanValue after using boolalpha
	cout << "booleanValue (after using boolalpha) is "
		<< boolalpha << booleanValue << endl << endl;

	cout << "switch booleanValue and use noboolalpha" << endl;
	booleanValue = false; // change booleanValue
	cout << noboolalpha << endl; // use noboolalpha

								 // display default false booleanValue after using noboolalpha
	cout << "booleanValue is " << booleanValue << endl;

	// display booleanValue after using boolalpha again
	cout << "booleanValue (after using boolalpha) is "
		<< boolalpha << booleanValue << endl;

}

void SaveStreamSettingTest()
{
	int integerValue = 1000;
	double doubleValue = 0.0947628;

	// display flags value, int and double values (original format)
	cout << "The value of the flags variable is: " << cout.flags()
		<< "\nPrint int and double in original format:\n"
		<< integerValue << '\t' << doubleValue << endl << endl;

	// 將cout.flags()回傳的輸出串流的格式化設定值Save到originalFormat變數裡
	ios_base::fmtflags originalFormat = cout.flags();
	cout << showbase << oct << scientific; // 修改輸出串流設定

										   // display flags value, int and double values (new format)
	cout << "The value of the flags variable is: " << cout.flags()
		<< "\nPrint int and double in a new format:\n"
		<< integerValue << '\t' << doubleValue << endl << endl;

	cout.flags(originalFormat); // 回復輸出串流設定

								// display flags value, int and double values (original format)
	cout << "The restored value of the flags variable is: "
		<< cout.flags()
		<< "\nPrint values in original format again:\n"
		<< integerValue << '\t' << doubleValue << endl;

}

void streamErrorStateTest()
{
	int integerValue;

	// display results of cin functions
	cout << "Before a bad input operation:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good()
		<< "\n\nExpects an integer, but enter a character: ";

	cin >> integerValue; // enter character value
	cout << endl;

	// display results of cin functions after bad input
	cout << "After a bad input operation:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good() << endl << endl;

	cin.clear(); // clear stream

				 // display results of cin functions after clearing cin
	cout << "After cin.clear()" << "\ncin.fail(): " << cin.fail()
		<< "\ncin.good(): " << cin.good() << endl;
}
