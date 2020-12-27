#include "BinaryTree.h"

BTNode * BT_CreateNode ( T Data )						// Create BT Node and return it
{
	BTNode * pNode = ( BTNode * ) malloc ( sizeof ( BTNode ) ) ;



	pNode -> m_Data = Data ;
	pNode -> m_pLeft = NULL ;
	pNode -> m_pRight = NULL ;


	return pNode ;
}

void BT_DestroyNode ( BTNode * pNode )					// Destroy BT Node
{
	free ( pNode ) ;
}

void BT_DestroyTree ( BTNode * pRoot )					// Destroy tree from Root to Leaf
{
	if ( NULL != pRoot -> m_pLeft )
	{
		BT_DestroyTree ( pRoot -> m_pLeft ) ;
	}
	if ( NULL != pRoot -> m_pRight )
	{
		BT_DestroyTree ( pRoot -> m_pRight ) ;
	}


	BT_DestroyNode ( pRoot ) ;
}

void BT_PreorderPrintTree ( BTNode * pRoot )			// Print tree with preorder
{
	printf ( "%d " , pRoot -> m_Data ) ;


	if ( NULL != pRoot -> m_pLeft )
	{
		BT_PreorderPrintTree ( pRoot -> m_pLeft ) ;
	}
	if ( NULL != pRoot -> m_pRight )
	{
		BT_PreorderPrintTree ( pRoot -> m_pRight ) ;
	}
}

void BT_InorderPrintTree ( BTNode * pRoot )				// Print tree with inorder
{
	if ( NULL != pRoot -> m_pLeft )
	{
		BT_InorderPrintTree ( pRoot -> m_pLeft ) ;
	}


	printf ( "%d " , pRoot -> m_Data ) ;


	if ( NULL != pRoot -> m_pRight )
	{
		BT_InorderPrintTree ( pRoot -> m_pRight ) ;
	}
}

void BT_PostorderPrintTree ( BTNode * pRoot )			// Print tree with postorder
{
	if ( NULL != pRoot -> m_pLeft )
	{
		BT_PostorderPrintTree ( pRoot -> m_pLeft ) ;
	}
	if ( NULL != pRoot -> m_pRight )
	{
		BT_PostorderPrintTree ( pRoot -> m_pRight ) ;
	}


	printf ( "%d " , pRoot -> m_Data ) ;
}