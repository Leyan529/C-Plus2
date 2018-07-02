#include <iostream>
#include <iomanip>
#include <string>
#include <boost\regex.hpp>

using namespace boost; //引用boost命名空間
using namespace std;

void regexTest1();

bool validate(const string&, const string&); // validate prototype
string inputData(const string&, const string&); // inputData prototype
void regexTest2();

void regexTest3();

#include "BoostTest\Book.h"
#include <boost\shared_ptr.hpp>
typedef boost::shared_ptr<Book> BookPtr;

void deleteBook(Book* book) {
	cout << "Custom deleter for a Book, ";
	delete book;
}
bool compareTitles(BookPtr bookPtr1, BookPtr bookPtr2) {
	return (bookPtr1->title < bookPtr2->title);
}
void sharedPtrTest();

#include "BoostTest\Author.h"
void weakPtrTest();

#include <algorithm>
void LambdaTest();
//ch23 144/151
void BoostTest() {
	
	/*regexTest1();
	regexTest2();*/
	//regexTest3();
	//sharedPtrTest();
	//weakPtrTest();
	LambdaTest();
	system("pause");
}

void regexTest1()
{
	//建立一個regex物件
	// [0-35-9] : 該模式匹配除4之外的任何數字。
	regex expression("J.*\\d[0-35-9]-\\d\\d-\\d\\d");

	string s = "Jane's Birthday is 05-12-75\n"
		"Dave's Birthday is 11-04-68\n"
		"John's Birthday is 04-28-73\n"
		"Joe's Birthday is 12-17-77";
	// smatch : 用來儲存match_results(匹配子表達式的有序集合)
	smatch match;


	// regex_search查找函數（查找第一次匹配）
	/*
	bool regex_search(const charT* str,
	match_results<const charT*, Allocator>& m,
	const basic_regex<charT, traits>& e,
	match_flag_type flags = match_default);
	*/

	while (regex_search(s, match, expression,
		match_not_dot_newline))
	{
		cout << match << endl; // print the matching string

							   //suffix() 回傳下一個sub_match，到最後一個匹配結果的结尾字串
		s = match.suffix();
	} // end while
}


