#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "RandomAccessTest\ClientData.h"
using namespace std;

void ClientDataCreate(string);
void ClientDataWrite(string);

void ClientDataRead(string);
void outputLine( ostream&, const ClientData & ); // prototype

void TransactionTest(string);
int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData &);
int getAccount(const char * const);

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };
//ch17 RandomAccessTest
void RandomAccessTest() {

	//const string a = "credit.dat";
	//ClientDataCreate(a);
	//ClientDataRead(a);
	//ClientDataWrite(a); // for test

	const string f = "transaction.dat";
	//ClientDataRead(f);
	TransactionTest(f); // for test
	system("pause");
}

void ClientDataCreate(string filename)
{
	ofstream outCredit(filename, ios::out | ios::binary);

	// exit program if ofstream could not open file
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // end if

	ClientData blankClient; // constructor zeros out each data member

							// output 100 blank records to file
	for (int i = 0; i < 100; i++)
		outCredit.write(reinterpret_cast< const char * >(&blankClient),
			sizeof(ClientData));
}
void ClientDataWrite(string filename)
{
	int accountNumber;
	string lastName;
	string firstName;
	double balance;

	fstream outCredit(filename, ios::in | ios::out | ios::binary);

	// exit program if fstream cannot open file
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
		ClientDataCreate(filename);
	} // end if
	ClientDataRead(filename);
	cout << "��J�@�ӼƭȬ�1~100���b�ḹ�X\n? ";

	// require user to specify account number
	ClientData client;
	cin >> accountNumber;

	// user enters information, which is copied into file
	while (accountNumber > 0 && accountNumber <= 100)
	{
		// user enters last name, first name and balance
		cout << "�п�J lastname, firstname, balance\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;

		// set record accountNumber, lastName, firstName and balance values
		client.setAccountNumber(accountNumber);
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);

		// seek position in file of user-specified record
		outCredit.seekp((client.getAccountNumber() - 1) *
			sizeof(ClientData));

		// write user-specified information in file
		outCredit.write(reinterpret_cast< const char * >(&client),
			sizeof(ClientData));		
		// enable user to enter another account
		cout << "��J�@�ӼƭȬ�1~100���b�ḹ�X\n? ";
		cin >> accountNumber;
	} // end while
}
void ClientDataRead(string filename)
{	
	ifstream inCredit(filename, ios::in | ios::binary);

	// exit program if ifstream cannot open file
	if (!inCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // end if

	cout << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "First Name" << left
		<< setw(10) << right << "Balance" << endl;

	ClientData client; // create record

						
	inCredit.read(reinterpret_cast< char * >(&client),
		sizeof(ClientData)); // �N���c�ƪ�����Ƭ��r�����Ы��A��Ū��

	// read all records from file
	while (inCredit && !inCredit.eof())
	{
		// display record
		if (client.getAccountNumber() != 0)
			outputLine(cout, client);

		// read next from file
		inCredit.read(reinterpret_cast< char * >(&client),
			sizeof(ClientData));
	} // end while
}
void outputLine(ostream &output, const ClientData &record)
{
	output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
} // end function outputLine

void TransactionTest(string filename)
{
	fstream inOutCredit(filename, ios::in | ios::out | ios::binary);

	// exit program if fstream cannot open file
	if (!inOutCredit)
	{
		cerr << "Created new file." << endl;
		ClientDataCreate(filename);
		exit(1);
	} // end if
	ClientDataRead(filename);
	int choice; // store user choice

				// enable user to specify action
	while ((choice = enterChoice()) != END)
	{		
		switch (choice)
		{
		case PRINT: // create text file from record file
			createTextFile(inOutCredit);
			break;
		case UPDATE: // update record
			updateRecord(inOutCredit);
			break;
		case NEW: // create record
			newRecord(inOutCredit);			
			break;
		case DELETE: // delete existing record
			deleteRecord(inOutCredit);
			break;
		default: // display error if user does not select valid choice
			cerr << "Incorrect choice" << endl;
			break;
		} // end switch

		inOutCredit.clear(); // reset end-of-file indicator
		ClientDataRead(filename);

	} // end while
}

int enterChoice()
{
	// display available options
	cout << "\nEnter your choice" << endl
		<< "1 - store a formatted text file of accounts" << endl
		<< "    called \"print.txt\" for printing" << endl
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - delete an account" << endl
		<< "5 - end program\n? ";

	int menuChoice;
	cin >> menuChoice; // input menu selection from user
	return menuChoice;
} // end function enterChoice

void createTextFile(fstream &readFromFile)
{
	// create text file
	ofstream outPrintFile("print.txt", ios::out);

	// exit program if ofstream cannot create file
	if (!outPrintFile)
	{
		cerr << "File could not be created." << endl;
		exit(1);
	} // end if

	outPrintFile << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "First Name" << right
		<< setw(10) << "Balance" << endl;

	// set file-position pointer to beginning of readFromFile
	readFromFile.seekg(0);

	// read first record from record file
	ClientData client;
	readFromFile.read(reinterpret_cast< char * >(&client),
		sizeof(ClientData));

	// copy all records from record file into text file
	while (!readFromFile.eof())
	{
		// write single record to text file
		if (client.getAccountNumber() != 0) // skip empty records
			outputLine(outPrintFile, client);

		// read next record from record file
		readFromFile.read(reinterpret_cast< char * >(&client),
			sizeof(ClientData));
	} // end while
} // end function createTextFile

void updateRecord(fstream &updateFile)
{
	// obtain number of account to update
	int accountNumber = getAccount("Enter account to update");

	// move file-position pointer to correct record in file
	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

	
	ClientData client;
	updateFile.read(reinterpret_cast< char * >(&client),
		sizeof(ClientData)); // �N���c�ƪ�����Ƭ��r�����Ы��A��Ū��

	// update record
	if (client.getAccountNumber() != 0)
	{
		outputLine(cout, client); // display the record

								  // request user to specify transaction
		cout << "\n�п�J�s�ڪ��B (�H+�ƪ��) �άO��X���B  (�H-�ƪ��): ";
		double transaction; // charge or payment
		cin >> transaction;

		// update record balance
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client); // display the record

								  // move file-position pointer to correct record in file
		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

		// write updated record over old record in file
		updateFile.write(reinterpret_cast< const char * >(&client),
			sizeof(ClientData));
	} // end if
	else // display error if account does not exist
		cerr << "Account #" << accountNumber
		<< " �S��������T." << endl;
} // end function updateRecord

