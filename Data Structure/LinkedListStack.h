#pragma once

#include "Basic.h"

typedef int T ;																			// Template for understanding

typedef struct LinkedListNode
{
	T m_Data ;
	struct LinkedListNode * m_pNext ;
} Node ;

typedef struct LinkedListStack
{
	Node * m_pHead ;																	// Head, first input. Pop last
	Node * m_pTail ;																	// Tail, lats input. Pop first
	int m_iCnt ;
} LinkedListStack ;

void LLS_CreateStack ( LinkedListStack ** pLinkedListStack ) ;							// Create stack with LinkedList
void LLS_DestroyStack ( LinkedListStack ** pLinkedListStack ) ;							// Destroy stack
Node * LLS_CreateNode ( T Data ) ;														// Create Node with T Data
void LLS_DestroyNode ( Node * pNode ) ;													// Destroy Node
void LLS_Push ( LinkedListStack ** pLinkedListStack , T Data ) ;						// Push Node into stacks
Node * LLS_Pop ( LinkedListStack ** pLinkedListStack ) ;								// Pop Node
Node * LLS_Top ( LinkedListStack * pLinkedListStack ) ;									// Return top, m_pTail
int LLS_GetSize ( LinkedListStack * pLinkedListStack ) ;								// Return current stack size
bool LLS_IsEmpty ( LinkedListStack * pLinkedListStack ) ;								// Return true if empty