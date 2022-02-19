#ifndef FF036A3D_FAD9_4D88_AC05_DD0A989B28FB
#define FF036A3D_FAD9_4D88_AC05_DD0A989B28FB

/*
MIT License

Copyright (c) 2022 Hello56721

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// A set of macros that everything in the game framework will need to use. Cur-
// rently, there is only one, and that is the one needed for exporting symbols 
// when building the project as a Microsoft(R) Windows(R) DLL(R).

// This needs to be placed before every symbol within the framework, otherwise
// building the framework as a DLL will not work properly.
#ifdef SCP_PLATFORM_WINDOWS
    #ifdef SCP_DLL
        #ifdef SCP_BUILD_DLL
            #define SCPGF __declspec(dllexport)
        #else
            #define SCPGF __declspec(dllimport)
        #endif
    #else
        #define SCPGF
    #endif
#else
    #define SCPGF
#endif

#endif /* FF036A3D_FAD9_4D88_AC05_DD0A989B28FB */
