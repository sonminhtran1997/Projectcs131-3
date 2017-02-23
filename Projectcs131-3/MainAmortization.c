//----------------------------------------------------------------------------
// File: argcv.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Amort.h"
#define TRUE 1
#define FALSE 0
//----------------------------------------------------------------------------
// Function:		main(void)		
//
// Title:			
//
// Description:		
//					
//					
//					
//									
// Programmer:		Son Minh Tran
// 
// Date:			02/07/2017
// Version:			1.0
//
// Environment:		HP Elitebook 8570P 
//					Hardware: 8GB
//							  Intel(R) Core(TM) i5-3320M 
//					Software: OS: MS Windows 10 Professional 64-bit
//
// Input:			
//					
//					
//					
//					
//					
//					
// Output:			
//					
//					
//					
//					
//					
//
//	Parameters:		argc	(int) 
//					argv[]	(char* or array pointer)
//  Returns:		EXIT_SUCCESS for successful completion 
//					Or EXIT_FAILURE when the program cannot read the 
//					data file and output file
// Called By:		None
// 
// Calls:			None
//
// History Log:		Commit github on 01/24/2017: 
//					Commit github on 01/25/2017: 
//					Commit github on 02/04/2017: 
//					Commit github on 02/08/2017: 
//----------------------------------------------------------------------------
double readApr();
int main(void) {
	short again = FALSE;
	double totalPayment = 0.0;
	double principal = 0.0;
	int month = 0;
	double monthlyRate = 0.0;
	double apr = 0.0;
	printMenu();
	do
	{
		switch (getche())
		{
		case '1':
		case 'P':
		case 'p':
			apr = readApr();
			monthlyRate = apr / 1200;
			printf("Enter the amount of money to be borrowed (amount > 0): $");
			safeReadDouble(&principal, "Please enter a non-negative number");
			printf("Principal: $%.2lf\n", principal);
			printf("Enter the number of months you will be making"
				"payments (0 < months <= 360): ");
			do
			{
				safeReadInt(&month, "Please enter a non - negative" 
					"number from 0 to 360:");
				if (month > 360)
				{
					puts("Please enter a non - negative number from 0 to 360: ");
				}
			} while (month > 360);
			printf("Number of Months to pay: %d\n", month);
			totalPayment= getPaymentAmount(month, principal, monthlyRate);
			printf("Payment: $%.2lf per month", totalPayment);
			break;
		case '2':
		case 'l':
		case 'L':
			printf("\nEnter the interest rate (APR) you will be paying"
				"(nearest 1/8 points, >=0): ");
			apr = readApr();
			printf("Interest: %.3lf%c\n", apr, '%');
			printf("Enter the amount of the monthly payment (amount > 0): $");
			safeReadDouble(&totalPayment, "Please enter a non-negative number");
			printf("Monthly Payment: $%.3lf\n", totalPayment);
			printf("Enter the number of months you will be"
				"making payments (0 < months <= 360):");
			do
			{
				safeReadInt(&month, "Please enter a non - negative"
					"number from 0 to 360:");
				if (month > 360)
				{
					puts("Please enter a non - negative number from 0 to 360: ");
				}
			} while (month > 360);
			printf("Number of Months to pay: %d\n", month);
			principal = getLoanAmount(month, totalPayment, monthlyRate);
			printf("Loan Amount: $%.2lf", principal);
			break;
		case '3':
		case 'N':
		case 'n':
			printf("\nEnter the interest rate (APR) you will be paying"
				"(nearest 1/8 points, >=0): ");
			safeReadDouble(&apr, "Please enter a non-negative number");
			monthlyRate = apr / 1200;
			printf("Interest: %.3lf%c\n", apr, '%');
			printf("Enter the amount of money to be borrowed (amount > 0): $");
			safeReadDouble(&principal, "Please enter a non-negative number");
			printf("Principal: $%.2lf\n", principal);
			printf("Enter the amount of the monthly payment (amount > 0): $");
			safeReadDouble(&totalPayment, "Please enter a non-negative number");
			printf("Monthly Payment: $%.3lf\n", totalPayment);
			month = getNumberOfMonths(principal, totalPayment, monthlyRate);
			printf("Number of months to pay the loan: %d", month);
			break;
		case '4':
		case 'I':
		case 'i':
			printf("\nOK");
			break;
		case '5':
		case 'Q':
		case 'q':
			return EXIT_SUCCESS;
		default:
			system("cls");
			printMenu();
			again = TRUE;
			break;
		}
	} while (again == TRUE);
	getchar();
	return EXIT_SUCCESS;
}