/*************************************************************
* Mean Time to Failure (MTTF) Calculator
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
**************************************************************/

#include <iostream>
#include "Calculate.h"

int main()
{
	std::cout << "Mean Time to Failure (MTTF) Calculator\n" << std::endl;

	float failureRate;
	std::cout << "\nTime until server failure (years): ";
	std::cin >> failureRate;

	float totalServers;
	std::cout << "\nTotal servers in datacenter: ";
	std::cin >> totalServers;

	float mttfValue = calculate(failureRate, totalServers);

	std::cout << "\nMTTF: " << mttfValue << " hours";

	std::cin.ignore();
	std::cin.get();
		
	return 0;
}
