#ifndef AMORT_H
#define AMORT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#pragma warning(disable: 4996)
// header for function get payment amount
double getPaymentAmount(int months, double principal, double monthlyRate);
// header for function get Loan amount
double getLoanAmount(int months, double totalPayment, double monthlyRate);
//header for function get number of months
int getNumberOfMonths(double principal, double totalPayment, double monthlyRate);
double getInterestRate(double sizeOfLoan, double monthlyPayment, int months);
void safeReadDouble(double* number_ptr, const char * prompt);
void safeReadInt(int* number_ptr, const char * prompt);
void cleanBuffer();
double readApr();
double readPrincipal();
double readPayment();
int readMonth();
#endif #pragma once
