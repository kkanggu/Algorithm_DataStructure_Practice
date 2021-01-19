#pragma once

#include "Basic.h"

int RabinKarp ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize ) ;			// Rabin-Karp algorithm

int Hash ( char * String , int iSize , int iStart ) ;			// Hash string and return
int ReHash ( char * String , int iSize , int iStart ,			// ReHash string and return
	int iHash , int iCoefficient ) ;