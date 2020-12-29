#include "RedBlackTree.h"

RBTNode * NIL ;

RBTNode * RBT_CreateNode ( T Data )												// Create RBT Node and return it
{
	RBTNode * pNode = ( RBTNode * ) malloc ( sizeof ( RBTNode ) ) ;



	pNode -> COLOR = RED ;
	pNode -> m_Data = Data ;
	pNode -> m_pLeft = NIL ;
	pNode -> m_pRight = NIL ;
	pNode -> m_pParent = NULL ;


	return pNode ;
}

void RBT_DestroyNode ( RBTNode * pNode ) 										// Destroy RBT Node
{
	free ( pNode ) ;
}

void RBT_DestroyTree ( RBTNode * pRoot ) 										// Destroy tree from Root to Leaf
{
	if ( NIL != pRoot -> m_pLeft )
		RBT_DestroyTree ( pRoot -> m_pLeft ) ;
	if ( NIL != pRoot -> m_pRight )
		RBT_DestroyTree ( pRoot -> m_pRight ) ;
	

	RBT_DestroyNode ( pRoot ) ;	
}

RBTNode * RBT_SearchNode ( RBTNode * pRoot , T Data ) 							// Search RBTNode that have Data
{
	if ( NIL != pRoot )
	{
		if ( Data == pRoot -> m_Data )
		{
			return pRoot ;
		}
		else if ( Data < pRoot -> m_Data )
		{
			RBT_SearchNode ( pRoot -> m_pLeft , Data ) ;
		}
		else
		{
			RBT_SearchNode ( pRoot -> m_pRight , Data ) ;
		}
	}
	else
	{
		return NULL ;													// Can't find data
	}
}

RBTNode * RBT_SearchMinNode ( RBTNode * pRoot )									// Search RBTNode that have min value
{
	RBTNode * pNode = pRoot ;



	if ( NIL == pNode )
	{
		return NIL ;
	}


	while ( NIL != pNode -> m_pLeft )
	{
		pNode = pNode -> m_pLeft ;
	}


	return pNode ;
}

void RBT_InsertNode ( RBTNode ** pRoot , RBTNode * pNode )						// Insert pNode into RBT
{
	RBTNode * pSearch = * pRoot ;
	RBTNode * pTemp = * pRoot ;



	if ( NIL == * pRoot )
	{
		* pRoot = pNode ;
	}
	else
	{
		while ( NIL != pTemp )
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
			pNode -> m_pParent = pSearch ;
		}
		else
		{
			pSearch -> m_pRight = pNode ;
			pNode -> m_pParent = pSearch ;
		}
	}

	RBT_RebuildAfterInsert ( pRoot , pNode ) ;
}

RBTNode * RBT_RemoveNode ( RBTNode ** pRoot , T Data )							// Remove RBTNode with Data
{
	RBTNode * pRemoveNode = NULL ;
	RBTNode * pTarget = RBT_SearchNode ( * pRoot , Data ) ;
	RBTNode * pSuccessor = NULL ;



	if ( NULL == pTarget )
	{
		return NULL ;
	}
	
	if ( ( NIL == pTarget -> m_pLeft ) || ( NIL == pTarget -> m_pRight ) )
	{																				// Has NILL
		pRemoveNode = pTarget ;
	}
	else
	{																				// No Nil, two child
		pRemoveNode = RBT_SearchMinNode ( pTarget -> m_pRight ) ;
		pTarget -> m_Data = pRemoveNode -> m_Data ;
		pSuccessor = pRemoveNode ;
	}


	if ( NIL != pRemoveNode -> m_pLeft )
		pSuccessor = pRemoveNode -> m_pLeft ;
	else
		pSuccessor = pRemoveNode -> m_pRight ;

	pSuccessor -> m_pParent = pRemoveNode -> m_pParent ;


	if ( NULL == pRemoveNode -> m_pParent )
		* pRoot = pSuccessor ;
	else
	{
		if ( pRemoveNode == pRemoveNode -> m_pParent -> m_pLeft )
			pRemoveNode -> m_pParent -> m_pLeft = pSuccessor ;
		else
			pRemoveNode -> m_pParent -> m_pRight = pSuccessor ;
	}
		
	if ( BLACK == pRemoveNode -> COLOR )
		RBT_RebuildAfterRemove ( pRoot , pSuccessor ) ;


	return pRemoveNode ;
}

