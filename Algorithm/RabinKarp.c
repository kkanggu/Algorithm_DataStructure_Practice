#include "RabinKarp.h"

int RabinKarp ( char * szText , int iTextSize , int iStart ,
				char * szPattern , int iPatternSize )			// Rabin-Karp algorithm
{
	const int iPatternHash = Hash ( szPattern , iPatternSize , 0 ) ;
	const int iCoefficient = pow ( 2.0 , iPatternSize - 1 ) ;
	int iTextHash = -1 ;



	if ( iTextSize + iStart >= iPatternSize )
	{
		iTextHash = Hash ( szText , iPatternSize , iStart ) ;


		for ( int i = iStart ; i <= iTextSize - iPatternSize ; ++i )
		{
			iTextHash = ReHash ( szText , iPatternSize , i , iTextHash , iCoefficient ) ;


			if ( iPatternHash == iTextHash )
			{
				for ( int j = 0 ; j < iPatternSize ; ++j )
				{
					if ( szText [ i + j ] != szPattern [ j ] )
					{
						return -1 ;
					}
				}


				return i ;
			}
		}
	}


	return -1 ;
}

int Hash ( char * String , int iSize , int iStart )				// Hash string and return
{
	int iHash = 0 ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		iHash += ( String [ i + iStart ] * pow ( 2.0 , iSize - ( i + 1 ) ) ) ;
	}


	return iHash ;
}

int ReHash ( char * String , int iSize , int iStart ,			// ReHash string and return
	int iHash , int iCoefficient )
{
	return String [ iStart + iSize - 1 ] + 2 * ( iHash - String [ iStart - 1 ] * iCoefficient ) ;
}