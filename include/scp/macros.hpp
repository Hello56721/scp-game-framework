#ifndef A284414F_C237_4968_9390_D8DD2BB1203A
#define A284414F_C237_4968_9390_D8DD2BB1203A

#pragma once

// This file contains all of the macros that will be used by almost everything 
// in the framework. Currently, it only contains the macro used for exporting 
// symbols when building the framework as a DLL.

// Macro for exporting the symbols when building as a DLL.
#ifdef SCP_DLL
    #ifdef SCP_BUILD_DLL
        #define SCPGF __declspec(dllexport)
    #else
        #define SCPGF __declspec(dllimport)
    #endif // SCP_BUILD_DLL
#else
    #define SCPGF
#endif // SCP_DLL

#endif /* A284414F_C237_4968_9390_D8DD2BB1203A */