void RBT_RebuildAfterInsert ( RBTNode ** pRoot , RBTNode * pNode )				// After insert, rebuild to rule
{
	while ( ( * pRoot != pNode ) && ( RED == pNode -> m_pParent -> COLOR ) )
	{
		if ( * pRoot == pNode -> m_pParent )
		{
			if ( RED == pNode -> m_pParent -> COLOR )
				pNode -> m_pParent -> COLOR = BLACK ;
		}
		else if ( pNode -> m_pParent == pNode -> m_pParent -> m_pParent -> m_pLeft )			// Left Parent
		{
			if ( RED == pNode -> m_pParent -> m_pParent -> m_pRight -> COLOR )					// Uncle is RED
			{
				pNode -> m_pParent -> m_pParent -> m_pRight -> COLOR = BLACK ;
				pNode -> m_pParent -> COLOR = BLACK ;
				pNode -> m_pParent -> m_pParent -> COLOR = RED ;

				pNode = pNode -> m_pParent -> m_pParent ;
			}
			else																				// Uncle BLACK
			{
				if ( pNode == pNode -> m_pParent -> m_pRight )									// pNode is RIGHT child of parent
				{
					pNode = pNode -> m_pParent ;
					RBT_RotateLeft ( pRoot , pNode ) ;
				}

				
				pNode -> m_pParent -> COLOR = BLACK ;
				pNode -> m_pParent -> m_pParent -> COLOR = RED ;
				RBT_RotateRight ( pRoot , pNode -> m_pParent -> m_pParent ) ;
			}
		}
		else																				// Right Parent
		{
			if ( RED == pNode -> m_pParent -> m_pParent -> m_pLeft -> COLOR )					// Uncle is RED
			{
				pNode -> m_pParent -> m_pParent -> m_pLeft -> COLOR = BLACK ;
				pNode -> m_pParent -> COLOR = BLACK ;
				pNode -> m_pParent -> m_pParent -> COLOR = RED ;

				pNode = pNode -> m_pParent -> m_pParent ;
			}
			else																				// Uncle BLACK
			{
				if ( pNode == pNode -> m_pParent -> m_pLeft )									// pNode is RIGHT child of parent
				{
					pNode = pNode -> m_pParent ;
					RBT_RotateRight ( pRoot , pNode ) ;
				}

				
				pNode -> m_pParent -> COLOR = BLACK ;
				pNode -> m_pParent -> m_pParent -> COLOR = RED ;
				RBT_RotateLeft ( pRoot , pNode -> m_pParent -> m_pParent ) ;
			}
		}
	}
}

void RBT_RebuildAfterRemove ( RBTNode ** pRoot , RBTNode * pSuccessor )			// After remove, rebuild to rule
{
	RBTNode * pSibling = NULL ;


	while ( ( NULL != pSuccessor -> m_pParent ) && ( BLACK == pSuccessor -> COLOR ) )
	{																			// At left
		if ( pSuccessor == pSuccessor -> m_pParent -> m_pLeft )
		{
			pSibling = pSuccessor -> m_pParent -> m_pRight ;


			if ( RED == pSibling -> COLOR )										// Sibling is RED
			{
				pSibling -> COLOR = BLACK ;
				pSuccessor -> m_pParent -> COLOR = RED ;
				RBT_RotateLeft ( pRoot , pSuccessor -> m_pParent ) ;
			}
			else																// Sibling is BLACK
			{
				if ( ( BLACK == pSibling -> m_pLeft -> COLOR )					// All BLACK
					&& ( BLACK == pSibling -> m_pRight -> COLOR ) )
				{
					pSibling -> COLOR = RED ;
					pSuccessor = pSuccessor -> m_pParent ;
				}
				else
				{
					if ( RED == pSibling -> m_pLeft -> COLOR )					// Left is RED
					{
						pSibling -> m_pLeft -> COLOR = BLACK ;
						pSibling -> COLOR = RED ;

						RBT_RotateRight ( pRoot , pSibling ) ;
						pSibling = pSuccessor -> m_pParent -> m_pRight ;
					}


					pSibling -> COLOR = pSuccessor -> m_pParent -> COLOR ;		// Right is RED
					pSuccessor -> m_pParent -> COLOR = BLACK ;
					pSibling -> m_pRight -> COLOR = BLACK ;
					RBT_RotateLeft ( pRoot , pSuccessor -> m_pParent ) ;
					pSuccessor = * pRoot ;
				}
			}
		}
		else																	// At right
		{
			pSibling = pSuccessor -> m_pParent -> m_pLeft ;


			if ( RED == pSibling -> COLOR )										// Sibling is RED
			{
				pSibling -> COLOR = BLACK ;
				pSuccessor -> m_pParent -> COLOR = RED ;
				RBT_RotateLeft ( pRoot , pSuccessor -> m_pParent ) ;
			}
			else																// Sibling is BLACK
			{
				if ( ( BLACK == pSibling -> m_pLeft -> COLOR )					// All BLACK
					&& ( BLACK == pSibling -> m_pRight -> COLOR ) )
				{
					pSibling -> COLOR = RED ;
					pSuccessor = pSuccessor -> m_pParent ;
				}
				else
				{
					if ( RED == pSibling -> m_pRight -> COLOR )					// Right is RED
					{
						pSibling -> m_pRight -> COLOR = BLACK ;
						pSibling -> COLOR = RED ;

						RBT_RotateLeft ( pRoot , pSibling ) ;
						pSibling = pSuccessor -> m_pParent -> m_pLeft ;
					}


					pSibling -> COLOR = pSuccessor -> m_pParent -> COLOR ;		// Left is RED
					pSuccessor -> m_pParent -> COLOR = BLACK ;
					pSibling -> m_pLeft -> COLOR = BLACK ;
					RBT_RotateRight ( pRoot , pSuccessor -> m_pParent ) ;
					pSuccessor = * pRoot ;
				}
			}
		}
	}
}