void newRecord(fstream &insertInFile)
{
	// obtain number of account to create
	int accountNumber = getAccount("Enter new account number");

	// move file-position pointer to correct record in file
	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

	// �N���c�ƪ�����Ƭ��r�����Ы��A��Ū��
	ClientData client;
	insertInFile.read(reinterpret_cast< char * >(&client),
		sizeof(ClientData));

	// create record, if record does not previously exist
	if (client.getAccountNumber() == 0)
	{
		string lastName;
		string firstName;
		double balance;

		// user enters last name, first name and balance
		cout << "��J lastname, firstname, balance\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;

		// use values to populate account values
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);

		// move file-position pointer to correct record in file
		insertInFile.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

		// �N���c�ƪ�����Ƭ��r�����Ы��A��s�W                      
		insertInFile.write(reinterpret_cast< const char * >(&client),
			sizeof(ClientData));
	} // end if
	else // display error if account already exists
		cerr << "Account #" << accountNumber
		<< " �w�g�s�b������T." << endl;
} // end function newRecord

void deleteRecord(fstream &deleteFromFile)
{
	// obtain number of account to delete
	int accountNumber = getAccount("��J���R����account�b��");

	// move file-position pointer to correct record in file
	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

	// read record from file
	ClientData client;
	deleteFromFile.read(reinterpret_cast< char * >(&client),
		sizeof(ClientData));

	// delete record, if record exists in file
	if (client.getAccountNumber() != 0)
	{
		ClientData blankClient; // create blank record

								// move file-position pointer to correct record in file
		deleteFromFile.seekp((accountNumber - 1) *
			sizeof(ClientData));

		// �H�@�ӪŪ�ClientData���N�쥻����Ƨ@�R��
		deleteFromFile.write(
			reinterpret_cast< const char * >(&blankClient),
			sizeof(ClientData));

		cout << "Account #" << accountNumber << " deleted.\n";
	} // end if
	else // display error if record does not exist
		cerr << "Account #" << accountNumber << " is empty.\n";
} // end deleteRecord

int getAccount(const char * const prompt)
{
	int accountNumber;

	// obtain account-number value
	do
	{
		cout << prompt << "�ƭȬ�1~100" << endl;
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);

	return accountNumber;
} // end function getAccount