# stack-trace-for-c
C Macros for do it yourself stack trace

This repository contains a Eclipse CDT project STACKTRACE to clone.

Using preprocessor macros, parameters and arguments are added to the function headers and function calls.

The function parameters are a fixed structure that references the same structure for the caller as a simply linked list.

Each macro is available without a comma for functions that have no further parameters, and with commas for functions that have additional parameters.

The preprocessor symbol STACKTRACE_ON can be used to toggle the stack trace on and off.

When the stack trace is turned off, no code is generated for it, no memory is needed and there is no overhead at runtime.