# stack-trace-for-c
C Macros for do it yourself stack trace

This repository contains a Eclipse CDT project STACKTRACE to clone.

The preprocessor symbol STACKTRACE_ON can be used to toggle the stack trace on and off.

Each macro is available without a comma for functions that have no further parameters, and with commas for functions that have additional parameters.

When the stack trace is turned off, no code is generated for it, no memory is needed and there is no overhead at runtime.