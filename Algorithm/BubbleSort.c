#include "Basic.h"

typedef int T ;

void BubbleSort ( T prgData [] , int iLength , bool bAscending )							// True, sort ascending order
{																							// False, srt descending order
	T Temp ;



	for ( int i = 0 ; i < iLength - 1 ; ++i )
	{
		for ( int j = 0 ; j < iLength - i - 1 ; ++j )
		{
			if ( ( bAscending && ( prgData [ j ] > prgData [ j + 1 ] ) )			// Ascending, (4) (3)
				|| ( ! bAscending && ( prgData [ j ] < prgData [ j + 1 ] ) ) )		// Descending, (3) (4)
			{
				Temp = prgData [ j + 1 ] ;
				prgData [ j + 1 ] = prgData [ j ] ;
				prgData [ j ] = Temp ;
			}
		}
	}
}