/*************************************************************
* Finger Table Calculator
*
* File Name: Main.cpp
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
**************************************************************/

#include <iostream>
#include <string>
#include "FingerTable.h"


int main() {

	std::cout << "Finger Table Calculator\n" << std::endl;

	// Get n value
	int n;
	std::cout << "\nEnter node ID: ";
	std::cin >> n;

	// Get m value
	int m;
	std::cout << "\nEnter m value: ";
	std::cin >> m;

	// Get all node values
	std::string allNodes;
	std::cout << "\nEnter all node IDs in ring: ";
	std::cin >> allNodes;

	// display title and create array display
	std::cout << "\n\n\n" << "N" << n << " Finger Table\n" << std::endl;
	std::cout << "i" << " | " << "ft[i]" << std::endl;
	std::cout << "----------" << std::endl;

	// create finger table
	std::vector<int> fingerTable = createTable(n, m, allNodes);
	
	// display finger table output to user
	int i = 0;
	for (int n : fingerTable)
	{
		std::cout << i << " | " << n << std::endl;
		i++;
	}

	// pause program until user exits
	std::cin.ignore();
	std::cin.get();
}

