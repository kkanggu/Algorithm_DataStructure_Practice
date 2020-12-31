#include "PriorityQueue.h"

PriorityQueue * PQ_Create ( int iInitializeSize )							// Create Priority Queue, min size iInitializeSize
{
	PriorityQueue * PQ = ( PriorityQueue * ) malloc ( sizeof ( Node ) * iInitializeSize ) ;



	PQ -> m_iCapacity = iInitializeSize ;
	PQ -> m_iUsedSize = 0 ;
	PQ -> m_iMinCapacity = iInitializeSize ;
	PQ -> m_pNodes = ( Node * ) malloc ( sizeof ( Node ) * iInitializeSize ) ;


	return PQ ;
}

void PQ_Destroy ( PriorityQueue * PQ )										// Destroy Priority Queue
{
	free ( PQ -> m_pNodes ) ;
	free ( PQ ) ;
}

void PQ_Enqueue ( PriorityQueue * PQ , Node NewNode )						// Enqueue Data into Priority Queue
{
	int iNodeIndex = PQ -> m_iUsedSize ++ ;
	int iParentIndex = PQ_GetParent ( iNodeIndex ) ;



	if ( PQ -> m_iCapacity == PQ -> m_iUsedSize )							// If full, expand capacity
	{
		PQ -> m_iCapacity *= 2 ;
		PQ -> m_pNodes = realloc ( PQ -> m_pNodes , sizeof ( Node ) * PQ -> m_iCapacity ) ;
	}


	PQ -> m_pNodes [ iNodeIndex ] = NewNode ;


	while ( 0 != iNodeIndex )
	{
		if ( PQ -> m_pNodes [ iParentIndex ].m_iPriority > NewNode.m_iPriority )
		{
			PQ_SwapNodes ( PQ , iParentIndex , iNodeIndex ) ;
			iNodeIndex = iParentIndex ;
			iParentIndex = PQ_GetParent ( iParentIndex ) ;
		}
		else
			break ;
	}
}

Node PQ_Dequeue ( PriorityQueue * PQ )										// Dequeue first Node from Priority Queue
{
	Node ReturnNode = PQ -> m_pNodes [ 0 ] ;
	int iNodeIndex = 0 ;
	int iLeftIndex = PQ_GetLeftChild ( iNodeIndex ) ;
	int iRightIndex = iLeftIndex + 1 ;
	int iTargetIndex = 0 ;



	PQ -> m_pNodes [ 0 ] = PQ -> m_pNodes [ -- PQ -> m_iUsedSize ] ;

	
	while ( true )
	{
		if ( PQ -> m_iUsedSize <= iLeftIndex )																	// No child
		{
			break ;
		}
		else if ( ( PQ -> m_iUsedSize <= iRightIndex )
			&& ( PQ -> m_pNodes [ iLeftIndex ].m_iPriority < PQ -> m_pNodes [ iNodeIndex ].m_iPriority ) )		// Only one child
		{
			iTargetIndex = iLeftIndex ;
		}
		else																									// Two child
		{
			if ( ( PQ -> m_pNodes [ iLeftIndex ].m_iPriority > PQ -> m_pNodes [ iNodeIndex ].m_iPriority )
				&& ( PQ -> m_pNodes [ iRightIndex ].m_iPriority > PQ -> m_pNodes [ iNodeIndex ].m_iPriority ) )		// Parent is smaller than childs
			{
				break ;
			}
			else if ( ( PQ -> m_pNodes [ iLeftIndex ].m_iPriority > PQ -> m_pNodes [ iNodeIndex ].m_iPriority )
				&& ( PQ -> m_pNodes [ iRightIndex ].m_iPriority < PQ -> m_pNodes [ iNodeIndex ].m_iPriority ) )		// Parent is bigger than right child
			{
				iTargetIndex = iRightIndex ;
			}
			else if ( ( PQ -> m_pNodes [ iLeftIndex ].m_iPriority < PQ -> m_pNodes [ iNodeIndex ].m_iPriority )
				&& ( PQ -> m_pNodes [ iRightIndex ].m_iPriority > PQ -> m_pNodes [ iNodeIndex ].m_iPriority ) )		// Parent is bigger than left child
			{
				iTargetIndex = iLeftIndex ;
			}
			else																									// Parent is bigger than right child
			{
				if ( PQ -> m_pNodes [ iLeftIndex ].m_iPriority < PQ -> m_pNodes [ iRightIndex ].m_iPriority )		// Left child is smaller
				{
					iTargetIndex = iLeftIndex ;
				}
				else
				{
					iTargetIndex = iRightIndex ;
				}
			}			
		}


		PQ_SwapNodes ( PQ , iNodeIndex , iTargetIndex ) ;
		iNodeIndex = iTargetIndex ;
		iLeftIndex = PQ_GetLeftChild ( iNodeIndex ) ;
		iRightIndex = iLeftIndex + 1 ;
	}

	//if ( ( PQ -> m_iCapacity > PQ -> m_iUsedSize * 2 ) && ( PQ -> m_iMinCapacity != PQ -> m_iCapacity ) )			// If too empty, reduce capacity
	//{
	//	PQ -> m_iCapacity /= 2 ;
	//	PQ -> m_pNodes = realloc ( PQ -> m_pNodes , PQ -> m_iCapacity ) ;
	//}


	return ReturnNode ;
}

int PQ_GetParent ( int iIndex )												// Get parent of iIndex Node
{
	return ( iIndex - 1 ) / 2 ;
}

int PQ_GetLeftChild ( int iIndex )											// Get left child of iIndex Node
{
	return ( iIndex * 2 ) + 1 ;
}

void PQ_SwapNodes ( PriorityQueue * PQ , int iIndex1 , int iIndex2 )		// Swap Nodes at iIndex1 & iIndex2
{
	Node Data1 = PQ -> m_pNodes [ iIndex1 ] ;
	Node Data2 = PQ -> m_pNodes [ iIndex2 ] ;



	PQ -> m_pNodes [ iIndex2 ] = Data1 ;
	PQ -> m_pNodes [ iIndex1 ] = Data2 ;
}