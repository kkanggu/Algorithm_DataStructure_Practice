#pragma once

#include "Basic.h"

typedef int T ;														// Template for understanding

typedef struct CircularQueue
{
	T * m_rgData ;
	int m_iFront ;													// Last input, first dequeue
	int m_iRear ;													// Rear point end node + 1, empty space
	int m_iCapacity ;
} CircularQueue ;

void CQ_CreateQueue ( CircularQueue ** pQueue , int iCapacity ) ;	// Create Circular Queue with array
void CQ_DestroyQueue ( CircularQueue ** pQueue ) ;					// Destroy Queue
void CQ_Enqueue ( CircularQueue ** pQueue , T pData ) ;				// Put T into Queue
T CQ_Dequeue ( CircularQueue ** pQueue ) ;							// Return T from Queue
int CQ_GetSize ( CircularQueue * pQueue ) ;							// Return count of T (Nodes)
bool CQ_IsEmpty ( CircularQueue * pQueue ) ;						// If emptry (No Node), true
bool CQ_IsFull ( CircularQueue * pQueue ) ;							// If full, true