#pragma once

#include "Basic.h"

typedef int T ;														// Template for understanding

typedef struct HeapNode
{
	T m_Data ;
} Node ;															// Heap member, can be any type

typedef struct Heap
{
	Node * m_pNodes ;												// Heap Node array
	int m_iCapacity ;												// Capacity for array
	int m_iUsedSize ;												// Current Heap size
} Heap ;

Heap * HEAP_Create ( int iInitializeSize ) ;						// Create Heap, max size iInitializeSize
void HEAP_Destroy ( Heap * H ) ;									// Destroy Heap
void HEAP_Insert ( Heap *  H , T Data ) ;							// Insert Data into Heap
void HEAP_DeleteMin ( Heap * H ) ;									// Delete min value at Heap
int HEAP_GetParent ( int iIndex ) ;									// Get parent of iIndex Node
int HEAP_GetLeftChild ( int iIndex ) ;								// Get left child of iIndex Node
void HEAP_SwapNodes ( Heap * H , int iIndex1 , int iIndex2 ) ;		// Swap Nodes at iIndex1 & iIndex2
void HEAP_PrintNodes ( Heap * H ) ;									// Print Heap