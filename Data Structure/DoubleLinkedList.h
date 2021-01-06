#pragma once

#include "Basic.h"

typedef int T ;																			// Template for understanding

typedef struct LinkedListNode
{
	T m_Data ;
	struct LinkedListNode * m_pPrev ;
	struct LinkedListNode * m_pNext ;						
} Node ;

typedef struct LinkedList
{
	Node * m_pHead ;
	int m_iCnt ;																		// For counting. Only Head have cnt info
} LinkedList ;

LinkedList * DLL_CreateLinkedList () ;													// Create LinkedList struct
void DLL_DestroyLinkedList (LinkedList ** pLinkedList ) ;								// Destroy LinkedList struct
Node * DLL_CreateNode ( T Data ) ;														// Add new Node with data, type T
void DLL_DestroyNode ( Node * pNode ) ;													// Destroy pNode
void DLL_AppendNode ( LinkedList ** pLinkedList , Node * pNewNode ) ;					// Add New Node
void DLL_InsertNode ( LinkedList ** pLinkedList , Node * pCurrent , Node * pNewNode ) ;	// Inser pNewNode after pCurrent, pCurrent -> pNewNode
void DLL_RemoveNode ( LinkedList ** pLinkedList , Node * pRemove ) ;					// Remove pRemove
Node * DLL_GetNodeAt ( LinkedList * pLinkedList , int iPosition ) ;						// Get Node of iPosition