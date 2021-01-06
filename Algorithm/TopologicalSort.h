#pragma once

#include "Basic.h"
#include "Graph_AdList.h"
#include "SingleLinkedList.h"

void TopologicalSort ( Vertex * V , Node ** LinkedList ) ;						// Sort topological
void TS_DFS ( Vertex * V , Node ** LinkedList ) ;								// TS with DFS