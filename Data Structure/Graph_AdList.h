#pragma once

#include "Basic.h"
																			// Directed Graph
typedef int T ;																// Template for understanding

typedef struct Vertex
{
	T m_Data ;
	bool m_bVisit ;
	int m_iIndex ;

	struct Vertex * m_pNext ;
	struct Edge * m_pAdjacencyList ;										// Point Edges that connected with current Vertex
} Vertex ;

typedef struct Edge
{
	int m_iWeight ;

	struct Edge * m_pNext ;													// Point Edges that have same Vertex m_pFrom
	struct Vertex * m_pFrom ;
	struct Vertex * m_pTarget ;
} Edge ;

typedef struct Graph
{
	int m_iVertexCnt ;

	struct Vertex * m_pVertices ;
} Graph ;

Graph * CreateGraph () ;													// Create Graph and return
void DestroyGraph ( Graph * G ) ;											// Destroy Graph
Vertex * CreateVertex ( T Data ) ;											// Create Vertex with T Data and return
void DestroyVertex ( Vertex * V ) ;											// Destroy Vertex
Edge * CreateEdge ( Vertex * pFrom , Vertex * pTarget , int iWeight ) ;		// Create Edge and return
void DestroyEdge ( Edge * E ) ;												// Destroy Edge

void AddVertex ( Graph * G , Vertex * V ) ;									// Add Vertex V into Graph G
void AddEdge ( Vertex * V , Edge * E ) ;									// Add Edge E connected with Vertex V
void PrintGraph ( Graph * G ) ;												// Print current Graph G