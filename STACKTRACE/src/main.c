/*
 ============================================================================
 Name        : main.c
 Author      : Heiner Kücker
 Version     :
 Copyright   : No copyright, do what you want with this code.
               No guarantee of functionality and no guarantee of accuracy.
 Description : Stack trace in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Switch for stack trace on
// This line must be before inclusion of the header file stacktrace.h
// Comment it out to disable stack trace
#define STACKTRACE_ON

// include for stack trace
#include "stacktrace.h"

void f1(STACKTRACE_PARAMETER_SINGLE)
{
	STACKTRACE_PRINT
}

void f2(STACKTRACE_PARAMETER_SINGLE)
{
	f1(STACKTRACE_ARGUMENT_SINGLE);
}

void f3(STACKTRACE_PARAMETER int n)
{
	printf("%s %d\n", __func__, n);
	STACKTRACE_PRINT
}

void f4(STACKTRACE_PARAMETER int n)
{
	printf("%s %d\n", __func__, n);
	f3(STACKTRACE_ARGUMENT n + 1);
}


int main(void)
{
	puts("Stack trace demo main");

	f2(STACKTRACE_ROOT_SINGLE);

	f4(STACKTRACE_ROOT 0);

	return EXIT_SUCCESS;
}
