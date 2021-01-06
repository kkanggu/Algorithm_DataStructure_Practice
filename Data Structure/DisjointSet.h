#pragma once

#include "Basic.h"

typedef struct DisjointSet
{
	struct DisjointSet * m_pParent ;
	void * m_pData ;
} DisjointSet ;

void DS_UnionSet ( DisjointSet * Set1 , DisjointSet * Set2 ) ;				// Union Set1 & Set2
DisjointSet * DS_FindSet ( DisjointSet * Set ) ;							// Return Root set
DisjointSet * DS_MakeSet ( void * NewData ) ;								// Make Set with void * NewData
void DS_DestroySet ( DisjointSet * Set ) ;									// Destroy Set