#include "Heap.h"

Heap * HEAP_Create ( int iInitializeSize )							// Create Heap, max size iInitializeSize
{
	Heap * H = ( Heap * ) malloc ( sizeof ( H ) ) ;



	H -> m_iCapacity = iInitializeSize ;
	H -> m_iUsedSize = 0 ;
	H -> m_pNodes = ( Node * ) malloc ( sizeof ( Node ) * iInitializeSize ) ;


	return H ;
}

void HEAP_Destroy ( Heap * H )										// Destroy Heap
{
	free ( H -> m_pNodes ) ;
	free ( H ) ;
}

void HEAP_Insert ( Heap * H , T Data )								// Insert Data into Heap
{
	Node NewNode ;
	int iNodeIndex = H -> m_iUsedSize ++ ;
	int iParentIndex = HEAP_GetParent ( iNodeIndex ) ;



	if ( H -> m_iCapacity == H -> m_iUsedSize )				// If full, expand capacity
	{
		H -> m_iCapacity *= 2 ;
		H -> m_pNodes = realloc ( H -> m_pNodes , sizeof ( Node ) * H -> m_iCapacity ) ;
	}


	NewNode.m_Data = Data ;
	H -> m_pNodes [ iNodeIndex ] = NewNode ;


	while ( 0 != iNodeIndex )
	{
		if ( H -> m_pNodes [ iParentIndex ].m_Data > NewNode.m_Data )
		{
			HEAP_SwapNodes ( H , iParentIndex , iNodeIndex ) ;
			iNodeIndex = iParentIndex ;
			iParentIndex = HEAP_GetParent ( iParentIndex ) ;
		}
		else
			break ;
	}
}

void HEAP_DeleteMin ( Heap * H )									// Delete min value at Heap
{
	int iNodeIndex = 0 ;
	int iLeftIndex = HEAP_GetLeftChild ( iNodeIndex ) ;
	int iRightIndex = iLeftIndex + 1 ;
	int iTargetIndex = 0 ;



	H -> m_pNodes [ 0 ] = H -> m_pNodes [ -- H -> m_iUsedSize ] ;

	
	while ( true )
	{
		if ( H -> m_iUsedSize <= iLeftIndex )															// No child
		{
			break ;
		}
		else if ( ( H -> m_iUsedSize <= iRightIndex )
			&& ( H -> m_pNodes [ iLeftIndex ].m_Data < H -> m_pNodes [ iNodeIndex ].m_Data ) )			// Only one child
		{
			iTargetIndex = iLeftIndex ;
		}
		else																							// Two child
		{
			if ( ( H -> m_pNodes [ iLeftIndex ].m_Data > H -> m_pNodes [ iNodeIndex ].m_Data )
				&& ( H -> m_pNodes [ iRightIndex ].m_Data > H -> m_pNodes [ iNodeIndex ].m_Data ) )			// Parent is smaller than childs
			{
				break ;
			}
			else if ( ( H -> m_pNodes [ iLeftIndex ].m_Data > H -> m_pNodes [ iNodeIndex ].m_Data )
				&& ( H -> m_pNodes [ iRightIndex ].m_Data < H -> m_pNodes [ iNodeIndex ].m_Data ) )			// Parent is bigger than right child
			{
				iTargetIndex = iRightIndex ;
			}
			else if ( ( H -> m_pNodes [ iLeftIndex ].m_Data < H -> m_pNodes [ iNodeIndex ].m_Data )
				&& ( H -> m_pNodes [ iRightIndex ].m_Data > H -> m_pNodes [ iNodeIndex ].m_Data ) )			// Parent is bigger than left child
			{
				iTargetIndex = iLeftIndex ;
			}
			else																							// Parent is bigger than right child
			{
				if ( H -> m_pNodes [ iLeftIndex ].m_Data < H -> m_pNodes [ iRightIndex ].m_Data )			// Left child is smaller
				{
					iTargetIndex = iLeftIndex ;
				}
				else
				{
					iTargetIndex = iRightIndex ;
				}
			}			
		}


		HEAP_SwapNodes ( H , iNodeIndex , iTargetIndex ) ;
		iNodeIndex = iTargetIndex ;
		iLeftIndex = HEAP_GetLeftChild ( iNodeIndex ) ;
		iRightIndex = iLeftIndex + 1 ;
	}

	if ( ( H -> m_iCapacity > H -> m_iUsedSize * 2 ) && ( 15 != H -> m_iCapacity ) )						// If too empty, reduce capacity
	{
		H -> m_iCapacity /= 2 ;
		H -> m_pNodes = realloc ( H -> m_pNodes , H -> m_iCapacity ) ;
	}
}

int HEAP_GetParent ( int iIndex )									// Get parent of iIndex Node
{
	return ( iIndex - 1 ) / 2 ;
}

int HEAP_GetLeftChild ( int iIndex )								// Get left child of iIndex Node
{
	return ( iIndex * 2 ) + 1 ;
}

void HEAP_SwapNodes ( Heap * H , int iIndex1 , int iIndex2 )		// Swap Nodes at iIndex1 & iIndex2
{
	Node Data1 = H -> m_pNodes [ iIndex1 ] ;
	Node Data2 = H -> m_pNodes [ iIndex2 ] ;



	H -> m_pNodes [ iIndex2 ] = Data1 ;
	H -> m_pNodes [ iIndex1 ] = Data2 ;
}

void HEAP_PrintNodes ( Heap * H )									// Print Heap
{
	for ( int i = 0 ; i < H -> m_iUsedSize ; ++i )
	{
		printf ( "%d " , H -> m_pNodes [ i ].m_Data ) ;
	}


	printf ( "\n" ) ;
}