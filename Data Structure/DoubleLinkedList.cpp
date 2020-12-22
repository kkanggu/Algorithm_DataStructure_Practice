#include "DoubleLinkedList.h"

LinkedList * DLL_CreateLinkedList ( LinkedList ** pLinkedList )					// Create LinkedList struct
{
	* pLinkedList = ( LinkedList * ) malloc ( sizeof ( pLinkedList ) ) ;
	( * pLinkedList ) -> m_iCnt = 0 ;
}

void DLL_DestroyLinkedList ( LinkedList ** pLinkedList )							// Destroy LinkedList struct
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

Node * DLL_CreateNode ( T Data )															// Add new Node with data, type T
{
	Node * pNewNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNewNode -> m_Data = Data ;
	pNewNode -> m_pPrev = NULL ;
	pNewNode -> m_pNext = NULL ;


	return pNewNode ;
}

void DLL_DestroyNode ( Node * pNode )														// Destroy pNode
{
	free ( pNode ) ;
}

void DLL_AppendNode ( LinkedList ** pLinkedList , Node * pNewNode )							// Add New Node
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
		pNewNode -> m_pPrev = pTail ;
		++ ( * pLinkedList ) -> m_iCnt ;
	}
}

void DLL_InsertNode ( LinkedList ** pLinkedList , Node * pCurrent , Node * pNewNode )		// Inser pNewNode after pCurrent, pCurrent -> pNewNode
{
	pCurrent -> m_pNext = pNewNode ;
	pNewNode -> m_pPrev = pCurrent ;

	if ( NULL != pCurrent -> m_pNext )			// pCurrent -> pAfter
	{
		Node * pAfter = pCurrent -> m_pNext ;


		
		pAfter -> m_pPrev = pNewNode ;
		pNewNode -> m_pNext = pAfter ;
		++ ( * pLinkedList ) -> m_iCnt ;
	}
}

void DLL_RemoveNode ( LinkedList ** pLinkedList , Node * pRemove )							// Remove pRemove
{
	Node * pDetection ;
	Node * pTemp ;



	if ( NULL != ( * pLinkedList ) -> m_pHead )
	{
		pDetection = ( * pLinkedList ) -> m_pHead ;
	}

	while ( ( NULL != pDetection ) && ( pRemove != pDetection ) )
	{
		pTemp = pDetection ;
		pDetection = pDetection -> m_pNext ;
	}

	if ( NULL != pDetection )						// Find pRemove, pTemp -> pDetection
	{
		if ( NULL != pDetection -> m_pNext )		// If pDetection is not Tail
			pDetection -> m_pNext -> m_pPrev = pTemp ;

		pTemp -> m_pNext = pDetection -> m_pNext ;
		DLL_DestroyNode ( pDetection ) ;
		-- ( * pLinkedList ) -> m_iCnt ;
	}
}

Node * DLL_GetNodeAt ( LinkedList * pLinkedList , int iPosition )							// Get Node of iPosition
{
	if ( pLinkedList -> m_iCnt > iPosition )				// If not overflow
	{
		Node * pDetection = pLinkedList -> m_pHead ;


		for ( int i = 0 ; i < iPosition ; ++i )
		{
			pDetection = pDetection -> m_pNext ;
		}



		return pDetection ;
	}
}