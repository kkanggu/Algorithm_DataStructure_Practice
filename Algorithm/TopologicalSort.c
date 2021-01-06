#include "TopologicalSort.h"

void TopologicalSort ( Vertex * V , Node ** LinkedList )						// Sort topological
{
	while ( NULL != V && ! V -> m_bVisit )
	{
		TS_DFS ( V , LinkedList ) ;

		V = V -> m_pNext ;
	}
}

void TS_DFS ( Vertex * V , Node ** LinkedList )									// TS with DFS
{
	Node * NewHead = NULL ;
	Edge * E = NULL ;



	V -> m_bVisit = true ;
	E = V -> m_pAdjacencyList ;


	while ( NULL != E)
	{
		if ( ( NULL != E -> m_pTarget ) && ( ! E -> m_pTarget -> m_bVisit ) )
			TS_DFS ( E -> m_pTarget , LinkedList ) ;


		E = E -> m_pNext ;
	}

	printf ( "%d\n" , V -> m_Data ) ;

	NewHead = SLL_CreateNode ( V ) ;
	SLL_InsertNewHead ( LinkedList , & NewHead ) ;
}