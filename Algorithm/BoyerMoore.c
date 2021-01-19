#include "BoyerMoore.h"

int BoyerMoore ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize )				// Boyer-Moore algorithm
{
	int irgBCT [ 128 ] ;
	int * ipSuffix = ( int * ) calloc ( iPatternSize + 1 , sizeof ( int ) ) ;
	int * ipGST = ( int * ) calloc ( iPatternSize + 1 , sizeof ( int ) ) ;
	int i = iStart ;
	int j = 0 ;
	int iPosition = -1 ;



	BuildBCT ( szPattern , iPatternSize , irgBCT ) ;
	BuildGST ( szPattern , iPatternSize , ipSuffix , ipGST ) ;


	while ( i <= iTextSize - iPatternSize )
	{
		j = iPatternSize - 1 ;


		while ( ( j >= 0 ) && ( szPattern [ j ] == szText [ i + j ] ) )
		{
			--j ;
		}


		if ( j < 0 )
		{
			iPosition = i ;
			break ;
		}
		else
		{
			i += iMax ( ipGST [ j + 1 ] , j - irgBCT [ szText [ i + j ] ] ) ;
		}
	}


	free ( ipSuffix ) ;
	free ( ipGST ) ;


	return iPosition ;
}

void BuildBCT ( char * Pattern , int iPatternSize ,
				int * ipBCT )										// Bad Character Shift
{
	for ( int i = 0 ; i < 128 ; ++i )
	{
		ipBCT [ i ] = -1 ;
	}

	for ( int j = 0 ; j < iPatternSize ; ++j )
	{
		ipBCT [ Pattern [ j ] ] = j ;
	}
}

void BuildGST ( char * Pattern , int iPatternSize ,
				int * ipSuffix , int * ipGST )						// Good Suffix Shift
{
	// Case 1
	int i = iPatternSize ;
	int j = iPatternSize + 1 ;



	ipSuffix [ i ] = j ;


	while ( i > 0 )
	{
		while ( ( j <= iPatternSize ) && ( Pattern [ i - 1 ] != Pattern [ j - 1 ] ) )
		{
			if ( 0 == ipGST [ j ] )
				ipGST [ j ] = j - i ;


			j = ipSuffix [ j ] ;
		}


		--i ;
		--j ;

		ipSuffix [ i ] = j ;
	}


	// Case 2

	j = ipSuffix [ 0 ] ;

	for ( int i = 0 ; i < iPatternSize ; ++i )
	{
		if ( 0 == ipGST [ i ] )
			ipGST [ i ] = j ;

		if ( i == j )
			j = ipSuffix [ j ] ;
	}
}

int iMax ( int iA , int iB )										// Return max value
{
	if ( iA > iB )
		return iA ;
	else
		return iB ;
}