#include "Amort.h"
#include <stdio.h>
#include <stdlib.h>
#define ONE 1
#define ZERO 0
#define TRUE 1
#define FALSE 0
#define EIGHT 8
#define HUNDRED 100
#define HALF 0.5
#define VERYSMALL 0.001
#define MANYTIMES 20
#define YEARLY_INTEREST_RATE 1200
#pragma once
double getPaymentAmount(int months, double principal, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	if (monthlyRate == ZERO)
	{
		return roundToNextCent(principal / months);
	}
	else
	{
		numerator = pow((ONE + monthlyRate), months) * principal * monthlyRate;
		denominator = pow((ONE + monthlyRate), months) - ONE;
		return roundToNextCent(numerator / denominator);
	}
}

double getLoanAmount(int months, double totalPayment, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	if (monthlyRate == ZERO)
	{
		return roundToNearestCent(totalPayment * months);
	}
	else
	{
		numerator = (pow((ONE + monthlyRate), months) - ONE) * totalPayment;
		denominator = pow((ONE + monthlyRate), months) * monthlyRate;
		return roundToNearestCent(numerator / denominator);
	}
}

int getNumberOfMonths(double principal, double totalPayment, double monthlyRate)
{
	double numerator = 0.0;
	double denominator = 0.0;
	if (monthlyRate == ZERO)
	{
		return (int)ceil(principal / totalPayment);
	}
	else
	{
		numerator = log(totalPayment) - log(totalPayment - (principal*monthlyRate));
		denominator = log(1 + monthlyRate);
		return (int)ceil(numerator / denominator);
	}
}

double iterativeFormula(double sizeOfLoan, double monthlyPayment,
	double rate, double months)
{
	double answer = (monthlyPayment / sizeOfLoan) - ((rate * pow(1 + rate, months))
		/ (pow(1 + rate, months) - 1));
	return answer;
}

double getAppDer(double secondary, double primary, double distance)
{
	double answer = 0;
	answer = (secondary - primary) / distance;
	return answer;
}

double getInterestRate(double sizeOfLoan, double monthlyPayment, int months)
{
	double rateGuess = 0.0;
	int counter = 0;
	if (monthlyPayment * months <= sizeOfLoan)
	{
		return 0;
	}
	rateGuess = ((monthlyPayment * months) - sizeOfLoan) / (sizeOfLoan);
	int keepGoing = TRUE;
	while (keepGoing == TRUE)
	{
		rateGuess = rateGuess - (iterativeFormula(sizeOfLoan, monthlyPayment,
			rateGuess, months) / (getAppDer(iterativeFormula(sizeOfLoan,
				monthlyPayment, rateGuess + VERYSMALL, months), iterativeFormula
				(sizeOfLoan, monthlyPayment, rateGuess, months), VERYSMALL)));
		counter++;
		if (counter == MANYTIMES)
		{
			keepGoing = FALSE;
		}
	}
	rateGuess = rateGuess * YEARLY_INTEREST_RATE;
	return roundToOneEighth(rateGuess);
}	

double readApr() {
	double interestRate = 0.0;
	printf("\nEnter the interest rate (APR) you will be paying"
		"(nearest 1/8 points, >=0): ");
	int condition = FALSE;
	do
	{
		safeReadDouble(&interestRate, "Please enter a non-negative number");
		if (interestRate < 0)
		{
			printf("please enter a positive value for Annual Payment Rate: ");
			condition = TRUE;
		}
		else {
			interestRate = roundToOneEighth(interestRate);
			printf("Interest: %.3lf%c", interestRate, '%');
			condition = FALSE;
		}
	} while (condition == TRUE);
	return interestRate;
}

double readPrincipal() {
	double loan = 0.0;
	printf("\nEnter the amount of money to be borrowed (amount > 0): $");
	int condition = FALSE;
	do
	{
		safeReadDouble(&loan, "\nPlease enter a non-negative number");
		if (loan <= 0)
		{
			printf("\nThe amount of Loan needs to be bigger than 0");
			condition = TRUE;
		}
		else {
			printf("Principal: $%.2lf", loan);
			condition = FALSE;
		}
	} while (condition == TRUE);
	return roundToNearestCent(loan);
}

