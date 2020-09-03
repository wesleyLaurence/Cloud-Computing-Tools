/***********************************************************
* Mean Time to Failure (MTTF) Calculator
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
************************************************************/

#pragma once

float calculate(float failureRate, float totalServers)
{
	/*
	failureRate: Total years until server failure
	totalServers: Total servers in datacenter

	RETURNS: MTTF (in hours)
	*/

	int monthsUntilFailure = 12 * failureRate;
	int hoursInMonth = 24 * 30;

	float mttf_value = (monthsUntilFailure * hoursInMonth) / totalServers;

	return mttf_value;
}