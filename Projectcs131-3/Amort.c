#include "Amort.h"
#include <stdio.h>
#include <stdlib.h>
#define ONE 1
#define ZERO 0
#define TRUE 1
#define FALSE 0
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

double readApr() {
	double interestRate = 0.0;
	printf("\nEnter the interest rate (APR) you will be paying"
		"(nearest 1/8 points, >=0): ");
	int condition = FALSE;
	do
	{
		safeReadDouble(&interestRate, "Please enter a non-negative number");
		if (interestRate <= 0)
		{
			printf("please enter a positive value for Annual Payment Rate: ");
			condition = TRUE;
		}
		else {
			printf("Interest: %.3lf%c\n", interestRate, '%');
		}
	} while (condition == TRUE);
	return interestRate;
}

double readPrincipal() {
	double totalLoan = 0.0;
	printf("Enter the amount of money to be borrowed (amount > 0): $");
	int condition = FALSE;
	do
	{
		safeReadDouble(&totalLoan, "Please enter a non-negative number");
		if (totalLoan <= 0)
		{
			printf("The amount of Loan needs to be bigger than 0");
			condition = TRUE;
		}
		else {
			printf("Principal: $%.2lf\n", totalLoan);
		}
	} while (condition == TRUE);
	return totalLoan;
}

int readMonth() {
	int numMonth = 0;
	int condition = FALSE;
	printf("Enter the number of months you will be making"
		"payments (0 < months <= 360): ");
	safeReadInt(&numMonth, "Please enter a non - negative"
		"number from 0 to 360:");
	do
	{
		if (numMonth <= 0 || numMonth > 360)
		{
			puts("You have to input positive game for number of months");
			condition = TRUE;
		}
		else {
			printf("Number of Months to pay: %d\n", numMonth);
		}
	} while (condition == TRUE);
	return numMonth;
}

double readPayment() {
	double payment = 0.0;
	int condition = FALSE;
	printf("Enter the amount of the monthly payment (amount > 0): $");
	safeReadDouble(&payment, "Please enter a non-negative number");
	do
	{
		if (payment <= 0)
		{
			puts("Please enter number bigger than 0 for your monthly payment");
			condition = TRUE;
		}
		else {
			printf("Payment: $%.2lf per month", payment);
		}
	} while (condition == TRUE);
	return payment;
}

void safeReadDouble(double * number_ptr, const char * prompt)
{
	while ((scanf("%lf", number_ptr)) != ONE)
	{
		puts(prompt);
		cleanBuffer();
	}
	cleanBuffer();
}
void safeReadInt(int * number_ptr, const char * prompt)
{
	while ((scanf("%d", number_ptr)) != ONE)
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
void printMenu() {
	printf("Amortization!\n");
	printf("Amortization Program written by Son Tran. ");
	printf("Please select a Menu Option\n\n");
	printf("\t1. Calculate (P)ayment Size\n");
	printf("\t2. Calculate (L)oan Size\n");
	printf("\t3. Calculate (N)umber of Payments\n");
	printf("\t4. Calculate (I)nterest (APR)\n");
	printf("\t5. (Q)uit\n\n");
	printf("Enter a menu option: ");
}