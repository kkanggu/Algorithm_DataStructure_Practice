#include "CircularQueue.h"

void CQ_CreateQueue ( CircularQueue ** pQueue , int iCapacity )							// Create Circular Queue with array
{
	* pQueue = ( CircularQueue * ) malloc ( sizeof ( CircularQueue ) ) ;



	( * pQueue ) -> m_rgData = ( T * ) malloc ( sizeof ( T ) * ( iCapacity + 1 ) ) ;
	( * pQueue ) -> m_iCapacity = iCapacity ;
	( * pQueue ) -> m_iFront = 0 ;
	( * pQueue ) -> m_iRear = 0 ;
}

void CQ_DestroyQueue ( CircularQueue ** pQueue )										// Destroy Queue
{
	free ( ( * pQueue ) -> m_rgData ) ;
	free ( * pQueue ) ;
}

void CQ_Enqueue ( CircularQueue ** pQueue , T pData )									// Put T into Queue
{
	if ( ! CQ_IsFull ( * pQueue ) )
	{
		( * pQueue ) -> m_rgData [ ( * pQueue ) -> m_iRear ++ ] = pData ;		// Use postfix to use short code


		if ( ( * pQueue ) -> m_iRear == ( * pQueue ) -> m_iCapacity )
		{
			( * pQueue ) -> m_iRear = 0 ;
		}
	}
}

T CQ_Dequeue ( CircularQueue ** pQueue )												// Return T from Queue
{
	T Data = ( * pQueue ) -> m_rgData [ ( * pQueue ) -> m_iFront ++ ] ;			// Use postfix to use short code
	


	if ( ( * pQueue ) -> m_iFront == ( * pQueue ) -> m_iCapacity )
	{
		( * pQueue ) -> m_iFront = 0 ;
	}


	return Data ;
}

int CQ_GetSize ( CircularQueue * pQueue )												// Return count of T (Nodes)
{
	if ( ( pQueue -> m_iFront ) <= ( pQueue -> m_iRear ) )						// Front 3, Rear 6
	{
		return ( pQueue -> m_iRear - pQueue -> m_iFront ) ;
	}
	else																		// Front 6, Rear 3
	{
		return ( pQueue -> m_iCapacity - pQueue -> m_iFront + pQueue -> m_iRear + 1 ) ;
	}
}

bool CQ_IsEmpty ( CircularQueue * pQueue )												// If emptry (No Node), true
{
	if ( ( pQueue -> m_iFront ) == ( pQueue -> m_iRear ) )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

bool CQ_IsFull ( CircularQueue * pQueue )												// If full, true
{
	if ( ( ( pQueue -> m_iRear - pQueue -> m_iFront ) == ( pQueue -> m_iCapacity ) )
		|| ( 1 == ( pQueue -> m_iFront - pQueue -> m_iRear ) ) )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}