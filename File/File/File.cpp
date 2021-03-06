// File.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#define FILENAME  "clients.txt"
using namespace std;

void exam8_1();

void exam8_2();
void outputLine(int, const string, double); // prototype

void exam8_3();
enum RequestType { ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END };
int getRequest();
bool shouldDisplay(int, double);


int main() {
	//exam8_1(); //讀檔
	//exam8_2(); //寫檔

	exam8_3();
	system("pause");
	return 0;
}

void exam8_1() {
	/**outClientFile("filename", 開啟模式)*/
	fstream outClientFile(FILENAME, ios::out); //創建了fstream檔案輸出入串流物件，用於打開文件  
	if (!outClientFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	cout << "Enter the account, name, and balance." << endl
		<< "Enter ? to end input.\n? ";
	int account;
	string name;
	double balance;
	while (cin >> account >> name >> balance)
	{
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "account : " << account << " , name : " << name << " , balance : " << balance << " => 一筆寫入完成 " << endl;
	} // end while
	outClientFile.close();
}

void exam8_2() {
	// ifstream constructor opens the file          
	ifstream inClientFile(FILENAME, ios::in);

	// exit program if ifstream could not open file
	if (!inClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if

	int account; // customer account number
	string name; // customer name
	double balance; //amount of money customer owes company

	cout << left << setw(10) << "Account" << setw(13)
		<< "Name" << "Balance" << endl << fixed << showpoint;

	// display each record in file
	while (inClientFile >> account >> name >> balance) //由檔案串流inClientFile逐筆1次讀入3個欄位
		outputLine(account, name, balance);
}
void outputLine(int account, const string name, double balance)
{
	// display single record from file
	cout << left << setw(10) << account << setw(13) << name
		<< setw(7) << setprecision(2) << right << balance << endl;
} // end function outputLine

void exam8_3() {
	// ifstream constructor opens the file          
	ifstream inClientFile(FILENAME, ios::in);

	// exit program if ifstream could not open file
	if (!inClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if

	int request; // request type: zero, credit or debit balance
	int account; // customer account number
	string name; // customer name
	double balance; // amount of money customer owes company

					// get user's request (e.g., zero, credit or debit balance)
	request = getRequest();

	// process user's request
	while (request != END)
	{
		switch (request)
		{
		case ZERO_BALANCE:
			cout << "\nAccounts with zero balances = 0:\n";
			break;
		case CREDIT_BALANCE:
			cout << "\nAccounts with credit balances < 0:\n";
			break;
		case DEBIT_BALANCE:
			cout << "\nAccounts with debit balances > 0:\n";
			break;
		} // end switch

		  // read account, name and balance from file
		inClientFile >> account >> name >> balance;

		// display file contents (until eof)
		while (!inClientFile.eof())
		{
			// display record
			if (shouldDisplay(request, balance))
				outputLine(account, name, balance);

			// read account, name and balance from file
			inClientFile >> account >> name >> balance;
		} // end inner while

		inClientFile.clear(); // reset eof for next input          
		inClientFile.seekg(0); // reposition to beginning of file
		request = getRequest(); // get additional request from user
	} // end outer while

	cout << "End of run." << endl;
}
int getRequest()
{
	int request; // request from user

				 // display request options
	cout << "\nEnter request" << endl
		<< " 1 - List accounts with zero balances" << endl
		<< " 2 - List accounts with credit balances" << endl
		<< " 3 - List accounts with debit balances" << endl
		<< " 4 - End of run" << fixed << showpoint;

	do // input user request
	{
		cout << "\n? ";
		cin >> request;
	} while (request < ZERO_BALANCE && request > END);

	return request;
} // end function getRequest  
bool shouldDisplay(int type, double balance)
{	// determine whether to display given record
	// determine whether to display zero balances
	if (type == ZERO_BALANCE && balance == 0)
		return true;

	// determine whether to display credit balances
	if (type == CREDIT_BALANCE && balance < 0)
		return true;

	// determine whether to display debit balances
	if (type == DEBIT_BALANCE && balance > 0)
		return true;

	return false;
} // end function shouldDisplay  
