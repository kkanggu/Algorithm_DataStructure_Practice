#include "Chaining.h"

HashTable * CHT_CreateHashTable ( int iTableSize )					// Create Chaining Hash Table
{
	HashTable * HT = ( HashTable * ) malloc ( sizeof ( HashTable ) ) ;



	HT -> m_iTableSize = iTableSize ;
	HT -> m_pTable = malloc ( sizeof ( List ) * iTableSize ) ;


	for ( int i = 0 ; i < iTableSize ; ++i )				// If each Node of m_pTable != NULL
	{														// If NULL, delete this for function
		HT -> m_pTable [ i ] = NULL ;
	}


	return HT ;
}

void CHT_DestroyHashTable ( HashTable * HT )						// Destroy Chaining Hash Table
{
	for ( int i = 0 ; i < HT -> m_iTableSize ; ++i )
	{
		if ( NULL != HT -> m_pTable [ i ] )
		{
			free ( HT -> m_pTable [ i ] -> m_Key ) ;
			free ( HT -> m_pTable [ i ] -> m_Value ) ;
			free ( HT -> m_pTable [ i ] ) ;
		}
	}

	free ( HT -> m_pTable ) ;
	free ( HT ) ;
}

Node * CHT_CreateNode ( KeyType Key , ValueType Value )				// Create Chaining Node
{
	Node * pNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNode -> m_Key = malloc ( sizeof ( char ) * ( strlen ( Key ) + 1 ) ) ;
	strcpy_s ( pNode -> m_Key , strlen ( Key ) + 1 , Key ) ;
	pNode -> m_Value = malloc ( sizeof ( char ) * ( strlen ( Value ) + 1 ) ) ;
	strcpy_s ( pNode -> m_Value , strlen ( Value ) + 1 , Value ) ;
	pNode -> m_pNext = NULL ;


	return pNode ;
}

void CHT_DestroyNode ( Node * pNode ) 								// Destroy Chaining Node
{
	free ( pNode ) ;
}

void CHT_Set ( HashTable * HT , KeyType Key , ValueType Value )		// Set Node into Hash Table
{
	Node * pNode = CHT_CreateNode ( Key , Value ) ;
	int iAddress = CHT_Hash ( Key , strlen ( Key ) , HT -> m_iTableSize ) ;


	if ( NULL != HT -> m_pTable [ iAddress ] )
		printf ( "Collision Occured : Key (%s) , Address (%d) \n" , Key , iAddress ) ;


	pNode -> m_pNext = HT -> m_pTable [ iAddress ] ;
	HT -> m_pTable [ iAddress ] = pNode ;

}

ValueType CHT_Get ( HashTable * HT , KeyType Key )					// Get value of Node for key
{
	int iAddress = CHT_Hash ( Key , strlen ( Key ) , HT -> m_iTableSize ) ;
	Node * pTarget = HT -> m_pTable [ iAddress ] ;



	while ( NULL != pTarget )
	{
		if ( 0 == strcmp ( Key , pTarget -> m_Key ) )		// If find
		{
			return pTarget -> m_Value ;
		}


		pTarget = pTarget -> m_pNext ;
	}


	return pTarget ;
}

int CHT_Hash ( KeyType Key , int iKeyLength , int iTableSize )		// Hashing and return it
{
	int iHashValue = 0 ;



	for ( int i = 0 ; i < iKeyLength ; ++i )
	{
		iHashValue = ( iHashValue << 3 ) + Key [ i ] ;
	}


	return iHashValue % iTableSize ;
}