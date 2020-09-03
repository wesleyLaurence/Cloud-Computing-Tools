/*************************************************************
* Finger Table Calculator
*
* File Name: FingerTable.cpp
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
**************************************************************/

#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int finger(int n, int i, int m)
{
	int finger_value = int(n + pow(2, i)) % int(pow(2, m));

	return finger_value;
}

std::vector<int> createTable(int n, int m, std::string allNodes)
{
	// Parse variables
	std::string delimiter = ",";
	std::string token;
	size_t pos = 0;

	// Parse allNodes string, convert each value to int, then push each value to vector
	std::vector<int> nodesVec;
	while ((pos = allNodes.find(delimiter)) != std::string::npos) {
		token = allNodes.substr(0, pos);
		nodesVec.push_back(std::stoi(token));
		allNodes.erase(0, pos + delimiter.length());
	}

	// push final value
	nodesVec.push_back(std::stoi(allNodes));

	// sort vector
	std::sort(nodesVec.begin(), nodesVec.end());

	std::vector<int> nearbyNodes;
	// calculate nearby nodes
	for (int i = 0; i < m; i++)
	{
		int val = finger(n, i, m);
		nearbyNodes.push_back(val);
	}

	int ft;
	std::vector<int> ftValues;
	for (int n : nearbyNodes)
	{
		if (n > nodesVec.back())
			ft = nodesVec[0];
		else
		{
			for (int i = 0; i < nodesVec.size() - 1; i++)
			{
				if (n > nodesVec[i])
					ft = nodesVec[i + 1];
			}
		}
		ftValues.push_back(ft);
	}

	return ftValues;
}