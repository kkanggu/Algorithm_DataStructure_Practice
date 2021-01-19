#pragma once

#include "Basic.h"

int KnuthMorrisPratt ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize ) ;						// Knuth Morris Pratt algorithm

void Preprocess ( char * Pattern , int iPatternSize , int * ipBorder ) ;	// Make border array