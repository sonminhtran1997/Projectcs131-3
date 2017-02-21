#include "Amort.h"
#include <stdio.h>
#include <stdlib.h>
#define ONE 1
#pragma once

double getPaymentAmount(int months, double principal, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	numerator = pow((ONE + monthlyRate), months) * principal * monthlyRate;
	denominator = pow((ONE + monthlyRate), months) - ONE;
	return numerator / denominator;
}

double getLoanAmount(int months, double totalPayment, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	numerator = (pow((ONE + monthlyRate), months) - ONE) * totalPayment;
	denominator = pow((ONE + monthlyRate), months) * monthlyRate;
	return numerator / denominator;
}

int getNumberOfMonths(double principal, double totalPayment, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	numerator = log(totalPayment) - log(totalPayment - (principal*monthlyRate));
	denominator = log(1 + monthlyRate);
	return numerator / denominator;
}

void safeReadDouble(double * number_ptr, const char * prompt)
{
	while ((scanf("%lf", number_ptr)) != ONE && *number_ptr < 0)
	{
		puts(prompt);
		cleanBuffer();
	}
	cleanBuffer();
}
void safeReadInt(int * number_ptr, const char * prompt)
{
	while ((scanf("%d", number_ptr)) != ONE && *number_ptr < 0)
	{
		puts(prompt);
		cleanBuffer();
	}
	cleanBuffer();
}
void cleanBuffer()
{
	while (getchar() != '\n');
}