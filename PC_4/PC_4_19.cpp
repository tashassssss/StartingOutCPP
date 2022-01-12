/*
Parking Lot
A parking lot charges the following rates for parking
__________________________________________________________________________________________
 Number of hour				                    Rate per hour
__________________________________________________________________________________________ 
<2                                                              $2
over 2 but no more than 4                                       $1.75
>5                                                              $1.50
__________________________________________________________________________________________

write a program that asks for the starting and ending times of a parked car and displays the amount to be paid.
The program should ask for the times to be entered as floating-point numbers in the form HM.MM.For example,07:00 hours will be entered as 07.00,and 16:28 hours will be entered as 16.28.
Note that each initiated hour must be paid in full.For example,1 hour and 3 mintes will cost $4.

Input validation:The program should not accept times that are greater than 21:59 or less than 07:00,the operating hours of the parking lot.
Also,no number whose last two digits are greater than 59 should be accepted.
Hint:You can get the minutes of the time by multiplying the time by 100 and then taking the remainder of the division by 100
	
	num - static_cast<int>(num)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float StartTime, Length, Mins, Hrs, Charges, StartMins, LengthInMins;


	// Ask user for the starting time and the number of minutes of the call.
	cout << "This program calculates your long-distance telephone charges.\n";
	cout << "Enter the starting time of the call as a floating-point number\n"
		 << "in the form HH.MM: ";
	cin  >> StartTime;
	cout << "Enter the number of minutes of the call in the form HH.MM: ";
	cin  >> Length;

	Hrs = static_cast<int>(Length);
	Mins = Length - static_cast<int>(Length);
	LengthInMins = (Hrs * 60) + (Mins * 100);
	StartMins = StartTime - static_cast<int>(StartTime);

	if (Mins <= .59 && StartMins <= .59)
	{
		cout << fixed << showpoint << setprecision(2);
		if (StartTime >= 00.00 && StartTime <= 06.59)
		{
			Charges = LengthInMins * 0.12;
			cout << "Cost of call: $" << Charges << endl;
		}
		else if (StartTime <= 19.00)
		{
			Charges = LengthInMins * 0.55;
			cout << "Cost of call: $" << Charges << endl;
		}
		else if (StartTime <= 23.59)
		{
			Charges = LengthInMins * 0.35;
			cout << "Cost of call: $" << Charges << endl;
		}
		else
			cout << "Error! Call times cannot be less than\n00.00 minutes"
		         << " or greater than 23.59 minutes.\n";
	}
	else
		cout << "Error! Last two digts in the numbers"
			 << " must be less than 59.\n";
	return 0;
}
