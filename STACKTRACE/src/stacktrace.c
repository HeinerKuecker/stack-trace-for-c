/*
 * stacktrace.c
 *
 * Created on: 01.06.2019
 * Author: Heiner Kücker
 */
#include <stdio.h>
#include <stdlib.h>
#include "stacktrace.h"

void print_Stacktrace(StacktraceElement_s stacktraceElement)
{
	const StacktraceElement_s * tmpStacktraceElement_p = &stacktraceElement;

	while (tmpStacktraceElement_p != NULL)
	{
		printf("%s:%d %s\n", tmpStacktraceElement_p->file, tmpStacktraceElement_p->line, tmpStacktraceElement_p->func);
		tmpStacktraceElement_p = tmpStacktraceElement_p->callerStacktraceElement_p;
	}
}


