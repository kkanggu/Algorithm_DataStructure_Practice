#include "MinimumSpanningTree.h"

void Prim ( Graph * G , Vertex * StartVertex , Graph * MST )							// Prim algorithm
{
	const int iCnt = G -> m_iVertexCnt ;
	int * irgWeight = ( int * ) malloc ( sizeof ( int ) * iCnt ) ;
	bool * bVertexCheck = ( bool * ) malloc ( sizeof ( bool ) * iCnt ) ;
	Vertex * V = G ->m_pVertices ;
	Edge * E ;
	int iMin = MAX_WEIGHT ;
	int iIndex = -1 ;
	Vertex ** VFirstVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** ESelectArray = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;
	Vertex ** VFinalVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** EFinalEdge = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;



	for ( int i = 0 ; i < iCnt ; ++i )											// Initialize
	{
		irgWeight [ i ] = MAX_WEIGHT ;											// Possible weight array
		bVertexCheck [ i ] = false ;											// Used Vertex check
		ESelectArray [ i ] = NULL ;												// Edge * array matching with irgWeight
		VFinalVertex [ i ] = NULL ;												// Final Vertex, use array to easy to access
		EFinalEdge [ i ] = NULL ;												// Final Edge, use array to easy to access
		VFirstVertex [ V -> m_iIndex ] = V ;									// Initial Vertex set, easy to access
		V = V -> m_pNext ;
	}


	V = StartVertex ;
	E = V -> m_pAdjacencyList ;
	irgWeight [ V -> m_iIndex ] = 0 ;
	bVertexCheck [ V -> m_iIndex ] = true ;
	VFinalVertex [ V -> m_iIndex ] = CreateVertex ( V -> m_iIndex ) ;
	AddVertex ( MST , VFinalVertex [ V -> m_iIndex ] ) ;


	while ( iCnt != MST -> m_iVertexCnt )										// while loops iCnt times
	{
		while ( NULL != E )														// Update weight value
		{
			if ( ( E -> m_iWeight < irgWeight [ E -> m_pTarget -> m_iIndex ] )	// Edge is small
				&& ( ! bVertexCheck [ E -> m_pTarget -> m_iIndex ] ) )			// And Vertex is not used
			{
				ESelectArray [ E -> m_pTarget -> m_iIndex ] = E ;
				irgWeight [ E -> m_pTarget -> m_iIndex ] = E -> m_iWeight ;
			}
			E = E -> m_pNext ;
		}


		for ( int i = 0 ; i < iCnt ; ++i )										// Find min path
		{
			if ( ( 0 < irgWeight [ i ] ) && ( iMin > irgWeight [ i ] ) )
			{
				iMin = irgWeight [ i ] ;
				iIndex = i ;
			}
		}

		E = ESelectArray [ iIndex ] ;
		VFinalVertex [ iIndex ] = CreateVertex ( E -> m_pTarget -> m_iIndex ) ;
		AddVertex ( MST , VFinalVertex [ iIndex ] ) ;
		EFinalEdge [ MST -> m_iVertexCnt - 2 ] = CreateEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , VFinalVertex [ E -> m_pTarget -> m_iIndex ] , E -> m_iWeight ) ;
		AddEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , EFinalEdge [ MST -> m_iVertexCnt - 2 ] ) ;
		
		irgWeight [ E -> m_pTarget -> m_iIndex ] = 0 ;
		bVertexCheck [ E -> m_pTarget -> m_iIndex ] = true ;
		
		V = VFirstVertex [ iIndex ] ;
		E = V -> m_pAdjacencyList ;
		iIndex = -1 ;
		iMin = MAX_WEIGHT ;
	}


	free ( irgWeight ) ;
	free ( bVertexCheck ) ;
	free ( VFirstVertex ) ;
	free ( ESelectArray ) ;
	free ( VFinalVertex ) ;
	free ( EFinalEdge ) ;
}

void Kruskal ( Graph * G , Graph * MST )												// Kruskal algorithm
{
	const int iCnt = G -> m_iVertexCnt ;
	Vertex * V = G -> m_pVertices ;
	Vertex * VFrom ;
	Vertex * VTarget ;
	Edge * E = V -> m_pAdjacencyList ;
	PriorityQueue * PQ = PQ_Create ( 20 ) ;
	int iIndex = -1 ;
	Vertex ** VFinalVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** EFinalEdge = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;
	DisjointSet ** Set = ( DisjointSet ** ) malloc ( sizeof ( DisjointSet * ) * iCnt ) ;
	Node PQNode ;



	for ( int i = 0 ; i < iCnt ; ++i )											// Initialize
	{
		VFinalVertex [ V -> m_iIndex ] = CreateVertex ( V -> m_iIndex) ;		// Vertex array, make it first.
		EFinalEdge [ i ] = NULL ;												// Final Edge, use array to easy to access
		Set [ i ] = DS_MakeSet ( V -> m_iIndex ) ;								// With this, find Disjoint set

		AddVertex ( MST , VFinalVertex [ i ] ) ;

		V = V -> m_pNext ;
	}
	

	V = G -> m_pVertices ;


	while ( NULL != V )															// Enqueue every Edge in ascending order
	{
		E = V -> m_pAdjacencyList ;


		while ( NULL != E )
		{
			Node NewNode = { E -> m_iWeight , E } ;


			PQ_Enqueue ( PQ , NewNode ) ;
			E = E -> m_pNext ;
		}


		V = V -> m_pNext ;
	}
	for ( int i = 0 ; i < iCnt - 1 ; )											// Main loop
	{																			// If MST is made, then quit this loop
		PQNode = PQ_Dequeue ( PQ ) ;
		
		E = PQNode.m_pData ;
		VFrom = E -> m_pFrom ;
		VTarget = E -> m_pTarget ;

		if ( DS_FindSet ( Set [ VFrom -> m_iIndex ] )
			!= DS_FindSet ( Set [ VTarget -> m_iIndex ] ) )						// If a cycle isn't made when Edge is inserted
		{
			DS_UnionSet ( DS_FindSet ( Set [ VFrom -> m_iIndex ] ) , DS_FindSet ( Set [ VTarget -> m_iIndex ] ) ) ;
			EFinalEdge [ i ] = CreateEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , VFinalVertex [ E -> m_pTarget -> m_iIndex ] , E -> m_iWeight ) ;
			AddEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , EFinalEdge [ i++ ] ) ;
		}
	}

	for ( int i = 0 ; i < iCnt ; ++i )
	{
		DS_DestroySet ( Set [ i ] ) ;
	}
	free ( Set ) ;
	PQ_Destroy ( PQ ) ;
	free ( VFinalVertex ) ;
	free ( EFinalEdge ) ;
}