void RBT_RotateLeft ( RBTNode ** pRoot , RBTNode * pParent )					// Rotate left
{
	RBTNode * pRightChild = pParent -> m_pRight ;



	pParent -> m_pRight = pRightChild -> m_pLeft ;


	if ( NIL != pRightChild -> m_pLeft )
		pRightChild -> m_pLeft -> m_pParent = pParent ;


	pRightChild -> m_pParent = pParent -> m_pParent ;


	if ( NULL == pParent -> m_pParent )
	{
		* pRoot = pRightChild ;
	}
	else
	{
		if ( pParent == pParent -> m_pParent -> m_pLeft )
		{
			pParent -> m_pParent -> m_pLeft = pRightChild ;
		}
		else
		{
			pParent -> m_pParent -> m_pRight = pRightChild ;
		}
	}

	
	pRightChild -> m_pLeft = pParent ;
	pParent -> m_pParent = pRightChild ;
}

void RBT_RotateRight ( RBTNode ** pRoot , RBTNode * pParent )					// Rotate Right
{
	RBTNode * pLeftChild = pParent -> m_pLeft ;



	pParent -> m_pLeft = pLeftChild -> m_pRight ;


	if ( NIL != pLeftChild -> m_pRight )
		pLeftChild -> m_pRight -> m_pParent = pParent ;


	pLeftChild -> m_pParent = pParent -> m_pParent ;


	if ( NULL == pParent -> m_pParent )
	{
		* pRoot = pLeftChild ;
	}
	else
	{
		if ( pParent == pParent -> m_pParent -> m_pLeft )
		{
			pParent -> m_pParent -> m_pLeft = pLeftChild ;
		}
		else
		{
			pParent -> m_pParent -> m_pRight = pLeftChild ;
		}
	}

	
	pLeftChild -> m_pRight = pParent ;
	pParent -> m_pParent = pLeftChild ;
}

void RBT_PrintTree ( RBTNode * pRoot , int iDepth , int iBlackCount )			// print
{
	//int i = 0 ;
	char c = 'X' ;
	int v = -1 ;
	char cnt [ 100 ] ;



	if ( NULL == pRoot || NIL == pRoot )
		return ;

	if ( BLACK == pRoot -> COLOR )
		++ iBlackCount ;

	if ( NULL != pRoot -> m_pParent )
	{
		v = pRoot -> m_pParent -> m_Data ;


		if ( pRoot == pRoot -> m_pParent -> m_pLeft )
			c = 'L' ;
		else
			c = 'R' ;
	}

	if ( ( NIL == pRoot -> m_pLeft ) && ( NIL == pRoot -> m_pRight ) )
		sprintf_s ( cnt , sizeof ( cnt ) , "--------- %d" , iBlackCount ) ;
	else
		sprintf_s ( cnt , sizeof ( cnt ) , "" ) ;

	for ( int i = 0 ; i < iDepth ; ++i )
	{
		printf ( " " ) ;
	}

	printf ( "%d %s [ %c , %d ] %s\n" , pRoot -> m_Data , ( RED == pRoot -> COLOR ) ? "RED" : "BLACK" , c , v , cnt ) ;

	RBT_PrintTree ( pRoot -> m_pLeft , iDepth + 1 , iBlackCount ) ;
	RBT_PrintTree ( pRoot -> m_pRight , iDepth + 1 , iBlackCount ) ;
}