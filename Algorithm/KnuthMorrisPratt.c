#include "KnuthMorrisPratt.h"

int KnuthMorrisPratt ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize )						// Knuth Morris Pratt algorithm
{
	int i = iStart ;
	int j = 0 ;
	int iPosition = -1 ;
	int * ipBorder = ( int * ) calloc ( iPatternSize + 1 , sizeof ( int ) ) ;



	Preprocess ( szPattern , iPatternSize , ipBorder ) ;


	while ( i < iTextSize )
	{
		while ( ( j >= 0 ) && ( szText [ i ] != szPattern [ j ] ) )
		{
			j = ipBorder [ j ] ;
		}


		++i ;
		++j ;


		if ( j == iPatternSize )
		{
			iPosition = i - j ;
			break ;
		}
	}


	free ( ipBorder ) ;

	return iPosition ;
}

void Preprocess ( char * Pattern , int iPatternSize , int * ipBorder )		// Make border array
{
	int i = 0 ;
	int j = -1 ;



	ipBorder [ 0 ] = -1 ;


	while ( i < iPatternSize )
	{
		while ( ( j > -1 ) && ( Pattern [ i ] != Pattern [ j ] ) )
		{
			j = ipBorder [ j ] ;
		}

		++i ;
		++j ;

		ipBorder [ i ] = j ;
	}
}