#pragma once

#include "Basic.h"
#include "Graph_AdList.h"
#include "LinkedQueue.h"

#define MAX_WEIGHT 65535 ;

void Dijkstra ( Graph * G , Vertex * StartVertex , Graph * MST ) ;		// Dijkstra algorithm