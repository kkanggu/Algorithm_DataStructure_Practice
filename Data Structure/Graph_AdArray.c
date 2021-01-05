#include "Graph_AdArray.h"

Graph * CreateGraph ( int ** iArray , int iCnt )							// Create Graph with Adjacent Array
{
	Graph * G = ( Graph * ) malloc ( sizeof ( Graph ) ) ;
	


	G -> m_iVertexCnt = 0 ;
	G -> m_pVertices = NULL ;


	for ( int i = 0 ; i < iCnt ; ++i )								// Add every vertex first
	{
		AddVertex ( G , CreateVertex ( i ) ) ;
	}
	for ( int i = 0 ; i < iCnt ; ++i )								// At each vertex
	{
		for ( int j = 0 ; j < iCnt ; ++j )							// Edge loop
		{
			if ( ( -1 != iArray [ i ] [ j ] )						// Path exist, -1 mean no path
				&& ( i != j ) )										// Ignore same vertex
			{
				AddEdge ( FindVertex ( G , i ) , CreateEdge ( FindVertex ( G , i ) , FindVertex ( G , j ) , iArray [ i ] [ j ] ) ) ;
			}
		}
	}


	return G ;
}

void DestroyGraph ( Graph * G )												// Destroy Graph
{
	Vertex * V = G -> m_pVertices ;
	Edge * E = G -> m_pVertices -> m_pAdjacencyList ;
	


	while ( NULL != V )
	{
		while ( NULL != E )
		{
			E = E -> m_pNext ;
			DestroyEdge ( G -> m_pVertices -> m_pAdjacencyList ) ;
			G -> m_pVertices -> m_pAdjacencyList = E ;
		}


		V = V -> m_pNext ;
		DestroyVertex ( G -> m_pVertices ) ;
		G -> m_pVertices = V ;
	}


	free ( G ) ;
}

Vertex * CreateVertex ( T Data )											// Create Vertex with T Data and return
{
	Vertex * V = ( Vertex * ) malloc ( sizeof ( Vertex ) ) ;



	V -> m_Data = Data ;
	V -> m_bVisit = false ;
	V -> m_iIndex = 0 ;
	V -> m_pNext = NULL ;
	V -> m_pAdjacencyList = NULL ;


	return V ;
}

void DestroyVertex ( Vertex * V )											// Destroy Vertex
{
	free ( V ) ;
}

Edge * CreateEdge ( Vertex * pFrom , Vertex * pTarget , int iWeight )		// Create Edge and return
{
	Edge * E = ( Edge * ) malloc ( sizeof ( Edge ) ) ;



	E -> m_iWeight = iWeight ;
	E -> m_pNext = NULL ;
	E -> m_pFrom = pFrom ;
	E -> m_pTarget = pTarget ;


	return E ;
}

void DestroyEdge ( Edge * E )												// Destroy Edge
{
	free ( E ) ;
}

void AddVertex ( Graph * G , Vertex * V )									// Add Vertex V into Graph G
{
	if ( NULL == G -> m_pVertices )
	{
		G -> m_pVertices = V ;
	}
	else
	{
		Vertex * pTemp = G -> m_pVertices ;


		while ( NULL != pTemp -> m_pNext )
		{
			pTemp = pTemp -> m_pNext ;
		}


		pTemp -> m_pNext = V ;
	}


	V -> m_iIndex = G -> m_iVertexCnt ++ ;							// Set to 0 and use postfix to ++
}

void AddEdge ( Vertex * V , Edge * E )										// Add Edge E connected with Vertex V
{
	if ( NULL == V -> m_pAdjacencyList )
	{
		V -> m_pAdjacencyList = E ;
	}
	else
	{
		Edge * pTemp = V -> m_pAdjacencyList ;


		while ( NULL != pTemp -> m_pNext )
		{
			pTemp = pTemp -> m_pNext ;
		}


		pTemp -> m_pNext = E ;
	}
}

void PrintGraph ( Graph * G )												// Print current Graph G
{
	Vertex * V = G -> m_pVertices ;
	Edge * E = V -> m_pAdjacencyList ;



	while ( NULL != V )
	{
		printf ( "Vertex %d :" , V -> m_iIndex ) ;


		while ( NULL != E )
		{
			printf ( " %d[%d]" , E -> m_pTarget -> m_iIndex , E -> m_iWeight ) ;

			E = E -> m_pNext ;
		}


		printf ( "\n" ) ;

		V = V -> m_pNext ;
		E = V -> m_pAdjacencyList ;
	}
}

Vertex * FindVertex ( Graph * G , int iIndex )								// Find vertex with index iIndex
{
	Vertex * V = G -> m_pVertices ;



	while ( NULL != V )
	{
		if ( iIndex == V -> m_iIndex )
			break ;


		V = V -> m_pNext ;
	}


	return V ;
}