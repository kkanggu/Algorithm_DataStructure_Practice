#include "SingleLinkedList.h"

LinkedList * SLL_CreateLinkedList ()								// Create LinkedList struct
{
	LinkedList * pLinkedList = ( LinkedList * ) malloc ( sizeof ( pLinkedList ) ) ;



	pLinkedList -> m_iCnt = 0 ;
	pLinkedList -> m_pHead = NULL ;


	return pLinkedList ;
}

void SLL_DestroyLinkedList ( LinkedList ** pLinkedList )									// Destroy LinkedList struct
{
	Node * pNode = ( * pLinkedList ) -> m_pHead ;



	while ( NULL != pNode )
	{
		pNode = pNode -> m_pNext ;
		free ( ( * pLinkedList ) -> m_pHead ) ;
		( * pLinkedList ) -> m_pHead = pNode ;
	}


	free ( * pLinkedList ) ;
}

Node * SLL_CreateNode ( V Data )															// Add new Node with data, type T
{
	Node * pNewNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNewNode -> m_Data = Data ;
	pNewNode -> m_pNext = NULL ;


	return pNewNode ;
}

void SLL_DestroyNode ( Node * pNode )														// Destroy pNode
{
	free ( pNode ) ;
}

void SLL_AppendNode ( LinkedList ** pLinkedList , Node * pNewNode )							// Add New Node
{
	if ( NULL == ( * pLinkedList ) -> m_pHead )												// If Empty
	{
		( * pLinkedList ) -> m_pHead = pNewNode ;
	}
	else
	{
		Node * pTail = ( * pLinkedList ) -> m_pHead ;



		while ( NULL != pTail -> m_pNext )
		{
			pTail = pTail -> m_pNext ;
		}


		pTail -> m_pNext = pNewNode ;
		++ ( * pLinkedList ) -> m_iCnt ;
	}
}

void SLL_InsertNode ( LinkedList ** pLinkedList , Node * pCurrent , Node * pNewNode )		// Inser pNewNode after pCurrent, pCurrent -> pNewNode
{
	pCurrent -> m_pNext = pNewNode ;

	if ( NULL != pCurrent -> m_pNext )												// pCurrent -> pAfter
	{
		Node * pAfter = pCurrent -> m_pNext ;


		
		pNewNode -> m_pNext = pAfter ;
		++ ( * pLinkedList ) -> m_iCnt ;
	}
}

void SLL_RemoveNode ( LinkedList ** pLinkedList , Node * pRemove )							// Remove pRemove
{
	Node * pDetection = NULL ;
	Node * pTemp = NULL ;



	if ( NULL != ( * pLinkedList ) -> m_pHead )
	{
		pDetection = ( * pLinkedList ) -> m_pHead ;
	}

	while ( ( NULL != pDetection ) && ( pRemove != pDetection ) )
	{
		pTemp = pDetection ;
		pDetection = pDetection -> m_pNext ;
	}

	if ( NULL != pDetection )														// Find pRemove, pTemp -> pDetection
	{
		pTemp -> m_pNext = pDetection -> m_pNext ;
		SLL_DestroyNode ( pDetection ) ;
		-- ( * pLinkedList ) -> m_iCnt ;
	}
}

Node * SLL_GetNodeAt ( LinkedList * pLinkedList , int iPosition )							// Get Node of iPosition
{
	if ( pLinkedList -> m_iCnt > iPosition )										// If not overflow
	{
		Node * pDetection = pLinkedList -> m_pHead ;


		for ( int i = 0 ; i < iPosition ; ++i )
		{
			pDetection = pDetection -> m_pNext ;
		}



		return pDetection ;
	}
}

void SLL_InsertNewHead ( LinkedList * pLinkedList , Node ** pNewHead )						// Add pNewHead to Head
{
	( * pNewHead ) -> m_pNext = pLinkedList -> m_pHead ;
	pLinkedList -> m_pHead = * pNewHead ;
}