bool validate(const string &data, const string &expression)
{
	// create a regex to validate the data
	regex validationExpression = regex(expression);
	return regex_match(data, validationExpression);
} // end of function validate
string inputData(const string &fieldName, const string &expression)
{
	string data; // store the data collected

				 // request the data from the user
	cout << "Enter " << fieldName << ": ";
	getline(cin, data);

	// 若validate失敗則繼續檢核
	while (!(validate(data, expression)))
	{
		cout << "Invalid " << fieldName << ".\n";
		cout << "Enter " << fieldName << ": ";
		getline(cin, data);
	} // end while

	return data;
} // end of function inputData
void regexTest2()
{
	// 大寫+多個小寫
	string lastName = inputData("last name", "[A-Z][a-zA-Z]*");

	// 大寫+多個小寫
	string firstName = inputData("first name", "[A-Z][a-zA-Z]*");

	// enter the address(#^n @^n or @^n @^n)
	string address = inputData("address",
		"[0-9]+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");

	// enter the city (@^n or @^n @^n)
	string city =
		inputData("city", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");

	// enter the state(@^n or @^n @^n)
	// @為字元
	string state = inputData("state",
		"([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");

	// enter the zip code(#####)
	// #為數字
	string zipCode = inputData("zip code", "\\d{5}");

	// enter the phone number(###-###-####)
	string phoneNumber = inputData("phone number",
		"[1-9]\\d{2}-[1-9]\\d{2}-\\d{4}");

	// display the validated data
	cout << "\nValidated Data\n\n"
		<< "Last name: " << lastName << endl
		<< "First name: " << firstName << endl
		<< "Address: " << address << endl
		<< "City: " << city << endl
		<< "State: " << state << endl
		<< "Zip code: " << zipCode << endl
		<< "Phone number: " << phoneNumber << endl;
}

void regexTest3()
{
	// create the test strings
	string testString1 = "This sentence ends in 5 stars *****";
	string testString2 = "1, 2, 3, 4, 5, 6, 7, 8";
	string output;

	cout << "Original string: " << testString1 << endl;

	// replace every * with a ^
	testString1 =
		regex_replace(testString1, regex("\\*"), "^");
	cout << "^ 替換為 *: " << testString1 << endl;

	// replace "stars" with "carets"
	testString1 = regex_replace(
		testString1, regex("stars"), "carets");
	cout << "\"carets\" 替換為 \"stars\": "
		<< testString1 << endl;

	// replace every word with "word"
	testString1 = regex_replace(
		testString1, regex("\\w+"), "word");
	cout << "替換所有包括數字、字母、底線的 \"字母\": " << testString1 << endl;

	// replace the first three digits with "digit"
	cout << "\nOriginal string: " << testString2 << endl;
	string testString2Copy = testString2;

	//format_first_only : 限定只取代第一個符合regex的flag
	for (int i = 0; i < 3; i++) // loop three times
	{
		testString2Copy = regex_replace(testString2Copy,
			regex("\\d"), "digit", format_first_only);
	} // end for

	cout << "取代前3個數字 by \"digit\": "
		<< testString2Copy << endl;

	// split the string at the commas
	cout << "string split at commas [";

	// sregex_token_iterator : 使用正則表達式切割成多個子序列
	sregex_token_iterator tokenIterator(testString2.begin(),
		testString2.end(), regex(",\\s"), -1); // token iterator
	sregex_token_iterator end; // empty iterator

	while (tokenIterator != end) // tokenIterator isn't empty
	{
		output += "\"" + *tokenIterator + "\", "; // add the token to output
		tokenIterator++; // advance the iterator
	} // end while

	  // 將尾巴後面的 ", " 從 output string刪除
	cout << output.substr(0, output.length() - 2) << "]" << endl;
}

void sharedPtrTest()
{
	// 建立第一個 shared_ptr 為bookPtr
	BookPtr bookPtr(new Book("C++ How to Program"));
	cout << "Reference count for Book " << bookPtr->title << " is: "
		<< bookPtr.use_count() << endl;

	// 使用bookPtr 再建立一個bookPtr2
	BookPtr bookPtr2(bookPtr);
	cout << "Reference count for Book " << bookPtr->title << " is: "
		<< bookPtr.use_count() << endl;

	// 改變shared_ptr的指標內容(兩邊內容一起被改變)
	bookPtr2->title = "Java How to Program";
	cout << "\nThe Book's title changed for both pointers: "
		<< "\nbookPtr: " << bookPtr->title
		<< "\nbookPtr2: " << bookPtr2->title << endl;

	// create a std::vector of shared_ptrs to Books (BookPtrs)
	vector< BookPtr > books;
	books.push_back(BookPtr(new Book("C How to Program")));
	books.push_back(BookPtr(new Book("VB How to Program")));
	books.push_back(BookPtr(new Book("C# How to Program")));
	books.push_back(BookPtr(new Book("C++ How to Program")));

	// print the Books in the vector
	cout << "\nBooks before sorting: " << endl;
	for (int i = 0; i < books.size(); i++)
		cout << (books[i])->title << "\n";

	// sort the vector by Book title and print the sorted vector
	sort(books.begin(), books.end(), compareTitles);
	cout << "\nBooks after sorting: " << endl;
	for (int i = 0; i < books.size(); i++)
		cout << (books[i])->title << "\n";

	// 建立帶有自定義刪除函數的shared_ptr建構式
	// 相當於直接呼叫解構子依序刪除所有元素
	cout << "\n使用自定義刪除函數deleter刪除shared_ptr 內容." << endl;
	BookPtr bookPtr3(new Book("我是deleter"), deleteBook);
	
	// reset : 釋放shared_ptr目前資源，並將shared_ptr設為null
	bookPtr3.reset(); 
	cout << bookPtr3.use_count() << endl;
					  // shared_ptrs are going out of scope
	cout << "\n所有的shared_ptr物件在以下段落被釋放." << endl;
}

void weakPtrTest()
{
	// create a Book and an Author
	boost::shared_ptr< Book > bookPtr(new Book("C++ How to Program"));
	boost::shared_ptr< Author > authorPtr(
		new Author("Deitel & Deitel"));

	// reference the Book and Author to each other
	bookPtr->weakAuthorPtr = authorPtr;
	authorPtr->weakBookPtr = bookPtr;

	// set the shared_ptr data members to create the memory leak
	bookPtr->sharedAuthorPtr = authorPtr;
	authorPtr->sharedBookPtr = bookPtr;

	// reference count for bookPtr and authorPtr is one
	cout << "Reference count for Book " << bookPtr->title << " is "
		<< bookPtr.use_count() << endl;
	cout << "Reference count for Author " << authorPtr->name << " is "
		<< authorPtr.use_count() << "\n" << endl;

	// access the cross references to print the data they point to
	cout << "透過weak_ptrs 存取Author's name和Book's title "
		<< "" << endl;
	//因透過lock回傳一個新的shared_ptr參考,故use_count + 1 = 3
	//脫離完函數區塊回復原use_count = 2
	bookPtr->printAuthorName();
	authorPtr->printBookTitle();
	
	// reference count for each shared_ptr is back to one
	cout << "Reference count for Book " << bookPtr->title << " is "
		<< bookPtr.use_count() << endl;
	cout << "Reference count for Author " << authorPtr->name << " is "
		<< authorPtr.use_count() << "\n" << endl;

	// the shared_ptrs go out of scope, the Book and Author are destroyed
	cout << "The shared_ptrs are going out of scope." << endl;
}

void LambdaTest()
{
	const int size = 4; // size of array values
	int array[size] = { 1, 2, 3, 4 }; // initialize values

	// Lambda將function object 以inline的方式定義在參數列中
	// Lambda表示式 : [](int i) {cout << i * 2 << endl; }
	for_each(array, array + size,
		[](int i) {cout << i * 2 << endl; }
	);

	// Lambda表示式 : [&sum](int i) {sum += i; }
	int sum = 0;
	for_each(array, array + size,
		[&sum](int i) {sum += i; }
	);
	cout << "Sum is " << sum << endl;
}
