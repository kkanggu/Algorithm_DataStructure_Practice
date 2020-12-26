#include "Basic.h"

typedef int T ;

void MergeSort ( T prgData [] , int iStart , int iEnd , int iNum , bool bAscending )	// Recursive merge sort function
{																						// True, sort ascending order
	if ( iStart + 1 < iEnd )															// False, srt descending order
	{
		int iHalf = ( iStart + iEnd ) / 2 ;



		MergeSort ( prgData , iStart , iHalf , iNum  , bAscending ) ;			// Recursive call
		MergeSort ( prgData , iHalf + 1 , iEnd , iNum , bAscending ) ;
		mergeArray ( prgData , iStart , iEnd , iNum ) ;							// Merge splited array
	}
	else if ( iStart + 1 == iEnd )												// If recursive function only have 2 values
	{
		if ( ( bAscending && ( prgData [ iStart ] > prgData [ iEnd ] ) )
				|| ( ! bAscending && ( prgData [ iStart ] < prgData [ iEnd ] ) ) )
		{
			T Temp = prgData [ iStart ] ;



			prgData [ iStart ] = prgData [ iEnd ] ;
			prgData [ iEnd ] = Temp ;
		}
	}
}

void mergeArray ( T prgData [] , int iStart , int iEnd , int iNum )						// Merge two splited arrays
{
	int iFormerIndex = iStart ;													// Check two arrays
	int iLatterIndex = ( iStart + iEnd ) / 2 + 1 ;
	T * TempArray = ( T * ) malloc ( sizeof ( T ) * iNum ) ;



	for ( int i = 0 ; i < iEnd - iStart + 1 ; ++i )
	{
		if ( -1 == iFormerIndex )												// Added all former array
		{
			TempArray [ i ] = prgData [ iLatterIndex ] ;
			++ iLatterIndex ;
		}
		else if ( -1 == iLatterIndex )											// Added all latter array
		{
			TempArray [ i ] = prgData [ iFormerIndex ] ;
			++ iFormerIndex ;			
		}
		else if ( TempArray [ iFormerIndex ] > prgData [ iLatterIndex ] )		// Former array is bigger than latter array
		{
			TempArray [ i ] = prgData [ iFormerIndex ] ;
			++ iFormerIndex ;

			if ( ( ( iStart + iEnd ) / 2 + 1 ) == iFormerIndex )
				iFormerIndex = -1 ;
		}
		else																	// Latter array is bigger than latter array
		{
			TempArray [ i ] = prgData [ iLatterIndex ] ;
			++ iLatterIndex ;

			if ( iEnd < iLatterIndex )
				iLatterIndex = -1 ;
		}
	}

	for ( int i = 0 ; i < iEnd - iStart + 1 ; ++i )								// Copy merged array
	{
		prgData [ i + iStart ] = TempArray [ i ] ;
	}

	free ( TempArray ) ;
}
