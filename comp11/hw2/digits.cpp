// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Benjamin Tanen
//         date: 1/23/14
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int input;
	int absolute;

	cout << "Enter a number: ";
	cin  >> input;
	absolute = abs(input);

	if (absolute > 99) {
		cout << "input has three or more digits";
	} else if (absolute > 9) {
	    cout << "input has two digits";
	} else if (absolute > 0) {
		cout << "input has one digit";
	} else if (absolute == 0) {
		cout << "input has one digit";
	}
	
	if (input < 0) {
		cout << " and input is negative" << endl;
	} else {
	    	cout << endl;
	}
	
        return 0;
}
