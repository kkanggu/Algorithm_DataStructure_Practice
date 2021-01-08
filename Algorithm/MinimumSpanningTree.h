#pragma once

#include "Basic.h"
#include "Graph_AdList.h"
#include "PriorityQueue.h"
#include "DisjointSet.h"

#define MAX_WEIGHT 65535 ;

void Prim ( Graph * G , Vertex * StartVertex , Graph * MST ) ;			// Prim algorithm
void Kruskal ( Graph * G , Graph * MST ) ;								// Kruskal algorithm