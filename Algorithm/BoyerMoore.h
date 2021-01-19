#pragma once

#include "Basic.h"

int BoyerMoore ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize ) ;				// Boyer-Moore algorithm

void BuildBCT ( char * Pattern , int iPatternSize ,
				int * ipBCT ) ;										// Bad Character Shift
void BuildGST ( char * Pattern , int iPatternSize ,
				int * ipSuffix , int * ipGST ) ;					// Good Suffix Shift

int iMax ( int iA , int iB ) ;										// Return max value