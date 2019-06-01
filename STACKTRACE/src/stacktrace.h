/*
 * stacktrace.h
 *
 * Created on: 01.06.2019
 * Author: Heiner Kücker
 */

#ifndef STACKTRACE_H_
#define STACKTRACE_H_

// This struct implements a simply linked list to the element of the respective caller
typedef struct StacktraceElement
{
	const char * file;
	const int line;
	const char * func;
	const struct StacktraceElement * callerStacktraceElement_p;
}StacktraceElement_s;

void print_Stacktrace(StacktraceElement_s stacktraceElement);

/***
 * Macros:
 *
 * Each macro is available without a comma for functions that have no further parameters, and with commas for functions that have additional parameters.
 */

/**
 * Function arguments, use in function call
 */

/*
 * Root arguments, use in root function call
 */

// Macro for root of stack trace for functions with StacktraceElement as the only parameter
#ifdef STACKTRACE_ON
#define STACKTRACE_ARGUMENT_ROOT_SINGLE (StacktraceElement_s){ __FILE__, __LINE__, __func__, NULL}
#else
#define STACKTRACE_ARGUMENT_ROOT_SINGLE
#endif

// Macro for root of stack trace for functions with StacktraceElement as one of several parameters
#ifdef STACKTRACE_ON
#define STACKTRACE_ARGUMENT_ROOT (StacktraceElement_s){ __FILE__, __LINE__, __func__, NULL},
#else
#define STACKTRACE_ARGUMENT_ROOT
#endif


/*
 * Subsequent arguments, use in subsequent function call
 */

// Macro for subsequent stack trace for functions with StacktraceElement as the only parameter
#ifdef STACKTRACE_ON
#define STACKTRACE_ARGUMENT_SINGLE (StacktraceElement_s){ __FILE__, __LINE__, __func__, &stacktraceElement}
#else
#define STACKTRACE_ARGUMENT_SINGLE
#endif

// Macro for root of stack trace for functions with StacktraceElement as one of several parameters
#ifdef STACKTRACE_ON
#define STACKTRACE_ARGUMENT (StacktraceElement_s){ __FILE__, __LINE__, __func__, &stacktraceElement},
#else
#define STACKTRACE_ARGUMENT
#endif



/**
 * Function parameters, use in the function declaration and definition
 */
// Macro for stack trace parameter for functions with StacktraceElement as the only parameter
#ifdef STACKTRACE_ON
#define STACKTRACE_PARAMETER_SINGLE StacktraceElement_s stacktraceElement
#else
#define STACKTRACE_PARAMETER_SINGLE
#endif

// Macro for stack trace parameter for functions with StacktraceElement as one of several parameters
#ifdef STACKTRACE_ON
#define STACKTRACE_PARAMETER StacktraceElement_s stacktraceElement,
#else
#define STACKTRACE_PARAMETER
#endif

/**
 * Print stack trace
 */
#ifdef STACKTRACE_ON
#define STACKTRACE_PRINT print_Stacktrace(stacktraceElement);
#else
#define STACKTRACE_PRINT
#endif


#endif /* STACKTRACE_H_ */
