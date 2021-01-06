#pragma once

#include "Basic.h"

typedef struct PriorityQueueNode
{
	int m_iPriority ;
	void * m_pData ;														// Use void * for scalability
} Node ;

typedef struct PriorityQueue
{
	Node * m_pNodes ;														// Node array
	int m_iCapacity ;														// Capacity for array
	int m_iUsedSize ;														// Current Priority Queue size
	int m_iMinCapacity ;													// Minimum capacity, dynamic size
} PriorityQueue ;

PriorityQueue * PQ_Create ( int iInitializeSize ) ;							// Create Priority Queue, min size iInitializeSize
void PQ_Destroy ( PriorityQueue * PQ ) ;									// Destroy Priority Queue
void PQ_Enqueue ( PriorityQueue * PQ , Node NewNode ) ;						// Enqueue Data into Priority Queue
Node PQ_Dequeue ( PriorityQueue * PQ ) ;									// Dequeue first Node from Priority Queue
int PQ_GetParent ( int iIndex ) ;											// Get parent of iIndex Node
int PQ_GetLeftChild ( int iIndex ) ;										// Get left child of iIndex Node
void PQ_SwapNodes ( PriorityQueue * PQ , int iIndex1 , int iIndex2 ) ;		// Swap Nodes at iIndex1 & iIndex2