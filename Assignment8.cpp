//**************************************************************//
//  
//  Program Name: Programming Lab 8
//  Author: Madeline Weber
//  Date: 10/28/2022
//  Description: This program designs a class that has data members for an employee's
//  hourly rate and hours worked. It creates an array of seven class objects and
//  reads the number of hours worked and pay rate from the "payroll.dat" file.
// 
//**************************************************************//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Payroll
{
	private:
		double employeeHours, payrate, grosspay;
	
	public:
		// Default constructor 
		Payroll()
		{
			employeeHours = 0;
			payrate = 0;
		}
		// set and get functions
		void setHour( double a )
		{
			employeeHours = a; 
		}
		void setRate( double b )
		{
			payrate = b;
		}
		double getHours()
		{
			return employeeHours;
		}
		double getPayrate()
		{
			return payrate;
		}
		double calculate_GrossPay()
		{
			grosspay = ( employeeHours * payrate );
			return grosspay;
		}
};

int main()
{
	
	// Create and initalize array objects, variables
	Payroll employeeData[7];
	double hours, rate; 
	
	//  Open and read file
	ifstream readFile;
	readFile.open("payroll.dat");
	
	if ( !readFile ) 					// validate that the file was opened 
		cout << "Error opening file.";
	else
		
		for ( int i = 0; i < 7; i++ )
		{
			readFile >> hours;
			readFile >> rate; 
			
			employeeData[i].setHour( hours );
			employeeData[i].setRate( rate );
		}
		
	readFile.close(); 					//  close file 
	
	// Display values
	cout << fixed << showpoint << setprecision(2);  // set the decimal to 2 points 
	
	for ( int x = 0; x < 7; x++ )
		cout << "Employee #" << ( x +1 ) << " gross pay: $" << employeeData[x].calculate_GrossPay() << endl;	
	
}
