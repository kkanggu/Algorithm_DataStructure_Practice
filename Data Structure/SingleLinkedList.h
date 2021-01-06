#pragma once

#include "Basic.h"
#include "Graph_AdList.h"

typedef Vertex * V ;																	// Template for understanding

typedef struct LinkedListNode
{
	V m_Data ;
	struct LinkedListNode * m_pNext ;						
} Node ;

typedef struct LinkedList
{
	Node * m_pHead ;
	int m_iCnt ;																		// For counting. Only Head have cnt info
} LinkedList ;

LinkedList * SLL_CreateLinkedList () ;													// Create LinkedList struct
void SLL_DestroyLinkedList (LinkedList ** pLinkedList ) ;								// Destroy LinkedList struct
Node * SLL_CreateNode ( V Data ) ;														// Add new Node with data, type T
void SLL_DestroyNode ( Node * pNode ) ;													// Destroy pNode
void SLL_AppendNode ( LinkedList ** pLinkedList , Node * pNewNode ) ;					// Add New Node
void SLL_InsertNode ( LinkedList ** pLinkedList , Node * pCurrent , Node * pNewNode ) ;	// Inser pNewNode after pCurrent, pCurrent -> pNewNode
void SLL_RemoveNode ( LinkedList ** pLinkedList , Node * pRemove ) ;					// Remove pRemove
Node * SLL_GetNodeAt ( LinkedList * pLinkedList , int iPosition ) ;						// Get Node of iPosition
void SLL_InsertNewHead ( LinkedList * pLinkedList , Node ** pNewHead ) ;				// Add pNewHead to Head