int readMonth() {
	int numMonth = 0;
	int condition = FALSE;
	printf("\nEnter the number of months you will be making "
		"payments (0 < months <= 360): ");
	do
	{
		safeReadInt(&numMonth, "\nPlease enter a non - negative"
			"number from 0 to 360:");
		if (numMonth <= 0 || numMonth > 360)
		{
			puts("\nYou have to input positive number for number of months");
			condition = TRUE;
		}
		else {
			printf("Number of Months to pay: %d", numMonth);
			condition = FALSE;
		}
	} while (condition == TRUE);
	return numMonth;
}

double readPayment() {
	double payment = 0.0;
	int condition = FALSE;
	printf("\nEnter the amount of the monthly payment (amount > 0): $");
	do
	{
		safeReadDouble(&payment, "\nPlease enter a non-negative number");
		if (payment <= 0)
		{
			puts("\nPlease enter number bigger than 0 for your monthly payment");
			condition = TRUE;
		}
		else {
			printf("Payment: $%.2lf per month", payment);
			condition = FALSE;
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

double roundToNextCent(double number) {
	return ceil(number * HUNDRED) / HUNDRED;
}

double roundToOneEighth(double number) {
	double out = 0.0;
	double roundUp = 0.0;
	double roundDown = 0.0;
	roundUp = ceil(number * EIGHT) / EIGHT;
	roundDown = floor(number * EIGHT) / EIGHT;
	if (fabs(roundUp - number) <= fabs(roundDown - number))
		return roundUp;
	else
		return roundDown;
}

double roundToNearestCent(double number) {
	return floor(number * HUNDRED + HALF) / HUNDRED;
}

void printTable(double principal, double payment, double monthlyRate, int month) {
	char ch = ' ';
	char filename[FILENAME_MAX] = "AmTable.txt";
	int returnValue = EXIT_SUCCESS;
	double interestPaid = 0.0;
	double principalPaid = 0.0;
	double loanBalance = 0.0;
	double tabPayment = 0.0;
	int countMonth = 1;
	FILE * outFileHandle = NULL;
	int i = 0;
	printf("\nDo you wish to print an Amortization Table(Y/N)? Y\b");
	ch = getche();
	if (ch == 'N' || ch == 'n')
	{
		return;
	}
	else {
		outFileHandle = fopen(filename, "w");
		loanBalance = principal;
		if (outFileHandle == NULL)
		{
			printf("Could not open file %s for output.\n"
				"Press any key to Continue", filename);
			returnValue = EXIT_FAILURE;
		}
		else {
			fprintf(outFileHandle, "Amortization Table for $%.2lf Loan "
				"at %.3lf%% interest for %d months\n", principal,
				monthlyRate * 1200, month);
			fprintf(outFileHandle, "\n");
			fprintf(outFileHandle, "%s %22s %15s %15s\n",
				"Payments", "Principal Paid", "Interest Paid",
				"Loan Balance");
			if (monthlyRate == 0)
			{
				tabPayment = payment;
				interestPaid = 0;
				principalPaid = payment;
				for (i = 0; i < month; i++)
				{
					if (i < month -1)
					{
						loanBalance -= principalPaid;
					}
					else
					{
						principalPaid = loanBalance;
						tabPayment = loanBalance;
						loanBalance = 0;
					}
					fprintf(outFileHandle, "%-5d ( %8.2lf) ",
						countMonth, tabPayment);
					fprintf(outFileHandle, "$ %13.2lf ",
						principalPaid);
					fprintf(outFileHandle, "$ %13.2lf ",
						interestPaid);
					fprintf(outFileHandle, "$ %12.2lf \n",
						loanBalance);
					countMonth++;
				}
			}
			else
			{
				for (i = month; i > ZERO; i--)
				{
					if (i > ONE)
					{
						tabPayment = getPaymentAmount(i, loanBalance, monthlyRate);
						interestPaid = loanBalance * monthlyRate;
						principalPaid = tabPayment - interestPaid;
						loanBalance -= principalPaid;
					}
					else 
					{
						interestPaid = loanBalance * monthlyRate;
						principalPaid = loanBalance;
						tabPayment = roundToNextCent(principalPaid + interestPaid);
						loanBalance = 0;
					}
						
					fprintf(outFileHandle, "%-5d ( %8.2lf) ",
							countMonth, tabPayment);
					fprintf(outFileHandle, "$ %13.2lf ",
							principalPaid);
					fprintf(outFileHandle, "$ %13.2lf ",
							interestPaid);
					fprintf(outFileHandle, "$ %12.2lf \n",
							loanBalance);
					countMonth++;
				}
			}
		}
		fclose(outFileHandle);
		system("AmTable.txt");
	}
}
