#pragma once

#include "Basic.h"
#include "Graph_AdList.h"
#include "PriorityQueue.h"
#include "DisjointSet.h"

#define MAX_WEIGHT 65535 ;

void Prim_AdList ( Graph * G , Vertex * StartVertex , Graph * MST ) ;			// Prim algorithm with Adjacent List
void Kruskal_AdList ( Graph * G , Graph * MST ) ;								// Kruskal algorithm with Adjacent List
void Prim_AdArray ( Graph * G , Vertex * StartVertex , Graph * MST ) ;			// Prim algorithm with Adjacent Array
void Kruskal_AdArray ( Graph * G , Graph * MST ) ;								// Kruskal algorithm with Adjacent Array