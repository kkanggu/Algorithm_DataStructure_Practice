#pragma once

#include "Basic.h"

typedef char * KeyType ;												// Key template for understanding
typedef char * ValueType ;												// Value template for understanding

typedef struct ChainingNode
{
	KeyType m_Key ;
	ValueType m_Value ;

	struct ChainingNode * m_pNext ;
} Node ;

typedef Node * List ;													// List is head of LinkedList

typedef struct HashTable
{
	int m_iTableSize ;
	List * m_pTable ;													// Each content of list array point ChainingNode, LinkedList style
} HashTable ;

HashTable * CHT_CreateHashTable ( int iTableSize ) ;					// Create Chaining Hash Table
void CHT_DestroyHashTable ( HashTable * HT ) ;							// Destroy Chaining Hash Table
Node * CHT_CreateNode ( KeyType Key , ValueType Value ) ;				// Create Chaining Node
void CHT_DestroyNode ( Node * pNode ) ;									// Destroy Chaining Node

void CHT_Set ( HashTable * HT , KeyType Key , ValueType Value ) ;		// Set Node into Hash Table
ValueType CHT_Get ( HashTable * HT , KeyType Key ) ;					// Get value of Node for key
int CHT_Hash ( KeyType Key , int iKeyLength , int iTableSize ) ;		// Hashing and return it