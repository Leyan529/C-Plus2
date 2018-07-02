#include <iostream>
#include <iomanip>
#include <vector>
#include "PolymoTest/Employee2.h"
#include "PolymoTest/BasePlusCommissionEmployee.h"
#include "PolymoTest/CommissionEmployee.h"
#include "PolymoTest/SalariedEmployee.h"
#include "PolymoTest/HourlyEmployee.h"


using namespace std;
void BaseDeriveTest1();
void BaseDeriveTest2();
void BaseDeriveTest3();
void DownCastTest1();


void AbstractTest1();
void virtualViaPointer(const Employee2 * const); // prototype
void virtualViaReference(const Employee2 &); // prototype

void AbstractTest2();

int PolymoTest() {

	//BaseDeriveTest1();
	//BaseDeriveTest2();
	//BaseDeriveT
	//DownCastTest1();
	//AbstractTest1();
	AbstractTest2();
	system("pause");
	return 0;
}

void BaseDeriveTest1()
{
	// create base-class object
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "222-22-2222", 10000, .06);

	// create base-class pointer
	CommissionEmployee *commissionEmployeePtr = 0;

	// create derived-class object
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	// create derived-class pointer
	BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// output objects commissionEmployee and basePlusCommissionEmployee
	cout << "�����Oprint:\n\n";
	commissionEmployee.print(); // invokes base-class print
	cout << "\n\n�l���Oprint\n\n";
	basePlusCommissionEmployee.print(); // invokes derived-class print

										// ���o�����O����
	commissionEmployeePtr = &commissionEmployee; // perfectly natural
	cout << "\n\n\n���o�����O����"
		<< "\n�I�s�����O print function:\n\n";
	commissionEmployeePtr->print(); // invokes base-class print

									// ���o�l���O����
	basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // natural
	cout << "\n\n\n���o�l���O����"
		<< "\n�I�s�l���O print function:\n\n";
	basePlusCommissionEmployeePtr->print(); // invokes derived-class print

											// aim base-class pointer at derived-class object and print
	commissionEmployeePtr = &basePlusCommissionEmployee;
	cout << "\n\n\n�H�����O���Ъ����ץh�ݫݤl���O����"
		<< "�I�s �����O print function:\n\n";
	commissionEmployeePtr->print(); // invokes base-class print
	cout << endl;
}

void BaseDeriveTest2()
{
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "222-22-2222", 10000, .06);
	BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

	//basePlusCommissionEmployeePtr = &commissionEmployee; //compile error
}

void BaseDeriveTest3()
{
	CommissionEmployee *commissionEmployeePtr = 0; // base class
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "333-33-3333", 5000, .04, 300); // derived class

														// aim base-class pointer at derived-class object
	commissionEmployeePtr = &basePlusCommissionEmployee;

	// invoke base-class member functions on derived-class
	// object through base-class pointer (allowed)
	string firstName = commissionEmployeePtr->getFirstName();
	string lastName = commissionEmployeePtr->getLastName();
	string ssn = commissionEmployeePtr->getSocialSecurityNumber();
	double grossSales = commissionEmployeePtr->getGrossSales();
	double commissionRate = commissionEmployeePtr->getCommissionRate();

	//double baseSalary = commissionEmployeePtr->getBaseSalary(); //compile error �����O�L�Ӧ����禡
	//commissionEmployeePtr->setBaseSalary(500); //compile error �����O�L�Ӧ����禡
}

