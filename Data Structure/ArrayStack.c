#include "ArrayStack.h"

void AS_CreateStack ( ArrayStack ** pArrayStack , int iCapacity )										// Create stack with array
{
	* pArrayStack = ( ArrayStack * ) malloc ( sizeof ( pArrayStack ) ) ;
	( * pArrayStack ) -> m_iCapacity = iCapacity ;
	( * pArrayStack ) -> m_rgData = ( T * ) malloc ( sizeof ( T ) * iCapacity ) ;
}


void AS_DestroyStack ( ArrayStack ** pArrayStack )														// Destroy stack
{
	free ( ( * pArrayStack ) -> m_rgData ) ;
	free ( * pArrayStack ) ;
}

void AS_Push ( ArrayStack ** pArrayStack , T Data )														// Push T data into stack
{
	AS_ExpandIfFull ( pArrayStack ) ;

	( * pArrayStack ) -> m_rgData [ ( * pArrayStack ) -> m_iCnt ++ ] = Data ;					// Use postfix to use short code
}

void AS_ExpandIfFull ( ArrayStack ** pArrayStack )														// Expand array if array is full
{
	if ( ( * pArrayStack ) -> m_iCnt == ( * pArrayStack ) -> m_iCapacity )
	{
		( * pArrayStack ) -> m_iCapacity *= 2 ;
		( * pArrayStack ) -> m_rgData = ( T * ) realloc ( ( * pArrayStack ) -> m_rgData , ( * pArrayStack ) -> m_iCapacity ) ;
	}
}

T AS_Pop ( ArrayStack ** pArrayStack )																	// Pop T
{
	T Data = ( * pArrayStack ) -> m_rgData [ ( * pArrayStack ) -> m_iCnt - 1 ] ;



	-- ( * pArrayStack ) -> m_iCnt ;

	AS_ReduceIfSmall ( pArrayStack ) ;


	return Data ;
}

void AS_ReduceIfSmall ( ArrayStack ** pArrayStack )														// Reduce array if m_iCnt * 2 <= m_iCapacity
{
	if ( ( ( * pArrayStack ) -> m_iCnt * 2 <= ( * pArrayStack ) -> m_iCapacity )
		&& ( ( * pArrayStack ) -> m_iCapacity != ( * pArrayStack ) -> m_iMinCapacity ) )		// m_iCnt *2 <= m_iCapacity AND m_iCapacity != m_iMinCapacity
	{
		( * pArrayStack ) -> m_iCapacity /= 2 ;
		( * pArrayStack ) -> m_rgData = ( T * ) realloc ( ( * pArrayStack ) -> m_rgData , ( * pArrayStack ) -> m_iCapacity ) ;
	}
}

int AS_GetSize ( ArrayStack * pArrayStack )																// Return current stack size
{
	return pArrayStack -> m_iCnt ;
}

bool AS_IsEmpty ( ArrayStack * pArrayStack )															// Return true if empty
{
	if ( 0 == pArrayStack -> m_iCnt )
		return true ;
	else
		return false ;
}