#include <iostream>
#include <iomanip>
#include "PolymoTest/CommissionEmployee.h"
#include "PolymoTest/BasePlusCommissionEmployee.h"
void CETest();
void BasePlusCETest();
void destructorTest();
int InherTest() {
	//CETest();
	//BasePlusCETest();
	destructorTest();
	system("pause");
	return 0;
}

void CETest()
{
	CommissionEmployee employee(
		"Sue", "Jones", "222-22-2222", 10000, .06);

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// get commission employee data
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate() << endl;

	employee.setGrossSales(8000); // set gross sales
	employee.setCommissionRate(.1); // set commission rate

	cout << "\nUpdated employee information output by print function: \n"
		<< endl;
	employee.print(); // display the new employee information

					  // display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
}

void BasePlusCETest()
{
	BasePlusCommissionEmployee
		employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// get commission employee data
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000); // set base salary

	cout << "\nUpdated employee information output by print function: \n"
		<< endl;
	employee.print(); // display the new employee information

					  // display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
}

void destructorTest()
{
	cout << fixed << setprecision(2);

	{ // begin new scope
		CommissionEmployee employee1(
			"Bob", "Lewis", "333-33-3333", 5000, .04);
	} // end scope 

	cout << endl;
	BasePlusCommissionEmployee
		employee2("Lisa", "Jones", "555-55-5555", 2000, .06, 800);

	cout << endl;
	BasePlusCommissionEmployee
		employee3("Mark", "Sands", "888-88-8888", 8000, .15, 2000);
	cout << endl;
	//根據stack規則後來建構的會先被解構
}
