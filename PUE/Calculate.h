/********************************************************************
* Power Usage Effectiveness (PUE) Calculator
*
* Author: Wesley Laurence
*
* Date: 09/03/2020
*
*********************************************************************/

#pragma once

float calculate(float totalPower, float itPower)
{
	return totalPower / itPower;
}