void DownCastTest1()
{
	// create base-class object
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "222-22-2222", 10000, .06);

	// create base-class pointer
	CommissionEmployee *commissionEmployeePtr = 0;

	// create derived-class object
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	// create derived-class pointer
	BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// output objects commissionEmployee and basePlusCommissionEmployee
	cout << "�����Oprint:\n\n";
	commissionEmployee.print(); // invokes base-class print
	cout << "\n\n�l���Oprint\n\n";
	basePlusCommissionEmployee.print(); // invokes derived-class print

										// ���o�����O����
	commissionEmployeePtr = &commissionEmployee; // perfectly natural
	cout << "\n\n\n���o�����O����"
		<< "\n�I�s�����O print function:\n\n";
	commissionEmployeePtr->print(); // invokes base-class print

									// ���o�l���O����
	basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // natural
	cout << "\n\n\n���o�l���O����"
		<< "\n�I�s�l���O print function:\n\n";
	basePlusCommissionEmployeePtr->print(); // invokes derived-class print

											// aim base-class pointer at derived-class object and print
	commissionEmployeePtr = &basePlusCommissionEmployee;
	cout << "\n\n\n�����禡�ƫ�A�H���󥻨����O�����ץh�I�s�Ӥ�k"
		<< "�I�s �����O print function:\n\n";
	//�h�T�{�O�n���檫�󥻨������O�A�p�G�O�l�����O���ܡB�O�_�����s��@�o�ӵ����禡
	commissionEmployeePtr->print(); // invokes base-class print
	cout << endl;
}

void AbstractTest1()
{
	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// create derived-class objects
	SalariedEmployee salariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	HourlyEmployee hourlyEmployee(
		"Karen", "Price", "222-22-2222", 16.75, 40);
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);

	cout << "Employees processed individually using static binding:\n\n";

	// output each Employee information and earnings using static binding
	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	hourlyEmployee.print();
	cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings()
		<< "\n\n";

	// create vector of four base-class pointers
	vector < Employee2 * > employees(4);

	// initialize vector with Employees
	employees[0] = &salariedEmployee;
	employees[1] = &hourlyEmployee;
	employees[2] = &commissionEmployee;
	employees[3] = &basePlusCommissionEmployee;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	// call virtualViaPointer to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (size_t i = 0; i < employees.size(); i++)		
		virtualViaPointer(employees[i]); //�ǧ}�Ϋ��б�

	// call virtualViaReference to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class references:\n\n";

	for (size_t i = 0; i < employees.size(); i++)
		virtualViaReference(*employees[i]); //�ǫ��ХΰѦұ�
}

void virtualViaPointer(const Employee2 * const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
} // end function virtualViaPointer

  // call Employee virtual functions print and earnings off a 
  // base-class reference using dynamic binding
void virtualViaReference(const Employee2 &baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
} // end function virtualViaReference

void AbstractTest2()
{
	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// create vector of four base-class pointers
	vector < Employee2 * > employees(4);

	// initialize vector with various kinds of Employees
	employees[0] = new SalariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	employees[1] = new HourlyEmployee(
		"Karen", "Price", "222-22-2222", 16.75, 40);
	employees[2] = new CommissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06);
	employees[3] = new BasePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);

	// polymorphically process each element in vector employees
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i]->print(); // output employee information
		cout << endl;

		// downcast pointer
		BasePlusCommissionEmployee *derivedPtr =
			dynamic_cast < BasePlusCommissionEmployee * >
			(employees[i]);
		//derivedPtr�u�����i�૬��BasePlusCommissionEmployee������

		// determine whether element points to base-salaried 
		// commission employee
		if (derivedPtr != 0) // 0 if not a BasePlusCommissionEmployee
		{ 
			double oldBaseSalary = derivedPtr->getBaseSalary();
			cout <<i<< " , old base salary: $" << oldBaseSalary << endl;
			derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
			cout << i << " , new base salary with 10% increase is: $"
				<< derivedPtr->getBaseSalary() << endl;
		} // end if

		cout << "earned $" << employees[i]->earnings() << "\n\n";
	} // end for   

	  // release objects pointed to by vector�s elements
	for (size_t j = 0; j < employees.size(); j++)
	{
		// output class name
		cout << "deleting object of "
			<< typeid(*employees[j]).name() << endl;

		delete employees[j];
	} // end for
}
