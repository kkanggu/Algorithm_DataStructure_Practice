#include "Graph_AdList.h"

Graph * CreateGraph ()														// Create Graph and return
{
	Graph * G = ( Graph * ) malloc ( sizeof ( Graph ) ) ;



	G -> m_iVertexCnt = 0 ;
	G -> m_pVertices = NULL ;


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
		printf ( "Vertex %d :" , V -> m_Data ) ;

		E = V -> m_pAdjacencyList ;


		while ( NULL != E )
		{
			printf ( " %d[%d]" , E -> m_pTarget -> m_Data , E -> m_iWeight ) ;

			E = E -> m_pNext ;
		}


		printf ( "\n" ) ;

		V = V -> m_pNext ;
	}
}