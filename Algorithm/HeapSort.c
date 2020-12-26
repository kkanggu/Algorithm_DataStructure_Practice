#include "Basic.h"

typedef int T ;

void HeapSort ( T prgData [] , int iNum , bool bAscending )					// True, sort ascending order
{																			// False, srt descending order
	makeHeap ( prgData , iNum , false , bAscending ) ;				// Make heap

	for ( int i = iNum - 1 ; i > 0 ; --i )							// Swap Root with Bottom
	{
		T Temp = prgData [ i ] ;

		prgData [ i ] = prgData [ 0 ] ;
		prgData [ 0 ] = Temp ;

		makeHeap ( prgData , iNum , true , bAscending ) ;
	}
}

void makeHeap( T prgData [] , int iNum , bool bSwap , bool bAscending )		// Make heap
{
	int iRoot ;
	int iChild ;


	if ( false == bSwap )											// Sort all data
	{
		for ( int i = 1 ; i < iNum ; ++i )
		{
			iChild = i ;


			while ( iChild )										// iChild have Root. if iChild == 0, then iChild is top of Heap
			{
				iRoot = ( iChild - 1 ) / 2 ;


				if ( ( bAscending && ( prgData [ iRoot ] < prgData [ iChild ] ) )
					|| ( !bAscending && ( prgData [ iRoot ] > prgData [ iChild ] ) ) )
				{
					T Temp = prgData [ iRoot ] ;

					prgData [ iRoot ] = prgData [ iChild ] ;
					prgData [ iChild ] = Temp ;
				}


				iChild = iRoot ;
			}
		}
	}
	else															// Sort swaped data
	{
		iChild = iNum - 1 ;


		while ( iChild )											// iChild have Root. if iChild == 0, then iChild is top of Heap
		{
			iRoot = ( iChild - 1 ) / 2 ;


			if ( ( bAscending && ( prgData [ iRoot ] < prgData [ iChild ] ) )
					|| ( !bAscending && ( prgData [ iRoot ] > prgData [ iChild ] ) ) )
			{
				T Temp = prgData [ iRoot ] ;

				prgData [ iRoot ] = prgData [ iChild ] ;
				prgData [ iChild ] = Temp ;
			}


			iChild = iRoot ;
		}
	}
}