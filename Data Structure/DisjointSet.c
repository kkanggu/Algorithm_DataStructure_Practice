#include "DisjointSet.h"

void DS_UnionSet ( DisjointSet * Set1 , DisjointSet * Set2 )				// Union Set1 & Set2
{
	Set2 = DS_FindSet ( Set2 ) ;
	Set2 -> m_pParent = Set1 ;
}

DisjointSet * DS_FindSet ( DisjointSet * Set )								// Return Root set
{
	while ( NULL != Set	-> m_pParent )
	{
		Set = Set -> m_pParent ;
	}


	return Set ;
}

DisjointSet * DS_MakeSet ( void * NewData )									// Make Set with void * NewData
{
	DisjointSet * NewNode = ( DisjointSet * ) malloc ( sizeof ( DisjointSet ) ) ;



	NewNode -> m_pData = NewData ;
	NewNode -> m_pParent = NULL ;


	return NewNode ;
}

void DS_DestroySet ( DisjointSet * Set )									// Destroy Set
{
	free ( Set ) ;
}