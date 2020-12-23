#include "LinkedQueue.h"

void LQ_CreateQueue ( LinkedQueue ** pQueue )						// Create Queue with Linked List
{
	* pQueue = ( LinkedQueue * ) malloc ( sizeof ( LinkedQueue ) ) ;



	( * pQueue ) -> m_iCnt = 0 ;
	( * pQueue ) -> m_pHead = NULL ;
	( * pQueue ) -> m_pTail = NULL ;
}

void LQ_DestroyQueue ( LinkedQueue ** pQueue )						// Destroy Queue and Nodes
{
	Node * pNode = ( * pQueue ) -> m_pHead ;



	while ( NULL != pNode )
	{
		pNode = pNode -> m_pNext ;
		LQ_DestroyNode ( ( * pQueue ) -> m_pHead ) ;
		( * pQueue ) -> m_pHead = pNode ;
	}


	free ( * pQueue ) ;
}

Node * LQ_CreateNode ( T Data )										// Create Node and return it
{
	Node * pNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNode -> m_Data = Data ;
	pNode -> m_pNext = NULL ;


	return pNode ;
}

void LQ_DestroyNode ( Node * pNode )								// Destroy pNode
{
	free ( pNode ) ;
}

void LQ_Enqueue ( LinkedQueue ** pQueue , Node * pNode )			// Enqueue pNode into pQueue
{
	if ( 0 == ( * pQueue ) -> m_iCnt )
	{
		( * pQueue ) -> m_pHead = pNode ;
		( * pQueue ) -> m_pTail = pNode ;
	}
	else
	{
		( * pQueue ) -> m_pTail -> m_pNext = pNode ;
		( * pQueue ) -> m_pTail = pNode ;
	}


	++ ( * pQueue ) -> m_iCnt ;
}

Node * LQ_Dequeue ( LinkedQueue ** pQueue )							// Dequeue Node from pQueue
{
	if ( LQ_IsEmpty ( * pQueue ) )
	{
		Node * pNode = ( * pQueue ) -> m_pHead ;



		( * pQueue ) -> m_pHead = pNode -> m_pNext ;
		-- ( * pQueue ) -> m_iCnt ;


		return pNode ;
	}
	else
	{
		return NULL ;
	}
}

bool LQ_IsEmpty ( LinkedQueue * pQueue )							// If no Node, true
{
	if ( 0 == pQueue -> m_iCnt )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}