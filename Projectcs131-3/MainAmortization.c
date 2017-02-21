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
int main(void) {
	short again = FALSE;
	double totalPayment = 0.0;
	double principal = 0.0;
	int month = 0;
	double monthlyRate = 0.0;
	double apr = 0.0;
	printf("Amortization!");
	printf("Amortization Program written by Son Tran");
	printf("Please select a Menu Option\n\n");
	printf("\t1. Calculate (P)ayment Size\n");
	printf("\t2. Calculate (L)oan Size\n");
	printf("\t3. Calculate (N)umber of Payments\n");
	printf("\t4. Calculate (I)nterest (APR)\n");
	printf("\t5. (Q)uit\n\n");
	printf("Enter a menu option: ");
	do
	{
		switch (getche())
		{
		case '1':
		case 'P':
		case 'p':
			printf("\nEnter the interest rate (APR) you will be paying"
				"(nearest 1/8 points, >=0): ");

			break;
		case '2':
		case 'l':
		case 'L':
			printf("\nvip");
			break;
		case '3':
		case 'N':
		case 'n':
			printf("\njk");
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
			again = TRUE;
			break;
		}
	} while (again == TRUE);
	getchar();
	return EXIT_SUCCESS;
}