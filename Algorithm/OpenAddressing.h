#pragma once
																		// Use double hashing
#include "Basic.h"														// To simplify, don't use the prime number

typedef char * KeyType ;												// Key template for understanding
typedef char * ValueType ;												// Value template for understanding

typedef struct OpenAddressingElement
{
	KeyType m_Key ;
	ValueType m_Value ;

	bool m_bOccupied ;
} Element ;

typedef struct HashTable
{
	int m_iTableSize ;
	int m_iOccupiedCount ;												// Current number of element

	Element * m_pTable ;												// Dynamic array
} HashTable ;

HashTable * OAHT_CreateHashTable ( int iTableSize ) ;					// Create Double Hashing Hash Table
void OAHT_DestroyHashTable ( HashTable * HT ) ;							// Destroy Double Hashing Hash Table
void OAHT_ResetElement ( Element * pElement ) ;							// Reset Element

void OAHT_Set ( HashTable ** HT , KeyType Key , ValueType Value ) ;		// Set Node into Hash Table
ValueType OAHT_Get ( HashTable * HT , KeyType Key ) ;					// Get value of Element for key
int OAHT_Hash1 ( KeyType Key , int iKeyLength , int iTableSize ) ;		// Hashing and return it
int OAHT_Hash2 ( KeyType Key , int iKeyLength , int iTableSize ) ;		// Hashing with different number from Hash1 and return it
void OAHT_ReHash ( HashTable ** OldHT ) ;								// If usage of HashTable > 0.75, then rehashing it.