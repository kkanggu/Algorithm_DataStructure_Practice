#include "Basic.h"

typedef int T ;

void InsertionSort ( T prgData [] , int iLength , bool bAscending )						// True, sort ascending order
{																						// False, srt descending order
	T Temp ;



	for ( int i = 1 ; i < iLength ; ++i )
	{
		for ( int j = 0 ; j < i ; ++j )
		{
			if ( ( bAscending && ( prgData [ j ] > prgData [ i ] ) )			// Ascending, (4) (3)
				|| ( ! bAscending && ( prgData [ j ] < prgData [ i ] ) ) )		// Descending, (3) (4)
			{
				Temp = prgData [ i ] ;


				for ( int k = i ; k > j ; --k )
				{
					prgData [ k ] = prgData [ k - 1 ] ;
				}


				prgData [ j ] = Temp ;
			}
		}
	}
}