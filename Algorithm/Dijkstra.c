#include "Dijkstra.h"

void Dijkstra ( Graph * G , Vertex * StartVertex , Graph * MST )		// Dijkstra algorithm
{
	const int iCnt = G -> m_iVertexCnt ;
	int * irgWeight = ( int * ) malloc ( sizeof ( int ) * iCnt ) ;
	bool * bVertexCheck = ( bool * ) malloc ( sizeof ( bool ) * iCnt ) ;
	Vertex * V = G ->m_pVertices ;
	Edge * E = V -> m_pAdjacencyList ;
	int iMin = MAX_WEIGHT ;
	int iIndex = -1 ;
	Vertex ** VFirstVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** ETargetEdge = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;
	Vertex ** VFinalVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** EFinalEdge = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;
	LinkedQueue * LQ ;
	Node * LQNode ;


	
	for ( int i = 0 ; i < iCnt ; ++i )											// Initialize
	{
		irgWeight [ i ] = MAX_WEIGHT ;											// Possible weight array
		bVertexCheck [ i ] = false ;											// Used Vertex check
		ETargetEdge [ i ] = NULL ;												// Edge * array matching with irgWeight
		EFinalEdge [ i ] = NULL ;												// Final Edge, use array to easy to access
		VFirstVertex [ V -> m_iIndex ] = V ;									// Initial Vertex set, easy to access
		VFinalVertex [ V -> m_iIndex ] = CreateVertex ( V -> m_iIndex ) ;		// Final Vertex, use array to easy to access. Make it first

		AddVertex ( MST , VFinalVertex [ V -> m_iIndex ] ) ;

		V = V -> m_pNext ;
	}


	LQ_CreateQueue ( & LQ ) ;
	LQ_Enqueue ( & LQ , LQ_CreateNode ( StartVertex ) ) ;
	irgWeight [ StartVertex -> m_iIndex ] = 0 ;
	bVertexCheck [ StartVertex -> m_iIndex ] = true ;


	while ( ! LQ_IsEmpty ( LQ ) )												// It loop until no Node in Queue
	{
		LQNode = LQ_Dequeue ( & LQ ) ;

		V = LQNode -> m_Data ;
		E = V -> m_pAdjacencyList ;
		LQ_DestroyNode ( LQNode ) ;


		while ( NULL != E )														// Update weight value
		{
			if ( ( irgWeight [ V -> m_iIndex ] + E -> m_iWeight )				// Path through V is small
				< irgWeight [ E -> m_pTarget -> m_iIndex ] )
			{
				irgWeight [ E -> m_pTarget -> m_iIndex ] = irgWeight [ V -> m_iIndex ] + E -> m_iWeight ;
				ETargetEdge [ E -> m_pTarget -> m_iIndex ] = E ;

				if ( ! bVertexCheck [ E -> m_pTarget -> m_iIndex ] )			// If new Vertex, then Enqueue
				{
					LQ_Enqueue ( & LQ , LQ_CreateNode ( E -> m_pTarget ) ) ;
					bVertexCheck [ E -> m_pTarget -> m_iIndex ] = true ;
				}
			}


			E = E -> m_pNext ;
		}
	}


	for ( int i = 0 ; i < iCnt ; ++i )
	{
		E = ETargetEdge [ i ] ;


		if ( NULL != E )
		{
			EFinalEdge [ i ] = CreateEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , VFinalVertex [ E -> m_pTarget -> m_iIndex ] , E -> m_iWeight ) ;
			AddEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , EFinalEdge [ i ] ) ;
		}
	}


	LQ_DestroyQueue ( & LQ ) ;
	free ( irgWeight ) ;
	free ( bVertexCheck ) ;
	free ( VFirstVertex ) ;
	free ( ETargetEdge ) ;
	free ( VFinalVertex ) ;
	free ( EFinalEdge ) ;
}