#include "Basic.h"

typedef int T ;

void SelectionSort ( int prgData [] , int iLength , bool Ascending )	// True, sort ascending order
{																		// False, srt descending order
	int MinMax = INT_MAX ;
	int iIndex = 0 ;



	for ( int i = 0 ; i < iLength - 1 ; ++i )
	{
		if ( Ascending )
			MinMax = INT_MIN ;
		else
			MinMax = INT_MAX ;


		iIndex = 0 ;


		for ( int j = 0 ; j < iLength - i ; ++j )
		{
			if ( ( Ascending && ( MinMax < prgData [ j ] ) )
				|| ( ! Ascending && ( MinMax > prgData [ j ] ) ) )
			{
				MinMax = prgData [ j ] ;						// Remember Min or Max value
				iIndex = j ;									// Remember index of Min or Max value
			}
		}

		if ( iLength - 1 - i != iIndex )						// Most right value isn't Min or Max value
		{
			int Temp = prgData [ iLength - 1 - i ] ;
			prgData [ iLength - 1 - i ] = MinMax ;
			prgData [ iIndex ] = Temp ;
		}
	}
}