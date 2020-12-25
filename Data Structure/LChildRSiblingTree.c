#include "LChildRSiblingTree.h"

LCRSNode * LCRS_CreateNode ( T Data )											// Create LCRS Node and return it
{
	LCRSNode * pNode = ( LCRSNode * ) malloc ( sizeof ( LCRSNode ) ) ;



	pNode -> m_Data = Data ;
	pNode -> m_pLeftChild = NULL ;
	pNode -> m_pRightSIbling = NULL ;


	return pNode ;
}

void LCRS_DestroyNode ( LCRSNode * pNode )										// Destroy LCRS Node
{
	free ( pNode ) ;
}

void LCRS_DestroyTree ( LCRSNode * pRoot )										// Destroy tree from Root to Leaf
{
	if ( NULL != pRoot -> m_pLeftChild )
	{
		LCRS_DestroyTree ( pRoot -> m_pLeftChild ) ;
	}
	if ( NULL != pRoot -> m_pRightSIbling )
	{
		LCRS_DestroyTree ( pRoot -> m_pRightSIbling ) ;
	}


	LCRS_DestroyNode ( pRoot ) ;
}

void LCRS_AddChildNode ( LCRSNode * pParentNode , LCRSNode * pChildNode )		// Add child Node
{
	if ( NULL == pParentNode -> m_pLeftChild )
	{
		pParentNode -> m_pLeftChild = pChildNode ;
	}
	else																// Already have child
	{
		LCRSNode * pTemp = pParentNode -> m_pLeftChild ;



		while ( NULL != pTemp -> m_pRightSIbling )
		{
			pTemp = pTemp -> m_pRightSIbling ;
		}


		pTemp -> m_pRightSIbling = pChildNode ;
	}
}

void LCRS_PrintTree ( LCRSNode * pRoot , int iDepth )							// Print tree like file explorer in Window
{
	for ( int i = 0 ; i < iDepth ; ++i )
	{
		printf ( "\t" ) ;
	}


	printf ( "%d\n" , pRoot -> m_Data ) ;									// Now T is int. If type is different, use another option or suitable function.


	if ( NULL != pRoot -> m_pLeftChild )
	{
		LCRS_PrintTree ( pRoot -> m_pLeftChild , iDepth + 1 ) ;
	}
	if ( NULL != pRoot -> m_pRightSIbling )
	{
		LCRS_PrintTree ( pRoot -> m_pRightSIbling , iDepth ) ;
	}	
}