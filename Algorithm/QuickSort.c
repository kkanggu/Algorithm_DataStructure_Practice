#include "Basic.h"

typedef int T ;

void SwapValue ( T * Data1 , T * Data2 )
{
	T Temp = * Data1 ;
	* Data1 = * Data2 ;
	* Data2 = Temp ;
}

T MiddleValue ( T prgData [] , int iIndex )											// Return middle value among first 3 values
{
	T Pivot = prgData [ iIndex ] ;													// Do not check first value is middle or not



	if ( ( prgData [ iIndex ] > prgData [ iIndex + 1 ] )							// 1 2 3
			&& ( prgData [ iIndex + 1 ] > prgData [ iIndex + 2 ] ) )
		{
			Pivot = prgData [ iIndex + 1 ] ;
			SwapValue ( & prgData [ iIndex ] , & prgData [ iIndex + 1 ] ) ;
		}
		else if ( ( prgData [ iIndex ] > prgData [ iIndex + 2 ] )					// 1 3 2
			&& ( prgData [ iIndex + 2 ] > prgData [ iIndex + 1 ] ) )
		{
			Pivot = prgData [ iIndex + 2 ] ;
			SwapValue ( & prgData [ iIndex ] , & prgData [ iIndex + 2 ] ) ;
		}
		else if ( ( prgData [ iIndex + 1 ] > prgData [ iIndex + 2 ] )				// 3 1 2
			&& ( prgData [ iIndex + 2 ] > prgData [ iIndex ] ) )
		{
			Pivot = prgData [ iIndex + 2 ] ;
			SwapValue ( & prgData [ iIndex ] , & prgData [ iIndex + 2 ] ) ;
		}
		else if ( ( prgData [ iIndex + 2 ] > prgData [ iIndex + 1 ] )				// 3 2 1
			&& ( prgData [ iIndex + 1 ] > prgData [ iIndex ] ) )
		{
			Pivot = prgData [ iIndex + 1 ] ;
			SwapValue ( & prgData [ iIndex ] , & prgData [ iIndex + 1 ] ) ;
		}


	return Pivot ;
}

void QuickSort ( T prgData [] , int iLeft , int iRight , bool bAscending )					// True, sort ascending order
{																							// False, srt descending order
	if ( iLeft < iRight )
	{
		T Pivot = prgData [ iLeft ] ;
		int iTempLeft = iLeft + 1 ;
		int iTempRight = iRight ;



		if ( iLeft + 2 <= iRight )													// If need to sort 3 more datas
		{																			// Use middle value of first 3 datas
			Pivot = MiddleValue ( prgData , iLeft ) ;								// For avoid worst condition
		}


		while ( iTempLeft < iTempRight )
		{
			while ( iTempLeft < iTempRight && ( ( bAscending && ( Pivot > prgData [ iTempLeft ] ) )
				|| ( ! bAscending && ( Pivot < prgData [ iTempLeft ] ) ) ) )
			{
				++ iTempLeft ;
			}
			while ( iTempLeft < iTempRight && ( ( bAscending && ( Pivot < prgData [ iTempRight ] ) )
				|| ( ! bAscending && ( Pivot > prgData [ iTempRight ] ) ) ) )
			{
				-- iTempRight ;
			}

			if ( iTempLeft < iTempRight )
			{
				SwapValue ( & prgData [ iTempLeft ] , & prgData [ iTempRight ] ) ;
			}
		}


		SwapValue ( & prgData [ iLeft ] , & prgData [ iTempLeft - 1 ] ) ;

		QuickSort ( prgData , iLeft , iTempLeft - 2 , bAscending ) ;
		QuickSort ( prgData , iTempLeft , iRight , bAscending ) ;
	}
}