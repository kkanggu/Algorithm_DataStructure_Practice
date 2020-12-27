#include "BinarySearchTree.h"

BSTNode * BST_CreateNode ( T Data )												// Create BT Node and return it
{
	BSTNode * pNode = ( BSTNode * ) malloc ( sizeof ( BSTNode ) ) ;



	pNode -> m_Data = Data ;
	pNode -> m_pLeft = NULL ;
	pNode -> m_pRight = NULL ;


	return pNode ;
}

void BST_DestroyNode ( BSTNode * pNode )										// Destroy BT Node
{
	free ( pNode ) ;
}

void BST_DestroyTree ( BSTNode * pRoot )										// Destroy tree from Root to Leaf
{
	if ( NULL != pRoot )
	{
		BST_DestroyTree ( pRoot -> m_pLeft ) ;
		BST_DestroyTree ( pRoot -> m_pRight ) ;
		BST_DestroyNode ( pRoot ) ;
	}
}

BSTNode * BST_SearchNode ( BSTNode * pRoot , T Data )							// Search BSTNode that have Data
{
	if ( NULL != pRoot )
	{
		if ( Data == pRoot -> m_Data )
		{
			return pRoot ;
		}
		else if ( Data < pRoot -> m_Data )
		{
			BST_SearchNode ( pRoot -> m_pLeft , Data ) ;
		}
		else
		{
			BST_SearchNode ( pRoot -> m_pRight , Data ) ;
		}
	}
	else
	{
		return NULL ;													// Can't find data
	}
}

BSTNode * BST_SearchMinNode ( BSTNode * pRoot )									// Search BSTNode that have min value
{
	BSTNode * pNode = pRoot ;



	if ( NULL == pNode )
	{
		return NULL ;
	}


	while ( NULL != pNode -> m_pLeft )
	{
		pNode = pNode -> m_pRight ;
	}


	return pNode ;
}

void BST_InsertNode ( BSTNode * pRoot , BSTNode * pNode )						// Insert pNode into BST
{
	BSTNode * pSearch ;
	BSTNode * pTemp = pRoot ;



	if ( NULL == pRoot )
	{
		pRoot = pNode ;
	}
	else
	{
		while ( NULL != pTemp )
		{
			pSearch = pTemp ;


			if ( pNode -> m_Data < pSearch -> m_Data )
			{
				pTemp = pSearch -> m_pLeft ;
			}
			else
			{
				pTemp = pSearch -> m_pRight ;
			}
		}


		if ( pNode -> m_Data < pSearch -> m_Data )
		{
			pSearch -> m_pLeft = pNode ;
		}
		else
		{
			pSearch -> m_pRight = pNode ;
		}
	}
}

BSTNode * BST_RemoveNode ( BSTNode * pRoot , BSTNode * pParent , T Data )		// Remove BSTNode with Data
{
	BSTNode * pReturnNode = NULL ;



	if ( NULL != pRoot )
	{
		if ( Data < pRoot -> m_Data )
		{
			pReturnNode = BST_RemoveNode ( pRoot -> m_pLeft , pRoot , Data ) ;
		}
		else if ( Data < pRoot -> m_Data )
		{
			pReturnNode = BST_RemoveNode ( pRoot -> m_pRight , pRoot , Data ) ;
		}
		else															// Find BSTNode have Data
		{
			pReturnNode = pRoot ;


			if ( ( NULL == pRoot -> m_pLeft ) && ( NULL == pRoot -> m_pRight ) )
			{															// No child
				if ( pRoot == pParent -> m_pLeft )
				{
					pParent -> m_pLeft = NULL ;
				}
				else
				{
					pParent -> m_pRight = NULL ;
				}
			}
			else if ( ( NULL != pRoot -> m_pLeft ) && ( NULL != pRoot -> m_pRight ) )
			{															// Two child
				BSTNode * pMinNode = BST_SearchMinNode ( pRoot -> m_pRight ) ;


				pReturnNode = BST_RemoveNode ( pRoot -> m_pRight , pRoot , pMinNode -> m_Data ) ;
				pRoot -> m_Data = pMinNode -> m_Data ;
			}
			else
			{															// One child
				BSTNode * pTemp ;


				if ( NULL != pRoot -> m_pLeft )
					pTemp = pRoot -> m_pLeft ;
				else
					pTemp = pRoot -> m_pRight ;

				if ( pRoot == pParent -> m_pLeft )
					pParent -> m_pLeft = pTemp ;
				else
					pParent -> m_pRight = pTemp ;
			}
		}


		return pReturnNode ;
	}
	else
	{
		return NULL ;
	}
}

void BST_InorderPrintTree ( BSTNode * pRoot )									// Print tree with inorder
{
	if ( NULL != pRoot -> m_pLeft )
	{
		BST_InorderPrintTree ( pRoot -> m_pLeft ) ;
	}


	printf ( "%d " , pRoot -> m_Data ) ;


	if ( NULL != pRoot -> m_pRight )
	{
		BST_InorderPrintTree ( pRoot -> m_pRight ) ;
	}
}