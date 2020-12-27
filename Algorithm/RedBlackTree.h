#pragma once

#include "Basic.h"

typedef int T ;											// Template for understanding


typedef struct RedBlackTree
{
	T m_Data ;
	struct RedBlackTree * m_pParent ;
	struct RedBlackTree * m_pLeft ;
	struct RedBlackTree * m_pRight ;

	enum { RED , BLACK } COLOR ;
} RBTNode ;

extern RBTNode * NIL ;


RBTNode * RBT_CreateNode ( T Data ) ;											// Create RBT Node and return it
void RBT_DestroyNode ( RBTNode * pNode ) ;										// Destroy RBT Node
void RBT_DestroyTree ( RBTNode * pRoot ) ;										// Destroy tree from Root to Leaf

RBTNode * RBT_SearchNode ( RBTNode * pRoot , T Data ) ;							// Search RBTNode that have Data
RBTNode * RBT_SearchMinNode ( RBTNode * pRoot ) ;								// Search RBTNode that have min value
void RBT_InsertNode ( RBTNode ** pRoot , RBTNode * pNode ) ;					// Insert pNode into RBT
RBTNode * RBT_RemoveNode ( RBTNode ** pRoot , T Data ) ;						// Remove BSTNode with Data
void RBT_RebuildAfterInsert ( RBTNode ** pRoot , RBTNode * pNode ) ;			// After insert, rebuild to rule
void RBT_RebuildAfterRemove ( RBTNode ** pRoot , RBTNode * pSuccessor ) ;		// After remove, rebuild to rule
void RBT_RotateLeft ( RBTNode ** pRoot , RBTNode * pParent ) ;					// Rotate left
void RBT_RotateRight ( RBTNode ** pRoot , RBTNode * pParent ) ;					// Rotate Right
void RBT_PrintTree ( RBTNode * pRoot , int iDepth , int iBlackCount ) ;			// print