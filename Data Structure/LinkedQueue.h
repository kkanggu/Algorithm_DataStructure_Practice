#pragma once

#include "Basic.h"

typedef int T ;														// Template for understanding

typedef struct LinkedListNode
{
	T m_Data ;
	struct LinkedListNode * m_pNext ;
} Node ;

typedef struct LinkedQueue
{
	Node * m_pHead ;												// Head, last input. Dequeue first
	Node * m_pTail ;												// Tail, first input. Pop first
	int m_iCnt ;
} LinkedQueue ;

void LQ_CreateQueue ( LinkedQueue ** pQueue ) ;						// Create Queue with Linked List
void LQ_DestroyQueue ( LinkedQueue ** pQueue ) ;					// Destroy Queue and Nodes
Node * LQ_CreateNode ( T Data ) ;									// Create Node and return it
void LQ_DestroyNode ( Node * pNode ) ;								// Destroy pNode
void LQ_Enqueue ( LinkedQueue ** pQueue , Node * pNode ) ;			// Enqueue pNode into pQueue
Node * LQ_Dequeue ( LinkedQueue ** pQueue ) ;						// Dequeue Node from pQueue
bool LQ_IsEmpty ( LinkedQueue * pQueue ) ;							// If no Node, true