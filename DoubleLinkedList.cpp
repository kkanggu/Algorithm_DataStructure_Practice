#include "DoubleLinkedList.h"

Node * DLL_CreateNode ( T Data )												// Add new Node with data, type T
{
	Node * pNewNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNewNode -> m_Data = Data ;
	pNewNode -> m_pPrev = NULL ;
	pNewNode -> m_pNext = NULL ;


	return pNewNode ;
}

void DLL_DestroyNode ( Node * pNode )											// Destroy pNode
{
	free ( pNode ) ;
}

void DLL_AppendNode ( Node ** pHead , Node * pNewNode )							// Add New Node
{
	if ( NULL == pHead )						// If Empty
	{
		* pHead = pNewNode ;
	}
	else
	{
		Node * pTail = * pHead ;



		while ( NULL != pTail -> m_pNext )
		{
			pTail = pTail -> m_pNext ;
		}


		pTail -> m_pNext = pNewNode ;
		pNewNode -> m_pPrev = pTail ;
		++ ( * pHead ) -> m_iCnt ;
	}
}

void DLL_InsertNode ( Node * pHead , Node * pCurrent , Node * pNewNode )		// Inser pNewNode after pCurrent, pCurrent -> pNewNode
{
	pCurrent -> m_pNext = pNewNode ;
	pNewNode -> m_pPrev = pCurrent ;
	++ pHead -> m_iCnt ;

	if ( NULL != pCurrent -> m_pNext )			// pCurrent -> pAfter
	{
		Node * pAfter = pCurrent -> m_pNext ;


		
		pAfter -> m_pPrev = pNewNode ;
		pNewNode -> m_pNext = pAfter ;
		++ pHead -> m_iCnt ;
	}
}

void DLL_RemoveNode ( Node ** pHead , Node * pRemove )							// Remove pRemove
{
	Node * pDetection ;
	Node * pTemp ;



	if ( NULL != * pHead )
	{
		pDetection = * pHead ;
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
		free ( pDetection ) ;
		-- ( * pHead ) -> m_iCnt ;
	}
}

Node * DLL_GetNodeAt ( Node * pHead , int iPosition )							// Get Node of iPosition
{
	if ( pHead -> m_iCnt > iPosition )				// If not overflow
	{
		Node * pDetection = pHead ;


		for ( int i = 0 ; i < iPosition ; ++i )
		{
			pDetection = pDetection -> m_pNext ;
		}



		return pDetection ;
	}
}