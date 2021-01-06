#include "MinimumSpanningTree.h"

void Prim_AdList ( Graph * G , Vertex * StartVertex , Graph * MST )						// Prim algorithm with Adjacent List
{
	const int iCnt = G -> m_iVertexCnt ;
	int * irgWeight = ( int * ) malloc ( sizeof ( int ) * iCnt ) ;
	bool * bVertexCheck = ( bool * ) malloc ( sizeof ( bool ) * iCnt ) ;
	Vertex * V = StartVertex ;
	Edge * E = V -> m_pAdjacencyList ;
	int iMin = MAX_WEIGHT ;
	int iIndex = -1 ;
	Edge ** ESelectArray = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;
	Vertex ** VFinalVertex = ( Vertex ** ) malloc ( sizeof ( Vertex * ) * iCnt ) ;
	Edge ** EFinalEdge = ( Edge ** ) malloc ( sizeof ( Edge * ) * iCnt ) ;



	for ( int i = 0 ; i < iCnt ; ++i )											// Initialize
	{
		irgWeight [ i ] = MAX_WEIGHT ;
		bVertexCheck [ i ] = false ;
		ESelectArray [ i ] = NULL ;
		VFinalVertex [ i ] = NULL ;
		EFinalEdge [ i ] = NULL ;
	}


	irgWeight [ V -> m_Data ] = 0 ;
	bVertexCheck [ V -> m_Data ] = true ;
	VFinalVertex [ V -> m_Data ] = CreateVertex ( V -> m_Data ) ;
	AddVertex ( MST , VFinalVertex [ V -> m_Data ] ) ;


	while ( iCnt != MST -> m_iVertexCnt )										// while loops iCnt times
	{
		while ( NULL != E )														// Update weight value
		{
			if ( ( E -> m_iWeight < irgWeight [ E -> m_pTarget -> m_Data ] )	// Edge is small
				&& ( ! bVertexCheck [ E -> m_pTarget -> m_Data ] ) )			// And Vertex is not used
			{
				ESelectArray [ E -> m_pTarget -> m_Data ] = E ;
				irgWeight [ E -> m_pTarget -> m_Data ] = E -> m_iWeight ;
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


		//E = V -> m_pAdjacencyList ;


		//while ( iIndex != E -> m_pTarget -> m_Data )							// Find Vertex have to be add
		//{
		//	E = E -> m_pNext ;
		//}
		
		E = ESelectArray [ iIndex ] ;
		VFinalVertex [ iIndex ] = CreateVertex ( E -> m_pTarget -> m_Data ) ;
		AddVertex ( MST , VFinalVertex [ iIndex ] ) ;
		EFinalEdge [ MST -> m_iVertexCnt - 2 ] = CreateEdge ( VFinalVertex [ E -> m_pFrom -> m_iIndex ] , VFinalVertex [ E -> m_pTarget -> m_iIndex ] , E -> m_iWeight ) ;
		AddEdge ( VFinalVertex [ iIndex ] , EFinalEdge [ MST -> m_iVertexCnt - 2 ] ) ;
		
		irgWeight [ E -> m_pTarget -> m_Data ] = 0 ;
		bVertexCheck [ E -> m_pTarget -> m_Data ] = true ;
		
		V = VFinalVertex [ iIndex ] ;
		E = V -> m_pAdjacencyList ;
		iIndex = -1 ;
		iMin = MAX_WEIGHT ;
	}
}

void Kruskal_AdList ( Graph * G , Graph * MST )											// Kruskal algorithm with Adjacent List
{

}

void Prim_AdArray ( Graph * G , Vertex * StartVertex , Graph * MST )			// Prim algorithm with Adjacent Array
{

}

void Kruskal_AdArray ( Graph * G , Graph * MST )								// Kruskal algorithm with Adjacent Array
{

}