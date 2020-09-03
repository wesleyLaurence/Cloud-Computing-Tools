/**********************************************************************
* Power Usage Effectiveness (PUE) Calculator
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
***********************************************************************/

#include <iostream>
#include "Calculate.h"

int main()
{
	std::cout << "Power Usage Effectiveness (PUE) Calculator\n" << std::endl;
	
	float totalPower;
	std::cout << "\nTotal Power (kWh): ";
	std::cin >> totalPower;

	float itPower;
	std::cout << "\nTotal IT Power (kWh): ";
	std::cin >> itPower;

	float pue = calculate(totalPower, itPower);

	std::cout << "\nPUE: " << pue << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}
