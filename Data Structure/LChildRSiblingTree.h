#pragma once

#include "Basic.h"

typedef int T ;																	// Template for understanding

typedef struct LCRSNode
{
	T m_Data ;
	struct LCRSNode * m_pLeftChild ;											// Point child
	struct LCRSNode * m_pRightSIbling ;											// Point sibling
} LCRSNode ;

LCRSNode * LCRS_CreateNode ( T Data ) ;											// Create LCRS Node and return it
void LCRS_DestroyNode ( LCRSNode * pNode ) ;									// Destroy LCRS Node
void LCRS_DestroyTree ( LCRSNode * pRoot ) ;									// Destroy tree from Root to Leaf
void LCRS_AddChildNode ( LCRSNode * pParentNode , LCRSNode * pChildNode ) ;		// Add child Node
void LCRS_PrintTree ( LCRSNode * pRoot , int iDepth ) ;							// Print tree like file explorer in Window