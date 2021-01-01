#include "OpenAddressing.h"

HashTable * OAHT_CreateHashTable ( int iTableSize )						// Create Double Hashing Hash Table
{
	HashTable * HT = ( HashTable * ) malloc ( sizeof ( HashTable ) ) ;



	HT -> m_iTableSize = iTableSize ;
	HT -> m_iOccupiedCount = 0 ;
	HT -> m_pTable = malloc ( sizeof ( Element ) * iTableSize ) ;


	for ( int i = 0 ; i < iTableSize ; ++i )					// If each m_bOccupied of Element != true
	{															// If every m_bOccupied is false, delete this for function
		HT -> m_pTable [ i ].m_bOccupied = false ;
	}


	return HT ;
}

void OAHT_DestroyHashTable ( HashTable * HT )							// Destroy Double Hashing Hash Table
{
	int i = 0 ;
	int iOccCnt = 0 ;



	while ( HT -> m_iOccupiedCount != iOccCnt )
	{
		if ( HT -> m_pTable [ i ].m_bOccupied )					// If occupied, then reset Element
		{
			OAHT_ResetElement ( & HT -> m_pTable [ i ] ) ;
			++ iOccCnt ;
		}


		++ i ;
	}


	free ( HT -> m_pTable ) ;
	free ( HT ) ;
}

void OAHT_ResetElement ( Element * pElement )							// Reset Element
{
	free ( pElement -> m_Key ) ;
	free ( pElement -> m_Value ) ;

	pElement -> m_bOccupied = false ;
}

void OAHT_Set ( HashTable ** HT , KeyType Key , ValueType Value )		// Set Node into Hash Table
{
	int iAddress ;
	int iStepSize ;
	



	if ( 0.75 < ( double ) ( * HT ) -> m_iOccupiedCount / ( * HT ) -> m_iTableSize )
	{
		OAHT_ReHash ( HT ) ;
	}


	iAddress = OAHT_Hash1 ( Key , strlen ( Key ) , ( * HT ) -> m_iTableSize ) ;
	iStepSize = OAHT_Hash2 ( Key , strlen ( Key ) , ( * HT ) -> m_iTableSize ) ;


	while ( ( * HT ) -> m_pTable [ iAddress ].m_bOccupied )			// If another Element exist
	{
		iAddress += iStepSize ;

		
		if ( iAddress >= ( * HT ) -> m_iTableSize )
			iAddress -= ( * HT ) -> m_iTableSize ;
	}


	( * HT ) -> m_pTable [ iAddress ].m_bOccupied = true ;
	( * HT ) -> m_pTable [ iAddress ].m_Key = malloc ( sizeof ( char ) * ( strlen ( Key ) + 1 ) ) ;
	strcpy_s ( ( * HT ) -> m_pTable [ iAddress ].m_Key , strlen ( Key ) + 1 , Key ) ;
	( * HT ) -> m_pTable [ iAddress ].m_Value = malloc ( sizeof ( char ) * ( strlen ( Value ) + 1 ) ) ;
	strcpy_s ( ( * HT ) -> m_pTable [ iAddress ].m_Value , strlen ( Value ) + 1 , Value ) ;

	++ ( * HT ) -> m_iOccupiedCount ;

	printf ( "Key (%s) entered at address (%d)\n" , Key , iAddress ) ;
}

ValueType OAHT_Get ( HashTable * HT , KeyType Key )						// Get value of Element for key
{
	int iAddress = OAHT_Hash1 ( Key , strlen ( Key ) , HT -> m_iTableSize ) ;
	int iStepSize = OAHT_Hash2 ( Key , strlen ( Key ) , HT -> m_iTableSize ) ;
	ValueType * pValue = NULL ;



	while ( HT -> m_pTable [ iAddress ].m_bOccupied )			// If occupied, search
	{
		if ( 0 == strcmp ( HT -> m_pTable [ iAddress ].m_Key , Key ) )
		{														// If find
			pValue = HT -> m_pTable [ iAddress ].m_Value ;

			break ;
		}


		iAddress += iStepSize ;


		if ( iAddress >= HT -> m_iTableSize )
		{
			iAddress -= HT -> m_iTableSize ;
		}
	}


	return pValue ;
}

int OAHT_Hash1 ( KeyType Key , int iKeyLength , int iTableSize )		// Hashing and return it
{
	int iHashValue = 0 ;



	for ( int i = 0 ; i < iKeyLength ; ++i )
	{
		iHashValue = ( iHashValue << 3 ) + Key [ i ] ;
	}


	return iHashValue % iTableSize ;
}

int OAHT_Hash2 ( KeyType Key , int iKeyLength , int iTableSize )		// Hashing with different number from Hash1 and return it
{
	int iHashValue = 0 ;



	for ( int i = 0 ; i < iKeyLength ; ++i )
	{
		iHashValue = ( iHashValue << 2 ) + Key [ i ] ;
	}


	return iHashValue % ( iTableSize - 3 ) + 1 ;
}

void OAHT_ReHash ( HashTable ** OldHT )									// If usage of HashTable > 0.75, then rehashing it.
{
	Element * pCopy = ( * OldHT ) -> m_pTable ;
	HashTable * NewHT = OAHT_CreateHashTable ( ( * OldHT ) -> m_iTableSize * 2 ) ;



	printf ( "ReHashing complete. New table size : %d\n" , NewHT -> m_iTableSize ) ;


	for ( int i = 0 ; i < ( * OldHT ) -> m_iTableSize ; ++i  )
	{
		if ( pCopy [ i ].m_bOccupied )							// If occupied
		{
			OAHT_Set ( & NewHT , pCopy [ i ].m_Key , pCopy [ i ].m_Value ) ;
		}
	}


	OAHT_DestroyHashTable ( * OldHT ) ;

	* OldHT = NewHT ;
}