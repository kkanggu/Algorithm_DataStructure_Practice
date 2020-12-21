#pragma once

#include "Basic.h"

typedef int T ;																	// Template for understanding

typedef struct LinkedListNode
{
	T m_Data ;
	struct LinkedListNode * m_pPrev ;
	struct LinkedListNode * m_pNext ;
	int m_iCnt ;																// For counting. Only Head have cnt info
} Node ;

Node * DLL_CreateNode ( T Data ) ;												// Add new Node with data, type T
void DLL_DestroyNode ( Node * pNode ) ;											// Destroy pNode
void DLL_AppendNode ( Node ** pHead , Node * pNewNode ) ;						// Add New Node, call DLL_CreateNode
void DLL_InsertNode ( Node * pHead , Node * pCurrent , Node * pNewNode ) ;		// Inser pNewNode after pCurrent, pCurrent -> pNewNode
void DLL_RemoveNode ( Node ** pHead , Node * pRemove ) ;						// Remove pRemove
Node * DLL_GetNodeAt ( Node * pHead , int iPosition ) ;							// Get Node of iPosition