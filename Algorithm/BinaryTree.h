#pragma once

#include "Basic.h"

typedef int T ;											// Template for understanding

typedef struct BinaryTreeNode
{
	T m_Data ;
	struct BinaryTreeNode * m_pLeft ;
	struct BinaryTreeNode * m_pRight ;
} BTNode ;

BTNode * BT_CreateNode ( T Data ) ;						// Create BT Node and return it
void BT_DestroyNode ( BTNode * pNode ) ;				// Destroy BT Node
void BT_DestroyTree ( BTNode * pRoot ) ;				// Destroy tree from Root to Leaf
void BT_PreorderPrintTree ( BTNode * pRoot ) ;			// Print tree with preorder
void BT_InorderPrintTree ( BTNode * pRoot ) ;			// Print tree with inorder
void BT_PostorderPrintTree ( BTNode * pRoot ) ;			// Print tree with postorder