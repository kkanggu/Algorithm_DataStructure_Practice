#include "LinkedListStack.h"

void LLS_CreateStack ( LinkedListStack ** pLinkedListStack )							// Create stack with LinkedList
{
	* pLinkedListStack = ( LinkedListStack * ) malloc ( sizeof ( LinkedListStack ) ) ;
}

void LLS_DestroyStack ( LinkedListStack ** pLinkedListStack )							// Destroy stack
{
	Node * pNode = ( * pLinkedListStack ) -> m_pHead ;



	while ( NULL != pNode )
	{
		pNode = pNode -> m_pNext ;
		LLS_DestroyNode ( ( * pLinkedListStack ) -> m_pHead ) ;
		( * pLinkedListStack ) -> m_pHead = pNode ;
	}


	free ( pLinkedListStack ) ;
}

Node * LLS_CreateNode ( T Data )														// Create Node with T Data
{
	Node * pNode = ( Node * ) malloc ( sizeof ( Node ) ) ;



	pNode -> m_Data = Data ;
	pNode -> m_pNext = NULL ;

	
	return pNode ;
}

void LLS_DestroyNode ( Node * pNode )													// Destroy Node
{
	free ( pNode ) ;
}

void LLS_Push ( LinkedListStack ** pLinkedListStack , T Data )							// Push Node into stack
{
	Node * pNode = LLS_CreateNode ( Data ) ;



	if ( LLS_IsEmpty ( * pLinkedListStack ) )
	{
		( * pLinkedListStack ) -> m_pHead = pNode ;
		( * pLinkedListStack ) -> m_pTail = pNode ;
	}
	else
	{
		( * pLinkedListStack ) -> m_pTail -> m_pNext = pNode ;
		( * pLinkedListStack ) -> m_pTail = pNode ;
	}


	++ ( * pLinkedListStack ) -> m_iCnt ;
}

Node * LLS_Pop ( LinkedListStack ** pLinkedListStack )									// Pop Node
{
	Node * pNode = ( * pLinkedListStack ) -> m_pHead ;



	if ( pNode == ( * pLinkedListStack ) -> m_pTail )							// Only one Node
	{
		( * pLinkedListStack ) -> m_pHead = NULL ;
		( * pLinkedListStack ) -> m_pTail = NULL ;
	}
	else
	{
		while ( ( * pLinkedListStack ) -> m_pTail != pNode -> m_pNext )			// After this while loop
		{																		// pNode -> m_pTail -> NULL
			pNode = pNode -> m_pNext ;
		}


		( * pLinkedListStack ) -> m_pTail = pNode ;
		pNode = pNode -> m_pNext ;
	}


	-- ( * pLinkedListStack ) -> m_iCnt ;


	return pNode ;
}

Node * LLS_Top ( LinkedListStack * pLinkedListStack )									// Return top, m_pTail
{
	return pLinkedListStack -> m_pTail ;
}

int LLS_GetSize ( LinkedListStack * pLinkedListStack )									// Return current stack size
{
	return pLinkedListStack -> m_iCnt ;
}

bool LLS_IsEmpty ( LinkedListStack * pLinkedListStack )									// Return true if empty
{
	if ( NULL == pLinkedListStack -> m_pHead )
		return true ;
	else
		return false ;
}