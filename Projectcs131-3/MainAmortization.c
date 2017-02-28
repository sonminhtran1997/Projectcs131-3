//----------------------------------------------------------------------------
// File: argcv.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Amort.h"
#include "MainAmortization.h"
#define TRUE 1
#define FALSE 0
#define MONTHPERCENT 1200
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
int main(void) {
	short again = TRUE;
	double totalPayment = 0.0;
	double principal = 0.0;
	int month = 0;
	double monthlyRate = 0.0;
	double apr = 0.0;
	int initialGuessMonth = 0;
	
	do
	{
		system("cls");
		printMenu();
		switch (getche())
		{
		case '1':
		case 'P':
		case 'p':
			apr = readApr();
			monthlyRate = apr / MONTHPERCENT;
			principal = readPrincipal();
			month = readMonth();
			totalPayment= getPaymentAmount(month, principal, monthlyRate);
			printf("\nPayment: $%.2lf per month", totalPayment);
			printTable(principal, totalPayment, monthlyRate, month);
			break;
		case '2':
		case 'l':
		case 'L':
			apr = readApr();
			monthlyRate = apr / MONTHPERCENT;
			totalPayment = readPayment();
			month = readMonth();
			principal = getLoanAmount(month, totalPayment, monthlyRate);
			printf("\nLoan Amount: $%.2lf", principal);
			printTable(principal, totalPayment, monthlyRate, month);
			break;
		case '3':
		case 'N':
		case 'n':
			apr = readApr();
			monthlyRate = apr / MONTHPERCENT;
			principal = readPrincipal();
			totalPayment = readPayment();
			month = getNumberOfMonths(principal, totalPayment, monthlyRate);
			printf("\nNumber of months to pay the loan: %d", month);
			printTable(principal, totalPayment, monthlyRate, month);
			break;
		case '4':
		case 'I':
		case 'i':
			principal = readPrincipal();
			totalPayment = readPayment();
			initialGuessMonth = ceil(principal / totalPayment);
			printf("\nNumber of months must be at least %d", initialGuessMonth);
			do
			{
				month = readMonth();
				if (month < initialGuessMonth)
				{
					printf("\nThe month you entered must be at least %d", initialGuessMonth);
				}
			} while (month < initialGuessMonth);
			apr = getInterestRate(principal, totalPayment, month);
			monthlyRate = apr / MONTHPERCENT;
			printf("\nAnnual Percentage Rate: %.3lf%c", apr, '%');
			printTable(principal, totalPayment, monthlyRate, month);
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